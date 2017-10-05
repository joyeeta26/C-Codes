#include<stdio.h>
 struct Node
 {
 	int data;
 	struct Node* next;
 };
 struct Node* getNode(int x)
 {
 	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
 	newNode->data=x;
 	newNode->next=NULL;
 	return newNode;
 }
 struct Node* push(struct Node* top,int x)
 {
 	Node* node=getNode(x);
 	if(node==NULL)
 		printf("stack full\n");
 	else
 	{
		node->next=top;
		top=node;
	}
 }
 int pop(struct Node* top,int *val)
 {
 	if(top==NULL)
 	{
 		printf("stack is empty\n");
		return -1;	
	}

		struct Node* p=top;
		top=top->next;
		*val=p->data;
		free(p);
		return x;
 }
 
