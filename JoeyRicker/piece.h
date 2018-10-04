/**
* @file piece.h
*
* @brief This is the header file for the piece class 
*
* @author Brock Ferrell
*/

// Brock Ferrell
// CS2401
// November 23, 2015
// Project7

#ifndef PIECE_H
#define PIECE_H
enum color {black, white, blank};

class piece {
public:
	piece() {theColor = blank;}


	/**
	* @brief This function flips the color of a game piece, from black to white or from white to black
	*
	* @param There are no parameters to this function
	*
	* @return This is a void function so there is no return value
	*/

	void flip()
	{
		if (theColor == white) {
			theColor = black;
		}
		else if (theColor == black) {
			theColor = white;
		}
	}

	bool is_blank()const {return theColor == blank;}
	bool is_black()const {return theColor == black;}
	bool is_white()const {return theColor == white;}
	void set_white() {theColor = white;}
	void set_black() {theColor = black;}

private:
	color theColor;

};

#endif

