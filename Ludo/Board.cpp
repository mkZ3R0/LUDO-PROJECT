#include "Board.h"
#include "Piece.h"
#include "Position.h"

sf::Texture Piece::red;
sf::Texture Piece::blue;
sf::Texture Piece::yellow;
sf::Texture Piece::green;
sf::Texture Piece::orange;
sf::Texture Piece::purple;
sf::Texture Piece::red_k;
sf::Texture Piece::blue_k;
sf::Texture Piece::yellow_k;
sf::Texture Piece::green_k;
sf::Texture Piece::orange_k;
sf::Texture Piece::purple_k;
sf::Texture Piece::multi;
sf::Texture Board::boardBg;
sf::Texture Board::turnBg;
sf::Texture Board::teamBg;
sf::Texture Board::quit;
sf::SoundBuffer Board::buffer;
sf::SoundBuffer Board::buffer2;
float Board::yOffSet;
float Board::xOffSet;

sf::Font Board::fontB;
sf::Text Board::textB;

void Board::displayTotalPieces(sf::RenderWindow& window, const int count, const int index)
{
    textB.setFont(fontB);
    textB.setString(to_string(count));
    textB.setFillColor(sf::Color::Black);
    textB.setOrigin(Board::xOffSet / 2.4, Board::yOffSet / 2.4);
    if(count<=9)
        textB.setCharacterSize(18);
    else
        textB.setCharacterSize(15);
    textB.setPosition(boardPlc[index].x,boardPlc[index].y);
    textB.Style::Bold;
    window.draw(textB);
}

void Board::loadAssets() {
    if (!Piece::blue.loadFromFile("Assets/blue.png")) {
            cerr << "Cannot load blue.png" << endl;
            exit(1);
    }
    if (!Piece::green.loadFromFile("Assets/green.png")) {
        cerr << "Cannot load green.png" << endl;
        exit(1);
    }
    if (!Piece::red.loadFromFile("Assets/red.png")) {
        cerr << "Cannot load red.png" << endl;
        exit(1);
    }
    if (!Piece::yellow.loadFromFile("Assets/yellow.png")) {
        cerr << "Cannot load yellow.png" << endl;
        exit(1);
    }
    if (!Piece::purple.loadFromFile("Assets/purple.png")) {
        cerr << "Cannot load purple.png" << endl;
        exit(1);
    }
    if (!Piece::orange.loadFromFile("Assets/orange.png")) {
        cerr << "Cannot load orange.png" << endl;
        exit(1);
    }
    if (!Piece::blue_k.loadFromFile("Assets/blue_k.png")) {
            cerr << "Cannot load blue_k.png" << endl;
            exit(1);
    }
    if (!Piece::green_k.loadFromFile("Assets/green_k.png")) {
        cerr << "Cannot load green_k.png" << endl;
        exit(1);
    }
    if (!Piece::red_k.loadFromFile("Assets/red_k.png")) {
        cerr << "Cannot load red_k.png" << endl;
        exit(1);
    }
    if (!Piece::yellow_k.loadFromFile("Assets/yellow_k.png")) {
        cerr << "Cannot load yellow_k.png" << endl;
        exit(1);
    }
    if (!Piece::purple_k.loadFromFile("Assets/purple_k.png")) {
        cerr << "Cannot load purple_k.png" << endl;
        exit(1);
    }
    if (!Piece::orange_k.loadFromFile("Assets/orange_k.png")) {
        cerr << "Cannot load orange_k.png" << endl;
        exit(1);
    }
    if (!Piece::multi.loadFromFile("Assets/multi_color.png")) {
        cerr << "Cannot load multi.png" << endl;
        exit(1);
    }
    if (!Board::boardBg.loadFromFile("Assets/board6.png")) {
        cerr << "Cannot load board6.png" << endl;
        exit(1);
    }
    if (!Board::turnBg.loadFromFile("Assets/turn.png")) {
        cerr << "Cannot load turn.png" << endl;
        exit(1);
    }
    if (!Board::teamBg.loadFromFile("Assets/team.png")) {
        cerr << "Cannot load team.png" << endl;
        exit(1);
    }
    if (!Board::fontB.loadFromFile("Assets/font.ttf")) {
        cerr << "Cannot load font" << endl;
        exit(1);
    }
    if (!Board::quit.loadFromFile("Assets/quit.png")) {
        cerr << "Cannot load quit.png" << endl;
        exit(1);
    }
    if (!buffer.loadFromFile("Assets/explosion.wav"))
    {
        cerr << "Cannot load explosion.wav" << endl;
        exit(1);
    }
    if (!buffer2.loadFromFile("Assets/scream.wav"))
    {
        cerr << "Cannot load scream.wav" << endl;
        exit(1);
    }
}

