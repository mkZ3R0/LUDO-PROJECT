#include "Ludo.h"
#include <algorithm>

sf::RenderWindow Ludo::window(sf::VideoMode(1184, 740), "Madni Ludo", sf::Style::Titlebar | sf::Style::Close);
Board Ludo::myBoard(window);
Dice Ludo::myDice;

vector<Player*> Ludo::allocatePlayers(const int num)
{
    assert(num > 0 && num <= 6);
    vector<Player*> p;
    switch (num)
    {
        case 1:
        {
            p.push_back(new Player(Purple));
            return p;
        }
        case 2:
        {
            p.push_back(new Player(Purple));
            p.push_back(new Player(Yellow));
            return p;
        }
        case 3:
        {
            p.push_back(new Player(Purple));
            p.push_back(new Player(Green));
            p.push_back(new Player(Blue));
            return p;
        }
        case 4:
        {
            p.push_back(new Player(Purple));
            p.push_back(new Player(Orange));
            p.push_back(new Player(Yellow));
            p.push_back(new Player(Blue));
            return p;
        }
        case 5:
        {
            p.push_back(new Player(Purple));
            p.push_back(new Player(Orange));
            p.push_back(new Player(Green));
            p.push_back(new Player(Yellow));
            p.push_back(new Player(Blue));
            return p;
        }
        case 6:
        {
            p.push_back(new Player(Purple));
            p.push_back(new Player(Orange));
            p.push_back(new Player(Green));
            p.push_back(new Player(Yellow));
            p.push_back(new Player(Blue));
            p.push_back(new Player(Red));
            return p;
        }
    }
    return p; //compiler warning
}

vector<Piece *> Ludo::allocatePiece(const Player* player) {
    vector<Piece*> pieces;
    for (int i = 0; i < 4; i++) {
        pieces.push_back(new Piece(player));
    }
    
    return pieces;
}

Ludo::Ludo() {
    srand(time(0));
    noOfPlayers=2; // input this with a different window
    currentTurn = rand()%noOfPlayers;
    Ludo::players = allocatePlayers(noOfPlayers);

    for(auto& player: players) {
        auto pieces = allocatePiece(player);
        auto homeArea = player->getPlayerHome();
        for (int i=0; i<4; i++) {
            myBoard.path[homeArea[i]].myPiece.push_back(pieces[i]);
        }
    }
}

int Ludo::select() {
    return myBoard.clickToIndex(Board::mouseClick(window));
}

bool Ludo::isValidSelection(const int index,const Player* p, const int currentRoll)
{
    cout << "checking if valid selection Piece" << endl;//for testing purpose remove later on
    //for now thinking only one piece at an index extend to multiple pieces on an index
    if (index < 0)
        return false;
    auto home = p->getPlayerHome();
    if (find(home.begin(), home.end(), index) != home.end() && currentRoll!=6) {
        return false;
    }
    for (auto iT = myBoard.path[index].myPiece.begin(); iT != myBoard.path[index].myPiece.end();iT++)
    {
        if (p->isMyPiece((*iT)->getColor()))
            return true;
    }
    return false;
}

bool Ludo::allSixes(const vector<int>& myRolls)
{
    cout << "checking if all sixes" << endl;//for testing purpose remove later on
    if (myRolls.size() != 3)
        return false;
    for (auto iT = myRolls.begin(); iT != myRolls.end(); iT++)
    {
        if ((*iT != 6))
            return false;
    }
    return true;
}

bool Ludo::isValidDiceSelect(const int totalRolls, int clickIndex)
{
    cout << "checking if valid dice selection" << endl;//for testing purpose remove later on
    if (clickIndex >= 0)
        return false;
    clickIndex = abs(clickIndex) - 1;
    if (clickIndex >= totalRolls)
        return false;
    return true;
}

int Ludo::convertIndexToDice(const vector<int>& dicesRolled,int index)
{
    cout << "converting index to dice roll" << endl;//for testing purpose remove later on
    index = abs(index) - 1;
    return dicesRolled[index];
}

