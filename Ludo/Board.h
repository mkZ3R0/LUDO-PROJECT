#ifndef _BOARD
#define _BOARD

#include "Position.h"
#include "Player.h"
#include "utility.h"

class Board {
    std::vector<Position> path;
    std::vector<Player*> players;
    static vector<position>boardPos;
    static void calculateBoardPos();
public:
    Board();
    static void displayBoard(sf::RenderWindow&);

};


#endif