int Board::clickToIndex(placement click) {
    int x = click.x / xOffSet;
    int y = click.y / yOffSet;

    // orange area
    if (x >= 0 && x <= 5) {
        if (y==6) {
            return 12+x;
        } else if (y==8) {
            return 10-x;
        } else if (y==7) {
            if (x==0) return 11;
            else return 95+x;
        }
    // darmian wala arrow area
    } else if (x>= 9 && x<= 14) {
        if (y==6) {
            return 31 + (x-9);
        } else if (y==8) {
            return 81 - (x-9);
        }
    // blue area
    } else if (x>= 18 && x<= 23) {
        if (y==6) {
            return 50 + (x-18);
        } else if (y==8) {
            return 62 - (x-18);
        } else if (y==7) {
            if (x==23) return 56;
            else return 118-(x-18);
        }
    }
    if (y>=0 && y<=5) {
        // green side
        if (x==6) {
            return 23 - y;
        } else if (x==8) {
            return 25 + y;
        } else if (x==7) {
            if(y==0) return 24;
            else return 101 + y;
        // yellow side
        } else if (x==15) {
            return 42 - y;
        } else if (x==17) {
            return 44 + y;
        } else if (x==16) {
            if(y==0) return 43;
            else return 107+y;
        }
    } else if (y>=9 && y<=14) {
        // purple area
        if (x==6) {
            if (y<=13) {
                return 4 - (y-9);
            } else {
                return 89;
            }
        } else if (x==8) {
            return 82 + (y-9);
        } else if (x==7) {
            if(y==14) return 88;
            else return 94 - (y-9);
        // red area
        } else if (x==15) {
            return 75 - (y-9);
        } else if (x==17) {
            return 63 + (y-9);
        } else if (x==16) {
            if(y==14) return 69; // nice
            else return 124 - (y-9);
        }
    }
    if (x>=2 && x<=3) {
        if (y==2) {
            return 130 + (x-2);
        } else if (y==3) {
            return 132 + (x-2);
        } else if (y==11) {
            return 126 + (x-2);
        } else if (y==12) {
            return 128 + (x-2);
        }
    } else if (x>= 11 && x<=12) {
        if (y==2) {
            return 134+(x-11);
        } else if (y==3) {
            return 136+(x-11);
        } else if (y==11) {
            return 146+(x-11);
        } else if (y==12) {
            return 148+(x-11);
        }
    } else if (x>=20 && x<=21) {
        if (y==2) {
            return 138+(x-20);
        } else if (y==3) {
            return 140+(x-20);
        } else if (y==11) {
            return 142+(x-20);
        } else if (y==12) {
            return 144+(x-20);
        }
    }
    if (y==7) {
        if (x==9) return -4;
        else if (x>=11 && x<=13) return -1*(x-10);
    }
    return -99;
}

placement Board::mouseClick(sf::RenderWindow& window) {
    placement raw{-1, -1};
    sf::Event event;
    while (window.waitEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                exit(0);
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    raw.y = event.mouseButton.y;
                    raw.x = event.mouseButton.x;
                    return raw;
                }
                break;
            default:
                break;
        }
    }
    return raw;
}

Board::Board(sf::RenderWindow& window) {
    this->loadAssets();

    float scaleX = (float)window.getSize().x / boardBg.getSize().x;
    float scaleY = (float)window.getSize().y / boardBg.getSize().y;
    auto bgSize = static_cast<sf::Vector2f>(boardBg.getSize());

    yOffSet = (bgSize.y*scaleY)/15.0; // 15 boxes from top to bottom
    xOffSet = (bgSize.x*scaleX)/24.0; // 24 boxes from left to right

    int size = 150;
    int regSize = 89;

    this->path = std::vector<Position>(size);

    map<int, positionType> mapping = {
        {0, Star},
        {8, Death},
        {11, Home},
        {13, Star},
        {21, Death},
        {24, Home},
        {26, Star},
        {34, Death},
        {40, Death},
        {43, Home},
        {45, Star},
        {53, Death},
        {56, Home},
        {58, Star},
        {66, Death},
        {69, Home},
        {71, Star},
        {79, Death},
        {85, Death},
        {88, Home}
    };

    for(auto sp: mapping) {
        path[sp.first].makeSpecial(sp.second);
    }

    Board::calculateBoardPlc();
}


