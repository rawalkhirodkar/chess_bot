
#include "board.h"

int Board:: bestmoveforwhite(piece* move1[12][12],int& mya,int& myb,int& myc,int& myd,bool &stalemate)
{
	int movable_to22[12][12];
	stalemate=true;
	piece* move2[12][12];
	int maxx=-100000;
	int x;
	int mywish2;
	copy(move1,move2);
	changeplayertowhite(move1);
	for(int a2=2;a2<10;a2++)
	{
		for(int b2=2;b2<10;b2++)
		{
			if(move1[a2][b2]!=NULL && move1[a2][b2]->type()==1)
			{
				for(int c2=2;c2<10;c2++)
				{
					for(int d2=2;d2<10;d2++)
					{	copy(move1,move2);state=0;
						selectpiece(a2*tilesize,b2*tilesize,move2,movable_to22);
						move2[a2][b2]->availablemoves(move2,movable_to22);	
						//state=1;
						if(movable_to22[c2][d2]!=0 && movable_to22[c2][d2]!=4 )
						{
							mywish2=getclicksandmove(a2,b2,c2*tilesize,d2*tilesize,move2,movable_to22);
							if(mywish2!=0 && !whiteincheck(move2))
							{
								copy(move2,move2);
								x=evaluate(move2);
								if(blackincheck(move2))
								{
									x=x+50;
									if(nomovesforblack(move2))
									{
										x=x+1000;
									}
								}
								if(x>maxx)
								{
									stalemate=false;
									maxx=x;
									mya=a2;
									myb=b2;
									myc=c2;
									myd=d2;
								}
								if(mywish2==6)
								{
									datapoints[9][9]->unmoved();
									whitecastled=false;
								}
								if(mywish2==7)
								{
									datapoints[2][9]->unmoved();
									whitecastled=false;
								}
								if(mywish2==8)
								{
									blackcastled=false;
									datapoints[9][2]->unmoved();
								}
								if(mywish2==9)
								{
									blackcastled=false;
									datapoints[2][2]->unmoved();
								}
							}
						}
					}					
				}
			}
		}
	}
	state=0;
	return maxx;
}
int Board:: bestmoveforblack(piece* move1[12][12],int& mya,int& myb,int& myc,int& myd,bool & stalemate)
{
	int movable_to22[12][12];
	int mywish2;
	stalemate=true;
	piece* move2[12][12];
	int minn=100000;
	int x;
	copy(move1,move2);
	changeplayertoblack(move1);
	for(int a2=2;a2<10;a2++)
	{
		for(int b2=2;b2<10;b2++)
		{
			if(move1[a2][b2]!=NULL && move1[a2][b2]->type()==0)
			{
			for(int c2=2;c2<10;c2++)
			{
				for(int d2=2;d2<10;d2++)
				{	copy(move1,move2);
					state=0;
					selectpiece(a2*tilesize,b2*tilesize,move2,movable_to22);
					move2[a2][b2]->availablemoves(move2,movable_to22);	
					//state=1;
					if(movable_to22[c2][d2]!=0 && movable_to22[c2][d2]!=4 )
					{
						mywish2=getclicksandmove(a2,b2,c2*tilesize,d2*tilesize,move2,movable_to22);
						if(mywish2!=0 && !blackincheck(move2))
						{
							copy(move2,move2);
							x=evaluate(move2);
							if(whiteincheck(move2))
							{
								x=x-50;
								if(nomovesforwhite(move2))
								{
									x=x-1000;
								}
							}
							if(x<minn)
							{
								stalemate=false;
								minn=x;
								mya=a2;
								myb=b2;
								myc=c2;
								myd=d2;
							}
							if(mywish2==6)
							{
								datapoints[9][9]->unmoved();
								whitecastled=false;
							}
							if(mywish2==7)
							{
								datapoints[2][9]->unmoved();
								whitecastled=false;
							}
							if(mywish2==8)
							{
								blackcastled=false;
								datapoints[9][2]->unmoved();
							}
							if(mywish2==9)
							{
								blackcastled=false;
								datapoints[2][2]->unmoved();
							}
						}
					}
				}
			}
		}
		}
	}
	state=0;
	return minn;
}


