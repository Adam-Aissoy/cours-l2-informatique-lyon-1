all: monprog
monprog:TableauDynamique.o main.o ElementTD.o
	g++ -g TableauDynamique.o main.o ElementTD.o -o monprog.out
main.o:main.cpp TableauDynamique.h ElementTD.h
	g++ -g –Wall –c main.cpp
TableauDynamique.o:TableauDynamique.cpp ElementTD.h
	g++ -g -Wall -c TableauDynamique.cpp
ElementTD.o:ElementTD.cpp
	g++ -g -Wall -c ElementTD.cpp

clean: 
	rm*.o
