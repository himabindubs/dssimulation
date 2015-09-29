#include<stdio.h>
#include<string.h>
#include"stackint.h"
#include"stackchar.h"
#include"queueint.h"
#include"queuechar.h"
#include"listint.h"
#include"listchar.h"
int choice, choice1;
stack s;
stack1 s1;
queue q;
queue1 q1;
list l;
list1 l1;
typedef union value {
	int a;
	char b;
}value;	
qslnode qs = (*qslnode) malloc(sizeof(qslnode));
qdlnode qd = (*qdlnode) malloc(sizeof(qdlnode));
qslnode1 qd1 = (*qslnode) malloc(sizeof(qslnode1));
qdlnode1 qd1 = (*qdlnode) malloc(sizeof(qdlnode1));
qinit(queue *q);
void acceptchoice() {
	char c[20], c1[20];
	scanf("%s", c);
	if(strcmp("stack", c) == 0) {	
		choice = 1;
		printf("Which stack do you want character/integer?");
		scanf("%s", c1);
		if(strcmp("character", c1) == 0)
			choice1 = 1;
		else
			choice1 = 2;	
	if(strcmp("queue", c) == 0) {
		choice = 2;
		printf("Which queue do you want character/integer?");
		scanf("%s", c1);
		if(strcmp("character", c1) == 0)
			choice1 = 1;
		else
			choice1 = 2;	
	}		
	if(strcmp("list", c) == 0) {
		printf("Do you want character/integer list?");
		scanf("%s", c1);
		if(strcmp("character", c1) == 0)
			choice1 = 1;
		else
			choice1 = 2;	
		choice = 3;
	}
	if(strcmp("tree", c) == 0) {					//to be done later
		printf("Which queue do you want character/integer?");
		scanf("%s", c1);
		if(strcmp("character", c1) == 0)
			choice1 = 1;
		else
			choice1 = 2;		
		choice = 4;
	}
void acceptvalues() {
	switch(choice) {
		case 1: switch(choice1) {
				case 1: printf("Enter the character you want to push");
					scanf("%c", value.b );
					push(stack *s, value.b);
					break;
				case 2: printf("Enter the number you want to push");
					scanf("%d", value.a);
					push(stack1 *s1, value.a)
					break;
			break;	
		case 2: switch(choice1) {
				case 1: printf("Enter the character you want to enqueue");
					scanf("%c", value.b);
					enqueue(queue *q, value.b)
					break;
				case 2: printf("Enter the number you want to enqueue");
					scanf("%d", value.a);
					enqueue(queue *q, value.a);
					break;
			break;	
		case 3: switch(choice1) {
				case 1: printf("Enter the character you want to include in the list");
					scanf("%c", value.b);
					
					break;
				case 2: printf("Enter the number you want to include in the list");
					scanf("%d", value.a);
					break;
			break;	
		case 4: switch(choice1) {
				case 1: printf("Enter the character you want to push");		//to be done later
					scanf("%c", value.b);
					break;
				case 2: printf("Enter the number you want to push");
					scanf("%d", value.a);
					break;
			break;						
}
int main() {
	int
