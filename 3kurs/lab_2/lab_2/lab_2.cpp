// lab_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;
class Test{
	int W;
	void Z(){
		cout << "Это закрытая функция класса Test" << endl;
	}
	public:
	Test(int);
	friend void fun(Test*);
};
void fun(Test *t){
	cout << t->W << endl;
	t->Z();
}
Test::Test(int x = 1){
	W = x;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Test temp1;
	fun(&temp1);
	return 0;
}

