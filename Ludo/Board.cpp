#include "Board.h"
#include "Piece.h"

sf::Texture Piece::red;
sf::Texture Piece::blue;
sf::Texture Piece::yellow;
sf::Texture Piece::green;
sf::Texture Piece::orange;
sf::Texture Piece::purple;
sf::Texture Board::boardBg;

float Board::yOffSet;
float Board::xOffSet;

void Board::loadAssets() {
    if (!Piece::blue.loadFromFile("Assets/blue.png")) {
            cerr << "Cannot load blue.png" << endl;
            exit(1);
    }
    if (!Piece::green.loadFromFile("Assets/green.png")) {
        cerr << "Cannot load green.png" << endl;
        exit(1);        
    }
    if (!Piece::red.loadFromFile("Assets/red.png")) {
        cerr << "Cannot load red.png" << endl;
        exit(1);   
    }
    if (!Piece::yellow.loadFromFile("Assets/yellow.png")) {
        cerr << "Cannot load yellow.png" << endl;
        exit(1);
    }
    if (!Piece::purple.loadFromFile("Assets/purple.png")) {
        cerr << "Cannot load purple.png" << endl;
        exit(1);
    }
    if (!Piece::orange.loadFromFile("Assets/orange.png")) {
        cerr << "Cannot load orange.png" << endl;
        exit(1);
    }
    if (!Board::boardBg.loadFromFile("Assets/board6.png")) {
        cerr << "Cannot load board6.png" << endl;
        exit(1);
    }
}

Board::Board() {
    this->loadAssets();
    auto bgSize = static_cast<sf::Vector2f>(boardBg.getSize());
    yOffSet = bgSize.y/15.0; // 15 boxes from top to bottom
    xOffSet = bgSize.x/24.0; // 24 boxes from left to right
}


//Board Indexes Guide: ( total 150, still working on more)
//indexes 0-89 board path
//90-95 purple path to victory
//96-101 orange path to victory
//102-107 green path to victory
//108-113 yellow path to victory
//114-119 blue path to victory
//120-125 red path to victory
//126-129 purple home
//130-133 orange home
//134-137 green home
//138-141 yellow home
//142-145 blue home
//146-149 red home


