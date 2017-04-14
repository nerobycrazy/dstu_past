// lab8.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getx(){
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);

	return bi.dwCursorPosition.X;
}

int gety(){
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);

	return bi.dwCursorPosition.Y;
}


//	1. ��������, ��� ������ ���������������� �������� �������������  oct, 
//		hex, dec, setfill, setw � setprecision:
//		�� ���������  �������, �� ������ ������� ������ ��� �� ����� ������?

//	2. ��������, ��� ���������� ��� ������ ����������� setprecision :
//		����� �������� ���� ��� ����� ���� ����� ������� ?
//	�	��������� �� ���������� ���������� ��� ������ ������� ���������� ?

//	3. ������ ����� ���� float.����� ������ ����, ��������, � 12 ��������,
//		������� ��� ������ : � ������� � ������� �������.�����  ������� ��� ���
//		2 ����(������ ��� � ����� ������) � �������  �������
//		� ������������� ����� � ������ � �������� ������������ '-'.

//#define ZADANIE1

//	��������� ��������� ��� �������� ������ ������������� ��������
//	�����-������ �������-������ ������ ios.

//#define ZADANIE2_3

//	1. ������� ����������� ��� ���������� endp, ������� ������������ ����� 
//		���������� ����� � ��� ���������� �������� ���������  �������� ��������
//		�� ����� ��������. ����� ����� �� �������� ����������� � �������-������������.
//		��� ������������(����� �� �����) ������� �� ����� ��������  �������������
//		������� ����� - ���� ������, ��������, "---------".
#define row 24
ostream &endp(ostream &stream){
	if (gety() % 24 == 0){
		gotoxy(0, gety() + row);
		gotoxy(0, gety() - row);
		cout << setw(79) << "-" << endl;
	}
	return stream;
}

ostream &endp(ostream &stream, int n){
	if (gety() % n == 0){
		gotoxy(0, gety() + row);
		gotoxy(0, gety() - row);
		cout << setw(79) << "-" << endl;
	}
		return stream;
}
ostream &fendp(ostream &stream, int n, char *str){
	if (gety() % n == 0){
		gotoxy(0, gety() + row);
		gotoxy(0, gety() - row);
		while (getx() + strlen(str) <= 80)
			cout << str;
		cout << endl;
	}
	return stream;
}

//	2. ������� ����������� ����������� endp(n), �� � ����������, �������� ������� 
//		�������� �� ����� �������� : ���� ������� ����� � ������� - ������������ 
//		����� �������� ������� ��������� n, �� ����������� ������� �� ����� ��������.

//	3. ������� ����������� � ����� ���������� fendp(n, s), ��� n - ���������� ����� 
//		�� ��������   s - ������ - �����������, ����������� � ����� ��������.

//������� 5.
//	�������� ��������� ��� �������� ������������ ���������� ������� ����� : 
//	���������� ����� �������� � ����� �������� � �����������  �������� ������;
//	��������� ������ ������� peek, putback, ignore.

#define ZADANIE456

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
#ifdef ZADANIE1
	cout << "�������� ������������� oct,dec,hex" << endl; 
	// �� ������ ��������
	int value = 64;
	cout << oct;
	cout << "Value(64) = oct " << value << endl;
	cout << dec;
	cout << "Value(64) = dec " << value << endl;
	cout << hex;
	cout << "Value(64) = hex " << value << endl << dec;
	
	cout << endl << "�������� ������������ setfill setw" << endl;
	cout << setfill('_');		// ���� �� �������������
	cout << setw(5);			// ��� ������� ��������
	cout << value << endl;
	cout << value << endl;
	cout << endl << "�������� ������������ setprecision" << endl; 
	double PI = 3.148755551234;
	cout << setprecision(10);	// �� ������ ��������
	cout << PI << endl;
	cout << PI + 10 << endl;	// ����� �������� ����
	cout << setprecision(6);
	cout << PI << endl << setfill(' ');			// ����������

	cout << endl << "�������� ������������ scientific, left, right" << endl;
	float num = 45.45632;
	cout << setw(12) << num << endl;
	cout << scientific << num << endl << fixed;
	cout << setfill('_');
	cout << setw(20) << left << num << endl;
	cout << setw(20) << right << num << endl;
	cout << setfill(' ');
#endif

#ifdef ZADANIE2_3
	
	cout.setf(ios::boolalpha);
	cout.fill(' ');
	cout.precision(4);
	bool log_false = 0, log_true = 1;
	cout << log_false << endl << log_true << endl;

	cout.unsetf(ios::dec);

	cout.setf(ios::oct); 
	cout.setf(ios::showbase);
	cout.setf(ios::uppercase);
	cout.setf(ios::left);
	int value;
	cout << "������� ����� ����� ";
	cin >> value;
	cout.width(20);
	cout << "oct = " << value << endl;

	cout.unsetf(ios::oct);
	cout.width(20);
	cout << "dec = " << value << endl;

	cout.width(20);
	cout.setf(ios::hex);
	cout << "hex = " << value << endl;
	cout.unsetf(ios::showbase);
	cout.unsetf(ios::uppercase);
	cout.unsetf(ios::left);
	

#endif 

#ifdef ZADANIE456

	//for (int i = 0; i <= 50; i++)
		//cout << endp << "x" << endl;
		//endp(cout, 10) << "x" << endl;
		//fendp(cout,10,"�����������") << "x" << endl;

	char ch;
	const int limit_m = 1000;
	char mas[limit_m];

	const int limit = 13;

	//cin.get(ch); // ������ ������ ������� �� ������
	//cout << endl << "ch = " << ch << endl;

	while (cin.get(mas,limit)){
		int get_count = cin.gcount();
		cout << " ���������� ��������� ��������: "
			<< get_count << endl;
		if (get_count < limit - 1)
			cin.ignore();
		cout << " �������� : " << mas << endl;
		cin.putback('\n');
	}
#endif
	return 0;
}

