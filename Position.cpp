#include "Position.h"

Posoition::Posoition() {
    special = false;
    type = Normal;
    myPiece = std::vector<Piece*>();
}

void Posoition::makeSpecial() {
    special = true;
}
