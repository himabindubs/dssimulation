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

#include <ncurses.h>
#include<stdlib.h>
#include"listfn.h"
#define MENUMAX1 7
#define N 5
void l_sort();
void l_exit();
void drawlistmenu(int item1) {
int c1;
char mainmenu1[] = "List Menu";
char menu1[MENUMAX1][21] = {
/* 7 items for MENUMAX1*/
"Append",
"Insert",
"Delete",
"Search",
"Reverse",
"Sort",
"Back to main menu"
};
clear();
addstr(mainmenu1);
	for(c1=0;c1<MENUMAX1;c1++) {
		if( c1==item1 )
		attron(A_REVERSE);
/* highlight selection */
		mvaddstr(3+(c1*2),20,menu1[c1]);
		attroff(A_REVERSE);
/* remove highlight */
		mvaddstr(17,25,"Use arrow keys to move; Enter to select:");
		refresh();
	}
}
int listmenu() {
	int key, menuitem1, i;
	menuitem1 = 0;
	initscr();
	start_color();
	assume_default_colors(COLOR_WHITE,COLOR_MAGENTA);
	attron(A_BOLD);
	drawlistmenu(menuitem1);
	noecho();
/* Disable echo */
	do {
		key = getch();
		switch(key) {
			case KEY_DOWN:
				menuitem1++;
				if(menuitem1 > MENUMAX1-1) menuitem1 = 0;
				break;
			case KEY_UP:
				menuitem1--;
				if(menuitem1 < 0) menuitem1 = MENUMAX1-1;
				break;
			default:
				break;
		}
	drawlistmenu(menuitem1);
	} while(key!= '\n');
	echo();
/* re-enable echo */
/* At this point, the value of the selected menu is kept in the
menuitem variable. The program can branch off to whatever
subroutine
is required to carry out that function
*/
char str[10];
int pos;	
	if(key = '\n')
	{	clear();
		switch(menuitem1) {
			case 0:	
				mvaddstr(10, 20, "Enter the charactar/integer you want to append");
				mvgetstr(12, 25, str);
				l_append(str);
				break;
			case 1:
				mvaddstr(10, 20, "Enter the position where you want to insert");
				move(12, 25);
				scanw("%d", &pos);
				mvaddstr(15, 20, "Enter the charactar/integer you want to insert");
				mvgetstr(17, 25, str);
				l_insert(str, pos);
				break;	
			case 2: 
				mvaddstr(10, 20, "Enter the position at which you want the list to be deleted.");
				move(12, 25);
				scanw("%d", &pos);
				l_remove(pos);
				break;
			case 3: 
				mvaddstr(10, 20, "Enter the charactar/integer you want to search");
				mvgetstr(12, 25, str); 
				l_search(str);
				break;
			case 4: 
				l_reverse();	 
				 break;	
			case 5:
				l_sort();
				break;	 
			case 6: 
				l_exit();
				break;
			default:
				break;
	}
}
endwin();
return 0;
}
