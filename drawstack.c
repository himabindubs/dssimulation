#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#define N 5
stack s;
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
	init_pair(1, COLOR_RED, COLOR_WHITE);
	attron(5);
	attrset(A_BOLD);
	curs_set(0);
	mvprintw(20, 10, "STACK");
	for(i = 0; i < N; i++) {			
		mvvline(column, row, '|', 4);
		mvhline(column + 4, row + 1 , '-', 10);//hline draws from current cursor pos
		mvvline(column, row + 11, '|', 4);
		mvaddch(column + 4, row, ACS_LLCORNER);
    		mvaddch(column + 4, row + 11, ACS_LRCORNER);
    		column -= 4;  
		//draws a stack
	}
	refresh();
	napms(1000);
	for(j = 4; j > 0; j--) {
		mvprintw(yco1, xco1, cp[j]);
		yco1 += 2;
		refresh();	//all d element are printed first
	}
	for(i = 0; i < N; i++) {
		mvaddstr(yco1, xco1, "       ");		//elements are erased as they r pushed into the stack 		
		yco1 -= 2;	//we want d elems to printed at d same place
		mvaddstr(yco, xco, cp[i]);
		mvprintw(yco, xco + 10, "%s  pushed", cp[i]);		
		column1 -= 4;  
		yco = column1 + 1;
		refresh();
		napms(1000);//prints elements of a stack
	}///////////////for push
	mvprintw(28, 25, "STACK FULL! PRESS ENTER TO POP THE ELEMENTS OUT");
	getch();
	mvprintw(28, 25, "                                               ");
	char *c;
	c = (char *)malloc(20);
	for(i = N - 1; i >= 0; i--) {
		mvaddstr(yco + 4, xco, "    ");
		if(!empty(&s))
			c = pop(&s);
		mvprintw(yco + 4, xco + 10, "%s  popped", c);
		yco += 4;
		mvprintw(yco1, xco1, c);
		yco1 += 2;//prints at d side. back to d list of elements
		refresh();
		getch();
	}
	mvprintw(28, 35, "STACK EMPTY!");
	curs_set(1); //comments to be removed later
	getch();//echoes, so needs an enter for next element to appear	
	clear();
	endwin();
	return 0;
}
	
int main() {
	char str[20];
	printf("enter the elements of the stack\n");
	while(i < N) {
		scanf("%s", str);
		cp[i] = (char*)malloc(20);
		strcpy(cp[i], str);
		if(!full(&s))
			push(&s, cp[i]);
		i++;
	}	
	draw();
	return 0;
}

