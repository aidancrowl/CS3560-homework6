all: build archive

build: game main.o game.o othello.o

archive: archive.tar

archive.tar: 
	tar cvf archive.tar .
	gzip archive.tar

game: game.o main.o othello.o
	g++ -Wall game.o main.o othello.o -o game 

main.o: main.cc 
	g++ -c main.cc 

game.o: game.cc game.h
	g++ -c game.cc

othello.o: othello.cc othello.h piece.h
	g++ -c othello.cc

clean:
	rm *.o game archive.tar.gz