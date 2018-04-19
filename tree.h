#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *l, *r;
}node;

typedef node *tree;

void init(tree *t);
void create(tree *t,int data);
void inorder(tree t);

void init(tree *t){
	*t==NULL;
}

void create(tree *t,int data){
	node  *q, *p = *t,*tmp;
	int result=0;
	tmp = (node*)malloc(sizeof(node));
	tmp->data = data;	
	tmp->l = NULL;
	tmp->r = NULL;
	if(*t == NULL) {
		*t = tmp;
		
	}
	else {
		while(p) {
 			q = p;
			//result = strcmp(p->str, str);
			if (data > p->data){ 
				p = p->r;
				result=1;	
			}
			else if (data < p->data){
				p = p->l;
				result=0;
			}
			else {
				return;
			}
		}
	/* p is NULL. q is p's parent */

	
		if(result =1) {
			q->r = tmp;
			}
		else{
			q->l= tmp;
		}
	}
}
void inorder(tree t){
	if(t == NULL) {
		return;
	}
	inorder(t->l);
	printf("\t%d\n",t->data);
	inorder(t->r);
}
