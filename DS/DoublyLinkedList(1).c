#include<stdio.h>
#include<process.h>

struct Node
{
	int data;
	struct Node *left, *right;
};
struct Node* InsertAtEnd(struct Node* start,struct Node** end,int x)
{
	if(start==NULL)
	{
		start=(struct Node*)malloc(sizeof(struct Node));
		if(start==NULL)
		{
			printf("Error!!");
			exit(0);
		}
		start->data=x;
		start->left=start->right=NULL;
		*end=start;
	}
	else
	{
	
		struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
		if(temp==NULL)
		{
			printf("Error\n");
			exit(0);
		}
			temp->data=x;
			temp->right=NULL;
			temp->left=*end;
			(*end)->right=temp;
			*end=temp;
		
	}
	printf("data inserted!!\n");
	return start;
}

int nodeCount(struct Node* start)
{
	if(start==NULL)
	return 0;
	else
	return(1+nodeCount(start->right));
}

struct Node* InsertAfterPos(struct Node* start,int pos,int x)
{
	struct Node *temp1,*temp2;
	int i=1;
	if(pos<0 || pos>nodeCount(start))
	{
		printf("error No such node exists!!\n");
	}
	else 
	{
			temp1=(struct Node*)malloc(sizeof(struct Node));
			if(temp1==NULL)
			{
				printf("error!!");
				exit(0);			
			}
			temp1->data=x;
		if(pos==0)
		{
		
		
			temp1->left=NULL;
			temp1->right=start;
			temp1->right->left=temp1;
			start=temp1;
		}
		else
		{
			temp2=start;
			while(i<pos)
			{
				i++;
				temp2=temp2->right;	
			}	
			temp1->right=temp2->right;
			temp1->left=temp2;
			temp1->left->right=temp1;
			temp1->right->left=temp1;
			
		}
	}
	printf("Data inserted!!\n");
	return start;
}

void displayForward(struct Node* start)
{
	if(start==NULL)
	return;

	printf("%d ",start->data);
	displayForward(start->right);
}

void displayReverse(struct Node* end)
{
	if(end==NULL)
	return;
	printf("%d ",end->data);
	displayReverse(end->left);
}

//Delete at particular position
struct Node* Delete(struct Node* start,int node_no,int *val,struct Node** end)
{
	int i=1;
	struct Node* temp,prev;
	if(start==NULL)
	{
		printf("Empty List\n");
		return start;
	}
	if(node_no<0 || node_no>nodeCount(start))
	{
		printf("No such node exists!!");
		exit(0);
	}
	if(node_no==0)
	{
		temp=start;
		start=start->right;
		start->left=NULL;
		*val=temp->data;
		free(temp);
	}
	else
	{
		temp=start;
		while(i<node_no)
		{
			i++;
			temp=temp->right;
		}
		temp->left->right=temp->right;
		if(temp->right!=NULL)
			temp->right->left=temp->left;
		else
			*end=temp;
		*val=temp->data;
		free(temp);
	}
	return start;
}
int main()
{
	struct Node *start,*end;
	start=end=NULL;
	int val,pos;
	int choice,ch,x,max=0;
	printf("1.Insert at end\n");
	printf("2.Delete at position\n");
	printf("3.Display forward\n");
	printf("4.count Nodes\n");
	printf("5.reverse linked list\n");
	printf("6.Insert after Position\n");
	printf("7.Display reverse\n");
	
	do
	{
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter value to insert\n");
				scanf("%d",&x);
				start=InsertAtEnd(start,&end,x);
			break;
			case 2:
				printf("Enter the position of the node u want to delete:\n");
				scanf("%d",&x);
				start=Delete(start,x,&val,&end);
				printf("Deleted value=%d\n",val);
			break;
			case 3:
				displayForward(start);
				printf("\n");
			break;
			case 4:
				printf("Total Nodes=%d\n",nodeCount(start));
			break;
			case 5:
			//	start=Reverse(start);
				break;
			case 6:
				printf("Enter value to insert\n");
				scanf("%d",&x);
				printf("enter the position after which u want to insert:");
				scanf("%d",&pos);
				start=InsertAfterPos(start,pos,x);
			break;
			case 7:
				displayReverse(end);
				printf("\n");
			break;
			default:
			printf("Wrong choice\n");	
		}
		printf("Enter 1 to continue\n");
		scanf("%d",&ch);
	}while(ch==1);
	return 0;
}


