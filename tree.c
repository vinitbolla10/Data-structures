#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

void init(tree *t){

	*t==NULL;
}

void create(tree *t,int data){
	node *p = *t, *q, *tmp;
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
	printf("%d",t->data);
	inorder(t->r);
}
