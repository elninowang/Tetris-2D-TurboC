#include <graphics.h>
#define	BOXLEC	20
#define	FRAMELEC	30
#define FRAMELEC1	20
#define	XD			10
#define	YD			20
#define	X1			319
#define	Y1			239
#define	X2			539
#define	Y2			79
#define	X3			539
#define	Y3			179
#define	X4			539
#define	Y4			279
#define	X5			539
#define	Y5			379
#define	X6			100
#define	Y6			30
#define	SCORE1	100
#define	SCORE2	300
#define	SCORE3	600
#define	SCORE4	1000
#define	PASSSCORE	1000
void graphset(){
	int graphdriver,graphmode;
	graphdriver=DETECT;
	initgraph(&graphdriver,&graphmode,"");
	cleardevice();
	setbkcolor(DARKGRAY);
}
int findcolor(int base){
	if( base==1 ) return BLUE;
	if( base==2 ) return YELLOW;
	if( base==3 ) return GREEN;
	if( base==4 ) return RED;
	else return DARKGRAY;
}
int oppsizecolor(int color){
	if( color==BLUE )
		return YELLOW;
	else if( color==YELLOW )
		return GREEN;
	else if( color==GREEN )
		return RED;
	else if( color==RED )
		return BLUE;
}
void drawbox(int xpos,int ypos,int color){
	int r=BOXLEC/2;
	int opcolor;
	int x,y;
	x=X1-r*XD;
	y=Y1-r*YD;
	opcolor=oppsizecolor(color);
	setcolor(opcolor);
	rectangle(x+xpos*BOXLEC+1,y+ypos*BOXLEC+1,x+(xpos+1)*BOXLEC-1,y+(ypos+1)*BOXLEC-1);
	setfillstyle(SOLID_FILL,color);
	bar(x+xpos*BOXLEC+3,y+ypos*BOXLEC+3,x+(xpos+1)*BOXLEC-3,y+(ypos+1)*BOXLEC-3);
}
void delbox(int xpos,int ypos){
	int r=BOXLEC/2;
	int opcolor;
	int x,y;
	x=X1-r*XD;
	y=Y1-r*YD;
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(x+xpos*BOXLEC,y+ypos*BOXLEC,x+(xpos+1)*BOXLEC,y+(ypos+1)*BOXLEC);
}
void drawframe(int x0,int y0){
	int left,right,up,down;
	left=x0-BOXLEC*XD/2;
	right=x0+BOXLEC*XD/2;
	up=y0-BOXLEC*YD/2;
	down=y0+BOXLEC*YD/2;
	setfillstyle(SOLID_FILL,BROWN);
	bar(left-FRAMELEC,up-FRAMELEC,left,down);
	bar(left-FRAMELEC,down,right,down+FRAMELEC);
	bar(right,up,right+FRAMELEC,down+FRAMELEC);
	bar(left,up-FRAMELEC,right+FRAMELEC,up);
}
void drawotherbox(int xpos,int ypos){
	int x=X2-2*BOXLEC;
	int y=Y2-2*BOXLEC;
	setcolor(BROWN);
	rectangle(x+xpos*BOXLEC+1,y+ypos*BOXLEC+1,x+(xpos+1)*BOXLEC-1,y+(ypos+1)*BOXLEC-1);
	setfillstyle(SOLID_FILL,WHITE);
	bar(x+xpos*BOXLEC+3,y+ypos*BOXLEC+3,x+(xpos+1)*BOXLEC-3,y+(ypos+1)*BOXLEC-3);
}
void delotherframe(){
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(X2-40,Y2-40,X2+40,Y2+40);
}
void drawotherframe(int xn,int yn){
	int left,right,up,down;
	left=xn-40;
	right=xn+40;
	up=yn-40;
	down=yn+40;
	setfillstyle(SOLID_FILL,MAGENTA);
	bar(left-FRAMELEC1,up-FRAMELEC1,left,down);
	bar(left-FRAMELEC1,down,right,down+FRAMELEC1);
	bar(right,up,right+FRAMELEC1,down+FRAMELEC1);
	bar(left,up-FRAMELEC1,right+FRAMELEC1,up);
}

void makemenu(int which){
	setcolor(BLUE);
	outtextxy(X6,Y6,"Resume Game");
	outtextxy(X6,Y6*2,"Restart");
	outtextxy(X6,Y6*3,"Change Speed");
	outtextxy(X6,Y6*4,"Exit");
	setcolor(LIGHTBLUE);
	if( which==1 ) outtextxy(X6,Y6,"Resume Game");
	if( which==2 ) outtextxy(X6,Y6*2,"Restart");
	if( which==3 ) outtextxy(X6,Y6*3,"Change Speed");
	if( which==4 ) outtextxy(X6,Y6*4,"Exit");
}