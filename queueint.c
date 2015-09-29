#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queueint.h"
void qinit(queue1 *q){
	q->head = NULL;
	q->tail = NULL;
}
void enqueue(queue1 *q, int *name){
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->data = (char *)malloc(strlen(name) + 1);
	strcpy(tmp->data, name);
	tmp->next = NULL;

	if(q->tail == NULL)
		q->head = tmp;
	else 
		q->tail->next = tmp;
	q->tail = tmp;
}
char *dequeue(queue1 *q){
	node *tmp = q->head->next;
	int *retdata = q->head->data;
	free(q->head);
	q->head = tmp;
	if(q->head == NULL)
		q->tail = NULL;
	return retdata;
}
int qempty(queue1 *q){
	if(q->head == NULL)
		return 1;
	return 0;
}
int qfull(queue1 *q){
	return 0;
}
void printqueue(queue1 *q) {
	node *tmp = q->head;
	printf("Queue: [");
	while(tmp) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf(" ]\n");
}
