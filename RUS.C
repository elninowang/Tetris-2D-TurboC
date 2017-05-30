#include "G:\tcl\rus\show.c"
int begin(){
	if( num==0)	return 1;
	if( num==1 ){
		if( state==0 )	return 3;
		else if( state==1 )	return 0;
	}
	if( num==2 ){
		if( state==0 )	return 2;
		if( state==1 )	return 1;
	}
	if( num==3 ){
		if( state==0 )	return 2;
		if( state==1 )	return 1;
	}
	if( num==4 ){
		if( state==0 )	return 2;
		if( state==1 )	return 1;
		if( state==2 )	return 2;
		if( state==3 )	return 1;
	}
	if( num==5 ){
		if( state==0 )	return 2;
		if( state==1 )	return 1;
		if( state==2 )	return 2;
		if( state==3 )	return 1;
	}
	if( num==6 ){
		if( state==0 )	return 2;
		if( state==1 )	return 1;
		if( state==2 )	return 2;
		if( state==3 )	return 1;
	}
}
int check(int __num,int __state,int xpos,int ypos){
	if( __num==0)	return check00(xpos,ypos);
	if( __num==1 ){
		if( __state==0 )	return check10(xpos,ypos);
		if( __state==1 )	return check11(xpos,ypos);
	}
	if( __num==2 ){
		if( __state==0 )	return check20(xpos,ypos);
		if( __state==1 )	return check21(xpos,ypos);
	}
	if( __num==3 ){
		if( __state==0 )	return check30(xpos,ypos);
		if( __state==1 )	return check31(xpos,ypos);
	}
	if( __num==4 ){
		if( __state==0 )	return check40(xpos,ypos);
		if( __state==1 )	return check41(xpos,ypos);
		if( __state==2 )	return check42(xpos,ypos);
		if( __state==3 )	return check43(xpos,ypos);
	}
	if( __num==5 ){
		if( __state==0 )	return check50(xpos,ypos);
		if( __state==1 )	return check51(xpos,ypos);
		if( __state==2 )	return check52(xpos,ypos);
		if( __state==3 )	return check53(xpos,ypos);
	}
	if( __num==6 ){
		if( __state==0 )	return check60(xpos,ypos);
		if( __state==1 )	return check61(xpos,ypos);
		if( __state==2 )	return check62(xpos,ypos);
		if( __state==3 )	return check63(xpos,ypos);
	}
}
void show(){
	if( num==0)	show00();
	if( num==1 ){
		if( state==0 )	show10();
		if( state==1 )	show11();
	}
	if( num==2 ){
		if( state==0 )	show20();
		if( state==1 )	show21();
	}
	if( num==3 ){
		if( state==0 )	show30();
		if( state==1 )	show31();
	}
	if( num==4 ){
		if( state==0 )	show40();
		if( state==1 )	show41();
		if( state==2 )	show42();
		if( state==3 )	show43();
	}
	if( num==5 ){
		if( state==0 )	show50();
		if( state==1 )	show51();
		if( state==2 )	show52();
		if( state==3 )	show53();
	}
	if( num==6 ){
		if( state==0 )	show60();
		if( state==1 )	show61();
		if( state==2 )	show62();
		if( state==3 )	show63();
	}
}
void del(){
	if( num==0)	del00();
	if( num==1 ){
		if( state==0 )	del10();
		if( state==1 )	del11();
	}
	if( num==2 ){
		if( state==0 )	del20();
		if( state==1 )	del21();
	}
	if( num==3 ){
		if( state==0 )	del30();
		if( state==1 )	del31();
	}
	if( num==4 ){
		if( state==0 )	del40();
		if( state==1 )	del41();
		if( state==2 )	del42();
		if( state==3 )	del43();
	}
	if( num==5 ){
		if( state==0 )	del50();
		if( state==1 )	del51();
		if( state==2 )	del52();
		if( state==3 )	del53();
	}
	if( num==6 ){
		if( state==0 )	del60();
		if( state==1 )	del61();
		if( state==2 )	del62();
		if( state==3 )	del63();
	}
}
int checkdown(){
	if( check(num,state,xnow,ynow+1)==1 )
		return 1;
	else return 0;
}
int checkleft(){
	if( check(num,state,xnow-1,ynow)==1 )
		return 1;
	else return 0;
}
int checkright(){
	if( check(num,state,xnow+1,ynow)==1 )
		return 1;
	else return 0;
}
int checkturn(){
	int tempstate;
	tempstate=(state>=fullstate[num]-1)?0:state+1;
	if( check(num,tempstate,xnow,ynow)==1 )
		return 1;
	else if( check(num,tempstate,xnow-1,ynow)==1 )
		return 2;
	else if( check(num,tempstate,xnow+1,ynow)==1 )
		return 3;
	else return 0;
}
void writepannel(){
	if( num==0)	write00();
	if( num==1 ){
		if( state==0 )	write10();
		if( state==1 )	write11();
	}
	if( num==2 ){
		if( state==0 )	write20();
		if( state==1 )	write21();
	}
	if( num==3 ){
		if( state==0 )	write30();
		if( state==1 )	write31();
	}
	if( num==4 ){
		if( state==0 )	write40();
		if( state==1 )	write41();
		if( state==2 )	write42();
		if( state==3 )	write43();
	}
	if( num==5 ){
		if( state==0 )	write50();
		if( state==1 )	write51();
		if( state==2 )	write52();
		if( state==3 )	write53();
	}
	if( num==6 ){
		if( state==0 )	write60();
		if( state==1 )	write61();
		if( state==2 )	write62();
		if( state==3 )	write63();
	}
}
void showother(){
	if( _num==0)	showother00();
	if( _num==1 ){
		if( _state==0 )	showother10();
		if( _state==1 )	showother11();
	}
	if( _num==2 ){
		if( _state==0 )	showother20();
		if( _state==1 )	showother21();
	}
	if( _num==3 ){
		if( _state==0 )	showother30();
		if( _state==1 )	showother31();
	}
	if( _num==4 ){
		if( _state==0 )	showother40();
		if( _state==1 )	showother41();
		if( _state==2 )	showother42();
		if( _state==3 )	showother43();
	}
	if( _num==5 ){
		if( _state==0 )	showother50();
		if( _state==1 )	showother51();
		if( _state==2 )	showother52();
		if( _state==3 )	showother53();
	}
	if( _num==6 ){
		if( _state==0 )	showother60();
		if( _state==1 )	showother61();
		if( _state==2 )	showother62();
		if( _state==3 )	showother63();
	}
}
void down(int row){
	int i,j;
	for( j=row;j>=highest;j-- ){
		for(i=0;i<XD;i++){
			delbox(i,j);
			if( j>0 )
				pannel[i][j]=pannel[i][j-1];
			else pannel[i][j]=0;
			drawbox(i,j,findcolor(pannel[i][j]) );
		}
	}
	highest++;
}
void makedown(){
	int flag=1;
	int max=0;
	int i,j;
	for(j=YD-1;j>=highest;j--){
		for( i=0;i<XD;i++ ){
			if( pannel[i][j]==0 ){
				flag=0;
				break;
			}
		}
		if( flag==1 ){
			down(j);
			max++;
			j++;
		}
		flag=1;
	}
	if( max==1 ) score+=SCORE1;
	else if( max==2 ) score+=SCORE2;
	else if( max==3 ) score+=SCORE3;
	else if( max==4 ) score+=SCORE4;
}

