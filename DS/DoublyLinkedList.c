#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* head;
struct Node* getNewNode(int x)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));		//dynamic memory allocation
	(*newNode).data=x;				//dereferencing newNode
	(*newNode).next=NULL;
	(*newNode).prev=NULL;
}

//insertion at head
void insertAtHead(int x)
{
	struct Node* newNode=getNewNode(x);
	printf("Inserting at head :%d\n",x);
	if(head==NULL)
	{
		head=newNode;
		return;
	}
	else
	{
		head->prev=newNode;
		newNode->next=head;
		head=newNode;
		
			
	}
}

//inserting at tail
void inserAtTail(int x)
{
	struct Node* newNode=getNewNode(x);
	printf("Inserting at tail :%d\n",x);
	if(head==NULL)
	{
		head=newNode;
		return;
	}
	else
	{
		struct Node* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		newNode->prev=temp;
		temp->next=newNode;
	}
}
//printing of Nodes
void print()
{
	struct Node* temp=head;
	printf("Forward: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
//reversing the linked list
void reverse(struct Node* head)
{
	 struct Node* current=head;
    struct Node* temp=NULL;
    while(current!=NULL)
    {
        temp=current->next;
        current->next=current->prev;
        current->prev=temp;
        current=current->prev;
    }
    if(temp!=NULL)
    {
       head=temp;
    }
	
		
		
}

//reverse print
void revPrint()
{
	struct Node* temp=head;
	printf("Reverse: ");
	if (temp==NULL) return;
	while(temp->next!=NULL)			//going to the last node
	{
		temp=temp->next;
	}
	while(temp!=NULL)				//printing backwards
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
int main()
{
	head=NULL;
	insertAtHead(2);	print();	revPrint();
	insertAtHead(3);	print();	revPrint();
	inserAtTail(5);		print();	revPrint();
	inserAtTail(9);		print();	revPrint();
	reverse(head);		print();
	return 0;
}
