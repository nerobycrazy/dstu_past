// STL_k.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

//#define VECTOR
//#define LIST
//#define QUEUE

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
#ifdef VECTOR
	//**********************************************************
	//							Вектор
	//**********************************************************
	int arraySize = 0;
	cout << "Введите размер массива: ";
	cin >> arraySize;
	vector<int> array(arraySize);

	for (int i = 0; i < array.size(); i++){
		cout << "Введите " << i << "-ый элемент массива: ";
		cin >> array[i];
	}

	cout << endl << "Введенный массив: \n";
	if (!array.empty())
		copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
	cout << "\nКоличество элементов массива: " << array.size() << endl;

	vector<int> array2 = array;
	cout << "\nЭлементы массива 2(копия 1)" << endl;
	copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));

	cout << "\n\nПервый элемент массива 2: \t" << array2.front() << endl;
	cout << "Последний элемент массива 2: \t" << array2.back() << endl;
	
	array2.insert(array2.begin(), 1008);
	cout << "Массив 2 с новым первым элементом: \n";
	copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));

	array.clear(); // теперь массив 1 пуст
	array2.push_back(12); // в конец массива 2  добавили 12
	
	cout << "Массив 2 с новым последним элементом: \n";
	copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));
	
	sort(array2.begin(), array2.end());
	cout << "\nОтсортированный массив 2: \n";
	copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));

	cout << "\nРеверс вектора" << endl;
	for (auto rit = array2.rbegin(); rit < array2.rend(); ++rit)
		cout << *rit << ends;

	cout << "\n\nMax size array2: " << array2.max_size();
#endif

#ifdef LIST
	//***************************************
	//				СПИСОК
	//***************************************
	list<int> newList;
	srand(time(NULL));

	for (int i = 0; i < 15; i++)
		newList.push_back(rand()%20);

	cout << "\n Список:" << endl;
	copy(newList.begin(), newList.end(), ostream_iterator<int>(cout, " "));
	cout << "\nПервый элемент списка:		" << newList.front();
	cout << "\nПоследний элемент списка:	" << newList.back();
	cout << "\n";

	newList.sort();

	cout << "\n Отсортированный список:" << endl;
	copy(newList.begin(), newList.end(), ostream_iterator<int>(cout, " "));

	newList.unique();

	cout << "\n Удалили дубликаты:" << endl;
	copy(newList.begin(), newList.end(), ostream_iterator<int>(cout, " "));

	list<int> newList2;
	for (int i = 0; i < 5; i++)
		newList2.push_back(rand()%20);
	
	newList2.sort();
	newList2.merge(newList); // объединение списков 
	// объединяет только сортированные списки!!!

	cout << "\n Объединенные списки 1 и 2:" << endl;
	copy(newList2.begin(), newList2.end(), ostream_iterator<int>(cout, " "));

#endif

#ifdef QUEUE
	queue<int> newqueue;
	newqueue.push(13);
	newqueue.push(15);
	newqueue.push(243);

	cout << "Размер очереди" << newqueue.size() << endl;
	while (newqueue.size() != 0){
		cout << newqueue.front() << " ";
		newqueue.pop();
	}
	
#endif
	return 0;
}

