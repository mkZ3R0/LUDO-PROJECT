#ifndef _POSITION
#define _POSITION

#include "utility.h"
#include "Piece.h"
#include <vector>

class Position {
    bool special;
    positionType type;
    std::vector<Piece*> myPiece;
public:
    Position();
    void makeSpecial(positionType);
};


#endif
