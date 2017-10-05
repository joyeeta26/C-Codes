#include<iostream>
#include<queue>
using namespace std;

struct bstNode
{
	char data;
	bstNode* left;
	bstNode* right;
};

struct bstNode* findMinNode(bstNode* root)
{
	while(root->left!=NULL)
	root=root->left;
	return root;
}

//Deleting a node
struct bstNode* Delete(struct bstNode* root,int data)
{
	if(root==NULL)
	return root;
	
	else if(data<root->data) root->left=Delete(root->left,data);
	else if(data>root->data) root->right=Delete(root->right,data);
   else  
   {
   		//No child
	   if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		//one child
		else if(root->left==NULL)
		{
			bstNode* temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			bstNode* temp=root;
			root=root->left;
			delete temp;
		}
		//two child
		else
		{
		    bstNode* temp=findMinNode(root->right);
			root->data=temp->data;
			root->right=Delete(root->right,temp->data);
		}
	}
	return root;
}
//finding height of a tree
int findHeight(bstNode* root)
{
	if(root==NULL)
	return -1;						//height of an empty node is -1
	else
	return max(findHeight(root->left),findHeight(root->right))+1;
}

//level order traversal(Level by Level)
void levelOrder(bstNode* root)
{
	if(root==NULL)
		return;
	queue<bstNode*> Q;				//creating a queue to store node pointers
	Q.push(root);
	while(!Q.empty())				//while queue is not empty
	{
		bstNode* current=Q.front();
		cout<<current->data<<" ";		//visiting nodes from front
		if(current->left!=NULL)	
			Q.push(current->left);
		if(current->right!=NULL)
			Q.push(current->right);
		Q.pop();					//removing front node
	}
}

//In Order traversal(L D R)
void inOrder(bstNode* root)
{
	if(root==NULL)
	return;
		inOrder(root->left);	
		cout<<root->data<<" ";
		inOrder(root->right);
		
	
}

//pre order traversal(D L R)
void preOrder(bstNode* root)
{
	if(root==NULL)
	return;
		
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
}
//post order traversal(L R D)
void postOrder(bstNode* root)
{
	if(root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

//creating new Node
bstNode* getNewNode(char data)
{
	bstNode* newNode=new bstNode;
	newNode->data=data;
	newNode->left=newNode->right=NULL;

	return newNode;
}
//Finding minimum value
int findMin(bstNode* root)						//root is local to this func
{
	if(root==NULL)
	{
		cout<<"Error: Tree is empty!";
		return -1;	
	}
	else
	{
		while(root->left!=NULL)
		{
			root=root->left;	
		}
		return root->data;
	}
				
}
//finding max value 
int findMax(bstNode* root)						//root is local to this func
{
	if(root==NULL)
	{
		cout<<"Error: Tree is empty!";
		return -1;	
	}
	else
	{
		while(root->right!=NULL)
		{
			root=root->right;	
		}
		return root->data;
	}
				
}

//finding min value using recursion
int findMinRec(bstNode* root)						//root is local to this func
{
	if(root==NULL)
	{
		cout<<"Error: Tree is empty!";
		return -1;	
	}
	else if(root->left==NULL)
	{
		return root->data;
	}
	return (char)findMinRec(root->left);
}

//finding min value using recursion
int findMaxRec(bstNode* root)						//root is local to this func
{
	if(root==NULL)
	{
		cout<<"Error: Tree is empty!";
		return -1;	
	}
	else if(root->right==NULL)
	{
		return root->data;
	}
	return findMaxRec(root->right);
				
}

//Insertion
bstNode* Insert(bstNode* root,char data)
{
	if(root==NULL)
	{
		root=getNewNode(data);
	}
	else if(data<=root->data)
	{
		root->left=Insert(root->left,data);
	}
	else
	{
		root->right=Insert(root->right,data);
	}
	
	return root;
}

//search
bool Search(bstNode* root,char data)
{
	if(root==NULL)				return false;
	else if(root->data==data)	return true;
	else if(data<=root->data)   return Search(root->left,data);
	else						return Search(root->right,data);
}

int main()
{
	bstNode* root=NULL;						//as root is local to the main func it needs to be modified everytime insertion takes place
	char ch,data;
	int choice;
	cout<<"*****Trees*****\n\n";
	cout<<"Enter your choice";
	cout<<"\n1.Insert";
	cout<<"\n2.Search";
	cout<<"\n3.Find Max/Min value using Recursion";
	cout<<"\n4.Find Max/Min value using Iteration";
	cout<<"\n5.Find height of the tree";
	cout<<"\n6.Level-order traversal";			//breadth first
	//depth first
	cout<<"\n7.pre-order traversal";
	cout<<"\n8.In-order traversal";	
	cout<<"\n9.post-order traversal\n";
	cout<<"10.Deleting Node";			
	do
	{
		cout<<"\nEnter choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
			root=Insert(root,'F');
			root=Insert(root,'D');
			root=Insert(root,'B');
			root=Insert(root,'A');
			root=Insert(root,'C');
			root=Insert(root,'E');
			root=Insert(root,'J');
			root=Insert(root,'G');
			root=Insert(root,'I');
			root=Insert(root,'H');
			root=Insert(root,'K');
			
			//cout<<"Enter data to be inserted\n";
			//cin>>data;
			//root=Insert(root,data);
			cout<<"Data inserted\n";
			break;
			
			case 2:
			cout<<"Enter data to be searched:\n";
			cin>>data;
			if(Search(root,data)==true) 	cout<<"Found\n";
			else							cout<<"Not found!!";
			break;
			
			case 3:
			cout<<"The maximum value in the tree is:"<<(char)findMaxRec(root);
			cout<<"\nThe minimum value in the tree is:"<<(char)findMinRec(root)<<"\n";
			break;
			
			case 4:
			cout<<"The maximum value in the tree is:"<<(char)findMax(root)<<"\n";
			cout<<"The minimum value in the tree is:"<<(char)findMin(root)<<"\n\n";
			break;
			
			case 5:
			cout<<"The height of the binary search tree is:"<<findHeight(root);
			break;
			
			case 6:
			cout<<"The level-order traversal of the list is as follows:\n";
			levelOrder(root);
			cout<<"\n";
			break;
			
			case 7:
			cout<<"The pre-order traversal of the list is as follows:\n";
			preOrder(root);
			cout<<"\n";
			break;

			case 8:
			cout<<"The In-order traversal of the list is as follows:\n";
			inOrder(root);
			cout<<"\n";
			break;
			
			case 9:
			cout<<"The post-order traversal of the list is as follows:\n";
			postOrder(root);
			cout<<"\n";
			break;
			
			case 10:
				cout<<"Enter the value to be deleted\n";
				cin>>data;
				Delete(root,data);
				cout<<"Deleted!\n";
				break;
						
			default:
			cout<<"Invalid choice";	
		}
		cout<<"\nDo you want to continue?";
		cin>>ch;	
	}while(ch=='y'||ch=='Y');	
		
	return 0;
}

