#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"
#define N 5
queue q;
char *cp[N] = {NULL};
int i = 0, j;
static int row = 35;
static int column = 20;
static int yco = 21;
static int xco = 40;
static int column1 = 20;
static int yco1 = 11;
static int xco1 = 20;		 
int draw() {
	initscr();
	clear();
	border('!', '!', '-', '-', '*', '*', '*', '*');
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	attrset(A_BOLD);
	curs_set(0);
	mvaddstr(20, 10, "QUEUE");
	for(i = 0; i < N; i++) {			
		mvvline(column, row, '|', 4);
		mvhline(column + 4, row + 1 , '-', 10);//hline draws from current cursor pos
		mvvline(column, row + 11, '|', 4);
		mvaddch(column + 4, row, ACS_LLCORNER);
    		mvaddch(column + 4, row + 11, ACS_LRCORNER);
    		column -= 4;  
		//draws a QUEUE
	}
	refresh();
	napms(1000);
	for(j = 4; j > 0; j--) {
		mvprintw(yco1, xco1, cp[j]);
		yco1 += 2;
		refresh();	//all d element are printed first
	}
	for(i = 0; i < N; i++) {
		mvaddstr(yco1, xco1, "       ");		//elements are erased as they r pushed into the queue		
		yco1 -= 2;	//we want d elems to printed at d same place
		mvaddstr(yco, xco, cp[i]);
		mvprintw(yco, xco + 10, "%s  enqueued", cp[i]);		
		column1 -= 4;  
		yco = column1 + 1;
		refresh();
		napms(1000);//prints elements of a queue
	}///////////////for enqueue
	mvprintw(28, 25, "QUEUE FULL! PRESS ENTER TO DEQUEUE THE ELEMENTS");
	getch();
	mvprintw(28, 25, "                                               ");
	char *c;
	c = (char *)malloc(20);
	yco = 21;
	xco = 40;
	yco1 = 21;
	xco1 = 20;
	for(i = 0; i < N; i++) {
		mvaddstr(yco, xco, "    ");
		if(!qempty(&q))
			c = dequeue(&q);
		mvprintw(yco, xco + 10, "%s  dequeued", cp[i]);
		yco -= 4;
		mvprintw(yco1, xco1, cp[i]);
		yco1 -= 2;
		refresh();
		getch();
	}
	mvprintw(28, 35, "QUEUE EMPTY!");
	curs_set(1); //comments to be removed later
	getch();//echoes, so needs an enter for next element to appear	
	clear();
	endwin();
	return 0;
}
	
int main() {
	char str[20];
	printf("enter the elements of the queue\n");
	while(i < N) {
		scanf("%s", str);
		cp[i] = (char*)malloc(20);
		strcpy(cp[i], str);
		if(!qfull(&q))
			enqueue(&q, cp[i]);
		i++;
	}	
	draw();
	return 0;
}

