#include<stdio.h>
#include<conio.h>
typedef struct node{
	int num;
	struct node *next;
}node;
struct node *list;
void create(list *l,int num){
	node *temp,*head,*t;
	temp=(struct node*)malloc(sizeof(struct node*));
	temp->num=num;	
	temp->next=NULL;	
	if(l!=NULL){
		t->next=temp;		
		t=temp;		
		}
		else{
		head=temp;
		t=temp;
		}
}


void init(list *l){
	return l->next==NULL;
	
}

int main(){
list *l;

int value;
init(&l);
while(scanf("%d",&value)!=-1){
create(&l,value);

}

return 0;
}
