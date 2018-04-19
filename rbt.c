#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

struct rbt
{
	int data;
	struct rbt *left,*right;
	struct rbt *par;
	int color;
}*root;

struct rbt *insert(struct rbt *root,int data);
struct rbt *add(struct rbt *root,int data);
void rotate_left(struct rbt *u);
void rotate_left_nocolor(struct rbt *u);
void rotate_right(struct rbt *u);
void rotate_right_nocolor(struct rbt *u);
void inorder(struct rbt *root);
struct rbt *delete(struct rbt *root,int data);
struct rbt *case_a(struct node *root,struct rbt *par,struct rbt *ptr);
struct rbt *case_b(struct node *root,struct rbt *par,struct rbt *ptr);
struct rbt *case_c(struct node *root,struct rbt *par,struct rbt *ptr);

int main()
{
	root=NULL;
	int ch,data;
	do
	{
		printf("\n1-Insert\n2-Inorder\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter data");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			case 2:
				inorder(root);
				break;
		}
	}while(1);
	return 0;
}

struct rbt *insert(struct rbt *root,int data)
{
	struct rbt *u;
	u=add(root,data);

	if(u->par==NULL)
	{
		return u;
	}

	while(u->par!=NULL && (u->par->color==0 && u->color==0))
	{
		if(u->par==u->par->par->left)   //left side
		{
			if(u->par->par->right == NULL)
			{
				
				if(u==u->par->left)		//LLb
				{
					printf("hayee");	
					rotate_right(u->par);
				}
				else					//LRb
				{
					printf("ohww");
					rotate_left_nocolor(u->par);
					rotate_right(u);
				}
			}
			else
			{
				if(u->par->par->right->color==0)   //LLr & LRr
				{
					printf("\nleft sidelllllll");
					u->par->color=1;
					u->par->par->right->color=1;

				
					if(u->par->par->par!=NULL)
					{
						u->par->par->color=0;
					}
					else
					{
						u->par->par->color=1;
					}
				}
				else
				{
					if(u==u->par->left)		//LLb
					{
						printf("hayee");	
						rotate_right(u->par);
					}
					else					//LRb
					{
						printf("ohww");
						rotate_left_nocolor(u->par);
						rotate_right(u);
					}
				}
			}
		}

		else    //right side
		{
			if(u->par->par->left == NULL)
			{
				
				if(u==u->par->right)		//RRb
				{
					printf("hayee");	
					rotate_left(u->par);
				}
				else						//RLb
				{
					printf("ohww");
					rotate_right_nocolor(u->par);
					rotate_left(u);
				}
			}
			else
			{
				if(u->par->par->left->color==0)   //RRr & RLr
				{
					u->par->color=1;
					u->par->par->left->color=1;

					if(u->par->par->par!=NULL)
					{
						u->par->par->color=0;
					}
					else
					{
						u->par->par->color=1;
					}
					u=u->par->par;
				}
				else
				{
						if(u==u->par->right)		//RRb
					{
						printf("hayee");	
						rotate_left(u->par);
					}
					else						//RLb
					{
						printf("ohww");
						rotate_right_nocolor(u->par);
						rotate_left(u);
					}
				}
			}
		}
	}
	while(u->par!=NULL)
	{
		u=u->par;
	}
	return u;
}

struct rbt *add(struct rbt *root,int data)
{
	struct rbt *temp,*curr,*head;
	temp=(struct rbt *)malloc(sizeof(struct rbt));
	
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{	printf("hello");
		temp->color=1;
		temp->par=NULL;
		root=temp;
		return root;
	}
	else
	{
		printf("oyye");
		curr=root;
		head=NULL;
		while(curr != NULL)
		{
			head=curr;
			if(data <= head->data)
			{
				printf("\nless");
				curr=curr->left;
				if(curr==NULL)
				{
					head->left=temp;
					break;
				}
			}
			else
			{
				printf("\nmore");
				curr=curr->right;
				if(curr==NULL)
				{
					head->right=temp;
					break;
				}
			}
		}
		temp->color=0;
		temp->par=head;
		return temp;
	}
}
void inorder(struct rbt *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d->%d 	  ",root->data,root->color);
		inorder(root->right);
	}
}

void rotate_left(struct rbt *u)
{
	struct rbt *temp;
	temp=u->par->par;
	u->par->right=u->left;
	if(u->left!=NULL)
	{
		u->left->par=u->par;
	}
		u->left=u->par;
		u->par->par=u;
		u->par=temp;

		if(u->par!=NULL)
		{
			if(u->left==u->par->left)
			{
				u->par->left=u;
			}
			else if(u->left==u->par->right)
			{
				u->par->right=u;
			}
			else
			{
				u->par->right=u;
			}
		}
		u->left->color=0;
		u->color=1;

}
void rotate_left_nocolor(struct rbt *u)
{
	struct rbt *temp;
	temp=u->right->left;
	u->right->par=u->par;
	u->par->left=u->right;
	u->right->left=u;
	u->par=u->right;
	u->right=temp;
	printf("\nAll okay");
}
void rotate_right(struct rbt *u)
{
	struct rbt *temp;
	temp=u->par->par;
	u->par->left=u->right;
	if(u->right!=NULL)
	{
		u->right->par=u->par;
	}
		u->right=u->par;
		u->par->par=u;
		u->par=temp;

		if(u->par!=NULL)
		{
			if(u->right==u->par->right)
			{
				u->par->right=u;
			}
			else if(u->right==u->par->left)
			{
				u->par->left=u;
			}
			else
			{
				u->par->left=u;
			}
		}
		u->right->color=0;
		u->color=1;
}
void rotate_right_nocolor(struct rbt *u)
{
	struct rbt *temp;
	temp=u->left->right;
	u->left->par=u->par;
	u->par->right=u->left;
	u->left->right=u;
	u->par=u->left;
	u->left=temp;
	printf("\nAll okay");
}
/*
struct rbt *delete(struct rbt *root,*int data)
{

}
struct rbt *case_a(struct rbt *root,struct rbt *par,struct rbt *ptr)
{

}
struct rbt *case_b(struct rbt *root,struct rbt *par,struct rbt *ptr)
{

}
struct rbt *case_c(struct rbt *root,struct rbt *par,struct rbt *ptr)
{

}*/
