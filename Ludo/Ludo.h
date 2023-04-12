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
    static Dice myDice;
    static vector<Player*> allocatePlayers(const int);
    static vector<Piece*> allocatePiece(const Player*);
    static int selectPiece();
    static int selectDiceRoll();
    static bool isValidDiceSelect(const int,int);
    static int convertIndexToDice(const vector<int>&,int);
    static bool isValidSelection(const int,const Player*);
    static void changeTurn(int&,const int);
    static bool isReleased(const int, const Player*, const int);
    static void releasePiece(const int);
    static bool allSixes(const vector<int>&);
    static int convertIndexToDiceIndex(const int);
    // private attributes
    vector<int> diceRolls;
    vector<Player*> players;
    int noOfPlayers;
    int currentTurn;
public:
    Ludo();
    void play();

};


#endif