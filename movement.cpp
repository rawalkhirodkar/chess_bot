
#include "board.h"
void Board:: moveto(piece* mydatapoints[12][12],int inx,int iny,int fix,int fiy) {
	mydatapoints[fix][fiy]=mydatapoints[inx][iny];
	mydatapoints[inx][iny]=NULL;
	mydatapoints[fix][fiy]->xpos=fix;
	mydatapoints[fix][fiy]->ypos=fiy;
}



void Board::selectpiece(int x,int y,piece* mydatapoints[12][12],int movable_top[12][12])
{
	int a,b;
	a=(int) x/tilesize;
	b=(int) y/tilesize;
	if(a>1 && a<10 && b>1 && b<10 )
	{
		if(mydatapoints[a][b]!=NULL && (mydatapoints[a][b]->activity()==1))
		{
			this->currentx=a;
			this->currenty=b;
			this->state=1;
			mydatapoints[this->currentx][this->currenty]->availablemoves(mydatapoints,movable_top);
			return;
		}
	}
}
int Board::getclicksandmove(int currx,int curry,int x,int y,piece* mydatapoints[12][12],int movable_top[12][12])
{
	bool enpassent=false;
	bool pawnpromotion=false;
	piece* pseudo;
	int a,b;
	a=(int) x/tilesize;
	b=(int) y/tilesize;
	if(mydatapoints[a][b]==NULL)
	{
	}
	if(mydatapoints[currx][curry]!=NULL)
	{
		mydatapoints[currx][curry]->availablemoves(mydatapoints,movable_top);
	}
	if(mydatapoints[a][b]!=NULL && (mydatapoints[a][b]->activity()==1))
	{
		selectpiece(x,y,mydatapoints,movable_top);
		return 0;
	}
	else if(movable_top[a][b]!=0)
	{
		pseudo=mydatapoints[a][b];
		moveto(mydatapoints,currx,curry,a,b);
		if(movable_top[a][b]==2)
		{
			enpassent=true;
		}
		else if(movable_top[a][b]==3)
		{
			pawnpromotion=true;
		}
		else if(movable_top[a][b]==6)
		{
						datapoints[9][9]->moved();
			moveto(mydatapoints,9,9,7,9);

			whitecastled=true;
			this->state=0;
			return 6;
		}
		else if(movable_top[a][b]==7)
		{
			datapoints[2][9]->moved();
			moveto(mydatapoints,2,9,5,9);
			
			whitecastled=true;
			this->state=0;
			return 7;
		}
		else if(movable_top[a][b]==8)
		{
						datapoints[9][2]->moved();
			moveto(mydatapoints,9,2,7,2);

			blackcastled=true;
			this->state=0;
			return 8;
		}
		else if(movable_top[a][b]==9)
		{
			datapoints[2][2]->moved();
			
			moveto(mydatapoints,2,2,5,2);
			
			blackcastled=true;
			this->state=0;
			return 9;
		}
		
		if(mydatapoints[a][b]->type()==0)
		{
			if(blackincheck(mydatapoints))
			{
			moveto(mydatapoints,a,b,currx,curry);
			mydatapoints[a][b]=pseudo;
			this->state=1;
			return 0;
			}
		}
		else if(mydatapoints[a][b]->type()==1)
		{
			if(whiteincheck(mydatapoints))
			{
			moveto(mydatapoints,a,b,currx,curry);
			mydatapoints[a][b]=pseudo;
			this->state=1;
			return 0;
			}
		}
		if(enpassent)
		{
			if(mydatapoints[a][b]->type()==0)
			{
				mydatapoints[a][b-1]=NULL;
			}
			else
			{
				mydatapoints[a][b+1]=NULL;
			}
		}
		else if(pawnpromotion)
		{
			mydatapoints[a][b]=new Queen(a,b,mydatapoints[a][b]->type());
			mydatapoints[a][b]->active=1;
		}
		this->state=0;
		return 1;
	}
		return 0;
}
	 
void Board:: changeplayertoblack(piece* mydatapoints[12][12])
{
	for(int i=2;i<=9;i++)
	{
		for(int j=2;j<=9;j++)
		{
			if(mydatapoints[i][j]!=NULL)
			{
				if(mydatapoints[i][j]->active==mydatapoints[i][j]->type())
			{
				mydatapoints[i][j]->flipactivity();
			}
			}
		}
	}
}
void Board:: changeplayertowhite(piece* mydatapoints[12][12])
{
	for(int i=2;i<=9;i++)
	{
		for(int j=2;j<=9;j++)
		{
			if(mydatapoints[i][j]!=NULL)
			{
				if(mydatapoints[i][j]->active!=mydatapoints[i][j]->type())
			{
				mydatapoints[i][j]->flipactivity();
			}
			}
		}
	}
}



void Board::copy(piece* a[12][12],piece* b[12][12])
{
	
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(a[i][j]!=NULL)
			{
				a[i][j]->xpos=i;
				a[i][j]->ypos=j;
			}
			b[i][j]=a[i][j];
		}
	}
}


