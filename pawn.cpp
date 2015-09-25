#include "pawn.h"


Pawn :: Pawn(int x,int y,bool color) {
	this->bow=color;
	this->active=color;
	this->xpos=x;
	this->ypos=y;
	this->piecename=mypieces::pawn;
	timesmoved=0;
	piecevalue=100;
}

void Pawn :: availablemoves(piece* datapoints[12][12],int movable_to[12][12])
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
	if(this->type()==1)
	{
		if(this->moves()==0)
		{
			if(datapoints[xpos][ypos-2]==NULL && datapoints[xpos][ypos-1]==NULL)
			{
				movable_to[xpos][ypos-2]=1;
				movesavailable++;
			}
		}
		if(datapoints[xpos][ypos-1]==NULL)
		{
			movable_to[xpos][ypos-1]=1;
			movesavailable++;
		}
		if(datapoints[xpos-1][ypos-1]!=NULL && datapoints[xpos-1][ypos-1]->piecename!=mypieces::boundary  && datapoints[xpos-1][ypos-1]->type()==0)
		{
			movable_to[xpos-1][ypos-1]=5;
			attacks++;
			datapoints[xpos-1][ypos-1]->attackedby++;
			movesavailable++;
		}
		if(datapoints[xpos+1][ypos-1]!=NULL && datapoints[xpos+1][ypos-1]->piecename!=mypieces::boundary && datapoints[xpos+1][ypos-1]->type()==0)
		{
			movable_to[xpos+1][ypos-1]=5;
			attacks++;
			datapoints[xpos+1][ypos-1]->attackedby++;
			movesavailable++;
		}
		if(datapoints[xpos-1][ypos-1]!=NULL && datapoints[xpos-1][ypos-1]->piecename!=mypieces::boundary  && datapoints[xpos-1][ypos-1]->type()==1)
		{
			movable_to[xpos-1][ypos-1]=4;
			defends++;
			datapoints[xpos-1][ypos-1]->defendedby++;
		}
		if(datapoints[xpos+1][ypos-1]!=NULL && datapoints[xpos+1][ypos-1]->piecename!=mypieces::boundary && datapoints[xpos+1][ypos-1]->type()==1)
		{
			movable_to[xpos+1][ypos-1]=4;
			defends++;
			datapoints[xpos+1][ypos-1]->defendedby++;
		}
		if(datapoints[xpos-1][ypos]!=NULL && datapoints[xpos-1][ypos]->piecename==mypieces::pawn && datapoints[xpos-1][ypos]->moves()==1 
		&& datapoints[xpos-1][ypos]->type()==0 && ypos==5)
		{
			movable_to[xpos-1][ypos-1]=2;
			attacks++;
			movesavailable++;
			datapoints[xpos-1][ypos]->attackedby++;
			
		}
		if(datapoints[xpos+1][ypos]!=NULL && datapoints[xpos+1][ypos]->piecename==mypieces::pawn && datapoints[xpos+1][ypos]->moves()==1
		&& datapoints[xpos+1][ypos]->type()==0 && ypos==5)
		{
			movable_to[xpos+1][ypos-1]=2;
			attacks++;
			movesavailable++;
			datapoints[xpos+1][ypos]->attackedby++;
		}
		for(int i=2;i<10;i++)
		{
			if(movable_to[i][2]==1 ||movable_to[i][2]==5)
			{
				movable_to[i][2]=3;
			}
		}
	}
	if(this->type()==0)
	{
		if(this->moves()==0)
		{
			if(datapoints[xpos][ypos+2]==NULL && datapoints[xpos][ypos+1]==NULL)
			{
				movable_to[xpos][ypos+2]=1;
				movesavailable++;
			}
		}
		if(datapoints[xpos][ypos+1]==NULL)
		{
			movable_to[xpos][ypos+1]=1;
			movesavailable++;
		}
		if(datapoints[xpos+1][ypos+1]!=NULL && datapoints[xpos+1][ypos+1]->piecename!=mypieces::boundary  && datapoints[xpos+1][ypos+1]->type()==1)
		{
			movable_to[xpos+1][ypos+1]=5;
			attacks++;
			datapoints[xpos+1][ypos+1]->attackedby++;
			movesavailable++;
		}
		if(datapoints[xpos-1][ypos+1]!=NULL && datapoints[xpos-1][ypos+1]->piecename!=mypieces::boundary && datapoints[xpos-1][ypos+1]->type()==1)
		{
			movable_to[xpos-1][ypos+1]=5;
			attacks++;
			datapoints[xpos-1][ypos+1]->attackedby++;
			movesavailable++;
		}
		if(datapoints[xpos+1][ypos+1]!=NULL && datapoints[xpos+1][ypos+1]->piecename!=mypieces::boundary  && datapoints[xpos+1][ypos+1]->type()==0)
		{
			movable_to[xpos+1][ypos+1]=4;
			defends++;
			datapoints[xpos+1][ypos+1]->defendedby++;
		}
		if(datapoints[xpos-1][ypos+1]!=NULL && datapoints[xpos-1][ypos+1]->piecename!=mypieces::boundary && datapoints[xpos-1][ypos+1]->type()==0)
		{
			movable_to[xpos-1][ypos+1]=4;
			defends++;
			datapoints[xpos-1][ypos+1]->defendedby++;
		}
		if(datapoints[xpos-1][ypos]!=NULL && datapoints[xpos-1][ypos]->piecename==mypieces::pawn && datapoints[xpos-1][ypos]->moves()==1 
		&& datapoints[xpos-1][ypos]->type()==1 && ypos==6)
		{
			movable_to[xpos-1][ypos+1]=2;
			attacks++;
			movesavailable++;
			datapoints[xpos-1][ypos]->attackedby++;
		}
		if(datapoints[xpos+1][ypos]!=NULL && datapoints[xpos+1][ypos]->piecename==mypieces::pawn && datapoints[xpos+1][ypos]->moves()==1
		&& datapoints[xpos+1][ypos]->type()==1 && ypos==6)
		{
			movable_to[xpos+1][ypos+1]=2;
			attacks++;
			movesavailable++;
			datapoints[xpos+1][ypos]->attackedby++;
		}
		for(int i=2;i<10;i++)
		{
			if(movable_to[i][9]==1||movable_to[i][9]==5)
			{
				movable_to[i][9]=3;
			}
		}
	}
	
}
