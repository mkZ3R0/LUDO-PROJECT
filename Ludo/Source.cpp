#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include "Board.h"

using namespace std;



int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");//,sf::Style::Fullscreen);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
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
        Board myBoard;
        Piece r(Red);
        Piece g(Green);
        Piece p(Purple);
        Piece b(Blue);
        Piece y(Yellow);
        Piece o(Orange);
        // displaying pieces
        while (indexR != -1)
        {
            if (indexR == 90)
                indexR = 0;
            if (indexY == 90)
                indexY = 0;
            if (indexG == 90)
                indexG = 0;
            if (indexB == 90)
                indexB = 0;
            if (indexP == 90)
                indexP = 0;
            if (indexO == 90)
                indexO = 0;
            myBoard.displayBoard(window);
            r.displayPiece(window, indexR++);
            o.displayPiece(window, indexO++);
            b.displayPiece(window, indexB++);
            g.displayPiece(window, indexG++);
            y.displayPiece(window, indexY++);
            p.displayPiece(window, indexP++);
            window.display();
            Sleep(500);
        }

    }

    return 0;
}