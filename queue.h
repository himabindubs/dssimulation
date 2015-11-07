#define SIZE 5
typedef struct queue {
	char *a[SIZE];
	int i, j;
}queue;

void qinit(queue *q);
void enqueue(queue *q, char *str);
char *dequeue(queue *q);
int qempty(queue *q);
int qfull(queue *q); 
