//Note: In printing topview of a tree,among the Nodes at the same horizontol distance
//the one that is encountered first while traversal is printed. 
#include<iostream>
#include<queue>
#include<vector>
#include <map>
using namespace std;
struct Node
{
	int key;
	Node* left,*right;
};

void topView(Node* root)
{
	if(root==NULL)
		return;
		
	 unordered_map<int, int> m;
	 queue<pair<Node*, int> > q;
 
	
	q.push(make_pair(root,0));
	
	while(!q.empty())
	{
		pair<Node*, int> p=q.front();
		Node* n=p.first;
		int val=p.second;					//val is the horizontol distance
		q.pop();
		
		// if horizontal value is not in the hashmap 
        // that means it is the first value with that
        // horizontal distance so print it and store 
        // this value in hashmap
        if(m.find(val)==m.end())
        {
        	m[val]=n->key;
        	cout<<n->key<<" ";
		}
		
		if(n->left!=NULL)
		{
			q.push(make_pair(n->left,val-1));
		}
		if(n->right!=NULL)
		{
			q.push(make_pair(n->right,val+1));
		}
	}
}

Node* newNode(int key)
{
	Node* node=new Node;
	node->key=key;
	node->left=node->right=NULL;
	return node;
}
int main()
{
	Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->right=newNode(4);
    root->left->right->right=newNode(5);
    root->left->right->right->right=newNode(6);
	topView(root);
	return 0;
}
