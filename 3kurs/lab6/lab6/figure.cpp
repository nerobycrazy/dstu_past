#include "stdafx.h"
#include "figure.h"

// методы Circle
Circle::Circle(double radius){
	if (radius < 0)
		exit(1);
	else
		r = radius;
}

double Circle::area() {
	return 3.14*r*r;
}

void Circle::show(){ 
	cout << "circle with radius = " << r << " and area = " << area() << endl;
}

double& Circle::get_r(){
	return r;
}
// методы Rectangle
Rectangle::Rectangle(double _a, double _b){
	a = _a;
	if (_b == 0)
		b = _a;
	else
		b = _b;
}
double Rectangle::area(){
	return a*b;
}
void Rectangle::show(){
	if (a == b)
		cout << "square with side a = "<< a <<" and area = " << area() << endl;
	else
		cout << "rectangle with side a = " << a << " side b = "<< b <<" and area = " << area() << endl;
}
double& Rectangle::get_a(){
	return a;
}
double& Rectangle::get_b(){
	return b;
}

