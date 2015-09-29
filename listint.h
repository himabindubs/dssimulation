typedef struct node {
	int no;
	struct node *next, *prev;
}ldlnode1;			//ldlnode1 means that it is doubly linked node for int
typedef struct node {
	int no;
	struct node *next;
}lslnode1;
typedef struct list {
	struct node *head, *tail;
	int length;
}list;
void init(list *l);
void traverse(list *l);
void insert(list *l, char *str, int pos);
int *remov(list *l, int pos);
void append(list *l, char *str);
int length(list *l);
void reverse(list *l);
void sort(list *l);
