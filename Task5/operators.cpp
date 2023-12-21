#include<iostream>
using namespace std;
void arthematicOperators(){
	cout<<"Arthematic operators : "<<endl;
	int number1,number2;
	cout<<"enter number 1 : ";
	cin>>number1;
	cout<<"enter numbber 2 : ";
	cin>>number2;
	cout<<"the sum of two numbers is : "<<number1+number2<<endl;
	cout<<"the difference  of two numbers is : "<<number1-number2<<endl;
	cout<<"the product of two numbers is : "<<number1*number2<<endl;
	cout<<"the quotient of  two numbers is : "<<number1/number2<<endl;
	cout<<"the remainder of two numbers is : "<<number1%number2<<end;
}
void relationalOperators(){
	cout<<endl;
	cout<<"Relational Operators : "<<endl;
	int number3,number4;
	cout<<"enter number 1 : ";
	cin>>number3;
	cout<<"enter number 2 : ";
	cin>>number4;
	
	cout<<"Equality : "<<(number3==number4)<<endl;
	cout<<"In-Equality : "<<(number3!=number4)<<endl;
	cout<<"greater than : "<<(number3>number4)<<endl;
	cout<<"less than : "<<(number3<number4)<<endl;
}
void logicalOperators(){
	cout<<endl;
	cout<<"Logical operators : "<<endl;
	bool a,b;
	cout<<"enter first value(0 or 1) : ";
	cin>>a;
	cout<<"enter second value(0 or 1) : ";
	cin>>b;
	cout<<"Logical AND  : "<<(a&&b)<<endl;
	cout<<"Logical OR : "<<(a||b)<<endl;
	cout<<"Logical NOT for first value : "<<!(a)<<endl;
	cout<<"Logical NOT for second value : "<<!(b)<<endl;
}
void assignmentOperators(){
	cout<<endl;
	cout<<"Assignment Operators : "<<endl;
	int x=5;
	cout<<"Intialized variable : "<<x<<endl;
	x+=4;
	cout<<"using += operaor : "<<x<<endl;
	x*=2;
	cout<<"using *= operator : "<<x<<endl;
	x%=2;
	cout<<"using %= operator : "<<x<<endl;
	cout<<"Final value of x  : "<<x<<endl;
}
int main(){
	arthematicOperators();

	relationalOperators();

	logicalOperators();

	assignmentOperators();
return 0;
}
