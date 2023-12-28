#include <iostream>
using namespace std;
class Operations
{
public:
	int addition(int a, int b)
	{
		return a + b;
	}
	double addition(double a, double b)
	{
		return (double)a + b;
	}
	int addition(int a, int b, int c)
	{
		return a + b + c;
	}
	int multiplication(int a, int b)
	{
		return a * b;
	}
	double multiplication(double a, double b)
	{
		return (double)a * b;
	}
	int multiplication(int a, int b, int c)
	{
		return a * b * c;
	}
};
int main()
{
	Operations math;
	cout << "result of additon : " << math.addition(2, 3) << endl;
	cout << "result of additon : " << math.addition(3.2, 1.4) << endl;
	cout << "result of additon : " << math.addition(2, 3, 4) << endl;
	cout << "result of multiplication : " << math.multiplication(2, 3) << endl;
	cout << "result of multiplication : " << math.multiplication(1.8, 4.2) << endl;
	cout << "result of multiplication : " << math.multiplication(2, 3, 4) << endl;
	return 0;
}
