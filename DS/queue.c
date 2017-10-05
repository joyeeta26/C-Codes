#include<stdio.h>
 struct Node
 {
 	int data;
 	struct Node *link;
 };
 void Delete(struct Node** front,struct Node** rear,int *value)
 {
 	if(*front==*rear && *rear==NULL)
 	{
 		printf("queue is empty!!");
 		exit(0);
	}
	strcut Node* temp=*front;
	*front=*front->link;
	*value=temp->data;
	if(*rear==*front)
	*rear=*rear->link;
	free(temp);
	
 }
 void insert(struct Node** front,struct Node** rear,int x)
 {
 	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
 	if(temp==NULL)
 	{
 		printf("failed to allocate memory!!");
 		exit(0);
	}
	temp->data=x;
	temp->link=NULL;
	if(*rear==NULL)
	{
		*rear=temp;
		*front=*rear;
	}
	else
	{
		*rear->link=temp;
		*rear=temp;
	}
 }
 void display(struct Node* front,struct Node* rear)
 {
 	if(*front==*rear && *rear==NULL)
 	{
 		printf("queue is empty");
		 exit(0);	
	}
	struct Node* temp=*front;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	
 }
int main()
{
	struct Node *front=NULL,*rear=NULL;
	int ch,ch1,x;
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	do{
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter value\n");
				scanf("%d",&ch)
				insert(&front,&rear,x);
		}
	}
	return 0;
}