void Board::getnextmove()
{
	piece* move1[12][12];piece* move3[12][12];piece* move2[12][12];
	int movable_to1[12][12];
	int movable_to2[12][12];
	int movable_to3[12][12];
	int minn2,minn3;
	int minn1=minn2=minn3=1000000;
	int x1,x2,x3,mywish1,mywish2,mywish3;
	int mya,myb,myc,myd;
	bool s1,s2,s3;
	s1=true;
	mywish3=0;
	int mya2,myb2,myc2,myd2;
	int mya3,myb3,myc3,myd3;
	int lala=10000;
	copy(datapoints,move1);
	for(int a=2;a<10;a++)
	{
		for(int b=2;b<10;b++)
		{
			
			if(datapoints[a][b]!=NULL && datapoints[a][b]->type()==0)
			{
				//changeplayertoblack(datapoints);
				state=0;
				
				for(int c=2;c<10;c++)
				{
					for(int d=2;d<10;d++)
					{
						
						mywish3=0;
						changeplayertoblack(datapoints);	
						copy(datapoints,move1);	
						state=0;
						selectpiece(a*tilesize,b*tilesize,move1,movable_to1);
						move1[a][b]->availablemoves(move1,movable_to1);	
						//state=1;
						if(movable_to1[c][d]!=0 && movable_to1[c][d]!=4 )
						{

							//lala=1110;
							mywish1=getclicksandmove(a,b,c*tilesize,d*tilesize,move1,movable_to1);
							copy(move1,move1);
							changeplayertowhite(move1);
							if(mywish1!=0)
							{
								if(!blackincheck(move1))
								{
										changeplayertowhite(move1);									
										if(whiteincheck(move1)&&nomovesforwhite(move1))
										{
											mywish3=1507;
											lala=-10000;
										}
										else
										{
											changeplayertowhite(move1);
											copy(move1,move2);
											if(!stalematewhite(move1))
											{	
												changeplayertowhite(move2);
												state=0;	
												bestmoveforwhite(move2,mya2,myb2,myc2,myd2,s2);
										
													changeplayertowhite(move2);
													state=0;
													copy(move1,move2);
													selectpiece(mya2*tilesize,myb2*tilesize,move2,movable_to2);state=1;
													mywish2=getclicksandmove(mya2,myb2,myc2*tilesize,myd2*tilesize,move2,movable_to2);
													copy(move2,move2);
												if(mywish2!=0 && !whiteincheck(move2))
												{
													changeplayertoblack(move2);
													if(blackincheck(move2)&&nomovesforblack(move2))
													{
														lala=10000;
														mywish3=1507;
													}
													else
													{
														changeplayertoblack(move2);
														if(!stalemateblack(move2))
														{	
															
															copy(move2,move3);
															changeplayertoblack(move2);
															state=0;
															bestmoveforblack(move3,mya3,myb3,myc3,myd3,s3);
															changeplayertoblack(move3);
															state=0;
															copy(move2,move3);
															selectpiece(mya3*tilesize,myb3*tilesize,move3,movable_to3);state=1;
															mywish3=getclicksandmove(mya3,myb3,myc3*tilesize,myd3*tilesize,move3,movable_to3);
															copy(move3,move3);
														}
														else
														{
															continue;
														}
													}
												}
												else
												{
													continue;
												}
												
											}
											else
											{
												mywish3=1507;
												lala=1000;
											}
										}
							
								if(mywish3!=0)
								{
									if(mywish3!=1507){copy(move3,move3);lala=evaluate(move3);}
									if(lala<minn1)
									{

										s1=false;
										minn1=lala;
										mya=a;
										myb=b;
										myc=c;
										myd=d;

									}
									if(mywish1==6||mywish2==6||mywish3==6)
									{
										if(datapoints[9][9]!=NULL)
										datapoints[9][9]->unmoved();
										whitecastled=false;
									}
									if(mywish1==7||mywish2==7||mywish3==7)
									{
										if(datapoints[2][9]!=NULL)
										datapoints[2][9]->unmoved();
										whitecastled=false;
									}
									if(mywish1==8||mywish2==8||mywish3==8)
									{
										if(datapoints[9][2]!=NULL)
										datapoints[9][2]->unmoved();
										whitecastled=false;
									}
									if(mywish1==9||mywish2==9||mywish3==9)
									{
										if(datapoints[2][2]!=NULL)
										datapoints[2][2]->unmoved();
										whitecastled=false;
									}
								}
							}	
								}
							
						}	
					}
				}
			}
		}
	}
	state=0;
	if(s1)
	{
		exit(15);
		return;
	}
	state=0;
	copy(datapoints,move1);
	changeplayertoblack(datapoints);

	selectpiece(mya*tilesize,myb*tilesize,datapoints,movable_to);

	getclicksandmove(mya,myb,myc*tilesize,myd*tilesize,datapoints,movable_to);
	copy(datapoints,datapoints);
	datapoints[myc][myd]->moved();
}

int Board::handle(int e)
{
	int x;
	int y;
	piece* pseud[12][12];
	if (e==FL_PUSH && Fl::event_button()==FL_LEFT_MOUSE) {
		x=Fl::event_x();
		y=Fl::event_y();
		if(state==0)
		{
			selectpiece(x,y,datapoints,movable_to);
		}
		else if(state==1)
		{
			datapoints[currentx][currenty]->availablemoves(datapoints,movable_to);
			getclicksandmove(currentx,currenty,x,y,datapoints,movable_to);
			if(state==0)
			{
				datapoints[(int)x/tilesize][(int)y/tilesize]->moved();
				changeplayertoblack(datapoints);
				copy(datapoints,pseud);
				if(blackincheck(pseud))
				{
					if(nomovesforblack(pseud))
					{
						draw();
						Fl::wait(5);
						//cout<<"You LOSE" << endl;
						exit(0);
					}
				}
				copy(datapoints,pseud);
				if(stalemateblack(pseud))
				{
					draw();
					Fl::wait(5);
					exit(5);
				}
				state=0;
				if(true)
				{
					changeplayertoblack(datapoints);
					draw();
					getnextmove();
					changeplayertowhite(datapoints);
					copy(datapoints,pseud);
					if(whiteincheck(pseud))
					{
						if(nomovesforwhite(pseud))
						{
							draw();
							Fl::wait(5);
							//cout<<"You LOSE" << endl;
							exit(1);
						}

					}
					copy(datapoints,pseud);
					if(stalematewhite(pseud))
						{
							draw();
							Fl::wait(6);
							exit(6);
						}
						state=0;
				}
			}
			state=0;
		}
		draw();
		
	}
	return 1;
}
