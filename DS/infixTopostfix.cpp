#include<iostream>
#include<stack>
using namespace std;
stack<char> S;
string postfixExp="";
bool isOpenParenthesis(char ch);
bool isRightAssociative(char ch);
bool isOperator(char op);
int operatorWeight(char op);
bool HasHigherPrecedence(char ch);
bool isOperand(char);
void postfix(string exp);
int main()
{
	string exp;
	cout<<"Enter expression in infix form:\n";
	cin>>exp;
	cout<<"The postfix form of the expression is:\n";
	postfix(exp);
	cout<<postfixExp;
	return 0;
}
bool isOpenParenthesis(char ch)
{
	if(ch=='['||ch=='('||ch=='{')
		return true;
	else
		return false;
}
bool isRightAssociative(char ch)
{
	if(ch=='^')return true;
	else
	return false;
}
int operatorWeight(char op)
{
	switch(op)
	{
		case '+':
		case '-':return 1;
		break;
		case '*':
		case '/':return 2;
		break;
		case '^':return 3;
		break;
	}
}
bool isOperator(char op)
{
if(op=='+'||op=='-'||op=='*'||op=='/'||op=='^')
return true;
else
return false;
}
bool HasHigherPrecedence(char ch)
{
	if(operatorWeight(S.top())>operatorWeight(ch))
	return true;
	else if(operatorWeight(S.top())==operatorWeight(ch))
	{
		if(isRightAssociative(ch))
			return false;
		else
			return true;
	}
	else
		return false;
}
bool isOperand(char ch)
{
	if((ch>='0' && ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	return true;
	return false;
	
}
void postfix(string exp)
{
	for(int i=0;exp[i];i++)
	{
		if(exp[i]==' '||exp[i]==',')
		continue;
		else if(isOperand(exp[i]))
			postfixExp+=exp[i];
		else if(isOperator(exp[i]))
		{
			while(!S.empty() && !isOpenParenthesis(S.top()) && HasHigherPrecedence(exp[i]))
			{
				postfixExp+=S.top();
				S.pop();
			}
			S.push(exp[i]);
		}
		else if(isOpenParenthesis(exp[i]))
			S.push(exp[i]);
		else
		{
			while(!S.empty()&&!isOpenParenthesis(S.top()))
			{
				postfixExp+=S.top();
				S.pop();
			}
			S.pop();
		}
	}
	while(!S.empty())
	{
		postfixExp+=S.top();
		S.pop();
	}
}

