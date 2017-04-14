// STL_k.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	//							������
	//**********************************************************
	int arraySize = 0;
	cout << "������� ������ �������: ";
	cin >> arraySize;
	vector<int> array(arraySize);

	for (int i = 0; i < array.size(); i++){
		cout << "������� " << i << "-�� ������� �������: ";
		cin >> array[i];
	}

	cout << endl << "��������� ������: \n";
	if (!array.empty())
		copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
	cout << "\n���������� ��������� �������: " << array.size() << endl;

	vector<int> array2 = array;
	cout << "\n�������� ������� 2(����� 1)" << endl;
	copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));

	cout << "\n\n������ ������� ������� 2: \t" << array2.front() << endl;
	cout << "��������� ������� ������� 2: \t" << array2.back() << endl;
	
	array2.insert(array2.begin(), 1008);
	cout << "������ 2 � ����� ������ ���������: \n";
	copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));

	array.clear(); // ������ ������ 1 ����
	array2.push_back(12); // � ����� ������� 2  �������� 12
	
	cout << "������ 2 � ����� ��������� ���������: \n";
	copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));
	
	sort(array2.begin(), array2.end());
	cout << "\n��������������� ������ 2: \n";
	copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));

	cout << "\n������ �������" << endl;
	for (auto rit = array2.rbegin(); rit < array2.rend(); ++rit)
		cout << *rit << ends;

	cout << "\n\nMax size array2: " << array2.max_size();
#endif

#ifdef LIST
	//***************************************
	//				������
	//***************************************
	list<int> newList;
	srand(time(NULL));

	for (int i = 0; i < 15; i++)
		newList.push_back(rand()%20);

	cout << "\n ������:" << endl;
	copy(newList.begin(), newList.end(), ostream_iterator<int>(cout, " "));
	cout << "\n������ ������� ������:		" << newList.front();
	cout << "\n��������� ������� ������:	" << newList.back();
	cout << "\n";

	newList.sort();

	cout << "\n ��������������� ������:" << endl;
	copy(newList.begin(), newList.end(), ostream_iterator<int>(cout, " "));

	newList.unique();

	cout << "\n ������� ���������:" << endl;
	copy(newList.begin(), newList.end(), ostream_iterator<int>(cout, " "));

	list<int> newList2;
	for (int i = 0; i < 5; i++)
		newList2.push_back(rand()%20);
	
	newList2.sort();
	newList2.merge(newList); // ����������� ������� 
	// ���������� ������ ������������� ������!!!

	cout << "\n ������������ ������ 1 � 2:" << endl;
	copy(newList2.begin(), newList2.end(), ostream_iterator<int>(cout, " "));

#endif

#ifdef QUEUE
	queue<int> newqueue;
	newqueue.push(13);
	newqueue.push(15);
	newqueue.push(243);

	cout << "������ �������" << newqueue.size() << endl;
	while (newqueue.size() != 0){
		cout << newqueue.front() << " ";
		newqueue.pop();
	}
	
#endif
	return 0;
}

