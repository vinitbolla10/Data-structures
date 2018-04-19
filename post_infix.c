#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct stack{
	char exp[MAX];
	int top;
}stack;

typedef struct stack *s,*op,*opr,*infix;

void init(stack *s);
void push(stack *s,char str);
int isfull(stack *s);
int isempty(stack *s);
int pop(stack *s);

int main(){
	stack s,op,opr,infix;
	
	char str,tmp,x,y,z;
	int count=0,count1=0;;
	init(&s);
	init(&op);
	init(&opr);
	init(&infix);
		if(!isfull(&s)){
			while(scanf("%c",&str)!=-1){
				push(&s,str);		
				}
			}
			else{
				printf("\nstack is full..!!!!!!!!!!!\n");
				
				}

	while(!isempty(&s)){
			tmp=pop(&s);
			printf("\n-------%c",tmp);
			
		}		
		
				while(1){
					printf("\n--------------------------------------------------------------------------------------\n");
					while(!isempty(&s)){
						
						tmp=pop(&s);
						if(( tmp >= 'a'||tmp <= 'Z' )){
					                printf("\npushing operands.........\n");				
							push(&op,tmp);
							count++;
						}
						else if(tmp >= 42 ||tmp <= 47){
							printf("\npushing operator.........\n");
							push(&opr,tmp);
							count1=count1+2;
						}
						else{
							printf("Invalid expression..re-enter the expression.....!!!!!!!");
							break;
						}
			
						if(count==2 && count1==2){
					            printf("infix--------");
							x=pop(&op);
							y=pop(&op);
							z=pop(&opr);
							push(&infix,x);
							push(&infix,z);
							push(&infix,y);	
							count=count-2;				
							count1=count1-2;			
						}
					}
				break;
						
				}
///*	printf("\npostfix string\n");	
				while(!isempty(&infix)){
					printf("infix poping:");					
						tmp=pop(&infix);
						printf("%c",tmp);
					}  
}

void init(stack *s){
	
	s->top=0;	
	}

void push(stack *s,char str){
	s->exp[s->top]=str;
	s->top++;
	return;
}

int pop(stack *s){
	char tmp;
	
	s->top--;
	tmp=s->exp[s-> top];
	//printf("\ndone poping:%d",temp);
	return tmp;
}

int isempty(stack *s){
	return s->top==0;
}


int isfull(stack *s){
	return s->top==MAX;
}



