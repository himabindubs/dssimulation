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
/* array a and i become global now */
#include "stack.h"
#include<stdlib.h>
#include<string.h>
void push(stack *s, char *str) {
	s->a[s->i] = (char*)malloc(20);
	strcpy(s -> a[s->i], str);
	s->i++;
}
char* pop(stack *s) {
	char *c = (char*)malloc(20);
	s->i--;
	c = s->a[s->i];
	return c;
}
/* This function gets added, because with a type declration, we can't do i = 0 */
void init(stack *s) {
	s->i = 0;
}
int empty(stack *s) {
	return s->i == 0;
}
int full(stack *s) {
	return s->i == 5;
}
