#include<stdio.h>
#include"list.h"
#include<string.h>
#include<stdlib.h>
void init(list *l) {
	l->head = NULL;
	l->length = 0;
}
void traverse(list *l) {
	node *p = l->head;
	printf("[");
	while(p != NULL) {
		printf("%s ", p->str);
		p = p->next;
		(l->length)++;
	}
	printf(" ]\n");
} 
void insert(list *l, char *str, int pos) {
	node *ptr, *tmp, *p;
	int i = 0;
	ptr = l->head;
	if(pos < 0 || pos > l->length)	
		return;
	tmp = (node*)malloc(sizeof(node));
	strcpy(tmp->str, str);
	while(i < pos - 1) {
		ptr = ptr->next;
		i++;
	}
	p = ptr->next;
	ptr->next = tmp;
	tmp->next = p; 
}	
char *remov(list *l, int pos) {
	node *ptr, *q;
	int i = 0;
	ptr = l->head;
	if(pos < 0 || pos > l->length)	
		return;
	while(i < pos - 1) {
		ptr = ptr->next;
		i++;
	}
	q = ptr->next;
	ptr->next = ptr->next->next;
	free(q); 
	(l->length)--;
	return ptr->next->str;
			
}
void append(list *l, char *str) {
	node *p, *tmp;
	p = l->head;
	while(p != NULL) {
		p = p->next;
	}
	tmp = (node *)malloc(sizeof(node));
	p = tmp;
	strcpy(tmp->str, str);
	tmp->next = NULL;
	(l->length)++;
}
int length(list *l) {
	return l->length;	
}
void reverse(list *l) {
	node *p, *q, *r;
	if(l->head->next == NULL)
		return;
	if(l->length == 2) {
		p = l->head->next;
		p->next = l->head;
		l->head = NULL;
		return;
	}		
	q = l->head;
	p = q->next;
	r = p->next;
	while(r != NULL) {
		p->next = q;
		q = p;	
		p = r;
		r = r->next;
	}
	return;
	//l->head  = q->next;
}
//int main() {
	
