#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	srand(static_cast<unsigned int>(time(nullptr)));
	int randomNumber=rand()%100+1;
	int guessingNumber;
	int noOfAttempts=1; 	
	cout<<"enter the guessing number : ";
	cin>>guessingNumber;
	while(true){
	if(guessingNumber==randomNumber){
		cout<<"congragulations! your guess "<<guessingNumber<<" is correct"<<endl;
		break;
	}
	else{
		cout<<"try again : ";
		cin>>guessingNumber;
		noOfAttempts++;
		if((randomNumber-10)>guessingNumber)
			cout<<"too low"<<endl;
		else if((randomNumber+10)<guessingNumber)
			cout<<"too high"<<endl;
		else
			cout<<"near by"<<endl;


	}
	
	}
	cout<<"No of Attempts taken : "<<noOfAttempts<<endl;
	return 0;
}
