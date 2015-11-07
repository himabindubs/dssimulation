#define SIZE 5
typedef struct stack{
	char *a[SIZE];
	int i;
}stack;

void init(stack *s);
void push(stack *s, char *str);
char *pop(stack *s);
int empty(stack *s);
int full(stack *s);
