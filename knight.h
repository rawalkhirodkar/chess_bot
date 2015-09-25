#include "piece.h"
class Knight:public  piece {
	public:
	virtual void availablemoves(piece* a[12][12],int b[12][12]);
	Knight(int x,int y,bool color);
	int movable(piece*a[12][12],int x,int y);
};
