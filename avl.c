#include<stdio.h>
#include<stdlib.h>
/*typedef struct node{
	int data,height;
	struct node *left,*right;
}node;

*/

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int main()
{
  struct Node *n = NULL;
	while(scanf("%d", &key) != -1) {
		insert(&n, key);
	}
	inorder(n);
	return 0;

}
struct Node* insert(struct Node* node, int key){
	int bal;
	if(n==NULL){
		create(key);
	}
	else if(key < n->data){
		node->left=insert(node->left);			
		}
	else if(key > n->data){
		node->right=insert(node->right);
		}
	else{
		return node;
		}
	
	node->height= 1 + max(height(node->left),height(node->right));

	bal = getBalance(node);
	
	if (bal > 1 && key < node->left->key)
        return rightRotate(node);
	
	if (bal < -1 && key > node->right->key)
        return leftRotate(node);

	if (bal > 1 && key > node->left->key){
	        node->left =  leftRotate(node->left);
	        return rightRotate(node);
	 }	
	
	if (bal < -1 && key < node->right->key){
        	node->right = rightRotate(node->right);
        	return leftRotate(node);
        }	

	 return node;

}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    return y;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
