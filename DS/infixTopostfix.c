#include<stdio.h>
#define MAXS 20

void push(char stack[],char x,int* top)
{
	if(*top<MAXS)
	{
		*top++;
		stack[*top]=x;
	}
	else
	{
		printf("stack is full\n");
		
	}
}
char pop( char stack[],int* top)
{
	 char val;
	if(*top==-1)
	printf("stack is empty\n");
	else
	{
		val=stack[*top];
		*top--;
	}
	return val;
}
 prec(char ch)
 {
 	switch(ch)
 	{
 		
 		case '$':return 0;
		case '+':
		case '-':return 1;
		case '/':
		case '*':return 2;
		case '(':return 3;
		
	}
}
 isOpenParenthesis(char ch)
{
		if(ch=='(')
		return 1;
		else
		return 0;
} 
 isOperand(char ch)
{
	if((ch>='0' && ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	return 1;
	return 0;
}
void convert(char infix[],char postfix[])
{
	 int top=-1;
	char stack[MAXS];
	push(stack,'$',&top);
	 int i=0,j=0;
	while(infix[i]!='\0')
	{
		if(isOperand(infix[i]))
			postfix[j++]=infix[i];
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
				postfix[j++]=pop(stack,&top);
			}
			pop(stack,&top);					
		}
		else if(prec(infix[i])>prec(stack[top]))
		{
			push(stack,infix[i],&top);
		
		}
		else if(prec(infix[i])<=prec(stack[top]))
		{
			while(prec(infix[i])<=prec(stack[top]))
			{
				
				postfix[j++]=pop(stack,&top);
			}
			push(stack,infix[i],&top);
		}
	i++;	
	}
	postfix[i]='\0';
}
 main()
{
	char infix[20],postfix[20];
	printf("enter the expression in infix form\n");
	scanf("%s",&infix);	
	printf("the postfix form of the expresion is:\n");
	convert(infix,postfix);
	printf("%s",postfix);
	return 0;
}

