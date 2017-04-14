// lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void ff(){
	cout << "global level ---> " << endl;
}

class BASE{
private:
	double d;
protected:
	long l;
public:
	int i;
	BASE(int a, double b, long c){
		i = a;
		d = b;
		l = c;
	}
	double get_d(){
		return d;
	}
	double& get_adr_d(){
		return d;
	}
	void ff(){
		cout << "func BASE ---> " << endl;
	}
};

class DERIVED : public BASE{
private:
	float f;
public:
	using BASE::i;
	using BASE::l;
	DERIVED();
	DERIVED(float f1, int i, double d, long l) :BASE(i, d, l){
		f = f1;
	}
	friend ostream& operator<<(ostream& os, DERIVED& obj);
	void ff(){
		cout << "func DERIVED ---> " << endl;
	}
};

class DERIVED1 : public DERIVED{
public:
	DERIVED1(float f, int i, double d, long l) :DERIVED(f, i, d, l){
		//cout << "cnstr drvd1" << endl;
	}
	void foo(){
		i++;
		l += 1;
		ff();
	}
};
ostream& operator<<(ostream& os, DERIVED& obj){
	os << "float f  = " << obj.f << "\t adr = " << int(&obj.f) << endl;
	os << "int i    = " << obj.i << "\t adr = " << int(&obj.i) << endl;
	os << "double d = " << obj.get_d() << "\t adr = " << int(&obj.get_adr_d()) << endl;
	os << "long l   = " << obj.l << "\t adr = " << int(&obj.l) << endl;
	return os;
}

int _tmain(int argc, _TCHAR* argv[])
{
	DERIVED obj();
	cout << "BASE " << sizeof(BASE) << " DERIVED " << sizeof(DERIVED) << endl;
	cout <<  endl;
	DERIVED obj1(4.3, 44, 45.5, 5434);
	DERIVED1 obj2(4.3, 34, 45.5, 555);
	obj2.foo();
	cout << obj1;
	return 0;
}

