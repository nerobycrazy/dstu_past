// лаба_7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

template <class T> void swap(T *x, T *y);
template <class T> T maxx(T x, T y);
char* maxx(char *strx, char *stry);
//===================================================================
class complex{
private:
	double real;
	double image;
public:
	complex() : real(0.0), image(0.0) {};
	complex(double x, double y){
		real = x;
		image = y;
	}
	complex operator+(const complex &obj){
		return complex(real + obj.real, image + obj.image);
	}
	complex operator-(const complex &obj){
		return complex(real - obj.real, image - obj.image);
	}
	friend ostream& operator<<(ostream& s, complex& obj);
	friend istream& operator>>(istream& s, complex& obj);
};

ostream& operator<<(ostream& s, complex& obj){
	s << "Real = " << obj.real << "  ";
	s << "Imag = " << obj.image;
	return s;
}

istream& operator>>(istream& s, complex& obj){
	cout << "Введите действительную часть: ";
	cin >> obj.real;
	cout << "Введите мнимую часть: ";
	cin >> obj.image;
	return s;
}
//===================================================================
template <class T>
class matrix{
private:
	T **matr;
	int row, col;
public:
	matrix(int i, int j) : row(i), col(j){
		matr = new T*[i];
		for (int i = 0; i<row; i++)
			matr[i] = new T[j];
		for (int i = 0; i<row; i++){
			for (int j = 0; j<col; j++){
				matr[i][j] = rand() % 10;
			}
		}
	}
	~matrix(){
		for (int i = 0; i<row; i++)
			delete matr[i];
		delete matr;
	}
	T& getelem(int i, int j){
		return matr[i][j];
	}
	int& getrow(){
		return row;
	}
	int& getcol(){
		return col;
	}
	void setelem(int i, int j, T z){
		matr[i][j] = z;
	}

	friend ostream& operator<<(ostream& s, const matrix<T> &x);
	friend istream& operator>>(istream& s, const matrix<T> &x);
	matrix<T>& operator+(matrix<T> &par);
	matrix<T>& operator-(matrix<T> &par);
	matrix<T>& operator=(matrix<T> &par);
};

template <class T>
ostream& operator<<(ostream& s, matrix<T> &x){
	int row = x.getrow();
	int col = x.getcol();
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++)
			s << x.getelem(i, j) << "\t";
		s << endl;
	}
	return s;
}

template <class T>
istream& operator>>(istream& s, matrix<T> &x){
	int row = x.getrow();
	int col = x.getcol();
	T tmp;
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			cout << "matr[" << i << "][" << j << "] = ";
			cin >> tmp;
			x.setelem(i, j, tmp);
		}
	}
	return s;
}

template<class T>
matrix<T>& matrix<T>::operator+(matrix<T> &par){
	int parrow = par.getrow();
	int parcol = par.getcol();
	if (parrow != this->row || parcol != this->col){
		cout << "Ранги матриц не одинаковы!!\n";
		exit(1);
	}
	matrix<T>* tmp = new matrix<T>(row, col);
	for (int i = 0; i<this->row; i++)
	for (int j = 0; j<this->col; j++)
		tmp->matr[i][j] = this->matr[i][j] + par.matr[i][j];
	return *tmp;
}

template<class T>
matrix<T>& matrix<T>::operator-(matrix<T> &par){
	int parrow = par.getrow();
	int parcol = par.getcol();
	if (parrow != this->row || parcol != this->col){
		cout << "Ранги матриц не одинаковы!!\n";
		exit(1);
	}
	matrix<T>* tmp = new matrix<T>(row, col);
	for (int i = 0; i<this->row; i++)
	for (int j = 0; j<this->col; j++)
		tmp->matr[i][j] = this->matr[i][j] - par.matr[i][j];
	return *tmp;
}

template<class T>
matrix<T>& matrix<T>::operator=(matrix<T> &par){
	int parrow = par.getrow();
	int parcol = par.getcol();
	if (parrow != this->row || parcol != this->col){
		cout << "Ранги матриц не одинаковы!!\n";
		exit(1);
	}
	for (int i = 0; i<this->row; i++)
	for (int j = 0; j<this->col; j++)
		this->matr[i][j] = par.matr[i][j];
	return *this;
}
//====================================================================
template <class T, int size>
class stack{
private:
	T dat[size];
	int top;
public:
	stack(){
		top = -1;
	}
	void push(T value);
	T pop();
};

template <class T, int size>
void stack<T, size>::push(T value){
	if (top<size - 1)
		dat[++top] = value;
	else
		cout << "Стек полон!!" << endl;
}

