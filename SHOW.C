#include <stdio.h>
#include "G:\tcl\rus\graph.c"
int fullstate[7]={1,2,2,2,4,4,4};
int pannel[XD][YD];
int xnow,ynow;
int num,state,cnow,cnum;
int _num,_state;
int top;
int highest=YD-1;
int score=0;
int basescore=0;
void showscore(){
	char str[10];
	int i;
	drawotherframe(X3,Y3);
	settextjustify(1,1);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(X3-40,Y3-40,X3+40,Y3+40);
	settextstyle(2,0,7);
	setcolor(BLUE);
	outtextxy(X3,Y3-20,"Score:");
	setcolor(GREEN);
	sprintf(str,"%d",score);
	outtextxy(X3,Y3+20,str);
}
void show00(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow+1,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow+1,ynow-1,cnow);
}
void show10(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow,ynow-2,cnow);
	drawbox(xnow,ynow-3,cnow);
}
void show11(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow-1,ynow,cnow);
	drawbox(xnow+1,ynow,cnow);
	drawbox(xnow+2,ynow,cnow);
}
void show20(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow-1,ynow-1,cnow);
	drawbox(xnow-1,ynow-2,cnow);
}
void show21(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow-1,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow+1,ynow-1,cnow);
}
void show30(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow+1,ynow-1,cnow);
	drawbox(xnow+1,ynow-2,cnow);
}
void show31(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow-1,ynow-1,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow+1,ynow,cnow);
}
void show40(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow+1,ynow-1,cnow);
	drawbox(xnow,ynow-2,cnow);
}
void show41(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow-1,ynow,cnow);
	drawbox(xnow+1,ynow,cnow);
}
void show42(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow-1,ynow-1,cnow);
	drawbox(xnow,ynow-2,cnow);
}
void show43(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow-1,ynow-1,cnow);
	drawbox(xnow+1,ynow-1,cnow);
}
void show50(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow,ynow-2,cnow);
	drawbox(xnow+1,ynow,cnow);
}
void show51(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow-1,ynow,cnow);
	drawbox(xnow+1,ynow,cnow);
	drawbox(xnow+1,ynow-1,cnow);
}
void show52(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow,ynow-2,cnow);
	drawbox(xnow-1,ynow-2,cnow);
}
void show53(){
	drawbox(xnow-1,ynow,cnow);
	drawbox(xnow-1,ynow-1,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow+1,ynow-1,cnow);
}
void show60(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow-1,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow,ynow-2,cnow);
}
void show61(){
	drawbox(xnow-1,ynow-1,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow+1,ynow-1,cnow);
	drawbox(xnow+1,ynow,cnow);
}
void show62(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow,ynow-1,cnow);
	drawbox(xnow,ynow-2,cnow);
	drawbox(xnow+1,ynow-2,cnow);
}
void show63(){
	drawbox(xnow,ynow,cnow);
	drawbox(xnow-1,ynow-1,cnow);
	drawbox(xnow-1,ynow,cnow);
	drawbox(xnow+1,ynow,cnow);
}
int check00(xpos,ypos){
	if( xpos<0 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<1 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos+1][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos-1]!=0 ) return 0;
	return 1;
}
int check10(xpos,ypos){
	if( xpos<0 || xpos>(XD-1) ) return 0;
	if( ypos>(YD-1) || ypos<3 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-2]!=0 ) return 0;
	if( pannel[xpos][ypos-3]!=0 ) return 0;
	return 1;
}
int check11(xpos,ypos){
	if( xpos<1 || xpos>(XD-1)-2 ) return 0;
	if( ypos>(YD-1) || ypos<0 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos-1][ypos]!=0 ) return 0;
	if( pannel[xpos+1][ypos]!=0 ) return 0;
	if( pannel[xpos+2][ypos]!=0 ) return 0;
	return 1;
}
int check20(xpos,ypos){
	if( xpos<1 || xpos>(XD-1) ) return 0;
	if( ypos>(YD-1) || ypos<2 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos-1][ypos-1]!=0 ) return 0;
	if( pannel[xpos-1][ypos-2]!=0 ) return 0;
	return 1;
}
int check21(xpos,ypos){
	if( xpos<1 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<1 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos-1][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos-1]!=0 ) return 0;
	return 1;
}
int check30(xpos,ypos){
	if( xpos<0 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<2 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos-2]!=0 ) return 0;
	return 1;
}
int check31(xpos,ypos){
	if( xpos<1 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<1 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos-1][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos]!=0 ) return 0;
	return 1;
}
int check40(xpos,ypos){
	if( xpos<0 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<2 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-2]!=0 ) return 0;
	return 1;
}
int check41(xpos,ypos){
	if( xpos<1 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<1 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos-1][ypos]!=0 ) return 0;
	if( pannel[xpos+1][ypos]!=0 ) return 0;
	return 1;
}
int check42(xpos,ypos){
	if( xpos<1 || xpos>(XD-1) ) return 0;
	if( ypos>(YD-1) || ypos<2 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos-1][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-2]!=0 ) return 0;
	return 1;
}
int check43(xpos,ypos){
	if( xpos<1 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<1 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos-1][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos-1]!=0 ) return 0;
	return 1;
}
int check50(xpos,ypos){
	if( xpos<0 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<2 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-2]!=0 ) return 0;
	if( pannel[xpos+1][ypos]!=0 ) return 0;
	return 1;
}
int check51(xpos,ypos){
	if( xpos<1 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<1 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos-1][ypos]!=0 ) return 0;
	if( pannel[xpos+1][ypos]!=0 ) return 0;
	if( pannel[xpos+1][ypos-1]!=0 ) return 0;
	return 1;
}
int check52(xpos,ypos){
	if( xpos<1 || xpos>(XD-1) ) return 0;
	if( ypos>(YD-1) || ypos<2 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-2]!=0 ) return 0;
	if( pannel[xpos-1][ypos-2]!=0 ) return 0;
	return 1;
}
int check53(xpos,ypos){
	if( xpos<1 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<1 )	return 0;
	if( pannel[xpos-1][ypos]!=0 ) return 0;
	if( pannel[xpos-1][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos-1]!=0 ) return 0;
	return 1;
}
int check60(xpos,ypos){
	if( xpos<1 || xpos>(XD-1) ) return 0;
	if( ypos>(YD-1) || ypos<2 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos-1][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-2]!=0 ) return 0;
	return 1;
}
int check61(xpos,ypos){
	if( xpos<1 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<1 )	return 0;
	if( pannel[xpos-1][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos-1]!=0 ) return 0;
	if( pannel[xpos+1][ypos]!=0 ) return 0;
	return 1;
}
int check62(xpos,ypos){
	if( xpos<0 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<2 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos][ypos-1]!=0 ) return 0;
	if( pannel[xpos][ypos-2]!=0 ) return 0;
	if( pannel[xpos+1][ypos-2]!=0 ) return 0;
	return 1;
}
int check63(xpos,ypos){
	if( xpos<1 || xpos>(XD-1)-1 ) return 0;
	if( ypos>(YD-1) || ypos<1 )	return 0;
	if( pannel[xpos][ypos]!=0 ) return 0;
	if( pannel[xpos-1][ypos-1]!=0 ) return 0;
	if( pannel[xpos-1][ypos]!=0 ) return 0;
	if( pannel[xpos+1][ypos]!=0 ) return 0;
	return 1;
}
void del00(){
	delbox(xnow,ynow);
	delbox(xnow+1,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow+1,ynow-1);
}
void del10(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow,ynow-2);
	delbox(xnow,ynow-3);
}
void del11(){
	delbox(xnow,ynow);
	delbox(xnow-1,ynow);
	delbox(xnow+1,ynow);
	delbox(xnow+2,ynow);
}
void del20(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow-1,ynow-1);
	delbox(xnow-1,ynow-2);
}
void del21(){
	delbox(xnow,ynow);
	delbox(xnow-1,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow+1,ynow-1);
}
void del30(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow+1,ynow-1);
	delbox(xnow+1,ynow-2);
}
void del31(){
	delbox(xnow,ynow);
	delbox(xnow-1,ynow-1);
	delbox(xnow,ynow-1);
	delbox(xnow+1,ynow);
}
void del40(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow+1,ynow-1);
	delbox(xnow,ynow-2);
}
void del41(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow-1,ynow);
	delbox(xnow+1,ynow);
}
void del42(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow-1,ynow-1);
	delbox(xnow,ynow-2);
}
void del43(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow-1,ynow-1);
	delbox(xnow+1,ynow-1);
}
void del50(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow,ynow-2);
	delbox(xnow+1,ynow);
}
void del51(){
	delbox(xnow,ynow);
	delbox(xnow-1,ynow);
	delbox(xnow+1,ynow);
	delbox(xnow+1,ynow-1);
}
void del52(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow,ynow-2);
	delbox(xnow-1,ynow-2);
}
void del53(){
	delbox(xnow-1,ynow);
	delbox(xnow-1,ynow-1);
	delbox(xnow,ynow-1);
	delbox(xnow+1,ynow-1);
}
void del60(){
	delbox(xnow,ynow);
	delbox(xnow-1,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow,ynow-2);
}
void del61(){
	delbox(xnow-1,ynow-1);
	delbox(xnow,ynow-1);
	delbox(xnow+1,ynow-1);
	delbox(xnow+1,ynow);
}
void del62(){
	delbox(xnow,ynow);
	delbox(xnow,ynow-1);
	delbox(xnow,ynow-2);
	delbox(xnow+1,ynow-2);
}
void del63(){
	delbox(xnow,ynow);
	delbox(xnow-1,ynow-1);
	delbox(xnow-1,ynow);
	delbox(xnow+1,ynow);
}
void write00(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow+1][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow+1][ynow-1]=cnum; 
	if( highest>ynow-1 ) highest=ynow-1;
}
void write10(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow][ynow-2]=cnum;
	pannel[xnow][ynow-3]=cnum; 
	if( highest>ynow-3 ) highest=ynow-3;
}
void write11(){
	pannel[xnow-1][ynow]=cnum;
	pannel[xnow][ynow]=cnum;
	pannel[xnow+1][ynow]=cnum;
	pannel[xnow+2][ynow]=cnum;
	if( highest>ynow ) highest=ynow;
}
void write20(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow-1][ynow-1]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow-1][ynow-2]=cnum; 
	if( highest>ynow-2 ) highest=ynow-2;
}
void write21(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow-1][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow+1][ynow-1]=cnum; 
	if( highest>ynow-1 ) highest=ynow-1;

}
void write30(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow+1][ynow-1]=cnum;
	pannel[xnow+1][ynow-2]=cnum; 
	if( highest>ynow-2 ) highest=ynow-2;
}
void write31(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow+1][ynow]=cnum;
	pannel[xnow-1][ynow-1]=cnum;
	pannel[xnow][ynow-1]=cnum; 
	if( highest>ynow-1 ) highest=ynow-1;
}
void write40(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow+1][ynow-1]=cnum;
	pannel[xnow][ynow-2]=cnum;
	if( highest>ynow-2 ) highest=ynow-2;
}
void write41(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow-1][ynow]=cnum;
	pannel[xnow+1][ynow]=cnum;
	if( highest>ynow-1 ) highest=ynow-1;
}
void write42(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow-1][ynow-1]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow][ynow-2]=cnum;
	if( highest>ynow-2 ) highest=ynow-2;
}
void write43(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow-1][ynow-1]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow+1][ynow-1]=cnum;
	if( highest>ynow-1 ) highest=ynow-1;
}
void write50(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow+1][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow][ynow-2]=cnum; 
	if( highest>ynow-2 ) highest=ynow-2;
}
void write51(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow-1][ynow]=cnum;
	pannel[xnow+1][ynow]=cnum;
	pannel[xnow+1][ynow-1]=cnum; 
	if( highest>ynow-1 ) highest=ynow-1;
}
void write52(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow-1][ynow-2]=cnum;
	pannel[xnow][ynow-2]=cnum;
	if( highest>ynow-2 ) highest=ynow-2;
}
void write53(){
	pannel[xnow-1][ynow]=cnum;
	pannel[xnow-1][ynow-1]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow+1][ynow-1]=cnum;
	if( highest>ynow-1 ) highest=ynow-1;
}
void write60(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow-1][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow][ynow-2]=cnum; 
	if( highest>ynow-2 ) highest=ynow-2;
}
void write61(){
	pannel[xnow+1][ynow]=cnum;
	pannel[xnow-1][ynow-1]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow+1][ynow-1]=cnum; 
	if( highest>ynow-1 ) highest=ynow-1;
}
void write62(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow][ynow-1]=cnum;
	pannel[xnow][ynow-2]=cnum;
	pannel[xnow+1][ynow-2]=cnum; 
	if( highest>ynow-2 ) highest=ynow-2;
}
void write63(){
	pannel[xnow][ynow]=cnum;
	pannel[xnow-1][ynow]=cnum;
	pannel[xnow+1][ynow]=cnum;
	pannel[xnow-1][ynow-1]=cnum; 
	if( highest>ynow-1 ) highest=ynow-1;
}
showother00(){
	drawotherbox(1,1);
	drawotherbox(2,1);
	drawotherbox(1,2);
	drawotherbox(2,2);
}
showother10(){
	drawotherbox(1,0);
	drawotherbox(1,1);
	drawotherbox(1,2);
	drawotherbox(1,3);
}
showother11(){
	drawotherbox(0,2);
	drawotherbox(1,2);
	drawotherbox(2,2);
	drawotherbox(3,2);
}
showother20(){
	drawotherbox(1,1);
	drawotherbox(1,2);
	drawotherbox(2,2);
	drawotherbox(2,3);
}
showother21(){
	drawotherbox(1,1);
	drawotherbox(2,1);
	drawotherbox(0,2);
	drawotherbox(1,2);
}
showother30(){
	drawotherbox(2,1);
	drawotherbox(1,2);
	drawotherbox(2,2);
	drawotherbox(1,3);
}
showother31(){
	drawotherbox(0,1);
	drawotherbox(1,1);
	drawotherbox(1,2);
	drawotherbox(2,2);
}
showother40(){
	drawotherbox(1,1);
	drawotherbox(1,2);
	drawotherbox(1,3);
	drawotherbox(2,2);
}
showother41(){
	drawotherbox(1,1);
	drawotherbox(0,2);
	drawotherbox(1,2);
	drawotherbox(2,2);
}
showother42(){
	drawotherbox(2,1);
	drawotherbox(1,2);
	drawotherbox(2,2);
	drawotherbox(2,3);
}
showother43(){
	drawotherbox(1,1);
	drawotherbox(2,1);
	drawotherbox(3,1);
	drawotherbox(2,2);
}
showother50(){
	drawotherbox(1,1);
	drawotherbox(1,2);
	drawotherbox(1,3);
	drawotherbox(2,3);
}
showother51(){
	drawotherbox(2,1);
	drawotherbox(0,2);
	drawotherbox(1,2);
	drawotherbox(2,2);
}
showother52(){
	drawotherbox(1,1);
	drawotherbox(2,1);
	drawotherbox(2,2);
	drawotherbox(2,3);
}
showother53(){
	drawotherbox(1,1);
	drawotherbox(2,1);
	drawotherbox(3,1);
	drawotherbox(1,2);
}
showother60(){
	drawotherbox(2,0);
	drawotherbox(2,1);
	drawotherbox(2,2);
	drawotherbox(1,2);
}
showother61(){
	drawotherbox(0,1);
	drawotherbox(1,1);
	drawotherbox(2,1);
	drawotherbox(2,2);
}
showother62(){
	drawotherbox(1,1);
	drawotherbox(1,2);
	drawotherbox(1,3);
	drawotherbox(2,1);
}
showother63(){
	drawotherbox(1,1);
	drawotherbox(1,2);
	drawotherbox(2,2);
	drawotherbox(3,2);
}

