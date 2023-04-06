#include "Board.h"

Board::Board()
{
}


vector<placement> Board::boardPlc(90);
void Board::calculateBoardPlc()
{
    sf::Texture temp;
    if (!temp.loadFromFile("Assets/board6.png"))
    {
        cout << "cannot Load image";
    }
    int index = 1;
    float yOffSet =temp.getSize().y/15.0;
    float xOffSet = temp.getSize().x/24.0;
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
    sf::Texture temp;
    int index = 0;
    if (!temp.loadFromFile("Assets/board6.png"))  //  img ==> file name for image
    {
        cout << "cannot Load image";
    }
    sf::Sprite s(temp);
    s.setColor(sf::Color::White);
    s.setScale(1,1); //  (width and heigth of image to be printed)
    s.setPosition(0,0); // position of image
    window.draw(s);	// draw() will only draw image on backend, image will not display on screen
    //window.display();  // display() will show image on screen
}
placement Board::getBoardPlc(const int index)
{
    return boardPlc[index];
}
