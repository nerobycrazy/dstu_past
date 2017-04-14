// lab6_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

class Base1{
	int i;
public:
	Base1(){
		cout << "Call constructor Base1 without parameters" << endl;
		i = 0;
	}
	Base1(int temp_int){
		cout << "Call constructor Base1 with parameters" << endl;
		i = temp_int;
	}
	void put(int);
	int get();
};

class Base2{
	char name[20];
public:
	Base2(){
		cout << "Call constructor Base2 without parameters" << endl;
		strcpy_s(name, "Empty");
	}
	Base2(char* temp_char){
		cout << "Call constructor Base2 with parameters" << endl;
		strcpy_s(name, temp_char);
	}
	void put(char*);
	char* get();
};

class Derived : public Base1, public Base2{
	char ch;
public:
	Derived(){
		cout << "Call constructor Derived without parameters" << endl;
		ch = 'V';
	}

	Derived(char temp_char, char* temp_char_m, int temp_int) :Base2(temp_char_m), Base1(temp_int){
		cout << "Call constructor Derived with parameters" << endl;
		ch = temp_char;
	}
	void put(char);
	char get(void);

	friend ostream& operator<<(ostream& os, Derived& obj);
};

// Описание функций Base1
void Base1::put(int temp_int){
	i = temp_int;
}
int Base1::get(){
	return i;
}

// Описаник функций Base2
void Base2::put(char* temp_char){
	strcpy_s(name, temp_char);
}
char* Base2::get(){
	return name;
}

// Описание функций Derived
void Derived::put(char temp_char){
	ch = temp_char;
}
char Derived::get(){
	return ch;
}
ostream& operator<<(ostream& os, Derived& obj){
	os << "i    = " << obj.Base1::get() << endl;
	os << "name = " << obj.Base2::get() << endl;
	os << "ch   = " << obj.get() << endl;
	return os;
}

int _main(int argc, _TCHAR* argv[])
{
	Derived obj;
	Derived obj_par('1', "Andrew", 19);
	cout << obj;
	cout << "-----------" << endl;
	cout << obj_par;
	return 0;
}



