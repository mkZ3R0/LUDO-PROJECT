#include "Ludo.h"
#include <algorithm>


sf::SoundBuffer Ludo::sB;
sf::Music Ludo::bgm;

vector<Player*> Ludo::allocatePlayers(const int num)
{
    assert(num > 1 && num <= 6);
    vector<Player*> p;
    switch (num)
    {
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
    return p; // compiler warning
}

vector<Piece *> Ludo::allocatePiece(const Player* player) {
    vector<Piece*> pieces;
    for (int i = 0; i < 4; i++) {
        pieces.push_back(new Piece(player));
    }

    return pieces;
}

vector<vector<Player*>> Ludo::allocateTeams(const int totalPlayers, const int totalTeamMembers,const vector<Player*>& gamePlayers)
{
    vector<vector<Player*>> teams;
    int totalTeams = totalPlayers / totalTeamMembers;
    if (totalTeams == 2 && totalPlayers == 4)
    {
        vector<Player*>p1;
        vector<Player*>p2;
        for (int i = 0; i < gamePlayers.size(); i++)
        {
            switch (gamePlayers[i]->getPlayerColor())
            {
                case Purple:
                {
                    p1.push_back(gamePlayers[i]);
                    break;
                }
                case Yellow:
                {
                    p1.push_back(gamePlayers[i]);
                    break;
                }
                case Orange:
                {
                    p2.push_back(gamePlayers[i]);
                    break;
                }
                case Blue:
                {
                    p2.push_back(gamePlayers[i]);
                    break;
                }
            }
        }
        teams.push_back(p1);
        p1.clear();
        teams.push_back(p2);
        p2.clear();
        return teams;
    }
    else if (totalTeams == 2 && totalPlayers == 6)
    {
        vector<Player*>p1;
        vector<Player*>p2;
        for (int i = 0; i < gamePlayers.size(); i++)
        {
            switch (gamePlayers[i]->getPlayerColor())
            {
            case Purple:
            {
                p1.push_back(gamePlayers[i]);
                break;
            }
            case Green:
            {
                p1.push_back(gamePlayers[i]);
                break;
            }
            case Blue:
            {
                p1.push_back(gamePlayers[i]);
                break;
            }
            case Orange:
            {
                p2.push_back(gamePlayers[i]);
                break;
            }
            case Red:
            {
                p2.push_back(gamePlayers[i]);
                break;
            }
            case Yellow:
            {
                p2.push_back(gamePlayers[i]);
                break;
            }
            }
        }
        teams.push_back(p1);
        p1.clear();
        teams.push_back(p2);
        p2.clear();
        return teams;
    }
    else
    {
        vector<Player*>p1;
        vector<Player*>p2;
        vector<Player*>p3;
        for (int i = 0; i < gamePlayers.size(); i++)
        {
            switch (gamePlayers[i]->getPlayerColor())
            {
            case Purple:
            {
                p1.push_back(gamePlayers[i]);
                break;
            }
            case Green:
            {
                p3.push_back(gamePlayers[i]);
                break;
            }
            case Blue:
            {
                p2.push_back(gamePlayers[i]);
                break;
            }
            case Orange:
            {
                p2.push_back(gamePlayers[i]);
                break;
            }
            case Red:
            {
                p3.push_back(gamePlayers[i]);
                break;
            }
            case Yellow:
            {
                p1.push_back(gamePlayers[i]);
                break;
            }
            }
        }
        teams.push_back(p1);
        p1.clear();
        teams.push_back(p2);
        p2.clear();
        teams.push_back(p3);
        p3.clear();
        return teams;
    }
}

bool Ludo::isTeamPiece(const colorType selectedPieceClr)const // TODO = IMPLEMENT IN TEAM GAME MODE
{
    int teamIndex = -1;
    teamIndex = getPlayerTeamIndex(players[currentTurn], teams);
    assert(teamIndex != -1);
    for (auto iT = teams[teamIndex].begin(); iT != teams[teamIndex].end(); iT++)
    {
        if ((*iT)->getPlayerColor() == selectedPieceClr)
            return true;
    }
    return false;
}

int Ludo::getPlayerTeamIndex(const Player* plyr, const vector<vector<Player*>>& teams)
{
    for (int i = 0; i < teams.size(); i++)
    {
        for (auto iT = teams[i].begin(); iT != teams[i].end(); iT++)
        {
            if ((*iT) == plyr)
            {
                return i;
            }
        }
    }
    throw("Unexpected Case");
}

sf::Texture Ludo::background;
void Ludo::prepareWindow() {
    sf::Sprite s(background);
    s.setColor(sf::Color::White);
    s.setPosition(0, 0);
    // scale to window
    float scaleX = (float)window.getSize().x / background.getSize().x;
    float scaleY = (float)window.getSize().y / background.getSize().y;
    s.setScale(scaleX, scaleY);
    window.draw(s);    

    sf::Text text = {"Madni Ludo", Board::fontB, 128};
    text.setFillColor(sf::Color::Red);
    text.setPosition(window.getSize().x/2 - text.getLocalBounds().width/2, window.getSize().y/10 - text.getLocalBounds().height/2);
    window.draw(text);
}

void Ludo::teamSelect() {
    this->prepareWindow();

    ////
    sf::Text soloMode("Solo Play", Board::fontB, 32);
    soloMode.setFillColor(sf::Color::Red);
    soloMode.setPosition(window.getSize().x/2 - soloMode.getLocalBounds().width/2, window.getSize().y/2 - soloMode.getLocalBounds().height/2);
    window.draw(soloMode);

    sf::Text teamMode("Team Play", Board::fontB, 32);
    teamMode.setFillColor(sf::Color::Red);
    teamMode.setPosition(window.getSize().x/2 - teamMode.getLocalBounds().width/2, window.getSize().y/2 - teamMode.getLocalBounds().height/2 + window.getSize().y/6);
    window.draw(teamMode);

    window.display();

    while(window.isOpen()) {
        sf::Event event;
        while(window.waitEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            exit(0);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (soloMode.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                this->isTeamMode = false;
                cout << "solo selected" << endl;
                return;
            }
            else if (teamMode.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                this->isTeamMode = true;
                cout << "team selected" << endl;
                return;
            }
        }
        }
    }
}

