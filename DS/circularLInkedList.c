#include<stdio.h>
#include<process.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* Insert(struct Node* start,int x)
{
	
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
		if(p==NULL)
		{
			printf("error");
			exit(0);
		}
		p->data=x;
	if(start==NULL)
	{
		
		start=p;
		start->next=start;
	}
	else if(x<start->data)
	{
		p->next=start;
		start=p;
	}
	else
	{
		struct Node* temp=start;
		
		while(temp->next!=start && x>temp->next->data)
		{
			temp=temp->next;
				printf("data inserted!\n");
		}
		if(temp->next==start)
		{
			temp->next=p;
			p->next=start;
				printf("data inserted!\n");
		}
		else
		{
			p->next=temp->next;
			temp->next=p;
				printf("data inserted!\n");
		}
	}

return start;	
}
void Display(struct Node* start)
{
	struct Node* temp=start;
	if(temp!=NULL)
	{
	do{
		printf("%d",temp->data);
		temp=temp->next;
	}while(temp!=start);
	}	
}
int main()
{
	struct Node* start=NULL;
	int choice,ch,x,max=0;
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.count Nodes\n");
	printf("5.reverse linked list\n");
	printf("6.largest element\n");
	
	do
	{
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter value to insert\n");
				scanf("%d",&x);
				start=Insert(start,x);
			break;
			case 2:
				printf("Enter the position of the node u want to delete:\n");
				scanf("%d",&x);
			//	start=Delete(start,x);
			break;
			case 3:
				Display(start);
				printf("\n");
			break;
			case 4:
			//	printf("Total Nodes=%d\n",countNodes(start));
			break;
			case 5:
			//	start=Reverse(start);
				break;
			case 6:
			//	printf("largest elememt=%d\n",maxNode(start));
			break;
			
			default:
			printf("Wrong choice\n");	
		}
		printf("Enter 1 to continue\n");
		scanf("%d",&ch);
	}while(ch==1);
	return 0;
}


