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
    sf::Sprite p;
    if(this->pColor==Blue) {
        p.setTexture(blue);
    }
    else if (this->pColor == Green) {
        p.setTexture(green);
    }
    else if (this->pColor == Red) {
        p.setTexture(red);
    }
    else if (this->pColor == Yellow) {
        p.setTexture(yellow);
    }
    else if (this->pColor == Purple) {
        p.setTexture(purple);
    }
    else if (this->pColor == Orange) {
        p.setTexture(orange);
    }

    //sf::Sprite p(temp);
    placement image=Board::getBoardPlc(index);
    //p.setColor(sf::Color::White);
    p.setOrigin(256.f, 256.f);
    p.setScale(0.089, 0.075);
    p.setPosition(image.x,image.y);//y axis off set 37.1
    //p.setPosition(354,617);//x axis offset 37.3
    //317,392
    window.draw(p);
}
