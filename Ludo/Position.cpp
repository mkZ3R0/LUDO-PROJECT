#include "Position.h"

Position::Position() {
    special = false;
    type = Normal;
    myPiece = std::vector<Piece*>();
}

void Position::makeSpecial(positionType _type) {
    special = true;
    type = _type;
}