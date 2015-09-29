#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queuechar.h"
void qinit(queue *q){
	q->head = NULL;
	q->tail = NULL;
}
void enqueue(queue *q, char *name){
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
char *dequeue(queue *q){
	node *tmp = q->head->next;
	char *retdata = q->head->data;
	free(q->head);
	q->head = tmp;
	if(q->head == NULL)
		q->tail = NULL;
	return retdata;
}
int qempty(queue *q){
	if(q->head == NULL)
		return 1;
	return 0;
}
int qfull(queue *q){
	return 0;
}
void printqueue(queue *q) {
	node *tmp = q->head;
	printf("Queue: [");
	while(tmp) {
		printf("%s ", tmp->data);
		tmp = tmp->next;
	}
	printf(" ]\n");
}
