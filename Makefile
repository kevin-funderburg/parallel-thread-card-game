sim: pairwar.o
	g++ -std=c++11 pairwar.o -o pairwar
sim.o: pairwar.c
	g++ -Wall -ansi -pedantic -std=c++11 -c pairwar.c
clean:
	@rm -rf pairwar.o
cleanall:
	@rm -rf pairwar.o pairwar
