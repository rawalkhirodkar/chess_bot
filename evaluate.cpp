#include "board.h"
int Board:: evaluate_pawn(piece * asserted[12][12])
{
        int blackpawn[8];
        int whitepawn[8];
        for(int i=0;i<8;i++)
        {
                blackpawn[i]=whitepawn[i]=0;
        }
        int sum=0;
        for(int i=2;i<10;i++)
        {
                for(int j=2;j<10;j++)
                {
                        if(asserted[i][j]!=NULL && asserted[i][j]->piecename==mypieces::pawn)
                        {

                                if(asserted[i][j]->type()==0)
                                {
                                        blackpawn[i-2]++;
                                        sum=sum-asserted[i][j]->pieceval()-PawnTable[9-i][9-j];
                                }
                                else
                                {
                                        whitepawn[i-2]++;
                                        sum=sum+asserted[i][j]->pieceval()+PawnTable[i-2][j-2];
                                }
                        }
                }
        }
        for(int i=0;i<8;i++)
        {
                if(whitepawn[i]>1)
                {
                        sum=sum-(whitepawn[i]*10);
                }
                if(blackpawn[i]>1)
                {
                        sum=sum+(blackpawn[i]*10);
                }
        }
        return sum;
}
int Board:: evaluate_bishop(piece * asserted[12][12])
{
        int blackbishop=0;
        int whitebishop=0;
        int sum=0;
        for(int i=2;i<10 ;i++)
        {
                for(int j=2;j<10;j++)
                {
                        if(asserted[i][j]!=NULL && asserted[i][j]->piecename==mypieces::bishop)
                        {
                                if(asserted[i][j]->type()==0)
                                {
                                        blackbishop++;
                                        sum=sum-asserted[i][j]->pieceval()-BishopTable[9-i][9-j];
                                }
                                else
                                {
                                        whitebishop++;
                                        sum=sum+asserted[i][j]->pieceval()+BishopTable[i-2][j-2];
                                }
                        }
                }
        }
        if(blackbishop==2)
        {
                sum=sum-15;
                if(endreached)
                {
                        sum=sum-15;
                }
        }
        if(whitebishop==2)
        {
                sum=sum+15;
                if(endreached)
                {
                        sum=sum+15;
                }

        }
        return sum;
}
int Board:: evaluate_knight(piece * asserted[12][12])
{
        int sum=0;
        for(int i=2;i<10;i++)
        {
                for(int j=2;j<10;j++)
                {
                        if(asserted[i][j]!=NULL && asserted[i][j]->piecename==mypieces::knight)
                        {
                                if(asserted[i][j]->type()==0)
                                {
                                        sum=sum-asserted[i][j]->pieceval()-KnightTable[9-i][9-j];
                                }
                                else
                                {
                                        sum=sum+asserted[i][j]->pieceval()+KnightTable[i-2][j-2];
                                }
                        }
                }
        }

        return sum;
}
int Board:: evaluate_rook(piece * asserted[12][12])
{
        int sum=0;
        for(int i=2;i<10;i++)
        {
                for(int j=2;j<10;j++)
                {
                        if(asserted[i][j]!=NULL && asserted[i][j]->piecename==mypieces::rook)
                        {
                                if(asserted[i][j]->type()==0)
                                {
                                        sum=sum-asserted[i][j]->pieceval()-RookTable[9-i][9-j];
                                }
                                else
                                {
                                        sum=sum+asserted[i][j]->pieceval()+RookTable[i-2][j-2];
                                }
                        }
                }
        }

        return sum;
}
int Board:: evaluate_queen(piece * asserted[12][12])
{
        int sum=0;
        for(int i=2;i<10;i++)
        {
                for(int j=2;j<10;j++)
                {
                        if(asserted[i][j]!=NULL && asserted[i][j]->piecename==mypieces::queen)
                        {
                                if(asserted[i][j]->type()==0)
                                {
                                        sum=sum-asserted[i][j]->pieceval()-QueenTable[9-i][9-j];
                                }
                                else
                                {
                                        sum=sum+asserted[i][j]->pieceval()+QueenTable[9-i][j-2];
                                }
                        }
                }
        }

        return sum;
}
int Board:: evaluate_king(piece * asserted[12][12])
{
        int sum=0;
        for(int i=2;i<10;i++)
        {
                for(int j=2;j<10;j++)
                {
                        if(asserted[i][j]!=NULL && asserted[i][j]->piecename==mypieces::king)
                        {
                                if(asserted[i][j]->type()==0 && endreached==0)
                                {
                                        sum=sum-KingMiddleTable[9-i][9-j];
                                }
                                else if(asserted[i][j]->type()==1 && endreached==0)
                                {
                                        sum=sum+KingMiddleTable[9-i][j-2];
                                }
                                else if(asserted[i][j]->type()==0 && endreached==1)
                                {
                                        sum=sum-KingEndTable[9-i][9-j];
                                }
                                else if(asserted[i][j]->type()==1 && endreached==1)
                                {
                                        sum=sum+KingEndTable[9-i][j-2];
                                }
                        }
                }
        }

        return sum;
}


int Board:: evaluate(piece * asserted[12][12])
{
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(asserted[i][j]!=NULL)
			{
				asserted[i][j]->defendedby=0;
				asserted[i][j]->attackedby=0;
				asserted[i][j]->movesavailable=0;
			}
		}
	}
	int pse[12][12];
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(asserted[i][j]!=NULL)
			{
				asserted[i][j]->availablemoves(asserted,pse);
			}
		}
	}
	int x=0;
	piece* save;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(asserted[i][j]!=NULL)
			{
				save=asserted[i][j];
				if(save->type()==0)
				{
					x=x-save->movesavailable;
					x=x-save->defendedby;
					x=x+save->attackedby;
					if(save->defendedby<save->attackedby)
					{
						x=x+(save->attackedby-save->defendedby)*10;
					}
				}
				else if(asserted[i][j]->type()==1)
				{
					x=x+save->movesavailable;
					x=x+save->defendedby;
					x=x-save->attackedby;
					if(save->defendedby<save->attackedby)
					{
						x=x-(save->attackedby-save->defendedby)*10;
					}
				}
			}
		}
	}
	if(blackcastled){x=x-25;}
	if(whitecastled){x=x+25;}
	x= x+ evaluate_bishop(asserted)+evaluate_king(asserted)+evaluate_queen(asserted)+evaluate_rook(asserted)+
	evaluate_pawn(asserted)+evaluate_knight(asserted);
	return x;
}
