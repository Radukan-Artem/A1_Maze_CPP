/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QTabWidget *tabWidget;
  QWidget *tab_maze;
  QPushButton *load_maze_button;
  QGroupBox *maze_generation_groupBox;
  QLabel *number_lines_maze_label;
  QSpinBox *number_lines_maze_spinBox;
  QSpinBox *number_columns_maze_spinBox;
  QLabel *number_columns_maze_label;
  QPushButton *maze_generation_button;
  QPushButton *save_maze_button;
  QGroupBox *solve_maze_groupBox;
  QLabel *start_x_label;
  QLabel *start_y_label;
  QSpinBox *start_x_spinBox;
  QSpinBox *start_y_spinBox;
  QLabel *end_x_label;
  QSpinBox *end_y_spinBox;
  QLabel *end_y_label;
  QSpinBox *end_x_spinBox;
  QPushButton *solve_maze_button;
  QGroupBox *q_learning_groupBox;
  QSpinBox *q_end_y_spinBox;
  QLabel *q_end_x_label;
  QSpinBox *q_end_x_spinBox;
  QLabel *q_end_y_label;
  QPushButton *end_maze_button;
  QLabel *count_episode_label;
  QSpinBox *count_episode_spinBox;
  QPushButton *train_agent_button;
  QSpinBox *q_start_y_spinBox;
  QLabel *q_start_y_label;
  QLabel *q_start_x_label;
  QSpinBox *q_start_x_spinBox;
  QPushButton *q_solve_maze_button;
  QWidget *tab_cave;
  QPushButton *load_cave_button;
  QPushButton *save_cave_button;
  QGroupBox *cave_generation_groupBox;
  QLabel *number_columns_cave_label;
  QPushButton *cave_generation_button;
  QLabel *number_lines_cave_label;
  QSpinBox *number_lines_cave_spinBox;
  QSpinBox *number_columns_cave_spinBox;
  QLabel *initialization_chance_label;
  QDoubleSpinBox *initialization_chance_doubleSpinBox;
  QGroupBox *change_cave_groupBox;
  QLabel *birth_limit_label;
  QSpinBox *birth_limit_spinBox;
  QLabel *death_limit_label;
  QSpinBox *death_limit_spinBox;
  QPushButton *save_limits_button;
  QPushButton *change_cave_button;
  QLabel *time_iterations_label;
  QLabel *number_iterations_label;
  QSpinBox *number_iterations_spinBox;
  QSpinBox *time_iterations_spinBox;
  QPushButton *rendering_cave_button;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 600);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(10, 10, 781, 541));
    tab_maze = new QWidget();
    tab_maze->setObjectName(QString::fromUtf8("tab_maze"));
    load_maze_button = new QPushButton(tab_maze);
    load_maze_button->setObjectName(QString::fromUtf8("load_maze_button"));
    load_maze_button->setGeometry(QRect(520, 0, 121, 32));
    maze_generation_groupBox = new QGroupBox(tab_maze);
    maze_generation_groupBox->setObjectName(
        QString::fromUtf8("maze_generation_groupBox"));
    maze_generation_groupBox->setGeometry(QRect(520, 40, 251, 111));
    number_lines_maze_label = new QLabel(maze_generation_groupBox);
    number_lines_maze_label->setObjectName(
        QString::fromUtf8("number_lines_maze_label"));
    number_lines_maze_label->setGeometry(QRect(10, 25, 141, 16));
    number_lines_maze_spinBox = new QSpinBox(maze_generation_groupBox);
    number_lines_maze_spinBox->setObjectName(
        QString::fromUtf8("number_lines_maze_spinBox"));
    number_lines_maze_spinBox->setGeometry(QRect(180, 23, 61, 22));
    number_lines_maze_spinBox->setMinimum(3);
    number_lines_maze_spinBox->setMaximum(50);
    number_columns_maze_spinBox = new QSpinBox(maze_generation_groupBox);
    number_columns_maze_spinBox->setObjectName(
        QString::fromUtf8("number_columns_maze_spinBox"));
    number_columns_maze_spinBox->setGeometry(QRect(180, 48, 61, 22));
    number_columns_maze_spinBox->setMinimum(3);
    number_columns_maze_spinBox->setMaximum(50);
    number_columns_maze_label = new QLabel(maze_generation_groupBox);
    number_columns_maze_label->setObjectName(
        QString::fromUtf8("number_columns_maze_label"));
    number_columns_maze_label->setGeometry(QRect(10, 50, 141, 16));
    maze_generation_button = new QPushButton(maze_generation_groupBox);
    maze_generation_button->setObjectName(
        QString::fromUtf8("maze_generation_button"));
    maze_generation_button->setGeometry(QRect(10, 75, 231, 32));
    save_maze_button = new QPushButton(tab_maze);
    save_maze_button->setObjectName(QString::fromUtf8("save_maze_button"));
    save_maze_button->setGeometry(QRect(650, 0, 121, 32));
    solve_maze_groupBox = new QGroupBox(tab_maze);
    solve_maze_groupBox->setObjectName(
        QString::fromUtf8("solve_maze_groupBox"));
    solve_maze_groupBox->setGeometry(QRect(520, 160, 251, 121));
    start_x_label = new QLabel(solve_maze_groupBox);
    start_x_label->setObjectName(QString::fromUtf8("start_x_label"));
    start_x_label->setGeometry(QRect(10, 25, 58, 16));
    start_y_label = new QLabel(solve_maze_groupBox);
    start_y_label->setObjectName(QString::fromUtf8("start_y_label"));
    start_y_label->setGeometry(QRect(130, 25, 58, 16));
    start_x_spinBox = new QSpinBox(solve_maze_groupBox);
    start_x_spinBox->setObjectName(QString::fromUtf8("start_x_spinBox"));
    start_x_spinBox->setGeometry(QRect(60, 23, 61, 22));
    start_x_spinBox->setMinimum(0);
    start_x_spinBox->setMaximum(50);
    start_x_spinBox->setValue(0);
    start_y_spinBox = new QSpinBox(solve_maze_groupBox);
    start_y_spinBox->setObjectName(QString::fromUtf8("start_y_spinBox"));
    start_y_spinBox->setGeometry(QRect(180, 23, 61, 22));
    start_y_spinBox->setMinimum(0);
    start_y_spinBox->setMaximum(50);
    end_x_label = new QLabel(solve_maze_groupBox);
    end_x_label->setObjectName(QString::fromUtf8("end_x_label"));
    end_x_label->setGeometry(QRect(10, 52, 58, 16));
    end_y_spinBox = new QSpinBox(solve_maze_groupBox);
    end_y_spinBox->setObjectName(QString::fromUtf8("end_y_spinBox"));
    end_y_spinBox->setGeometry(QRect(180, 50, 61, 22));
    end_y_spinBox->setMinimum(0);
    end_y_spinBox->setMaximum(50);
    end_y_label = new QLabel(solve_maze_groupBox);
    end_y_label->setObjectName(QString::fromUtf8("end_y_label"));
    end_y_label->setGeometry(QRect(130, 52, 58, 16));
    end_x_spinBox = new QSpinBox(solve_maze_groupBox);
    end_x_spinBox->setObjectName(QString::fromUtf8("end_x_spinBox"));
    end_x_spinBox->setGeometry(QRect(60, 50, 61, 22));
    end_x_spinBox->setMinimum(0);
    end_x_spinBox->setMaximum(50);
    end_x_spinBox->setValue(0);
    solve_maze_button = new QPushButton(solve_maze_groupBox);
    solve_maze_button->setObjectName(QString::fromUtf8("solve_maze_button"));
    solve_maze_button->setGeometry(QRect(10, 80, 231, 32));
    q_learning_groupBox = new QGroupBox(tab_maze);
    q_learning_groupBox->setObjectName(
        QString::fromUtf8("q_learning_groupBox"));
    q_learning_groupBox->setGeometry(QRect(520, 290, 251, 211));
    q_end_y_spinBox = new QSpinBox(q_learning_groupBox);
    q_end_y_spinBox->setObjectName(QString::fromUtf8("q_end_y_spinBox"));
    q_end_y_spinBox->setGeometry(QRect(180, 20, 61, 22));
    q_end_y_spinBox->setMinimum(0);
    q_end_y_spinBox->setMaximum(50);
    q_end_x_label = new QLabel(q_learning_groupBox);
    q_end_x_label->setObjectName(QString::fromUtf8("q_end_x_label"));
    q_end_x_label->setGeometry(QRect(10, 22, 58, 16));
    q_end_x_spinBox = new QSpinBox(q_learning_groupBox);
    q_end_x_spinBox->setObjectName(QString::fromUtf8("q_end_x_spinBox"));
    q_end_x_spinBox->setGeometry(QRect(60, 20, 61, 22));
    q_end_x_spinBox->setMinimum(0);
    q_end_x_spinBox->setMaximum(50);
    q_end_x_spinBox->setValue(0);
    q_end_y_label = new QLabel(q_learning_groupBox);
    q_end_y_label->setObjectName(QString::fromUtf8("q_end_y_label"));
    q_end_y_label->setGeometry(QRect(130, 22, 58, 16));
    end_maze_button = new QPushButton(q_learning_groupBox);
    end_maze_button->setObjectName(QString::fromUtf8("end_maze_button"));
    end_maze_button->setGeometry(QRect(10, 50, 231, 32));
    count_episode_label = new QLabel(q_learning_groupBox);
    count_episode_label->setObjectName(
        QString::fromUtf8("count_episode_label"));
    count_episode_label->setGeometry(QRect(10, 90, 141, 16));
    count_episode_spinBox = new QSpinBox(q_learning_groupBox);
    count_episode_spinBox->setObjectName(
        QString::fromUtf8("count_episode_spinBox"));
    count_episode_spinBox->setGeometry(QRect(160, 87, 81, 22));
    count_episode_spinBox->setMinimum(1);
    count_episode_spinBox->setMaximum(999999999);
    count_episode_spinBox->setSingleStep(100);
    count_episode_spinBox->setValue(1000);
    train_agent_button = new QPushButton(q_learning_groupBox);
    train_agent_button->setObjectName(QString::fromUtf8("train_agent_button"));
    train_agent_button->setEnabled(true);
    train_agent_button->setGeometry(QRect(10, 110, 231, 32));
    q_start_y_spinBox = new QSpinBox(q_learning_groupBox);
    q_start_y_spinBox->setObjectName(QString::fromUtf8("q_start_y_spinBox"));
    q_start_y_spinBox->setGeometry(QRect(180, 150, 61, 22));
    q_start_y_spinBox->setMinimum(0);
    q_start_y_spinBox->setMaximum(50);
    q_start_y_label = new QLabel(q_learning_groupBox);
    q_start_y_label->setObjectName(QString::fromUtf8("q_start_y_label"));
    q_start_y_label->setGeometry(QRect(130, 152, 58, 16));
    q_start_x_label = new QLabel(q_learning_groupBox);
    q_start_x_label->setObjectName(QString::fromUtf8("q_start_x_label"));
    q_start_x_label->setGeometry(QRect(10, 152, 58, 16));
    q_start_x_spinBox = new QSpinBox(q_learning_groupBox);
    q_start_x_spinBox->setObjectName(QString::fromUtf8("q_start_x_spinBox"));
    q_start_x_spinBox->setGeometry(QRect(60, 150, 61, 22));
    q_start_x_spinBox->setMinimum(0);
    q_start_x_spinBox->setMaximum(50);
    q_start_x_spinBox->setValue(0);
    q_solve_maze_button = new QPushButton(q_learning_groupBox);
    q_solve_maze_button->setObjectName(
        QString::fromUtf8("q_solve_maze_button"));
    q_solve_maze_button->setEnabled(true);
    q_solve_maze_button->setGeometry(QRect(10, 174, 231, 32));
    tabWidget->addTab(tab_maze, QString());
    tab_cave = new QWidget();
    tab_cave->setObjectName(QString::fromUtf8("tab_cave"));
    load_cave_button = new QPushButton(tab_cave);
    load_cave_button->setObjectName(QString::fromUtf8("load_cave_button"));
    load_cave_button->setGeometry(QRect(520, 0, 121, 32));
    save_cave_button = new QPushButton(tab_cave);
    save_cave_button->setObjectName(QString::fromUtf8("save_cave_button"));
    save_cave_button->setGeometry(QRect(650, 0, 121, 32));
    cave_generation_groupBox = new QGroupBox(tab_cave);
    cave_generation_groupBox->setObjectName(
        QString::fromUtf8("cave_generation_groupBox"));
    cave_generation_groupBox->setGeometry(QRect(520, 30, 251, 141));
    number_columns_cave_label = new QLabel(cave_generation_groupBox);
    number_columns_cave_label->setObjectName(
        QString::fromUtf8("number_columns_cave_label"));
    number_columns_cave_label->setGeometry(QRect(10, 50, 141, 16));
    cave_generation_button = new QPushButton(cave_generation_groupBox);
    cave_generation_button->setObjectName(
        QString::fromUtf8("cave_generation_button"));
    cave_generation_button->setGeometry(QRect(10, 100, 231, 32));
    number_lines_cave_label = new QLabel(cave_generation_groupBox);
    number_lines_cave_label->setObjectName(
        QString::fromUtf8("number_lines_cave_label"));
    number_lines_cave_label->setGeometry(QRect(10, 25, 141, 16));
    number_lines_cave_spinBox = new QSpinBox(cave_generation_groupBox);
    number_lines_cave_spinBox->setObjectName(
        QString::fromUtf8("number_lines_cave_spinBox"));
    number_lines_cave_spinBox->setGeometry(QRect(180, 23, 61, 22));
    number_lines_cave_spinBox->setMinimum(3);
    number_lines_cave_spinBox->setMaximum(50);
    number_columns_cave_spinBox = new QSpinBox(cave_generation_groupBox);
    number_columns_cave_spinBox->setObjectName(
        QString::fromUtf8("number_columns_cave_spinBox"));
    number_columns_cave_spinBox->setGeometry(QRect(180, 48, 61, 22));
    number_columns_cave_spinBox->setMinimum(3);
    number_columns_cave_spinBox->setMaximum(50);
    initialization_chance_label = new QLabel(cave_generation_groupBox);
    initialization_chance_label->setObjectName(
        QString::fromUtf8("initialization_chance_label"));
    initialization_chance_label->setGeometry(QRect(10, 75, 141, 16));
    initialization_chance_doubleSpinBox =
        new QDoubleSpinBox(cave_generation_groupBox);
    initialization_chance_doubleSpinBox->setObjectName(
        QString::fromUtf8("initialization_chance_doubleSpinBox"));
    initialization_chance_doubleSpinBox->setGeometry(QRect(180, 73, 62, 22));
    initialization_chance_doubleSpinBox->setMaximum(1.000000000000000);
    initialization_chance_doubleSpinBox->setSingleStep(0.010000000000000);
    change_cave_groupBox = new QGroupBox(tab_cave);
    change_cave_groupBox->setObjectName(
        QString::fromUtf8("change_cave_groupBox"));
    change_cave_groupBox->setGeometry(QRect(520, 180, 251, 241));
    birth_limit_label = new QLabel(change_cave_groupBox);
    birth_limit_label->setObjectName(QString::fromUtf8("birth_limit_label"));
    birth_limit_label->setGeometry(QRect(10, 25, 141, 16));
    birth_limit_spinBox = new QSpinBox(change_cave_groupBox);
    birth_limit_spinBox->setObjectName(
        QString::fromUtf8("birth_limit_spinBox"));
    birth_limit_spinBox->setGeometry(QRect(180, 23, 61, 22));
    birth_limit_spinBox->setMinimum(0);
    birth_limit_spinBox->setMaximum(7);
    death_limit_label = new QLabel(change_cave_groupBox);
    death_limit_label->setObjectName(QString::fromUtf8("death_limit_label"));
    death_limit_label->setGeometry(QRect(10, 52, 141, 16));
    death_limit_spinBox = new QSpinBox(change_cave_groupBox);
    death_limit_spinBox->setObjectName(
        QString::fromUtf8("death_limit_spinBox"));
    death_limit_spinBox->setGeometry(QRect(180, 50, 61, 22));
    death_limit_spinBox->setMinimum(0);
    death_limit_spinBox->setMaximum(7);
    save_limits_button = new QPushButton(change_cave_groupBox);
    save_limits_button->setObjectName(QString::fromUtf8("save_limits_button"));
    save_limits_button->setGeometry(QRect(10, 80, 231, 32));
    change_cave_button = new QPushButton(change_cave_groupBox);
    change_cave_button->setObjectName(QString::fromUtf8("change_cave_button"));
    change_cave_button->setGeometry(QRect(10, 110, 231, 32));
    time_iterations_label = new QLabel(change_cave_groupBox);
    time_iterations_label->setObjectName(
        QString::fromUtf8("time_iterations_label"));
    time_iterations_label->setGeometry(QRect(10, 172, 141, 16));
    number_iterations_label = new QLabel(change_cave_groupBox);
    number_iterations_label->setObjectName(
        QString::fromUtf8("number_iterations_label"));
    number_iterations_label->setGeometry(QRect(10, 145, 141, 16));
    number_iterations_spinBox = new QSpinBox(change_cave_groupBox);
    number_iterations_spinBox->setObjectName(
        QString::fromUtf8("number_iterations_spinBox"));
    number_iterations_spinBox->setGeometry(QRect(160, 143, 81, 22));
    number_iterations_spinBox->setMinimum(0);
    number_iterations_spinBox->setMaximum(25);
    time_iterations_spinBox = new QSpinBox(change_cave_groupBox);
    time_iterations_spinBox->setObjectName(
        QString::fromUtf8("time_iterations_spinBox"));
    time_iterations_spinBox->setGeometry(QRect(160, 170, 81, 22));
    time_iterations_spinBox->setMinimum(0);
    time_iterations_spinBox->setMaximum(15000);
    time_iterations_spinBox->setSingleStep(1000);
    rendering_cave_button = new QPushButton(change_cave_groupBox);
    rendering_cave_button->setObjectName(
        QString::fromUtf8("rendering_cave_button"));
    rendering_cave_button->setGeometry(QRect(10, 200, 231, 32));
    tabWidget->addTab(tab_cave, QString());
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 24));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    tabWidget->setCurrentIndex(0);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    load_maze_button->setText(
        QCoreApplication::translate("MainWindow",
                                    "\320\227\320\260\320\263\321\200\321\203"
                                    "\320\267\320\270\321\202\321\214",
                                    nullptr));
    maze_generation_groupBox->setTitle(
        QCoreApplication::translate("MainWindow",
                                    "\320\223\320\265\320\275\320\265\321\200"
                                    "\320\260\321\206\320\270\321\217 "
                                    "\320\273\320\260\320\261\320\270\321\200"
                                    "\320\270\320\275\321\202\320\260",
                                    nullptr));
    number_lines_maze_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320"
        "\262\320\276 \321\201\321\202\321\200\320\276\320\272",
        nullptr));
    number_columns_maze_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320"
        "\262\320\276 "
        "\321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262",
        nullptr));
    maze_generation_button->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320"
        "\276\320\262\320\260\321\202\321\214 "
        "\320\273\320\260\320\261\320\270\321\200\320\270\320\275\321\202",
        nullptr));
    save_maze_button->setText(
        QCoreApplication::translate("MainWindow",
                                    "\320\241\320\276\321\205\321\200\320\260"
                                    "\320\275\320\270\321\202\321\214",
                                    nullptr));
    solve_maze_groupBox->setTitle(QCoreApplication::translate(
        "MainWindow",
        "\320\240\320\265\321\210\320\265\320\275\320\270\320\265 "
        "\320\273\320\260\320\261\320\270\321\200\320\270\320\275\321\202\320"
        "\260",
        nullptr));
    start_x_label->setText(
        QCoreApplication::translate("MainWindow", "Start x", nullptr));
    start_y_label->setText(
        QCoreApplication::translate("MainWindow", "Start y", nullptr));
    end_x_label->setText(
        QCoreApplication::translate("MainWindow", "End x", nullptr));
    end_y_label->setText(
        QCoreApplication::translate("MainWindow", "End y", nullptr));
    solve_maze_button->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\240\320\265\321\210\320\270\321\202\321\214 "
        "\320\273\320\260\320\261\320\270\321\200\320\270\320\275\321\202",
        nullptr));
    q_learning_groupBox->setTitle(QCoreApplication::translate(
        "MainWindow",
        "Q-\320\276\320\261\321\203\321\207\320\265\320\275\320\270\320\265",
        nullptr));
    q_end_x_label->setText(
        QCoreApplication::translate("MainWindow", "End x", nullptr));
    q_end_y_label->setText(
        QCoreApplication::translate("MainWindow", "End y", nullptr));
    end_maze_button->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\236\320\277\321\200\320\265\320\264\320\265\320\273\320\270\321"
        "\202\321\214 \320\272\320\276\320\275\320\265\321\206 "
        "\320\273\320\260\320\261\320\270\321\200\320\270\320\275\321\202\320"
        "\260",
        nullptr));
    count_episode_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320"
        "\262\320\276 "
        "\321\215\320\277\320\270\320\267\320\276\320\264\320\276\320\262",
        nullptr));
    train_agent_button->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\236\320\261\321\203\321\207\320\270\321\202\321\214 "
        "\320\260\320\263\320\265\320\275\321\202\320\260",
        nullptr));
    q_start_y_label->setText(
        QCoreApplication::translate("MainWindow", "Start y", nullptr));
    q_start_x_label->setText(
        QCoreApplication::translate("MainWindow", "Start x", nullptr));
    q_solve_maze_button->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\235\320\260\320\271\321\202\320\270 "
        "\320\277\321\203\321\202\321\214 "
        "\320\260\320\263\320\265\320\275\321\202\320\260",
        nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(tab_maze),
        QCoreApplication::translate(
            "MainWindow",
            "\320\233\320\260\320\261\320\270\321\200\320\270\320\275\321\202",
            nullptr));
    load_cave_button->setText(
        QCoreApplication::translate("MainWindow",
                                    "\320\227\320\260\320\263\321\200\321\203"
                                    "\320\267\320\270\321\202\321\214",
                                    nullptr));
    save_cave_button->setText(
        QCoreApplication::translate("MainWindow",
                                    "\320\241\320\276\321\205\321\200\320\260"
                                    "\320\275\320\270\321\202\321\214",
                                    nullptr));
    cave_generation_groupBox->setTitle(QCoreApplication::translate(
        "MainWindow",
        "\320\223\320\265\320\275\320\265\321\200\320\260\321\206\320\270\321"
        "\217 \320\277\320\265\321\211\320\265\321\200\321\213",
        nullptr));
    number_columns_cave_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320"
        "\262\320\276 "
        "\321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262",
        nullptr));
    cave_generation_button->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320"
        "\276\320\262\320\260\321\202\321\214 "
        "\320\277\320\265\321\211\320\265\321\200\321\203",
        nullptr));
    number_lines_cave_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320"
        "\262\320\276 \321\201\321\202\321\200\320\276\320\272",
        nullptr));
    initialization_chance_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\250\320\260\320\275\321\201 "
        "\320\270\320\275\320\270\321\206\320\270\320\260\320\273\320\270\320"
        "\267\320\260\321\206\320\270\320\270",
        nullptr));
    change_cave_groupBox->setTitle(QCoreApplication::translate(
        "MainWindow",
        "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320"
        "\265 \320\277\320\265\321\211\320\265\321\200\321\213",
        nullptr));
    birth_limit_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\233\320\270\320\274\320\270\321\202 "
        "\321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217",
        nullptr));
    death_limit_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\233\320\270\320\274\320\270\321\202 "
        "\321\201\320\274\320\265\321\200\321\202\320\270",
        nullptr));
    save_limits_button->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320"
        "\270\321\202\321\214 \320\273\320\270\320\274\320\270\321\202\321\213",
        nullptr));
    change_cave_button->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\260\321"
        "\217 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\321\217",
        nullptr));
    time_iterations_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\222\321\200\320\265\320\274\321\217 "
        "\320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\270 "
        "(\320\274\321\201)",
        nullptr));
    number_iterations_label->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320"
        "\262\320\276 "
        "\320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271",
        nullptr));
    rendering_cave_button->setText(
        QCoreApplication::translate("MainWindow",
                                    "\320\240\320\265\320\275\320\264\320\265"
                                    "\321\200\320\270\320\275\320\263",
                                    nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(tab_cave),
        QCoreApplication::translate(
            "MainWindow", "\320\237\320\265\321\211\320\265\321\200\320\260",
            nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
