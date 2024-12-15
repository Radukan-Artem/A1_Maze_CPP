#ifndef MAZE_HPP
#define MAZE_HPP

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// sleep
#include <unistd.h>

#define SIZE 10

#define COUNT_ACTIONS 4
#define EPSILON 0.9
#define DISCONT 0.9
#define LEARNING_RATE 0.9

#define MAIN_REWARD 1000.0
#define PUNISHMENT -1000.0
#define REWARD_FOR_MOVE -1.0

/**
 * @brief Действия, которые может выполнить агент в лабиринте.
 */
enum Actions { Up = 0, Left, Down, Right };

namespace s21 {

/**
 * @brief Функция для инициализации рандомного генератора.
 */
void set_rand();

/**
 * @brief Класс для работы с точками на плоскости.
 */
class Point {
 public:
  int x_ = 0;  ///< Координата X точки.
  int y_ = 0;  ///< Координата Y точки.

  /**
   * @brief Конструктор класса Point.
   *
   * @param x Координата X, по умолчанию 0.
   * @param y Координата Y, по умолчанию 0.
   */
  Point(int x = 0, int y = 0);

  /**
   * @brief Конструктор копирования класса Point.
   *
   * @param other Объект класса Point для копирования.
   */
  Point(const Point& other);

  /**
   * @brief Деструктор класса Point.
   */
  ~Point();

  Point& operator=(const Point& other);  ///< Оператор присваивания.
  bool operator==(const Point& other);  ///< Оператор сравнения на равенство.
  bool operator!=(const Point& other);  ///< Оператор сравнения на неравенство.
  Point& operator+=(const Point& other);  ///< Оператор сложения с другим Point.
  Point& operator-=(const Point& other);  ///< Оператор вычитания другого Point.

  /**
   * @brief Сравнивает два объекта Point на равенство.
   *
   * @param other Другой объект Point.
   * @return true, если точки равны, иначе false.
   */
  bool EqPoint(const Point& other);

  /**
   * @brief Очищает значения координат точки.
   */
  void clear();

  /**
   * @brief Поворачивает точку направо.
   */
  void turn_right();

  /**
   * @brief Поворачивает точку налево.
   */
  void turn_left();
};

/**
 * @brief Класс для работы с лабиринтом.
 */
class Maze {
 private:
  int count_rows_;  ///< Количество строк в лабиринте.
  int count_columns_;  ///< Количество столбцов в лабиринте.
  std::vector<bool>
      right_walls_;  ///< Вектор, содержащий информацию о правых стенах.
  std::vector<bool>
      lower_walls_;  ///< Вектор, содержащий информацию о нижних стенах.
  Point start_;      ///< Начальная точка лабиринта.
  Point end_;        ///< Конечная точка лабиринта.
  std::vector<Point> path_;  ///< Путь решения лабиринта.
  int length_path_;          ///< Длина пути.

  void set_count_row_columns(int row, int column);
  void clear_maze();
  void clear_path_maze();
  void set_assignment(std::vector<int>* line_walls);
  void creating_right_walls(std::vector<int>* line_walls, int number_row);
  void creating_lower_walls(std::vector<int>* line_walls, int number_row);
  void cleaning_line_walls(std::vector<int>* line_walls, int number_row);
  void last_line_adjustment(std::vector<int>* line_walls);
  void set_equalization(std::vector<int>* line_walls, int index_set);
  bool is_correct_step(const Point& point, const Point& direction);

 public:
  // Maze operator=(const Maze& other);

  // void test_init();

  /**
   * @brief Получает количество строк в лабиринте.
   *
   * @return Количество строк.
   */
  int get_count_rows();

  /**
   * @brief Получает количество столбцов в лабиринте.
   *
   * @return Количество столбцов.
   */
  int get_count_columns();

  /**
   * @brief Проверяет наличие правой стены.
   *
   * @param row Номер строки.
   * @param column Номер столбца.
   * @return true, если стена есть, иначе false.
   */
  bool get_right_wall(int row, int column);

  /**
   * @brief Проверяет наличие нижней стены.
   *
   * @param row Номер строки.
   * @param column Номер столбца.
   * @return true, если стена есть, иначе false.
   */
  bool get_lower_wall(int row, int column);

  /**
   * @brief Генерирует лабиринт заданного размера.
   *
   * @param new_count_rows Количество строк.
   * @param new_count_columns Количество столбцов.
   */
  void generation_maze(int new_count_rows, int new_count_columns);

  /**
   * @brief Устанавливает начальную точку лабиринта.
   *
   * @param x Координата X начальной точки.
   * @param y Координата Y начальной точки.
   */
  void set_start(int x, int y);

