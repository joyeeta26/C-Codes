#include<stdio.h>
#define MAXS 20
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
		printf("stack is full\n");
	else
		{
			s->top++;
			s->A[s->top]=x;
		}
}
int pop(struct satck *s)
{
	int x;
	if(s->top==-1)
	{
		printf("stack is empty\n");
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
	int ch,i;
	initialize(&s);
	printf("!.Push\n");
	printf("2.Pop\n");
	printf("3.")
	return 0;
}

