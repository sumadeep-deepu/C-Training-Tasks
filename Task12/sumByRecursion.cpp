#include <iostream>
using namespace std;
int sumOfDigits(int num)
{
	if (num <= 0)
	{
		return 0;
	}
	return ((num % 10) + sumOfDigits(num / 10));
}
int main()
{
	int num;
	cout << "enter the number : ";
	cin >> num;
	cout << "sum of digits is : " << sumOfDigits(num) << endl;
	return 0;
}
