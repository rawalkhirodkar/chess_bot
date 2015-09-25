#include "piece.h"
class Rook:public  piece {
	public:
	virtual void availablemoves(piece* a[12][12],int b[12][12]);
	Rook(int x,int y,bool color);
};
