#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
	const int size = 5;
	int myArray[size] = {2, 5, 1, 7, 9};
	try
	{
		int index;
		cout << "enter the index of the element to display : ";
		cin >> index;
		if (index >= size || index < 0)
		{
			throw out_of_range("index provided is out of range");
		}
		cout << "value at index : " << index << "is " << myArray[index] << endl;
	}
	catch (out_of_range e)
	{
		cerr << e.what() << endl;
	}
	return 0;
};
