// lab 6 zad 2
#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class DomesticAnimal{
protected:
	float weight;
	double price;
	char color[20];
public:
	DomesticAnimal(){
		cout << "Constructor without parameters" << endl;
	}
	DomesticAnimal(float temp1, double temp2, char* temp3){
		weight = temp1;
		price = temp2;
		strcpy_s(color, temp3);
	}
	virtual void print();
};

class Cow : virtual public DomesticAnimal{
public:
	Cow(){
		cout << "Constructor default Cow" << endl;
	}
	Cow(float temp1, double temp2, char* temp3) :DomesticAnimal(temp1, temp2, temp3){

	}
	void print(){
		cout << " void print Cow" << endl;
		DomesticAnimal::print();
	}
};

class Buffalo : virtual public DomesticAnimal{
public:
	Buffalo(){
		cout << "Constructor default Buffalo" << endl;
	}
	Buffalo(float temp1, double temp2, char* temp3) :DomesticAnimal(temp1, temp2, temp3){

	}
	void print(){
		cout << " void print Buffalo" << endl;
		DomesticAnimal::print();
	}
};

class Beefalo : public Cow, public Buffalo{
public:
	Beefalo(float temp1, double temp2, char* temp3) : DomesticAnimal(temp1, temp2, temp3){
	}
	void print(){
		cout << " void print Beefalo" << endl;
		DomesticAnimal::print();
	}
};

void DomesticAnimal::print(){
	cout << "DomesticAnimal" << endl;
	cout << "weight = " << weight << endl;
	cout << "price = " << price << endl;
	cout << "color = " << color << endl;
}

int main(){
	//DomesticAnimal obj(45.4, 1500.333, "Black");
	//obj.print();

	Cow temp1(67.4, 34, "Brown");
	temp1.print();

	cout << " =======================" << endl;

	Beefalo temp2(34.4, 123, "Light brown");
	temp2.print();

	return 0;
}