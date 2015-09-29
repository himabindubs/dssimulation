typedef struct node {
	int no;
	struct node *next;
}qslnode1;
typedef struct node {
	int no;
	struct node *next, *prev;
}qdlnode1;
typedef struct queue {
	struct node *head, *tail;
}queue;

void qinit(queue *q);
void enqueue(queue *q, char ch);
int dequeue(queue *q);
int qempty(queue *q);
int qfull(queue *q); 
