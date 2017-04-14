// var6.cpp: определяет точку входа для консольного приложения.
//
// Курсовая работа. Вариант 6. LIST.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <time.h>
#include <string>
#include <fstream>
#include <iterator>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

#define LOW_PRED 2
#define HIGH_PRED 3
#define HIGH_PRED_ZAKAZ 40
#define SIZE 20

template <class T>
T getElem(list<T> st, int ind){
	for (int i = 1; i <= ind; i++){
		st.pop_back();
	}
	T temp = st.back();
	return temp;
}
template <class T>
int l_max(list<T> temp){
	int max;
	int index_max = 0;
	max = getElem(temp, 0);
	for (int i = 0; i < temp.size(); i++){
		if (getElem(temp, i)>max){
			max = getElem(temp, i);
			index_max = i;
		}
	}
	return index_max;
}
ostream &endp(ostream &stream){
	stream << setfill('=') << setw(80) << "=" << setfill(' ') << endl;
	return stream;
}
class Menu{
	string Food_Name; 
	double Food_Price;
public:
	Menu(){
		Food_Name = "noname";
		Food_Price = 0.0;
	}
	string getFood_Name(){
		return Food_Name;
	}
	double getFood_Price(){
		return Food_Price;
	}
	void setFood_Name(string t_name){
		Food_Name = t_name;
	}
	void setFood_Price(float t_p){
		Food_Price = t_p;
	}
	void file_read(list<Menu> &lm);

	friend ostream& operator<<(ostream&, Menu&);
	friend istream& operator>>(istream&, Menu&);
	friend void delete_menu_item(string);
};
void Menu::file_read(list<Menu> &lm){
	ifstream file("menu.txt");
	Menu item;
	char buffer[100];

	while (!file.eof()){
		file.getline(buffer, 100);
		item.Food_Name = buffer;

		file.getline(buffer, 100);
		item.Food_Price = atof(buffer);

		lm.push_back(item);
	}
	file.close();
}
ostream& operator<<(ostream& stream, Menu &tM){
	stream << setw(50) << tM.Food_Name
		<< setw(10) << tM.Food_Price;
	return stream;
}
istream& operator>>(istream& stream, Menu &tM){
	cout << setw(30) << "Введите название блюда:";
	getline(stream, tM.Food_Name);
	cout << setw(30) << "Введите цену блюда:";
	stream >> tM.Food_Price;

	ofstream file("menu.txt", ios_base::app);

	file << tM.Food_Name << "\n";
	file << tM.Food_Price << "\n";

	file.close();

	return stream;
}
void delete_menu_item(string t_Name){
	ifstream file("menu.txt");
	list<Menu> temp_lm;
	Menu temp_item;
	char buffer[100];

	while (!file.eof()){
		file.getline(buffer, 100);
		temp_item.Food_Name = buffer;

		file.getline(buffer, 50);
		temp_item.Food_Price = atof(buffer);

		if (t_Name != temp_item.Food_Name){
			temp_lm.push_back(temp_item);
		}
	}
	file.close();
	temp_lm.resize(temp_lm.size() - 1);

	ofstream file1("menu.txt");
	list<Menu>::iterator it;
	for (it = temp_lm.begin(); it != temp_lm.end(); ++it)
	{
		Menu obj = *it;
		file1 << obj.Food_Name << "\n";
		file1 << obj.Food_Price << "\n";
	}
	file.close();
}
class Oficiant{
private:
	string name;
public:
	Oficiant() :name("undefined"){};
	friend void ofic_file_read(list<Oficiant>&lo);
	friend Oficiant gen_rand_of();

	string getname(){
		return name;
	}
	friend ostream& operator<<(ostream&, Oficiant&);
};
void ofic_file_read(list<Oficiant> &lo){
	ifstream file("oficiant.txt");
	Oficiant item;
	char buffer[100];

	while (!file.eof()){
		file.getline(buffer, 100);
		item.name = buffer;

		lo.push_back(item);
	}
	file.close();
}
ostream& operator<<(ostream& stream, Oficiant& of){
	stream << of.name << endl;
	return stream;
}
Oficiant gen_rand_of(){
	list<Oficiant> t_l;
	ofic_file_read(t_l);

	int id;
	int size = t_l.size();

	id = rand() % size;
	return (getElem(t_l, id));
}
class Client{
private:
	string name;
	double size_discount; 
public:
	Client(){
		name = "undefined";
		size_discount = 0.0;
	};
	friend void cl_file_read(list<Client>&lc);
	friend Client gen_rand_client();

	string getClName(){
		return name;
	}
	double getDsize(){
		return size_discount;
	}

