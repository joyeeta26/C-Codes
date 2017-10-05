#include<iostream>
using namespace std;
class bank
{
	char name[20];
	int accNo;
	char type;
	float bal;
	public:
		void getData();
		void deposit();
		void withdraw();
		void display();
		int getAccNo();
};
		void bank:: getData(){
			cout<<"Name:";  cin>>name;
			cout<<"Account no:";cin>>accNo;
cout<<"Type of Account(Enter 'C' for current/ Enter 'S' for           Savings):"; cin>>type;
			cout<<"Balance:";cin>>bal;
		}
		void bank:: deposit(){
			float amount;
			cout<<"Enter how much you want to deposit?\n";
			cin>>amount;
			bal+=amount;
			cout<<"Amount deposited successfully\n";
		}
		void bank::withdraw(){
			float amount;
			if(bal<1000 )
			 cout<<"Insufficient balance\n";
			else{
				cout<<"Enter how much you want to withdraw?\n";
				cin>>amount;
				if(amount>bal)
					cout<<"Sorry!! Insufficient Balance\n";
					else{
						bal-=amount;
						cout<<"Amount withdrawn successfully\n";
					}
			}
		}
		void bank::display(){
			cout<<"********************\n";
			cout<<"Account Details:\n";
			cout<<"Name:"<<name<<"\n";
			cout<<"Account Number:"<<accNo<<"\n";
			cout<<"Type of Account:"<<type<<"\n";
			cout<<"Balance:"<<bal<<"\n";
			cout<<"********************\n";
		}
		int bank:: getAccNo(){
			return accNo;
		}
int main(){
	bank b[10];int n;
	cout<<"for how many customers u want to feed data?\n";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter the following informations for the customer:"<<i+1<<"\n";
		b[i].getData();		
	}
	char ch;
	int no,pos,choice;
	cout<<"\nTransactions\n";
	cout<<"1.Deposit\n";
	cout<<"2.Withdraw\n";
	cout<<"3.Display\n";
	do{
		cout<<"Enter the Account Number:\n";
		cin>>no;
		cout<<"which of the following services would u like to avail?\n";
		cin>>choice;
		for(int i=0;i<10;i++){
			if(b[i].getAccNo()==no)
				pos=i;
		}
		switch(choice){
			case 1:   b[pos].deposit(); 		break;
			case 2:   b[pos].withdraw();		break;
			case 3:    b[pos].display();		break;
			default:   cout<<"Invalid choice\n";
		}
		cout<<"Do u want to continue?\n";
		cin>>ch;
	}while(ch=='y'||ch=='Y');	
	return 0;
}

