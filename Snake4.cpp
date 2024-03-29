# include "iGraphics.h"
# include <math.h>
# include <stdlib.h>
# include <time.h>
# define widdth 10
# define scrnwdth 1280
# define scrnht 600
/*all imports*/

void Snakemove();
void snakeinitialize();

FILE *fpl,*fps;
int game=3,size=50,i,state=0,speed =10,used=0,end=0,spd=150,mazeno=0,level=3,signal=2,foodeaten=0,j=0,p=0,z;
int n=4,randm=234,exfood=0,extime,prsnttime;
int foodx=640,foody=300,exfoodx,exfoody;
int x[6000],y[6000],highcmp[5];

struct highscore{
		int lvl;
		int score;
	} hgh[5],hghd[5];


void highscorefit(int levelnow,int scorenow){
	FILE *fphigh,*fpcamp;
	int po;

	//scorenow=11,levelnow=4;

	fphigh=fopen("highscores.txt","r");
	fpcamp=fopen("camphigh.txt","r");
	for(po=0;po<5;po++){
		fscanf(fphigh,"%d%d",&(hgh[po].lvl),&(hgh[po].score));
	}

	fclose(fphigh);

	fphigh=fopen("highscores.txt","w");

	for(po=0;po<5;po++){
		if(hgh[po].lvl==levelnow){
			if(hgh[po].score<scorenow){
				hgh[po].score=scorenow;
			}
		}
			fprintf(fphigh,"%d %d\n",hgh[po].lvl,hgh[po].score);
	}

	fclose(fphigh);
}


int hsreturn(int level){
	FILE *fphigh;
	int a,b,c;
	fphigh=fopen("highscores.txt","r");
	for(c=1;c<=5;c++){
		fscanf(fphigh,"%d%d",&a,&b);
		if(a==level){
			fclose(fphigh);
			return b;
		}
	}
}

