#include<stdio.h>
# define MAXQ 2
struct queue
{
	int front;
	int rear;
	int A[MAXQ];
};
void initialize(struct queue* q)
{
	q->front=0;
	q->rear=0;
}
int Delete(struct queue* q)
{
	int x;
	if(q->front==q->rear)
	{
		printf("Queue is empty\n");
		return -1;
	}
	x=q->A[q->front];
	q->front=(q->front+1)%MAXQ;
	return x;
}
void Display(struct queue q)
{
	int i;
	if(q.rear==q.front)
	printf("Empty queue\n");
	else
	{
		i=q.front;
		do{
			printf("%d\t",q.A[i]);
			i=(i+1)%MAXQ;
		}while(i!=q.rear);
		printf("\n");
	}
}
void Insert(struct queue* q,int x)
{
	if((q->rear+1)%MAXQ==q->front)
	{
		printf("Queue is full\n");
	}
	else
	{
		q->A[q->rear]=x;
		q->rear=(q->rear+1)%MAXQ;
		printf("value inserted\n");
	}
}
int main()
{
	struct queue q;
	int ch,x;
	initialize(&q);

	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Dsplay\n");
	printf("4.Exit\n");
	char choice;
	do{
	printf("Enter choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter value to be inserted:\n");
			scanf("%d",&x);
			Insert(&q,x);
		
			break;
		case 2:
			x=Delete(&q);
			if(x!=-1)
			printf("Deleted value=%d\n",x);
			
			break;
		case 3:
			Display(q);
			break;
	//	default:
	//		printf("Wrong choice\n");
	//		break;
	}
	//printf("Do you want to continue?");
	//scanf(" %c",&choice);
}while(ch<4);
	return 0;
}

