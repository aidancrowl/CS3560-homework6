/**
*@file main.cc
*@brief runs game code and restarts the game when the game ends
*@author Brock Ferrell
*/



// Brock Ferrell
// CS2401
// November 23, 2015
// Project7

#include "game.h"
#include "othello.h"
using namespace main_savitch_14;

/**
*@brief makes an Othello game which is played and then restarted
*@param none
*@return an integer value //zero for exit status
*/


int main()
{
	Othello theGame;
	theGame.restart();
	theGame.play();
}
