#include "piece.h"
class Queen:public  piece {
	public:
	virtual void availablemoves(piece* a[12][12],int b[12][12]);
	Queen(int x,int y,bool color);
};
