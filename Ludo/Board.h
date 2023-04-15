#ifndef _BOARD
#define _BOARD

#include "Position.h"
#include "Player.h"
#include "Dice.h"
#include "utility.h"


class Board {
    std::vector<Position> path;
    std::vector<Player*> players;
public:
    static sf::Texture boardBg;
    static sf::Texture turnBg;
    static float yOffSet;
    static float xOffSet;
    static vector<placement>boardPlc;
    Board(sf::RenderWindow&);
    void displayBoard(sf::RenderWindow&, const Player* = nullptr)const;
    static placement getBoardPlc(const int);
    static void calculateBoardPlc();// for now public for testing, but later turn it private
    void loadAssets();
    static placement mouseClick(sf::RenderWindow&); // TODO: make private
    static int clickToIndex(placement);
    int movePiece(sf::RenderWindow&, int, int, int = 0);
    void kill(sf::RenderWindow&, int, Player*);
    Position& operator[](const int);
    const Position& operator[](const int) const;
};


#endif

