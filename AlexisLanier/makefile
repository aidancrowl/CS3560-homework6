#Makefile for CS3560 Hw 5
#Alexis Lanier

all: game build archive

build: game

game: main.o game.o othello.o
	g++ -o game main.cc game.cc othello.cc

main.o: main.cc game.h othello.h
	g++ -c main.cc

game.o: game.cc game.h
	g++ -c game.cc

othello.o: othello.cc othello.h game.h piece.h colors.h
	g++ -c othello.cc

archive: colors.h game.cc game.h main.cc othello.cc othello.h piece.h makefile
	tar cvzf cs3560hw.tar.gz /home/alexis/cs3560hw

clean: 
	rm main.o game.o othello.o game
