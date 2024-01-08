#include <iostream>
using namespace std;
class Numbers
{
private:
	double value;

public:
	Numbers(double value) : value(value) {}

	Numbers operator+(Numbers &second)
	{
		return Numbers(value + second.value);
	}
	Numbers operator-(Numbers &second)
	{
		return Numbers(value - second.value);
	}
	Numbers operator*(Numbers &second)
	{
		return Numbers(value * second.value);
	}
	Numbers operator/(Numbers &second)
	{
		return Numbers(value / second.value);
	}

	void display()
	{
		cout << "Value : " << value << endl;
	}
};
int main()
{
	Numbers n1(5.0);
	Numbers n2(3.0);

	Numbers res_add = n1 + n2;
	Numbers res_sub = n1 - n2;
	Numbers res_mul = n1 * n2;
	Numbers res_div = n1 / n2;

	cout << "n1 : ";
	n1.display();

	cout << "n2 : ";
	n2.display();

	cout << "n1+n2 : ";
	res_add.display();

	cout << "n1-n2 : ";
	res_sub.display();

	cout << "n1*n1 : ";
	res_mul.display();

	cout << "n1/n2 : ";
	res_div.display();

	return 0;
}
