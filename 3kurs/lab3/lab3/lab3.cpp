// lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

class Goods{
	char name[30];
	char date[15];
	float price;
	int count;
	int nakladnaya;
public:
	float c_price(); // Вычисление стоимости
	void change(char*,char*,float,int,int);
	void show();
	Goods(char*, char*, float, int, int);
	~Goods();
	Goods(const Goods &obj){
		cout << "\nКонструктор копирования\n";
		/*
		strcpy_s(name, obj.name);
		strcpy_s(date, obj.date);
		price = obj.price;
		count = obj.count;
		nakladnaya = obj.nakladnaya;
		*/

	}
	Goods& operator=(const Goods&);
};

Goods::Goods(char* n1, char* d1, float p1, int co1, int nak1){
	cout << "#Конструктор" << endl;
	strcpy_s(name, n1);
	strcpy_s(date, d1);
	price = p1;
	count = co1;
	nakladnaya = nak1;
}
Goods::~Goods(){
	cout << "#Деструктор" << endl;
}
float Goods::c_price(){
	return price*count;
}
void Goods::change(char* n2, char* d2, float p2, int co2, int nak2){
	strcpy_s(name, n2);
	strcpy_s(date, d2);
	price = p2;
	count = co2;
	nakladnaya = nak2;
}
void Goods::show(){
	cout << name << " " << date << " " << price << " " << count << " " << nakladnaya << endl;
}

Goods& Goods::operator=(const Goods& obj){
	cout << "Перегрузка" << endl;
	strcpy_s(name, obj.name);
	strcpy_s(date, obj.date);
	price = obj.price;
	count = obj.count;
	nakladnaya = obj.nakladnaya;
	return *this;
}

void main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Вход в функцию main()" << endl;
	
	Goods obj("iPhone 5s", "14.04.2016", 52300, 2, 456); 
	obj.show();
	cout <<"ОБщая стоимость: "<< obj.c_price() << endl;

	obj.change("iPhone 6", "15.06.2016", 52333, 3, 457); // изменение полей

	obj.show();
	cout << "ОБщая стоимость: " << obj.c_price() << endl;

	Goods obj1 = obj;
	obj1 = obj;
	obj1.show();
	
	cout << "Выход из функции main()" << endl;
}

