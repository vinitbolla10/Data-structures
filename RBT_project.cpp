#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
using namespace std;

struct RBT
{
 int key;
 char name[100];
 struct RBT* left;
 struct RBT* right;
 struct RBT* parent;
 char color;
};
struct RBT* T=NULL;

void rotate_left(struct RBT *q)     //Function to rotate left
{
  struct RBT *k;
  k=q->right;
  q->right=k->left;
  if(k->left!=NULL)
    k->left->parent=q;
  k->parent=q->parent;
  if(q->parent==NULL)
  {
     T=k;
  }

  else if((q->parent->left!=NULL)&&(q->key==q->parent->left->key))
    q->parent->left=k;
  else
    q->parent->right=k;
 k->left=q;
 q->parent=k;
}

void rotate_right(struct RBT *k)    //Function to rotate right
{
 struct RBT *q;
 q=k->left;
 k->left=q->right;
 if(q->right!=NULL)
   q->right->parent=k;
 q->parent=k->parent;
 if(k->parent==NULL)
   T=q;
 else if((k->parent->left!=NULL)&&(k->key==k->parent->left->key))
   k->parent->left = q;
 else
  k->parent->right=q;

 q->right=k;
 k->parent=q;
}

void balance(struct RBT *p)
{
  struct RBT *k=NULL;
  while((p->parent!=NULL)&&(p->parent->color=='r'))
  {
   if((p->parent->parent->left!=NULL)&&(p->parent->key==p->parent->parent->left->key))
    {

     k=p->parent->parent->right;
     if((k!=NULL)&&(k->color=='r'))
      {

                                      //LLr & LRr
       p->parent->color='b';
       k->color='b';
       p->parent->parent->color='r';
       p=p->parent->parent;

      }
     else
     {
      if((p->parent->right!=NULL)&&(p->key==p->parent->right->key))
      {
        p=p->parent;
       rotate_left(p);                //LRb
      }
     p->parent->color='b';
     p->parent->parent->color='r';
     rotate_right(p->parent->parent);
        //LLb
     }
    }
   else
    {
     k=p->parent->parent->left;
     if((k!=NULL)&&(k->color=='r'))
      {
                                // RRr & RLr
        p->parent->color='b';
        k->color='b';
        p->parent->parent->color = 'r';
        p=p->parent->parent;
      }
     else
      {
      if ((p->parent->left!=NULL)&&(p->key == p->parent->left->key))
      {
       p=p->parent;
       rotate_right(p);             //RLb
      }

     p->parent->color='b';
     if(p->parent->parent!=T)
     p->parent->parent->color='r';

     rotate_left(p->parent->parent);    //RRb

     }
    }
  }
 T->color='b';

}

void put(int n,char value[])
{
 struct RBT *q,*k;
 struct RBT* p=(struct RBT*)malloc(sizeof(struct RBT));
 p->key=n;
 strcpy(p->name,value);
 p->left=NULL;
 p->right=NULL;
 p->color='r';
 p->parent=NULL;
 q=T;
 if(T==NULL)
 {
  T=p;
  T->color='b';
  return;
 }
 while(q!=NULL)
 {
  k=q;
  if(p->key<q->key)                     //searching the node
   q=q->left;
  else
   q=q->right;
 }
 p->parent=k;
 if(p->key<k->key)
   k->left=p;                        // assigning the parent
 else
  k->right=p;
cout<<"aaa";
  balance(p);
}

struct RBT* successor(struct RBT *u)         // Function to find the successor of a node.
{
  struct RBT *v;
  if (u->right)
   {
    v=u->right;
    while (v->left)
    {
     v = v->left;
    }
   return v;
   }
  v = u->parent;
  while (v && u == v->right)
  {
   u = v;
   v = v->parent;
  }
 return v;
}

