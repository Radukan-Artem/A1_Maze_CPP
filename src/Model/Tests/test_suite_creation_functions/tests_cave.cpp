
#include "../unit_tests.hpp"

void check_cave_parameters(s21::Cave test_cave, int current_count_rows,
                           int current_count_columns) {
  EXPECT_EQ(test_cave.get_count_rows(), current_count_rows);
  EXPECT_EQ(test_cave.get_count_columns(), current_count_columns);
}

void check_cells_cave(s21::Cave test_cave,
                      std::vector<std::vector<bool>> current_cell) {
  for (int i = 0; i < test_cave.get_count_rows(); i++) {
    for (int j = 0; j < test_cave.get_count_columns(); j++) {
      EXPECT_EQ(test_cave.get_value_cell(i, j), current_cell[i][j]);
    }
  }
}

void check_eq_caves(s21::Cave test_cave, s21::Cave copy_cave) {
  EXPECT_EQ(test_cave.get_count_columns(), copy_cave.get_count_columns());
  EXPECT_EQ(test_cave.get_count_rows(), copy_cave.get_count_rows());
  for (int i = 0; i < test_cave.get_count_rows(); i++) {
    for (int j = 0; j < test_cave.get_count_columns(); j++) {
      EXPECT_EQ(test_cave.get_value_cell(i, j), copy_cave.get_value_cell(i, j));
      EXPECT_EQ(test_cave.get_value_cell(i, j), copy_cave.get_value_cell(i, j));
    }
  }
}

TEST(TestCave, Test_cave_0) {
  s21::Cave test_cave("cave_1.txt");

  std::vector<std::vector<bool>> current_cells = {
      {1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
      {0, 0, 1, 0, 1, 0, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
      {1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
      {1, 0, 0, 0, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 1, 1, 0, 0, 0}};

  check_cave_parameters(test_cave, 10, 10);
  check_cells_cave(test_cave, current_cells);

  test_cave.change_death_limit(3);
  test_cave.change_birth_limit(4);
  test_cave.change_initialization_chance(0.5);
  for (int i = 0; i < 10; i++) {
    test_cave.make_change();
  }

  std::vector<std::vector<bool>> current_cells_after_updates = {
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
      {1, 1, 0, 0, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

  check_cells_cave(test_cave, current_cells_after_updates);
}

TEST(TestCave, Test_cave_1) {
  s21::Cave test_cave(10, 10);
  test_cave.change_initialization_chance(0.5);
  test_cave.init_cave(10, 10);
  test_cave.save_file("generation_cave.txt");

  s21::Cave copy_cave;
  copy_cave.read_file("generation_cave.txt");

  check_eq_caves(test_cave, copy_cave);
}