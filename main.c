#include<stdio.h>
#include<stdlib.h>
#include "tree1.h"
int main(){
	tree t;
	int data,ch;
	init(&t);
	/*while(scanf("%d",data)!=-1){
		create(&t,data);
		
	}*/	
	/*do{
	printf("1.insert\n2.display\n3.exit\nenter the choice:\n");
	scanf("%d",&ch);
	switch(ch){
	case 1:
		printf("Enter the elemnt:");
		scanf("%d",&data);
		create(&t,data);
		break;
	case 2:
		inorder(t);
		break;
	case 3:
		exit(0);

}
}while(ch!=3);*/
	while(scanf("%d", &data) != -1) {
		insert(&t, data);
	}
	inorder(t);
	return 0;
}
