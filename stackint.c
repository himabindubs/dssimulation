/* array a and curr become global now */
#include "stackint.h"
void push(stack1 *s, int number) {
	s->a[s->curr] = number;
	s->curr++;
}
int pop(stack1 *s) {
	int x = s->a[s->curr-1];
	s->curr--;
	return x;
}
/* This function gets added, because with a type declration, we can't do curr = 0 */
void init(stack1 *s) {
	s->curr = 0;
}
int empty(stack1 *s) {
	return s->curr == 0;
}
int full(stack1 *s) {
	return s->curr == 128;
}
