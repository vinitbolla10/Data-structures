/*
*NAME:- VINIT BOLLA
*DATE:- 24/01/18
*ROLL_NO. :- H-54
*
*Q. Wirte C or C++ program to Implement Red Black Tree Data Structure for storing set of integer keys.
*and perform the following operations.
*1. Insert()
*2. Delete()
*3. Search()
*/
#include<stdio.h>
#include<stdlib.h>


struct node
{
	char color;
	int data;
	struct  node *left;
	struct  node *right;
	struct  node *parent;
};

struct node *root;
struct node *gp;

int find(int item,struct node **loc);
struct node *succ(struct node *ptr);
void del_balance(struct node *ptr);
void del(int);


void RotateLeft(struct node *a)
{
	struct node *b;

	b = a->right;
	a->right= b->left;

	if(b->left !=gp)
        b->left->parent = a;

	b->parent = a->parent;

	if(a->parent == gp )
		root = b;
	else if( a == a->parent->left )
		a->parent->left = b;
	else
		a->parent->right = b;
    b->left = a;
	a->parent = b;
}
void RotateRight(struct node *a)
{
	struct node *b;

	b = a->left;
	a->left= b->right;

	if(b->right !=gp )
        b->right->parent = a;

	b->parent = a->parent;

	if(a->parent == gp )
		root = b;
	else if( a == a->parent->right )
		a->parent->right = b;
	else
		a->parent->left = b;

	b->right = a;
	a->parent = b;
}




void inorder(struct node *ptr)
{
	if(ptr!=gp)
	{
		inorder(ptr->left);
		printf("\n %d -> %c\n",ptr->data,ptr->color);
		inorder(ptr->right);
	}
}

void make_rbt(struct node *child )
{
	struct node *uncle, *par, *grandPar;

	while( child->parent->color == 'r' )
	{
		par = child->parent;
		grandPar = par->parent;



		if( par == grandPar->left )
		{
			uncle = grandPar->right;


			if(uncle->color == 'r' )
			{

				par->color ='b';
				uncle->color ='b';
				grandPar->color ='r';
				child = grandPar;



			}
			else
			{


				if( child == par->right)
				{

					RotateLeft(par);


					child = par;
					par = child->parent;



				}

				par->color ='b';
				grandPar->color = 'r';


				RotateRight(grandPar);


			}
		}
		else
		{
			if(par == grandPar->right )
			{
				uncle = grandPar->left;
				if(uncle->color == 'r' )
				{
					par->color ='b';
					uncle->color ='b';
					grandPar->color ='r';
					child = grandPar;

				}
				else
				{
					if( child == par->left)
					{

						RotateRight(par);
						child = par;
						par = child->parent;

					}

					par->color ='b';
					grandPar->color = 'r';


					RotateLeft(grandPar);


				}
			}
		}
	}
	root->color ='b';

}
void insert (int n )
{
	struct node *temp, *ptr, *par;

	par = gp;
	ptr = root;

	while( ptr != gp )
	{
		par = ptr;
		if( n < ptr->data )
			ptr = ptr->left;
		else if( n > ptr->data )
			ptr = ptr->right;
		else
		{
			printf("Duplicate\n");
			return;
		}
	}
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = n;
	temp->left = gp;
	temp->right = gp;
	temp->color = 'r';
	temp->parent = par;

	if(par==gp)
		root = temp;
	else if(temp ->data < par->data )
		par->left = temp;
	else
		par->right = temp;


	make_rbt(temp);

}








