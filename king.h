#include "piece.h"
class King:public  piece {
	public:
	virtual void availablemoves(piece* a[12][12],int b[12][12]);
	King(int x,int y,bool color);
	bool check(piece* datapoints[12][12],int x,int y);
};
