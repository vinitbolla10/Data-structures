#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
 int d;
 struct node* left,*right,*parent;
};
 typedef struct node node;

 node* arr,*root;
 int n;
 void accept();
 node* web(int,int);
 node* merge1(node*,node*);
 void preorder(node*);

int main()
{
  int m,i;
  printf("Enter max no. You want to enter- ");
  scanf("%d",&m);

 for(i=0;i<m;i++)
 { //x =pow(2,i);
   //printf(" \n 2^ i = %d",x);
    if((pow(2,i))> m)
    break;
     }
 n = pow(2,i);
 printf("\n n is %d",n);
 accept();
 root = web(0,n-1);
 preorder(root);
 return 0;
}

void preorder(node* p)
{
 if(p!=NULL)
  {printf("%d ",p->d);
   preorder(p->left);
   preorder(p->right);
  }
}

node* merge1(node* p1,node* p2)
{
  node* r = (node*)malloc(sizeof(node));
  r->d = p1->d || p2->d;
  r->left = r->parent =r->right = NULL;
  return r;
}

node* web(int st,int ed)
{
  if(st!=ed)
   {
    node* r1 = web(st,(st+ed)/2);
    node* r2  = web((st+ed)/2+1,ed);

    node* r3 = merge1(r1,r2);
    r1->parent = r2->parent = r3;
    r3->left = r1;
    r3->right = r2;
    return r3;
   }
 else return arr+st;
}

void accept()
{ int nn,x;
 arr =(node*)malloc(n*sizeof(node));
 for(int i=0;i<n;i++)
 {//arr[i] = (node*)malloc(sizeof(node));
  (arr+i)->d =0; (arr+i)->left =NULL; (arr+i)->right =NULL; (arr+i)->parent = NULL;
 }
 printf("Enter no of elements ");
 scanf("%d",&nn);
 printf("Enter elements- ");
 for(int i=0;i<nn;i++)
 {
  scanf("%d",&x);
  (arr+x)->d = 1;
 }
 for(int i=0;i<n;i++)
 {
  printf("\n %d - %d",i,(arr+i)->d);
 }
}
