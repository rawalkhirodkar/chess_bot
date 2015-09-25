
#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include "allpieces.h"

static const int tilesize=50;
class Board:public Fl_Widget {
	protected:
	int color;
	int bx, by, bw, bh;
	piece* datapoints[12][12];
	int movable_to[12][12];
	public:
	int inix,iniy,finx,finy;
	void getnextmove();
	Board(int bx, int by, int bw, int bh, int c);
	int handle (int e);
	void draw();
	int PawnTable[8][8],KnightTable[8][8],RookTable[8][8],KingMiddleTable[8][8],KingEndTable[8][8],QueenTable[8][8],BishopTable[8][8];
	void selectpiece(int x,int y,piece* mydatapoints[12][12],int movable_top[12][12]);
	int evaluate(piece* asserted[12][12]);
	int evaluate_bishop(piece* asserted[12][12]);
	int evaluate_knight(piece* asserted[12][12]);
	int evaluate_pawn(piece* asserted[12][12]);
	int evaluate_queen(piece* asserted[12][12]);
	int evaluate_rook(piece* asserted[12][12]);
	int evaluate_king(piece* asserted[12][12]);
	void moveto(piece* mydatapoints[12][12],int inx,int iny,int fix,int fiy);
	bool whiteincheck(piece* mydatapoints[12][12]);
	bool blackincheck(piece* mydatapoints[12][12]);
	bool nomovesforblack(piece* mydatapoints[12][12]);
	bool nomovesforwhite(piece* mydatapoints[12][12]);
	bool stalemateblack(piece* move[12][12]);
	bool stalematewhite(piece* move[12][12]);
	bool checkmatewhite(piece* move[12][12]);
	bool checkmateblack(piece* move[12][12]);
	void changeplayertoblack(piece* mydatapoints[12][12]);
	void changeplayertowhite(piece* mydatapoints[12][12]);
	int bestmoveforblack(piece* move1[12][12],int& mya,int& myb,int& myc,int& myd,bool& s);
	int bestmoveforwhite(piece* move1[12][12],int& mya,int& myb,int& myc,int& myd,bool& s);
	void copy(piece* a[12][12],piece* b[12][12]);
	bool whitecastled;
	bool blackcastled;
	bool endreached;
	int currentx;
	int currenty;
	bool state;//If 1 then something is currently clicked on.If 0 nothing is clicked on.
	int getclicksandmove(int,int,int,int,piece* ddatapoints[12][12],int movable_top[12][12]);
};
