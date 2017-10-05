#include<stdio.h>
#define MAXS 3
struct stack
{
	int A[MAXS];
	int top;
};
void initialize(struct stack *s)
{
	s->top=-1;
}
void push(struct stack *s,int x)
{
	if(s->top==MAXS)
		printf("stack overflow\n");
	else
		{
			s->top++;
			s->A[s->top]=x;
			printf("Inserted\n");
		}
}
int pop(struct stack *s)
{
	int x;
	if(s->top==-1)
	{
		printf("stack underflow\n");
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
int main()
{
	struct stack s;
	int ch,x;
	initialize(&s);
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
				push(&s,x);
				
				break;
			case 2:
				x=pop(&s);
				if(x!=-1)
				{
					printf("deleted value=%d\n",x);
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

