#define MAX 10
typedef struct stack{
	int a[MAX];
	int i;
}stack;
void init(stack *s);
void push(stack *s,int n);
int isfull(stack *s);
int isempty(stack *s);
int pop(stack *s);

