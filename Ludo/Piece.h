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
    static sf::Texture red_k;
    static sf::Texture blue_k;
    static sf::Texture yellow_k;
    static sf::Texture green_k;
    static sf::Texture orange_k;
    static sf::Texture purple_k;
    Piece(const Player*);
    colorType getColor()const;
    bool canGoHome()const;
    void changeKilledStatus();
    void displayPiece(sf::RenderWindow&, const placement);
    const Player* getMyPlayer()const;
};

#endif

