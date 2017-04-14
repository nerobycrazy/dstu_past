//
//

#include "stdafx.h"
#include <stdio.h> 
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;

//templates
template<class T>
void VectorPrint(vector<T> vec){
	for (int i = 0; i < vec.size(); i++)
		cout << vec.at(i) << endl;
}
template<class T>
int find(vector<T> vec, T val){
	for (int i = 0; i < vec.size(); i++){
		if (vec.at(i) == val)
			return 1;
	}
	return 0;
}
template<class T>
int index_maxx(vector<T> vec){
	T max;
	int index_m;
	max = vec.at(0);
	for (int i = 0; i < vec.size(); i++){
		if (vec.at(i)>max){
			max = vec.at(i);
			index_m = i;
		}
	}
	return index_m;

}

// Abstract Man
class Man{
protected:
	string fam; // фамилия
	string sex; // пол
	int Vozr; // возраст
	string obraz; // образование
	string profes; // профессия
	string dolzhn; // должность
	int Stage1; //стаж на последней должности
	int StageAll; // общий стаж
public:
	Man(){
		fam = "Иванов";
		sex = "М";
		Vozr = 0;
		obraz = "Среднее специальное";
		profes = "Инженер-программист";
		dolzhn = "Программист";
		Stage1 = 0;
		StageAll = 0;
	}
	string get_sex(){
		return sex;
	}
	int get_vozr(){
		return Vozr;
	}
	string get_obraz(){
		return obraz;
	}
	int get_Stage1(){
		return Stage1;
	}
	int get_StageAll(){
		return StageAll;
	}

};

// Vacancy
class Vacancy : virtual public Man{
protected:
	string NameFirm; // название фирмы
	string VacDolzh; // вакантная должность
	double vZP; // Зарплата
	string Prichina_Otkaza;
public:
	Vacancy() :Man(){
		NameFirm = "NoName";
		VacDolzh = "NoDolzh";
		vZP = 0;
		Prichina_Otkaza = "Нет";
	}
	string get_NameFirm(){
		return NameFirm;
	}
	string get_VacDo(){
		return VacDolzh;
	}
	double get_vZP(){
		return vZP;
	}
	string get_Prichina(){
		return Prichina_Otkaza;
	}
	void set_Prichina(string o){
		Prichina_Otkaza = o;
	}

