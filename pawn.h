
#include "piece.h"
class Pawn:public  piece {
	public:
	virtual void availablemoves(piece* a[12][12],int b[12][12]);
	Pawn(int x,int y,bool color);
};
