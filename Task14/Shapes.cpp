#include <iostream>
using namespace std;
const double pi = 22.0 / 7.0;
class Shape
{
public:
	virtual void calculateArea() = 0;
};
class Circle : public Shape
{
private:
	double radius;

public:
	Circle(double rad) : radius(rad) {}

	void calculateArea()
	{
		double area = pi * radius * radius;
		cout << "area of the circle : " << area << endl;
	}
};
class Rectangle : public Shape
{
private:
	long length, breadth;

public:
	Rectangle(long len, long b) : length(len), breadth(b) {}

	void calculateArea()
	{
		long area = length * breadth;
		cout << "area of the ractangle : " << area << endl;
	}
};
int main()
{
	Shape *cir = new Circle(2.45);
	Shape *rect = new Rectangle(5, 6);
	cir->calculateArea();
	rect->calculateArea();
	return 0;
}
