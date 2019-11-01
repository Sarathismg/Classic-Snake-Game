//# include "iGraphics.h"
//# include <math.h>
//# include <stdlib.h>
//# include <time.h>
//# define width 10
//# define scrnwdth 1280
//# define scrnht 600
//
//void Snakemove();
//
//int game=0,size=50,i,state=0,speed =10,used=0,end=0,spd=150,mazeno=0,level=2,signal=1,foodeaten=0,j=0;
//int n=4,randm=234;
//int foodx=640,foody=300;
//int x[6000],y[6000];
//
//void random(){
//	randm+=491;
//	randm%=37983;
//}
//
//void statecheck()
//{
//	while(j<1){
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
//	Snakemove();
//	j++;
//	}
//	j=0;
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
//		if(x[i] == foodx && y[i] == foody){
//			genfood();
//			printf("Snake\n");
//		}
//	printf("%d %d\n",foodx,foody);
//	signal = 0;
//
//	}
//	
//}
//
//void drawfood(){
//	if(level==1){
//		iSetColor(136,0,6);
//	}
//	else if(level==2){
//		iSetColor(28,241,17);
//	}
//	else if(level==3){
//		iSetColor(253,67,53);
//	}
//	else if(level==4){
//		iSetColor(30,8,239);
//	}
//	else if(level==5){
//		iSetColor(18,240,7);
//	}
//	/*iFilledCircle(foodx+width/2,foody+width/2,width/2,width/2);
//	iSetColor(0,0,0);
//	iCircle(foodx+width/2,foody+width/2,width/2,width/2);*/
//	iFilledRectangle(foodx,foody,width,width);
//	iSetColor(0,0,0);
//	iRectangle(foodx,foody,width,width);
//}
//
//void isdead()
//{
//	for(i=size-1;i>1;i--){
//		if(x[0]==x[i] && ( y[0] == y[i]))
//			end=1;
//	}
//	if(x[0]== foodx && y[0] == foody){
//		foodeaten++;
//		signal=1;
//		genfood();
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
//void scoreshow(){
//	int now,p;
//	p=foodeaten;
//	iShowBMP(0,scrnht,"SCORE.bmp");
//	iSetColor(243,123,7);
//	iFilledRectangle(240,scrnht,scrnwdth-480,80);
//	for(i=1;i<=5;i++){
//		now=p%10;
//		if(now==0){
//		iShowBMP(scrnwdth-80*i,scrnht,"zero.bmp");
//		}
//		else if(now==1){
//			iShowBMP(scrnwdth-80*i,scrnht,"one.bmp");
//		}
//		else if(now==2){
//			iShowBMP(scrnwdth-80*i,scrnht,"two.bmp");
//		}
//		else if(now==3){
//			iShowBMP(scrnwdth-80*i,scrnht,"three.bmp");
//		}
//		else if(now==4){
//			iShowBMP(scrnwdth-80*i,scrnht,"four.bmp");
//		}
//		else if(now==5){
//			iShowBMP(scrnwdth-80*i,scrnht,"five.bmp");
//		}
//		else if(now==6){
//			iShowBMP(scrnwdth-80*i,scrnht,"six.bmp");
//		}
//		else if(now==7){
//			iShowBMP(scrnwdth-80*i,scrnht,"seven.bmp");
//		}
//		else if(now==8){
//			iShowBMP(scrnwdth-80*i,scrnht,"eight.bmp");
//		}
//		else if(now==9){
//			iShowBMP(scrnwdth-80*i,scrnht,"nine.bmp");
//		}
//
//		p=p/10;
//
//		iSetColor(0,0,0);
//		iRectangle(0,scrnht,240,80);
//		iRectangle(scrnwdth-80*i,scrnht,80,80);
//	}
//	
//
//
//}
//
//
//
//
//void Snakemove()
//{
//	if(level==1){
//		iSetColor(236,0,140);
//	}
//	else if(level==2){
//	iSetColor(255,0,0);
//	}
//	else if(level==3){
//		iSetColor(97,92,91);
//	}
//	else if(level==4){
//		iSetColor(234,222,25);
//	}
//	else if(level==5){
//		iSetColor(6,229,232);
//	}
//
//	isdead();
//
//	for(i=size-1;i>=0;i--)
//	{
//		if(i==0){
//				if(level==1){
//					iSetColor(6,0,236);
//				}
//				else if(level==2){
//					iSetColor(155,155,0);
//				}
//				else if(level==3){
//					iSetColor(255,0,0);
//				}
//				else if(level==4){
//					iSetColor(11,157,226);
//				}
//				else if(level==5){
//					iSetColor(188,164,5);
//				}
//		}
//		iFilledRectangle(x[i],y[i],width,width);
//	
//	}
//	iSetColor(0,0,0);
//	for(i=size-1;i>=0;i--){
//		iRectangle(x[i],y[i],width,width);
//	}
//	if(end==1){
//		 iPauseTimer(0);
//		 iPauseTimer(1);
//		 game=1;
//	}
//}
//
//void maze_level_01(){
//	iShowBMP(0,0,"mazelevel01.bmp");
//}
//
//void maze_level_02(){
//	 double mazex[]={0,0,0,scrnwdth-20};//4 rectangles
//	 double mazey[]={0,0,scrnht-20,20};
//	 double mazedx[]={scrnwdth,20,scrnwdth-20,20};
//	 double mazedy[]={20,scrnht-20,20,scrnht-20};
//	 mazeno=4;
//	 iShowBMP(0,0,"mazelevel02.bmp");
//	 iSetColor(55,41,12);
//	 for(i=0;i<mazeno;i++){
//		 iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//}
//
//void maze_level_03(){
//	double mazex[]={((scrnwdth/3)),0,scrnwdth/1.5,scrnwdth/2};//4 rectangles
//	double mazey[]={scrnht/3,scrnht/6,0,scrnht/1.2};
//	double mazedx[]={20,scrnwdth/2,20,scrnwdth/2};
//	double mazedy[]={scrnht/1.5,20,scrnht/1.5,20};
//	iShowBMP(0,0,"mazelevel03.bmp");
//	mazeno=4;
//	iSetColor(42,90,201);
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
//	iShowBMP(0,0,"mazelevel04.bmp");
//	iSetColor(35,234,25);
//	for(i=0;i<mazeno;i++){
//		iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//}
//
//
//void maze_level_05(){
//	double mazex[20]={0.6*scrnwdth,0,0,0.4*scrnwdth,0.3*scrnwdth,0,0,0.6*scrnwdth};//8 rectangles
//	double mazey[20]={0,scrnht/3,scrnht/1.5,scrnht/1.5,scrnht-20,scrnht-40,scrnht-20,scrnht/1.5};
//	double mazedx[20]={20,scrnwdth,0.4*scrnwdth,20,0.55*scrnwdth,0.1*scrnwdth,0.2*scrnwdth,0.4*scrnwdth};
//	double mazedy[20]={scrnht/3,20,20,scrnht/3-20,20,20,20,20};
//	mazeno=8;
//	level=5;
//	iShowBMP(0,0,"mazelevel05.bmp");
//	iSetColor(220,239,7);
//	for(i=0;i<mazeno;i++){
//		iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//}
//
//
//
//void iDraw()
//{
//	iClear();
//	if(game ==0){
//		if(level==1){
//			maze_level_01();
//		}
//		else if(level==2){
//			maze_level_02();
//		}
//		else if(level==3){
//			maze_level_03();
//		}
//		else if(level==4){
//			maze_level_04();
//		}
//		else if(level=5){
//			maze_level_05();
//		}
//
//		drawfood();
//		Snakemove();
//
//		iSetColor(0,0,0);
//		iRectangle(0,0,scrnwdth,scrnht);
//
//		iSetColor(0,0,0);
//		iFilledRectangle(0,600,scrnwdth,80);
//	}
//	else
//	{
//		iClear();
//		iShowBMP(0,0,"Gameover.bmp");
//
//		iSetColor(0,0,0);
//		iRectangle(0,0,scrnwdth,scrnht);
//
//	}
//	
//	scoreshow();
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
//		j=1;
//		statecheck();
//		isdead();
//		}
//	}
//	else if( key == 'w')
//		{
//
//		if(state!=2 && state!=1){
//		state = 1;
//		j = 1;
//		statecheck();
//		isdead();
//
//		}
//	}
//	else if( key == 's')
//		{
//		if(state!=1 && state!=2){
//		state = 2;
//		j =1 ;
//		statecheck();
//		isdead();
//
//	}
//	}
//	else if( key == 'd')
//		{if(state!=0 && state!=3){
//		state = 3;
//		j= 1;
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
//	if(key == GLUT_KEY_UP)
//	{
//		if(state!=2 && state!=1){
//		state = 1;
//		i = 1;
//		statecheck();
//		isdead();
//
//		}	
//	}
//	else if(key== GLUT_KEY_DOWN)
//	{
//		if(state!=1 && state!=2){
//		state = 2;
//		i = 1;
//		statecheck();
//		isdead();
//		}
//
//	}
//	else if(key== GLUT_KEY_LEFT)
//	{
//		if(state!=3 && state!= 0){
//		state=0;
//		statecheck();
//		isdead();
//		}
//
//	}
//	else if(key== GLUT_KEY_RIGHT)
//	{
//		if(state!=0 && state!=3){
//		state = 3;
//		i = 1;
//		statecheck();
//		isdead();
//		}
//
//	}
//
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
//	iSetTimer(10,statecheck);
//	iSetTimer(1,random);
//	iInitialize(scrnwdth,scrnht+80,"Snake!");
//	
//
//}