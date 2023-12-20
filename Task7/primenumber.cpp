#include<iostream>
using namespace std;
int main(){
	int number;
	cout<<"Enter a positive Integer : ";
	cin>>number;
	int divisor=2;
	bool isprime=true;
	while(divisor<=number/2){
		if(number%divisor==0){
			isprime=false;
			break;
		}
		++divisor;
	}
	if(isprime && number>1)
		cout<<number<<" is a prime number"<<endl;
	else
		cout<<number<<" is not a prime number"<<endl;
	return 0;
}
	

