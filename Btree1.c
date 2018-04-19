#include<stdio.h>
#include<stdlib.h>

struct btree
{
	int n;                       // no. of keys in a nodee............
	int *key;                   // data inside a node
	struct btree** child;
	int leaf;
};

struct btree* root=NULL;
struct btree* s;
int m,flag,sflag;
struct btree* insert(struct btree* ptr,int k);
void splitchild(int c,struct btree* T,struct btree* s,int k);
void insertnonfull(struct btree* T,int k);
struct btree *findchild(int key,struct btree *ptr);
void inorder(struct btree *ptr);
void search(struct btree *ptr,int num);

int main()
{

	printf("\nenter order of Btree  :  ");
	scanf("%d",&m);
  while(1)
  {
	  flag=0;
	  sflag=0;
	  int num,choice,i;
	  printf("\n1.Insert\n2.inorder\n3.search\n4.exit\n");
	  printf("\nEnter your choice : ");
	  scanf("%d",&choice);
	  switch(choice)
	  {
		  case 1:
		               printf("\nEnter number :  ");
					   scanf("%d",&num);
					   root=insert(root,num);
		  break;
		  case 2:
		                   for(i=0;i<root->n;i++)
						   {
		                    printf("\nroot %d=%d",i,root->key[i]);
						   }
						printf("\n\nchilds first number");
						   for(i=0;i<=root->n;i++)
						   {

							printf("\nchild %d=%d",i,root->child[i]->key[0]);
						   }


						   printf("\n\n");
						   inorder(root);
		  break;
		  case 3:
		                 printf("\nEnter no. for search: ");
                          scanf("%d",&num);
                           search(root,num);

						   if(flag==0)
							   printf("\nNumber is not found in tree");

		  break;
		  case 4:
		                 exit(1);
		  break;
	  }
  }
  return 0;
}

struct btree* insert(struct btree* ptr,int k)//insert
{
	//int j;
	if(ptr==NULL)
	{
		ptr=(struct btree*)malloc(sizeof(struct btree));
		ptr->key=(int*)malloc((m-1)*sizeof(struct btree));
		ptr->child=(struct btree**)malloc(m*sizeof(struct btree));
		ptr->leaf=1;
		ptr->key[0]=k;
		ptr->n=1;

		return ptr;
	}
	else if(ptr->n==m)
	{
		if(root->leaf==1)
		{
			s=(struct btree*)malloc(sizeof(struct btree));
			s->child=(struct btree**)malloc(m*sizeof(struct btree));
			s->key=(int*)malloc((m-1)*sizeof(struct btree));
			s->n=0;
			s->child[0]=ptr;
			splitchild(0,ptr,s,k);
			ptr=s;

		return ptr;
		}
		else
		{
			printf("\n\nroot is full but child is not");
		       	insertnonfull(ptr,k);
			if(ptr->n==m)
			{
				printf("\n\nroot is full split it \n");
				sflag=1;
				s=(struct btree*)malloc(sizeof(struct btree));
				s->child=(struct btree**)malloc(m*sizeof(struct btree));
				s->key=(int*)malloc((m-1)*sizeof(struct btree));
				s->n=0;
				s->child[0]=ptr;
				splitchild(111,ptr,s,ptr->key[ptr->n-1]);
				ptr=s;

			return ptr;
			}
		}
	}
	else
	{
		insertnonfull(ptr,k);
		}
	return ptr;
}

void splitchild(int c,struct btree* T,struct btree* s,int k)//split child
{
	if(c==0)
		printf("\nsplit root");
	else
		printf("\nsplit child");

   		printf("\n");

	struct btree* z=(struct btree*)malloc(sizeof(struct btree));
	z->key=(int*)malloc((m-1)*sizeof(struct btree));

	z->child=(struct btree**)malloc(m*sizeof(struct btree));
	int temp[m];
	int j;

	struct btree* x;
	x=T;

	for(j=0;j<m-1;j++)
	{
		temp[j]=T->key[j];
	}

	j=m-2;
	while(j>=0 && temp[j]>k)
	{
		temp[j+1]=temp[j];    // before spliting sorting an array------
		j--;
	}
    	temp[j+1]=k;			//inserted element..................

	for(j=0;j<m;j++)
		printf("\ttemp%d=%d",j,temp[j]);

	if(sflag== 1)
	{
		for(j=0;j<(m/2);j++)
	    {
	      z->key[j] = temp[j+((m/2)+1)];
	      z->child[j+1] = findchild(temp[j+((m/2)+1)],x);
	    }

	    z->child[0] = findchild(temp[m/2],x);
	}
	else
	{
		for(j=0;j<(m/2);j++)
	    {
	      z->key[j] = temp[j+((m/2)+1)];
	    }
	}


		for(j=0;j<m/2;j++)
	{
		T->key[j]=temp[j];
	}


	for(j=0;j<m/2;j++)
	{
		z->key[j]=temp[j+(m/2)+1];
	}


	j=s->n-1;


	while(j>=0 && s->key[j]>temp[m/2])
	{
		s->key[j+1]=s->key[j];
		  s->child[j+2] = s->child[j+1];
		j--;
	}
	s->key[j+1]=temp[m/2];
	printf("\nroot->[%d]=%d",j+1,s->key[j+1]);

	    if(m%2 == 0) // m is even
    {
    	z->n = m/2 - 1;
    }
    else // m is odd
    {
	    z->n = m/2;
    }

	T->n=m/2;
	s->child[j+1]=T;
	s->child[j+2]=z;
	s->n=s->n+1;
	s->leaf=0;

	    if(sflag == 1)
    {
    	z->leaf = 0;
    }
    else
    {
    	z->leaf = 1;
    }

}

void insertnonfull(struct btree* T,int k)//insert in nonfull node
{
	int i=T->n-1;                  // n is no. of nodes at present...........
	if(T->leaf==1)
	{
		printf("\ninsertion in leaf node\n");
		while(i>=0 && T->key[i]>k)
		{
			T->key[i+1]=T->key[i];             // comparing the elements in an array and sorting them accordingly
			i--;
		}
		T->key[i+1]=k;				//..........inserted element.
		T->n=T->n+1;
	}
	else
	{
		 while(i>=0 && T->key[i]>k)
		 {
			 i--;
		 }

			 if(T->child[i+1]->n==m-1)
			 {
				 splitchild(i+1,T->child[i+1],T,k);
			 }
			 else
			 {
				insertnonfull(T->child[i+1],k);

			 }
		 }

}

struct btree *findchild(int key,struct btree *ptr)
{
	int i=0;
	while(key >= ptr->child[i]->key[0])
	{
		i++;
	}
	return ptr->child[i];
}

void inorder(struct btree *ptr)//inorder
{
	int i;
	for(i = 0; i < ptr->n; i++)
	{
		if(ptr->leaf == 0)
			inorder(ptr->child[i]);

		printf("%d,",ptr->key[i]);
	}

	if(ptr->leaf == 0)
		inorder(ptr->child[i]);
}


void search(struct btree *ptr,int num) // Search function
{
	int i;
	for(i = 0; i < ptr->n; i++)
	{
		if(ptr->leaf == 0)
			search(ptr->child[i],num);

		if(ptr->key[i] == num)
		{
			printf("\nNumber is found in tree= %d\n",ptr->key[i]);
			flag = 1;
		}
	}

	if(ptr->leaf == 0)
	{
		search(ptr->child[i],num);
	}
}

