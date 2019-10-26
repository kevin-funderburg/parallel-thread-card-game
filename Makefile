sim: main.o
	g++ -std=c++11 main.o -o main
sim.o: main.cpp
	g++ -Wall -ansi -pedantic -std=c++11 -c main.cpp -lpthread
clean:
	@rm -rf main.o
cleanall:
	@rm -rf main.o main
