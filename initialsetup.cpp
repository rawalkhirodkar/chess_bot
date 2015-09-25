#inlcude "board.h"
	Board :: Board(int bx, int by, int bw, int bh, int c): Fl_Widget (bx,by,bw,bh) { 
	this->bx = bx; this->by = by; this->bw = bw; this->bh = bh; color =c;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			datapoints[i][j]=NULL;
			movable_to[i][j]=0;
		}
	}
	
	datapoints[2][2]=new Rook(2,2,0);
	datapoints[3][2]=new Knight(3,2,0);
	datapoints[4][2]=new Bishop(4,2,0);
	datapoints[5][2]=new Queen(5,2,0);
	datapoints[6][2]=new King(6,2,0);
	datapoints[7][2]=new Bishop(7,2,0);
	datapoints[8][2]=new Knight(8,2,0);
	datapoints[9][2]=new Rook(9,2,0);
	
	datapoints[2][9]=new Rook(2,9,1);
	datapoints[3][9]=new Knight(3,9,1);
	datapoints[4][9]=new Bishop(4,9,1);
	datapoints[5][9]=new Queen(5,9,1);
	datapoints[6][9]=new King(6,9,1);
	datapoints[7][9]=new Bishop(7,9,1);
	datapoints[8][9]=new Knight(8,9,1);
	datapoints[9][9]=new Rook(9,9,1);
	
	for(int i=0;i<8;i++)
	{
		datapoints[i+2][8]=new Pawn(i+2,8,1);
		datapoints[i+2][3]=new Pawn(i+2,3,0);
	}
	
	for(int i=0;i<12;i++)
	{
		datapoints[i][0]=new boundarypiece();
		datapoints[i][1]=new boundarypiece();
		datapoints[i][10]=new boundarypiece();
		datapoints[i][11]=new boundarypiece();
	}
	for(int i=0;i<12;i++)
	{
		datapoints[0][i]=new boundarypiece();
		datapoints[1][i]=new boundarypiece();
		datapoints[10][i]=new boundarypiece();
		datapoints[11][i]=new boundarypiece();
	}
	state=0;
	inix=iniy=finx=finy=0;
	int pawn[64]={0,  0,  0,  0,  0,  0,  0,  0,
				50, 50, 50, 50, 50, 50, 50, 50,
				10, 10, 20, 30, 30, 20, 10, 10,
				 5,  5, 10, 25, 25, 10,  5,  5,
				 0,  0,  0, 20, 20,  0,  0,  0,
				 5, -5,-10,  0,  0,-10, -5,  5,
				 5, 10, 10,-20,-20, 10, 10,  5,
				 0,  0,  0,  0,  0,  0,  0,  0};
	int knight[64]={-50,-40,-30,-30,-30,-30,-40,-50,
				-40,-20,  0,  0,  0,  0,-20,-40,
				-30,  0, 10, 15, 15, 10,  0,-30,
				-30,  5, 15, 20, 20, 15,  5,-30,
				-30,  0, 15, 20, 20, 15,  0,-30,
				-30,  5, 10, 15, 15, 10,  5,-30,
				-40,-20,  0,  5,  5,  0,-20,-40,
				-50,-40,-30,-30,-30,-30,-40,-50};
	int bishop[64]={-20,-10,-10,-10,-10,-10,-10,-20,
				-10,  0,  0,  0,  0,  0,  0,-10,
				-10,  0,  5, 10, 10,  5,  0,-10,
				-10,  5,  5, 10, 10,  5,  5,-10,
				-10,  0, 10, 10, 10, 10,  0,-10,
				-10, 10, 10, 10, 10, 10, 10,-10,
				-10,  5,  0,  0,  0,  0,  5,-10,
				-20,-10,-10,-10,-10,-10,-10,-20};
	int rook[64]={  0,  0,  0,  0,  0,  0,  0,  0,
				  5, 10, 10, 10, 10, 10, 10,  5,
				 -5,  0,  0,  0,  0,  0,  0, -5,
				 -5,  0,  0,  0,  0,  0,  0, -5,
				 -5,  0,  0,  0,  0,  0,  0, -5,
				 -5,  0,  0,  0,  0,  0,  0, -5,
				 -5,  0,  0,  0,  0,  0,  0, -5,
				  0,  0,  0,  5,  5,  0,  0,  0};
	int queen[64]={-20,-10,-10, -5, -5,-10,-10,-20,
					-10,  0,  0,  0,  0,  0,  0,-10,
					-10,  0,  5,  5,  5,  5,  0,-10,
					 -5,  0,  5,  5,  5,  5,  0, -5,
					  0,  0,  5,  5,  5,  5,  0, -5,
					-10,  5,  5,  5,  5,  5,  0,-10,
					-10,  0,  5,  0,  0,  0,  0,-10,
					-20,-10,-10, -5, -5,-10,-10,-20};
	int kingmiddle[64]={-30,-40,-40,-50,-50,-40,-40,-30,
						-30,-40,-40,-50,-50,-40,-40,-30,
						-30,-40,-40,-50,-50,-40,-40,-30,
						-30,-40,-40,-50,-50,-40,-40,-30,
						-20,-30,-30,-40,-40,-30,-30,-20,
						-10,-20,-20,-20,-20,-20,-20,-10,
						 20, 20,  0,  0,  0,  0, 20, 20,
						 20, 30, 10,  0,  0, 10, 30, 20};
	int kingend[64]={-50,-40,-30,-20,-20,-30,-40,-50,
						-30,-20,-10,  0,  0,-10,-20,-30,
						-30,-10, 20, 30, 30, 20,-10,-30,
						-30,-10, 30, 40, 40, 30,-10,-30,
						-30,-10, 30, 40, 40, 30,-10,-30,
						-30,-10, 20, 30, 30, 20,-10,-30,
						-30,-30,  0,  0,  0,  0,-30,-30,
						-50,-30,-30,-30,-30,-30,-30,-50};
	for(int i=0;i<64;i++)
	{
		PawnTable[i%8][(int)i/8]=pawn[i];
		QueenTable[i%8][(int)i/8]=queen[i];
		RookTable[i%8][(int)i/8]=rook[i];
		KnightTable[i%8][(int)i/8]=knight[i];
		KingEndTable[i%8][(int)i/8]=kingend[i];
		KingMiddleTable[i%8][(int)i/8]=kingmiddle[i];
		BishopTable[i%8][(int)i/8]=bishop[i];
	}
	blackcastled=false;
	whitecastled=false;
	endreached=false;
}