int Ludo::selectNumber(const char* msg, vector<int> nums) {
    this->prepareWindow();

    sf::Text text(msg, Board::fontB, 32);
    text.setFillColor(sf::Color::Red);
    text.setPosition(window.getSize().x/2 - text.getLocalBounds().width/2, window.getSize().y/2 - text.getLocalBounds().height/2 - window.getSize().y/6);
    window.draw(text); 

    vector<sf::Text> nos;
    for (auto& i: nums) {
        nos.push_back({std::to_string(i), Board::fontB, 32});
    }

    for(int i=0; i<nos.size(); i++) {
        nos[i].setFillColor(sf::Color::Red);
        nos[i].setPosition(window.getSize().x/2 - nos[i].getLocalBounds().width/2, window.getSize().y/2 - nos[i].getLocalBounds().height/2 + i*(window.getSize().y/10) );
        window.draw(nos[i]);
    }

    window.display();

    while(window.isOpen()) {
        sf::Event event;
        while(window.waitEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            exit(0);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            for(auto& n: nos) {
                if (n.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int _rval = atoi(static_cast<std::string>(n.getString()).c_str());
                    cout << msg << " " << _rval << endl;
                    return _rval;  
                }
            }
        }
        }
    }
    return -1;
}

Ludo::Ludo():window(sf::VideoMode(1184, 740), "Madni Ludo", sf::Style::Titlebar | sf::Style::Close)
{
    myBoard = new Board(window);
    myDice = new Dice();
    srand(time(0));

    if (!background.loadFromFile("Assets/backgroud.png")) {
        cerr << "coult not open background.png" << endl;
        exit(1);
    }

    // TODO: move out of constructor
    this->teamSelect();
    if (isTeamMode) {
        noOfPlayers = this->selectNumber("Number of Players", {4, 6});
        if (noOfPlayers == 4) totalTeamMembers = 2;
        else if (noOfPlayers == 6) {
            totalTeamMembers = this->selectNumber("Players per teams", {2, 3});
        }
    } else {
        noOfPlayers = this->selectNumber("Number of Players");
    }
    assert(noOfPlayers >= 2 && noOfPlayers <= 6);
    if (isTeamMode) assert(totalTeamMembers == 2 || totalTeamMembers == 3);

    players = allocatePlayers(noOfPlayers);
    if (isTeamMode) teams = allocateTeams(noOfPlayers, totalTeamMembers, players);
    currentTurn = rand()%noOfPlayers;

    for(auto& player: players) {
        auto pieces = allocatePiece(player);
        auto homeArea = player->getPlayerHome();
        for (int i=0; i<4; i++) {
            (*myBoard)[homeArea[i]].myPiece.push_back(pieces[i]);
        }
    }

    if (!sB.loadFromFile("Assets/results.ogg"))
    {
        cerr << "Cannot load results.ogg" << endl;
        exit(1);
    }
    if (!bgm.openFromFile("Assets/BGM.ogg")) {
        cerr << "file not found" << endl;
        exit(1);
    }
}