	void ReadFromFile(vector<Vacancy>&);
	friend ostream& operator<<(ostream&, Vacancy&);
	friend istream& operator>>(istream&, Vacancy&);
	friend void DeleteVacancy(string);
};
void Vacancy::ReadFromFile(vector<Vacancy> &vec){
	ifstream file("вакансии.txt");
	Vacancy temp;
	char buffer[100];

	while (!file.eof()) {
		file.getline(buffer, 100);
		temp.NameFirm = buffer;

		file.getline(buffer, 30);
		temp.VacDolzh = buffer;

		file.getline(buffer, 30);
		temp.vZP = atof(buffer);

		file.getline(buffer, 100);
		temp.sex = buffer;

		file.getline(buffer, 30);
		temp.Vozr = atoi(buffer);

		file.getline(buffer, 100);
		temp.obraz = buffer;

		file.getline(buffer, 30);
		temp.Stage1 = atoi(buffer);

		file.getline(buffer, 30);
		temp.StageAll = atoi(buffer);

		vec.push_back(temp);
	}
	vec.pop_back();
	file.close();
}
ostream& operator<<(ostream& os, Vacancy& obj){
	cout << "------------------------------\n";
	cout << setw(21) << "Информация о фирме:" << endl;
	os << setw(15) << obj.NameFirm
		<< setw(30) << obj.VacDolzh
		<< setw(10) << obj.vZP;
	cout << endl << setw(25) << "Требования к кандидату:" << endl;
	os << setw(5) << obj.sex
		<< setw(5) << obj.Vozr
		<< setw(20) << obj.obraz
		<< setw(5) << obj.Stage1
		<< setw(5) << obj.StageAll
		<< endl;
	cout << "------------------------------\n";
	return os;
}
istream& operator>>(istream& os, Vacancy& obj){
	cout << "Введите название фирмы: ";
	getline(os, obj.NameFirm);
	cout << "Введите вакантную должность: ";
	getline(os, obj.VacDolzh);
	cout << "Введите пол: ";
	getline(os, obj.sex);
	cout << "Введите образование: ";
	getline(os, obj.obraz);
	cout << "Введите возраст: ";
	os >> obj.Vozr;
	cout << "Введите опыт работы(на последней работе): ";
	os >> obj.Stage1;
	cout << "Введите общий опыт работы: ";
	os >> obj.StageAll;
	cout << "Введите зарплату: ";
	os >> obj.vZP;

	ofstream file("вакансии.txt", ios_base::app);

	file << obj.NameFirm << "\n";
	file << obj.VacDolzh << "\n";
	file << obj.vZP << "\n";
	file << obj.sex << "\n";
	file << obj.Vozr << "\n";
	file << obj.obraz << "\n";
	file << obj.Stage1 << "\n";
	file << obj.StageAll << "\n";

	file.close();
	return os;
}
void DeleteVacancy(string name){
	ifstream file("вакансии.txt");
	Vacancy temp;
	vector<Vacancy> vec;
	vec.reserve(100);
	char buffer[100];

	while (!file.eof()) {
		file.getline(buffer, 100);
		temp.NameFirm = buffer;

		file.getline(buffer, 30);
		temp.VacDolzh = buffer;

		file.getline(buffer, 30);
		temp.vZP = atof(buffer);

		file.getline(buffer, 100);
		temp.sex = buffer;

		file.getline(buffer, 30);
		temp.Vozr = atoi(buffer);

		file.getline(buffer, 100);
		temp.obraz = buffer;

		file.getline(buffer, 30);
		temp.Stage1 = atoi(buffer);

		file.getline(buffer, 30);
		temp.StageAll = atoi(buffer);

		if (temp.NameFirm != name)
			vec.push_back(temp);
	}

	file.close();

	ofstream fil("вакансии.txt");
	int j = 0;
	for (int i = 0; i < vec.size() - 1; i++){
		fil << vec.at(i).NameFirm << "\n";
		fil << vec.at(i).VacDolzh << "\n";
		fil << vec.at(i).vZP << "\n";
		fil << vec.at(i).sex << "\n";
		fil << vec.at(i).obraz << "\n";
		fil << vec.at(i).Stage1 << "\n";
		fil << vec.at(i).StageAll << "\n";
	}
	fil.close();
}

// Unemployed
class Unemployed : virtual public Man{
protected:
	string date; // дата постановки на учет
	double ZP; // желаемая зарплата
	string need_dol; // желаемая должность
	vector<Vacancy> vaca; // доступные вакансии
public:
	Unemployed() :Man(){
		date = "01.01.1900";
		ZP = 0;
		need_dol = "NoDolzh";
	}
	string get_fam(){
		return fam;
	}
	string get_need_dol(){
		return need_dol;
	}
	vector<Vacancy> &get_vaca(){
		return vaca;
	}

	void ReadFromFile(vector<Unemployed> &);
	void GenerateListVac(vector<Vacancy>);

	friend ostream& operator<<(ostream&, Unemployed&);
	friend istream& operator>>(istream&, Unemployed&);
	friend void DeleteUnemployed(string);
};
void Unemployed::ReadFromFile(vector<Unemployed> &vec){
	ifstream file("безработные.txt");
	Unemployed temp;
	char buffer[100];

	while (!file.eof()) {
		file.getline(buffer, 100);
		temp.fam = buffer;

		file.getline(buffer, 30);
		temp.sex = buffer;

		file.getline(buffer, 30);
		temp.Vozr = atoi(buffer);

		file.getline(buffer, 100);
		temp.obraz = buffer;

		file.getline(buffer, 100);
		temp.profes = buffer;

		file.getline(buffer, 100);
		temp.dolzhn = buffer;

		file.getline(buffer, 30);
		temp.Stage1 = atoi(buffer);

		file.getline(buffer, 30);
		temp.StageAll = atoi(buffer);

		file.getline(buffer, 100);
		temp.date = buffer;

		file.getline(buffer, 30);
		temp.ZP = atof(buffer);

		file.getline(buffer, 100);
		temp.need_dol = buffer;

		vec.push_back(temp);
	}
	vec.pop_back();
	file.close();
}
void Unemployed::GenerateListVac(vector<Vacancy> vec_vac){
	for (int i = 0; i < vec_vac.size(); i++){
		if (get_need_dol() == vec_vac.at(i).get_VacDo()){
			vaca.push_back(vec_vac.at(i));
		}
	}
}

