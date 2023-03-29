#ifndef _POSITION
#define _POSITION

#include "utility.h"
#include "Piece.h"
#include <vector>

class Posoition {
    bool special;
    positionType type;
    std::vector<Piece*> myPiece;
public:
    Posoition();
    void makeSpecial();
};


#endif