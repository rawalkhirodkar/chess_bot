#include "piece.h"
class Bishop:public  piece {
	public:
	virtual void availablemoves(piece* a[12][12],int b[12][12]);
	Bishop(int x,int y,bool color);
};
