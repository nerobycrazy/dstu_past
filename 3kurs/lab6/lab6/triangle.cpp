#include "stdafx.h"
#include "new_fig.h"
#include <math.h>

Triangle::Triangle(double a1, double b1, double c1){
	if (a1 + b1 > c1){
		a = a1;
		b = b1;
		c = c1;
	}
	else{ exit(1); }
}
double Triangle::area(){
	double p = (a + b + c)*0.5;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}
void Triangle::show(){
	cout << "triangle with side = " << a << ",  " << b << ",  " << c << "  area = " << area() << endl;
}
