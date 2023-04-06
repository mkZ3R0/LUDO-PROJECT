#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include "Board.h"
#include<conio.h>

using namespace std;



// Function to get the position on screen by mouse
void static getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window)
{
    while (true)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i p = sf::Mouse::getPosition(window);

            cpos = p.x;
            rpos = p.y;
            break;
        }
    }
}


// Function to print image on screen

void print(sf::RenderWindow& window,string name,int column, int row,int scx,int scy)
{
    sf::Texture temp;
    if (!temp.loadFromFile(name))  //  img ==> file name for image
    {
        cout << "cannot Load immage";
    }

    sf::Sprite s(temp);
    s.setColor(sf::Color::White);
    s.setScale(scx,scy); //  (width and heigth of image to be printed)

    s.setPosition(column, row); // position of image
    window.draw(s);	// draw() will only draw image on backend, image will not display on screen
    window.display();  // display() will show image on screen
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");//,sf::Style::Fullscreen);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Board myBoard;
        myBoard.displayBoard(window);
    }

    return 0;
}