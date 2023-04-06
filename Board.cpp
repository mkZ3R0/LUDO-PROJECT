#include "headers/Board.h"

Board::Board() {
    // TODO: handle six player board construction

    /* 
        6 boxes in one line
        3 lines in one area
        4 total areas
    */
    int size = (6*3)*4; // 72

    /*
        6 boxes in one line
        2 lines in one area + 1 additional box
        4 total areas
    */
    int regSize = ((6*2)*4)+4;

    this->path = std::vector<Posoition>(size);

    // make speical star postions
    int diff[2]= {8, 5}, i=1;
    for (int j = 0; j < regSize; j+=diff[i]) {
        path[j].makeSpecial(Star);
        i = (i+1)%2;
    }
    // make home path -> this is the position just outside the home line
    for (int j = 11, next=regSize+1; j < regSize; j+=13, next+=6) {
        path[j].makeSpecial(Home);
        path[j].setNext(next);
    }  
}