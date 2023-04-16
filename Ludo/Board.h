#ifndef _BOARD
#define _BOARD

#include "Position.h"
#include "Player.h"
#include "Dice.h"
#include "utility.h"


class Board {
    std::vector<Position> path;
    std::vector<Player*> players;
    static void calculateBoardPlc();
    static sf::Font fontB;
    static sf::Text textB;
    static sf::SoundBuffer buffer;
    static sf::SoundBuffer buffer2;
    static void displayTotalPieces(sf::RenderWindow&, const int, const int);
public:
    static sf::Texture boardBg;//make private
    static sf::Texture turnBg;//make private
    static float yOffSet;//make private
    static float xOffSet;//make private
    static vector<placement>boardPlc;
    Board(sf::RenderWindow&);
    void displayBoard(sf::RenderWindow&, const Player* = nullptr)const;
    static placement getBoardPlc(const int);
    void loadAssets();
    static placement mouseClick(sf::RenderWindow&); // TODO: make private
    static int clickToIndex(placement);
    int movePiece(sf::RenderWindow&, int, int, int = 0);
    void kill(sf::RenderWindow& window, int currentIndex, Player* currentPlayer);//for individual
    void killTeam(sf::RenderWindow&, int, Player*,const vector<Player*>&);//for teams
    Position& operator[](const int);
    const Position& operator[](const int) const;
};


#endif

