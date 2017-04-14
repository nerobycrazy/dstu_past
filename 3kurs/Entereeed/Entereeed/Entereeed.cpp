// Entereeed.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include "Windows.h"

using namespace std;

#define SIZE 100

class car{
		char marka[SIZE];
		int power;
		float price;
	public:
		void input();
		void output();
};

void car::input(){
	cout << "¬ведите марку авто: "<< endl;
	//cin >> marka;
	gets_s(marka);
	cout << "¬ведите мощность автомобил€" << endl;
	cin >> power;
	cout << "¬ведите стоимость" << endl;
	cin >> price;
	return;
}
void car::output(){
	cout << marka << "     " << power << "       " << price << endl;
	return;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	car car1;
	car1.input();

	system("CLS");

	car1.output();

	return 0;
}

