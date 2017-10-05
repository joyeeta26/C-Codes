#include<stdio.h>
#define MAXS 3
void transfer(struct queue* q);
void Display(struct queue q);
void initialize(struct queue* q);
void InsertQ(struct queue* q,int x);
int deleteQ(struct queue* q);
void push(struct stack* s,int x);
int pop(struct stack * s);
struct stack
{
	int top;
	int A[MAXS];
};
struct queue
{
	struct stack s1,s2;
};

void print(struct stack s)
{
	int t;
		t=s.top;
		while(t!=-1)
		{
			printf("%d ",s.A[t]);
			t--;
		}
		printf("\n"); 
}
void transfer(struct queue* q)
{
	int x;
	while(q->s1.top!=-1)
		{
			x=pop(&q->s1);
			push(&q->s2,x);
		}
}
void Display(struct queue q)
{
	int x,t;
	if(q.s2.top==-1&&q.s2.top!=-1)
	{
		transfer(&q);
		print(q.s2);
		
	}
	else if(q.s2.top!=-1&&q.s1.top!=-1)
	{
		print(q.s2);
		q.s2.top=-1;
		transfer(&q);
		print(q.s2);
		
	}
	else
		print(q.s2);
	
}
void initialize(struct queue* q)
{
	q->s1.top=-1;
	q->s2.top=-1;
}
void InsertQ(struct queue* q,int x)
{
	if(q->s1.top==MAXS)
		printf("Queue full!!");
	else
	{
		push(&q->s1,x);
	}
	
}
int deleteQ(struct queue* q)
{
	int x;
	if(q->s1.top==-1 && q->s2.top==-1)
	{
		printf("Empty Queue\n");
		return -1;
	}
	if(q->s2.top==-1)
	{
		transfer(q);
	}

	x=pop(&q->s2);
	return x;
}
void push(struct stack* s,int x)
{
	s->top++;
	s->A[s->top]=x;
}
int pop(struct stack * s)
{
	int x;
	x=s->A[s->top];
	s->top--;
	return x;
}
int main()
{
	struct queue q;
	initialize(&q);
	int x;
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	char ch;
	do
	{
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("enter value which u want to insert\n");
			scanf("%d",&x);
			InsertQ(&q,x);
			break;
			case 2:
			deleteQ(&q);
			break;
			case 3:
				Display(q);
				break;
			default:
				printf("wrong choice!!\n");
		}
	}while(ch<4);
	return 0;
}

