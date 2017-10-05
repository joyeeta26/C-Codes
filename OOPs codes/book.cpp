#include<iostream>
using namespace std;
class BOOK
{
	int Book_no;
	char book_name[20];
	float price;
	void total_cost(int N)
	{
		float tc=N*price;
		cout<<"\nThe total cost of "<<N<<" copies is Rs."<<tc<<"\nThanks for shopping..";
	}
	public:
		void INPUT()
		{
			cout<<"Enter the following information:\n";
			cout<<"Book NO:";
			cin>>Book_no;cout<<"\n";
			
			cout<<"Book Name:";
			cin>>book_name;cout<<"\n";
			
			cout<<"price:";
			cin>>price;cout<<"\n";
			
		}
		void purchase()
		{
			int N;
			cout<<"Enter the no of copies u want to purchase:\n";
			cin>>N;
			total_cost(N);
		}
};
int main()
{
	BOOK book;
	book.INPUT();
	book.purchase();
	return 0;
}

