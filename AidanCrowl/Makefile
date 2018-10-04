all: build doc

build: game main.o game.o othello.o

doc: 
	doxygen config-file.conf

game: game.o main.o othello.o
	g++ -Wall game.o main.o othello.o -o game 

main.o: main.cc 
	g++ -c main.cc 

game.o: game.cc game.h
	g++ -c game.cc

othello.o: othello.cc othello.h piece.h
	g++ -c othello.cc

clean:
	rm *.o game
	rm -r html latex
