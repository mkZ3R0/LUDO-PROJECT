#ifndef _BOARD
#define _BOARD

#include "Position.h"
#include "Player.h"
#include "Dice.h"
#include "utility.h"


class Board {
    friend class Dice;
    friend class Ludo;
    std::vector<Position> path;
    std::vector<Player*> players;
    static vector<placement>boardPlc;
public:
    static sf::Texture boardBg;
    static float yOffSet;
    static float xOffSet;
    Board();
    static void displayBoard(sf::RenderWindow&);
    static placement getBoardPlc(const int);
    static void calculateBoardPlc();//for now public for testing, but later turn it private
    void loadAssets();
    static placement mouseClick(sf::RenderWindow&); //TODO: make private
    int clickToIndex(placement);

};


#endif

