#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *left, *right;
}node;

typedef node *tree;

void init(tree *t);
void insert(tree *t, int val);
void inorder(tree t);
 
/*init function must be called by the user*/

void init(tree *t) {
	*t = NULL;
}


void insert(tree *t, int data) {
	node *temp, *temp1 = *t, *temp2;
	int flag = 0;
	temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	if(*t == NULL) {
		*t = temp;
		return;
		
	}
	else {
		while(temp1) {
			temp2 = temp1;
			if(data > temp1->data) {
				temp1 = temp1->right;
				flag = 1;
			}
			else if(data < temp1->data) {	
				temp1 = temp1->left;
				flag = 0;
			}
			else {
				return;
			}
		}
		if(flag == 1) {
			temp2->right = temp;
		}
		else {
			temp2->left = temp;
		}
	}
}

void inorder(tree t) {
	if(t == NULL) {
		return;
	}
	inorder(t->left);
	printf("\t%d\n", t->data);
	inorder(t->right);
}
			
	
	
