typedef struct node {
	char ch;
	struct node *next;
}qslnode;
typedef struct node {
	char ch;
	struct node *next, *prev;
}qdlnode;

typedef struct queue {
	struct node *head, *tail;
}cqueue;

void cqinit(cqueue *q);
void cenqueue(cqueue *q, char ch);
char cdequeue(cqueue *q);
int cqempty(cqueue *q);
int cqfull(cqueue *q); 
