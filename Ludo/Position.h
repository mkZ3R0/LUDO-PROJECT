#ifndef _POSITION
#define _POSITION

#include "utility.h"
#include "Piece.h"
#include <vector>

class Position {
    friend class Board;
    friend class Ludo;
    bool special;
    positionType type;
    std::vector<Piece*> myPiece;
public:
    Position();
    void makeSpecial(positionType);
};


#endif
