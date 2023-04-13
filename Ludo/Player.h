#ifndef _PLAYER
#define _PLAYER

#include "utility.h"

class Player 
{
	//static helpers:
	static void assignKeyAndHome(Player&, const colorType);
	//attributes
	playerKeyPoints pK;
	colorType plC;
	vector<int> myHome;
public:
	Player(const colorType);
	colorType getPlayerColor()const;
	const vector<int>& getPlayerHome()const;
	int getPlayerKey(const keys)const;
	bool isMyPiece(const colorType)const;
};

#endif

