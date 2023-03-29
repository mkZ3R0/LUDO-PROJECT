#ifndef _POSITION
#define _POSITION

#include "utility.h"
#include "Piece.h"
#include <vector>
#include <iostream>

class Posoition {
    bool special;
    positionType type;
    std::vector<Piece*> myPiece;
    int next;
public:

    Posoition();
    void makeSpecial(positionType);
    void setNext(int);

    // TEMPORARY!!!
    void give() {
        if (special) {
            std::cout << "Special -- type:" << type;
            if (type == Home) {
                std::cout << " -- home:" << next;
            }
        } else {
            std::cout << "Not special";
        }      
    }
};


#endif