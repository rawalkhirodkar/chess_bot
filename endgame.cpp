#include "board.h"
bool Board:: nomovesforwhite(piece* mydatapoints[12][12])
{
	piece* pseudo;
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
			if(mydatapoints[i][j]!=NULL && mydatapoints[i][j]->type()==1 )
			{	
				for(int k=2;k<=9;k++)
				{
					for(int l=2;l<=9;l++)
					{
						mydatapoints[i][j]->availablemoves(mydatapoints,movable_top);
						if(movable_top[k][l]==1 || movable_top[k][l]==2 || movable_top[k][l]==3 || movable_top[k][l]==5)
						{
							pseudo=mydatapoints[k][l];
							moveto(mydatapoints,i,j,k,l);
							if(!whiteincheck(mydatapoints))
							{
								moveto(mydatapoints,k,l,i,j);
								mydatapoints[k][l]=pseudo;
								return false;
							}
							else
							{
								moveto(mydatapoints,k,l,i,j);
								mydatapoints[k][l]=pseudo;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
bool Board:: nomovesforblack(piece* mydatapoints[12][12])
{
	piece* pseudo;
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
			if(mydatapoints[i][j]!=NULL && mydatapoints[i][j]->type()==0 )
			{	
				for(int k=2;k<=9;k++)
				{
					for(int l=2;l<=9;l++)
					{
						mydatapoints[i][j]->availablemoves(mydatapoints,movable_top);
						if(movable_top[k][l]==1 || movable_top[k][l]==2 || movable_top[k][l]==3 || movable_top[k][l]==5)
						{
							pseudo=mydatapoints[k][l];
							moveto(mydatapoints,i,j,k,l);
							if(!blackincheck(mydatapoints))
							{
								moveto(mydatapoints,k,l,i,j);
								mydatapoints[k][l]=pseudo;
								return false;
							}
							else
							{
								moveto(mydatapoints,k,l,i,j);
								mydatapoints[k][l]=pseudo;
							}
						}
					}
				}
			}
		}
	}
	return true;
}

bool Board::stalemateblack(piece* move1[12][12])
{
	if(!blackincheck(move1))
	{
		if(nomovesforblack(move1))
		{
			return true;
		}
	}
	return false;
}
bool Board::stalematewhite(piece* move1[12][12])
{
	if(!whiteincheck(move1))
	{
		if(nomovesforwhite(move1))
		{
			return true;
		}
	}
	return false;
}

bool Board::checkmateblack(piece* move1[12][12])
{
	if(blackincheck(move1))
	{
		if(nomovesforblack(move1))
		{
			return true;
		}
	}
	return false;
}
bool Board::checkmatewhite(piece* move1[12][12])
{
	if(whiteincheck(move1))
	{
		if(nomovesforwhite(move1))
		{
			return true;
		}
	}
	return false;
}


