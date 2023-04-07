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

vector<placement> Board::boardPlc(90);
void Board::calculateBoardPlc()
{
    int index = 1;

    boardPlc[0] = {242.4,503.4 };
    while (index >=1 && index <=4 )
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y - yOffSet };
        index++;
    }
    if (index == 5)
    {
        boardPlc[index] = { boardPlc[index - 1].x-xOffSet,boardPlc[index - 1].y - yOffSet };
        index++;
    }
    while (index >= 6 && index <= 10)
    {
        boardPlc[index] = { boardPlc[index - 1].x-xOffSet,boardPlc[index - 1].y };
        index++;
    }
    while (index >= 11 && index <= 12)
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y-yOffSet };
        index++;
    }
    while (index >= 13 && index <= 17)
    {
        boardPlc[index] = { boardPlc[index - 1].x + xOffSet,boardPlc[index - 1].y };
        index++;
    }
    if (index == 18)
    {
        boardPlc[index] = { boardPlc[index - 1].x + xOffSet,boardPlc[index - 1].y - yOffSet };
        index++;
    }
    while (index >= 19 && index <= 23)
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y-yOffSet };
        index++;
    }
    while (index >= 24 && index <= 25)
    {
        boardPlc[index] = { boardPlc[index - 1].x+xOffSet,boardPlc[index - 1].y };
        index++;
    }
    while (index >= 26 && index <= 30)
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y+yOffSet };
        index++;
    }
    if (index == 31)
    {
        boardPlc[index] = { boardPlc[index - 1].x + xOffSet,boardPlc[index - 1].y + yOffSet };
        index++;
    }
    while (index >= 32 && index <= 36)
    {
        boardPlc[index] = { boardPlc[index - 1].x+xOffSet,boardPlc[index - 1].y};
        index++;
    }
    if (index == 37)
    {
        boardPlc[index] = { boardPlc[index - 1].x + xOffSet,boardPlc[index - 1].y - yOffSet };
        index++;
    }
    while (index >= 38 && index <= 42)
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y-yOffSet };
        index++;
    }
    while (index >= 43 && index <= 44)
    {
        boardPlc[index] = { boardPlc[index - 1].x+xOffSet,boardPlc[index - 1].y };
        index++;
    }
    while (index >= 45 && index <= 49)
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y+yOffSet};
        index++;
    }
    if (index == 50)
    {
        boardPlc[index] = { boardPlc[index - 1].x + xOffSet,boardPlc[index - 1].y + yOffSet };
        index++;
    }
    while (index >= 51 && index <= 55)
    {
        boardPlc[index] = { boardPlc[index - 1].x+xOffSet,boardPlc[index - 1].y};
        index++;
    }
    while (index >= 56 && index <= 57)
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y+yOffSet };
        index++;
    }
    while (index >= 58 && index <= 62)
    {
        boardPlc[index] = { boardPlc[index - 1].x-xOffSet,boardPlc[index - 1].y};
        index++;
    }
    if (index == 63)
    {
        boardPlc[index] = { boardPlc[index - 1].x - xOffSet,boardPlc[index - 1].y + yOffSet };
        index++;
    }
    while (index >= 64 && index <= 68)
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y+yOffSet };
        index++;
    }
    while (index >= 69 && index <=70)
    {
        boardPlc[index] = { boardPlc[index - 1].x-xOffSet,boardPlc[index - 1].y};
        index++;
    }
    while (index >= 71 && index <= 75)
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y-yOffSet };
        index++;
    }
    if (index == 76)
    {
        boardPlc[index] = { boardPlc[index - 1].x - xOffSet,boardPlc[index - 1].y - yOffSet };
        index++;
    }
    while (index >= 77 && index <= 81)
    {
        boardPlc[index] = { boardPlc[index - 1].x-xOffSet,boardPlc[index - 1].y };
        index++;
    }
    if (index == 82)
    {
        boardPlc[index] = { boardPlc[index - 1].x - xOffSet,boardPlc[index - 1].y + yOffSet };
        index++;
    }
    while (index >= 83 && index <= 87)
    {
        boardPlc[index] = { boardPlc[index - 1].x,boardPlc[index - 1].y+ yOffSet };
        index++;
    }
    while (index >= 88 && index <= 89)
    {
        boardPlc[index] = { boardPlc[index - 1].x-xOffSet,boardPlc[index - 1].y};
        index++;
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
