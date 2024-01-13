CCFLAGS=--std=c++17 -pedantic -Wall -Werror -ggdb3

kubok: parse.o main.o solver.o
	g++ -o kubok $(CCFLAGS) parse.o main.o solver.o
solver.o: solver.cpp solver.hpp
	g++ -c $(CCFLAGS) -o solver.o solver.cpp
parse.o: parse.cpp parse.hpp
	g++ -c $(CCFLAGS) -o parse.o parse.cpp
main.o: main.cpp parse.hpp solver.hpp
	g++ -c $(CCFLAGS) -o main.o main.cpp