int Ludo::select() {
    return myBoard->clickToIndex(Board::mouseClick(window));
}

int Ludo::selectPiece(const vector<Piece *>& myPiece) {
    auto s = myPiece.size();
    sf::RenderWindow selectWindow(sf::VideoMode(Board::xOffSet*s, Board::yOffSet), "Select Piece", sf::Style::Titlebar);
    auto p = sf::VideoMode::getDesktopMode();
    sf::Vector2i a = {(int)p.width/2, (int)p.height/2};
    selectWindow.setPosition(a);
    selectWindow.clear(sf::Color::White);
    for (int i = 0; i < s; i++) {
        placement pl = {static_cast<float>(Board::xOffSet*(i) + Board::xOffSet/2.0), static_cast<float>(Board::yOffSet/2.0)};
        myPiece[i]->displayPiece(selectWindow, pl);
    }
    selectWindow.display();

    while(selectWindow.isOpen()) {
        auto pl = Board::mouseClick(selectWindow);
        return pl.x/Board::xOffSet;
    }
    return 0;
}

bool Ludo::isValidSelection(const int index, const Player* p, const int currentRoll) const
{
    cout << "checking if valid selection Piece" << endl;//TODO: for testing purpose remove later on
    // for now thinking only one piece at an index extend to multiple pieces on an index
    if (index < 0)
        return false;
    auto home = p->getPlayerHome();
    if (find(home.begin(), home.end(), index) != home.end() && currentRoll!=6) {
        return false;
    }
    for (auto iT = (*myBoard)[index].myPiece.begin(); iT != (*myBoard)[index].myPiece.end();iT++)
    {
        if (isTeamMode)
        {
            int end = p->getPlayerKey(_end);
            if ((*myBoard)[end].myPiece.size() == 4)
            {
                if (isTeamPiece((*iT)->getColor()))
                    return true;
            }
            else if(p->isMyPiece((*iT)->getColor()))
                return true;
        }
        else if (p->isMyPiece((*iT)->getColor()))
            return true;
    }
    cout << "exiting valid selection Piece" << endl;//TODO: for testing purpose remove later on
    return false;
}

bool Ludo::allSixes(const vector<int>& myRolls)
{
    cout << "checking if all sixes" << endl;// for testing purpose remove later on
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
    cout << "checking if valid dice selection" << endl;// for testing purpose remove later on
    if (clickIndex >= 0)
        return false;
    clickIndex = abs(clickIndex) - 1;
    if (clickIndex >= totalRolls)
        return false;
    return true;
}

int Ludo::convertIndexToDice(int index) const
{
    cout << "converting index to dice roll" << endl;// for testing purpose remove later on
    index = abs(index) - 1;
    return diceRolls[index];
}

