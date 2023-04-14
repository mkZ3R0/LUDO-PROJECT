#pragma once
#include "utility.h"
#include "Ludo.h"

class Dice
{
	int roll;
	static void loadDice();
	static void calculateDicePlc();
	static vector<placement>boardDicePlc;
public:
	static sf::Texture one;
	static sf::Texture two;
	static sf::Texture three;
	static sf::Texture four;
	static sf::Texture five;
	static sf::Texture six;
	Dice();
	int rollDice();
	int giveSix();//cheat;
	int cheatRoll(sf::RenderWindow&);//cheat;
	void rollingDice(const vector<int>&,const int);//for animation
	void displayRoll(sf::RenderWindow&,const int,const int)const;
};

