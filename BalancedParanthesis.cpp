#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
stack <char> S;

bool isPair(char ch)
{

	if((ch==')' && S.top()=='(') || (ch==']'&& S.top()=='[')||(ch=='}'|| S.top()=='{'))
	{
		return true;	
	}
	else
	return false;
}
bool matchParenthesis(string str)
{
	while(!S.empty())
	S.pop();
	string exp="[{(";
	string Exp="]})";
	string::iterator itr;
	for(itr=str.begin();itr<=str.end();itr++)
	{
		if(exp.find(*itr)!=string::npos)			//npos=-1 implying not found
		{
			S.push(*itr);
		}
		else if(Exp.find(*itr)!=string::npos)
		{
			if(S.empty()||!(isPair(*itr)))
			{
				return false;
			}
			else
				S.pop();
		}
		
		
	}
	 return S.empty()?true:false;
}
int main()
{
	string str;
	
	cout<<"Enter a string\n";
	cin>>str;
	
	
	

	if(matchParenthesis(str))
	{
		cout<<"Balanced";
	}
	else
	cout<<"Unbalanced!\n";
	return 0;
}

