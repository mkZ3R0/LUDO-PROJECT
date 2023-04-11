#ifndef _PIECE
#define _PIECE

#include "utility.h"

class Player;

class Piece {
    const colorType pColor;
    const Player* myPlayer;
    bool hasKilled;
public:
    static sf::Texture red;
    static sf::Texture blue;
    static sf::Texture yellow;
    static sf::Texture green;
    static sf::Texture orange;
    static sf::Texture purple;
    Piece(const Player*);
    colorType getColor()const;
    bool canGoHome()const;
    void changeKilledStatus();
    void displayPiece(sf::RenderWindow&,const int);
};

#endif

