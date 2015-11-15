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

#include<stdlib.h>
#include<string.h>
#include<ncurses.h>
#include"listfn.h"
#define N 8
#define MAX_COORD 115
char *cp2[N] = {NULL};
static int i2 = 0;
static int count = 0;
void l_draw();
void l_sort();
void l_exit();	
void l_append(char *str) {
	cp2[i2] = (char *)malloc(20);
	strcpy(cp2[i2], str);	//elements are appended. An array of char ptrs has been taken so as to generalise the input without user's knowledge i.e int and char will both be treated as a string. This makes handling of errors and code writing easy
	i2++;
	count++;	//count keeps a count of the nodes inserted
	l_draw();
	return;
}
void l_insert(char *str, int pos) {
	int i;
	cp2[i2] = (char *)malloc(20);
	i2++;
	count++;
	for(i = count - 1; i > pos; i--) {
		cp2[i] = cp2[i - 1];
	}
	cp2[pos] = str;
	initscr();
	clear();
	init_pair(1,COLOR_BLUE, COLOR_WHITE);
	init_pair(2,COLOR_BLACK, COLOR_WHITE);
	init_pair(3,COLOR_RED, COLOR_WHITE);
	start_color();
	border('!', '!', '-', '-', '*', '*', '*', '*');
	curs_set(0);
	attrset(A_BOLD);
	bkgd(COLOR_PAIR(1));
	mvprintw(5, 10, "LIST");
	int j = 0;
	for(i = 10; i <= MAX_COORD; i += 15) {
		if(cp2[j]) {				//draws a list only if the pos exits
			mvhline(10, i , '-', 10);
			mvhline(16, i , '-', 10);
			mvhline(13, i , '-', 10);//partition line
			mvaddch(13, i , ACS_ULCORNER);//pl
			mvaddch(13, i + 10, ACS_URCORNER);	//pl
			mvvline(10, i , '|', 6);
			mvvline(10, i + 10, '|', 6);
			mvaddch(10, i , ACS_ULCORNER);
			mvaddch(10, i + 10, ACS_URCORNER);	
			mvaddch(16, i , ACS_LLCORNER);
			mvaddch(16, i + 10, ACS_LRCORNER);
			mvhline(15, 11 + i , '-', 2);
			mvvline(9, 12 + i , '|', 6);
			mvaddch(15, i + 12, ACS_LRCORNER);
			mvhline(9, 12 + i , '-', 7);
			mvaddch(9, 12 + i , ACS_ULCORNER);
			mvaddch(9, i + 19, ACS_URCORNER);
		}
		j++;
	}
	refresh();
	i = 0;
	while(i < count) {
		if(i != pos) {	//prints all the non-matching elements
			attron(COLOR_PAIR(2));
			mvaddstr(11, 15 * (i + 1), cp2[i]);	
			attroff(COLOR_PAIR(2));
		}
		if(i == pos) {	//prints all the matching elements
			mvaddstr(7, 15, "The element has been inserted.");
			attron(COLOR_PAIR(3));
			mvaddstr(11, 15 * (i + 1), cp2[i]);	
			attroff(COLOR_PAIR(3));
		}	
		i++;	
	}
	refresh();
	getch();
	curs_set(1);
	attroff(COLOR_PAIR(1));
	listmenu();
	return;
}	
	
