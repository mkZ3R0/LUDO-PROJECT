#include "Board.h"

Board::Board()
{
}


vector<position> Board::boardPos(91);
void Board::calculateBoardPos()
{
    int index = 1;
    float yOffSet = 37.1;
    float xOffSet = 37.3;
    boardPos[0] = {242.4,503.4 };
    while (index > 0 && index <=4 )
    {
        boardPos[index] = { boardPos[index - 1].x,boardPos[index - 1].y - yOffSet };
        index++;
    }
    if (index == 5)
    {
        boardPos[index] = { boardPos[index - 1].x-xOffSet,boardPos[index - 1].y - yOffSet };
        index++;
    }
    while (index >= 6 && index <= 10)
    {
        boardPos[index] = { boardPos[index - 1].x-xOffSet,boardPos[index - 1].y };
        index++;
    }
    while (index >= 11 && index <= 12)
    {
        boardPos[index] = { boardPos[index - 1].x,boardPos[index - 1].y-yOffSet };
        index++;
    }
    while (index >= 13 && index <= 17)
    {
        boardPos[index] = { boardPos[index - 1].x + xOffSet,boardPos[index - 1].y };
        index++;
    }
    while (index >= 13 && index <= 17)
    {
        boardPos[index] = { boardPos[index - 1].x + xOffSet,boardPos[index - 1].y };
        index++;
    }
    if (index == 18)
    {
        boardPos[index] = { boardPos[index - 1].x + xOffSet,boardPos[index - 1].y - yOffSet };
        index++;
    }
    while (index >= 19 && index <= 23)
    {
        boardPos[index] = { boardPos[index - 1].x,boardPos[index - 1].y-yOffSet };
        index++;
    }
    while (index >= 24 && index <= 25)
    {
        boardPos[index] = { boardPos[index - 1].x,boardPos[index - 1].y - yOffSet };
        index++;
    }
}
void Board::displayBoard(sf::RenderWindow& window)
{
    sf::Texture temp;
    if (!temp.loadFromFile("Assets/board6.png"))  //  img ==> file name for image
    {
        cout << "cannot Load image";
    }
    sf::Sprite s(temp);
    s.setColor(sf::Color::White);
    s.setScale(1,1); //  (width and heigth of image to be printed)
    s.setPosition(0,0); // position of image
    window.draw(s);	// draw() will only draw image on backend, image will not display on screen
    Piece p(Red);
    p.displayPiece(window);
    window.display();  // display() will show image on screen
}