void balance_delete(struct RBT *u)
{
 while (u !=T  && u->color == 'b')
  {
    struct RBT *s = NULL;
    if ((u->parent->left!=NULL) && (u == u->parent->left))
    {
     s=u->parent->right;
     if ((s!=NULL) && (s->color == 'r'))          //Left sibling is red.
      {
        s->color = 'b';
        u->parent->color = 'r';
        rotate_left(u->parent);
        s=u->parent->right;
      }
     if ((s!=NULL) && (s->right!=NULL) && (s->left!=NULL) && (s->left->color == 'b') && (s->right->color == 'b'))
     {
      s->color = 'r';                            //If both child are black.
      u = u->parent;
     }
     else if((s!=NULL) && (s->right->color == 'b'))
     {
     s->left->color = 'b';                     // Atleast one child is black
     s->color = 'r';
      rotate_right(s);                          //RL
      s = u->parent->right;
     }
     if(s!=NULL)
     {
      s->color = u->parent->color;
      u->parent->color = 'b';
      s->right->color = 'b';                   //RR
      rotate_left(u->parent);
      u = T;
     }
    }

  else
  {
   s = u->parent->left;
   if ((s!=NULL) && (s->color == 'r'))
   {
    s->color = 'b';
    u->parent->color = 'r';
    rotate_left(u->parent);
    if(u->parent!=NULL)
     s = u->parent->left;
   }
   if ((s!=NULL) && (s->right!=NULL) && (s->left!=NULL) && (s->right->color == 'b') && (s->left->color == 'b'))
    u = u->parent;                                       // Both child of sibling are black

   else if((s!=NULL) && (s->right!=NULL) && (s->left!=NULL) && (s->left->color == 'b'))
   {
    s->right->color = 'b';
    s->color = 'r';
    rotate_right(s);                                    // Atleast one child of sibling is red
    s = u->parent->left;
   }
  if(u->parent!=NULL)
  {
   s->color = u->parent->color;                       //LR
   u->parent->color = 'b';
  }
  if(s->left!=NULL)
   s->left->color = 'b';
  if(u->parent !=NULL)                                //RR
   rotate_left(u->parent);
  u = T;
  }
 }
 u->color = 'b';
}

void remove(int var)
{
 struct RBT *u = NULL, *v = NULL, *k;
 k=T;
 if((k->left ==NULL ) &&(k->right==NULL) && (k->key==var))  //To delete the only node.
 {
  k=NULL;
  printf("\nRBTREE is empty\n");
  free(k);
 }
 while(k->key !=var && k!=NULL)
 {                                                     //Searching the key to be deleted
  if(var<k->key)
   k=k->left;
  else
   k=k->right;
 }
 if((k->left==NULL)||(k->right==NULL))
 {
  v = k;
 }
 else
 {
  v = successor(k);
 }
if(v->left!=NULL)                           // Assigning value to u(u is child to be replaced)
 {
  u = v->left;
 }
 else
 {
  if(v->right !=NULL)
   u = v->right;
 }
 if((u!=NULL) && (v->parent !=NULL))
  u->parent = v->parent;
 if ((v !=NULL) && (u!=NULL) && (v->parent==NULL))
  T=u;
 else if (v == v->parent->left)
  v->parent->left = u;
 else
  v->parent->right = u;
 if (v != k)
  k->key = v->key;
 if ((v!=NULL) && (u!=NULL) && (v->color == 'b'))
  balance_delete(u);                            //Delete when u&v are black

 v=NULL;                                        //Delete the node when u/v are red
 free(v);
}

int containskey(int n)
{
   struct RBT *p;
   int data;
   data=n;
   p=T;
   while(p!=NULL)
   {
    if(p->key<data)
     p=p->right;
    else if(p->key>data)
     p=p->left;
    else if(p->key==data)
    {
     return 1;
    }
   }
   return 0;
}


struct RBT* higherEntry(int n)
{
   struct RBT *p;
   int data;
   data=n;
   p=T;
   while(p!=NULL)
   {
    if(p->key<data)
     p=p->right;
    else if(p->key>data)
     p=p->left;
    else if(p->key==data)
    {
    if(p->right!=NULL)
    {
         p=p->right;
      while(p->left!=NULL)
      {
        p=p->left;
      }
     return p;
     }
     break;
    }
   }
   return NULL;

}

