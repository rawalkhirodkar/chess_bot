class boundarypiece: public piece {
	public:
	virtual void availablemoves(piece* a[12][12],int b[12][12]){};
	boundarypiece(){this->piecename=mypieces::boundary;}
};
