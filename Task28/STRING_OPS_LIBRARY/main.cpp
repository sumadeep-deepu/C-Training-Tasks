#include "stringOperations.h"
#include <iostream>
using namespace std;
int main()
{
	string str1, str2;
	cout << "enter the string 1: ";
	cin >> str1;
	cout << "enter the string 2: ";
	cin >> str2;
	cout << "reverse of str 1 is " << reverse(str1) << endl;
	cout << "reverse of str 2 is " << reverse(str2) << endl;
	string str3 = concate(str1, str2);
	cout << "the concatenation od two strings is  : " << str3 << endl;
	cout << "reverse of concatenated string is : " << reverse(str3) << endl;
	int start, end;
	cout << "enter the starting index : ";
	cin >> start;
	cout << "enter the ending index : ";
	cin >> end;
	if (start + end >= str3.length())
	{
		cout << "the size of string exceeded !!!" << endl;
		return 1;
	}
	cout << "substring is  : " << substr(str3, start, end) << endl;
	return 0;
}
