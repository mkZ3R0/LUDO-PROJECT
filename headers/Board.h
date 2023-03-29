#ifndef _BOARD
#define _BOARD

#include "Position.h"
#include "Player.h"
#include <vector>
#include <iostream>

class Board {
    std::vector<Posoition> path;
    std::vector<Player*> players;
public:
    Board();

    // TEMPORARY!!!
    void printV() {
        for (int i = 0; i < path.size(); i++)
        {
            std::cout << i << "-> "; path[i].give(); std::cout << std::endl;         
        }
        
    }


};


#endif