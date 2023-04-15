#include "Piece.h"
#include "Board.h"

Piece::Piece(const Player* ply)
    :myPlayer(ply), pColor(ply->getPlayerColor())
{
    this->hasKilled = false;
}
colorType Piece::getColor()const
{
    return this->pColor;
}
bool Piece::canGoHome()const
{
    return this->hasKilled;
}
void Piece::changeKilledStatus()
{
    this->hasKilled = !(this->hasKilled);
}
void Piece::displayPiece(sf::RenderWindow& window, const placement image)
{
    sf::Sprite p;
    switch (pColor) {
    case Blue:
        if (this->canGoHome()) {
            p.setTexture(blue_k);
        } else {
            p.setTexture(blue);
        }
        break;
    case Green:
        if (this->canGoHome()) {
            p.setTexture(green_k);
        } else {
            p.setTexture(green);
        }        break;
    case Red:
        if (this->canGoHome()) {
            p.setTexture(red_k);
        } else {
            p.setTexture(red);
        }        break;
    case Yellow:
        if (this->canGoHome()) {
            p.setTexture(yellow_k);
        } else {
            p.setTexture(yellow);
        }        break;
    case Purple:
        if (this->canGoHome()) {
            p.setTexture(purple_k);
        } else {
            p.setTexture(purple);
        }        break;
    case Orange:
        if (this->canGoHome()) {
            p.setTexture(orange_k);
        } else {
            p.setTexture(orange);
        }        break;
    default:
        break;
    }

    auto _pieceSize = static_cast<sf::Vector2f>(p.getTexture()->getSize());
    auto scaleFactor = std::min(Board::xOffSet / _pieceSize.x, Board::yOffSet / _pieceSize.y);

    p.setOrigin(_pieceSize.x/2, _pieceSize.y/2);
    p.setScale(scaleFactor, scaleFactor);
    p.setPosition(image.x, image.y);

    window.draw(p);
}
const Player* Piece::getMyPlayer()const
{
    return this->myPlayer;
}
