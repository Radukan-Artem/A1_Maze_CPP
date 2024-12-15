#include "cave.hpp"

s21::Cave::Cave() {
  count_rows_ = 0;
  count_columns_ = 0;
  change_death_limit(DEFAULT_DEATH_LIMIT);
  change_birth_limit(DEFAULT_BIRTH_LIMIT);
  change_initialization_chance(DEFAULT_INITIALIZATION_CHANCE);
}

s21::Cave::Cave(int count_row, int count_columns, int death_limit,
                int birth_limit, double initialization_chance) {
  init_cave(count_row, count_columns, death_limit, birth_limit,
            initialization_chance);
}

s21::Cave::Cave(std::string path, int death_limit, int birth_limit) {
  read_file(path, death_limit, birth_limit);
}

s21::Cave::~Cave() { clear(); }

void s21::Cave::clear() {
  cells_.clear();
  count_rows_ = 0;
  count_columns_ = 0;
}

void s21::Cave::init_cave(int count_row, int count_columns, int death_limit,
                          int birth_limit, double initialization_chance) {
  clear();
  count_rows_ = count_row;
  count_columns_ = count_columns;

  change_death_limit(death_limit);
  change_birth_limit(birth_limit);
  change_initialization_chance(initialization_chance);
  for (int i = 0; i < count_rows_; i++) {
    for (int j = 0; j < count_columns_; j++) {
      if ((double)(rand()) / RAND_MAX < initialization_chance_) {
        cells_.push_back(true);
      } else {
        cells_.push_back(false);
      }
    }
  }
}

void s21::Cave::read_file(std::string path, int death_limit, int birth_limit) {
  clear();
  change_death_limit(death_limit);
  change_birth_limit(birth_limit);
  std::ifstream in(path);
  if (in.is_open()) {
    bool elem = false;
    in >> count_rows_;
    in >> count_columns_;

    for (int i = 0; i < count_rows_; i++) {
      for (int j = 0; j < count_columns_; j++) {
        in >> elem;
        cells_.push_back(elem);
      }
    }
  }
  in.close();
}

void s21::Cave::save_file(std::string path) {
  std::ofstream out;  // поток для записи
  out.open(path);     // открываем файл для записи
  if (out.is_open()) {
    out << count_rows_ << " " << count_columns_ << std::endl;
    for (int i = 0; i < count_rows_; i++) {
      for (int j = 0; j < count_columns_; j++) {
        out << (int)get_value_cell(i, j) << " ";
      }
      out << std::endl;
    }
  }
  out.close();
}

void s21::Cave::change_death_limit(int death_limit) {
  if (death_limit < 0) {
    death_limit_ = 0;
  } else if (death_limit > 7) {
    death_limit_ = 7;
  } else {
    death_limit_ = death_limit;
  }
}
void s21::Cave::change_birth_limit(int birth_limit) {
  if (birth_limit < 0) {
    birth_limit_ = 0;
  } else if (birth_limit > 7) {
    birth_limit_ = 7;
  } else {
    birth_limit_ = birth_limit;
  }
}

void s21::Cave::change_initialization_chance(double initialization_chance) {
  if (initialization_chance < 0) {
    initialization_chance_ = 0.0;
  } else if (initialization_chance > 1) {
    initialization_chance_ = 1.0;
  } else {
    initialization_chance_ = initialization_chance;
  }
}

bool s21::Cave::get_value_cell(int index_row, int index_column) {
  bool result = true;
  if (index_row >= 0 && index_row < count_rows_ && index_column >= 0 &&
      index_column < count_columns_) {
    result = cells_[index_row * count_columns_ + index_column];
  }
  return result;
}

void s21::Cave::make_change() {
  std::vector<bool> list_changes;
  for (int i = 0; i < count_rows_; i++) {
    for (int j = 0; j < count_columns_; j++) {
      list_changes.push_back(check_need_change(i, j));
    }
  }

  for (int i = 0; i < count_rows_; i++) {
    for (int j = 0; j < count_columns_; j++) {
      if (list_changes[i * count_columns_ + j]) {
        cells_[i * count_columns_ + j] = !cells_[i * count_columns_ + j];
      }
    }
  }
}

int s21::Cave::get_count_lives_around(int index_row, int index_column) {
  int result = 0;

  result += get_value_cell(index_row - 1, index_column - 1);
  result += get_value_cell(index_row - 1, index_column);
  result += get_value_cell(index_row - 1, index_column + 1);
  result += get_value_cell(index_row, index_column - 1);
  result += get_value_cell(index_row, index_column + 1);
  result += get_value_cell(index_row + 1, index_column - 1);
  result += get_value_cell(index_row + 1, index_column);
  result += get_value_cell(index_row + 1, index_column + 1);

  return result;
}

bool s21::Cave::check_need_change(int index_row, int index_column) {
  bool result = false;
  int count_lives = get_count_lives_around(index_row, index_column);
  if (get_value_cell(index_row, index_column)) {
    if (count_lives < death_limit_) {
      result = true;
    } else {
      result = false;
    }
  } else {
    if (count_lives > birth_limit_) {
      result = true;
    } else {
      result = false;
    }
  }

  return result;
}

int s21::Cave::get_count_rows() { return count_rows_; }

int s21::Cave::get_count_columns() { return count_columns_; }
