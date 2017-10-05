#include<stdio.h>
#define MAXS 3
struct stack
{
	int A[MAXS];
	int top;
};
struct stack s,s2;
void initialize(struct stack *s)
{
	s->top=-1;
}
int push(struct stack *s,int x)
{
	if(s->top==MAXS)
		return -1;
	else
		{
			s->top++;
			s->A[s->top]=x;
			printf("Inserted\n");
		}
		return 0;
}
int pop(struct stack *s)
{
	int x;
	if(s->top==-1)
	{
		return -1;
	}
	x=s->A[s->top];
	s->top--;
	return x;
}
void display(struct stack s)
{
	int i;
	i=s.top;
	while(i!=-1)
	{
		printf("%d ",s.A[i]);
		i--;
	}
}
void transfer(struct stack* s,struct stack* s1)
{
	int i,v;

		for(i=s1->top;i!=-1;i--)
		{
			
			v=push(s,s1->A[i]);
		}
	
		s1->top=-1;
		
}
int main()
{

	int ch,x,i;
	initialize(&s);
	initialize(&s2);
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	do
	{
		printf("\nEnter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter value\n");
				scanf("%d",&x);
				i=push(&s,x);
				if(i==-1)
					i=push(&s2,x);
				if(i==-1)
					printf("stack overflow\n");
				break;
			case 2:
				x=pop(&s);
				if(x!=-1)
				{
					printf("deleted value=%d\n",x);
				}
				else
				{
					transfer(&s,&s2);
					x=pop(&s);
					if(x!=-1)
					printf("deleted value=%d\n",x);
					else
					printf("stack underflow\n");
					
				}
				break;
			case 3:
				display(s);
				break;
			default:
				printf("you entered wrong choice :( \n");
		}
	}while(ch<4);
	return 0;
}
