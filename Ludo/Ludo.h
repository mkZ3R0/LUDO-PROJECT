#ifndef _LUDO
#define _LUDO
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "utility.h"
#include "Dice.h"
#include "Player.h"
#include "Position.h"

class Board;
class Dice;

class Ludo {
    friend class Dice;
    static vector<Player*> allocatePlayers(const int);
    static vector<Piece*> allocatePiece(const Player*);
    static int select(sf::RenderWindow&,const Board*);
    static int selectPiece(const vector<Piece*>&);
    static bool isValidDiceSelect(const int,int);
    static int convertIndexToDice(const vector<int>&,int);
    static bool isValidSelection(sf::RenderWindow&,const Board*,const int,const Player*, const int);
    static void changeTurn(int&,const int);
    static bool isReleased(const Board*,const int, const Player*, const int);
    static void releasePiece(sf::RenderWindow&,Board*,const int);
    static bool allSixes(const vector<int>&);
    static int convertIndexToDiceIndex(const int);
    static void displayRolls(sf::RenderWindow&,const vector<int>&,const Dice*);
    static int countPieceColor(const Board* ,const colorType,const int);
    static void checkLeaderBoard(const Board*,Player*, unordered_set<Player*>&);
    static bool isGameEnd(unordered_set<Player*>&, const vector<Player*>&);
    static void displayResult(const unordered_set<Player*>&);
    bool canPlayMore(const vector<int>&, const Player*);
    bool isLegal(const Board*, const int, const int, const int, const Player*);
    // private attributes
    vector<int> diceRolls;
    vector<Player*> players;
    unordered_set <Player*> leaderBoard;
    int noOfPlayers;
    int currentTurn;
    sf::RenderWindow window;
    Board* myBoard;
    Dice* myDice;
public:
    Ludo();
    void play();

};


#endif