#include "rook.h"


Rook :: Rook(int x,int y,bool color) {
	this->bow=color;
	this->active=color;
	this->xpos=x;
	this->ypos=y;
	this->piecename=mypieces::rook;
	timesmoved=0;
	piecevalue=500;
}
void Rook :: availablemoves(piece * datapoints[12][12],int movable_to[12][12])
{
	attacks=0;
	defends=0;
	movesavailable=0;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			movable_to[i][j]=0;
		}
	}
	genmove(datapoints,movable_to,1,0);
	genmove(datapoints,movable_to,0,-1);
	genmove(datapoints,movable_to,0,1);
	genmove(datapoints,movable_to,-1,0);
}
