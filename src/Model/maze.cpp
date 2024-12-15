#include "maze.hpp"

void s21::set_rand() {
  std::timespec ts;
  std::timespec_get(&ts, TIME_UTC);
  srand(static_cast<long int>(ts.tv_nsec));
}

s21::Point::Point(int x, int y) : x_(x), y_(y) {}

s21::Point::Point(const s21::Point& other) : x_(other.x_), y_(other.y_) {}

s21::Point::~Point() {}

s21::Point& s21::Point::operator=(const Point& other) {
  x_ = other.x_;
  y_ = other.y_;
  return *this;
}

bool s21::Point::operator==(const Point& other) { return EqPoint(other); }

bool s21::Point::operator!=(const Point& other) { return !EqPoint(other); }

bool s21::Point::EqPoint(const Point& other) {
  bool result = false;
  if (x_ == other.x_ && y_ == other.y_) {
    result = true;
  }
  return result;
}

void s21::Point::clear() {
  x_ = 0;
  y_ = 0;
}

s21::Point& s21::Point::operator+=(const Point& other) {
  x_ = x_ + other.x_;
  y_ = y_ + other.y_;
  return *this;
}

s21::Point& s21::Point::operator-=(const Point& other) {
  x_ = x_ - other.x_;
  y_ = y_ - other.y_;
  return *this;
}

void s21::Point::turn_right() {
  if (x_ == 0) {
    x_ = -y_;
    y_ = 0;
  } else {
    y_ = x_;
    x_ = 0;
  }
}

void s21::Point::turn_left() {
  if (x_ == 0) {
    x_ = y_;
    y_ = 0;
  } else {
    y_ = -x_;
    x_ = 0;
  }
}

void s21::Maze::set_count_row_columns(int row, int column) {
  count_rows_ = row;
  count_columns_ = column;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      right_walls_.push_back(false);
      lower_walls_.push_back(false);
    }
  }
}

int s21::Maze::get_count_rows() { return count_rows_; }

int s21::Maze::get_count_columns() { return count_columns_; }

bool s21::Maze::get_right_wall(int row, int column) {
  return right_walls_[row * count_columns_ + column];
}

bool s21::Maze::get_lower_wall(int row, int column) {
  return lower_walls_[row * count_columns_ + column];
}

void s21::Maze::generation_maze(int new_count_rows, int new_count_columns) {
  clear_maze();
  set_count_row_columns(new_count_rows, new_count_columns);
  std::vector<int> line_walls;
  for (int i = 0; i < new_count_columns; i++) {
    line_walls.push_back(0);
  }
  for (int i = 0; i < new_count_rows - 1; i++) {
    set_assignment(&line_walls);
    creating_right_walls(&line_walls, i);
    creating_lower_walls(&line_walls, i);
    cleaning_line_walls(&line_walls, i);
  }
  // Последняя строка
  set_assignment(&line_walls);
  creating_right_walls(&line_walls, new_count_rows - 1);
  last_line_adjustment(&line_walls);
}

void s21::Maze::clear_maze() {
  set_count_row_columns(0, 0);
  right_walls_.clear();
  lower_walls_.clear();
  clear_path_maze();
  start_.clear();
  end_.clear();
}

void s21::Maze::clear_path_maze() {
  path_.clear();
  length_path_ = 0;
}

void s21::Maze::set_assignment(std::vector<int>* line_walls) {
  static unsigned int number_for_new_set = 1;
  for (int i = 0; i < count_columns_; i++) {
    if ((*line_walls)[i] == 0) {
      (*line_walls)[i] = number_for_new_set;
      number_for_new_set++;
    }
  }
}

void s21::Maze::creating_right_walls(std::vector<int>* line_walls,
                                     int number_row) {
  set_rand();
  int is_wall;
  for (int i = 0; i < count_columns_ - 1; i++) {
    is_wall = rand() % 2;
    if (is_wall || (*line_walls)[i] == (*line_walls)[i + 1]) {
      right_walls_[number_row * count_columns_ + i] = true;
    } else {
      set_equalization(line_walls, i);
    }
  }
  right_walls_[number_row * count_columns_ + count_columns_ - 1] = true;
}

void s21::Maze::creating_lower_walls(std::vector<int>* line_walls,
                                     int number_row) {
  set_rand();
  int is_wall;
  int last_number_set = 0;
  bool there_is_open_wall = false;
  for (int i = 0; i < count_columns_ - 1; i++) {
    is_wall = rand() % 2;
    if ((*line_walls)[i] != last_number_set) {
      last_number_set = (*line_walls)[i];
      there_is_open_wall = false;
    }
    if (is_wall) {
      if (there_is_open_wall || ((*line_walls)[i] == (*line_walls)[i + 1])) {
        lower_walls_[number_row * count_columns_ + i] = true;
      }
    } else {
      there_is_open_wall = true;
    }
  }
  is_wall = rand() % 2;
  if ((*line_walls)[count_columns_ - 1] != last_number_set) {
    there_is_open_wall = false;
  }
  if (is_wall && there_is_open_wall) {
    lower_walls_[number_row * count_columns_ + count_columns_ - 1] = true;
  }
}

