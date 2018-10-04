/**
* @file game.cc
*
* @brief This file is the source file for the game class
* There are multiple functions designed to make a terminal game playable
* This game will be designed to have a player play against an intelligent computer player
*
* @author Brock Ferrell
*/

#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include "game.h"     // Provides definition of game class
using namespace std;

namespace main_savitch_14
{
//*************************************************************************
// STATIC MEMBER CONSTANTS
// const int game::SEARCH_LEVELS;

//*************************************************************************
// PUBLIC MEMBER FUNCTIONS

/**
* @brief This function is the main function that allows for the game to be played.
* It starts by restarting the game to ensure a new game is being played
* It continues to loop and play while the game is not over, starting with the 
* human player, then the computer, displaying the board and finding the next turn
* after each move. This is repeated until the game is over.
*
* @param There are no parameters for this function
*
* @return The winner of the game is returned
*/

game::who game::play( )
// The play function should not be overridden. It plays one round of the
// game, with the human player moving first and the computer second.
// The return value is the winner of the game (or NEUTRAL for a tie).
{
	restart( );

	while (!is_game_over( ))
	{
		display_status( );
		whosTurn();
		if (last_mover( ) == COMPUTER) {
			countingPieces();
			make_human_move( );
		}
		else {
			make_computer_move( );
		}
	}
	display_status( );
	return HUMAN;
}



//*************************************************************************
// OPTIONAL VIRTUAL FUNCTIONS (overriding these functions is optional)


/**
* @brief This function displays a message provided by the another part of the program
* It is a constant function, so it won't modify the object that it calls
*
* @param The parameter is a constant string, const string& message, which allows the message to be passed through
*
* @return Since this is a void function, there is no return value
*/

void game::display_message(const string& message) const
{
	cout << message;
}


/**
* @brief This function promts the user to enter a move into the keyboard.
* It will store that move as a string 
*
* @param There are no parameters to this function
*
* @return The string named answer is returned, which stores the user's move
* that they typed on the keyboard
*/

string game::get_user_move( ) const
{
	string answer;

	display_message("If you cannot move, please press 'S'\n");
	display_message("Your move, please: ");
	getline(cin, answer);
	return answer;
}

game::who game::winning()const {

	int value = evaluate();

	if (value > 0) {
		return last_mover();
	} else if (value < 0) {
		return next_mover();
	} else {
		return NEUTRAL;
	}

}

//*************************************************************************
// PRIVATE FUNCTIONS (these are the same for every game)

/**
* @brief This function is the method used to generate the 
* intelligent computer move. In a queue of strings, all of
* the possible moves the computer is able to make.
* All of these moves are evaluated, and a value is given to them
* based on how the board will end up at the end of the move. 
* Whatever the most favorable board based on the rules of the game is,
* that is what move the computer will make
*
* @param int look_ahead - represents the number of moves ahead that the 
* algorith should use when calculating the best move. This is defined in 
* another part of the program
* int beat_this - value of another move that is being considered
* 
* @return -best_value - this is the computer's best possible move
* It is negative because the move is made from the human's perspective
*/

int game::eval_with_lookahead(int look_ahead, int beat_this)
// Evaluate a board position with lookahead.
// --int look_aheads:  How deep the lookahead should go to evaluate the move.
// --int beat_this: Value of another move that we're considering. If the
// current board position can't beat this, then cut it short.
// The return value is large if the position is good for the player who just
// moved.
{
	queue<string> moves;   // All possible opponent moves
	int value;             // Value of a board position after opponent moves
	int best_value;        // Evaluation of best opponent move
	game* future;          // Pointer to a future version of this game

	// Base case:
	if (look_ahead == 0 || is_game_over( ))
	{
		if (last_mover( ) == COMPUTER)
			return evaluate( );
		else
			return -evaluate( );
	}

	// Recursive case:
	// The level is above 0, so try all possible opponent moves. Keep the
	// value of the best of these moves from the opponent's perspective.
	compute_moves(moves);
	// assert(!moves.empty( ));
	best_value = INT_MIN;
	while (!moves.empty( ))
	{
		future = clone( );
		future->make_move(moves.front( ));
		value = future->eval_with_lookahead(look_ahead - 1, best_value);
		delete future;
		if (value > best_value)
		{
			if (-value <= beat_this)
				return INT_MIN + 1; // Alpha-beta pruning
			best_value = value;
		}
		moves.pop( );
	}

	// The value was calculated from the opponent's perspective.
	// The answer we return should be from player's perspective, so multiply times -1:
	return -best_value;
}


/**
* @brief This function makes the computer move using a queue of strings
* It creates a new game where future moves can be made and evaluated,
* where the best move will eventually be executed.
* 
* @param This function has no parameters
*
* @return This function is a void function, so it has no return value
*/
void game::make_computer_move( )
{
	queue<string> moves;
	int value;
	int best_value;
	string best_move;
	game* future;

	// Compute all legal moves that the computer could make.
	compute_moves(moves);
	//assert(!moves.empty( ));

	// Evaluate each possible legal move, saving the index of the best
	// in best_index and saving its value in best_value.
	best_value = INT_MIN;
	while (!moves.empty( ))
	{
		future = clone( );
		future->make_move(moves.front( ));
		value = future->eval_with_lookahead(SEARCH_LEVELS, best_value);
		delete future;
		if (value >= best_value)
		{
			best_value = value;
			best_move = moves.front( );
		}
		moves.pop( );
	}

	// Make the best move.
	make_move(best_move);
}

/**
* @brief This function makes the game move for the human.
* It calls the function get_user_move in order to get the 
* human move from the keyboard, as well as checks if its a legal move
* If it is a legal move, the move is brought the make_move function
*
* @param There are no parameters to this function
*
* @return This is a void function so it has no return value
*/

void game::make_human_move( ) {
	string move;

	move = get_user_move( );
	while (!is_legal(move))
	{
		display_message("Illegal move.\n");
		move = get_user_move( );
	}
	make_move(move);
}

}