struct RBT* lowerEntry(int n)
{
   struct RBT *p;
   int data;
   data=n;
   p=T;
   while(p!=NULL)
   {
    if(p->key<data)
     p=p->right;
    else if(p->key>data)
     p=p->left;
    else if(p->key==data)
    {
      if(p->left!=NULL)
      {
      p=p->left;
      while(p->left!=NULL)
      {
        p=p->right;
      }
     return p;
     }
     break;
    }
   }
   return NULL;

}



void inorder(struct RBT* T)
{
 struct RBT* temp=T;
 if(temp!=NULL)
  {
   inorder(temp->left);
   printf(" %d(%s)-%c ",temp->key,temp->name,temp->color);
   inorder(temp->right);
  }
}


void replace(struct RBT *T,int n,char new_value[])
{
   struct RBT *p;
   int data;
   data=n;
   p=T;
   while(p!=NULL)
   {
    if(p->key<data)
     p=p->right;
    else if(p->key>data)
     p=p->left;
    else if(p->key==data)
    {
    strcpy(p->name,new_value);
     printf("\nKey's value replaced");
     break;
    }
    else
    {
     printf("Key not found");
    }
   }
}

struct RBT* firstEntry()
{
  struct RBT* t=T;
   if(t==NULL)
   {
     return NULL;
   }
   else
   {
       while(t->left!=NULL)
       {
         t=t->left;
       }
       return t;
   }
}

struct RBT* lastEntry()
{
  struct RBT* t=T;
   if(t==NULL)
   {
     return NULL;
   }
   else
   {
       while(t->right!=NULL)
       {
         t=t->right;
       }
       return t;
   }

}


int main()
{
 int n,ch;
 int a;
 int s=0;
 struct RBT* x;
 char value[100];
 printf("Enter: 1:Put \t 2:Remove\t 3:Display\t 4:ContainsKey \t 5:Replace\t 6:HigherEntry\t 7:LowerEntry\t 8:FirstEntry\t 9:LastEntry\t 10:Size\t 11:Exit\n");
 printf("Enter your choice:");
 scanf("%d",&ch);
 do
  {
   switch(ch)
  {
    case 1:
     printf("Enter the key to be added: ");
     scanf("%d",&n);
     cout<<"Enter name assigned to key:";
     cin>>value;
     put(n,value);
     s++;
     inorder(T);
     break;
    case 2:
     printf("Enter the key to be removed: ");
     scanf("%d",&n);
     remove(n);
     s--;
     inorder(T);
     break;
    case 3:
     inorder(T);
     break;
    case 4:
     printf("Enter the number to be searched: ");
     scanf("%d",&n);
     a=containskey(n);
     if(a==1)
       cout<<"Key found";
     else
       cout<<"Key not found";
     break;
     case 5:
     printf("Enter the key whose value is to be replaced:");
     cin>>n;
     cout<<"Enter new value for key:";
     cin>>value;
     replace(T,n,value);
     break;
     case 6:
      printf("Enter the key:");
      cin>>n;
      x=higherEntry(n);
      if(x==NULL)
      {
        cout<<"No such key exits!";
      }
      else
      {
        cout<<"\nKey:"<<x->key<<"\tValue:"<<x->name;
      }
      break;
      case 7:
      cout<<"Enter the key:";
      cin>>n;
      x=lowerEntry(n);
      if(x==NULL)
      {
        cout<<"No such key exits!";
      }
      else
      {
        cout<<"\nKey:"<<x->key<<"\tValue:"<<x->name;
      }
      break;
      case 8:
      x=firstEntry();
      if(x==NULL)
      {
        cout<<"No such key exits!";
      }
      else
      {
        cout<<"\nKey:"<<x->key<<"\tValue:"<<x->name;
      }
      break;
      case 9:
      x=lastEntry();
      if(x==NULL)
      {
        cout<<"No such key exits!";
      }
      else
      {
        cout<<"\nKey:"<<x->key<<"\tValue:"<<x->name;
      }
      break;
      case 10:
      cout<<"Size of key-value mapping:"<<s;
    }
  printf("\n Enter your choice:");
  scanf("%d",&ch);
  }while(ch!=11);
}