	friend ostream& operator<<(ostream&, Client&);
};
void cl_file_read(list<Client>&lc){
	ifstream file("client.txt");
	Client item;
	char buffer[100];

	while (!file.eof()){
		file.getline(buffer, 100);
		item.name = buffer;

		file.getline(buffer, 100);
		item.size_discount = atof(buffer);

		lc.push_back(item);
	}
	file.close();
}
ostream& operator<<(ostream& stream, Client& item){
	stream << setw(30) << item.name
		<< setw(10) << item.size_discount
		<< endl;
	return stream;
}
Client gen_rand_client(){
	list<Client> t_l;
	cl_file_read(t_l);

	int id;
	int size = t_l.size();

	id = rand() % size;
	return (getElem(t_l, id));
}
class Zakaz{
	Oficiant of;
	Client cl;
	double sum;
	list<int> lc; 
	list<Menu> lm; // 
public:
	Zakaz();
	friend Zakaz createZakaz(list<Menu>&); //+
	friend void createListZakaz(list<Menu>&, list<Zakaz>&); //+
	friend void showListZakaz(list<Zakaz>&);
	friend void printListZakaz(list<Zakaz>&);
	Oficiant getOf(){
		return of;
	}
	Client getCl(){
		return cl;
	}
	double getSum(){
		return sum;
	}
	list<int> getCount(){
		return lc;
	}
	list<Menu> getMenu(){
		return lm;
	}

