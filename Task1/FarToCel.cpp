#include<iostream>
using namespace std;
int main(){
	float Ftemp;
	cout<<"enter the Fahrenheit temperature : ";
	cin>>Ftemp;
	float Ctemp=(Ftemp-32)*5/9;
	cout<<"the equivalent celius temperature is : "<<Ctemp<<"C"<<endl;
	return 0;

}
