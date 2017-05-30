#include "g:\tcl\rus\rus.c"
#include "dos.h"
#define programsize 4000
#define ESC 	0x01
#define LEFT	0x4B
#define RIGHT	0x4D
#define DOWN	0x50
#define UP		0x48
#define ENTER  0x1c
#define SPACE	0x39
#define TEMPTIME	1
void interrupt (*oldint)();
void interrupt newint();
void install();
void on_time();
static struct SREGS seg;
int TIME=17;
int b=0;
int myss,stack;
int intsp,intss;
int busy=0;
int time=17;
int temp[7]={0,0,0,0,0,0,0};
int ipos=0;
int running=1;
int keydown=0;

int getkey(){
	union REGS rg;
	rg.h.ah=0;
	int86(0x16,&rg,&rg);
	return rg.h.ah;
}
void showspeed(){
	char str[5];
	int speed;
	drawotherframe(X4,Y4);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(X4-40,Y4-40,X4+40,Y4+40);
	setcolor(LIGHTGREEN);
	outtextxy(X4,Y4-20,"Speed:");
	setcolor(YELLOW);
	speed=9-(TIME-1)/2;
	sprintf(str,"%d",speed);
	outtextxy(X4,Y4+20,str);
}
void showstatus(){
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(X5-40,Y5-40,X5+40,Y5+40);
	setcolor(WHITE);
	outtextxy(X5,Y5-20,"Status:");
	if( highest>YD*2/3 ){
		setcolor(GREEN);
		outtextxy(X5,Y5+20,"Safe");
	}
	else if( highest<YD/3 ){
		setcolor(RED);
		outtextxy(X5,Y5+20,"Dange");
		outtextxy(X5-1,Y5+19,"Dange");
	}
	else{
		setcolor(YELLOW);
		outtextxy(X5,Y5+20,"Care");
	}
}
void dlg(int,int,char *);
void fail(){
	running=0;
	dlg(BLUE,RED,"Dead!Press ESC.");
}
void dlg(int bkcolor,int fontcolor,char str[]){
	setcolor(fontcolor);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(0,439-5*Y6-40,X6+80,439-Y6*5+40);
	outtextxy(X6,439-5*Y6,str);
/*
	setcolor(WHITE);
	rectangle(X1-100,Y1-40,X1+100,Y1+40);
	rectangle(X1-99,Y1-39,X1+99,Y1+39);
	rectangle(X1-98,Y1-38,X1+98,Y1+38);
	setfillstyle(SOLID_FILL,bkcolor);
	bar(X1-97,Y1-37,X1+97,Y1+37);
	setcolor(fontcolor);
	outtextxy(X1,Y1,str);
*/
}
void redlg(){
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(0,439-5*Y6-40,X6+80,439-5*Y6+40);
}
int getrank(int status){
	if( status==-1 ){
		ipos=(ipos>=6)?0:(++ipos);
		return ipos;
	}
	else{
		temp[status]=(temp[status]>=(fullstate[status]-1))?0:(++temp[status]);
		return temp[status];
	}
}
int domenu(){
	int which;
	int key;
	if( running==0 ) which=2;
	else which=1;
	makemenu(which);
	key=getkey();
	while(1){
		switch(key){
			case UP:
				which=(which<=1)?4:--which;
				makemenu(which);
				break;
			case DOWN:
				which=(which>=4)?1:++which;
				makemenu(which);
				break;
			case ESC:
				if( running==0 ){
					dlg(BLUE,YELLOW,"Can't Resume");
					getkey();
					redlg();
				}
				else{
					makemenu(0);
					install(newint);
					return;
				}
				break;
			case ENTER:
				if( which==1 ){
					if( running==0 ){
						dlg(BLUE,YELLOW,"Can't Resume");
						getkey();
						redlg();
					}
					else{
						makemenu(0);
						install(newint);
						return;
					}
				}
				else if( which==2 ){
					int i,j;
					for(i=0;i<XD;i++)
						for(j=0;j<YD;j++){
							pannel[i][j]=0;
							delbox(i,j);
						}
					TIME=17;
					num=getrank(-1);
					state=getrank(num);
					_num=getrank(-1);
					_state=getrank(_num);
					xnow=4;
					ynow=begin();
					TIME=17;
					time=TIME;
					running=1;
					highest=19;
					score=0;
					delotherframe();
					showother();
					showspeed();
					showscore();
					showstatus();
					install(newint);
					makemenu(0);
					return;
				}
				else if( which==3 ){
					char str[10];
					dlg(WHITE,WHITE,"Speed:");
					key=getkey();
					while( key<0x01 || key>0x0a )
						key=getkey();
					if( key!=ESC ){
						sprintf(str,"Speed: %d",key-1);
						time=(9-(key-1))*2+1;
						TIME=time;
						showspeed();
						b=0;
						dlg(WHITE,WHITE,str);
					}
					else redlg();
				}
				else if( which==4 ){
					closegraph();
					exit(0);
				}
				break;
		}
		key=getkey();
	}
}
void main(){
	int key;
	char *p;
	int i,j;
	graphset();
	for( i=0;i<XD;i++)
		for( j=0;j<YD;j++)
			pannel[i][j]=0;
	num=getrank(-1);
	state=getrank(num);
	_num=getrank(-1);
	_state=getrank(_num);
	drawframe(X1,Y1);
	drawotherframe(X2,Y2);
	drawotherframe(X5,Y5);
	cnum=1;
	cnow=findcolor(cnum);
	xnow=4;
	ynow=begin();
	show();
	showother();
	showscore();
	showspeed();
	showstatus();
	makemenu(0);
	p=(char *)newint;
	on_time(p);
	while(1){
		int flag;
		install( newint );
		key=getkey();
		switch(key){
			case LEFT:
				disable();
				if( checkleft()==1 ){
					del();
					xnow--;
					show();
				}
				enable();
				break;
			case RIGHT:
				disable();
				if( checkright()==1 ){
					del();
					xnow++;
					show();
				}
				enable();
				break;
			case SPACE:
				disable();
				if( flag=checkturn() ){
					del();
					state=(state>=fullstate[num]-1)?0:(++state);
					if( flag==2 ) xnow--;
					if( flag==3 ) xnow++;
					show();
				}
				enable();
				break;
			case DOWN:
				disable();
				if( keydown==0 ){
					b=0;
					time=TEMPTIME;
					keydown=1;
				}
				else{
					b=0;
					time=TIME;
					keydown=0;
				}
				enable();
				break;
			case ESC:
				install(oldint);
				if( running==0 )
					 redlg();
				domenu();
				break;
		}
	}
}
void on_time(int (*p)() ){
	segread(&seg);
	stack=programsize*16;
	myss=_SS;
	oldint=getvect(0x1c);
}
void install(void interrupt(*faddr)() ){
	disable();
	setvect(0x1c,faddr);
	enable();
}
void interrupt newint(){
	(*oldint)();
	if( busy==0 && running==1 ){
		busy=1;
		disable();
		intss=_SS;
		intsp=_SP;
		_SS=myss;
		_SP=stack;
		enable();
		b+=1;
		if( b==time ){
			if( checkdown()==1 ){
				del();
				ynow++;
				show();
			}
			else{
				writepannel();
				if( highest<=0 ) fail();
				makedown();
				showscore();
				showstatus();
				if( score>=basescore+PASSSCORE ){
					basescore+=PASSSCORE;
					if( TIME>2 ) TIME-=2;
					showspeed();
				}
				num=_num;
				state=_state;
				(cnum==4)?cnum=1:cnum++;
				cnow=findcolor(cnum);
				_num=getrank(-1);
				_state=getrank(_num);
				xnow=4;
				ynow=begin();
				if( check(num,state,xnow,ynow)==0 )
					fail();
				show();
				delotherframe();
				showother();
				keydown=0;
				time=TIME;
			}
			b=0;
		}
		disable();
		_SP=intsp;
		_SS=intss;
		enable();
		busy=0;
	}
}