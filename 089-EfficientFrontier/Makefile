CCFLAGS=--std=gnu++98 -pedantic -Wall -Werror -ggdb3
efficient_frontier: parse.o main.o
	g++ -o efficient_frontier $(CCFLAGS) parse.o main.o
parse.o: parse.cpp parse.hpp asset.hpp portfolio.hpp
	g++ -c $(CCFLAGS) -o parse.o parse.cpp
efficient_frontier.o: efficient_frontier.cpp asset.hpp parse.hpp portfolio.hpp
	g++ -c $(CCFLAGS) -o main.o efficient_frontier

clean:
	rm -f *.o  *~ efficient_frontier
