#ifndef _LUDO
#define _LUDO
#include <SFML/Graphics.hpp>
#include "utility.h"
#include "Board.h"
#include "Dice.h"


class Ludo {
    static sf::RenderWindow window;
    static Board myBoard;

public:
    Ludo();
    void play();

};


#endif