ostream& operator<<(ostream& os, Unemployed& obj){
	os << left << " " << setw(15) << obj.fam
		<< setw(5) << obj.sex
		<< setw(5) << obj.Vozr
		<< setw(25) << obj.obraz
		<< setw(25) << obj.profes
		<< setw(25) << obj.dolzhn
		<< setw(5) << obj.Stage1
		<< setw(5) << obj.StageAll
		<< setw(15) << obj.date
		<< setw(8) << obj.ZP
		<< setw(15) << obj.need_dol
		<< endl << endl;
	for (int i = 0; i < obj.vaca.size(); i++){
		cout << "  " << setw(20) << obj.vaca.at(i).get_NameFirm()
			<< setw(20) << obj.vaca.at(i).get_VacDo()
			<< setw(11) << obj.vaca.at(i).get_vZP()
			<< setw(20) << obj.vaca.at(i).get_Prichina()
			<< endl;
	}
	return os;
}
istream& operator>>(istream& os, Unemployed& obj){
	cout << "Введите фамилию: ";
	getline(os, obj.fam);
	cout << "Введите пол: ";
	getline(os, obj.sex);
	cout << "Введите образование: ";
	getline(os, obj.obraz);
	cout << "Введите профессию: ";
	getline(os, obj.profes);
	cout << "Введите должность: ";
	getline(os, obj.dolzhn);
	cout << "Введите дату постановки на учет ДД.ММ.ГГГГ: ";
	getline(os, obj.date);
	cout << "Введите желаемую должность: ";
	getline(os, obj.need_dol);
	cout << "Введите возраст: ";
	os >> obj.Vozr;
	cout << "Введите опыт работы(на последней работе): ";
	os >> obj.Stage1;
	cout << "Введите общий опыт работы: ";
	os >> obj.StageAll;
	cout << "Введите зарплату: ";
	os >> obj.ZP;


	ofstream file("безработные.txt", ios_base::app);

	file << obj.fam << "\n";
	file << obj.sex << "\n";
	file << obj.Vozr << "\n";
	file << obj.obraz << "\n";
	file << obj.profes << "\n";
	file << obj.dolzhn << "\n";
	file << obj.Stage1 << "\n";
	file << obj.StageAll << "\n";
	file << obj.date << "\n";
	file << obj.ZP << "\n";
	file << obj.need_dol << "\n";

	file.close();
	return os;

}
void DeleteUnemployed(string temp){
	ifstream file("безработные.txt");
	Unemployed obj;
	vector<Unemployed> vec;
	vec.reserve(100);
	char buffer[100];

	while (!file.eof()) {
		file.getline(buffer, 100);
		obj.fam = buffer;

		file.getline(buffer, 30);
		obj.sex = buffer;

		file.getline(buffer, 30);
		obj.Vozr = atoi(buffer);

		file.getline(buffer, 100);
		obj.obraz = buffer;

		file.getline(buffer, 100);
		obj.profes = buffer;

		file.getline(buffer, 100);
		obj.dolzhn = buffer;

		file.getline(buffer, 30);
		obj.Stage1 = atoi(buffer);

		file.getline(buffer, 30);
		obj.StageAll = atoi(buffer);

		file.getline(buffer, 100);
		obj.date = buffer;

		file.getline(buffer, 30);
		obj.ZP = atof(buffer);

		file.getline(buffer, 100);
		obj.need_dol = buffer;

		if (obj.fam != temp)
			vec.push_back(obj);
	}

	file.close();

	ofstream fil("безработные.txt");
	int j = 0;
	for (int i = 0; i < vec.size() - 1; i++){
		fil << vec.at(i).fam << "\n";
		fil << vec.at(i).sex << "\n";
		fil << vec.at(i).Vozr << "\n";
		fil << vec.at(i).obraz << "\n";
		fil << vec.at(i).profes << "\n";
		fil << vec.at(i).dolzhn << "\n";
		fil << vec.at(i).Stage1 << "\n";
		fil << vec.at(i).StageAll << "\n";
		fil << vec.at(i).date << "\n";
		fil << vec.at(i).ZP << "\n";
		fil << vec.at(i).need_dol << "\n";
	}
	fil.close();
}

