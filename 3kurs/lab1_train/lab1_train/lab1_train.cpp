// labwork1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

#define SIZE 100

class Product{
	char naimenovanie[SIZE];
	char proizvoditel[SIZE];
	float cena;
	int srok_hranen;
	int count;
public:
	Product(char* na, char* pr, float ce, int sro, int k);
	~Product();
	void set();
	void show();
	void for_name(char*); //список товаров для заданного наименования
	void for_name_with_cena(char*,float);	//список товаров для заданного наименования, 
											//цена которых не превышает указанной;
	void for_srok(int); // список товаров, срок хранения которых больше заданного.
};
Product::Product(char* na, char* pr, float ce, int sro, int k){
	strcpy_s(naimenovanie, na);
	strcpy_s(proizvoditel, pr);
	cena = ce;
	srok_hranen = sro;
	count = k;
}
Product::~Product(){
	cout << "Destructor" << endl;
}
void Product::set(){
	cout << "Введите наименование " << endl;
	cin >> naimenovanie;
	cout << "Введите производителя" << endl;
	cin >> proizvoditel;
	cout << "Введите цену" << endl;
	cin >> cena;
	cout << "Введите срок хранения" << endl;
	cin >> srok_hranen;
	cout << "Введите количество" << endl;
	cin >> count;
}
void Product::show(){
	cout << "Наименование " << naimenovanie << endl;
	cout << "Производитель " << proizvoditel << endl;
	cout << "Цена " << cena << endl;
	cout << "Срок хранения " << srok_hranen << endl;
	cout << "Количество " << count << endl;
	cout << "-------------------------" << endl;
}

void Product::for_name(char* name){
	if (strcmp(name, naimenovanie) == 0){
		show();
	}
}

void Product::for_name_with_cena(char* name, float cen){
	if ((strcmp(name, naimenovanie) == 0) && (cena <= cen)){
		show();
	}
}
void Product::for_srok(int srok){
	if (srok_hranen>srok)
		show();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Product mas_Product[5] = {
		Product("Колбаса", "Тавр", 300.5, 3, 50),
		Product("Молоко", "Белый медведь", 50.8, 1, 50),
		Product("Сыр", "Российский", 243.5, 5, 51),
		Product("Курица", "Ко-ко-ко", 270.6, 1, 20),
		Product("Яйца","Домик у бабули", 50.3, 6, 6)
	};
	for (int i = 0; i <= 4; i++){
		mas_Product[i].show();
	}
	//system("CLS");  // очистка консоли
	cout << "----Изменение продукта------" << endl;
	//mas_Product[0].set(); // изменение

	mas_Product[0].show();
	// a)
	cout << "======Список по наименованию=======" << endl;
	for (int i = 0; i <= 4; i++){
		mas_Product[i].for_name("Сыр");
	}
	// б)
	cout << "======Список по наименованию + цена не превышает=======" << endl;
	for (int i = 0; i <= 4; i++){
		mas_Product[i].for_name_with_cena("Сыр", 243.5);
	}
	// в)
	cout << "======Список, срок хранения больше указанного=======" << endl;
	for (int i = 0; i <= 4; i++){
		mas_Product[i].for_srok(1);
	}
	return 0;
}

