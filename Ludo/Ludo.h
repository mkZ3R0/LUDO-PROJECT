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
    int select();
    static int selectPiece(const vector<Piece*>&);
    static bool isValidDiceSelect(const int, int);
    int convertIndexToDice(int) const;
    bool isValidSelection(const int, const Player*, const int) const;
    static void changeTurn(int&, const int);
    bool isReleased(const int, const Player*, const int) const;
    void releasePiece(const int);
    static bool allSixes(const vector<int>&);
    static int convertIndexToDiceIndex(const int);
    static void displayRolls(sf::RenderWindow&, const vector<int>&, const Dice*);
    int countPieceColor(const colorType, const int) const;
    void checkLeaderBoard(Player*);
    bool isGameEnd();
    void displayResult() const;
    bool canPlayMore(const vector<int>&, const Player*);
    bool isLegal(const int, const int, const int, const Player*) const;
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