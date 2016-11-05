 #include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'
#define MAXBODY 100

struct Food{
	int x,y,yes;
}food;

struct Snake{
	int x[MAXBODY],y[MAXBODY];
	int body;
	char direction,life;
}snake;

char map[21][21];

void delay(unsigned int z){
	unsigned int i,j;
	for(i=z;i>0;i--)
	for(j=110;j>0;j--);
}

void main(){
	printf("             hungry snake \n         press any key to start\n      tips:W=UP A=LEFT S=DOWN D=RIGHT");
	getch();
	game();
	getch(); 
}

int game(){
	char c;
	snake.x[1]=8;
	snake.x[2]=8;
	snake.x[3]=8;
	snake.y[1]=7;
	snake.y[2]=8;
	snake.y[3]=9;
	snake.body=3;
	snake.direction=UP;
	snake.life=1;
	while(snake.life==1){
	     makefood();
	     print();
	     if(kbhit())
	       c=getch();
	    if((snake.direction==UP||snake.direction==DOWN)&&(c==LEFT||c==RIGHT))
	       snake.direction=c;
	    if((snake.direction==LEFT||snake.direction==RIGHT)&&(c==UP||c==DOWN))
	       snake.direction=c;
	       delay(1000000);
		   move();
	    if(snake.x[1]==0||snake.y[1]==0||snake.x[1]==21||snake.y[1]==21)
	       snake.life=0;
	       int i;
	    for(i=2;i<=snake.body;i++){
	    	if(snake.x[1]==snake.x[i]&&snake.y[1]==snake.y[i])
	    	 snake.life=0;
	    }
	if (snake.body==49) {
	    printf("YOU WIN!");
	    return;}
	}
	printf("YOU DIED!\nGAMEOVER\n");
	printf("your score is %d",snake.body);
	return;
}
int makefood(){
	int random,i,sign;
	srand((unsigned int)(time(NULL)));
	if (food.yes==0){
		do{
		   random=(rand()%19+1);
		   food.x=random;
		   food.y=((random*random)%19+1);
		    for(i=1;i<=snake.body;i++){
			   if(food.x==snake.x[i]&&food.y==snake.y[i]) {
			   sign=1;
			   break;
			   }
			   else sign=0;
		    }
		}
		while(sign==1);}
	food.yes=1;
	return;
} 

int move(){
	int i,cancel=0;
	for(i=snake.body;i>=1;i--){
		snake.x[i+1]=snake.x[i];
		snake.y[i+1]=snake.y[i];
	}
	switch(snake.direction){
		case UP:{
			snake.y[1]--;
			break;
		}
		case DOWN:{
			snake.y[1]++;
			break;
		}
		case LEFT:{
			snake.x[1]--;
			break;
		}
		case RIGHT:{
			snake.x[1]++;
			break;
		}
	}
	if (snake.x[1]==food.x&&snake.y[1]==food.y){
		snake.body++;
		cancel=1;
		food.yes=0;
	}
	if(cancel==0){
		snake.x[snake.body+1]=0;
		snake.x[snake.body+1]=0;
	}
	return;
}

int print(){
    system("cls");
	int t;
	int i,j;
	for(t=0;t<=21;t++){
		map[0][t]='+';
		map[t][0]='+';
		map[21][t]='+';
		map[t][21]='+';
	}
	for(t=1;t<=snake.body;t++){
		map[snake.x[t]][snake.y[t]]='@';
	}
	map[food.x][food.y]='*';
	for(j=0;j<=21;j++){
		for(i=0;i<=21;i++)
		   printf("%c",map[i][j]);
		printf("\n");
	}
    for(j=0;j<=21;j++){
		for(i=0;i<=21;i++)
		map[i][j]=0;
	}
	return;
}




















