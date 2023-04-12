#ifndef _UTILITY
#define _UTILITY

#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include <cassert>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void __sleep(unsigned int);

enum colorType { Red, Green, Blue, Yellow,Purple,Orange };

enum positionType { Normal, Star, Home , Death };

struct placement
{
	float x;
	float y;
};

struct playerKeyPoints
{
	int myStart;
	int myEnd;
	int myPathToVic;
	int vicDoor;
};

#endif
