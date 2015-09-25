#include "knight.h"


Knight :: Knight(int x,int y,bool color) {
	this->bow=color;
	this->active=color;
	this->xpos=x;
	this->ypos=y;
	this->piecename=mypieces::knight;
	timesmoved=0;
	piecevalue=320;
}
int Knight::movable(piece*datapoints[12][12],int x,int y)
{
	if(datapoints[xpos+x][ypos+y]==NULL)
	{
		movesavailable++;
		return 1;
	}
	else if (datapoints[xpos+x][ypos+y]!=NULL && datapoints[xpos+x][ypos+y]->piecename!=mypieces::boundary && datapoints[xpos+x][ypos+y]->type()!=this->type())
	{
		movesavailable++;attacks++;datapoints[xpos+x][ypos+y]->attackedby++;
		return 5;
	}
	else if (datapoints[xpos+x][ypos+y]!=NULL && datapoints[xpos+x][ypos+y]->piecename!=mypieces::boundary && datapoints[xpos+x][ypos+y]->type()==this->type())
	{
		defends++;datapoints[xpos+x][ypos+y]->defendedby++;
		return 4;
	}
	return 0;
}
void Knight:: availablemoves(piece * datapoints[12][12],int movable_to[12][12])
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
	movable_to[xpos+2][ypos+1]=movable(datapoints,2,1);
	movable_to[xpos+2][ypos-1]=movable(datapoints,2,-1);
	movable_to[xpos-2][ypos-1]=movable(datapoints,-2,-1);
	movable_to[xpos-2][ypos+1]=movable(datapoints,-2,1);
	movable_to[xpos+1][ypos+2]=movable(datapoints,1,2);
	movable_to[xpos+1][ypos-2]=movable(datapoints,1,-2);
	movable_to[xpos-1][ypos-2]=movable(datapoints,-1,-2);
	movable_to[xpos-1][ypos+2]=movable(datapoints,-1,2);
}
