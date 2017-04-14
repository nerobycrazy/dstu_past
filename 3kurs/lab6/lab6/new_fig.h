#include "figure.h"

class Triangle : public Figure{
private:
	double a;
	double b;
	double c;
public:
	Triangle(double a1, double b1, double c1);
	double area();
	void show();
};