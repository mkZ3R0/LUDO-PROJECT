#include "Position.h"

Position::Position() {
    special = false;
    type = Normal;
    myPiece = std::vector<Piece*>();
}

void Position::makeSpecial() {
    special = true;
}