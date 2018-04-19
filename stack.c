#include "stack.h"
void init(stack *s){
	s->i=0;
	}

void push(stack *s,int n){
	s->a[s->i++]=n;
	
	
}

int isempty(stack *s) {
	return s->i == 0;
}

int isfull(stack *s){
	return s->i==MAX;

}

int pop(stack *s){
	int x;
	s->i--;
	x=s->a[s->i];
	
	return x;
} 
