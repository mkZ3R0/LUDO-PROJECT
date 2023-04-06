#include "Piece.h"
#include "Board.h"
Piece::Piece(colorType c)
    :pColor(c)
{

}
colorType Piece::getColor()const
{
    return this->pColor;
}

void Piece::displayPiece(sf::RenderWindow& window,const int index)
{
    sf::Texture temp;
    temp.setSmooth(true);
    if(this->pColor==Blue)
    {
        if (!temp.loadFromFile("Assets/blue.png"))
        {
            cout << "cannot Load image";
        }
    }
    else if (this->pColor == Green)
    {
        if (!temp.loadFromFile("Assets/green.png"))
        {
            cout << "cannot Load image";
        }
    }
    else if (this->pColor == Red)
    {
        if (!temp.loadFromFile("Assets/red.png"))
        {
            cout << "cannot Load image";
        }
    }
    else if (this->pColor == Yellow)
    {
        if (!temp.loadFromFile("Assets/yellow.png"))
        {
            cout << "cannot Load image";
        }
    }
    else if (this->pColor == Purple)
    {
        if (!temp.loadFromFile("Assets/purple.png"))
        {
            cout << "cannot Load image";
        }
    }
    else if (this->pColor == Orange)
    {
        if (!temp.loadFromFile("Assets/orange.png"))
        {
            cout << "cannot Load image";
        }
    }
    sf::Sprite p(temp);
    placement image=Board::getBoardPlc(index);
    //p.setColor(sf::Color::White);
    p.setOrigin(256.f, 256.f);
    p.setScale(0.089, 0.075);
    p.setPosition(image.x,image.y);//y axis off set 37.1
    //p.setPosition(354,617);//x axis offset 37.3
    //317,392
    window.draw(p);
}
