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
	double radius;
	long length,breadth;
	cout<<"enter the radius : ";
 	cin>>radius;
	Shape *cir = new Circle(radius);
	cir->calculateArea();
	cout<<"enter length and breadth : ";
	cin>>length,breadth;
	Shape *rect = new Rectangle(length,breadth);
	rect->calculateArea();
	return 0;
}