  /**
   * @brief Устанавливает конечную точку лабиринта.
   *
   * @param x Координата X конечной точки.
   * @param y Координата Y конечной точки.
   */
  void set_end(int x, int y);

  /**
   * @brief Устанавливает случайные начальную и конечную точки лабиринта.
   */
  void random_start_end();

  /**
   * @brief Устанавливает начальную и конечную точки лабиринта.
   *
   * @param start_x Координата X начальной точки.
   * @param start_y Координата Y начальной точки.
   * @param end_x Координата X конечной точки.
   * @param end_y Координата Y конечной точки.
   */
  void set_start_end(int start_x, int start_y, int end_x, int end_y);

  /**
   * @brief Находит путь через лабиринт.
   */
  void find_path();

  /**
   * @brief Получает длину пути решения лабиринта.
   *
   * @return Длина пути.
   */
  int get_length_path();

  /**
   * @brief Получает точку пути по индексу.
   *
   * @param index Индекс точки в пути.
   * @return Ссылка на объект Point.
   */
  Point& get_point_path(int index);

  /**
   * @brief Получает конечную точку лабиринта.
   *
   * @return Ссылка на объект Point.
   */
  Point& get_end();

  /**
   * @brief Читает лабиринт из файла.
   *
   * @param path Путь к файлу.
   */
  void read_file(std::string path);

  /**
   * @brief Сохраняет лабиринт в файл.
   *
   * @param path Путь к файлу.
   */
  void save_file(std::string path);

  //__________

  /**
   * @brief Выполняет шаг агента в лабиринте.
   *
   * @param state Текущая точка.
   * @param new_state Новая точка после выполнения действия.
   * @param reward Награда за действие.
   * @param action Действие, которое выполняется.
   * @return true, если действие выполнено корректно, иначе false.
   */
  bool make_move(Point& state, Point* new_state, double* reward,
                 Actions action);

  /**
   * @brief Получает начальную точку для обучения агента.
   *
   * @return Точка старта для обучения.
   */
  Point get_start_for_training();

  /**
   * @brief Конвертирует действие в направление движения.
   *
   * @param action Действие, выполняемое агентом.
   * @param direction Направление движения.
   */
  void actions_to_direction(Actions action, Point* direction);
};

/**
 * @brief Класс для управления агентом, который обучается и решает лабиринт.
 */
class Agent {
 private:
  Maze* environment_;  ///< Указатель на среду лабиринта.
  int count_actions_;  ///< Количество возможных действий.
  std::vector<std::vector<double>>
      q_values_;  ///< Q-значения для действий в каждом состоянии.
  std::vector<Point> path_;  ///< Путь агента через лабиринт.
  double epsilon_;  ///< Вероятность выбора случайного действия (для
                    ///< epsilon-жадной стратегии).
  double discont_;  ///< Коэффициент дисконтирования награды.
  double learning_rate_;  ///< Скорость обучения агента.
  Point state_;           ///< Текущее состояние агента.

  int get_index_action_with_max_value(int index_state);
  Actions get_new_actions(int index_state);
  double get_max_value_by_index(int index_state);

 public:
  /**
   * @brief Конструктор класса Agent.
   *
   * @param new_environment Указатель на лабиринт для обучения.
   */
  Agent(Maze* new_environment);

  /**
   * @brief Деструктор класса Agent.
   */
  ~Agent();

  /**
   * @brief Инициализирует нового агента с новой средой.
   *
   * @param new_environment Указатель на новый лабиринт.
   */
  void init_new_environment(Maze* new_environment);

  /**
   * @brief Очищает текущее состояние агента и его пути.
   */
  void clear();

  /**
   * @brief Обучает агента на протяжении заданного количества эпизодов.
   *
   * @param count_episode Количество эпизодов обучения, по умолчанию 1000.
   */
  void training(int count_episode = 1000);

  /**
   * @brief Инициализирует состояние агента.
   */
  void init_state();

  /**
   * @brief Выполняет действие агентом.
   *
   * @return true, если действие выполнено успешно, иначе false.
   */
  bool perform_action();

  /**
   * @brief Находит путь от заданной точки старта.
   *
   * @param start Точка старта.
   */
  void find_path(Point start);

  /**
   * @brief Получает точку пути по индексу.
   *
   * @param index Индекс точки в пути.
   * @return Ссылка на объект Point.
   */
  Point& get_point_path(int index);

  /**
   * @brief Получает текущее состояние агента.
   *
   * @return Ссылка на объект Point.
   */
  Point& get_state();

  /**
   * @brief Получает длину пути решения лабиринта агентом.
   *
   * @return Длина пути.
   */
  int get_length_path();
};

}  // namespace s21

#endif  // MAZE_HPP
