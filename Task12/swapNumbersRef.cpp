#include <iostream>
using namespace std;
void swapNumbers(int &a, int &b)
{
	int temp;
	temp = b;
	b = a;
	a = temp;
	cout << "value of a : " << a << endl;
	cout << "value of b :" << b << endl;
}
int multiplyNumbers(int a, int b)
{
	return a * b;
}
int main()
{
	int num1, num2;
	cout << "enter number 1 : ";
	cin >> num1;
	cout << "enter number 2 : ";
	cin >> num2;
	swapNumbers(num1, num2);
	cout << "product of two values : " << multiplyNumbers(num1, num2) << endl;

	return 0;
}
