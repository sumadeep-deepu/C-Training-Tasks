#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string line = "";
	string element;
	vector<string> names;
	names.push_back("sumadeep");
	names.push_back("deepak");
	names.push_back("charan");

	for (auto it = names.begin(); it != names.end(); it++)
	{
		cout << *it << endl;
	}
	for (auto it = names.begin(); it != names.end(); it++)
	{
		line += *it;
	}
	cout << endl;
	cout << line << endl;
	cout << endl;
	cout << "enter the name  to find : ";
	cin >> element;
	auto it = find(names.begin(), names.end(), element);
	if (it != names.end())
	{
		cout << "the name " << element << " is found" << endl;
	}
	else
		cout << "the name " << element << " is not found" << endl;

	return 0;
}