void loadgame(){
	//fflush(stdin);
	
	fpl=fopen("sav2.txt","r");
	if(fpl!=NULL){
	fscanf(fpl,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d ",&game,&size,&i,&state,&speed,&used,&end,&spd,&mazeno,&level,&signal,&foodeaten,&j,&p);
	fscanf(fpl,"%d %d %d %d %d ",&n,&randm,&exfood,&extime,&prsnttime);
	fscanf(fpl,"%d %d %d %d ",&foodx,&foody,&exfoodx,&exfoody);
	game = 0;
	for(i=0;i<size;i++){
		fscanf(fpl,"%d ",&x[i]);
	}
	for(i=0;i<size;i++){
		fscanf(fpl,"%d ",&y[i]);
	}
	}
	if(fpl!=NULL)
	fclose(fpl);
	iResumeTimer(0);
}

void savegame(){
	fps=fopen("sav2.txt","w");
	fprintf(fps,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d ",game,size,i,state,speed,used,end,spd,mazeno,level,signal,foodeaten,j,p);
	fprintf(fps,"%d %d %d %d %d ",n,randm,exfood,extime,prsnttime);
	fprintf(fps,"%d %d %d %d ",foodx,foody,exfoodx,exfoody);
	for(i=0;i<size;i++){
		fprintf(fps,"%d ",x[i]);
	}
	for(i=0;i<size;i++){
		fprintf(fps,"%d ",y[i]);
	}
	fclose(fps);
}


void random(){
	randm+=491;
	randm%=37983;
}


void statecheck()
{
	int temp,temp1;
	//iSetColor(100,100,100);
	//iFilledRectangle(212,453,200,400);
	//while(j<1){
	for(i=size;i>0;i--)
	{
		x[i]=x[i-1];
		y[i]=y[i-1];
	}

	if(state==0)//snake moving left
	{
		x[0]-=speed;
		if(x[0]<0)
			x[0]=scrnwdth-widdth;
	}

	else if(state==1)//up
	{
		y[0]+=speed;
		if((y[0]+widdth)>scrnht)
			y[0]=0;
	}

	else if(state==2)//down
	{
		y[0]-=speed;
		if(y[0]<0)
			y[0]=scrnht-widdth;
	}

	else if(state==3)//snake moving right
	{
		x[0]+=speed;
		if((x[0]+widdth)>scrnwdth)
			x[0]=0;
	}
	if(z==1){
		if((level==1 && foodeaten==20)||(level==2 && foodeaten==25)||(level==3 && foodeaten==30)||(level==4 && foodeaten==35)){
			temp=p;
			temp1=level;
			snakeinitialize();
			iPauseTimer(0);
			iPauseTimer(1);
			p=temp;
			level=temp1+1;
			game=9;
			
		}
		else if(level==5 && foodeaten==45){
			temp=p;
			temp1=level;
			snakeinitialize();
			iPauseTimer(0);
			iPauseTimer(1);
			p=temp;
			level=temp1+1;
			game=10;
			
		}
	}

	Snakemove();
	

	j++;
	}
	//j=0;
	//iDraw();


void genfood(){
	if(signal == 1){
		
	srand(time(NULL));
	foodx = ((((rand()*7)+85+randm+21*(int)foodx+56)%(scrnwdth-widdth))/widdth)*widdth;
	foody = ((((rand()*2)+12+randm+65*(int)foody+67)%(scrnht-widdth))/widdth)*widdth;
	for(i=size-1;i>=0;i--)
		if(x[i] == foodx && y[i] == foody){
			genfood();
			printf("Snake\n");
		}
	printf("%d %d\n",foodx,foody);
	signal = 0;
}
}
	
void genfood2(){
	if(exfood == 0){
	srand(time(NULL));
	exfoodx = ((((rand()*6)+67+randm+19*(int)exfoodx+67)%(scrnwdth-widdth))/widdth)*widdth;
	exfoody = ((((rand()*9)+23+randm+7*(int)exfoody+10)%(scrnht-widdth))/widdth)*widdth;
	for(i=size-1;i>=0;i--)
		if(x[i] == exfoodx && y[i] == exfoody){
			genfood2();
			//printf("Snake\n");
		
		}
		exfood = 1;
	}
	//printf("%d %d\n",foodx,foody);
	
}

void drawex(){
	static int rr=25,gg=135,bb=210;
	rr+=80;
	rr%=255;
	gg+=40;
	gg%=255;
	bb+=79;
	bb%=255;
	iSetColor(rr,gg,bb);
	iFilledRectangle(exfoodx,exfoody,widdth,widdth);
}

void drawfood(){
	if(level==1){
		iSetColor(146,0,141);
	}
	else if(level==2){
		iSetColor(28,241,17);
	}
	else if(level==3){
		iSetColor(253,67,53);
	}
	else if(level==4){
		iSetColor(30,8,239);
	}
	else if(level==5){
		iSetColor(18,240,7);
	}
	/*iFilledCircle(foodx+width/2,foody+width/2,width/2,width/2);
	iSetColor(0,0,0);
	iCircle(foodx+width/2,foody+width/2,width/2,width/2);*/
	iFilledRectangle(foodx,foody,widdth,widdth);
	iSetColor(0,0,0);
	iRectangle(foodx,foody,widdth,widdth);
}

void inctime(){
	prsnttime+=1;
	printf("%d\n",prsnttime);
}

void extrafood(){
	
	if(prsnttime >= extime ){
		prsnttime=0;
		exfood=2;
	}
	else{
		if(exfood!=1){
		genfood2();
		}
		drawex();
	}
}


void isdead()
{
	for(i=size-1;i>1;i--){
		if(x[0]==x[i] && ( y[0] == y[i]))
			end=1;
	}
	if(x[0]== foodx && y[0] == foody){
		prsnttime = 0;
		exfood=0;
		foodeaten++;
		signal=1;
		genfood();
		size+=1;
		p++;
		
	}

	if(exfood == 1){
	if(x[0]== exfoodx && y[0] == exfoody){        //score condition needed to be put here
		p+=10*(extime-prsnttime)/extime;
		exfood = 2;
		prsnttime = 0;
	}
	}
	
}

void mazedead(double mazex[],double mazey[],double mazedx[],double mazedy[]){
	for(i=0;i<mazeno;i++){
		if((x[0]+widdth)>mazex[i] && (x[0]<(mazex[i]+mazedx[i])) && (y[0]+widdth)>mazey[i] && (y[0]<(mazey[i]+mazedy[i])))
			end=1;
		if((foodx+widdth)>mazex[i] && (foodx<(mazex[i]+mazedx[i])) && (foody+widdth)>mazey[i] && (foody<(mazey[i]+mazedy[i]))){
			signal = 1;
			genfood();
		}
		if(exfood == 1){
		if((exfoodx+widdth)>mazex[i] && (exfoodx<(mazex[i]+mazedx[i])) && (exfoody+widdth)>mazey[i] && (exfoody<(mazey[i]+mazedy[i]))){
			exfood=0;
			genfood2();
			
		}

	}
}
}



void scoreshow(){
	int now,temp=p;
	//p=foodeaten;
	iShowBMP(scrnwdth-200,scrnht+40,"SCORE.bmp");
	iSetColor(0,0,0);
	iRectangle(scrnwdth-200,scrnht+40,200,40);
	//iSetColor(0,0,0);
	//iFilledRectangle(120,scrnht,scrnwdth-200,80);
	for(i=1;i<=5;i++){
		now=temp%10;
		if(now==0){
		iShowBMP(scrnwdth-40*i,scrnht,"zero.bmp");
		}
		else if(now==1){
			iShowBMP(scrnwdth-40*i,scrnht,"one.bmp");
		}
		else if(now==2){
			iShowBMP(scrnwdth-40*i,scrnht,"two.bmp");
		}
		else if(now==3){
			iShowBMP(scrnwdth-40*i,scrnht,"three.bmp");
		}
		else if(now==4){
			iShowBMP(scrnwdth-40*i,scrnht,"four.bmp");
		}
		else if(now==5){
			iShowBMP(scrnwdth-40*i,scrnht,"five.bmp");
		}
		else if(now==6){
			iShowBMP(scrnwdth-40*i,scrnht,"six.bmp");
		}
		else if(now==7){
			iShowBMP(scrnwdth-40*i,scrnht,"seven.bmp");
		}
		else if(now==8){
			iShowBMP(scrnwdth-40*i,scrnht,"eight.bmp");
		}
		else if(now==9){
			iShowBMP(scrnwdth-40*i,scrnht,"nine.bmp");
		}

		temp=temp/10;

		iSetColor(0,0,0);
		iRectangle(scrnwdth-40*i,scrnht,40,40);
	}
	if(z==0){
		iShowBMP(0,scrnht+40,"foodeaten.bmp");
	}
	else{
		iShowBMP(0,scrnht+40,"foodremaining.bmp");
	}
	iSetColor(0,0,0);
	iRectangle(0,scrnht+40,120,40);
	if(z==0){
		temp=foodeaten;
	}
	else{
		if(level==1){
			temp=20-foodeaten;
		}
		else if(level==2){
			temp=25-foodeaten;
		}
		else if(level==3){
			temp=30-foodeaten;
		}
		else if(level==4){
			temp=35-foodeaten;
		}
		else if(level==5){
			temp=45-foodeaten;
		}
	}

	for(i=1;i<=3;i++){
		now=temp%10;
		if(now==0){
		iShowBMP(120-40*i,scrnht,"zero.bmp");
		}
		else if(now==1){
			iShowBMP(120-40*i,scrnht,"one.bmp");
		}
		else if(now==2){
			iShowBMP(120-40*i,scrnht,"two.bmp");
		}
		else if(now==3){
			iShowBMP(120-40*i,scrnht,"three.bmp");
		}
		else if(now==4){
			iShowBMP(120-40*i,scrnht,"four.bmp");
		}
		else if(now==5){
			iShowBMP(120-40*i,scrnht,"five.bmp");
		}
		else if(now==6){
			iShowBMP(120-40*i,scrnht,"six.bmp");
		}
		else if(now==7){
			iShowBMP(120-40*i,scrnht,"seven.bmp");
		}
		else if(now==8){
			iShowBMP(120-40*i,scrnht,"eight.bmp");
		}
		else if(now==9){
			iShowBMP(120-40*i,scrnht,"nine.bmp");
		}

		temp=temp/10;

		iSetColor(0,0,0);
		iRectangle(120-40*i,scrnht,40,40);
	}

	iSetColor(247,148,28);
	iFilledRectangle(120,scrnht,scrnwdth-320,80);
}



void Snakemove()
{
	if(level==1){
		iSetColor(236,0,140);
	}
	else if(level==2){
	iSetColor(255,0,0);
	}
	else if(level==3){
		iSetColor(97,92,91);
	}
	else if(level==4){
		iSetColor(234,222,25);
	}
	else if(level==5){
		iSetColor(6,229,232);
	}

	isdead();

	for(i=size-1;i>=0;i--)
	{
		if(i==0){
				if(level==1){
					iSetColor(6,0,236);
				}
				else if(level==2){
					iSetColor(155,155,0);
				}
				else if(level==3){
					iSetColor(255,0,0);
				}
				else if(level==4){
					iSetColor(11,157,226);
				}
				else if(level==5){
					iSetColor(188,164,5);
				}
		}
		iFilledRectangle(x[i],y[i],widdth,widdth);
	
	}
	iSetColor(0,0,0);
	for(i=size-1;i>=0;i--){
		iRectangle(x[i],y[i],widdth,widdth);
	}
	if(end==1){
		 iPauseTimer(0);
		 iPauseTimer(1);
		 game=1;
	}
}


void maze_level_01(){
	iShowBMP(0,0,"mazelevel01.bmp");
	extime=16;
}

void maze_level_02(){
	 double mazex[]={0,0,0,scrnwdth-20};//4 rectangles
	 double mazey[]={0,0,scrnht-20,20};
	 double mazedx[]={scrnwdth,20,scrnwdth-20,20};
	 double mazedy[]={20,scrnht-20,20,scrnht-20};
	 extime = 12;
	 mazeno=4;
	 iShowBMP(0,0,"mazelevel02.bmp");
	  iSetColor(55,41,12);
	 for(i=0;i<mazeno;i++){
		 iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
	}
	mazedead(mazex,mazey,mazedx,mazedy);
}

void maze_level_03(){
	double mazex[]={((scrnwdth/3)),0,scrnwdth/1.5,scrnwdth/2};//4 rectangles
	double mazey[]={scrnht/3,scrnht/6,0,scrnht/1.2};
	double mazedx[]={20,scrnwdth/2,20,scrnwdth/2};
	double mazedy[]={scrnht/1.5,20,scrnht/1.5,20};
	iShowBMP(0,0,"mazelevel03.bmp");
	extime = 10;

	mazeno=4;
	iSetColor(42,90,201);
	for(i=0;i<mazeno;i++){
		iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
	}
	mazedead(mazex,mazey,mazedx,mazedy);
}

void maze_level_04(){
	double mazex[]={0,0,0,scrnwdth-20,0,scrnwdth-20,scrnwdth/10,9*scrnwdth/10,scrnwdth/5,scrnwdth/5};//10 rectangles
	double mazey[]={0,scrnht-20,0,0,7*scrnht/12,7*scrnht/12,scrnht/2.4,scrnht/2.4,(scrnht/2.4)-20,7*scrnht/12};
	double mazedx[]={scrnwdth,scrnwdth,20,20,20,20,20,20,3*scrnwdth/5,3*scrnwdth/5};
	double mazedy[]={20,20,scrnht/2.4,scrnht/2.4,scrnht/2.4,scrnht/2.4,scrnht/6,scrnht/6,20,20};
	extime = 8;
	mazeno=10;
	level=4;
	iShowBMP(0,0,"mazelevel04.bmp");
	iSetColor(35,234,25);
	for(i=0;i<mazeno;i++){
		iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
	}
	mazedead(mazex,mazey,mazedx,mazedy);
}

void maze_level_05(){
	double mazex[]={0.6*scrnwdth,0,0,0.4*scrnwdth,0.3*scrnwdth,0,0,0.6*scrnwdth};//8 rectangles
	double mazey[]={0,scrnht/3,scrnht/1.5,scrnht/1.5,scrnht-20,scrnht-40,scrnht-20,scrnht/1.5};
	double mazedx[]={20,scrnwdth,0.4*scrnwdth,20,0.55*scrnwdth,0.1*scrnwdth,0.2*scrnwdth,0.4*scrnwdth};
	double mazedy[]={scrnht/3,20,20,scrnht/3-20,20,20,20,20};
	extime = 8;
	mazeno=8;
	level=5;
	iShowBMP(0,0,"mazelevel05.bmp");
	iSetColor(220,239,7);
	for(i=0;i<mazeno;i++){
		iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
	}
	mazedead(mazex,mazey,mazedx,mazedy);
}

void highshow(){
	int a,sc,temp1,b,nw;
	iShowBMP(290,scrnht-160,"halloffame.bmp");
	iShowBMP(0,0,"backtomenu.bmp");
	iShowBMP(315,70,"level5.bmp");
	iShowBMP(315,140,"level4.bmp");
	iShowBMP(315,210,"level3.bmp");
	iShowBMP(315,280,"level2.bmp");
	iShowBMP(315,350,"level1.bmp");

	for(a=1;a<=5;a++){
		sc=hsreturn(6-a);
		temp1=sc;
		for(b=1;b<=5;b++){
			nw=temp1%10;
			if(nw==0){
				iShowBMP(865-40*b,70*a,"zero.bmp");
			}
			else if(nw==1){
				iShowBMP(865-40*b,70*a,"one.bmp");
			}
			else if(nw==2){
				iShowBMP(865-40*b,70*a,"two.bmp");
			}
			else if(nw==3){
				iShowBMP(865-40*b,70*a,"three.bmp");
			}
			else if(nw==4){
				iShowBMP(865-40*b,70*a,"four.bmp");
			}
			else if(nw==5){
				iShowBMP(865-40*b,70*a,"five.bmp");
			}
			else if(nw==6){
				iShowBMP(865-40*b,70*a,"six.bmp");
			}
			else if(nw==7){
				iShowBMP(865-40*b,70*a,"seven.bmp");
			}
			else if(nw==8){
				iShowBMP(865-40*b,70*a,"eight.bmp");
			}
			else if(nw==9){
				iShowBMP(865-40*b,70*a,"nine.bmp");
			}

			temp1=temp1/10;
		}
	}
}

void snakeinitialize(){
			foodeaten=0;
			p=0;
			for(i=0;i<size;i++){
				x[i]=200+speed*(i);
				y[i]=150;
			}
			size=50;
			state=0;
			speed=10;
			used=0;
			end=0;
			spd=150;
			signal=2;
			randm=234;
			exfood=0;
			iResumeTimer(0);
			iResumeTimer(1);

}



void iDraw()
{
	iClear();
	if(game ==0){// While playing the game
		if(level==1){
			maze_level_01();
		}
		else if(level==2){
			maze_level_02();
		}
		else if(level==3){
			maze_level_03();
		}
		else if(level==4){
			maze_level_04();
		}
		else if(level=5){
			maze_level_05();
		}
		//statecheck();////////
		if(foodeaten%5 == 0 && exfood!=2 &&foodeaten!=0){
			extrafood();
		}
		
		drawfood();
		Snakemove();
		

		iSetColor(0,0,0);
		iRectangle(0,0,scrnwdth,scrnht);

		/*iSetColor(0,0,0);
		iFilledRectangle(0,600,scrnwdth,80);*/

		scoreshow();
	}
	else if(game == 1)//Gameover interface
	{
		highscorefit(level,p);
		iClear();
		iShowBMP(0,0,"Gameover.bmp");
		iSetColor(0,0,0);
		iRectangle(0,0,scrnwdth,scrnht);
		scoreshow();
		iShowBMP(0,0,"backtomenu.bmp");
		iShowBMP(980,0,"exit.bmp");
	}
	else if ( game == 2)//Pause menu
	{
		iClear();
		iSetColor(255,50,0);
		iFilledRectangle(0,0,scrnwdth,scrnht);
		//iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(scrnwdth/2-150,scrnht/2-150,"Pause.bmp");
		iShowBMP(scrnwdth/2+40-150,scrnht/2-150+32,"pExit.bmp");
		iShowBMP(scrnwdth/2+40-150,scrnht/2-150+98,"Save.bmp");
		iShowBMP(scrnwdth/2+40-150,scrnht/2-150+163,"Resume.bmp");
		scoreshow();
		//iDelay(4);
		
	}

	else if(game==3){//main menu
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(80,scrnht-150,"name.bmp");
		iShowBMP(40,70,"exit.bmp");
		iShowBMP(40,140,"instructions.bmp");
		iShowBMP(40,210,"highscores.bmp");
		iShowBMP(40,280,"loadgame.bmp");
		iShowBMP(40,350,"newgame.bmp");
	}

	else if(game == 4){//Instructions
		iShowBMP(0,0,"maininstructions.bmp");//Change kora lagbe
		iShowBMP(0,0,"backtomenu.bmp");
	}
	else if(game==5){//Highscore select mode: classic or campaign
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(290,scrnht-160,"selectmode.bmp");
		iShowBMP(490,280,"campaign.bmp");
		iShowBMP(490,350,"classic.bmp");
		iShowBMP(0,0,"backtomenu.bmp");
	}
	else if(game==6){//Classic mode select level
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(290,scrnht-160,"selectlevel.bmp");
		iShowBMP(490,70,"level5.bmp");
		iShowBMP(490,140,"level4.bmp");
		iShowBMP(490,210,"level3.bmp");
		iShowBMP(490,280,"level2.bmp");
		iShowBMP(490,350,"level1.bmp");
		iShowBMP(0,0,"back.bmp");
	}
	else if(game==7){//Highscore display
		//your code here , with backtomenu
		iShowBMP(0,0,"mainmenu.bmp");

	}
	else if(game==8){//select mode for new game
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(290,scrnht-160,"selectmode.bmp");
		iShowBMP(490,280,"campaign.bmp");
		iShowBMP(490,350,"classic.bmp");
		iShowBMP(0,0,"backtomenu.bmp");
	}
	else if(game==9){//Level up display
		iShowBMP(0,0,"levelup.bmp");
		iShowBMP(340,50,"nextlevel.bmp");
	}
	else if(game==10){//Campaign mode winning display
		iShowBMP(0,0,"congratz.bmp");
		iShowBMP(0,0,"backtomenu.bmp");
	}
}


void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	//pause menu
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(game==2){
			if((mx>=scrnwdth/2-150+40 && mx<=(scrnwdth/2-150+297))){
			if(my>=scrnht/2-150+32 && my<= scrnht/2-150+32+52)
				game = 3;
			else if(my>=scrnht/2-150+98 && my<= scrnht/2-150+98+51)
				savegame();
			else if(my>=scrnht/2-150+163 && my<= scrnht/2-150+163+52){
				game = 0;
				iResumeTimer(0);
			}
		}
		}
		else if(game==3){
			if(mx>=40 && mx<=340){
				if(my>=70 && my<=120){
					exit(0);
				}
				else if(my>=140 && my<=190){
					game=4;
				}
				else if(my>=210 && my<=260){
					game=5;
				}
				else if(my>=280 && my<=330){
					loadgame();
				}
				else if(my>=350 && my<=400){
					game=8;
				}
			}
		}
		else if(game == 6){
			snakeinitialize();
			if(mx>=490 && mx<=790){
				if(my>=70 && my<=120){
					level=5;
					game=0;
				}
				else if(my>=140 && my<=190){
					level=4;
					game=0;
				}
				else if(my>=210 && my<=260){
					level=3;
					game=0;
				}
				else if(my>=280 && my<=330){
					level=2;
					game=0;
				}
				else if(my>=350 && my<=400){
					level=1;
					game=0;
				}
			}
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=8;
			}
		}
		else if(game==1){
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}
			else if((mx>= 980 && mx<=1280) && (my>=0 && my<=50)){
				exit(0);
			}
		}

		else if(game==4){
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}
		}

		else if(game==5){
			if(mx>=490 && mx<=790){
				if(my>=280 && my<=330){
					z=1;
					game=7;
				}
				else if(my>=350 && my<=400){
					z=0;
					game=7;
				}
			}
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}
		}
		else if(game==7){// mouse er kaj boshao
		}

		else if(game==8){
			if(mx>=490 && my<=790){
				if(my>=280 && my<=330){
					z=1;
					snakeinitialize();
					level=1;
					game=0;
				}
				else if(my>=350 && my<=400){
					z=0;
					game=6;
				}
			}

			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}
		}
		else if(game==9){
			if((mx>=340 && mx<=940) && (my>=50 && my<=100)){
				game=0;
				iResumeTimer(0);
				iResumeTimer(1);
			}
		}
		else if(game==10){
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}
			
		}
	}
	
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

