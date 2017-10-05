#include<iostream>

using namespace std;
class string
{
	char* p;
	int len;
	public:
		string(){
			len=0;
			p=0;
		};
		string(const char* s);
		string(const string& s);
		~string(){
			delete p;
		};
		friend string operator+(string& a,string& t);
		friend int operator<=(string& a,string& b); 
		friend void show(const string s);
};

string::string(const char *s)
{
	 len=strlen(s);
	 p=new char[len+1];
	 strcpy(p,s);
}
string::string(const string& s)
{
	len=s.len;
	p=new char[len+1];
	strcpy(p,s.p);	
} 
string string::operator+(string& s,string& t)
{
	string temp;
	temp.len=s.len+t.len;
	temp.p=new char[temp.len+1];
	strcpy(temp.p,s.p);
	strcat(temp.p,t.p);
	return temp.p;
}
int string::operator<=(string &s,string &t)
{
	int len1=s.len;
	int len2=t.len;
	if(len1>=len2)
	return 1;
	else 
	return 0;
}
void show(const string s)
{
	cout<<s.p<<"\n";
}
int main()
{
	string s1="New";					
	string s2="York";
	string s3="Delhi";
	string string1,string2,string3;
	string1=s1;	
	string2=s2;
	string3=s1+s3;
	
	cout<<"string 1:";show(string1);
	cout<<"string 2:";show(string2);
	cout<<"\n\n";
	cout<<"string 3:";show(string3);
	if(string1<=string3)
	{
		show(string1);
		cout<<" is smaller than ";
		show(string3);
		cout<<"\n";	
	}			
	else
	{
		show(string3);
		cout<<" is smaller than ";
		show(string1);
		cout<<"\n";
	}
	return 0;
}

