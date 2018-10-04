/**
* @file main.cc
*
* @brief This is the main file that runs the game
*
* @author Brock Ferrell
*/

// Brock Ferrell
// CS2401
// November 23, 2015
// Project7

#include "game.h"
#include "othello.h"
using namespace main_savitch_14;


int main()
{
	Othello theGame;
	theGame.restart();
	theGame.play();
}
