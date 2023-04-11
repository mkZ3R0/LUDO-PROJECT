#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include "Board.h"
#include "Dice.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Madni Ludo", sf::Style::Titlebar | sf::Style::Close);
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
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
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
            d.rollDice();
            d.displayRoll(window);
            window.display();
            __sleep(500);
        }

    }

    return 0;
}