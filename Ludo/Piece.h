#ifndef _PIECE
#define _PIECE

#include "utility.h"

class Piece {
    const colorType pColor;
public:
    Piece(colorType);
    colorType getColor()const;
    void displayPiece(sf::RenderWindow&,const int);
};

#endif

