#include "headers/Position.h"

Posoition::Posoition() {
    special = false;
    type = Normal;
    myPiece = std::vector<Piece*>();
    next = -1;
}

void Posoition::makeSpecial(positionType t) {
    special = true;
    type = t;
}

void Posoition::setNext(int n) {
    next = n;
}
