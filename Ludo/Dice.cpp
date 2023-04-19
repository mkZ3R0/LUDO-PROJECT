#include "Dice.h"
#include "Board.h"
#include<iostream>
using namespace std;

// dice faces textures;
sf::Texture Dice::one;
sf::Texture Dice::two;
sf::Texture Dice::three;
sf::Texture Dice::four;
sf::Texture Dice::five;
sf::Texture Dice::six;
sf::SoundBuffer Dice::soundBuffer;


Dice::Dice()
	:roll(0)
{
    loadDice();
    calculateDicePlc();
}

void Dice::loadDice()
{
    if (!Dice::one.loadFromFile("Assets/1.png")) {
        cerr << "Cannot load 1.png" << endl;
        exit(1);
    }
    if (!Dice::two.loadFromFile("Assets/2.png")) {
        cerr << "Cannot load 2.png" << endl;
        exit(1);
    }
    if (!Dice::three.loadFromFile("Assets/3.png")) {
        cerr << "Cannot load 3.png" << endl;
        exit(1);
    }
    if (!Dice::four.loadFromFile("Assets/4.png")) {
        cerr << "Cannot load 4.png" << endl;
        exit(1);
    }
    if (!Dice::five.loadFromFile("Assets/5.png")) {
        cerr << "Cannot load 5.png" << endl;
        exit(1);
    }
    if (!Dice::six.loadFromFile("Assets/6.png")) {
        cerr << "Cannot load 6.png" << endl;
        exit(1);
    }
    if (!soundBuffer.loadFromFile("Assets/diceRoll.ogg"))
    {
        cerr << "Cannot load diceRoll.ogg" << endl;
        exit(1);
    }
}

int Dice::rollDice()
{
	return roll=(rand() % 6) + 1;
}

int Dice::cheatRoll(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.waitEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            exit(0);
            break;
        case sf::Event::KeyPressed:
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
                roll = 6;
                return roll;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                roll = 5;
                return roll;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                roll = 4;
                return roll;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                roll = 3;
                return roll;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                roll = 2;
                return roll;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                roll = 1;
                return roll;
            }
            break;
        }
        }
    }
    return 1; // compiler warning
}

int Dice::giveSix()
{
    roll = 6;
    return 6;
}

void Dice::displayRoll(sf::RenderWindow& window, const int rollNumber, const int myRoll,bool selected)const
{
    sf::Sprite d;
    switch (myRoll) {
    case 1:
        d.setTexture(one);
        break;
    case 2:
        d.setTexture(two);
        break;
    case 3:
        d.setTexture(three);
        break;
    case 4:
        d.setTexture(four);
        break;
    case 5:
        d.setTexture(five);
        break;
    case 6:
        d.setTexture(six);
        break;
    default:
        break;
    }
    auto _diceSize = static_cast<sf::Vector2f>(d.getTexture()->getSize());
    auto scaleFactor = std::min(Board::xOffSet / _diceSize.x, Board::yOffSet / _diceSize.y);
    if(selected)
        d.setColor(sf::Color(255, 255, 143));
    d.setOrigin(_diceSize.x / 2, _diceSize.y / 2);
    d.setScale(scaleFactor, scaleFactor);
    d.setPosition(boardDicePlc[rollNumber].x, boardDicePlc[rollNumber].y);

    window.draw(d);
}

vector<placement> Dice::boardDicePlc(3);
void Dice::calculateDicePlc()
{
    boardDicePlc[0] = { Board::boardPlc[79].x , Board::boardPlc[79].y - Board::yOffSet};
    for (int i = 1; i <= 2; i++)
        boardDicePlc[i] = { boardDicePlc[i-1].x + Board::xOffSet , boardDicePlc[i-1].y };
}

void Dice::rollingDice(sf::RenderWindow& window, const Board* myBoard, const vector<int>& myRolls, const int rollNumber, const Player* currentPlayer)
{
    sf::Sprite d;
    int random = 0;
    sf::Sound s;
    s.setBuffer(soundBuffer);
    s.play();
    __sleep(200);
    for (int i = 0; i < 5; i++)
    {
        random = (rand() % 6) + 1;
        switch (random) {
        case 1:
            d.setTexture(one);
            break;
        case 2:
            d.setTexture(two);
            break;
        case 3:
            d.setTexture(three);
            break;
        case 4:
            d.setTexture(four);
            break;
        case 5:
            d.setTexture(five);
            break;
        case 6:
            d.setTexture(six);
            break;
        default:
            break;
        }
        auto _diceSize = static_cast<sf::Vector2f>(d.getTexture()->getSize());
        auto scaleFactor = std::min(Board::xOffSet / _diceSize.x, Board::yOffSet / _diceSize.y);
        d.setOrigin(_diceSize.x / 2, _diceSize.y / 2);
        d.setScale(scaleFactor, scaleFactor);
        d.setPosition(boardDicePlc[rollNumber].x, boardDicePlc[rollNumber].y);
        myBoard->displayBoard(window, currentPlayer);
        Ludo::displayRolls(window, myRolls, this);
        window.draw(d);
        window.display();
        __sleep(100);
    }
}

