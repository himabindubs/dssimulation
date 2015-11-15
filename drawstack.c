
/*	
********* Copyright (C) Himabindu Boddupalli. himabindu.bs@gmail.com
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    ****************************************** */
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
int drawstack() {
	initscr();
	clear();
	border('!', '!', '-', '-', '*', '*', '*', '*');
	start_color();
	assume_default_colors(COLOR_WHITE, COLOR_MAGENTA);
	init_pair(1, COLOR_CYAN, COLOR_MAGENTA);
	init_pair(2, COLOR_YELLOW, COLOR_MAGENTA);
	init_pair(3, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(4, COLOR_RED, COLOR_MAGENTA);
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
	attron(COLOR_PAIR(1));
	for(j = 4; j > 0; j--) {
		mvprintw(yco1, xco1, cp[j]);
		yco1 += 2;
		refresh();	//all d element are printed first
	}
	attroff(COLOR_PAIR(1));
	for(i = 0; i < N; i++) {
		mvaddstr(yco1, xco1, "       ");		//elements are erased as they r pushed into the stack 		
		yco1 -= 2;	//we want d elems to printed at d same place
		mvaddstr(yco, xco, cp[i]);
		attron(COLOR_PAIR(3));
		mvprintw(yco, xco + 10, "%s  pushed", cp[i]);
		attroff(COLOR_PAIR(3));
		column1 -= 4;  
		yco = column1 + 1;
		refresh();
		napms(1000);//prints elements of a stack
	}///////////////for push
	attron(COLOR_PAIR(4));
	mvprintw(28, 25, "STACK FULL! PRESS ENTER TO POP THE ELEMENTS OUT");
	attroff(COLOR_PAIR(4));
	getch();
	mvprintw(28, 25, "                                               ");
	char *c;
	c = (char *)malloc(20);
	for(i = N - 1; i >= 0; i--) {
		mvaddstr(yco + 4, xco, "    ");
		if(!empty(&s))
			c = pop(&s);
		attron(COLOR_PAIR(2));
		mvprintw(yco + 4, xco + 10, "%s  popped", c);
		attroff(COLOR_PAIR(2));
		yco += 4;
		attron(COLOR_PAIR(1));
		mvprintw(yco1, xco1, c);
		attroff(COLOR_PAIR(1));
		yco1 += 2;//prints at d side. back to d list of elements
		refresh();
		getch();
	}
	attron(COLOR_PAIR(4));
	mvprintw(28, 35, "STACK EMPTY!");
	attroff(COLOR_PAIR(4));	
	curs_set(1); //comments to be removed later
	getch();//echoes, so needs an enter for next element to appear	
	clear();
	int k;
	for(k = 0; k < N; k++) {
		free(cp[k]);
		cp[k] = NULL;
	}
	row = 35;
	column = 20;
	yco = 21;	//yco and xco print elements in the queue
	xco = 40;
	column1 = 20;
	yco1 = 11;	//yco1 and xco1 print elements at the side
	xco1 = 20;
	main();
	endwin();
	return 0;
}
	
void accept_stack() {
	initscr();
	clear();
	char str[20];
	attron(A_BOLD);
	mvaddstr(10, 20, "Enter the 5 elements of the stack\n");
	keypad(stdscr, TRUE);
	refresh();
	echo();
	init(&s);
	while(i < N) {
		mvgetstr(12 + i, 30, str);
		cp[i] = (char*)malloc(20);
		strcpy(cp[i], str);
		refresh();
		if(!full(&s))
			push(&s, cp[i]);
		i++;
		
	}	
	endwin();
	drawstack();
	return;
}

