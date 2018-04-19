#include<stdio.h>
#include<stdlib.h>
// 0 is black, 1 is red
struct Node{
	int data;
	struct node *left;
	struct node *right;
	int color;
};

struct Node* newnode(int key){
	struct Node* node;
     
        node = (struct Node*)malloc(sizeof(struct Node));
        node->data   = key;
        node->left   = NULL;
        node->right  = NULL;
        node->color = 1;  
    
        return(node);
}

struct Node* rootnode(int key){
	struct Node* node;
     
        node = (struct Node*)malloc(sizeof(struct Node));
        node->data   = key;
        node->left   = NULL;
        node->right  = NULL;
        node->color = 0;  
    
        return(node);
}

struct Node* insert(struct Node* node, int key)
{
	if(node == NULL){
		return(rootnode(key));	
}

}
