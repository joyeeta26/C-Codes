#include<iostream>
#include<string.h>
#include<stack>

using namespace std;
stack<int> S;

int Evaluate(int op1,int op2,char op)
{
	switch(op)
	{
		case '+': return op1+op2;
		case '-': return op1-op2;
		case '*': return op1*op2;
		case '/': return op1/op2;
		default:
		cout<<"wrong operator\n";
	}
}
	
int prefix(char* exp)
{
	int len=0;
	for( len=0;exp[len];len++);
	
	for(int i=len-1;i>=0;i--)
	{
		if(isdigit(exp[i]))
		S.push(exp[i]-'0');
		else
		{
			int op1=S.top(); S.pop();
			int op2=S.top(); S.pop();
			S.push(Evaluate(op1,op2,exp[i]));
		}
	}
	return S.top();
}

int postfix(char* exp)
{
	
	int  res=0;
	for(int i=0;exp[i];i++)
	{
		if(isdigit(exp[i]))
			S.push(exp[i]-'0');
		else
		{
			int op2=S.top();
			S.pop();
			int op1=S.top();
			S.pop();
			S.push(Evaluate(op1,op2,exp[i]));
		}
	}
	return S.top();
}
int main()
{
	int choice;
	char ch;
	char str[40];
	cout<<"Which type of expression do u want to evaluate?\n";
	cout<<"1.Prefix\n";
	cout<<"2.Postfix\n";
	do
	{
		cout<<"Enter choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
			cout<<"Enter the expression\n";
			cin>>str;
			cout<<"The value of the expression is: "<<prefix(str)<<"\n";
			break;
			case 2:
			cout<<"Enter the expression\n";
			cin>>str;
			cout<<"The value of the expression is: "<<postfix(str)<<"\n";
			break;
			default:
				cout<<"Sorry! No such option found!\n";
		}
		cout<<"Do you want to continue?\n";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}

