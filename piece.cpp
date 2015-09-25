#include "piece.h"

unsigned short int piece:: pieceval(){return piecevalue;}

unsigned short int piece:: getxpos(){return xpos;}

unsigned short int piece:: getypos(){return ypos;}

bool piece:: activity(){return active;}

void piece:: flipactivity(){active= !active;}

void piece :: unmoved() {
	this->timesmoved--;
	return;
}
void piece :: moved() {
	this->timesmoved++;
	return;
}

unsigned short int piece :: moves() {
	return timesmoved;
}

bool piece :: type() {
	return bow;
}


void piece:: genmove(piece* datapoints[12][12],int movable_to[12][12],int x,int y)
{
	bool xtrue=true;
	int myx=x;
	int myy=y;
	x=x*myx;
	y=y*myy;
	while(xtrue)
	{
		if(datapoints[(x*myx)+xpos][(y*myy)+ypos]==NULL)
		{
			movable_to[(x*myx)+xpos][(y*myy)+ypos]=1;
			movesavailable++;
			x++;
			y++;
		}
		else if(datapoints[(x*myx)+xpos][(y*myy)+ypos]->piecename==mypieces::boundary)
		{
			xtrue=false;
		}
		else if(datapoints[(x*myx)+xpos][(y*myy)+ypos]->type()!=this->type())
		{
			movable_to[(x*myx)+xpos][(y*myy)+ypos]=5;
			attacks++;
			movesavailable++;
			datapoints[(x*myx)+xpos][(y*myy)+ypos]->attackedby++;
			xtrue=false;
		}
		else if(datapoints[(x*myx)+xpos][(y*myy)+ypos]->type()==this->type())
		{
			movable_to[xpos+(x*myx)][ypos+(y*myy)]=4;
			defends++;
			datapoints[(x*myx)+xpos][(y*myy)+ypos]->defendedby++;
			xtrue=false;
		}
	}
}