void Ludo::changeTurn(int& Turn, const int totalPlayers)
{
    cout << "changing turn" << endl;// for testing purpose remove later on
    Turn = (Turn + 1) % totalPlayers;
}

bool Ludo::isReleased(const int roll, const Player* plyr, const int boardIndex) const
{
    cout << "check if wanting to release piece" << endl;// for testing purpose remove later on
    if (roll != 6)
        return false;
    bool isHomeEmpty = true;
    auto home = plyr->getPlayerHome();
    for (auto iT = home.begin(); iT != home.end(); iT++)
    {
        if (!((*myBoard)[*iT].myPiece.empty()))
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

bool Ludo::isTeamPieceReleased(const int roll, const Player* plyr, const int boardIndex)const
{
    cout << "check if wanting to release team member piece" << endl;// TODO::REMOVE for testing purpose remove later on
    if (roll != 6)
        return false;
    int teamIndex = getPlayerTeamIndex(plyr, teams);
    for (int i = 0; i < teams[teamIndex].size(); i++)
    {
        auto home = teams[teamIndex][i]->getPlayerHome();
        for (auto iT = home.begin(); iT != home.end(); iT++)
        {
            if (!((*myBoard)[*iT].myPiece.empty()) && (*iT)==boardIndex)
            {
                return true;
            }
        }
    }
    return false;
}

void Ludo::releasePiece(const int boardIndex)
{
    cout << "releasing piece" << endl;// for testing purpose remove later on
    Piece* p =(*myBoard)[boardIndex].myPiece[0];
    (*myBoard)[boardIndex].myPiece.erase((*myBoard)[boardIndex].myPiece.begin());
    int startIndex = p->getMyPlayer()->getPlayerKey(_start);
    (*myBoard)[startIndex].myPiece.push_back(p);
    myBoard->displayBoard(window, p->getMyPlayer());
}

int Ludo::convertIndexToDiceIndex(const int index)
{
    return (abs(index)-1);
}

void Ludo::displayRolls(sf::RenderWindow& window, const vector<int>& myRolls, const Dice* myDice)
{
    int index = 0;
    for (auto iT = myRolls.begin(); iT != myRolls.end(); iT++)
    {
        myDice->displayRoll(window, index++, *iT);
    }
}

bool Ludo::canPlayMore(const Player* currentPlayer) {
    auto homeArea = currentPlayer->getPlayerHome();
    auto winI = currentPlayer->getPlayerKey(_end);
    auto doorI = currentPlayer->getPlayerKey(_door);
    int emptyCount=0;
    for (int i=0; i<4; i++) {
        if ((*myBoard)[homeArea[i]].myPiece.empty()) { // home empty
            emptyCount++;
        }
    }

    if (find(diceRolls.begin(), diceRolls.end(), 6) == diceRolls.end()) { // no 6 in die
        if (emptyCount == (*myBoard)[winI].myPiece.size()) { // no piece on regular board
            return false;
        }
        for (int i = doorI; i < winI; i++) {
            if ((*myBoard)[i].myPiece.size()>0) {
                auto cmp = winI-i;
                // check if the remainder path is present in dice, less or equal
                if(std::any_of(diceRolls.begin(), diceRolls.end(), [=](int i) { return i <= cmp; })) {
                    return true;
                } else {
                    // if only pieces remaining are on the win path, then return false, else can probably
                    auto rem = 4-((4-emptyCount)+(*myBoard)[winI].myPiece.size());
                    if (rem == 1) {
                        return false;
                    } else {
                        for (int j = i+1; j < winI; j++) {
                            if ((*myBoard)[i].myPiece.size()>0) {
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
    // Mukees is legal movement function
    for (int i = 0; i < 89; i++)
    {
        for (int j =0;j< (*myBoard)[i].myPiece.size(); j++)
        {
            for (auto dice = diceRolls.begin(); dice != diceRolls.end(); dice++)
            {
                if (!isTeamMode)
                {
                    if ((*myBoard)[i].myPiece[j]->getColor() == currentPlayer->getPlayerColor())
                    {
                        if (isLegal(i, j, *dice, currentPlayer))
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

// will be used for legal movement involving joota

bool Ludo::isLegal(int boardIndex, int selectedPieceIndex, int rolledNumber, const Player* player) const {
    if (isReleased(rolledNumber, player, boardIndex)) return true;
    if (isTeamMode)
    {
        if(isTeamPieceReleased(rolledNumber, player, boardIndex))
            return true;
    }
    Piece* pToMove = (*myBoard)[boardIndex].myPiece[0];//TODO CONFIRM IF DEFAULT 0 INDEX OR SHOULD BE SELECTEDPIECEINDEX
    auto playerTurn = pToMove->getMyPlayer();
    int currentIndex = boardIndex;
    while (rolledNumber != 0) {
        if ((*myBoard)[currentIndex].special && (*myBoard)[currentIndex].type == Home && playerTurn->getPlayerKey(_victory) == currentIndex && pToMove->canGoHome()) {
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
    }//added for teamMode
    if (isTeamMode)
    {
        colorType c = (*myBoard)[boardIndex].myPiece[selectedPieceIndex]->getColor();
        if (isTeamPiece(c) && player->getPlayerColor() != c)
        {
            if ((*myBoard)[player->getPlayerKey(_end)].myPiece.size() != 4)
                return false;
        }
    }
    return true;
}

void Ludo::checkLeaderBoard(Player* currentPly)
{
    if ((*myBoard)[currentPly->getPlayerKey(_end)].myPiece.size() == 4)
    {
        if (leaderBoard.find(currentPly) == leaderBoard.end())
        {
            leaderBoard.insert(currentPly);
        }
    }
}

void Ludo::checkLeaderBoardTeams(Player* plyr)
{
    int teamIndex = getPlayerTeamIndex(plyr, teams);
    for (int i = 0; i < teams[teamIndex].size(); i++)
    {
        int end = teams[teamIndex][i]->getPlayerKey(_end);
        if ((*myBoard)[end].myPiece.size() != 4)
            return;
    }
    if (teamLeaderBoard.find(teamIndex) == teamLeaderBoard.end())
        teamLeaderBoard.insert(teamIndex);
}

bool Ludo::isGameEnd()
{
    if (leaderBoard.size() == (players.size() - 1))
    {
        for (auto iT = players.begin(); iT != players.end(); iT++)
        {
            Player* p = *iT;
            if (leaderBoard.find(*iT) == leaderBoard.end())
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

bool Ludo::isGameEndTeams(const int totalTeams)
{
    if (teamLeaderBoard.size() == totalTeams-1)
    {
        for (int i = 0; i<teams.size(); i++)
        {
            if (teamLeaderBoard.find(i) == teamLeaderBoard.end())
            {
                teamLeaderBoard.insert(i);
                return true;
            }
        }
        throw("Invalid Case found");
    }
    else
        return false;
}

void Ludo::displayResult() const //TODO= CHANGE TO PROPER SCREEN
{
    sf::Sound s;
    s.setBuffer(sB);
    s.play();
    int count = 1;
    cout << "Results are in" << endl;
    for (auto iT = leaderBoard.begin(); iT != leaderBoard.end(); iT++)
    {
        cout << count++ <<"- Player "<< (*iT)->getPlayerColor() << endl;
    }
}

void Ludo::displayResultTeams() const//TODO= CHANGE TO PROPER SCREEN
{
    sf::Sound s;
    s.setBuffer(sB);
    s.play();
    int count = 1;
    cout << "Results are in" << endl;
    for (auto iT = teamLeaderBoard.begin(); iT != teamLeaderBoard.end(); iT++)
    {
        cout << count++ << " Team of ";
        for (int i = 0; i < teams[(*iT)].size(); i++)
            cout << teams[(*iT)][i]->getPlayerColor() << " ";
        cout << endl;
    }
}

bool Ludo::hasWon(const Player* p)const
{
    if (!isTeamMode && (*myBoard)[p->getPlayerKey(_end)].myPiece.size() == 4)// skips turn in individual mode if already won;
        return true;
    else
        return false;
}

void Ludo::play() {
    bgm.play();
    int teamIndex = 0;
    while (window.isOpen())
    {
        bgm.setLoop(true);
        Ludo::myBoard->displayBoard(Ludo::window, players[currentTurn]);
        window.display();
        if (isTeamMode)
            teamIndex = getPlayerTeamIndex(players[currentTurn], teams);
        int rollCount = 0;
        int roll=0;
        do
        {
            if(hasWon(players[currentTurn]))
                break;
            myDice->rollingDice(window, myBoard, diceRolls, rollCount, players[currentTurn]);
            //roll = myDice->rollDice();
            roll = myDice->cheatRoll(window);//cheat
            diceRolls.push_back(roll);
            rollCount++;
        } while (roll == 6 && rollCount != 3);
        Ludo::myBoard->displayBoard(Ludo::window, players[currentTurn]);
        displayRolls(window, diceRolls, myDice);
        window.display();
        __sleep(500);
        while (!diceRolls.empty() && !allSixes(diceRolls) && canPlayMore(players[currentTurn]))
        {
            myBoard->displayBoard(window, players[currentTurn]);
            displayRolls(window, diceRolls, myDice);
            window.display();
            int diceIndex = -1;
            do
            {
                diceIndex = select();

            } while (!isValidDiceSelect(diceRolls.size(), diceIndex));
            int currentRoll = convertIndexToDice(diceIndex);
            int selectedBoardIndex = -1;
            int selectedPieceIndex = 0;
            do
            {
                selectedBoardIndex = select();
                if (isValidDiceSelect(diceRolls.size(), selectedBoardIndex)) {
                    currentRoll = convertIndexToDice(selectedBoardIndex);
                    diceIndex = selectedBoardIndex;
                    selectedBoardIndex = -1;
                }
                else if (isValidSelection(selectedBoardIndex, players[currentTurn], currentRoll)) {
                    if ((*myBoard)[selectedBoardIndex].myPiece.size() > 1) {
                        do {
                            selectedPieceIndex = selectPiece((*myBoard)[selectedBoardIndex].myPiece);//TODO=enhance for teams and for look up
                        } while ((!isTeamMode && (*myBoard)[selectedBoardIndex].myPiece[selectedPieceIndex]->getColor() != players[currentTurn]->getPlayerColor() || (isTeamMode && !isTeamPiece((*myBoard)[selectedBoardIndex].myPiece[selectedPieceIndex]->getColor()))));
                    }
                    if (isLegal(selectedBoardIndex, selectedPieceIndex, currentRoll, players[currentTurn])) {//TODO=enhance for teams and joota
                        break;
                    }
                    else {
                        selectedPieceIndex = 0;
                    }
                }
            } while (true);
            diceRolls.erase(diceRolls.begin() + convertIndexToDiceIndex(diceIndex));
            if ((!isTeamMode && isReleased(currentRoll, players[currentTurn], selectedBoardIndex)) || (isTeamMode && isTeamPieceReleased(currentRoll, players[currentTurn], selectedBoardIndex)))
            {
                releasePiece(selectedBoardIndex);
            }
            else
            {
                auto currentIndex = myBoard->movePiece(window, selectedBoardIndex, currentRoll, selectedPieceIndex);
                if (isTeamMode)
                    myBoard->killTeam(window, currentIndex, players[currentTurn], teams[teamIndex]);
                else
                    myBoard->kill(window, currentIndex, players[currentTurn]);
                myBoard->displayBoard(window, players[currentTurn]);
            }
            window.display();
        }
        diceRolls.clear();
        if (isTeamMode)
            checkLeaderBoardTeams(players[currentTurn]);
        else
            checkLeaderBoard(players[currentTurn]);
        if (!isTeamMode)
        {
            if (isGameEnd())
            {
                displayResult();// TODO=change to proper leader board display and end game
            }
        }
        else if(isGameEndTeams(teams.size()))
        {
            if (isTeamMode)
                displayResultTeams();
        }
        changeTurn(currentTurn, noOfPlayers);

    }
}
