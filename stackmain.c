#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "stack.h"
int main(){
	stack s;
	int a,b;
	char c;
		init(&s);
		while(!isfull(&s)){
			printf("Enter the element to push:");
			scanf("%d",&a);
			push(&s,a);
	
		}
	while(!isempty(&s)){
		b=pop(&s);
		printf("poped element-------%d\n",b);

	}
	/*while()		
	printf("Enter the choice:[Y/N]");
		scanf("%c",&c);
		
		if(c=='Y'||c=='y'){
			printf("Enter the element to be push:");
			scanf("%d",&a);
			push(&s,a);
		}
		else if(c=='N'||c=='n'){
	//		printf("Exit:");
			b=pop(&s);
			printf("poped ele%d",b);			
		}
*/


	
       return 0;
}
