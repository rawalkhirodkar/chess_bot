#include "king.h"


King :: King(int x,int y,bool color) {
	this->bow=color;
	this->active=color;
	this->xpos=x;
	this->ypos=y;
	this->piecename=mypieces::king;
	timesmoved=0;
	piecevalue=20000;
}
bool King::check(piece* datapoints[12][12],int x,int y)
{
	piece* pdatapoints[12][12];
	int movable_top[12][12];
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			pdatapoints[i][j]=datapoints[i][j];
			movable_top[i][j]=0;
		}
	}
	for(int i=2;i<=9;i++)
	{
		
		for(int j=2;j<=9;j++)
		{
			if(pdatapoints[i][j]!=NULL && pdatapoints[i][j]->activity()==0 && pdatapoints[i][j]->piecename!=mypieces::king)
			{
				pdatapoints[i][j]->availablemoves(pdatapoints,movable_top);
				if(movable_top[x][y]==1 ||movable_top[x][y]==3 || movable_top[x][y]==5 )
				{
					return true;
				}
			}
		}
	}
	return false;
}
void King:: availablemoves(piece * datapoints[12][12],int movable_to[12][12])
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
	for(int i=-1;i<2;i++)
	{
		for(int j=-1;j<2;j++)
		{
			if(i!=0 || j!=0)
			{
				if(datapoints[xpos+i][ypos+j]==NULL)
				{
					movable_to[xpos+i][ypos+j]=1;
					movesavailable++;
				}
				else if(datapoints[xpos+i][ypos+j]->piecename==mypieces::boundary)
				{
					continue;
				}
				else if(datapoints[xpos+i][ypos+j]->type()!=this->type())
				{
					movable_to[xpos+i][ypos+j]=5;attacks++;datapoints[xpos+i][ypos+j]->attackedby++;
					movesavailable++;
				}
				else if(datapoints[xpos+i][ypos+j]->type()==this->type())
				{
					movable_to[xpos+i][ypos+j]=4;defends++;datapoints[xpos+i][ypos+j]->defendedby++;
				}
			}
		}
	}
	if(this->moves()==0)
	{
		if(this->type()==1)
		{
			if(datapoints[9][9]!=NULL && datapoints[9][9]->piecename==mypieces::rook && this->xpos==6 && this->ypos==9 && datapoints[9][9]->moves()==0 && datapoints[9][9]->type()==1)
			{
				if(datapoints[8][9]==NULL && datapoints[7][9]==NULL)
				{
					if(!check(datapoints,6,9)&&!check(datapoints,8,9)&& !check(datapoints,7,9))
					{
						movable_to[8][9]=6;
						movesavailable++;
					}
				}
			}
			if(datapoints[2][9]!=NULL && datapoints[2][9]->piecename==mypieces::rook && this->xpos==6 && this->ypos==9 && datapoints[2][9]->moves()==0 && datapoints[2][9]->type()==1)
			{
				if(datapoints[3][9]==NULL && datapoints[4][9]==NULL && datapoints[5][9]==NULL)
				{
					if(!check(datapoints,6,9)&&!check(datapoints,3,9)&&!check(datapoints,4,9) &&!check(datapoints,5,9))
					{
						movable_to[4][9]=7;
						movesavailable++;
					}
				}
			}
			
		}
		else
		{
			if(datapoints[9][2]!=NULL && datapoints[9][2]->piecename==mypieces::rook && this->xpos==6 && this->ypos==2  && datapoints[9][2]->moves()==0 && datapoints[9][2]->type()==0)
			{
				if(datapoints[8][2]==NULL && datapoints[7][2]==NULL)
				{
					if(!check(datapoints,6,2)&&!check(datapoints,8,2)&&!check(datapoints,7,2))
					{
						movable_to[8][2]=8;
						movesavailable++;
					}
				}
			}
			if(datapoints[2][2]!=NULL && datapoints[2][2]->piecename==mypieces::rook && this->xpos==6 && this->ypos==2 && datapoints[2][2]->moves()==0 && datapoints[2][2]->type()==0)
			{
				if(datapoints[3][2]==NULL && datapoints[4][2]==NULL && datapoints[5][2]==NULL)
				{
					if(!check(datapoints,6,2)&&!check(datapoints,3,2)&&!check(datapoints,4,2)&&!check(datapoints,5,2))
					{
						movable_to[4][2]=9;
						movesavailable++;
					}
				}
			}
		}
	}
}
