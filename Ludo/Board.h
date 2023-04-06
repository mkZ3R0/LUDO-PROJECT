#ifndef _BOARD
#define _BOARD

#include "Position.h"
#include "Player.h"
#include <vector>
#include "utility.h"

class Board {
    std::vector<Position> path;
    std::vector<Player*> players;
public:
    Board();
    static void displayBoard(sf::RenderWindow&);

};


#endif