	friend ostream& operator<<(ostream&, Zakaz&);
};
Zakaz::Zakaz(){
}
Zakaz createZakaz(list<Menu>& t_lm){

	Zakaz item;
	Menu m_item;

	m_item.file_read(t_lm);

	int count; 
	count = rand() % HIGH_PRED + LOW_PRED;
	int ind_menu;
	int count_n; 
	int *ind_mas = new int[count];
	bool flag;

	for (int i = 1; i <= count; i++){
		count_n = rand() % 3 + 1;
		for (;;){
			ind_menu = rand() % t_lm.size();
			flag = 0;
			for (int j = 1; j < i; j++){
				if (ind_menu == ind_mas[j]){
					flag = 1;
					break;
				}
			}
			if (!flag){
				break;
			}
		}

		ind_mas[i] = ind_menu;

		m_item = getElem(t_lm, ind_menu);

		item.lm.push_back(m_item); // 
		item.lc.push_back(count_n); //
		item.sum += m_item.getFood_Price()*count_n;
		item.of = gen_rand_of();
		item.cl = gen_rand_client();
	}

	return item;
}
template <int size>
void createListZakaz(list<Menu>& t_lm, list<Zakaz>& list_zakaz){
	Zakaz *mas[size];
	for (int i = 0; i < size; i++){
		mas[i] = new Zakaz;
		*mas[i] = createZakaz(t_lm);
	}
	for (int i = 0; i < size; i++){
		list_zakaz.push_back(*mas[i]);
	}
}
ostream& operator<<(ostream& stream, Zakaz& temp){
	stream << setfill(' ');
	stream << "Клиент: " << temp.cl.getClName() << endl;
	stream << "Обслужил: " << temp.of.getname() << endl;
	for (int i = 0; i < temp.lm.size(); i++){
		stream << getElem(temp.lm, i) << "\t " << getElem(temp.lc, i) << endl;
	}
	stream << setw(65) << "Итог:   " << temp.sum << endl; //? maybe push an* place
	stream << setw(65) << "Итог со скидкой: " << temp.sum - temp.sum*temp.cl.getDsize() << endl;
	stream << setw(80) << setfill('-') << '-';
	return stream;
}
class Smena{
public:
	Smena();
	friend double Itog_Smeni(list<Zakaz> &temp); //выручка за смену
	friend void Itog_Oficiant(list<Zakaz> &temp); //выручка по официанту
	friend double Itog_AVG(list<Zakaz> &temp); // средняя стоимость заказа
	friend void Count_Foood(list<Zakaz> &temp); // количество проданных наименований
};
double Itog_Smeni(list<Zakaz> &temp){
	double Sum_Itog = 0.0;
	for (int i = 0; i < temp.size(); i++){
		Sum_Itog += (getElem(temp, i).getSum() - getElem(temp, i).getSum()*getElem(temp, i).getCl().getDsize());
	}
	return Sum_Itog;
}
template<int size>
void Itog_Oficiant(list<Zakaz> &temp){
	ofstream file("smena_compl.txt", ios_base::app);
	list<Oficiant> tempList;
	file << "Выручка по каждому официанту \n" << endp << endl;
	cout << "Выручка по каждому официанту \n" << endp << endl;
	for (int i = 0; i < size; i++){
		file << setw(20) << left << getElem(temp, i).getOf().getname() << setw(10) << getElem(temp, i).getSum() - getElem(temp, i).getSum()*getElem(temp, i).getCl().getDsize() << "\n";
		cout << setw(20) << getElem(temp, i).getOf().getname() << setw(10) << getElem(temp, i).getSum() - getElem(temp, i).getSum()*getElem(temp, i).getCl().getDsize() << "\n";
	}
	file << endp;
	cout << endp;
	file.close();
}
template<int size>
void showListZakaz(list<Zakaz>&t){
	for (int i = 0; i < size; i++){
		cout << getElem(t, i) << endl;
	}
}
template<int size>
void printListZakaz(list<Zakaz>&t){
	ofstream file("smena_compl.txt", ios_base::app);
	for (int i = 0; i < size; i++){
		file << getElem(t, i) << "\n";
		cout << getElem(t, i) << "\n";
	}
	file.close();
}
template<int size>
double Itog_AVG(list<Zakaz> &temp){
	double AVG = 0.0;
	for (int i = 0; i < temp.size(); i++){
		AVG += (getElem(temp, i).getSum() - getElem(temp, i).getSum()*getElem(temp, i).getCl().getDsize());
	}
	AVG = AVG / size;
	return AVG;
}
template<int size>
void Count_Foood(list<Zakaz> &temp){
	ofstream file("smena_compl.txt", ios_base::app);
	list<Menu> temp_menu;
	Menu t1;
	t1.file_read(temp_menu);
	list<string> ptr;
	list<int> intl;
	file << "Количество проданных наименований: \n";
	cout << "Количество проданных наименований: \n";
	int x = 0;
	for (int i = 0; i < size; i++){
		while (x < getElem(temp, i).getMenu().size()){
			for (int y = 1; y <= getElem(getElem(temp, i).getCount(), x); y++)
				ptr.push_back(getElem(getElem(temp, i).getMenu(), x).getFood_Name());
			x++;
		}
		x = 0;
	}
	int count = 0;
	for (int i = 0; i < temp_menu.size(); i++){
		for (int k = 0; k < ptr.size(); k++){
			if (getElem(temp_menu, i).getFood_Name() == getElem(ptr, k))
				count++;
		}
		intl.push_back(count);
		count = 0;
	}
	for (int i = 0; i < intl.size(); i++){
		file << setw(30) << getElem(temp_menu, i).getFood_Name() << setw(15) << " количество продано - " << getElem(intl, i) << "\n";
		cout << setw(30) << getElem(temp_menu, i).getFood_Name() << setw(15) << " количество продано - " << getElem(intl, i) << "\n";
	}
	// most popular
	file << endp << "Самое популярное блюдо: " << getElem(temp_menu, l_max(intl)).getFood_Name() << "\n";
	cout << endp << "Самое популярное блюдо: " << getElem(temp_menu, l_max(intl)).getFood_Name() << "\n";

	file.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	Menu temp;
	list<Menu> list_menu;
	list<Zakaz> list_zakaz;

	createListZakaz<SIZE>(list_menu, list_zakaz);

	char c;
	while (1){
		showListZakaz<SIZE>(list_zakaz);
		cout << endp << setw(50) << "Основное меню\n";
		cout << setw(50) << "1. Добавить новое блюдо\n";
		cout << setw(50) << "2. Удалить блюдо из меню\n";
		cout << setw(50) << "3. Сформировать отчет\n";
		c = _getch();
		switch (c){
		case '1':{
					 system("CLS");
					 cout << "Добавление нового блюда: \n";
					 cin >> temp;
					 break;
		}
		case '2':{
					 system("CLS");
					 string temp;
					 cout << setw(30) << "Введите блюдо для удаления: ";
					 getline(cin, temp);
					 delete_menu_item(temp);
					 break;
		}
		case '3':{
					 system("CLS");
					 ofstream file("smena_compl.txt");
					 file << endp << "Выручка за смену: " << Itog_Smeni(list_zakaz) << " RUB" << endl << endp;
					 cout << endp << "Выручка за смену: " << Itog_Smeni(list_zakaz) << " RUB" << endl << endp;
					 file << "Отчет по смене \n" << endp;
					 cout << "Отчет по смене \n" << endp;
					 file.close();
					 printListZakaz<SIZE>(list_zakaz);
					 Itog_Oficiant<SIZE>(list_zakaz);
					 ofstream file1("smena_compl.txt", ios_base::app);
					 file1 << "Средняя стоимость заказа: " << Itog_AVG<SIZE>(list_zakaz) << " RUB" << endl << endp << "\n";
					 cout << "Средняя стоимость заказа: " << Itog_AVG<SIZE>(list_zakaz) << " RUB" << endl << endp << "\n";
					 file1.close();
					 Count_Foood<SIZE>(list_zakaz);
					 _getch();
					 break;
		}
		case 27:
			exit(1);
		default:
			cout << "Некорретный ввод!!!";
			break;
		}
	}
	return 0;
}