//WAP to convert a given Postfix expression into its equivalent Prefix expression and evaluate it using stack. 
#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct stack
{
  int top;
  char Operand[10][20];
  int arr[10];
};

void init(struct stack *);
void push (struct stack *,char *);   //for pushing the elements in stack
char * pop (struct stack *);  //for poping
int evaluate(int,int,char instr);
void push1 ( struct stack *,int );
int pop1 (struct stack *);

int main()
{
    int len=0,i,value1,value2,value,temp;
    char x[10],y[10],t[10],instr[10],instr1[10];
    struct stack s;
    init(&s);

    printf("\nenter an expression in postfix form:\t");
    scanf("%s",instr);
    len=strlen(instr);

    for(i=0;i<len;i++)
    {
        t[0]=instr[i];
        t[1]='\0';

        if (isalpha(instr[i]))
        {
            push(&s,t);
        }

        else
        {
            strcpy(x,pop(&s));
            strcpy(y,pop(&s));

            strcat(y,x);
            strcat(t,y);
            push(&s,t);
        }
    }

    for(i=0;i<=s.top;i++)
    {
        printf("\n\nprefix form is: %s\t",s.Operand[s.top]);
    }

    printf("\n\nEnter Expression in digits followed by operators: \t");
    scanf("%s",instr1);
    len=strlen(instr1);

    for(i=0;i<len;i++)
    {
            if(isdigit(instr1[i]))
            {
               
                push1(&s,instr1[i]-'0');
            }
            else
            {
                 value1 = pop1(&s);
                 value2 = pop1(&s);
                 temp = evaluate (value1,value2,instr1[i]);
                 push1(&s,temp);
            }
    }
    printf("\n\nThe value of expression : %d/n",temp);
return 0;
}

void init (struct stack * s)
{
    s->top = -1;
}

void push(struct stack * s, char * x)
{
    s->top++;
    strcpy(s->Operand[s->top],x);
}

void push1( struct stack *s,int x)
{
   s->top++;
   s->arr[s->top] = x;
}


char *pop (struct stack *s)
{
    return(s->Operand[s->top--]);
}

int pop1 (struct stack *s)
{
    return(s->arr[s->top--]);
}

int evaluate(int value1,int value2,char temp1)
{
    int v;
    switch (temp1)
    {
     case '+':
         return (value1 + value2);
         break;

     case '-' :
          return (value1 - value2);
          break;

     case '*':
        return (value1 * value2);
        break;

     case '/':
        return (value1 / value2);
        break;
    }
}
/*output:
enter an expression in postfix form:	abc*+


prefix form is: +a*bc	

Enter Expression in digits followed by operators: 	123*+


The value of expression : 7

*/
