#include<iostream>
using namespace std;

namespace Geometry{
	const double PI=22.0/7.0;
	const double E=2.71828;
}

namespace Shapes{
	double Area(double radius){
		return Geometry::PI*(radius*radius);
	}
	double Area(double length,double breadth){
		return length*breadth;
	}
}
using namespace Shapes;
main(){
	double radius,length,breadth;
	cout<<"enter the radius of circle : ";
	cin>>radius;
	cout<<"Area of the circle  : "<<Area(radius)<<endl;
	cout<<"enter the length : ";
	cin>>length;
	cout<<"enter breadth : ";
	cin>>breadth;
	cout<<"Area of rectangle : "<<Area(length,breadth)<<endl;
}
