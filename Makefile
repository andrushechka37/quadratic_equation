
start: main.o check.o solve.o
	clang++ main.o check.o solve.o -o output

main.o: main.cpp solve.h read_coefficient.h
	clang++ -c main.cpp

check.o: check.cpp solve.h read_coefficient.h testing.h
	clang++ -c check.cpp

solve.o: solve.cpp solve.h read_coefficient.h testing.h
	clang++ -c solve.cpp



test: main_test.o  solve.o unit_tests.o
	clang++ main_test.o  solve.o unit_tests.o -o output

main_test.o: main_test.cpp solve.h read_coefficient.h testing.h
	clang++ -c main_test.cpp

solve.o: solve.cpp solve.h read_coefficient.h testing.h
	clang++ -c solve.cpp

unit_tests.o: unit_tests.cpp solve.h read_coefficient.h testing.h
	clang++ -c unit_tests.cpp

