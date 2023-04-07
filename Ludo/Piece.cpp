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
    switch (pColor) {
    case Blue:
        p.setTexture(blue);
        break;
    case Green:
        p.setTexture(green);
        break;
    case Red:
        p.setTexture(red);
        break;
    case Yellow:
        p.setTexture(yellow);
        break;
    case Purple:
        p.setTexture(purple);
        break;
    case Orange:
        p.setTexture(orange);
        break;
    default:
        break;
    }

    placement image=Board::getBoardPlc(index);
    auto _pieceSize = static_cast<sf::Vector2f>(p.getTexture()->getSize());
    auto scaleFactor = std::min(Board::xOffSet / _pieceSize.x, Board::yOffSet / _pieceSize.y);

    p.setOrigin(_pieceSize.x/2, _pieceSize.y/2);
    p.setScale(scaleFactor, scaleFactor);
    p.setPosition(image.x,image.y);

    window.draw(p);
}
