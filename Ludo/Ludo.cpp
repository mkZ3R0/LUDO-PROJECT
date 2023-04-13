#include "Ludo.h"

sf::RenderWindow Ludo::window(sf::VideoMode(895, 558), "Madni Ludo", sf::Style::Titlebar | sf::Style::Close);
Board Ludo::myBoard;
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

int Ludo::selectPiece()
{
    cout << "selecting Piece" << endl;//for testing purpose remove later on
    return myBoard.clickToIndex(Board::mouseClick(window));
}

bool Ludo::isValidSelection(const int index,const Player* p)
{
    cout << "checking if valid selection Piece" << endl;//for testing purpose remove later on
    //for now thinking only one piece at an index extend to multiple pieces on an index
    if (index < 0)
        return false;
    for (auto iT = myBoard.path[index].myPiece.begin(); iT != myBoard.path[index].myPiece.end();iT++)
    {
        if (p->isMyPiece((*iT)->getColor()))
            return true;
    }
    return false;
}

int Ludo::selectDiceRoll()
{
    cout << "selecting Dice roll" << endl;//for testing purpose remove later on
    return myBoard.clickToIndex(Board::mouseClick(window));  
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
    int startIndex = p->getMyPlayer()->getPlayerKey('s');
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

void Ludo::play() {

    while (window.isOpen())
    {
        Ludo::myBoard.displayBoard(Ludo::window);
        window.display();
        cout << "Current turn" << players[currentTurn]->getPlayerColor() << endl;//turn to proper prompt function;
        int rollCount = 0;
        int roll=0;
        myDice.giveSix();//cheats
        diceRolls.push_back(6);
        rollCount++;
        do
        {
            roll= myDice.rollDice();
            diceRolls.push_back(roll);
            rollCount++;
        } while (roll==6 && rollCount!=3);
        while (!diceRolls.empty() && !allSixes(diceRolls))
        {
            myBoard.displayBoard(window);//so that dices are displayed over the board;
            displayRolls(diceRolls);
            window.display();
            int diceIndex=-1;
            do
            {
                diceIndex = selectDiceRoll();

            } while (!isValidDiceSelect(diceRolls.size(),diceIndex));
            int currentRoll = convertIndexToDice(diceRolls,diceIndex);
            int selectedBoardIndex = -1;
            do
            {
                selectedBoardIndex = selectPiece();

            } while (!isValidSelection(selectedBoardIndex,players[currentTurn]));
            diceRolls.erase(diceRolls.begin() + convertIndexToDiceIndex(diceIndex));
            if (isReleased(currentRoll, players[currentTurn], selectedBoardIndex))
            {
                releasePiece(selectedBoardIndex);
            }
            else
            {
                myBoard.movePiece(window, selectedBoardIndex,currentRoll);//no check for killing insert it
                myBoard.displayBoard(window);
            }
            window.display();
        }
        changeTurn(currentTurn,noOfPlayers);

    }
}
