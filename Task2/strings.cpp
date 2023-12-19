#include<vector>
#include<string>
#include<iostream>
using namespace std;

string reverse(string word){
	string r;
	for(int i = word.length() - 1;i >= 0;i--){
		r += word[i];
	}
	return r;
}
int main(){
	string sentence;
	cout<<"Enter a sentence  : ";
	getline(cin,sentence);
	vector<string>words;
	string word;
	for(char c:sentence)
	{
	   if(c==' ')
	   {
	    words.push_back(reverse(word));
	    word="";
	   }
	   else{
	   word+=c;
	   }
	   }
	words.push_back(reverse(word));	
	
	for(int i=0;i<words.size();++i){
		cout<<words[i]<<" ";
	}
	return 0;
}
