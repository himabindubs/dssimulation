#define SIZE 1000
typedef struct stack{
	int a[SIZE];
	int i;
}stack1;
void init(stack1 *s);
void push(stack1 *s, int x);
int pop(stack1 *s);
int empty(stack1 *s);
int full(stack1 *s);