//1-up,2-down , 3- right,0- left
void iKeyboard(unsigned char key)
{
	if(key == 'a')
	{
		if(state!=3 && state!= 0){
		state=0;
		//j=1;
		statecheck();
		isdead();
		}
	}
	else if( key == 'w')
		{

		if(state!=2 && state!=1){
		state = 1;
		//j = 1;
		statecheck();
		isdead();

		}
	}
	else if( key == 's')
		{
		if(state!=1 && state!=2){
		state = 2;
		//j =1 ;
		statecheck();
		isdead();

	}
	}
	else if( key == 'd')
		{if(state!=0 && state!=3){
		state = 3;
		//j= 1;
		statecheck();
		isdead();

	}
	}
	if(key == ';' && exfood == 1){        //cheat code 
		p+=10*(extime-prsnttime)/extime;
		exfood = 2;
		prsnttime = 0;
	}

	if(key == 'l'){
		loadgame();
	}
	if(key =='g'){
		savegame();
	}
	if(key == 'p')
	{
		//do something with 'q'
		if(game==0){
		iPauseTimer(0);
		game = 2;
		}
	}
	if(key == 'r'){
		if(game==2){
			game=0;
			iResumeTimer(0);
		}
	}

	if(key == 'c'){
		prsnttime = 0;
		exfood=0;
		foodeaten++;
		signal=1;
		genfood();
		size+=1;
		p++;
}
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_UP)
	{
		if(state!=2 && state!=1){
		state = 1;
		i = 1;
		statecheck();
		isdead();

		}	
	}
	else if(key== GLUT_KEY_DOWN)
	{
		if(state!=1 && state!=2){
		state = 2;
		i = 1;
		statecheck();
		isdead();
		}

	}
	else if(key== GLUT_KEY_LEFT)
	{
		if(state!=3 && state!= 0){
		state=0;
		statecheck();
		isdead();
		}

	}
	else if(key== GLUT_KEY_RIGHT)
	{
		if(state!=0 && state!=3){
		state = 3;
		i = 1;
		statecheck();
		isdead();
		}

	}

}



int main()
{
	for(i=0;i<size;i++)
	{
		x[i]=200+speed*(i);
		y[i]=150;
	}
	genfood();
	genfood2();
	iSetTimer(60,statecheck);
	iSetTimer(1,random);
	iSetTimer(500,inctime);
	iInitialize(scrnwdth,scrnht+80,"Ultimate Snake Game!");
	
}