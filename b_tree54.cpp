/*

*NAME:- VINIT BOLLA

*DATE:-6/2/18

*ROLL_NO. :- H-54

*/
#include <stdio.h>
//#include<malloc.h>
//#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
using namespace std;
struct Btree
{
  int n;
  int *keys;
  int m;
  int leaf;
  struct Btree **child;
  struct Btree *parent;
};
struct Btree *root=NULL;
int m;
int check=0;
void traverse(Btree *t,int no) ;
void search (Btree *t,int k);
Btree * insert(struct Btree *root,int key);
Btree * splitchild(struct Btree* p,int key,struct Btree*q,struct Btree *root,int child);
void initialise (struct Btree *root);

int main() // main function
{
//int m;
//int check=0;
//clrscr();
cout<<"enter the size of m";
cin>>m;
cout<<"enter the size of elements" ;
int s;
cin>>s;
while (s>0)
{
	int a;
	cout<<"enter element";
	cin>>a;
	root = insert(root,a);
	s--;
}
while (1)
{
	int ch;
	cout<<"\n 1.insert 2. traverse 3.search 4.exit";
	cin>>ch;
	switch (ch)
	{
	case 1:int a;
	cout<<"\n enter element";
	cin>>a;
	root= insert(root,a);
	break;
	2 cout: case<<"\n traversal is \n ";
		traverse (root,0);
		cout<<"\n\n";

		break;

	case 3: cout<<"\n enter element to be searched";
		int x;
		cin>>x;
		cout<<endl;
		search(root,x);
		if(check==1)
		  cout<<"element is present";
		  else
		  cout<<"element is absent";
		  check=0;
		break;
	case 4:exit(0);

	default: cout<<"\n invalid choice";

       }
}

getch();
return 0;

}
Btree * insert(struct Btree *root,int key)
{
	if (root==NULL)//initially when tree is empty
	{
		root=new Btree;
		initialise(root);
		root->n++;
		root->leaf=1;
		root->keys[0]=key;
		return root;

	}
	else
	{
		struct Btree *p;
		p=root;
		while (p!=NULL && p->leaf!=1)//traverse to reach the leaf where the key is to be inserted
		{

		int i;
			for(i=0;i<p->n;i++)
			{
				if(key<p->keys[i])
				{

				break;
				}
			}


			if(p->leaf==0)
			{
			p=p->child[i];
			cout<<"shffted to child p"<<"whose child first key is \n"<<p->keys[0];
			}
			else
			break;

		}
		//now if u reached the node and it is also full split that child;
		if(p->n==p->m-1)
		root=splitchild(p,key,NULL,root,0);

		else//the reached node is not full
		{
			int i;
			for( i=0;i<p->n;i++)//find postition of the key
			{
			if(key<p->keys[i])
			break;
			}
			if(i!=p->m-1)
			{
				for(int j=p->n-1;j>=i;j++)//shift all the keys forward
				{
					p->keys[j+1]=p->keys[j];
				}
			}
			p->keys[i]=key;
			p->n++;
		}
		return root;
	}
}



void initialise (struct Btree *root)
{
	root->m=m;
	root->parent=NULL;
	root->keys=new int[root->m-1];
	root->child=(struct Btree **)malloc(m*sizeof(struct Btree*));
	root->leaf=1;
	root->n=0;

	for(int i=0;i<root->m;i++)
	{
		root->child[i]=NULL;
		if(i<root->m-1)
		root->keys[i]=0;
	}

}
Btree * splitchild(struct Btree* p,int key,struct Btree*q,struct Btree *root,int child)
{
		int temp[100];
		int i=0;
		struct Btree *s=NULL;
		if(p->n!=m-1)//parent of splitted child is not full wont go in normal case
		{
			int i;
			for( i=0;i<p->n;i++)//find postition of the key
			{
			if(key<p->keys[i])
			break;
			}
			if(i!=p->n)
			{
				for(int j=p->n-1;j>=i;j++)//shift all the keys forward
				{
					p->keys[j+1]=p->keys[j];
				}

				for (j=p->n;j>=i;j--)
				{
					p->child[j+1]=p->child[j];

				}
			}
			p->keys[i]=key;
			p->n++;
			p->child[i+1]=q;
			q->parent=p;

		}
		else// normal split case
		{
			if(p->parent==NULL)//p is root
			{
				s=new Btree;
				initialise(s);
				root=s;
				s->n++;
				p->parent=s;
			    s->child[0]=p;
				s->leaf=0;
			}

			while (p->keys[i]<key && i<p->m-1)//first store keys less than our key
			{
				temp[i]=p->keys[i];
				i++;
			}
			//store our key
			temp[i]=key;
			while(i!=p->m-1)//storing the remainig keys
			{
				temp[i]=p->keys[i];
				i++;
			}
			int median=temp[p->m/2];

			//store the first half back to p;
			for(i=0;i<p->m/2;i++)
				p->keys[i]=temp[i];

			p->n=m/2;
			struct Btree *z=new Btree;
			initialise (z);
			z->parent=s;//z is the new node in which half keys are going to be placed

			//now depending on p we will decide whether z is leaf or not
			if(p->leaf==1)
				z->leaf=1;
			else
				z->leaf=0;
			//storing the second half to z;
				for(i=p->m/2+1;i<p->m;i++)
				{
					z->keys[i-(m/2+1)]=temp[i];
				}
				z->n=p->m/2;
			if(s!=NULL)
			{
					s->keys[0]=median;
					s->child[1]=z;

			}
			else
			{
				int i;
				for(i=0;i<p->parent->n;i++)//finding position of the child p;
				{
					if(p==p->parent->child[i])
						break;
				}
				root=splitchild(p->parent,median,z,root,i+1);
			}


		if(q!=NULL)//we have a node which is splitted
		{
			    int i;
		if(child<=p->m/2)
		{
			for( i=p->m/2;i<p->m;i++)
			{
			z->child[i-p->m/2]=p->child[i];
			z->child[i-p->m/2]->parent=z;
			}
			for(i=child;i<p->m/2;i++)
			{
			p->child[i+1]=p->child[i];
			}
			p->child[child]=q;
			q->parent=p;
		}
      else
      {
	for( i=p->m/2+1;i<child;i++)
	{
	  z->child[i-p->m/2-1]=p->child[i];
	  z->child[i-p->m/2-1]->parent=z;
	 }
	 z->child[child-p->m/2-1]=q;
	 q->parent=z;
	 for( i=child;i<=p->m;i++)
	 {
	   z->child[i-p->m/2]=p->child[i];
	   z->child[i-p->m/2]->parent=z;
	 }
      }


      }

	}//else
      return root;

}//function

void traverse(Btree* t,int no)
{
  int i=0;
  while(t!=NULL && i!=t->n+1 )
  {
    for(i=0;i<=t->n;i++)
    {
      if(i==0)
	no++;
      traverse(t->child[i],no);
      if(i<t->n)
      cout<<"("<<no<<")"<<t->keys[i]<<" ";
      if(i==t->n)
	cout<<endl;
    }

  }
}
void search(Btree* t,int k)
{
  int i=0;
  while(t!=NULL && i!=t->n+1 )
  {
    for(i=0;i<=t->n;i++)
    {
      search(t->child[i],k);
      if(k=t->keys[i])
      check=1;

    }
  }

}


