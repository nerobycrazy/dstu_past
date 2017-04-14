// lab8.cpp: определяет точку входа для консольного приложения.
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


//	1. Выяснить, как далеко распространяется действие манипуляторов  oct, 
//		hex, dec, setfill, setw и setprecision:
//		на ближайший  операнд, на данную цепочку вывода или до явной отмены?

//	2. Выяснить, что определяет при выводе манипулятор setprecision :
//		число значащих цифр или число цифр после запятой ?
//	П	роисходит ли округление результата или лишние разряды обрезаются ?

//	3. Задано число типа float.Задав ширину поля, например, в 12 символов,
//		вывести его дважды : в обычной и научной нотации.Затем  вывести его еще
//		2 раза(каждый раз с новой строки) в обычной  нотации
//		с выравниванием влево и вправо и символом заполнителем '-'.

//#define ZADANIE1

//	Составить программу для проверки работы форматирующих операций
//	ввода-вывода функций-членов класса ios.

//#define ZADANIE2_3

//	1. Создать манипулятор без параметров endp, который подсчитывает число 
//		выведенных строк и при заполнении страницы выполняет  операцию перехода
//		на новую страницу. Число строк на странице фиксировано в функции-манипуляторе.
//		При тестировании(вывод на экран) переход на новую страницу  смоделировать
//		выводом какой - либо строки, например, "---------".
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

//	2. Создать аналогичный манипулятор endp(n), но с параметром, задающим условие 
//		перехода на новую страницу : если счетчик строк в функции - манипуляторе 
//		имеет значение большее заданного n, то осуществить переход на новую страницу.

//	3. Создать манипулятор с двумя парамтрами fendp(n, s), где n - количество строк 
//		на странице   s - строка - приглашение, выводящееся в конце страницы.

//Задание 5.
//	Написать программу для проверки возможностей управления потоком ввода : 
//	ограничить число вводимых в буфер символов с последующей  очисткой потока;
//	проверить работу функций peek, putback, ignore.

#define ZADANIE456

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
#ifdef ZADANIE1
	cout << "Действие манипуляторов oct,dec,hex" << endl; 
	// до отмены действия
	int value = 64;
	cout << oct;
	cout << "Value(64) = oct " << value << endl;
	cout << dec;
	cout << "Value(64) = dec " << value << endl;
	cout << hex;
	cout << "Value(64) = hex " << value << endl << dec;
	
	cout << endl << "Действие манипулятора setfill setw" << endl;
	cout << setfill('_');		// пока не переопределим
	cout << setw(5);			// для первого операнда
	cout << value << endl;
	cout << value << endl;
	cout << endl << "Действие манипулятора setprecision" << endl; 
	double PI = 3.148755551234;
	cout << setprecision(10);	// до отмены действия
	cout << PI << endl;
	cout << PI + 10 << endl;	// число значащих цифр
	cout << setprecision(6);
	cout << PI << endl << setfill(' ');			// округление

	cout << endl << "Действие манипулятора scientific, left, right" << endl;
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
	cout << "Введите целое число ";
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
		//fendp(cout,10,"Приглашение") << "x" << endl;

	char ch;
	const int limit_m = 1000;
	char mas[limit_m];

	const int limit = 13;

	//cin.get(ch); // чтение одного символа из потока
	//cout << endl << "ch = " << ch << endl;

	while (cin.get(mas,limit)){
		int get_count = cin.gcount();
		cout << " фактически прочитано символов: "
			<< get_count << endl;
		if (get_count < limit - 1)
			cin.ignore();
		cout << " Записано : " << mas << endl;
		cin.putback('\n');
	}
#endif
	return 0;
}

