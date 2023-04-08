#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include "Board.h"

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
        Piece r(Red);
        Piece g(Green);
        Piece p(Purple);
        Piece b(Blue);
        Piece y(Yellow);
        Piece o(Orange);
        // displaying pieces
        while (indexR != -1)
        {
            myBoard.displayBoard(window);
            r.displayPiece(window, indexR++%90);
            o.displayPiece(window, indexO++%90);
            b.displayPiece(window, indexB++%90);
            g.displayPiece(window, indexG++%90);
            y.displayPiece(window, indexY++%90);
            p.displayPiece(window, indexP++%90);

            window.display();
            __sleep(500);
        }

    }

    return 0;
}