#include<iostream>
#include<stack>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
struct Node* top=NULL;

//Stack Reversal
void Reverse()
{
	if(top==NULL)
	return;
	stack<Node*> S;
	Node* temp=top;
	while(temp!=NULL)
	{
		S.push(temp);
		temp=temp->next;
	}
	top=S.top();
	temp=S.top();
	S.pop();
	while(!S.empty())
	{
		temp->next=S.top();
		
		S.pop();
		temp=temp->next;
	}
	temp->next=NULL;
	
	
}

//creating new node
Node* getNewnode(int data)
{
	Node* newNode=new Node;
	 newNode->data=data;
	 newNode->next=NULL;
	 return newNode;
}

//Insertion of new Node
void Insert(int data)
{
	Node* newNode=getNewnode(data);
	newNode->next=top;
	top=newNode;
}

//Deletion of new Node
void Delete()
{
	Node* temp=top;
	top=top->next;
	delete temp;
}

//get the top element
int getTop()
{
	return top->data;
}

//check whether the list is empty
bool isEmpty()
{
	if(top==NULL)
	return true;
	else
	return false;
}

//displaying the list
void display()
{
	if(top==NULL)
	{
		cout<<"No elements to display!!\n";
		return;
	}
	Node* temp=top;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
		
	}
	cout<<"\n";
}

//main function
int main()
{
	int ch;
	char choice;
	
	cout<<"1.Insertion(at top)\n";
	cout<<"2.Deletion(at top)\n";
	cout<<"3.Reverse";
	cout<<"\n4.Get top\n";
	cout<<"5.Is empty\n";
	cout<<"6.Display\n";
	
	int data;
	do
	{
		cout<<"Enter choice:\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the value which u want to insert:\n";
				cin>>data;
				Insert(data);
				cout<<"Data inserted!\n";
				break;
			case 2:
				Delete();
				cout<<"Top node successfully deleted!\n";
				break;
			case 3:
				Reverse();
				cout<<"Stack after reversal:\n";
				display();
				break;
			case 4:
				cout<<"The top element of the stack is:"<<getTop()<<"\n";
				break;
			case 5:
				if(isEmpty())
					cout<<"Stack is empty!\n";
				else
					cout<<"Stack is not empty!\n";
				break;
				case 6:
					display();
					break;
			default:
				cout<<"Wrong choice entered!\n";
				
		}
		cout<<"Do u want to continue?\n";
		cin>>choice;
	}while(choice=='y');
	return 0;
}

