//# include "igraphics.h"
//# include <math.h>
//# include <stdlib.h>
//# include <time.h>
//# include <stdio.h>
//# define widdth 10
//# define scrnwdth 1280
//# define scrnht 600
//
//void snakemove();
//
//file *fpl,*fps;
//int game=3,size=50,i,state=0,speed =10,used=0,end=0,spd=150,mazeno=0,level=3,signal=2,foodeaten=0,j=0,p=0;
//int n=4,randm=234,exfood=0,extime,prsnttime;
//int foodx=640,foody=300,exfoodx,exfoody;
//int x[6000],y[6000];
//
//struct highscore{
//		int lvl;
//		int score;
//	} hgh[5],hghd[5];
//
//
//void highscorefit(int levelnow,int scorenow){
//	file *fphigh;
//	int po;
//
//	//scorenow=11,levelnow=4;
//
//	fphigh=fopen("highscores.txt","r");
//	for(po=0;po<5;po++){
//		fscanf(fphigh,"%d%d",&(hgh[po].lvl),&(hgh[po].score));
//	}
//
//	fclose(fphigh);
//
//	fphigh=fopen("highscores.txt","w");
//
//	for(po=0;po<5;po++){
//		if(hgh[po].lvl==levelnow){
//			if(hgh[po].score<scorenow){
//				hgh[po].score=scorenow;
//			}
//		}
//			fprintf(fphigh,"%d %d\n",hgh[po].lvl,hgh[po].score);
//	}
//
//	fclose(fphigh);
//}
//
//
//int hsreturn(int level){
//	file *fphigh;
//	int a,b,c;
//	fphigh=fopen("highscores.txt","r");
//	for(c=1;c<=5;c++){
//		fscanf(fphigh,"%d%d",&a,&b);
//		if(a==level){
//			fclose(fphigh);
//			return b;
//		}
//	}
//}
//
//void loadgame(){
//	//fflush(stdin);
//	
//	fpl=fopen("sav2.txt","r");
//	if(fpl!=null){
//	fscanf(fpl,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d ",&game,&size,&i,&state,&speed,&used,&end,&spd,&mazeno,&level,&signal,&foodeaten,&j,&p);
//	fscanf(fpl,"%d %d %d %d %d ",&n,&randm,&exfood,&extime,&prsnttime);
//	fscanf(fpl,"%d %d %d %d ",&foodx,&foody,&exfoodx,&exfoody);
//	game = 0;
//	for(i=0;i<size;i++){
//		fscanf(fpl,"%d ",&x[i]);
//	}
//	for(i=0;i<size;i++){
//		fscanf(fpl,"%d ",&y[i]);
//	}
//	}
//	if(fpl!=null)
//	fclose(fpl);
//
//	iresumetimer(0);
//	iresumetimer(1);
//}
//
//void savegame(){
//	fps=fopen("sav2.txt","w");
//	fprintf(fps,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d ",game,size,i,state,speed,used,end,spd,mazeno,level,signal,foodeaten,j,p);
//	fprintf(fps,"%d %d %d %d %d ",n,randm,exfood,extime,prsnttime);
//	fprintf(fps,"%d %d %d %d ",foodx,foody,exfoodx,exfoody);
//	for(i=0;i<size;i++){
//		fprintf(fps,"%d ",x[i]);
//	}
//	for(i=0;i<size;i++){
//		fprintf(fps,"%d ",y[i]);
//	}
//	fclose(fps);
//}
//
//
//void random(){
//	randm+=491;
//	randm%=37983;
//}
//
//void statecheck()
//{
//	
//	//isetcolor(100,100,100);
//	//ifilledrectangle(212,453,200,400);
//	//while(j<1){
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
//			x[0]=scrnwdth-widdth;
//	}
//
//	else if(state==1)//up
//	{
//		y[0]+=speed;
//		if((y[0]+widdth)>scrnht)
//			y[0]=0;
//	}
//
//	else if(state==2)//down
//	{
//		y[0]-=speed;
//		if(y[0]<0)
//			y[0]=scrnht-widdth;
//	}
//
//	else if(state==3)//snake moving right
//	{
//		x[0]+=speed;
//		if((x[0]+widdth)>scrnwdth)
//			x[0]=0;
//	}
//	snakemove();
//	
//
//	j++;
//	}
//	//j=0;
//	//idraw();
//
//
//void genfood(){
//	if(signal == 1){
//		
//	srand(time(null));
//	foodx = ((((rand()*7)+85+randm+21*(int)foodx+56)%(scrnwdth-widdth))/widdth)*widdth;
//	foody = ((((rand()*2)+12+randm+65*(int)foody+67)%(scrnht-widdth))/widdth)*widdth;
//	for(i=size-1;i>=0;i--)
//		if(x[i] == foodx && y[i] == foody){
//			genfood();
//			printf("snake\n");
//		}
//	printf("%d %d\n",foodx,foody);
//	signal = 0;
//}
//}
//	
//void genfood2(){
//	if(exfood == 0){
//	srand(time(null));
//	exfoodx = ((((rand()*6)+67+randm+19*(int)exfoodx+67)%(scrnwdth-widdth))/widdth)*widdth;
//	exfoody = ((((rand()*9)+23+randm+7*(int)exfoody+10)%(scrnht-widdth))/widdth)*widdth;
//	for(i=size-1;i>=0;i--)
//		if(x[i] == exfoodx && y[i] == exfoody){
//			genfood2();
//			//printf("snake\n");
//		
//		}
//		exfood = 1;
//	}
//	//printf("%d %d\n",foodx,foody);
//	
//}
//
//void drawex(){
//	static int rr=25,gg=135,bb=210;
//	rr+=80;
//	rr%=255;
//	gg+=40;
//	gg%=255;
//	bb+=79;
//	bb%=255;
//	isetcolor(rr,gg,bb);
//	ifilledrectangle(exfoodx,exfoody,widdth,widdth);
//}
//
//void drawfood(){
//	if(level==1){
//		isetcolor(146,0,141);
//	}
//	else if(level==2){
//		isetcolor(28,241,17);
//	}
//	else if(level==3){
//		isetcolor(253,67,53);
//	}
//	else if(level==4){
//		isetcolor(30,8,239);
//	}
//	else if(level==5){
//		isetcolor(18,240,7);
//	}
//	/*ifilledcircle(foodx+width/2,foody+width/2,width/2,width/2);
//	isetcolor(0,0,0);
//	icircle(foodx+width/2,foody+width/2,width/2,width/2);*/
//	ifilledrectangle(foodx,foody,widdth,widdth);
//	isetcolor(0,0,0);
//	irectangle(foodx,foody,widdth,widdth);
//}
//
//void inctime(){
//	prsnttime+=1;
//	//printf("%d\n",prsnttime);
//}
//
//void extrafood(){
//	
//	if(prsnttime >= extime ){
//		prsnttime=0;
//		exfood=2;
//	}
//	else{
//		if(exfood!=1){
//		genfood2();
//		}
//		drawex();
//	}
//}
//
//
//void isdead()
//{
//	for(i=size-1;i>1;i--){
//		if(x[0]==x[i] && ( y[0] == y[i]))
//			end=1;
//	}
//	if(x[0]== foodx && y[0] == foody){
//		prsnttime = 0;
//		exfood=0;
//		foodeaten++;
//		signal=1;
//		genfood();
//		size+=1;
//		p++;
//		
//	}
//
//	if(exfood == 1){
//	if(x[0]== exfoodx && y[0] == exfoody){        //score condition needed to be put here
//		p+=10*(extime-prsnttime)/extime;
//		exfood = 2;
//		prsnttime = 0;
//	}
//	}
//	
//}
//
//void mazedead(double mazex[],double mazey[],double mazedx[],double mazedy[]){
//	for(i=0;i<mazeno;i++){
//		if((x[0]+widdth)>mazex[i] && (x[0]<(mazex[i]+mazedx[i])) && (y[0]+widdth)>mazey[i] && (y[0]<(mazey[i]+mazedy[i])))
//			end=1;
//		if((foodx+widdth)>mazex[i] && (foodx<(mazex[i]+mazedx[i])) && (foody+widdth)>mazey[i] && (foody<(mazey[i]+mazedy[i]))){
//			signal = 1;
//			genfood();
//		}
//		if(exfood == 1){
//		if((exfoodx+widdth)>mazex[i] && (exfoodx<(mazex[i]+mazedx[i])) && (exfoody+widdth)>mazey[i] && (exfoody<(mazey[i]+mazedy[i]))){
//			exfood=0;
//			genfood2();
//			
//		}
//
//	}
//}
//}
//
//
//
//void scoreshow(){
//	int now,temp=p;
//	//p=foodeaten;
//	ishowbmp(scrnwdth-200,scrnht+40,"score.bmp");
//	isetcolor(0,0,0);
//	irectangle(scrnwdth-200,scrnht+40,200,40);
//	//isetcolor(0,0,0);
//	//ifilledrectangle(120,scrnht,scrnwdth-200,80);
//	for(i=1;i<=5;i++){
//		now=temp%10;
//		if(now==0){
//		ishowbmp(scrnwdth-40*i,scrnht,"zero.bmp");
//		}
//		else if(now==1){
//			ishowbmp(scrnwdth-40*i,scrnht,"one.bmp");
//		}
//		else if(now==2){
//			ishowbmp(scrnwdth-40*i,scrnht,"two.bmp");
//		}
//		else if(now==3){
//			ishowbmp(scrnwdth-40*i,scrnht,"three.bmp");
//		}
//		else if(now==4){
//			ishowbmp(scrnwdth-40*i,scrnht,"four.bmp");
//		}
//		else if(now==5){
//			ishowbmp(scrnwdth-40*i,scrnht,"five.bmp");
//		}
//		else if(now==6){
//			ishowbmp(scrnwdth-40*i,scrnht,"six.bmp");
//		}
//		else if(now==7){
//			ishowbmp(scrnwdth-40*i,scrnht,"seven.bmp");
//		}
//		else if(now==8){
//			ishowbmp(scrnwdth-40*i,scrnht,"eight.bmp");
//		}
//		else if(now==9){
//			ishowbmp(scrnwdth-40*i,scrnht,"nine.bmp");
//		}
//
//		temp=temp/10;
//
//		isetcolor(0,0,0);
//		irectangle(scrnwdth-40*i,scrnht,40,40);
//	}
//
//	ishowbmp(0,scrnht+40,"foodeaten.bmp");
//	isetcolor(0,0,0);
//	irectangle(0,scrnht+40,120,40);
//	temp=foodeaten;
//
//	for(i=1;i<=3;i++){
//		now=temp%10;
//		if(now==0){
//		ishowbmp(120-40*i,scrnht,"zero.bmp");
//		}
//		else if(now==1){
//			ishowbmp(120-40*i,scrnht,"one.bmp");
//		}
//		else if(now==2){
//			ishowbmp(120-40*i,scrnht,"two.bmp");
//		}
//		else if(now==3){
//			ishowbmp(120-40*i,scrnht,"three.bmp");
//		}
//		else if(now==4){
//			ishowbmp(120-40*i,scrnht,"four.bmp");
//		}
//		else if(now==5){
//			ishowbmp(120-40*i,scrnht,"five.bmp");
//		}
//		else if(now==6){
//			ishowbmp(120-40*i,scrnht,"six.bmp");
//		}
//		else if(now==7){
//			ishowbmp(120-40*i,scrnht,"seven.bmp");
//		}
//		else if(now==8){
//			ishowbmp(120-40*i,scrnht,"eight.bmp");
//		}
//		else if(now==9){
//			ishowbmp(120-40*i,scrnht,"nine.bmp");
//		}
//
//		temp=temp/10;
//
//		isetcolor(0,0,0);
//		irectangle(120-40*i,scrnht,40,40);
//	}
//
//	isetcolor(247,148,28);
//	ifilledrectangle(120,scrnht,scrnwdth-320,80);
//}
//
//
//
//void snakemove()
//{
//	if(level==1){
//		isetcolor(236,0,140);
//	}
//	else if(level==2){
//	isetcolor(255,0,0);
//	}
//	else if(level==3){
//		isetcolor(97,92,91);
//	}
//	else if(level==4){
//		isetcolor(234,222,25);
//	}
//	else if(level==5){
//		isetcolor(6,229,232);
//	}
//
//	isdead();
//
//	for(i=size-1;i>=0;i--)
//	{
//		if(i==0){
//				if(level==1){
//					isetcolor(6,0,236);
//				}
//				else if(level==2){
//					isetcolor(155,155,0);
//				}
//				else if(level==3){
//					isetcolor(255,0,0);
//				}
//				else if(level==4){
//					isetcolor(11,157,226);
//				}
//				else if(level==5){
//					isetcolor(188,164,5);
//				}
//		}
//		ifilledrectangle(x[i],y[i],widdth,widdth);
//	
//	}
//	isetcolor(0,0,0);
//	for(i=size-1;i>=0;i--){
//		irectangle(x[i],y[i],widdth,widdth);
//	}
//	if(end==1){
//		 ipausetimer(0);
//		 ipausetimer(1);
//		 game=1;
//	}
//}
//
//
//void maze_level_01(){
//	ishowbmp(0,0,"mazelevel01.bmp");
//	extime=16;
//}
//
//void maze_level_02(){
//	 double mazex[]={0,0,0,scrnwdth-20};//4 rectangles
//	 double mazey[]={0,0,scrnht-20,20};
//	 double mazedx[]={scrnwdth,20,scrnwdth-20,20};
//	 double mazedy[]={20,scrnht-20,20,scrnht-20};
//	 extime = 12;
//	 mazeno=4;
//	 ishowbmp(0,0,"mazelevel02.bmp");
//	  isetcolor(55,41,12);
//	 for(i=0;i<mazeno;i++){
//		 ifilledrectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//}
//
//void maze_level_03(){
//	double mazex[]={((scrnwdth/3)),0,scrnwdth/1.5,scrnwdth/2};//4 rectangles
//	double mazey[]={scrnht/3,scrnht/6,0,scrnht/1.2};
//	double mazedx[]={20,scrnwdth/2,20,scrnwdth/2};
//	double mazedy[]={scrnht/1.5,20,scrnht/1.5,20};
//	ishowbmp(0,0,"mazelevel03.bmp");
//	extime = 10;
//
//	mazeno=4;
//	isetcolor(42,90,201);
//	for(i=0;i<mazeno;i++){
//		ifilledrectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//}
//
//void maze_level_04(){
//	double mazex[]={0,0,0,scrnwdth-20,0,scrnwdth-20,scrnwdth/10,9*scrnwdth/10,scrnwdth/5,scrnwdth/5};//10 rectangles
//	double mazey[]={0,scrnht-20,0,0,7*scrnht/12,7*scrnht/12,scrnht/2.4,scrnht/2.4,(scrnht/2.4)-20,7*scrnht/12};
//	double mazedx[]={scrnwdth,scrnwdth,20,20,20,20,20,20,3*scrnwdth/5,3*scrnwdth/5};
//	double mazedy[]={20,20,scrnht/2.4,scrnht/2.4,scrnht/2.4,scrnht/2.4,scrnht/6,scrnht/6,20,20};
//	extime = 8;
//	mazeno=10;
//	level=4;
//	ishowbmp(0,0,"mazelevel04.bmp");
//	isetcolor(35,234,25);
//	for(i=0;i<mazeno;i++){
//		ifilledrectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//}
//
//void maze_level_05(){
//	double mazex[]={0.6*scrnwdth,0,0,0.4*scrnwdth,0.3*scrnwdth,0,0,0.6*scrnwdth};//8 rectangles
//	double mazey[]={0,scrnht/3,scrnht/1.5,scrnht/1.5,scrnht-20,scrnht-40,scrnht-20,scrnht/1.5};
//	double mazedx[]={20,scrnwdth,0.4*scrnwdth,20,0.55*scrnwdth,0.1*scrnwdth,0.2*scrnwdth,0.4*scrnwdth};
//	double mazedy[]={scrnht/3,20,20,scrnht/3-20,20,20,20,20};
//	extime = 8;
//	mazeno=8;
//	level=5;
//	ishowbmp(0,0,"mazelevel05.bmp");
//	isetcolor(220,239,7);
//	for(i=0;i<mazeno;i++){
//		ifilledrectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
//	}
//	mazedead(mazex,mazey,mazedx,mazedy);
//}
//
//void highshow(){
//	int a,sc,temp1,b,nw;
//	ishowbmp(290,scrnht-160,"halloffame.bmp");
//	ishowbmp(0,0,"backtomenu.bmp");
//	ishowbmp(315,70,"legendary.bmp");
//	ishowbmp(315,140,"expert.bmp");
//	ishowbmp(315,210,"specialist.bmp");
//	ishowbmp(315,280,"amateur.bmp");
//	ishowbmp(315,350,"novice.bmp");
//
//	for(a=1;a<=5;a++){
//		sc=hsreturn(6-a);
//		temp1=sc;
//		for(b=1;b<=5;b++){
//			nw=temp1%10;
//			if(nw==0){
//				ishowbmp(865-40*b,70*a,"zero.bmp");
//			}
//			else if(nw==1){
//				ishowbmp(865-40*b,70*a,"one.bmp");
//			}
//			else if(nw==2){
//				ishowbmp(865-40*b,70*a,"two.bmp");
//			}
//			else if(nw==3){
//				ishowbmp(865-40*b,70*a,"three.bmp");
//			}
//			else if(nw==4){
//				ishowbmp(865-40*b,70*a,"four.bmp");
//			}
//			else if(nw==5){
//				ishowbmp(865-40*b,70*a,"five.bmp");
//			}
//			else if(nw==6){
//				ishowbmp(865-40*b,70*a,"six.bmp");
//			}
//			else if(nw==7){
//				ishowbmp(865-40*b,70*a,"seven.bmp");
//			}
//			else if(nw==8){
//				ishowbmp(865-40*b,70*a,"eight.bmp");
//			}
//			else if(nw==9){
//				ishowbmp(865-40*b,70*a,"nine.bmp");
//			}
//
//			temp1=temp1/10;
//		}
//	}
//}
//
//void snakeinitialize(){
//			foodeaten=0;
//			p=0;
//			for(i=0;i<size;i++){
//				x[i]=200+speed*(i);
//				y[i]=150;
//			}
//			size=50;
//			state=0;
//			speed=10;
//			used=0;
//			end=0;
//			spd=150;
//			signal=2;
//			randm=234;
//			exfood=0;
//			iresumetimer(0);
//			iresumetimer(1);
//}
//
//
//
//void idraw()
//{
//	iclear();
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
//		//statecheck();////////
//		if(foodeaten%5 == 0 && exfood!=2){
//			extrafood();
//		}
//		
//		drawfood();
//		snakemove();
//		
//
//		isetcolor(0,0,0);
//		irectangle(0,0,scrnwdth,scrnht);
//
//		isetcolor(0,0,0);
//		ifilledrectangle(0,600,scrnwdth,80);
//
//		scoreshow();
//	}
//	else if(game == 1)
//	{
//		highscorefit(level,p);
//		iclear();
//		ishowbmp(0,0,"gameover.bmp");
//		isetcolor(0,0,0);
//		irectangle(0,0,scrnwdth,scrnht);
//		scoreshow();
//		ishowbmp(0,0,"backtomenu.bmp");
//		ishowbmp(980,0,"exit.bmp");
//	}
//	else if ( game == 2)
//	{
//		iclear();
//		isetcolor(255,50,0);
//		ifilledrectangle(0,0,scrnwdth,scrnht);
//		//ishowbmp(0,0,"mainmenu.bmp");
//		ishowbmp(scrnwdth/2-150,scrnht/2-150,"pause.bmp");
//		ishowbmp(scrnwdth/2+40-150,scrnht/2-150+32,"pexit.bmp");
//		ishowbmp(scrnwdth/2+40-150,scrnht/2-150+98,"save.bmp");
//		ishowbmp(scrnwdth/2+40-150,scrnht/2-150+163,"resume.bmp");
//		scoreshow();
//		//idelay(4);
//		
//	}
//
//	else if(game==3){
//		ishowbmp(0,0,"mainmenu.bmp");
//		ishowbmp(80,scrnht-150,"name.bmp");
//		ishowbmp(40,70,"exit.bmp");
//		ishowbmp(40,140,"instructions.bmp");
//		ishowbmp(40,210,"highscores.bmp");
//		ishowbmp(40,280,"loadgame.bmp");
//		ishowbmp(40,350,"newgame.bmp");
//	}
//
//	else if(game == 4){
//		ishowbmp(0,0,"maininstructions.bmp");
//		ishowbmp(0,0,"backtomenu.bmp");
//	}
//	else if(game==5){
//		ishowbmp(0,0,"mainmenu.bmp");
//		highshow();
//	}
//	else if(game==6){
//		ishowbmp(0,0,"mainmenu.bmp");
//		ishowbmp(290,scrnht-160,"selectlevel.bmp");
//		ishowbmp(490,70,"legendary.bmp");
//		ishowbmp(490,140,"expert.bmp");
//		ishowbmp(490,210,"specialist.bmp");
//		ishowbmp(490,280,"amateur.bmp");
//		ishowbmp(490,350,"novice.bmp");
//		ishowbmp(0,0,"backtomenu.bmp");
//	}
//	
//}
//
//
//void imousemove(int mx, int my)
//{
//	
//}
//
//
//void imouse(int button, int state, int mx, int my)
//{
//	//pause menu
//	if(button == glut_left_button && state == glut_down)
//	{
//		if(game==2){
//			if((mx>=scrnwdth/2-150+40 && mx<=(scrnwdth/2-150+297))){
//			if(my>=scrnht/2-150+32 && my<= scrnht/2-150+32+52){
//				highscorefit(level,p);
//				game = 3;
//			}
//			else if(my>=scrnht/2-150+98 && my<= scrnht/2-150+98+51){
//				highscorefit(level,p);
//				savegame();
//			}
//			else if(my>=scrnht/2-150+163 && my<= scrnht/2-150+163+52){
//				game = 0;
//				iresumetimer(0);
//			}
//		}
//		}
//		else if(game==3){
//			if(mx>=40 && mx<=340){
//				if(my>=70 && my<=120){
//					exit(0);
//				}
//				else if(my>=140 && my<=190){
//					game=4;
//				}
//				else if(my>=210 && my<=260){
//					game=5;
//				}
//				else if(my>=280 && my<=330){
//					loadgame();
//				}
//				else if(my>=350 && my<=400){
//					game=6;
//				}
//			}
//		}
//		else if(game==6){
//			snakeinitialize();
//			if(mx>=490 && mx<=790){
//				if(my>=70 && my<=120){
//					level=5;
//					game=0;
//				}
//				else if(my>=140 && my<=190){
//					level=4;
//					game=0;
//				}
//				else if(my>=210 && my<=260){
//					level=3;
//					game=0;
//				}
//				else if(my>=280 && my<=330){
//					level=2;
//					game=0;
//				}
//				else if(my>=350 && my<=400){
//					level=1;
//					game=0;
//				}
//			}
//			else if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
//				game=3;
//			}
//
//		}
//		else if(game==5 || game==4){
//			if(mx>=0 && mx<=300){
//				if(my>=0 && my<=50){
//					game=3;
//				}
//			}
//		}
//		else if(game==1){
//			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
//				game=3;
//			}
//			else if((mx>= 980 && mx<=1280) && (my>=0 && my<=50)){
//				exit(0);
//			}
//		}
//	}
//	
//	if(button == glut_right_button && state == glut_down)
//	{
//		
//	}
//}
//
////1-up,2-down , 3- right,0- left
//void ikeyboard(unsigned char key)
//{
//	if(key == 'a')
//	{
//		if(state!=3 && state!= 0){
//		state=0;
//		//j=1;
//		statecheck();
//		isdead();
//		}
//	}
//	else if( key == 'w')
//		{
//
//		if(state!=2 && state!=1){
//		state = 1;
//		//j = 1;
//		statecheck();
//		isdead();
//
//		}
//	}
//	else if( key == 's')
//		{
//		if(state!=1 && state!=2){
//		state = 2;
//		//j =1 ;
//		statecheck();
//		isdead();
//
//	}
//	}
//	else if( key == 'd')
//		{if(state!=0 && state!=3){
//		state = 3;
//		//j= 1;
//		statecheck();
//		isdead();
//
//	}
//	}
//	if(key == ';' && exfood == 1){        //cheat code 
//		p+=10*(extime-prsnttime)/extime;
//		exfood = 2;
//		prsnttime = 0;
//	}
//
//	if(key == 'l'){
//		loadgame();
//	}
//	if(key =='g'){
//		savegame();
//	}
//	if(key == 'p')
//	{
//		//do something with 'q'
//		if(game==0){
//		ipausetimer(0);
//		game = 2;
//		}
//	}
//	if(key == 'r'){
//		if(game==2){
//			game=0;
//			iresumetimer(0);
//		}
//	}
//}
//
//
//void ispecialkeyboard(unsigned char key)
//{
//
//	if(key == glut_key_up)
//	{
//		if(state!=2 && state!=1){
//		state = 1;
//		i = 1;
//		statecheck();
//		isdead();
//
//		}	
//	}
//	else if(key== glut_key_down)
//	{
//		if(state!=1 && state!=2){
//		state = 2;
//		i = 1;
//		statecheck();
//		isdead();
//		}
//
//	}
//	else if(key== glut_key_left)
//	{
//		if(state!=3 && state!= 0){
//		state=0;
//		statecheck();
//		isdead();
//		}
//
//	}
//	else if(key== glut_key_right)
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
//	genfood();
//	genfood2();
//	isettimer(60,statecheck);
//	isettimer(1,random);
//	isettimer(500,inctime);
//	iinitialize(scrnwdth,scrnht+80,"ultimate snake game");
//	
//
//}