// lab2_1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

class Notebook;

class Abonent{
	int uniq;
	char familie[30];
	char phone[15];
public:
	Abonent(int, char*, char*);
	~Abonent();
	friend Notebook;
};

class Notebook{
public:
	void change(Abonent &,int);
	void show(Abonent);
};

Abonent::Abonent(int num, char f[30], char p[15]){
	cout << "#cnstr" << endl;
	uniq = num;
	strcpy_s(familie, f);
	strcpy_s(phone, p);
}

void Notebook::change(Abonent &obj, int un){
	char pp[15];
	if (un == obj.uniq){
		cout << "������� ����� ����� ��������" << endl;
		cin >> pp;
		strcpy_s(obj.phone, pp);
	}
	else cout << "�������� ID" << endl;
}

void Notebook::show(Abonent obj){
	cout << obj.uniq << "  " << obj.familie << "  " << obj.phone << endl;
}

Abonent::~Abonent(){
	cout << "#destr" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Abonent obj_mas[5] = {
		Abonent(123, "����������", "89281235404"),
		Abonent(124, "�������", "89224123495"),
		Abonent(125, "������", "89224123495"),
		Abonent(126, "��������", "89224123495"),
		Abonent(127, "���������", "89224123495"),
	};
	Notebook work;

	for (int i = 0; i <= 4; i++)
		work.show(obj_mas[i]);

	work.change(obj_mas[0], 123);
	work.show(obj_mas[0]);



	return 0;
}

