
all:build doc

build:

game.o: game.cc game.h
		g++ -c game.cc

othello.o: othello.cc othello.h game.h colors.h piece.h
		g++ -c othello.cc

main.o: main.cc othello.cc othello.h game.cc game.h
		g++ -c main.cc 

game: game.o othello.o main.o
		g++ -o game main.cc game.cc othello.cc

archive:  colors.h game.cc game.h game.o main.cc main.o makefile othello.cc othello.h othello.o piece.h game
	tar cvzf files.tar.gz /home/jr895115/CS3560-HW5

clean: 
	rm game.o main.o othello.o game

doc: 
	doxygen Doxyfile






