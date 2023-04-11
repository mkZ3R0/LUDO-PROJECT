#pragma once
#include "utility.h"

class Dice
{
	int roll;
	static void loadDice();
public:
	static sf::Texture one;
	static sf::Texture two;
	static sf::Texture three;
	static sf::Texture four;
	static sf::Texture five;
	static sf::Texture six;
	Dice();
	int rollDice();
	void displayRoll(sf::RenderWindow&)const;
};