// Date
class Date{
	int day;
	int month;
	int year;
	int days_in_month[13];
public:
	Date();
	Date(int day, int month, int year);
	Date& operator--();
	friend ostream& operator<<(ostream&, Date&);
};
Date::Date(){

	int d_in_m[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < 13; i++)
		days_in_month[i] = d_in_m[i];

	const char* now = __DATE__;		//получаем текущую дату

	int month;
	char m[4];
	m[0] = now[0];
	m[1] = now[1];
	m[2] = now[2];
	m[3] = '\0';

	if (!strcmp(m, "Jan"))
		month = 1;
	if (!strcmp(m, "Feb"))
		month = 2;
	if (!strcmp(m, "Mar"))
		month = 3;
	if (!strcmp(m, "Apr"))
		month = 4;
	if (!strcmp(m, "May"))
		month = 5;
	if (!strcmp(m, "Jun"))
		month = 6;
	if (!strcmp(m, "Jul"))
		month = 7;
	if (!strcmp(m, "Aug"))
		month = 8;
	if (!strcmp(m, "Sep"))
		month = 9;
	if (!strcmp(m, "Oct"))
		month = 10;
	if (!strcmp(m, "Nov"))
		month = 11;
	if (!strcmp(m, "Dec"))
		month = 12;

	char d[3];
	d[0] = now[4];
	d[1] = now[5];
	d[2] = '\0';
	const char* s = d;
	int day = atoi(s);

	char y[5];
	y[0] = now[7];
	y[1] = now[8];
	y[2] = now[9];
	y[3] = now[10];
	y[4] = '\0';
	const char* sy = y;
	int year = atoi(sy);

	this->day = day;
	this->month = month;
	this->year = year;
}
Date& Date::operator--(){
	if (day - 1 > 1){
		day--;
	}
	else{
		if (month - 1 < 1){
			month += 12;
			year--;
		}
		day = days_in_month[month - 1];
		month--;
	}
	return *this;
}
ostream& operator<<(ostream& os, Date &d){
	os << d.day << "." << d.month << "." << d.year;
	return os;
}

