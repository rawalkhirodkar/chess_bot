#include "board.h"

#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>


void Board :: draw() {
	for(int i=2;i<10;i++)
	{
			for(int j=2;j<10;j++)
			{
					if(datapoints[i][j]!=NULL)
					{
						if(datapoints[i][j]->type()==0)
						{
							fl_draw_box(FL_FLAT_BOX,i*tilesize,j*tilesize,
								tilesize-2,tilesize-2,((datapoints[i][j]->piecename))*20+15);
						}
						else
						{
							fl_draw_box(FL_BORDER_BOX,i*tilesize,j*tilesize,
								tilesize-2,tilesize-2,((datapoints[i][j]->piecename))*20+5);
						}
					}
					else
					{
						fl_draw_box(FL_FLAT_BOX,i*tilesize,j*tilesize,
								tilesize-2,tilesize-2,57);
					}
					if(state==1)
					{
						if(movable_to[i][j]==1 || movable_to[i][j]==3){
							fl_draw_box(FL_BORDER_BOX,i*tilesize,j*tilesize,
										tilesize-2,tilesize-2,79);
						}
						else if(movable_to[i][j]==2)
						{
							fl_draw_box(FL_BORDER_BOX,i*tilesize,j*tilesize,
										tilesize-2,tilesize-2,109);
						}
						else if(movable_to[i][j]==5)
						{
							fl_draw_box(FL_BORDER_BOX,i*tilesize,j*tilesize,
										tilesize-2,tilesize-2,139);
						}
						else if(movable_to[i][j]>5)
						{
							fl_draw_box(FL_BORDER_BOX,i*tilesize,j*tilesize,
										tilesize-2,tilesize-2,149);
						}
					}
			}
	}
	fl_register_images(); 	
    Fl_Box box(0,0,51,47);     // widget that will contain image
    Fl_PNG_Image jpg("image.png");      // load jpeg image into ram
    box.image(jpg);  
    parent()->redraw();
    parent()->show();                          // attach jpg image to box
}
