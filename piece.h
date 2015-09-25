#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

namespace mypieces
{
	enum mypieces{pawn,knight,rook,queen,king,bishop,boundary};
}

class piece {
	protected:
	bool bow;//Black or white.
	unsigned short int timesmoved;
	//1 means active and 0 is inactive;
	unsigned short int color;
	unsigned short int piecevalue;
	public:
	unsigned short int piecename;
	unsigned short int attacks;
	unsigned short int defends;
	unsigned short int attackedby;
	unsigned short int defendedby;
	unsigned short int movesavailable;
	unsigned short int xpos;
	unsigned short int ypos;
	bool active;
	bool type();	
	bool activity();
	void flipactivity();
	virtual void availablemoves(piece* a[12][12],int b[12][12])=0 ;
	void genmove(piece* datapoints[12][12],int movable_to[12][12],int x,int y);
	void moved();
	void unmoved();
	unsigned short int pieceval();
	unsigned short int moves();
	unsigned short int getxpos();
	unsigned short int getypos();
};

