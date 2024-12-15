#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <unistd.h>

#include <QFileDialog>
#include <QMainWindow>
#include <QPainter>
#include <QTime>
#include <QTimer>

#include "../Model/cave.hpp"
#include "../Model/maze.hpp"

#define WALL_WIDTH 2

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief The MainWindow class
 *
 * Основной класс главного окна приложения. Отвечает за визуализацию и обработку
 * взаимодействия с пользователем для работы с лабиринтами и пещерами.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief Конструктор класса MainWindow
   *
   * Инициализирует главное окно приложения.
   *
   * @param parent Родительский виджет, по умолчанию nullptr.
   */
  MainWindow(QWidget *parent = nullptr);

  /**
   * @brief Деструктор класса MainWindow
   */
  ~MainWindow();

 private:
  Ui::MainWindow *ui;  ///< Указатель на пользовательский интерфейс.
  s21::Maze maze_;  ///< Объект для работы с лабиринтом.
  s21::Agent
      *agent_;  ///< Указатель на агента для обучения и решения лабиринтов.
  int x_field_;            ///< Координата X поля.
  int y_field_;            ///< Координата Y поля.
  double corridor_width_;  ///< Ширина коридора в лабиринте.
  double corridor_height_;  ///< Высота коридора в лабиринте.

  s21::Cave cave_;  ///< Объект для работы с пещерами.
  double cell_width_;   ///< Ширина ячейки в пещере.
  double cell_height_;  ///< Высота ячейки в пещере.
  QTimer *timer;        ///< Таймер для обновлений.
  int count_iterators;  ///< Счетчик итераций.

  /**
   * @brief Назначает функции на кнопки интерфейса.
   */
  void assign_functions_to_buttons();

  /**
   * @brief Событие перерисовки окна.
   *
   * @param event Указатель на событие отрисовки.
   */
  void paintEvent(QPaintEvent *event) override;

  /**
   * @brief Рисует лабиринт.
   *
   * @param painter Указатель на объект QPainter для рисования.
   */
  void paint_maze(QPainter *painter);

  /**
   * @brief Рассчитывает размеры коридоров лабиринта.
   */
  void calculate_size_corridors();

  /**
   * @brief Рисует решение лабиринта.
   *
   * @param painter Указатель на объект QPainter для рисования.
   */
  void paint_solution_maze(QPainter *painter);

  /**
   * @brief Рисует решение лабиринта с использованием Q-learning.
   *
   * @param painter Указатель на объект QPainter для рисования.
   */
  void paint_q_solution_maze(QPainter *painter);

  /**
   * @brief Рисует пещеру.
   *
   * @param painter Указатель на объект QPainter для рисования.
   */
  void paint_cave(QPainter *painter);

  /**
   * @brief Загружает настройки по умолчанию для пещеры.
   */
  void load_default_settings_cave();

  /**
   * @brief Рассчитывает размеры ячеек пещеры.
   */
  void calculate_size_cells();

 private slots:
  /**
   * @brief Слот для загрузки лабиринта.
   */
  void load_maze_click();

  /**
   * @brief Слот для генерации лабиринта.
   */
  void maze_generation_click();

  /**
   * @brief Слот для сохранения лабиринта.
   */
  void save_maze_click();

  /**
   * @brief Слот для решения лабиринта.
   */
  void solve_maze_click();

  /**
   * @brief Слот для завершения работы с лабиринтом.
   */
  void end_maze_click();

  /**
   * @brief Слот для тренировки агента.
   */
  void train_agent_click();

  /**
   * @brief Слот для решения лабиринта с использованием Q-learning.
   */
  void q_solve_maze_click();

  /**
   * @brief Слот для загрузки пещеры.
   */
  void load_cave_click();

  /**
   * @brief Слот для сохранения пещеры.
   */
  void save_cave_click();

  /**
   * @brief Слот для генерации пещеры.
   */
  void cave_generation_click();

  /**
   * @brief Слот для сохранения пределов пещеры.
   */
  void save_limits_click();

  /**
   * @brief Слот для изменения параметров пещеры.
   */
  void change_cave_click();

  /**
   * @brief Слот для рендеринга пещеры.
   */
  void rendering_cave_click();
};

#endif  // MAINWINDOW_H
