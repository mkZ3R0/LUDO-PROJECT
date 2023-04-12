#ifndef _LUDO
#define _LUDO
#include <SFML/Graphics.hpp>
#include "utility.h"
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "Position.h"


class Ludo {
    static sf::RenderWindow window;
    static Board myBoard;
    static vector<Player*> allocatePlayers(const int);
    static vector<Piece*> allocatePiece(const Player*);
public:
    Ludo();
    void play();

};


#endif