// Board Indexes Guide: ( total 150, still working on more)
// indexes 0-89 board path
// 90-95 purple path to victory
// 96-101 orange path to victory
// 102-107 green path to victory
// 108-113 yellow path to victory
// 114-119 blue path to victory
// 120-125 red path to victory
// 126-129 purple home
// 130-133 orange home
// 134-137 green home
// 138-141 yellow home
// 142-145 blue home
// 146-149 red home


vector<placement> Board::boardPlc(150);
void Board::calculateBoardPlc()
{
    int index = 1;

    boardPlc[0] = {static_cast<float>(xOffSet*6 + xOffSet/2.0), static_cast<float>(yOffSet*13 + yOffSet/2.0)};
    while (index != 90)
    {
        while ((index >= 1 && index <= 4) || (index >= 11 && index <= 12) || (index >= 19 && index <= 23) || (index >= 38 && index <= 42) || (index >= 71 && index <= 75))
        {
            boardPlc[index] = { boardPlc[index - 1].x, boardPlc[index - 1].y - yOffSet };
            index++;
        }
        if ((index == 5) || (index == 76))
        {
            boardPlc[index] = { boardPlc[index - 1].x - xOffSet, boardPlc[index - 1].y - yOffSet };
            index++;
        }
        while ((index >= 6 && index <= 10) || (index >= 58 && index <= 62) || (index >= 69 && index <= 70) || (index >= 77 && index <= 81) || (index >= 88 && index <= 89))
        {
            boardPlc[index] = { boardPlc[index - 1].x - xOffSet, boardPlc[index - 1].y };
            index++;
        }
        while ((index >= 13 && index <= 17) || (index >= 24 && index <= 25) || (index >= 32 && index <= 36) || (index >= 43 && index <= 44) || (index >= 51 && index <= 55))
        {
            boardPlc[index] = { boardPlc[index - 1].x + xOffSet, boardPlc[index - 1].y };
            index++;
        }
        if ((index == 18) || (index == 37))
        {
            boardPlc[index] = { boardPlc[index - 1].x + xOffSet, boardPlc[index - 1].y - yOffSet };
            index++;
        }
        while ((index >= 26 && index <= 30) || (index >= 45 && index <= 49) || (index >= 56 && index <= 57) || (index >= 64 && index <= 68) || (index >= 83 && index <= 87))
        {
            boardPlc[index] = { boardPlc[index - 1].x, boardPlc[index - 1].y + yOffSet };
            index++;
        }
        if ((index == 31) || (index == 50))
        {
            boardPlc[index] = { boardPlc[index - 1].x + xOffSet, boardPlc[index - 1].y + yOffSet };
            index++;
        }
        if ((index == 63) || (index == 82))
        {
            boardPlc[index] = { boardPlc[index - 1].x - xOffSet, boardPlc[index - 1].y + yOffSet };
            index++;
        }
    }
    while (index != 126)
    {
        while ((index >= 91 && index <= 95) || (index >= 121 && index <= 125))
        {
            boardPlc[index] = { boardPlc[index - 1].x, boardPlc[index - 1].y - yOffSet };
            index++;
        }
        while (index >= 97 && index <= 101)
        {
            boardPlc[index] = { boardPlc[index - 1].x + xOffSet, boardPlc[index - 1].y };
            index++;
        }
        while ((index >= 103 && index <= 107) || (index >= 109 && index <= 113))
        {
            boardPlc[index] = { boardPlc[index - 1].x, boardPlc[index - 1].y + yOffSet };
            index++;
        }
        while (index >= 115 && index <= 119)
        {
            boardPlc[index] = { boardPlc[index - 1].x - xOffSet, boardPlc[index - 1].y };
            index++;
        }
        if (index == 90)
        {
            boardPlc[index] = { boardPlc[88].x, boardPlc[88].y - yOffSet };
            index++;
        }
        if (index == 96)
        {
            boardPlc[index] = { boardPlc[11].x+xOffSet, boardPlc[11].y};
            index++;
        }
        if (index == 102)
        {
            boardPlc[index] = { boardPlc[24].x , boardPlc[24].y +yOffSet};
            index++;
        }
        if (index == 108)
        {
            boardPlc[index] = { boardPlc[43].x, boardPlc[43].y + yOffSet };
            index++;
        }
        if (index == 114)
        {
            boardPlc[index] = { boardPlc[56].x-xOffSet, boardPlc[56].y};
            index++;
        }
        if (index == 120)
        {
            boardPlc[index] = { boardPlc[69].x, boardPlc[69].y -yOffSet};
            index++;
        }
    }
    while (index != 150)
    {
        boardPlc[126] = { boardPlc[2].x - (4 * xOffSet), boardPlc[2].y };
        boardPlc[130] = { boardPlc[14].x, boardPlc[14].y - (4 * yOffSet) };
        boardPlc[134] = { boardPlc[27].x + (3 * xOffSet), boardPlc[27].y };
        boardPlc[138] = { boardPlc[46].x + (3 * xOffSet), boardPlc[46].y };
        boardPlc[142] = { boardPlc[60].x , boardPlc[60].y + (3 * yOffSet) };
        boardPlc[146] = { boardPlc[73].x - (4 * xOffSet), boardPlc[73].y };
        if (index == 126 || index == 130 || index == 134 || index == 138 || index == 142 || index == 146)
            index++;
        if (index == 127 || index == 131 || index == 135 || index == 139 || index == 143 || index == 147)
        {
            boardPlc[index] = { boardPlc[index-1].x + xOffSet, boardPlc[index-1].y };
            index++;
        }
        if (index == 128 || index == 132 || index == 136 || index == 140 ||  index == 144 || index == 148)
        {
            boardPlc[index] = { boardPlc[index-1].x - xOffSet, boardPlc[index-1].y + yOffSet };
            index++;
        }
        if (index == 129 || index == 133 || index == 137 || index == 141 || index == 145 || index == 149)
        {
            boardPlc[index] = { boardPlc[index-1].x + xOffSet, boardPlc[index-1].y };
            index++;
        }
    }
}

