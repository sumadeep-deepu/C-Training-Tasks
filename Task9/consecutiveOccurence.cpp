#include<iostream>
#include<string>
using namespace std;

string compressString(string& line){
	string compressed;

	 if(line.empty()){
		return compressed;
	}

	char currentChar=line[0];
	int count=1;
	for(int i=1;i<line.length();i++){
		if(line[i]==currentChar){
			count++;
		}
		else{
			compressed+=currentChar;
			compressed+=to_string(count);
			currentChar=line[i];
			count=1;
		}
	}
	compressed+=currentChar;
	compressed+=to_string(count);
	return compressed;
}

int main(){
	string line;
	cout<<"Enter the string : ";
	cin>>line;
	string compressedString=compressString(line);
	cout<<"the original String is : "<<line<<endl;
	cout<<"compressed string is : "<<compressedString<<endl;

return 0;

}

