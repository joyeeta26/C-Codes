//linked List in Ascending Order
#include<stdio.h>

struct Node
{
	int data;
	struct Node* next;
};
	int MAX=0;
struct Node* getNewNode(int x)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
struct Node* Reverse(struct Node* p)
{
	struct Node* curr,*prev;
	prev=NULL;
	curr=p;
	while(curr!=NULL)
	{
		p=p->next;
		curr->next=prev;
		prev=curr;
		curr=p;
		
	}
	return prev;
}
int maxNode(struct Node* start)
{
	if(start==NULL)
	return 0;
	else
	{
	struct Node* p=start;
	while(p!=NULL)
	{
		if(p->data>MAX)
		MAX=p->data;
		p=p->next;
	}
	}
	return MAX;
}
void Display(struct Node* start)
{
	if(start==NULL)
		return;

	printf("%d ",start->data);
	Display(start->next);				//start is not manipulated

	
}
struct Node* Delete(struct Node* start,int pos)
{
	int totalNodes=countNodes(start);
	int i;
	if(start==NULL)
		printf("empty linked list\n");
	else
	{
		struct Node* prev,*curr;
		prev=NULL;
		curr=start;
		i=1;
		if(pos>0 && pos<=totalNodes)
		{
			while(i<pos)
			{
				prev=curr;
				curr=curr->next;
				i++;
			}
			if(prev==NULL)
			{
				start=curr->next;
				free(curr);
			}
			else
			{
				prev->next=curr->next;
				free(curr);
			}
		printf("Deleted!!\n");
		}
		else
		printf("position out of range\n");
	}
	return start;
}
int countNodes(struct Node* start)
{
	if(start==NULL)
	return 0;
	else
	return (1+countNodes(start->next));			//start is not manipulated
}
/*int countNodes(struct Node** start)
{
	if(*start==NULL)
	return 0;
	else
	return (1+countNodes(&(*start->next)));			//start is not manipulated
}*/
struct Node* Insert(int x,struct Node* start)
{
	struct Node* p,*q;
	p=start;
	q=getNewNode(x);								//creating a new node
	if(q==NULL)
	{
		printf("Memory not allocated!!\n");
	}
	else
	{
		if(start==NULL||(start!=NULL && x<start->data))
		{
			q->next=start;;
			start=q;
		}
		else
		{
			while(p->next!=NULL&&(x>p->next->data))
			{
				p=p->next;
			}
			q->next=p->next;
			p->next=q;
		}
		printf("Data inserted!!\n");
	}
	return start;
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
				start=Insert(x,start);
			break;
			case 2:
				printf("Enter the position of the node u want to delete:\n");
				scanf("%d",&x);
				start=Delete(start,x);
			break;
			case 3:
				Display(start);
				printf("\n");
			break;
			case 4:
				printf("Total Nodes=%d\n",countNodes(start));
			break;
			case 5:
				start=Reverse(start);
				break;
			case 6:
				printf("largest elememt=%d\n",maxNode(start));
			break;
			
			default:
			printf("Wrong choice\n");	
		}
		printf("Enter 1 to continue\n");
		scanf("%d",&ch);
	}while(ch==1);
	return 0;
}

