#include "board.h"
bool Board ::whiteincheck(piece* mydatapoints[12][12]) {
	int x,y;
	int movable_top[12][12];
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			movable_top[i][j]=0;
		}
	}
	for(int i=2;i<=9;i++)
	{
		for(int j=2;j<=9;j++)
		{
			if(mydatapoints[i][j]!=NULL && mydatapoints[i][j]->piecename==mypieces:: king && mydatapoints[i][j]->type()==1)
			{
				x=i;
				y=j;
			}
		}
	}
	for(int i=2;i<=9;i++)
	{
		
		for(int j=2;j<=9;j++)
		{
			if(mydatapoints[i][j]!=NULL && mydatapoints[i][j]->type()==0)
			{
				mydatapoints[i][j]->availablemoves(mydatapoints,movable_top);
				if(movable_top[x][y]==1 || movable_top[x][y]==5 || movable_top[x][y]==3 || movable_top[x][y]==2)
				{
					return true;
					
				}
			}
		}
	}
	return false;
}

bool Board ::blackincheck(piece* mydatapoints[12][12]) {
	int x,y;
	int movable_top[12][12];
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			movable_top[i][j]=0;
		}
	}
	for(int i=2;i<=9;i++)
	{
		for(int j=2;j<=9;j++)
		{
			if(mydatapoints[i][j]!=NULL && mydatapoints[i][j]->piecename==mypieces:: king && mydatapoints[i][j]->type()==0)
			{
				x=i;
				y=j;
			}
		}
	}
	for(int i=2;i<=9;i++)
	{
		
		for(int j=2;j<=9;j++)
		{
			if(mydatapoints[i][j]!=NULL && mydatapoints[i][j]->type()==1)
			{
				mydatapoints[i][j]->availablemoves(mydatapoints,movable_top);
				if(movable_top[x][y]==1 || movable_top[x][y]==5 || movable_top[x][y]==3 || movable_top[x][y]==2)
				{
					return true;
				}
			}
		}
	}
	return false;
}
