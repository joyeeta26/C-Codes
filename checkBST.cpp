#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left,* right;
};
Node* getNewNode(int data)
{
	Node* newNode=new Node;
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
bool bstUtil(Node* root,int minVal,int maxVal)
{
	if(root==NULL)
	return true;
	if(root->data>minVal && root->data<maxVal && bstUtil(root->left,minVal,root->data) && bstUtil(root->right,root->data,maxVal))
		return true;
	else
		return false;
}
bool isBST(Node* root)
{
	return bstUtil(root,INT_MIN,INT_MAX);
}
int main()
{
	
	return 0;
}

