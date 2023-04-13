#include "Player.h"

void Player::assignKeyAndHome(Player& p, const colorType cl)
{
	switch (cl)
	{
		case Purple:
		{
			p.pK.myStart = 0 ;
			p.pK.myEnd = 95 ;
			p.pK.myPathToVic = 88;
			p.pK.vicDoor = 90;
			for (int i = 126; i <= 129; i++)
				p.myHome.push_back(i);
			return;
		}
		case Orange:
		{
			p.pK.myStart = 13;
			p.pK.myEnd = 101;
			p.pK.myPathToVic = 11;
			p.pK.vicDoor = 96;
			for (int i = 130; i <= 133; i++)
				p.myHome.push_back(i);
			return;
		}
		case Green:
		{
			p.pK.myStart = 26;
			p.pK.myEnd = 107;
			p.pK.myPathToVic = 24;
			p.pK.vicDoor = 102;
			for (int i = 134; i <= 137; i++)
				p.myHome.push_back(i);
			return;
		}
		case Yellow:
		{
			p.pK.myStart = 45;
			p.pK.myEnd = 113;
			p.pK.myPathToVic = 43;
			p.pK.vicDoor = 108;
			for (int i = 138; i <= 141; i++)
				p.myHome.push_back(i);
			return;
		}
		case Blue:
		{
			p.pK.myStart = 58;
			p.pK.myEnd = 119;
			p.pK.myPathToVic = 56;
			p.pK.vicDoor = 114;
			for (int i = 142; i <= 145; i++)
				p.myHome.push_back(i);
			return;
		}
		case Red:
		{
			p.pK.myStart = 71;
			p.pK.myEnd = 125;
			p.pK.myPathToVic = 69;
			p.pK.vicDoor = 120;
			for (int i = 146; i <= 149; i++)
				p.myHome.push_back(i);
			return;
		}
	}
}

Player::Player(const colorType pl_Color)
	:plC(pl_Color)
{
	assignKeyAndHome(*this, pl_Color);
}

colorType Player::getPlayerColor()const
{
	return this->plC;
}

const vector<int>& Player::getPlayerHome()const
{
	return this->myHome;// returns shallow copy;
}

int Player::getPlayerKey(const keys c)const
{
	switch (c)
	{
		case _start:
		{
			return this->pK.myStart;
		}
		case _end:
		{
			return this->pK.myEnd;
		}
		case _door:
		{
			return this->pK.vicDoor;
		}
		case _victory:
		{
			return this->pK.myPathToVic;
		}
	}
	return -1; // compiler warning
}

bool Player::isMyPiece(const colorType pieceColor)const
{
	return (this->plC == pieceColor);
}