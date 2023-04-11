#include "Dice.h"
#include<iostream>
using namespace std;

Dice::Dice()
	:roll(0)
{}
int Dice::rollDice()const
{
	return (rand() % 6) + 1;
}
