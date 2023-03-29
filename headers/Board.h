#ifndef _BOARD
#define _BOARD

#include "Position.h"
#include "Player.h"
#include <vector>

class Board {
    std::vector<Posoition> path;
    std::vector<Player*> players;
public:
    Board();


};


#endif