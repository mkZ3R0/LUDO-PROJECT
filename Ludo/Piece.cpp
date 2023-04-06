#include "Piece.h"

Piece::Piece(colorType c)
    :pColor(c)
{

}
colorType Piece::getColor()const
{
    return this->pColor;
}

void Piece::displayPiece(sf::RenderWindow& window)
{
    sf::Texture temp;
    temp.setSmooth(true);
    if(this->pColor==Blue)
    {
        if (!temp.loadFromFile("Assets/blueGoti.png"))
        {
            cout << "cannot Load immage";
        }
    }
    else if (this->pColor == Green)
    {
        if (!temp.loadFromFile("Assets/greenGoti.png"))
        {
            cout << "cannot Load immage";
        }
    }
    else if (this->pColor == Red)
    {
        if (!temp.loadFromFile("Assets/red.png"))
        {
            cout << "cannot Load immage";
        }
    }
    else if (this->pColor == Yellow)
    {
        if (!temp.loadFromFile("Assets/YellowGoti.png"))
        {
            cout << "cannot Load immage";
        }
    }
    sf::Sprite p(temp);
    //p.setColor(sf::Color::White);
    p.setOrigin(256.f, 256.f);
    p.setScale(0.089, 0.082);
    p.setPosition(354,617);//x axis offset 50
    //575
    window.draw(p);
}

/*
    p.setScale(0.089, 0.082);
    p.setPosition(204,494);*/
