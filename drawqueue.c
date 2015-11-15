

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
#include"queue.h"
#define N 5
queue q;
char *cp1[N] = {NULL};
int i1 = 0, j;
static int row = 35;
static int column = 20;
static int yco = 21;	//yco and xco print elements in the queue
static int xco = 40;
static int column1 = 20;
static int yco1 = 11;	//yco1 and xco1 print elements at the side
static int xco1 = 20;		 
int drawqueue() {
	initscr();
	clear();
	border('!', '!', '-', '-', '*', '*', '*', '*');
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_MAGENTA);
	init_pair(2, COLOR_YELLOW, COLOR_MAGENTA);
	init_pair(3, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(4, COLOR_RED, COLOR_MAGENTA);
	attrset(A_BOLD);
	curs_set(0);
	mvaddstr(20, 10, "QUEUE");
	for(i1 = 0; i1 < N; i1++) {			
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
	attron(COLOR_PAIR(1));
	for(j = 4; j > 0; j--) {
		mvprintw(yco1, xco1, cp1[j]);
		yco1 += 2;
		refresh();	//all d element are printed first at the side
	}
	attroff(COLOR_PAIR(1));
	for(i1 = 0; i1 < N; i1++) {
		mvaddstr(yco1, xco1, "       ");		//elements are erased as they r pushed into the queue		
		yco1 -= 2;	//we want d elems to printed at d same place
		mvaddstr(yco, xco, cp1[i1]);
		attron(COLOR_PAIR(3));
		mvprintw(yco, xco + 10, "%s  enqueued", cp1[i1]);
		attroff(COLOR_PAIR(3));		
		column1 -= 4;  
		yco = column1 + 1;
		refresh();
		napms(1000);//prints elements of a queue
	}///////////////for enqueue
	attron(COLOR_PAIR(4));
	mvprintw(28, 25, "QUEUE FULL! PRESS ENTER TO DEQUEUE THE ELEMENTS");
	attroff(COLOR_PAIR(4));
	getch();
	mvprintw(28, 25, "                                               ");
	char *c;
	c = (char *)malloc(20);
	yco = 21;
	xco = 40;
	yco1 = 21;
	xco1 = 20;
	for(i1 = 0; i1 < N; i1++) {
		mvaddstr(yco, xco, "    ");
		if(!qempty(&q))
			c = dequeue(&q);
		attron(COLOR_PAIR(2));	
		mvprintw(yco, xco + 10, "%s  dequeued", cp1[i1]);
		attroff(COLOR_PAIR(2));
		yco -= 4;
		attron(COLOR_PAIR(1));
		mvprintw(yco1, xco1, cp1[i1]);
		attroff(COLOR_PAIR(1));
		yco1 -= 2;
		refresh();
		getch();
	}
	attron(COLOR_PAIR(4));
	mvprintw(28, 35, "QUEUE EMPTY!");
	attroff(COLOR_PAIR(4));
	curs_set(1); 
	getch();//echoes, so needs an enter for next element to appear	
	clear();
	int k;
	for(k = 0; k < N; k++) {
		free(cp1[k]);
		cp1[k] = NULL;
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
	
int accept_queue() {		//accepts the values from the user as elements for the queue
	initscr();
	clear();
	char str[20];
	attron(A_BOLD);
	mvaddstr(10, 20, "Enter the 5 elements of the queue\n");
	keypad(stdscr, TRUE);
	refresh();
	echo();
	while(i1 < N) {
		mvgetstr(12 + i1, 30, str);
		cp1[i1] = (char*)malloc(20);
		strcpy(cp1[i1], str);
		refresh();
		if(!qfull(&q))
			enqueue(&q, cp1[i1]);
		i1++;
	}	
	drawqueue();
	endwin();
	return 0;
}

