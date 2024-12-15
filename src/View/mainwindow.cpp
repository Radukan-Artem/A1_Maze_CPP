#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  agent_ = new s21::Agent(&maze_);

  x_field_ = ui->tabWidget->x() + 10;
  y_field_ = ui->tabWidget->y() + 30;

  assign_functions_to_buttons();
  load_default_settings_cave();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::assign_functions_to_buttons() {
  connect(ui->load_maze_button, SIGNAL(clicked()), this,
          SLOT(load_maze_click()));
  connect(ui->save_maze_button, SIGNAL(clicked()), this,
          SLOT(save_maze_click()));

  connect(ui->maze_generation_button, SIGNAL(clicked()), this,
          SLOT(maze_generation_click()));
  connect(ui->solve_maze_button, SIGNAL(clicked()), this,
          SLOT(solve_maze_click()));

  connect(ui->end_maze_button, SIGNAL(clicked()), this, SLOT(end_maze_click()));
  connect(ui->train_agent_button, SIGNAL(clicked()), this,
          SLOT(train_agent_click()));
  connect(ui->q_solve_maze_button, SIGNAL(clicked()), this,
          SLOT(q_solve_maze_click()));

  connect(ui->load_cave_button, SIGNAL(clicked()), this,
          SLOT(load_cave_click()));
  connect(ui->save_cave_button, SIGNAL(clicked()), this,
          SLOT(save_cave_click()));
  connect(ui->cave_generation_button, SIGNAL(clicked()), this,
          SLOT(cave_generation_click()));
  connect(ui->save_limits_button, SIGNAL(clicked()), this,
          SLOT(save_limits_click()));
  connect(ui->change_cave_button, SIGNAL(clicked()), this,
          SLOT(change_cave_click()));
  connect(ui->rendering_cave_button, SIGNAL(clicked()), this,
          SLOT(rendering_cave_click()));
}

void MainWindow::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  painter.setBrush(Qt::white);
  painter.setPen(QPen(Qt::black, WALL_WIDTH));
  painter.drawRect(x_field_, y_field_, 500, 500);

  switch (ui->tabWidget->currentIndex()) {
    case 0:
      paint_maze(&painter);
      paint_solution_maze(&painter);
      paint_q_solution_maze(&painter);
      break;
    case 1:
      paint_cave(&painter);
      break;
  }

  painter.end();
}

void MainWindow::paint_maze(QPainter *painter) {
  int count_right_walls = maze_.get_count_columns() - 1;
  int count_lower_walls = maze_.get_count_rows() - 1;

  for (int i = 0; i < maze_.get_count_rows(); i++) {
    for (int j = 0; j < maze_.get_count_columns(); j++) {
      if (maze_.get_right_wall(i, j) && j != count_right_walls) {
        double x = (WALL_WIDTH + corridor_width_) * (j + 1);
        double y_start = WALL_WIDTH + (WALL_WIDTH + corridor_height_) * (i);
        double y_end = y_start + corridor_height_;
        if (i != 0) {
          y_start -= WALL_WIDTH;
        }
        painter->drawPolyline({QPointF(x_field_ + x, y_field_ + y_start),
                               QPointF(x_field_ + x, y_field_ + y_end)});
      }
      if (maze_.get_lower_wall(i, j) == 1 && i != count_lower_walls) {
        double x_start = WALL_WIDTH + (WALL_WIDTH + corridor_width_) * (j);
        double x_end = x_start + corridor_width_;
        double y = (WALL_WIDTH + corridor_height_) * (i + 1);
        if (j != 0) {
          x_start -= WALL_WIDTH;
        }
        painter->drawPolyline({QPointF(x_field_ + x_start, y_field_ + y),
                               QPointF(x_field_ + x_end, y_field_ + y)});
      }
    }
  }
}

void MainWindow::load_maze_click() {
  QString path = QFileDialog::getOpenFileName(this, tr("Open Maze"), "",
                                              tr("Maze Files (*.txt)"));
  maze_.read_file(path.toStdString());
  calculate_size_corridors();
  agent_->init_new_environment(&maze_);
  update();
}

void MainWindow::calculate_size_corridors() {
  if (maze_.get_count_columns() > 0 && maze_.get_count_rows() > 0) {
    corridor_width_ = (500.0 - (maze_.get_count_columns() + 1) * 2) /
                      maze_.get_count_columns();
    corridor_height_ =
        (500.0 - (maze_.get_count_rows() + 1) * 2) / maze_.get_count_rows();

    ui->start_x_spinBox->setMaximum(maze_.get_count_columns() - 1);
    ui->start_y_spinBox->setMaximum(maze_.get_count_rows() - 1);
    ui->end_x_spinBox->setMaximum(maze_.get_count_columns() - 1);
    ui->end_y_spinBox->setMaximum(maze_.get_count_rows() - 1);

    ui->q_end_x_spinBox->setMaximum(maze_.get_count_columns() - 1);
    ui->q_end_y_spinBox->setMaximum(maze_.get_count_rows() - 1);
    ui->q_start_x_spinBox->setMaximum(maze_.get_count_columns() - 1);
    ui->q_start_y_spinBox->setMaximum(maze_.get_count_rows() - 1);
  }
}