void l_remove(int pos) {
	int i;
	for(i = pos; i < count; i++) {
		cp2[i] = cp2[i + 1];
	}
	free(cp2[count - 1]);
	i2--;
	count--;	
	l_draw();
	return;
}
void l_sort() {
	int i, min, j, tmp;
	for(i = 0; i < count - 1; i++) {
		min = *cp2[i]; 
		for(j = i + 1; j < count; j++) {
			if(*cp2[j] < min) {
				tmp = *cp2[i];
				*cp2[i] = *cp2[j];
				*cp2[j] = tmp;
			}
		}
	}
	l_draw();
	return;
}				
void l_reverse() {
	refresh();
	int i;
	char *tmp;
	tmp = (char *)malloc(20);
	for(i = 0; i < count / 2; i++) {
		tmp = cp2[i];
		cp2[i] = cp2[count - i - 1];
		cp2[count - i - 1] = tmp;
		refresh();
	}
	l_draw();	
	return;
}	
void l_exit() {
	int i;
	for(i = 0; i < N; i++) {
		free(cp2[i]);
		cp2[i] = NULL;
	}
	count = 0;
	i2 = 0;	
	main();//to main fn
	return;
}	
void l_search(char *str) {
	initscr();
	clear();
	init_pair(1,COLOR_BLUE, COLOR_WHITE);
	init_pair(2,COLOR_BLACK, COLOR_WHITE);
	init_pair(3,COLOR_RED, COLOR_WHITE);
	start_color();
	border('!', '!', '-', '-', '*', '*', '*', '*');
	curs_set(0);
	attrset(A_BOLD);
	bkgd(COLOR_PAIR(1));
	mvprintw(5, 10, "LIST");
	int i, j = 0, found = 0;
	for(i = 10; i <= MAX_COORD; i += 15) {
		if(cp2[j]) {				//draws a list only if the pos exits
			mvhline(10, i , '-', 10);
			mvhline(16, i , '-', 10);
			mvhline(13, i , '-', 10);//partition line
			mvaddch(13, i , ACS_ULCORNER);//pl
			mvaddch(13, i + 10, ACS_URCORNER);	//pl
			mvvline(10, i , '|', 6);
			mvvline(10, i + 10, '|', 6);
			mvaddch(10, i , ACS_ULCORNER);
			mvaddch(10, i + 10, ACS_URCORNER);	
			mvaddch(16, i , ACS_LLCORNER);
			mvaddch(16, i + 10, ACS_LRCORNER);
			mvhline(15, 11 + i , '-', 2);
			mvvline(9, 12 + i , '|', 6);
			mvaddch(15, i + 12, ACS_LRCORNER);
			mvhline(9, 12 + i , '-', 7);
			mvaddch(9, 12 + i , ACS_ULCORNER);
			mvaddch(9, i + 19, ACS_URCORNER);
		}
		j++;
	}
	refresh();
	i = 0;
	while(i < count) {
		if(cp2[i] && strcmp(cp2[i], str) != 0) {	//prints all the non-matching elements
			attron(COLOR_PAIR(2));
			mvaddstr(11, 15 * (i + 1), cp2[i]);	
			attroff(COLOR_PAIR(2));
		}
		if(cp2[i] && strcmp(cp2[i], str) == 0) {	//prints all the matching elements
			mvaddstr(7, 15, "The element has been found. Highlighted in");
			attron(COLOR_PAIR(3));
			mvaddstr(7, 58, "RED");
			mvaddstr(11, 15 * (i + 1), cp2[i]);	
			attroff(COLOR_PAIR(3));
			found = 1;
		}	
		i++;	
	}
	if(!found)
		mvaddstr(7, 15, "The element has not been found."); 
	refresh();
	getch();
	curs_set(1);
	attroff(COLOR_PAIR(1));
	listmenu();
	return;
}	
			//here I have not actually used list data structure. I have stressed more on showing operations on lists.			
void l_draw() {		//l_draw is a multi-purpose fn which draws for append, remove and sort. It does not draw for search and insert because for those functions there is some 					difference in the way in which the elements are printed.		
	initscr();
	clear();
	init_pair(1,COLOR_BLUE, COLOR_WHITE);
	init_pair(2,COLOR_BLACK, COLOR_WHITE);
	start_color();
	border('!', '!', '-', '-', '*', '*', '*', '*');
	curs_set(0);
	attrset(A_BOLD);
	bkgd(COLOR_PAIR(1));
	move(5, 10);
	char text[] = "LIST";
	char *t;
	t = text; /* initialize NCurses */
	while(*t) {//loop through the whole string 
		addch(*t);
		t++;
		refresh();
		napms(100);
	}
	int i, j = 0;
	for(i = 10; i <= MAX_COORD; i += 15) {
		if(cp2[j]) {				//draws a list only if the pos exits
			mvhline(10, i , '-', 10);
			mvhline(16, i , '-', 10);
			mvhline(13, i , '-', 10);//partition line
			mvaddch(13, i , ACS_ULCORNER);//pl
			mvaddch(13, i + 10, ACS_URCORNER);	//pl
			mvvline(10, i , '|', 6);
			mvvline(10, i + 10, '|', 6);
			mvaddch(10, i , ACS_ULCORNER);
			mvaddch(10, i + 10, ACS_URCORNER);	
			mvaddch(16, i , ACS_LLCORNER);
			mvaddch(16, i + 10, ACS_LRCORNER);
			mvhline(15, 11 + i , '-', 2);
			mvvline(9, 12 + i , '|', 6);
			mvaddch(15, i + 12, ACS_LRCORNER);
			mvhline(9, 12 + i , '-', 7);
			mvaddch(9, 12 + i , ACS_ULCORNER);
			mvaddch(9, i + 19, ACS_URCORNER);
		}
		j++;
	}
	refresh();
	attron(COLOR_PAIR(2));
	i = 0;
	while(i < N) {
		if(cp2[i]) {
			mvaddstr(11, 15 * (i + 1), cp2[i]);	//prints all the existing elements
			
		}
		i++;	
	}		
	attroff(COLOR_PAIR(2));
	getch();
	curs_set(1);
	attroff(COLOR_PAIR(1));
	listmenu();
	return;
	
}
