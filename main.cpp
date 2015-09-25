#include "board.h"

int main()
{
	Fl_Window *window = new Fl_Window (12*tilesize,12*tilesize,"DEMO");
	window->color(56);
	Board *b = new Board(0,0,12*tilesize,12*tilesize,70); 
	window->end(); 
   	window->show();
   	return(Fl::run());
}
