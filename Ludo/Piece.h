#ifndef _PIECE
#define _PIECE

#include "utility.h"

class Piece {
    const colorType pColor;
    bool hasKilled;
public:
    static sf::Texture red;
    static sf::Texture blue;
    static sf::Texture yellow;
    static sf::Texture green;
    static sf::Texture orange;
    static sf::Texture purple;
    
    Piece(colorType);
    colorType getColor()const;
    void displayPiece(sf::RenderWindow&,const int);
};

#endif