void MainWindow::maze_generation_click() {
  int count_lines = ui->number_lines_maze_spinBox->value();
  int count_columns = ui->number_columns_maze_spinBox->value();

  maze_.generation_maze(count_lines, count_columns);

  calculate_size_corridors();

  agent_->init_new_environment(&maze_);

  update();
}

void MainWindow::save_maze_click() {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save Maze"), "",
                                                  tr("Maze (*.txt)"));
  maze_.save_file(fileName.toStdString());
}

void MainWindow::solve_maze_click() {
  if (maze_.get_count_columns() > 0 && maze_.get_count_rows() > 0) {
    int start_x = ui->start_x_spinBox->value();
    int start_y = ui->start_y_spinBox->value();
    int end_x = ui->end_x_spinBox->value();
    int end_y = ui->end_y_spinBox->value();
    maze_.set_start_end(start_x, start_y, end_x, end_y);
    maze_.find_path();

    agent_->init_new_environment(&maze_);

    update();
  }
}

void MainWindow::paint_solution_maze(QPainter *painter) {
  if (maze_.get_length_path() > 0) {
    painter->setBrush(Qt::red);
    painter->setPen(QPen(Qt::green));
    s21::Point last_point = maze_.get_point_path(0);

    painter->drawRect(x_field_ + corridor_width_ / 4 + WALL_WIDTH +
                          (WALL_WIDTH + corridor_width_) * (last_point.x_),
                      y_field_ + corridor_height_ / 4 + WALL_WIDTH +
                          (WALL_WIDTH + corridor_height_) * (last_point.y_),
                      corridor_width_ / 2, corridor_height_ / 2);
    for (int i = 0; i < maze_.get_length_path(); i++) {
      s21::Point new_point = maze_.get_point_path(i);

      double x_start = corridor_width_ / 2 + WALL_WIDTH +
                       (WALL_WIDTH + corridor_width_) * (last_point.x_);
      double x_end = corridor_width_ / 2 + WALL_WIDTH +
                     (WALL_WIDTH + corridor_width_) * (new_point.x_);
      double y_start = corridor_height_ / 2 + WALL_WIDTH +
                       (WALL_WIDTH + corridor_height_) * (last_point.y_);
      double y_end = corridor_height_ / 2 + WALL_WIDTH +
                     (WALL_WIDTH + corridor_height_) * (new_point.y_);

      painter->drawPolyline({QPointF(x_field_ + x_start, y_field_ + y_start),
                             QPointF(x_field_ + x_end, y_field_ + y_end)});

      last_point = new_point;
    }
    painter->setBrush(Qt::blue);
    painter->drawRect(x_field_ + corridor_width_ / 4 + WALL_WIDTH +
                          (WALL_WIDTH + corridor_width_) * (last_point.x_),
                      y_field_ + corridor_height_ / 4 + WALL_WIDTH +
                          (WALL_WIDTH + corridor_height_) * (last_point.y_),
                      corridor_width_ / 2, corridor_height_ / 2);
    painter->setPen(QPen(Qt::black));
  }
}

void MainWindow::end_maze_click() {
  if (maze_.get_count_columns() > 0 && maze_.get_count_rows() > 0) {
    int end_x = ui->q_end_x_spinBox->value();
    int end_y = ui->q_end_y_spinBox->value();
    maze_.set_end(end_x, end_y);
    agent_->init_new_environment(&maze_);
  }
}

void MainWindow::train_agent_click() {
  if (maze_.get_count_columns() > 0 && maze_.get_count_rows() > 0) {
    ui->train_agent_button->setEnabled(false);
    agent_->training(ui->count_episode_spinBox->value());
    ui->train_agent_button->setEnabled(true);
  }
}

void MainWindow::q_solve_maze_click() {
  int start_x = ui->q_start_x_spinBox->value();
  int start_y = ui->q_start_y_spinBox->value();
  agent_->find_path(s21::Point(start_x, start_y));
  update();
}

