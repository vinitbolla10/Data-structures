/*
*NAME:- VINIT BOLLA
*DATE:- 16/02/18
*ROLL_NO. :- H-54
*
*Q. Wirte C or C++ program to convert postfix expression to infix expression.
*/
#include<stdio.h>
#include<string.h>
struct stack
{
	char key[50];
}s[50],temp;
int top=-1;
void main()
{
	char str[50],t[50],t1[50],con[100],t2[50];
	int i,n,flag=0;
	printf("Enter postfix expression:\n");
	scanf("%s",str);//store the expression
	n=strlen(str);
	printf("Infix Expression:\n");
	for(i=0;i<n;i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='%'||str[i]=='/'||str[i]=='*')
		{
			strcpy(con,"");
			t2[0]=str[i];

			strcpy(t,s[top].key);//pop the character 1
			top--;
			strcpy(t1,s[top].key);//pop the character 2
			top--;
			strcat(con,t1);
			strcat(con,t2);
			strcat(con,t);
			top++;
			strcpy(s[top].key,con);//push the expression
				
		}

		else
		{
			t2[0]=str[i];
			top++;
			strcpy(s[top].key,t2);//push the character
		}
		
	}
	printf("%s\n",s[top].key);	//print the infix expression		
	
}

