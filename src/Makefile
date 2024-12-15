CPP=clang++
CPPFLAGS=-c -Wall  -Werror -Wextra -g -std=c++17
CCTEST=clang++ -fprofile-arcs -ftest-coverage

all: clean install styleformat

maze_cave.a:
	$(CCTEST) $(CPPFLAGS) -c Model/maze.cpp Model/cave.cpp
	ar rc maze_cave.a maze.o cave.o

compile_unit_tests: maze_cave.a
	$(CCTEST) $(CPPFLAGS) Model/Tests/unit_tests.cpp Model/Tests/test_suite_creation_functions/*.cpp
	$(CCTEST) unit_tests.o tests_*.o maze_cave.a -o unit_tests -lgtest


install:
	@mkdir -p build
	@cd View && qmake && make && mv View.app ../build/Maze_Cave.app

uninstall:
	rm -rf build

tests: clean compile_unit_tests
	./unit_tests

styleformat:
	find . -type f | grep "\.(c|cc|cpp|h|hpp|tpp|inc)$$" -E | xargs clang-format -i --verbose --Werror

stylecheck:
	find . -type f | grep "\.(c|cc|cpp|h|hpp|tpp|inc)$$" -E | xargs clang-format -n --verbose --Werror

test_asan: tests
	./unit_tests -fmp-omit-pointer -fsanitize=address


clean:
	rm -rf result View/*.o View/Makefile View/.qmake*
	rm -rf *.o *.a *.gcno *.gcda *.info *.gcov *.so unit_tests
	rm -rf report
	rm -rf obj *.dSYM **/*.dSYM html latex
	

dist:
	@mkdir -p ../dist
	@cp -R build/Maze_Cave.app ../dist
	@cd ../dist && tar cvzf Maze_Cave.tgz *
	@cd ../dist && rm -rf Maze_Cave.app
	
#3 @cp doc/3d_viewer.md ../dist && cp doc/3d_viewer.texi ../dist
#5 @cd ../dist && rm -rf Maze_Cave.app 3d_viewer.md 3d_viewer.texi

dvi:
	doxygen Doxyfile
	open ./html/index.html