template <class T, int size>
T stack<T, size>::pop(){
	if (top>-1)
		return dat[top--];
	else
		cout << "Стек пуст!!";
	return NULL;
}
//=====================================================================
int main()
{
	setlocale(LC_ALL, "Russian");

	//		SWAP
	//		1.1
	cout << endl << "SWAP - замена местами" << endl << endl;

	int intx = 1;
	int inty = 2;
	cout << setfill('-') << setw(20) << left << "-----int" << endl;
	cout << intx << "\t\t" << inty << endl;
	swap(intx, inty);
	cout << intx << "\t\t" << inty << endl;

	long longx = 54434;
	long longy = 17787;
	cout << setfill('-') << setw(20) << left << "-----long" << endl;
	cout << longx << "\t\t" << longy << endl;
	swap(longx, longy);
	cout << longx << "\t\t" << longy << endl;

	float floatx = 1.543;
	float floaty = 2.134;
	cout << setfill('-') << setw(20) << left << "-----float" << endl;
	cout << floatx << "\t\t" << floaty << endl;
	swap(floatx, floaty);
	cout << floatx << "\t\t" << floaty << endl;

	double doublex = 1.5435453453;
	double doubley = 2.1345434355;
	cout << setfill('-') << setw(20) << left << "-----double" << endl;
	cout << doublex << "\t\t" << doubley << endl;
	swap(doublex, doubley);
	cout << doublex << "\t\t" << doubley << endl;

	char charx = 'a';
	char chary = 'b';
	cout << setfill('-') << setw(20) << left << "-----char" << endl;
	cout << charx << "\t\t" << chary << endl;
	swap(charx, chary);
	cout << charx << "\t\t" << chary << endl;

	string stringx = "aaaaa";
	string stringy = "bbbbb";
	cout << setfill('-') << setw(20) << left << "-----string" << endl;
	cout << stringx << "\t\t" << stringy << endl;
	swap(stringx, stringy);
	cout << stringx << "\t\t" << stringy << endl;

	//		MAXX
	//		1.2

	cout << endl	<< "MAXX - возвращение максимального значения" << endl << endl;
	
	cout << intx	<< "\t" << inty		<< "\t\t" << "max = " << maxx(intx, inty)		<< endl;
	cout << longx	<< "\t" << longy	<< "\t\t" << "max = " << maxx(longx, longy)		<< endl;
	cout << floatx	<< "\t" << floaty	<< "\t\t" << "max = " << maxx(floatx, floaty)	<< endl;
	cout << doublex << "\t" << doubley	<< "\t\t" << "max = " << maxx(doublex, doubley) << endl;
	cout << charx	<< "\t" << chary	<< "\t\t" << "max = " << maxx(charx, chary)		<< endl;
	cout << stringx << "\t" << stringy	<< "\t\t" << "max = " << maxx(stringx, stringy) << endl;
	char* charstrx = "Hello";
	char* charstry = "World";
	cout << charstrx << "\t" << charstry << "\t\t" << "max = " << maxx(charstrx, charstry) << endl;
	
	//		COMPLEX 
	//		2.1
	cout << endl << "COMPLEX - комплексные числа" << endl << endl;

	complex num(5.5, 6.7);

	cout << num << endl;
	cout << "\tcomplex1 + complex2\n" << (num + num) << endl;
	cout << "\tcomplex1 - complex2\n" << (num - num) << endl;

	//		MATRIX
	//		2.2
	
	cout << endl << "MATRIX - шаблон класса матриц" << endl << endl;

	cout << setfill('-') << setw(20) << left << "-----int" << endl;
	matrix<int> intm(3, 3);
	cout << endl;
	cout << intm;

	//matrix<int> intmm(2,2);
	//cin>>intmm;
	//cout<<intmm;

	matrix<int> intm1(3, 3);
	cout << endl;
	cout << intm1;
	cout << "\t\t\tintm + intm" << endl;
	cout << endl;
	cout << (intm + intm1);

	cout << "\t\t\tintm - intm" << endl;
	cout << endl;
	cout << (intm - intm1);

	cout << "\t\t\tintm = intm1" << endl;
	cout << endl;
	intm = intm1;
	cout << intm;

	cout << setfill('-') << setw(20) << left << "-----float" << endl;
	matrix<float> floatm(3, 3);
	cout << endl;
	cout << floatm;

	//matrix<float> mm(2,2);
	//cin>>mm;
	//cout<<mm;

	matrix<float> floatm1(3, 3);
	cout << endl;
	cout << floatm1;
	cout << "\t\t\tfloatm + floatm" << endl;
	cout << endl;
	cout << (floatm + floatm1);

	cout << "\t\t\tfloatm - floatm" << endl;
	cout << endl;
	cout << (floatm - floatm1);

	cout << "\t\t\tfloatm = floatm1" << endl;
	cout << endl;
	floatm = floatm1;
	cout << floatm;

	//		СТЕК
	//		3

	cout << endl << "STACK - шаблон стека" << endl << endl;

	stack<int, 6> intst;
	intst.push(11);
	intst.push(22);
	intst.push(33);
	intst.push(44);
	intst.push(55);
	intst.push(66);

	cout << intst.pop() << endl;
	cout << intst.pop() << endl;
	cout << intst.pop() << endl;
	cout << intst.pop() << endl;
	cout << intst.pop() << endl;
	cout << intst.pop() << endl;

	cout << endl;
	stack<float, 3> floatst;

	floatst.push(11.35);
	floatst.push(22.87);
	floatst.push(33.65);

	cout << floatst.pop() << endl;
	cout << floatst.pop() << endl;
	cout << floatst.pop() << endl;

	return 0;
}

template <class T>
void swap(T *x, T *y){
	T temp = x;
	x = y;
	y = temp;
}

template <class T>
T maxx(T x, T y){
	cout << "Шаблонная функция" << endl;
	return (x>y) ? x : y;
}

char* maxx(char *strx, char *stry){
	cout << "Специализированная функция" << endl;
	if (strcmp(strx, stry) == 0)
		return "Строки \"равны\"\n";
	return (strcmp(strx, stry) < 0) ? strx : stry;
}