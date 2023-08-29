
start: main.o check.o solve.o work_with_command_line.o
	clang++ main.o check.o solve.o work_with_command_line.cpp -o output

main.o: main.cpp solve.h read_coefficient.h
	clang++ -c main.cpp

check.o: check.cpp solve.h read_coefficient.h unit_tests.h
	clang++ -c check.cpp

solve.o: solve.cpp solve.h read_coefficient.h unit_tests.h
	clang++ -c solve.cpp
work_with_command_line.o: work_with_command_line.cpp read_coefficient.h
	clang++ -c work_with_command_line.cpp



test: main_test.o  solve.o unit_tests.o
	clang++ main_test.o  solve.o unit_tests.o -o output

main_test.o: main_test.cpp solve.h read_coefficient.h unit_tests.h
	clang++ -c main_test.cpp

solve.o: solve.cpp solve.h read_coefficient.h unit_tests.h
	clang++ -c solve.cpp

unit_tests.o: unit_tests.cpp solve.h read_coefficient.h unit_tests.h
	clang++ -c unit_tests.cpp

