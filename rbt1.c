#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data, colour;
	struct node *left,*right, *parent;;
}node;

int main(){

  node *n = NULL;
	int key;
 

	while(scanf("%d",&key) != -1) {
		insert(n,key);
	}
   
   return 0;
}



void insert(node *n,int value){
	node *temp, *current= n,*head;
	int i;
	temp = (node*)malloc(sizeof(node));
	temp->data=value;
	temp->right = NULL;
	temp->left = NULL;
		if(n == NULL){
			printf("-----root node:-----");
			temp->colour = 1;
			temp->parent = NULL;
			n = temp;
			//return;					
		}
		else{
printf("-----node:-----");
			current = n;
			
			while(current != NULL){
				head = current;
	
				if(value > current->data){
					current = current->right;

						if(current==NULL){
							temp->colour = 0;							
							head->right = temp;
							temp->parent = head;
							n = temp;
			//				return;
						}									
				}
				else{
					current =  current->left;
					
						if(current==NULL){
							temp->colour = 0;							
							head->left=temp;
							temp->parent = head;
							n = temp;
			//				return;									
						}				
					
							
				}		
				
			}
		}

}
