#ifndef CAVE_HPP
#define CAVE_HPP

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// для тестов
#define SIZE_CAVE 50
#define DEATH_LIMIT 5
#define BIRTH_LIMIT 5

#define DEFAULT_DEATH_LIMIT 3
#define DEFAULT_BIRTH_LIMIT 5
#define DEFAULT_INITIALIZATION_CHANCE 0.5

namespace s21 {

/**
 * @brief Класс для моделирования пещеры с живыми и мертвыми клетками.
 */
class Cave {
 private:
  int count_rows_;     ///< Количество строк в пещере.
  int count_columns_;  ///< Количество столбцов в пещере.
  int death_limit_;    ///< Порог для смерти клетки.
  int birth_limit_;    ///< Порог для рождения клетки.
  std::vector<bool>
      cells_;  ///< Вектор клеток: false -> мертвая; true -> живая.
  double initialization_chance_;  ///< Вероятность начального заполнения клеток.

  /**
   * @brief Подсчитывает количество живых клеток вокруг данной клетки.
   *
   * @param index_row Индекс строки клетки.
   * @param index_column Индекс столбца клетки.
   * @return Количество живых клеток вокруг.
   */
  int get_count_lives_around(int index_row, int index_column);

  /**
   * @brief Проверяет, нужно ли менять состояние клетки.
   *
   * @param index_row Индекс строки клетки.
   * @param index_column Индекс столбца клетки.
   * @return true, если состояние клетки нужно изменить, иначе false.
   */
  bool check_need_change(int index_row, int index_column);

 public:
  /**
   * @brief Конструктор по умолчанию.
   */
  Cave();

  /**
   * @brief Конструктор с параметрами для инициализации пещеры.
   *
   * @param count_row Количество строк.
   * @param count_columns Количество столбцов.
   * @param death_limit Порог для смерти клетки.
   * @param birth_limit Порог для рождения клетки.
   * @param initialization_chance Вероятность начального заполнения клеток.
   */
  Cave(int count_row, int count_columns, int death_limit = DEFAULT_DEATH_LIMIT,
       int birth_limit = DEFAULT_BIRTH_LIMIT,
       double initialization_chance = DEFAULT_INITIALIZATION_CHANCE);

  /**
   * @brief Конструктор для создания пещеры из файла.
   *
   * @param path Путь к файлу.
   * @param death_limit Порог для смерти клетки.
   * @param birth_limit Порог для рождения клетки.
   */
  Cave(std::string path, int death_limit = DEFAULT_DEATH_LIMIT,
       int birth_limit = DEFAULT_BIRTH_LIMIT);

  /**
   * @brief Деструктор класса Cave.
   */
  ~Cave();

  /**
   * @brief Очищает текущую пещеру, делая все клетки мертвыми.
   */
  void clear();

  /**
   * @brief Инициализирует новую пещеру заданного размера.
   *
   * @param count_row Количество строк.
   * @param count_columns Количество столбцов.
   * @param death_limit Порог для смерти клетки.
   * @param birth_limit Порог для рождения клетки.
   * @param initialization_chance Вероятность начального заполнения клеток.
   */
  void init_cave(int count_row, int count_columns,
                 int death_limit = DEFAULT_DEATH_LIMIT,
                 int birth_limit = DEFAULT_BIRTH_LIMIT,
                 double initialization_chance = DEFAULT_INITIALIZATION_CHANCE);

  /**
   * @brief Читает пещеру из файла.
   *
   * @param path Путь к файлу.
   * @param death_limit Порог для смерти клетки.
   * @param birth_limit Порог для рождения клетки.
   */
  void read_file(std::string path, int death_limit = DEFAULT_DEATH_LIMIT,
                 int birth_limit = DEFAULT_BIRTH_LIMIT);

  /**
   * @brief Сохраняет текущую пещеру в файл.
   *
   * @param path Путь к файлу.
   */
  void save_file(std::string path);

  /**
   * @brief Изменяет порог для смерти клетки.
   *
   * @param death_limit Новый порог для смерти клетки.
   */
  void change_death_limit(int death_limit);

  /**
   * @brief Изменяет порог для рождения клетки.
   *
   * @param birth_limit Новый порог для рождения клетки.
   */
  void change_birth_limit(int birth_limit);

  /**
   * @brief Изменяет вероятность начального заполнения клеток.
   *
   * @param initialization_chance Новая вероятность заполнения.
   */
  void change_initialization_chance(double initialization_chance);

  /**
   * @brief Получает значение клетки (живая или мертвая).
   *
   * @param index_row Индекс строки клетки.
   * @param index_column Индекс столбца клетки.
   * @return true, если клетка живая, иначе false.
   */
  bool get_value_cell(int index_row, int index_column);

  /**
   * @brief Производит изменение состояния клеток в пещере на основе правил.
   */
  void make_change();

  /**
   * @brief Получает количество строк в пещере.
   *
   * @return Количество строк.
   */
  int get_count_rows();

  /**
   * @brief Получает количество столбцов в пещере.
   *
   * @return Количество столбцов.
   */
  int get_count_columns();
};

}  // namespace s21

#endif  // CAVE_HPP