vector<placement> Board::boardPlc(150);
void Board::calculateBoardPlc()
{
    int index = 1;

    boardPlc[0] = {242.4,503.4 };
    while (index != 90)
    {
        while ((index >= 1 && index <= 4) || (index >= 11 && index <= 12) || (index >= 19 && index <= 23) || (index >= 38 && index <= 42) || (index >= 71 && index <= 75))
        {
            boardPlc[index] = { boardPlc[index - 1].x, boardPlc[index - 1].y - yOffSet };
            index++;
        }
        if ((index == 5) || (index == 76))
        {
            boardPlc[index] = { boardPlc[index - 1].x - xOffSet, boardPlc[index - 1].y - yOffSet };
            index++;
        }
        while ((index >= 6 && index <= 10) || (index >= 58 && index <= 62) || (index >= 69 && index <= 70) || (index >= 77 && index <= 81) || (index >= 88 && index <= 89))
        {
            boardPlc[index] = { boardPlc[index - 1].x - xOffSet, boardPlc[index - 1].y };
            index++;
        }
        while ((index >= 13 && index <= 17) || (index >= 24 && index <= 25) || (index >= 32 && index <= 36) || (index >= 43 && index <= 44) || (index >= 51 && index <= 55))
        {
            boardPlc[index] = { boardPlc[index - 1].x + xOffSet, boardPlc[index - 1].y };
            index++;
        }
        if ((index == 18) || (index == 37))
        {
            boardPlc[index] = { boardPlc[index - 1].x + xOffSet, boardPlc[index - 1].y - yOffSet };
            index++;
        }
        while ((index >= 26 && index <= 30) || (index >= 45 && index <= 49) || (index >= 56 && index <= 57) || (index >= 64 && index <= 68) || (index >= 83 && index <= 87))
        {
            boardPlc[index] = { boardPlc[index - 1].x, boardPlc[index - 1].y + yOffSet };
            index++;
        }
        if ((index == 31) || (index == 50))
        {
            boardPlc[index] = { boardPlc[index - 1].x + xOffSet, boardPlc[index - 1].y + yOffSet };
            index++;
        }
        if ((index == 63) || (index == 82))
        {
            boardPlc[index] = { boardPlc[index - 1].x - xOffSet, boardPlc[index - 1].y + yOffSet };
            index++;
        }
    }
    while (index != 126)
    {
        while ((index >= 91 && index <= 95) || (index >= 121 && index <= 125))
        {
            boardPlc[index] = { boardPlc[index - 1].x, boardPlc[index - 1].y - yOffSet };
            index++;
        }
        while (index >= 97 && index <= 101)
        {
            boardPlc[index] = { boardPlc[index - 1].x + xOffSet, boardPlc[index - 1].y };
            index++;
        }
        while ((index >= 103 && index <= 107) || (index >= 109 && index <= 113))
        {
            boardPlc[index] = { boardPlc[index - 1].x, boardPlc[index - 1].y + yOffSet };
            index++;
        }
        while (index >= 115 && index <= 119)
        {
            boardPlc[index] = { boardPlc[index - 1].x - xOffSet, boardPlc[index - 1].y };
            index++;
        }
        if (index == 90)
        {
            boardPlc[index] = { boardPlc[88].x, boardPlc[88].y - yOffSet };
            index++;
        }
        if (index == 96)
        {
            boardPlc[index] = { boardPlc[11].x+xOffSet, boardPlc[11].y};
            index++;
        }
        if (index == 102)
        {
            boardPlc[index] = { boardPlc[24].x , boardPlc[24].y +yOffSet};
            index++;
        }
        if (index == 108)
        {
            boardPlc[index] = { boardPlc[43].x,boardPlc[43].y + yOffSet };
            index++;
        }
        if (index == 114)
        {
            boardPlc[index] = { boardPlc[56].x-xOffSet, boardPlc[56].y};
            index++;
        }
        if (index == 120)
        {
            boardPlc[index] = { boardPlc[69].x, boardPlc[69].y -yOffSet};
            index++;
        }
    }
    while (index != 150)
    {
        boardPlc[126] = { boardPlc[2].x - (4 * xOffSet), boardPlc[2].y };
        boardPlc[130] = { boardPlc[14].x, boardPlc[14].y - (4 * yOffSet) };
        boardPlc[134] = { boardPlc[27].x + (3 * xOffSet), boardPlc[27].y };
        boardPlc[138] = { boardPlc[46].x + (3 * xOffSet), boardPlc[46].y };
        boardPlc[142] = { boardPlc[60].x , boardPlc[60].y + (3 * yOffSet) };
        boardPlc[146] = { boardPlc[73].x - (4 * xOffSet), boardPlc[73].y };
        if (index == 126 || index == 130 || index == 134 || index == 138 || index == 142 || index == 146)
            index++;
        if (index == 127 || index == 131 || index == 135 || index == 139 || index == 143 || index == 147)
        {
            boardPlc[index] = { boardPlc[index-1].x + xOffSet, boardPlc[index-1].y };
            index++;
        }
        if (index == 128 || index == 132 || index == 136 || index == 140 ||  index == 144 || index == 148)
        {
            boardPlc[index] = { boardPlc[index-1].x - xOffSet, boardPlc[index-1].y + yOffSet };
            index++;
        }
        if (index == 129 || index == 133 || index == 137 || index == 141 || index == 145 || index == 149)
        {
            boardPlc[index] = { boardPlc[index-1].x + xOffSet, boardPlc[index-1].y };
            index++;
        }
    }
}

void Board::displayBoard(sf::RenderWindow& window)
{
    int index = 0;
    sf::Sprite s(boardBg);
    s.setColor(sf::Color::White);
    s.setScale(1,1); //  (width and heigth of image to be printed)
    s.setPosition(0,0); // position of image
    window.draw(s);	// draw() will only draw image on backend, image will not display on screen
}

placement Board::getBoardPlc(const int index)
{
    return boardPlc[index];
}