void Ludo::changeTurn(int& Turn, const int totalPlayers)
{
    cout << "changing turn" << endl;//for testing purpose remove later on
    Turn = (Turn + 1) % totalPlayers;
}

bool Ludo::isReleased(const int roll, const Player* plyr, const int boardIndex)
{
    cout << "check if wanting to release piece" << endl;//for testing purpose remove later on
    if (roll != 6)
        return false;
    bool isHomeEmpty = true;
    auto home = plyr->getPlayerHome();
    for (auto iT = home.begin(); iT != home.end(); iT++)
    {
        if (!(myBoard.path[*iT].myPiece.empty()))
        {
            isHomeEmpty = false;
            break;
        }
    }
    if (isHomeEmpty)
        return false;
    for (auto iT = home.begin(); iT != home.end(); iT++)
    {
        if ((*iT) == boardIndex)
            return true;
    }
    return false;
}

void Ludo::releasePiece(const int boardIndex)
{
    cout << "releasing piece" << endl;//for testing purpose remove later on
    Piece* p = myBoard.path[boardIndex].myPiece[0];
    myBoard.path[boardIndex].myPiece.erase(myBoard.path[boardIndex].myPiece.begin());
    int startIndex = p->getMyPlayer()->getPlayerKey(_start);
    myBoard.path[startIndex].myPiece.push_back(p);
    myBoard.displayBoard(window);
}

int Ludo::convertIndexToDiceIndex(const int index)
{
    return (abs(index)-1);
}

void Ludo::displayRolls(const vector<int>& myRolls)
{
    int index = 0;
    for (auto iT = myRolls.begin(); iT != myRolls.end(); iT++)
    {
        myDice.displayRoll(window, index++, *iT);
    }
}