int main()
{
	int choice,num;

	gp = (struct node *) malloc(sizeof(struct node));
	gp->data = -1;
	gp->color = 'b';
	root = gp;


	while(1)
	{

		printf("\n1.Insert\n2..Display\n3..delete\n4.exit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("\nEnter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		case 2:
			inorder(root);
			break;
		case 3:
			printf("\nEnter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		case 4:
			exit(0);
	}
	}

}


struct node *succ(struct node *loc)
{
	struct node *ptr=loc->right;
	while(ptr->left!=gp)
	{
		ptr=ptr->left;
	}
	return ptr;
}


void del_balance(struct node *nptr)
{
	struct node *sib;

	while( nptr!=root )
	{
		if( nptr == nptr->parent->left )
		{
			sib = nptr->parent->right;
			if( sib->color == 'r' )/* Case L_1 */
			{
				printf("L_Case 1\n");
				sib->color = 'b';
				nptr->parent->color = 'r';
				RotateLeft(nptr->parent);
				sib = nptr->parent->right; /*new sibling which is 'b'*/
			
			}
			if( sib->left->color == 'b'  && sib->right->color == 'b' )
			{
				sib->color='r';
				
				if(nptr->parent->color == 'r' )/*Case L_2a*/
				{
					printf("L_Case 2a\n");
					nptr->parent->color = 'b';
					return;
				}
				else
				{
					printf("Case L_2b\n");
				    nptr=nptr->parent;	/*Case L_2b */
				}
			
			}
			else 
			{
				if(sib->right->color=='b')  /*Case L_3a*/
				{
					printf("Case L_3a\n");
					sib->left->color='b';
					sib->color='r';
					RotateRight(sib);
					sib = nptr->parent->right;
					
				}
				
				printf("Case L_3b\n");
                sib->color = nptr->parent->color;  /*Case L_3b*/
				nptr->parent->color = 'b';
				sib->right->color = 'b';
				RotateLeft(nptr->parent);
				
				return;	
				
			}
		}
		else
		{
			sib = nptr->parent->left;
			if( sib->color == 'r' )	/* Case R_1 */
			{
				printf("Case R_1\n");
				sib->color ='b';
				nptr->parent->color = 'r';
				RotateRight(nptr->parent);
				sib = nptr->parent->left;
				
			}
			
			if( sib->right->color == 'b'  && sib->left->color == 'b' )
			{
				sib->color='r';
				if(nptr->parent->color == 'r' )/* Case R_2a*/
				{
					printf("Case R_2a\n");
					nptr->parent->color = 'b';
					return;
				}
				else	/* Case R_2b*/
				{
					printf("Case R_2b\n");
					nptr=nptr->parent; 
				}
				
			}
            else 
			{
				if(sib->left->color=='b')  /*Case R_3a*/
				{
					printf("Case R_3a\n");
					sib->right->color='b';
					sib->color='r';
					RotateLeft(sib);
					sib = nptr->parent->left;
					
				}
				
				
				sib->color = nptr->parent->color;
				nptr->parent->color = 'b';
				sib->left->color = 'b';
				RotateRight(nptr->parent);
				
				return;
			}
		}
	}
}/*end of del_balance*/



int find(int item,struct node **loc)
{
	struct node *ptr;

	if(root==gp)/*Tree is empty*/
	{
		*loc=gp;
		return 0;
	}

	if(item==root->data)/*Item is at root*/
	{
		*loc=root;
		return 1;
	}

	/*Initialize ptr*/
	if(item < root->data)
		ptr=root->left;
	else
		ptr=root->right;

	while(ptr!=gp)
	{
		if(item == ptr->data)
		{       
			*loc=ptr;
			return 1;
		}
		if(item < ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	 }
	 *loc=gp;		/*Item not found*/
	 return 0;
}


void del(int item)
{
	struct node *child,*ptr,*successor;
    
	if( ! find(item, &ptr) )
	{
		printf("item not present \n");
		return;
	}

	if(ptr->left != gp || ptr->right != gp )
	{
		successor = succ(ptr);
		ptr->data = successor->data;
		ptr=successor;
	}
		
	if( ptr->left !=gp )
		child = ptr->left;
	else
		child = ptr->right;
	
	child->parent = ptr->parent;
	
	if(ptr->parent == gp)
		root=child;
	else if( ptr == ptr->parent->left )
		ptr->parent->left = child;
	else 
		ptr->parent->right = child;
	
	
		
	if( child == root )
		child->color = 'b';
    else if( ptr->color == 'b' )/*'b' node*/  
	{
		if( child != gp ) /*one child which is 'r'*/
            child->color = 'b';
		else	/*no child*/
			del_balance(child);
	}
	
}





