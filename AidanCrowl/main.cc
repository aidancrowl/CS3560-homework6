/**
* @file main.cc
* @brief Runs code required to play a game
* @author Brock Ferrell
*/

#include "game.h"
#include "othello.h"
using namespace main_savitch_14;

/**
* @brief Plays a game
* @param None
* @return an integer value (0 for Exit Status)
*/

int main()
{
	Othello theGame;
	theGame.restart();
	theGame.play();
}
