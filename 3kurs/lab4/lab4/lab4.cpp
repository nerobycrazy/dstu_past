// lab4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;
class date{
	int day, month, year, md[13];
public:
	date(int a = 0, int b = 0, int c = 0){ // ����������� ������������
		int days[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		for (int i = 0; i < 13; i++){
			md[i] = days[i];
		}
		day = a;
		month = b;
		year = c;
	}
	date(const date &obj){ // ����������� ������������ �����������
		day = obj.day;
		month = obj.month;
		year = obj.year;
	}

	date operator+(date); // ���� + ����					### complete
	date operator+(int); // ���� + int						### complete
	friend date operator+(int, date&); // int + data		### complete
	date operator++(); // ���������� �����������  ++		### complete

	date operator-(date); // ���� - ����					### complete
	date operator-(int); // ���� - int						### complete
	date operator--(); // ���������� ����������� --			### complete

	friend ostream& operator <<(ostream&, const date&); // ������� � ����� cout		 ### complete

	void show(){
		cout <<"Date - " << day <<"." << month << "." << year << endl;
	}
};

date date::operator+(date obj){
	date temp = *this;
	temp.day += obj.day;
	while ((temp.day > md[temp.month])){
		temp.day -= md[temp.month];
		temp.month++;
		if (temp.month>12){
			temp.year++;
			temp.month = 1;
		}
	}
	//
	temp.month += obj.month;
	while (temp.month > 12){
		temp.year++;
		temp.month -= 12;
	}
	//
	temp.year += obj.year;
	return temp;
}
date date::operator+(int days){
	date temp = *this;
	temp.day += days;
	while ((temp.day > md[temp.month])){
		temp.day -= md[temp.month];
		temp.month++;
		if (temp.month>12){
			temp.year++;
			temp.month = 1;
		}
	}
	return temp;
}
date operator+(int days, date &temp){
	temp.day += days;
	while ((temp.day > temp.md[temp.month])){
		temp.day -= temp.md[temp.month];
		temp.month++;
		if (temp.month>12){
			temp.year++;
			temp.month = 1;
		}
	}
	return temp;
}
date date::operator++(){
	day++;
	if (day > md[month]){
		day = 1;
		month++;
		if (month == 13){
			month = 1;
			year++;
		}
	}
	return *this;
}
date date::operator-(date obj){
	date temp = *this;
	temp.day -= obj.day;
	while (temp.day < 1){
		temp.month--;
		if (!temp.month){
			temp.month = 12;
			temp.year--;
		}
		temp.day += md[temp.month];
	}
	temp.month -= obj.month;
	while (temp.month < 1){
		temp.year--;
		temp.month += 12;
	}
	temp.year -= obj.year;
	return temp;
}
date date::operator-(int days){
	date temp = *this;
	temp.day -= days;
	while (temp.day < 1){
		temp.month--;
		if (!temp.month){
			temp.month = 12;
			temp.year--;
		}
		temp.day += md[temp.month];
	}
	return temp;
}
date date::operator--(){
	day--;
	if (day < 1){
		month--;
		if (month == 0){
			year--;
			month = 12;
		}
		day = md[month];
	}
	return *this;
}
ostream&::operator<<(ostream& os, const date& obj){ //������� � �����
	os << obj.day << "." << obj.month << "." << obj.year;
	return os;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	date date1(29, 2, 2016);
	date date2(1200, 3, 2);
	cout << "���������� �������� \"+\" (���� + ����)" << endl;
	date date3 = date1 + date2; // ���� + ����
	
	cout << date1 << " ������������ � " << date3 << endl << endl;
	
	cout << "���������� �������� \"+\" (���� + int)" << endl;
	date date4 = date1 + 180;	// ���� + int
	cout << date1 << " to " << date4 << endl << endl;
	
	cout << "���������� �������� \"+\" (int + ����)" << endl;
	date date5 = 180 + date1;	// int + ����
	cout << date1 << " to " << date5 << endl << endl;
	
	cout << "���������� �������� \"++\" (����++)" << endl;
	date newyear(31, 12, 2016);
	cout << newyear++ << endl << endl; // ����++

	cout << "���������� �������� \"-\" (���� - ����)" << endl;
	date date6 = date1 - date2; // ���� - ����
	cout << date1 << " to " << date6 << endl << endl;

	cout << "���������� �������� \"-\" (���� - int)" << endl;
	date6 = date1 - 1800; // ���� - int
	cout << date1 << " to " << date6 << endl << endl;
	
	cout << "���������� �������� \"--\" (����--)" << endl;
	date lastyear(1, 1, 2016);
	cout << lastyear-- << endl;

	return 0;
}