int Board::countPieceColor(const colorType c, const int bIndex) const
{
    int count = 0;
    for (auto iT = (*this)[bIndex].myPiece.begin(); iT != (*this)[bIndex].myPiece.end(); iT++)
    {
        if ((*iT)->getColor() == c)
            count++;
    }
    return count;
}

void Board::displayBoard(sf::RenderWindow& window, const Player* currentPlayer, const vector<Player*> team)const
{
    int index = 0;
    sf::Sprite s(boardBg);
    s.setColor(sf::Color::White);

    s.setPosition(0, 0);

    // scale to window
    float scaleX = (float)window.getSize().x / boardBg.getSize().x;
    float scaleY = (float)window.getSize().y / boardBg.getSize().y;
    s.setScale(scaleX, scaleY);

    window.draw(s);
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i].myPiece.size() != 0)
        {
            if (path[i].myPiece.size() != countPieceColor(path[i].myPiece[0]->getColor(), i)) {
                path[i].myPiece.front()->displayPiece(window, getBoardPlc(i), true);
            }
            else {
                path[i].myPiece.front()->displayPiece(window, getBoardPlc(i));
            }
        }
        if(path[i].myPiece.size()>1)
        {
            displayTotalPieces(window, path[i].myPiece.size(), i);
        }
    }

    sf::Sprite q;
    q.setTexture(quit);
    auto _quitSize = static_cast<sf::Vector2f>(quit.getSize());
    auto scaleFactor = std::min(xOffSet / _quitSize.x, yOffSet / _quitSize.y);
    q.setOrigin(_quitSize.x / 2, _quitSize.y / 2);
    q.setScale(scaleFactor, scaleFactor);
    q.setPosition(boardPlc[81].x, boardPlc[81].y - yOffSet);
    window.draw(q);

    if (currentPlayer != nullptr) {
        auto home = currentPlayer->getPlayerHome()[3];
        auto pos = getBoardPlc(home);
        placement p = {(float)(pos.x-(0.50*xOffSet)), (float)(pos.y-(0.50*yOffSet))};
        sf::Sprite highlight(turnBg);

        auto _Size = static_cast<sf::Vector2f>(turnBg.getSize());

        highlight.setOrigin(_Size.x/2, _Size.y/2);

        highlight.setPosition(p.x, p.y);
        highlight.setScale(scaleX, scaleY);
        window.draw(highlight);
    }
    if (!team.empty()) {
        for(auto& player: team) {
            auto home = player->getPlayerHome()[3];
            auto pos = getBoardPlc(home);
            placement p = {(float)(pos.x-(0.50*xOffSet)), (float)(pos.y-(0.50*yOffSet))};
            sf::Sprite highlight(teamBg);

            auto _Size = static_cast<sf::Vector2f>(teamBg.getSize());

            highlight.setOrigin(_Size.x/2, _Size.y/2);

            highlight.setPosition(p.x, p.y);
            highlight.setScale(scaleX, scaleY);
            window.draw(highlight);
        }
    }
}

placement Board::getBoardPlc(const int index)
{
    return boardPlc[index];
}

