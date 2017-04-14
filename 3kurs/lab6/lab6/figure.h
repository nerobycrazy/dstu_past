#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

class Figure{
public:
	virtual double area() = 0;
	virtual void show() = 0;
};

class Circle : public Figure{
private:
	double r;
public:
	Circle(double radius);
	double area();
	void show();
	double& get_r();
};

class Rectangle : public Figure{
private:
	double a;
	double b;
public:
	Rectangle(double _a, double _b=0);
	double area();
	void show();
	double& get_a();
	double& get_b();
};