void FindPeopleVacancy(vector<Unemployed> U_vec, string vac){
	bool flag = FALSE;
	for (int i = 0; i < U_vec.size(); i++){
		if (U_vec.at(i).get_need_dol() == vac){
			cout << U_vec.at(i);
			flag = TRUE;
		}
	}
	if (flag == FALSE)
		cout << "Подходящих кандидатов не найдено" << endl;
}
void FindFirmVacancy(vector<Vacancy> V_vec, string vac){
	bool flag = FALSE;
	for (int i = 0; i < V_vec.size(); i++){
		if (V_vec.at(i).get_VacDo() == vac){
			cout << V_vec.at(i);
			flag = TRUE;
		}
	}
	if (flag == FALSE)
		cout << "Подходящих фирм не найдено" << endl;
}
void Rating(vector<Vacancy> V_vec){
	int size = V_vec.size();
	vector<string> str;
	vector<int> intv;
	int count = 0;

	for (int i = 0; i < size; i++){
		// копируем в новый массив
		if (find<string>(str, V_vec.at(i).get_VacDo()) != 1)
			str.push_back(V_vec.at(i).get_VacDo());
	}

	for (int i = 0; i < str.size(); i++){
		for (int k = 0; k < size; k++){
			if (str.at(i) == V_vec.at(k).get_VacDo())
				count++;
		}
		intv.push_back(count);
		count = 0;
	}
	int ii = index_maxx<int>(intv);
	float m = intv.at(ii);
	ofstream file("rating.txt");
	cout << "-----------Рейтинг вакансий на бирже------" << endl;
	file << "-----------Рейтинг вакансий на бирже------" << endl;
	for (int i = 0; i < str.size(); i++){
		cout << right << setw(30) << str.at(i) << setw(8) << setprecision(4) <<intv.at(i) / m * 100 << " %" << endl;
		file << right << setw(30) << str.at(i) << setw(8) << setprecision(4) << intv.at(i) / m * 100 << " %" << endl;
	}
	file.close();
}
void Deal(Unemployed& un){
	if (un.get_vaca().size() != 0){
		for (int i = 0; i < un.get_vaca().size(); i++){ // выбираем каждую фирму
			// условия отбора - образование, пол, возраст, стаж общий, стаж предыдущей работы
			if (un.get_vaca().at(i).get_obraz() != un.get_obraz())
				un.get_vaca().at(i).set_Prichina("Несоответствие образования");
			if ((un.get_vaca().at(i).get_sex() != "Н") && (un.get_vaca().at(i).get_sex() != un.get_sex()))
				un.get_vaca().at(i).set_Prichina("Несоответствие пола");
			if (un.get_vaca().at(i).get_vozr()>un.get_vozr())
				un.get_vaca().at(i).set_Prichina("Несоответствие возраста");
			if (un.get_vaca().at(i).get_Stage1() > un.get_Stage1())
				un.get_vaca().at(i).set_Prichina("Несоответствие 1 стажа");
			if (un.get_vaca().at(i).get_StageAll() > un.get_StageAll())
				un.get_vaca().at(i).set_Prichina("Несоответствие общего стажа");
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Date date;

	Vacancy temp, temp1;
	vector<Vacancy> V_vec;
	temp.ReadFromFile(V_vec);

	Unemployed st;
	vector<Unemployed> U_vec;
	st.ReadFromFile(U_vec);

	for (int i = 0; i < U_vec.size(); i++){
		U_vec.at(i).GenerateListVac(V_vec);
		Deal(U_vec.at(i));
	}
	int index = 0;
	int vSIZE = U_vec.size();
	int *mas = new int[100];
	int mk = 0;
	bool flag = false;
	int igor = 0;

	for (int i = 0; i < 30; i++){
		igor = 0;
		cout << setw(40) << setfill('-') << " " << date << setw(100) << "-" << setfill(' ') << endl;
		int IS = 0;
		IS = rand() % 2;
		if (IS == 1){
			index = rand() % vSIZE;
			while (true){
				flag = true;
				for (int i = 0; i < 100; i++){
					if (index == mas[i]){
						index = rand() % vSIZE;
						flag = false;
					}
				}
				if (flag){ break; }
			}
			//
			for (int k = 0; k < U_vec.at(index).get_vaca().size(); k++){
				if (U_vec.at(index).get_vaca().at(k).get_Prichina() == "Нет"){
					// решение о том выбрать работу или нет
					int Reshenie = rand() % 2;
					if (Reshenie == 1){
						// если выбрал эту работу то
						mas[mk] = index;
						mk++;
						igor = 1;
						break;
					}
				}
			}
			if (igor == 1){
				cout << U_vec.at(index) << " Выдано направление на работу - " << date << endl;
			}
			else{
				cout << U_vec.at(index);
			}
			date--;
		}
		else{
			date--;
		}
	}
	//menu

	char c;
	while (1){
		cout << endl << setw(60) << setfill('-') << "-" << setfill(' ') << endl;
		cout << " Основное меню программы\n";
		cout << "1. Добавить нового безработного\n";
		cout << "2. Добавить новую вакансию\n";
		cout << "3. Удалить безработного\n";
		cout << "4. Удалить вакансию\n";
		cout << "5. Рейтинг специальностей\n";
		cout << "6. Поиск предлагаемых вакансий\n";
		cout << "7. Поиск необходимых вакансий\n";
		cout << "Введите номер из списка меню: >>> ";
		c = _getch();
		switch (c){
		case '1':{
					 system("CLS");
					 Unemployed u_temp;
					 cin >> u_temp;
					 system("PAUSE");
					 break;
		}
		case '2':{
					 system("CLS");
					 cin.ignore('\n', 1);
					 Vacancy vac_temp;
					 cin >> vac_temp;
					 system("PAUSE");
					 break;
		}
		case '3':{
					 system("CLS");
					 string fff;
					 for (int i = 0; i < U_vec.size(); i++)
						 cout << U_vec.at(i).get_fam() << endl;
					 cout << "Введите фамилию безработноого: " ;
					 cin >> fff;
					 DeleteUnemployed(fff);
					 system("PAUSE");
					 break;
		}
		case '4':{
					 system("CLS");
					 string nnn;
					 for (int i = 0; i < V_vec.size(); i++)
						 cout << V_vec.at(i).get_NameFirm() << endl;
					 cout << "Введите название фирмы: ";
					 cin >> nnn;
					 DeleteVacancy(nnn);
					 system("PAUSE");
					 break;
		}
		case '5':{
					 system("CLS");
					 Rating(V_vec);
					 system("PAUSE");
					 break;
		}
		case '6':{
					 system("CLS");
					 cout << "Введите вакансию: ";
					 string vacaca;
					 cin >> vacaca;
					 FindFirmVacancy(V_vec, vacaca);
					 system("PAUSE");
					 break;
		}
		case '7':{
					 system("CLS");
					 cout << "Введите вакансию: ";
					 string vacaca;
					 cin >> vacaca;
					 FindPeopleVacancy(U_vec, vacaca);
					 system("PAUSE");
					 break;
		}
		case 27:
			exit(1);
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}

	return 0;
}

