#include "Board.h"

Board::Board()
{
}
void Board::displayBoard(sf::RenderWindow& window)
{
    sf::Texture temp;
    if (!temp.loadFromFile("Assets/board4.jpg"))  //  img ==> file name for image
    {
        cout << "cannot Load immage";
    }
    sf::Sprite s(temp);
    s.setColor(sf::Color::White);
    s.setScale(1.35,1.1); //  (width and heigth of image to be printed)

    s.setPosition(0,0); // position of image
    window.draw(s);	// draw() will only draw image on backend, image will not display on screen
    Piece p(Red);
    p.displayPiece(window);
    window.display();  // display() will show image on screen
}
