// labwork1.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	void for_name(char*); //������ ������� ��� ��������� ������������
	void for_name_with_cena(char*,float);	//������ ������� ��� ��������� ������������, 
											//���� ������� �� ��������� ���������;
	void for_srok(int); // ������ �������, ���� �������� ������� ������ ���������.
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
	cout << "������� ������������ " << endl;
	cin >> naimenovanie;
	cout << "������� �������������" << endl;
	cin >> proizvoditel;
	cout << "������� ����" << endl;
	cin >> cena;
	cout << "������� ���� ��������" << endl;
	cin >> srok_hranen;
	cout << "������� ����������" << endl;
	cin >> count;
}
void Product::show(){
	cout << "������������ " << naimenovanie << endl;
	cout << "������������� " << proizvoditel << endl;
	cout << "���� " << cena << endl;
	cout << "���� �������� " << srok_hranen << endl;
	cout << "���������� " << count << endl;
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
		Product("�������", "����", 300.5, 3, 50),
		Product("������", "����� �������", 50.8, 1, 50),
		Product("���", "����������", 243.5, 5, 51),
		Product("������", "��-��-��", 270.6, 1, 20),
		Product("����","����� � ������", 50.3, 6, 6)
	};
	for (int i = 0; i <= 4; i++){
		mas_Product[i].show();
	}
	//system("CLS");  // ������� �������
	cout << "----��������� ��������------" << endl;
	//mas_Product[0].set(); // ���������

	mas_Product[0].show();
	// a)
	cout << "======������ �� ������������=======" << endl;
	for (int i = 0; i <= 4; i++){
		mas_Product[i].for_name("���");
	}
	// �)
	cout << "======������ �� ������������ + ���� �� ���������=======" << endl;
	for (int i = 0; i <= 4; i++){
		mas_Product[i].for_name_with_cena("���", 243.5);
	}
	// �)
	cout << "======������, ���� �������� ������ ����������=======" << endl;
	for (int i = 0; i <= 4; i++){
		mas_Product[i].for_srok(1);
	}
	return 0;
}

