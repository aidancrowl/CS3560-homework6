#Makefile for CS3560 Hw 5
#Alexis Lanier

all: build doc

build: game

doc: 
	doxygen Doxyfile

game: main.o game.o othello.o
	g++ -o game main.cc game.cc othello.cc

main.o: main.cc game.h othello.h
	g++ -c main.cc

game.o: game.cc game.h
	g++ -c game.cc

othello.o: othello.cc othello.h game.h piece.h colors.h
	g++ -c othello.cc

clean: 
	rm main.o game.o othello.o game
	rm -r html latex
