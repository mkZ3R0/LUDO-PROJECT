#ifndef _POSITION
#define _POSITION

#include "utility.h"
#include "Piece.h"
#include <vector>
#include "Board.h"

class Position {
    friend class Board;
    bool special;
    positionType type;
    std::vector<Piece*> myPiece;
public:
    Position();
    void makeSpecial(positionType);
};


#endif