bool Ludo::canPlayMore(const vector<int> &diceRolls, const Player* currentPlayer) {
    auto homeArea = currentPlayer->getPlayerHome();
    auto winI = currentPlayer->getPlayerKey(_end);
    auto doorI = currentPlayer->getPlayerKey(_door);
    
    int emptyCount=0; 
    for (int i=0; i<4; i++) {
        if (myBoard.path[homeArea[i]].myPiece.empty()) { // home empty
            emptyCount++;
        }
    }

    if (find(diceRolls.begin(), diceRolls.end(), 6) == diceRolls.end()) { // no 6 in die
        if (emptyCount == myBoard.path[winI].myPiece.size()) { // no piece on regular board
            return false;
        }
        for (int i = doorI; i < winI; i++) {
            if (myBoard.path[i].myPiece.size()>0) {
                auto cmp = winI-i;
                // check if the remainder path is present in dice, less or equal
                if(std::any_of(diceRolls.begin(), diceRolls.end(), [=](int i) { return i <= cmp; })) {
                    return true;
                } else {
                    // if only pieces remaining are on the win path, then return false, else can probably
                    auto rem = 4-((4-emptyCount)+myBoard.path[winI].myPiece.size());
                    if (rem == 1) {
                        return false;
                    } else {
                        for (int j = i+1; j < winI; j++) {
                            if (myBoard.path[i].myPiece.size()>0) {
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        
        return true; // have some free piece on board
    }
    return true; // have 6, come on you can play
}

int Ludo::countPieceColor(const colorType c, const int bIndex)
{
    int count = 0;
    for (auto iT = myBoard.path[bIndex].myPiece.begin(); iT != myBoard.path[bIndex].myPiece.end(); iT++)
    {
        if ((*iT)->getColor() == c)
            count++;
    }
    return count;
}

//will be used for legal movement involving joota

bool Ludo::isLegal(int boardIndex, int rolledNumber, const Player* player) {
    if (isReleased(rolledNumber, player, boardIndex)) return true;
    Piece* pToMove = myBoard.path[boardIndex].myPiece[0];
    auto playerTurn = pToMove->getMyPlayer();
    int currentIndex = boardIndex;
    while (rolledNumber != 0) {
        if (myBoard.path[currentIndex].special && myBoard.path[currentIndex].type == Home && playerTurn->getPlayerKey(_victory) == currentIndex && pToMove->canGoHome()) {
            rolledNumber--;
            currentIndex = playerTurn->getPlayerKey(_door);
        }
        else {
            rolledNumber--;
            if (currentIndex == 89)
                currentIndex = 0;
            else
                currentIndex++;
        }
    }
    if (currentIndex > playerTurn->getPlayerKey(_end)) {
        return false;
    } 
    return true;
}

void Ludo::checkLeaderBoard(Player* currentPly, unordered_set<Player*>& leaderBoard)
{
    if (myBoard.path[currentPly->getPlayerKey(_end)].myPiece.size() == 4)
    {
        if (leaderBoard.find(currentPly) == leaderBoard.end())
        {
            leaderBoard.insert(currentPly);
        }
    }
}

bool Ludo::isGameEnd(unordered_set<Player*>& leaderBoard, const vector<Player*>& gamePlayers)
{
    if (leaderBoard.size() == (gamePlayers.size() - 1))
    {
        for (auto iT = gamePlayers.begin(); iT != gamePlayers.end(); iT++)
        {
            Player* p = *iT;
            if (leaderBoard.find(*iT) != leaderBoard.end())
            {
                leaderBoard.insert(p);
                return true;
            }
        }
        throw("Invalid Case found");
    }
    else
        return false;
}

void Ludo::displayResult(const unordered_set<Player*>& result)//for now printing on console
{
    int count = 1;
    cout << "Results are in" << endl;
    for (auto iT = result.begin(); iT != result.end(); iT++)
    {
        cout << count++ <<"- Player "<< (*iT)->getPlayerColor() << endl;
    }
}

void Ludo::play() {

    while (window.isOpen())
    {
        Ludo::myBoard.displayBoard(Ludo::window);
        window.display();
        cout << "Current turn" << players[currentTurn]->getPlayerColor() << endl;//turn to proper prompt function;
        int rollCount = 0;
        int roll=0;
        do
        {
            //roll= myDice.rollDice();
            roll = myDice.cheatRoll(window);//cheat
            diceRolls.push_back(roll);
            rollCount++;
        } while (roll==6 && rollCount!=3);
        Ludo::myBoard.displayBoard(Ludo::window);
        displayRolls(diceRolls);
        window.display();
        __sleep(500);
        while (!diceRolls.empty() && !allSixes(diceRolls) && canPlayMore(diceRolls, players[currentTurn]))
        {
            myBoard.displayBoard(window);//so that dices are displayed over the board;
            displayRolls(diceRolls);
            window.display();
            int diceIndex=-1;
            do
            {
                diceIndex = select();

            } while (!isValidDiceSelect(diceRolls.size(),diceIndex));
            int currentRoll = convertIndexToDice(diceRolls,diceIndex);
            int selectedBoardIndex = -1;
            do
            {
                selectedBoardIndex = select();
                if (isValidDiceSelect(diceRolls.size(), selectedBoardIndex)) {
                    currentRoll = convertIndexToDice(diceRolls, selectedBoardIndex);
                    diceIndex = selectedBoardIndex;
                    selectedBoardIndex = -1;
                }
                else if (isValidSelection(selectedBoardIndex,players[currentTurn], currentRoll) && isLegal(selectedBoardIndex, currentRoll, players[currentTurn])) break;
            } while (true);
            diceRolls.erase(diceRolls.begin() + convertIndexToDiceIndex(diceIndex));
            if (isReleased(currentRoll, players[currentTurn], selectedBoardIndex))
            {
                releasePiece(selectedBoardIndex);
            }
            else
            {
                auto currentIndex = myBoard.movePiece(window, selectedBoardIndex, currentRoll);//no check for killing insert it
                myBoard.kill(window, currentIndex, players[currentTurn]);
                myBoard.displayBoard(window);
            }
            window.display();
        }
        diceRolls.clear();
        checkLeaderBoard(players[currentTurn], leaderBoard);
        if (isGameEnd(leaderBoard,players))
        {
            displayResult(leaderBoard);//change to proper leader board display
        }
        changeTurn(currentTurn,noOfPlayers);

    }
}
