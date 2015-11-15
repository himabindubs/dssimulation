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
#define MENUMAX 4
#include "listfn.h"
#include "fn.h"

void drawmenu(int item) {
int c;
char mainmenu[] = "Main Menu";
char menu[MENUMAX][21] = {
/* 4 items for MENUMAX*/
"Stack",
"Queue",
"List",
"Quit"
};
clear();
addstr(mainmenu);
	for(c=0;c<MENUMAX;c++) {
		if( c==item )
		attron(A_REVERSE);
/* highlight selection */
		mvaddstr(3+(c*2),20,menu[c]);
		attroff(A_REVERSE);
/* remove highlight */
		mvaddstr(17,25,"Use arrow keys to move; Enter to select:");
		refresh();
	}
}
int main() {
	int key,menuitem;
	menuitem = 0;
	initscr();
	start_color();
	assume_default_colors(COLOR_WHITE,COLOR_MAGENTA);
	attron(A_BOLD);
	drawmenu(menuitem);
	keypad(stdscr,TRUE);
	noecho();
/* Disable echo */
	do {
		key = getch();
		switch(key) {
			case KEY_DOWN:
				menuitem++;
				if(menuitem > MENUMAX-1) menuitem = 0;
				break;
			case KEY_UP:
				menuitem--;
				if(menuitem < 0) menuitem = MENUMAX-1;
				break;
			default:
				break;
		}
	drawmenu(menuitem);
	} while(key!= '\n');
	echo();
/* re-enable echo */
/* At this point, the value of the selected menu is kept in the
menuitem variable. The program can branch off to whatever
subroutine
is required to carry out that function
*/
	if(key = '\n')
	{
		switch(menuitem) {
			case 0: accept_stack();	 ///in drawstack.c to draw a stack
				break;
			case 1: accept_queue();		///to draw a queue
				break;
			case 2: listmenu();	//goes to another menu having list functionalities
				break;
			case 3: break;	//exits the program
			default:
				break;
		}
	}
endwin();
return 0;
}



