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
#include <stdlib.h>
#include <string.h>
#include "queue.h"
void enqueue(queue *q, char *str) {
	q->a[q->i] = (char*)malloc(20);
	strcpy(q -> a[q->i], str);
	q->i++;			//i's index inc. with every enqueue
}
char* dequeue(queue *q) {
	char *c = (char*)malloc(20);
	if(q->a[q->i] > q->a[q->j]) {
		strcpy(c, q->a[q->j]);
		q->j++;
	}			//j's index inc. with every dequeue
	return c;
}
void qinit(queue *q) {
	q->i = 0;
	q->j = 0;
}
int qempty(queue *q) {
	return q->j == 5 || q->i == 0 ||  q->i == q->j;
}
int qfull(queue *q) {
	return q->i == 5;
}
