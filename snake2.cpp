//# include "iGraphics.h"
//# include <math.h>
//# include <stdlib.h>
//# include <time.h>
//# define width 10
//# define scrnwdth 1280
//# define scrnht 680
//
//
//int size=50,i,state=0,speed =10,used=0,end=0,spd=150,mazeno=0,level=1,signal=1;
//int n=4,randm=234;
//int foodx=910,foody=600;
//int x[6000],y[6000];
//
//void random(){
//	randm+=491;
//	randm%=37983;
//}
//
//void statecheck()
//{
//	for(i=size;i>0;i--)
//	{
//		x[i]=x[i-1];
//		y[i]=y[i-1];
//	}
//
//	if(state==0)//snake moving left
//	{
//		x[0]-=speed;
//		if(x[0]<0)
//			x[0]=scrnwdth-width;
//	}
//
//	else if(state==1)//up
//	{
//		y[0]+=speed;
//		if((y[0]+width)>scrnht)
//			y[0]=0;
//	}
//
//	else if(state==2)//down
//	{
//		y[0]-=speed;
//		if(y[0]<0)
//			y[0]=scrnht-width;
//	}
//
//	else if(state==3)//snake moving right
//	{
//		x[0]+=speed;
//		if((x[0]+width)>scrnwdth)
//			x[0]=0;
//	}
//	//used=1;
//
//}
//
//void genfood(){
//	if(signal == 1){
//		
//	srand(time(NULL));
//	foodx = ((((rand()*7)+85+randm+21*(int)foodx+56)%(scrnwdth-width))/width)*width;
//	foody = ((((rand()*2)+12+randm+65*(int)foody+67)%(scrnht-width))/width)*width;
//	for(i=size-1;i>=0;i--)
//		if(x[i] == foodx && y[i] == foody)
//			genfood();
//	printf("%lf %lf\n",foodx,foody);
//	signal = 0;
//
//	}
//	
//}
//
//void drawfood(){
//	iSetColor(155,110,34);
//	iFilledRectangle(foodx,foody,width,width);
//}
//
//void isdead()
//{
//	for(i=size-1;i>1;i--)
//		if(x[0]==x[i] && ( y[0] == y[i]))
//			end=1;
//	if(x[0]== foodx && y[0] == foody){
//		genfood();
//		signal=1;
//		size+=5;
//	}
//	
//}
//
//void mazedead(double mazex[],double mazey[],double mazedx[],double mazedy[]){
//	for(i=0;i<mazeno;i++){
//		if((x[0]+width)>mazex[i] && (x[0]<(mazex[i]+mazedx[i])) && (y[0]+width)>mazey[i] && (y[0]<(mazey[i]+mazedy[i])))
//			end=1;
//		if((foodx+width)>mazex[i] && (foodx<(mazex[i]+mazedx[i])) && (foody+width)>mazey[i] && (foody<(mazey[i]+mazedy[i]))){
//			signal = 1;
//			genfood();
//			
//		}
//
//	}
//}
//
//
//
//void Snakemove()
//{
//	if(level==2){
//	iSetColor(255,0,0);
//	}
//	else if(level==3){
//		iSetColor(0,0,255);
//	}
//	else if(level==4){
//		iSetColor(181,60,86);
//	}
//
//	isdead();
//	//if(end!=1)
//	for(i=size-1;i>=0;i--)
//	{
//		//iSetColor(0,155,0);
//		iFilledRectangle(x[i],y[i],width,width);
//	
//	}
//	if(end==1){
//		 iPauseTimer(0);
//		 iPauseTimer(1);
//	}
//}
//
//void maze_level_02(){
//	 double mazex[]={0,0,0,scrnwdth-20};//4 rectangles
//	 double mazey[]={0,0,scrnht-20,20};
//	 double mazedx[]={scrnwdth,20,scrnwdth-20,20};
//	 double mazedy[]={20,scrnht-20,20,scrnht-20};
//	 mazeno=4;
//	 spd=spd/3;
//	 level=2;
//	 iSetColor(15,235,175);
//	 iFilledRectangle(0,0,scrnwdth,scrnht);
//	 iSetColor(255,0,0);
//	 for(i=0;i<mazeno;i++){
//		 iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//	/*iFilledRectangle(20,20,scrnwdth-40,20);
//	iFilledRectangle(20,20,20,scrnht-40);
//	iFilledRectangle(20,scrnht-40,scrnwdth-40,20);
//	iFilledRectangle(scrnwdth-40,20,20,scrnht-40);*/
//}
//
//void maze_level_03(){
//	double mazex[]={((scrnwdth/3)),0,scrnwdth/1.5,scrnwdth/2};//4 rectangles
//	double mazey[]={scrnht/3,scrnht/6,0,scrnht/1.2};
//	double mazedx[]={20,scrnwdth/2,20,scrnwdth/2};
//	double mazedy[]={scrnht/1.5,20,scrnht/1.5,20};
//	level=3;
//	spd=spd/4;
//	mazeno=4;
//	iSetColor(195,212,190);
//	iFilledRectangle(0,0,scrnwdth,scrnht);
//	iSetColor(0,0,255);
//	for(i=0;i<mazeno;i++){
//		iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//}
//
//void maze_level_04(){
//	double mazex[20]={0,0,0,scrnwdth-20,0,scrnwdth-20,scrnwdth/10,9*scrnwdth/10,scrnwdth/5,scrnwdth/5};//10 rectangles
//	double mazey[20]={0,scrnht-20,0,0,7*scrnht/12,7*scrnht/12,scrnht/2.4,scrnht/2.4,(scrnht/2.4)-20,7*scrnht/12};
//	double mazedx[20]={scrnwdth,scrnwdth,20,20,20,20,20,20,3*scrnwdth/5,3*scrnwdth/5};
//	double mazedy[20]={20,20,scrnht/2.4,scrnht/2.4,scrnht/2.4,scrnht/2.4,scrnht/6,scrnht/6,20,20};
//	mazeno=10;
//	level=4;
//	iSetColor(227,210,9);
//	iFilledRectangle(0,0,scrnwdth,scrnht);
//	iSetColor(181,60,86);
//	for(i=0;i<mazeno;i++){
//		iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//}
//
//void iDraw()
//{
//	iClear();
//	//if(signal == 1)
//	maze_level_02();
//	drawfood();
//	Snakemove();
//	
//	
//}
//
//
//void iMouseMove(int mx, int my)
//{
//	
//}
//
//
//void iMouse(int button, int state, int mx, int my)
//{
//	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//			
//	}
//	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//	{
//		
//	}
//}
//
////1-up,2-down , 3- right,0- left
//void iKeyboard(unsigned char key)
//{
//	if(key == 'a')
//	{
//		if(state!=3 && state!= 0){
//		state=0;
//		statecheck();
//		isdead();
//		}
//	}
//	else if( key == 'w')
//		{
//
//		if(state!=2 && state!=1){
//		state = 1;
//		statecheck();
//		isdead();
//
//		}
//	}
//	else if( key == 's')
//		{
//		if(state!=1 && state!=2){
//		state = 2;
//		statecheck();
//		isdead();
//
//	}
//	}
//	else if( key == 'd')
//		{if(state!=0 && state!=3){
//		state = 3;
//		statecheck();
//		isdead();
//
//	}
//	}
//}
//
//
//void iSpecialKeyboard(unsigned char key)
//{
//
//	if(key == GLUT_KEY_END)
//	{
//		exit(0);	
//	}
//}
//
//
//
//int main()
//{
//	for(i=0;i<size;i++)
//	{
//		x[i]=200+speed*(i);
//		y[i]=150;
//	}
//	iSetTimer(spd/5,statecheck);
//	iSetTimer(1,random);
//	iInitialize(scrnwdth,scrnht,"Snake!");
//	
//
//}