#ifndef _UTILITY
#define _UTILITY

#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include<Windows.h>
using namespace std;

enum colorType { Red, Green, Blue, Yellow,Purple,Orange };

enum positionType { Normal, Star, Home };

struct placement
{
	float x;
	float y;
};

#endif
