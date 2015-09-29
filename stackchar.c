/* array a and curr become global now */
#include "stackchar.h"
void push(stack *s, char c) {
	s->a[s->curr] = c;
	s->curr++;
}
char pop(stack *s) {
	int x = s->a[s->curr-1];
	s->curr--;
	return x;
}
/* This function gets added, because with a type declration, we can't do curr = 0 */
void init(stack *s) {
	s->curr = 0;
}
int empty(stack *s) {
	return s->curr == 0;
}
int full(stack *s) {
	return s->curr == 128;
}
