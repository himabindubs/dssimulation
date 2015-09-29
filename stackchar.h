#define SIZE 1000
typedef struct stack{
	char a[SIZE];
	int i;
}stack;
void init(stack *s);
void push(stack *s, int x);
int pop(stack *s);
int empty(stack *s);
int full(stack *s);
