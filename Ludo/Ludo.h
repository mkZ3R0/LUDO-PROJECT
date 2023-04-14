#ifndef _LUDO
#define _LUDO
#include <SFML/Graphics.hpp>
#include "utility.h"
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "Position.h"


class Ludo {
    friend class Dice;
    static sf::RenderWindow window;
    static Board myBoard;
    static Dice myDice;
    static vector<Player*> allocatePlayers(const int);
    static vector<Piece*> allocatePiece(const Player*);
    static int select();
    static bool isValidDiceSelect(const int,int);
    static int convertIndexToDice(const vector<int>&,int);
    static bool isValidSelection(const int,const Player*, const int);
    static void changeTurn(int&,const int);
    static bool isReleased(const int, const Player*, const int);
    static void releasePiece(const int);
    static bool allSixes(const vector<int>&);
    static int convertIndexToDiceIndex(const int);
    static void displayRolls(const vector<int>&);
    static int countPieceColor(const colorType,const int);
    static void checkLeaderBoard(Player*, unordered_set<Player*>&);
    static bool isGameEnd(unordered_set<Player*>&, const vector<Player*>&);
    static void displayResult(const unordered_set<Player*>&);
    bool canPlayMore(const vector<int>&, const Player*);
    bool isLegal(const int, const int, const Player*);
    // private attributes
    vector<int> diceRolls;
    vector<Player*> players;
    unordered_set <Player*> leaderBoard;
    int noOfPlayers;
    int currentTurn;
public:
    Ludo();
    void play();

};


#endif