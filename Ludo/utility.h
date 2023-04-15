#ifndef _UTILITY
#define _UTILITY

#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include <cassert>
#include <unordered_set>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void __sleep(unsigned int);

enum colorType { Orange, Green, Yellow, Purple, Red, Blue };

enum positionType { Normal, Star, Home , Death };

enum keys {_start, _end, _door, _victory};

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