void s21::Maze::cleaning_line_walls(std::vector<int>* line_walls,
                                    int number_row) {
  for (int i = 0; i < count_columns_; i++) {
    if (lower_walls_[number_row * count_columns_ + i]) {
      (*line_walls)[i] = 0;
    }
  }
}

void s21::Maze::last_line_adjustment(std::vector<int>* line_walls) {
  int last_row_index = (count_rows_ - 1) * count_columns_;
  for (int i = 0; i < count_columns_ - 1; i++) {
    lower_walls_[last_row_index + i] = true;
    if ((*line_walls)[i] != (*line_walls)[i + 1]) {
      right_walls_[last_row_index + i] = false;
      set_equalization(line_walls, i);
    }
  }
  lower_walls_[last_row_index + count_columns_ - 1] = true;
}

void s21::Maze::set_equalization(std::vector<int>* line_walls, int index_set) {
  int replaceable_set = (*line_walls)[index_set + 1];
  for (int i = 0; i < count_columns_; i++) {
    if ((*line_walls)[i] == replaceable_set) {
      (*line_walls)[i] = (*line_walls)[index_set];
    }
  }
}

void s21::Maze::set_start(int x, int y) {
  clear_path_maze();
  start_.x_ = x;
  start_.y_ = y;
}

void s21::Maze::set_end(int x, int y) {
  clear_path_maze();
  end_.x_ = x;
  end_.y_ = y;
}

void s21::Maze::random_start_end() {
  set_rand();
  int x = rand() % (SIZE);
  int y = rand() % (SIZE);
  set_start(x, y);
  x = rand() % (SIZE);
  y = rand() % (SIZE);
  set_end(x, y);
}

void s21::Maze::set_start_end(int start_x, int start_y, int end_x, int end_y) {
  set_start(start_x, start_y);
  set_end(end_x, end_y);
}

void s21::Maze::find_path() {
  s21::Point direction(0, -1);
  path_.push_back(start_);
  length_path_ = 1;

  while (path_.back() != end_) {
    s21::Point new_point(0, 0);
    new_point = path_.back();
    if (is_correct_step(new_point, direction)) {
      new_point += direction;
      direction.turn_right();
      if (new_point != path_[length_path_ - 2]) {
        path_.push_back(new_point);
        length_path_++;
      } else {
        path_.pop_back();
        length_path_--;
      }

    } else {
      direction.turn_left();
    }
  }
}

bool s21::Maze::is_correct_step(const s21::Point& point,
                                const s21::Point& direction) {
  bool result = false;
  if (direction.x_ == -1 && direction.y_ == 0) {
    if (point.x_ > 0 && get_right_wall(point.y_, point.x_ - 1) == false) {
      result = true;
    }
  } else if (direction.x_ == 1 && direction.y_ == 0) {
    if (point.x_ < count_columns_ - 1 &&
        get_right_wall(point.y_, point.x_) == false) {
      result = true;
    }
  } else if (direction.x_ == 0 && direction.y_ == -1) {
    if (point.y_ > 0 && get_lower_wall(point.y_ - 1, point.x_) == false) {
      result = true;
    }
  } else if (direction.x_ == 0 && direction.y_ == 1) {
    if (point.y_ < count_rows_ - 1 &&
        get_lower_wall(point.y_, point.x_) == false) {
      result = true;
    }
  }

  return result;
}

int s21::Maze::get_length_path() { return length_path_; }

s21::Point& s21::Maze::get_point_path(int index) { return path_[index]; }

void s21::Maze::read_file(std::string path) {
  clear_maze();
  std::ifstream in(path);
  if (in.is_open()) {
    bool elem = false;
    in >> count_rows_;
    in >> count_columns_;

    for (int i = 0; i < count_rows_; i++) {
      for (int j = 0; j < count_columns_; j++) {
        in >> elem;
        right_walls_.push_back(elem);
      }
    }
    for (int i = 0; i < count_rows_; i++) {
      for (int j = 0; j < count_columns_; j++) {
        in >> elem;
        lower_walls_.push_back(elem);
      }
    }
  }
  in.close();
}

void s21::Maze::save_file(std::string path) {
  std::ofstream out;
  out.open(path);
  if (out.is_open()) {
    out << count_rows_ << " " << count_columns_ << std::endl;
    for (int i = 0; i < count_rows_; i++) {
      for (int j = 0; j < count_columns_; j++) {
        out << (int)get_right_wall(i, j) << " ";
      }
      out << std::endl;
    }
    out << std::endl;
    for (int i = 0; i < count_rows_; i++) {
      for (int j = 0; j < count_columns_; j++) {
        out << (int)get_lower_wall(i, j) << " ";
      }
      out << std::endl;
    }
  }
  out.close();
}

// __________________________________________________________________________________________________
// Q learning

s21::Agent::Agent(s21::Maze* new_environment) {
  count_actions_ = COUNT_ACTIONS;
  epsilon_ = EPSILON;
  discont_ = DISCONT;
  learning_rate_ = LEARNING_RATE;
  init_new_environment(new_environment);
}

