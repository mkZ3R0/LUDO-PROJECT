#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include "Board.h"
#include "Dice.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(895, 558), "Madni Ludo", sf::Style::Titlebar | sf::Style::Close);
    Board myBoard;
    Board::calculateBoardPlc();
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

            //__sleep(500);
        }

    }

    return 0;
}