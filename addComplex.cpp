#include<iostream>
using namespace std;
class Complex
{
	float real;
	float imag;
	public:
		Complex add(Complex&,Complex&);
		void input(float r,float i)
		{
			real=r;
			imag=i;
		}
		void display();
};
void Complex::display()
{
	cout<<real<<"+ i("<<imag<<")\n";
}
Complex Complex::add(Complex& c1,Complex& c2)
{
	real=c1.real+c2.real;
	imag=c2.imag+c1.imag;

}
int main()
{
	Complex c1,c2,c3;
	float r,i;
	cout<<"Enter the real and imaginary parts of the first complex number:\n";
	cin>>r>>i;
	c1.input(r,i);
	cout<<"Enter the real and imaginary parts of the second complex number:\n";
	cin>>r>>i;
	c2.input(r,i);
	cout<<"The addition of the 2 complex nos:\n";
	c3.add(c1,c2);
	c1.display();
	cout<<"+\n";
	c2.display();
	cout<<"= ";c3.display();
	return 0;
}

