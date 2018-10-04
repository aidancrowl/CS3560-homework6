/**
* @file piece.h
* @brief Defines piece class and implements all functions
* @author Brock Ferrell
*/

#ifndef PIECE_H
#define PIECE_H
enum color {black, white, blank};

class piece {
public:
	piece() {theColor = blank;}

/**
* @brief Changes a piece to the opposite color (white to black, black to white)
* @param none
* @return void
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

