#include "Dice.h"
#include "Board.h"
#include<iostream>
using namespace std;

//dice faces textures;
sf::Texture Dice::one;
sf::Texture Dice::two;
sf::Texture Dice::three;
sf::Texture Dice::four;
sf::Texture Dice::five;
sf::Texture Dice::six;

Dice::Dice()
	:roll(0)
{
    loadDice();
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
}

int Dice::rollDice()
{
	return roll=(rand() % 6) + 1;
}

void Dice::displayRoll(sf::RenderWindow& window)const
{
    sf::Sprite d;
    switch (roll) {
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
    d.setPosition(Board::boardBg.getSize().x*1.1,Board::boardBg.getSize().y*0.25);

    window.draw(d);
}