s21::Agent::~Agent() {}

void s21::Agent::clear() {
  for (int i = 0; i < (int)q_values_.size(); i++) {
    q_values_[i].clear();
  }
  q_values_.clear();
  path_.clear();
}

void s21::Agent::init_new_environment(s21::Maze* new_environment) {
  environment_ = new_environment;
  clear();
  int count_states =
      new_environment->get_count_columns() * new_environment->get_count_rows();
  for (int i = 0; i < count_states; i++) {
    std::vector<double> state;
    for (int j = 0; j < count_actions_; j++) {
      state.push_back(0.0);
    }
    q_values_.push_back(state);
  }
}

int s21::Agent::get_index_action_with_max_value(int index_state) {
  int result = 0;
  double max_value = q_values_[index_state][0];

  for (int i = 1; i < count_actions_; i++) {
    if (q_values_[index_state][i] > max_value) {
      max_value = q_values_[index_state][i];
      result = i;
    }
  }

  return result;
}

Actions s21::Agent::get_new_actions(int index_state) {
  Actions result = (Actions)0;
  if ((double)(rand()) / RAND_MAX < epsilon_) {
    result = (Actions)get_index_action_with_max_value(index_state);
  } else {
    result = (Actions)(rand() % (count_actions_));
  }
  return result;
}

bool s21::Maze::make_move(Point& state, Point* new_state, double* reward,
                          Actions action) {
  bool need_restart = false;

  *new_state = state;

  s21::Point direction(0, 0);

  actions_to_direction(action, &direction);

  if (state != end_) {
    if (is_correct_step(state, direction)) {
      (*new_state) += direction;
      if ((*new_state) == end_) {
        *reward = MAIN_REWARD;
        need_restart = true;
      } else {
        *reward = REWARD_FOR_MOVE;
      }
    } else {
      *reward = PUNISHMENT;
      need_restart = true;
    }
  } else {
    need_restart = true;
  }
  return need_restart;
}

void s21::Maze::actions_to_direction(Actions action, s21::Point* direction) {
  switch (action) {
    case Up:
      direction->x_ = 0;
      direction->y_ = -1;
      break;
    case Down:
      direction->x_ = 0;
      direction->y_ = 1;
      break;
    case Left:
      direction->x_ = -1;
      direction->y_ = 0;
      break;
    case Right:
      direction->x_ = 1;
      direction->y_ = 0;
      break;
  }
}

void s21::Agent::training(int count_episode) {
  for (int i = 0; i < count_episode; i++) {
    set_rand();
    bool end_episode = false;
    init_state();
    while (!end_episode) {
      end_episode = perform_action();
    }
  }
}

s21::Point s21::Maze::get_start_for_training() {
  s21::Point result(0, 0);
  result.x_ = rand() % (count_rows_);
  result.y_ = rand() % (count_columns_);

  while (result == end_) {
    result.x_ = (rand() % (count_rows_));
    result.y_ = (rand() % (count_columns_));
  }
  return result;
}

void s21::Agent::init_state() {
  state_ = environment_->get_start_for_training();
}

bool s21::Agent::perform_action() {
  bool result = false;
  int index_state = state_.x_ * environment_->get_count_columns() + state_.y_;
  Actions new_action = get_new_actions(index_state);
  s21::Point new_state(0, 0);
  double reward = 0.0;

  result = environment_->make_move(state_, &new_state, &reward, new_action);

  int index_new_state =
      new_state.x_ * environment_->get_count_columns() + new_state.y_;
  double old_q_value = q_values_[index_state][new_action];
  double temporal_diference =
      reward + (discont_ * get_max_value_by_index(index_new_state)) -
      old_q_value;

  double new_q_value = old_q_value + (learning_rate_ * temporal_diference);
  q_values_[index_state][new_action] = new_q_value;

  state_ = new_state;

  return result;
}

double s21::Agent::get_max_value_by_index(int index_state) {
  double max_value = q_values_[index_state][0];

  for (int i = 1; i < count_actions_; i++) {
    if (q_values_[index_state][i] > max_value) {
      max_value = q_values_[index_state][i];
    }
  }

  return max_value;
}

void s21::Agent::find_path(Point start) {
  path_.clear();

  bool end = false;
  state_ = start;
  path_.push_back(state_);
  double reward = 0.0;

  int count_point = 0;

  while (!end && count_point < (int)q_values_.size()) {
    int index_state = state_.x_ * environment_->get_count_columns() + state_.y_;
    Actions action = (Actions)get_index_action_with_max_value(index_state);
    end = environment_->make_move(state_, &start, &reward, action);
    state_ = start;
    path_.push_back(state_);
    count_point++;
  }
}

s21::Point& s21::Agent::get_point_path(int index) { return path_[index]; }

s21::Point& s21::Agent::get_state() { return state_; }

s21::Point& s21::Maze::get_end() { return end_; }

int s21::Agent::get_length_path() { return path_.size(); }
