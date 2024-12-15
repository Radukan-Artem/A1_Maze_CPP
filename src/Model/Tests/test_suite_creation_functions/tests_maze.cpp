
#include "../unit_tests.hpp"

void check_maze_parameters(s21::Maze test_maze, int current_count_rows,
                           int current_count_columns) {
  EXPECT_EQ(test_maze.get_count_rows(), current_count_rows);
  EXPECT_EQ(test_maze.get_count_columns(), current_count_columns);
}

void check_right_walls_maze(s21::Maze test_maze,
                            std::vector<std::vector<bool>> current_walls) {
  for (int i = 0; i < test_maze.get_count_rows(); i++) {
    for (int j = 0; j < test_maze.get_count_columns(); j++) {
      EXPECT_EQ(test_maze.get_right_wall(i, j), current_walls[i][j]);
    }
  }
}

void check_lower_walls_maze(s21::Maze test_maze,
                            std::vector<std::vector<bool>> current_walls) {
  for (int i = 0; i < test_maze.get_count_rows(); i++) {
    for (int j = 0; j < test_maze.get_count_columns(); j++) {
      EXPECT_EQ(test_maze.get_lower_wall(i, j), current_walls[i][j]);
    }
  }
}

void check_path_maze(s21::Maze test_maze,
                     std::vector<s21::Point> current_path) {
  EXPECT_EQ(test_maze.get_length_path(), int(current_path.size()));
  for (int i = 0; i < test_maze.get_length_path(); i++) {
    EXPECT_EQ(test_maze.get_point_path(i).x_, current_path[i].x_);
    EXPECT_EQ(test_maze.get_point_path(i).y_, current_path[i].y_);
  }
}

void check_eq_mazes(s21::Maze test_maze, s21::Maze copy_maze) {
  EXPECT_EQ(test_maze.get_count_columns(), copy_maze.get_count_columns());
  EXPECT_EQ(test_maze.get_count_rows(), copy_maze.get_count_rows());
  for (int i = 0; i < test_maze.get_count_rows(); i++) {
    for (int j = 0; j < test_maze.get_count_columns(); j++) {
      EXPECT_EQ(test_maze.get_lower_wall(i, j), copy_maze.get_lower_wall(i, j));
      EXPECT_EQ(test_maze.get_right_wall(i, j), copy_maze.get_right_wall(i, j));
    }
  }
}

void check_path_agent(s21::Agent test_agent,
                      std::vector<s21::Point> current_path) {
  EXPECT_EQ(test_agent.get_length_path(), int(current_path.size()));
  for (int i = 0; i < test_agent.get_length_path(); i++) {
    EXPECT_EQ(test_agent.get_point_path(i).x_, current_path[i].x_);
    EXPECT_EQ(test_agent.get_point_path(i).y_, current_path[i].y_);
  }
}

TEST(TestMaze, Test_maze_0) {
  s21::Maze test_maze;
  test_maze.read_file("maze_1.txt");
  test_maze.random_start_end();
  test_maze.set_start_end(0, 0, 9, 9);
  test_maze.find_path();

  std::vector<std::vector<bool>> current_right_walls = {
      {0, 0, 1, 0, 0, 0, 0, 1, 0, 1}, {0, 1, 1, 1, 0, 0, 0, 1, 1, 1},
      {1, 0, 1, 0, 0, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 1, 0, 1, 1},
      {0, 0, 1, 0, 1, 0, 1, 0, 1, 1}, {1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
      {0, 0, 0, 1, 1, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
      {1, 0, 0, 0, 1, 1, 1, 0, 0, 1}, {0, 1, 0, 1, 0, 1, 0, 0, 0, 1}};

  std::vector<std::vector<bool>> current_lower_walls = {
      {0, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 1, 0, 0, 1, 0},
      {1, 0, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 0, 0, 0, 0},
      {1, 1, 0, 1, 0, 0, 1, 0, 1, 1}, {0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
      {1, 0, 1, 0, 0, 0, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

  std::vector<s21::Point> current_path = {
      s21::Point(0, 0), s21::Point(1, 0), s21::Point(2, 0), s21::Point(2, 1),
      s21::Point(2, 2), s21::Point(1, 2), s21::Point(1, 3), s21::Point(2, 3),
      s21::Point(3, 3), s21::Point(3, 4), s21::Point(4, 4), s21::Point(4, 3),
      s21::Point(5, 3), s21::Point(5, 2), s21::Point(4, 2), s21::Point(3, 2),
      s21::Point(3, 1), s21::Point(3, 0), s21::Point(4, 0), s21::Point(4, 1),
      s21::Point(5, 1), s21::Point(6, 1), s21::Point(7, 1), s21::Point(7, 2),
      s21::Point(7, 3), s21::Point(8, 3), s21::Point(8, 2), s21::Point(8, 1),
      s21::Point(8, 0), s21::Point(9, 0), s21::Point(9, 1), s21::Point(9, 2),
      s21::Point(9, 3), s21::Point(9, 4), s21::Point(9, 5), s21::Point(9, 6),
      s21::Point(8, 6), s21::Point(8, 5), s21::Point(7, 5), s21::Point(7, 6),
      s21::Point(6, 6), s21::Point(5, 6), s21::Point(5, 7), s21::Point(6, 7),
      s21::Point(6, 8), s21::Point(6, 9), s21::Point(7, 9), s21::Point(8, 9),
      s21::Point(9, 9)};

  check_maze_parameters(test_maze, 10, 10);
  check_right_walls_maze(test_maze, current_right_walls);
  check_lower_walls_maze(test_maze, current_lower_walls);
  check_path_maze(test_maze, current_path);
}

TEST(TestMaze, Test_maze_1) {
  s21::Maze test_maze;
  test_maze.generation_maze(10, 10);
  test_maze.save_file("generation_maze.txt");

  s21::Maze copy_maze;
  copy_maze.read_file("generation_maze.txt");

  check_eq_mazes(test_maze, copy_maze);
}

TEST(TestMaze, Test_maze_2) {
  s21::Maze test_maze;
  test_maze.read_file("maze_1.txt");
  test_maze.set_start_end(0, 0, 5, 5);

  std::vector<s21::Point> current_path = {
      s21::Point(0, 0), s21::Point(1, 0), s21::Point(2, 0), s21::Point(2, 1),
      s21::Point(2, 2), s21::Point(1, 2), s21::Point(1, 3), s21::Point(2, 3),
      s21::Point(3, 3), s21::Point(3, 4), s21::Point(4, 4), s21::Point(4, 3),
      s21::Point(5, 3), s21::Point(6, 3), s21::Point(6, 4), s21::Point(5, 4),
      s21::Point(5, 5)};

  s21::Agent test_agent(&test_maze);
  test_agent.training(100000);
  s21::Point start_point(0, 0);
  test_agent.find_path(start_point);
  check_path_agent(test_agent, current_path);
}
