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
    static sf::SoundBuffer sB  ; // FOR MUSIC
    static sf::Music bgm;
    static sf::Texture background;
    static vector<Player*> allocatePlayers(const int);
    static vector<Piece*> allocatePiece(const Player*);
    static vector<vector<Player*>> allocateTeams(const int, const int,const vector<Player*>&);
    int select();
    static int selectPiece(const vector<Piece*>&);
    static bool isValidDiceSelect(const int, int);
    static int getPlayerTeamIndex(const Player*, const vector<vector<Player*>>&);
    int convertIndexToDice(int) const;
    bool isValidSelection(const int, const Player*, const int) const;
    bool isTeamPiece(const colorType)const;
    static void changeTurn(int&, const int);
    bool isReleased(const int, const Player*, const int) const;
    bool isTeamPieceReleased(const int, const Player*, const int)const;
    bool hasWon(const Player*)const;
    void releasePiece(const int);
    static bool allSixes(const vector<int>&);
    static int convertIndexToDiceIndex(const int);
    static void displayRolls(sf::RenderWindow&, const vector<int>&, const Dice*);
    void checkLeaderBoard(Player*);
    void checkLeaderBoardTeams(Player*);
    bool isGameEnd();
    bool isGameEndTeams(const int);
    void displayResult() const;
    void displayResultTeams() const;
    bool canPlayMore(const Player*);
    bool isLegal(const int, const int, const int, const Player*) const;
    // private attributes
    vector<int> diceRolls;
    vector<Player*> players;
    vector<vector<Player*>> teams;
    unordered_set <Player*> leaderBoard;// for individual;
    unordered_set <int> teamLeaderBoard;// for teams;
    int noOfPlayers;
    int currentTurn;
    sf::RenderWindow window;
    Board* myBoard;
    Dice* myDice;
    bool isTeamMode;
    int totalTeamMembers;

    void prepareWindow();
    void teamSelect();
    int selectNumber(const char*, vector<int> = {2,3,4,5,6});
    void TeamNumber();

public:
    Ludo();
    void play();

};


#endif