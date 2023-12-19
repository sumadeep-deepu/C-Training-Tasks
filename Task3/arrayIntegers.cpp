#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void bubbleSort(int arr[],int size){
	for(int i=0;i<size-1;++i){
		for(int j=0;j<size-i-1;++j){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main(){
const int arraySize=10;
int myArray[arraySize];
srand(static_cast<unsigned int>(time(nullptr)));
for(int i=0;i<arraySize;i++){
	myArray[i]=rand()%100+1;
}
for(int i=0;i<10;i++){
	cout<<myArray[i]<<" ";
}
cout<<endl;
int sum=0;
for(int i=0;i<arraySize;i++){
	if(myArray[i]%2==0){
	sum+=myArray[i];
}
	}
cout<<"sum of even elements in the array is : "<<sum<<endl;
cout<<"Elemets greater than 50 are : "<<endl;
for(int i=0;i<arraySize;i++){
	if(myArray[i]>50){
		cout<<myArray[i]<<" ";
	}
}

bubbleSort(myArray,arraySize);
cout<<"\nafter sorting : "<<endl;
for(int i=0;i<arraySize;i++){
	cout<<myArray[i]<<" ";
}
cout<<"\nthe second largest element in the array is : "<<myArray[arraySize-2]<<endl;

for(int i=0;i<arraySize;i++){
	cout<<myArray[i]*2<<" ";
}
return 0;
}