int Board::movePiece(sf::RenderWindow& window, int boardIndex, int rolledNumber, int indexPieceNum, const vector<Player*> team)
{
    Piece* pToMove = path[boardIndex].myPiece[indexPieceNum];
    auto playerTurn = pToMove->getMyPlayer();
    path[boardIndex].myPiece.erase(path[boardIndex].myPiece.begin() + indexPieceNum);
    int currentIndex = boardIndex;
    while (rolledNumber != 0)
    {
        if (path[currentIndex].special && path[currentIndex].type == Home && playerTurn->getPlayerKey(_victory) == currentIndex && pToMove->canGoHome())
        {
            rolledNumber--;
            currentIndex = playerTurn->getPlayerKey(_door);
            displayBoard(window, playerTurn, team);
            pToMove->displayPiece(window, getBoardPlc(currentIndex));
            window.display();
            __sleep(100);
        }
        else
        {
            rolledNumber--;
            if (currentIndex == 89)
                currentIndex = 0;
            else
                currentIndex++;
            displayBoard(window, playerTurn, team);
            pToMove->displayPiece(window, getBoardPlc(currentIndex));
            window.display();
            __sleep(100);
        }
    }
    path[currentIndex].myPiece.push_back(pToMove);
    if (path[currentIndex].special && path[currentIndex].type == Death)
    {
        sf::Sound s;
        s.setBuffer(buffer);
        s.play();
        __sleep(800);
        path[currentIndex].myPiece.erase(find(path[currentIndex].myPiece.begin(), path[currentIndex].myPiece.end(), pToMove));
        auto goHome = playerTurn->getPlayerHome();
        for (auto i = goHome.begin(); i != goHome.end(); i++)
        {
            if (path[*i].myPiece.empty())
            {
                path[*i].myPiece.push_back(pToMove);
                displayBoard(window, playerTurn, team);
                pToMove->displayPiece(window, getBoardPlc(*i));
                window.display();
                break;
            }
        }
    }
    return currentIndex;
}

void Board::kill(sf::RenderWindow& window, int currentIndex, Player* currentPlayer)
{
    if (path[currentIndex].myPiece.size() == 2 && path[currentIndex].type != Star)
    {
        if (path[currentIndex].myPiece[0]->getMyPlayer()->getPlayerColor() != currentPlayer->getPlayerColor()) {
            auto pToKill = path[currentIndex].myPiece[0];
            if (pToKill->canGoHome()) {
                pToKill->changeKilledStatus();
            }
            sf::Sound s;
            s.setBuffer(buffer2);
            s.play();
            __sleep(1000);
            auto home = pToKill->getMyPlayer()->getPlayerHome();
            path[currentIndex].myPiece.erase(path[currentIndex].myPiece.begin());
            for (auto i = home.begin(); i != home.end(); i++) {
                if (path[*i].myPiece.empty()) {
                    path[*i].myPiece.push_back(pToKill);
                    displayBoard(window, pToKill->getMyPlayer());
                    pToKill->displayPiece(window, getBoardPlc(*i));
                    window.display();
                    break;
                }
            }
            if (!path[currentIndex].myPiece[0]->canGoHome()) {
                path[currentIndex].myPiece[0]->changeKilledStatus();
            }
        }
    }
}

void Board::killTeam(sf::RenderWindow& window, int currentIndex, Player* currentPlayer, const vector<Player*>& team) {
    if (path[currentIndex].myPiece.size()==2 && path[currentIndex].type != Star) {
        colorType pieceClr = path[currentIndex].myPiece[0]->getMyPlayer()->getPlayerColor();
        for (int i = 0; i < team.size(); i++)
        {
            if (team[i]->getPlayerColor() == pieceClr)
                return;
        }
        if (pieceClr != currentPlayer->getPlayerColor()) {
            auto pToKill = path[currentIndex].myPiece[0];
            if (pToKill->canGoHome()) {
                pToKill->changeKilledStatus();
            }
            sf::Sound s;
            s.setBuffer(buffer2);
            s.play();
            __sleep(1000);
            auto home = pToKill->getMyPlayer()->getPlayerHome();
            path[currentIndex].myPiece.erase(path[currentIndex].myPiece.begin());
            for (auto i = home.begin(); i != home.end(); i++) {
                if (path[*i].myPiece.empty()) {
                    path[*i].myPiece.push_back(pToKill);
                    displayBoard(window, pToKill->getMyPlayer(), team);
                    pToKill->displayPiece(window, getBoardPlc(*i));
                    window.display();
                    break;
                }
            }
            if (!path[currentIndex].myPiece[0]->canGoHome()) {
                path[currentIndex].myPiece[0]->changeKilledStatus();
            }
        }
    }
}

Position& Board::operator[](const int i) {
    return this->path[i];
}

const Position &Board::operator[](const int i) const {
    return this->path[i];
}
