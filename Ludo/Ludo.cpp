#include "Ludo.h"

sf::RenderWindow Ludo::window(sf::VideoMode(895, 558), "Madni Ludo", sf::Style::Titlebar | sf::Style::Close);
Board Ludo::myBoard;

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
    auto pieces = vector<Piece*>(4);
    for (int i = 0; i < 4; i++) {
        pieces.push_back(new Piece(player));
    }
    
    return pieces;
}

Ludo::Ludo() {
    int noOfPlayers=2; // input this with a different window

    auto players = allocatePlayers(noOfPlayers);

    for(auto& player: players) {
        auto pieces = allocatePiece(player);
        auto homeArea = player->getPlayerHome();
        for (int i=0; i<4; i++) {
            myBoard.path[homeArea[i]].myPiece.push_back(pieces[i]);
        }
    }
}

void Ludo::play() {
    int indexR = 71;
    int indexO = 13;
    int indexB = 58;
    int indexP = 0;
    int indexG = 26;
    int indexY = 45;
    while (window.isOpen())
    {
        Player green(Green);
        Player red(Red);
        Player purple(Purple);
        Player blue(Blue);
        Player yellow(Yellow);
        Player orange(Orange);
        Piece r(&red);
        Piece g(&green);
        Piece p(&purple);
        Piece b(&blue);
        Piece y(&yellow);
        Piece o(&yellow);
        Dice d;
        // displaying pieces
        while (indexR != -1)
        {
            myBoard.displayBoard(window);
            r.displayPiece(window, indexR++%150);
            o.displayPiece(window, indexO++%150);
            b.displayPiece(window, indexB++%150);
            g.displayPiece(window, indexG++%150);
            y.displayPiece(window, indexY++%150);
            p.displayPiece(window, indexP++%150);
            for (size_t id = 0; id < 3; id++) {
                d.rollDice();
                d.displayRoll(window,id);
            }
            window.display();
            cout << myBoard.clickToIndex(Board::mouseClick(window)) << endl;
        }
    }
}
