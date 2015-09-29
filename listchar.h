typedef struct node {
	char str[20];
	struct lnode *next, *prev;
}ldlnode;			//ldl is list doubly linked
typedef struct node {
	char str[20];
	struct node *next;	//lsl is list singly linked
}lslnode;
typedef struct list {
	struct node *head, *tail;
	int length;
}list;
void init(list *l);
void traverse(list *l);
void insert(list *l, char *str, int pos);
char *remov(list *l, int pos);
void append(list *l, char *str);
int length(list *l);
void reverse(list *l);
void sort(list *l);
