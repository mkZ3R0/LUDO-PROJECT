#ifndef _LUDO
#define _LUDO
#include <SFML/Graphics.hpp>
#include "utility.h"
#include "Board.h"
#include "Dice.h"
#include "Player.h"


class Ludo {
    static sf::RenderWindow window;
    static Board myBoard;
    static vector<Player*> allocatePlayers(const int);
public:
    Ludo();
    void play();

};


#endif