void MainWindow::paint_q_solution_maze(QPainter *painter) {
  if (agent_->get_length_path() > 0) {
    painter->setBrush(Qt::darkMagenta);
    painter->setPen(QPen(Qt::magenta));
    s21::Point last_point = agent_->get_point_path(0);

    painter->drawRect(x_field_ + corridor_width_ / 4 + WALL_WIDTH +
                          (WALL_WIDTH + corridor_width_) * (last_point.x_),
                      y_field_ + corridor_height_ / 4 + WALL_WIDTH +
                          (WALL_WIDTH + corridor_height_) * (last_point.y_),
                      corridor_width_ / 2, corridor_height_ / 2);
    for (int i = 0; i < agent_->get_length_path(); i++) {
      s21::Point new_point = agent_->get_point_path(i);

      double x_start = corridor_width_ / 2 + WALL_WIDTH +
                       (WALL_WIDTH + corridor_width_) * (last_point.x_);
      double x_end = corridor_width_ / 2 + WALL_WIDTH +
                     (WALL_WIDTH + corridor_width_) * (new_point.x_);
      double y_start = corridor_height_ / 2 + WALL_WIDTH +
                       (WALL_WIDTH + corridor_height_) * (last_point.y_);
      double y_end = corridor_height_ / 2 + WALL_WIDTH +
                     (WALL_WIDTH + corridor_height_) * (new_point.y_);

      painter->drawPolyline({QPointF(x_field_ + x_start, y_field_ + y_start),
                             QPointF(x_field_ + x_end, y_field_ + y_end)});

      last_point = new_point;
    }
    painter->setBrush(Qt::blue);
    painter->drawRect(x_field_ + corridor_width_ / 4 + WALL_WIDTH +
                          (WALL_WIDTH + corridor_width_) * (last_point.x_),
                      y_field_ + corridor_height_ / 4 + WALL_WIDTH +
                          (WALL_WIDTH + corridor_height_) * (last_point.y_),
                      corridor_width_ / 2, corridor_height_ / 2);
    painter->setPen(QPen(Qt::black));
  }
}

void MainWindow::paint_cave(QPainter *painter) {
  for (int i = 0; i < cave_.get_count_rows(); i++) {
    for (int j = 0; j < cave_.get_count_columns(); j++) {
      if (!cave_.get_value_cell(i, j)) {
        painter->setBrush(Qt::white);
        painter->setPen(QPen(Qt::white));
      } else {
        painter->setBrush(Qt::black);
        painter->setPen(QPen(Qt::black));
      }
      painter->drawRect(x_field_ + j * cell_width_, y_field_ + i * cell_height_,
                        cell_width_, cell_height_);
    }
  }

  painter->setBrush(Qt::white);
  painter->setPen(QPen(Qt::black));
}

void MainWindow::load_default_settings_cave() {
  ui->initialization_chance_doubleSpinBox->setValue(
      DEFAULT_INITIALIZATION_CHANCE);
  ui->death_limit_spinBox->setValue(DEFAULT_DEATH_LIMIT);
  ui->birth_limit_spinBox->setValue(DEFAULT_BIRTH_LIMIT);
}

void MainWindow::load_cave_click() {
  QString path = QFileDialog::getOpenFileName(this, tr("Open Cave"), "",
                                              tr("Cave Files (*.txt)"));
  int death_limit = ui->death_limit_spinBox->value();
  int birth_limit = ui->birth_limit_spinBox->value();
  cave_.read_file(path.toStdString(), death_limit, birth_limit);
  calculate_size_cells();
  update();
}

void MainWindow::calculate_size_cells() {
  if (cave_.get_count_columns() > 0 && cave_.get_count_rows() > 0) {
    cell_width_ = 500.0 / cave_.get_count_columns();
    cell_height_ = 500.0 / cave_.get_count_rows();
  }
}

void MainWindow::save_cave_click() {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save Cave"), "",
                                                  tr("Cave (*.txt)"));
  cave_.save_file(fileName.toStdString());
}

void MainWindow::cave_generation_click() {
  int count_lines = ui->number_lines_cave_spinBox->value();
  int count_columns = ui->number_columns_cave_spinBox->value();
  int death_limit = ui->death_limit_spinBox->value();
  int birth_limit = ui->birth_limit_spinBox->value();
  double initialization_chance_ =
      ui->initialization_chance_doubleSpinBox->value();

  cave_.init_cave(count_lines, count_columns, death_limit, birth_limit,
                  initialization_chance_);

  calculate_size_cells();

  update();
}

void MainWindow::save_limits_click() {
  int death_limit = ui->death_limit_spinBox->value();
  int birth_limit = ui->birth_limit_spinBox->value();

  cave_.change_death_limit(death_limit);
  cave_.change_birth_limit(birth_limit);
}

void MainWindow::change_cave_click() {
  count_iterators++;
  if (count_iterators >= ui->number_iterations_spinBox->value()) {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(change_cave_click()));
  }
  cave_.make_change();
  update();
}

void MainWindow::rendering_cave_click() {
  count_iterators = 0;
  int time_iterations = ui->time_iterations_spinBox->value();

  timer = new QTimer();

  connect(timer, SIGNAL(timeout()), this, SLOT(change_cave_click()));
  timer->start(time_iterations);
}
