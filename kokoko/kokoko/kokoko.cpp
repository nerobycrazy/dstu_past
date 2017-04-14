// kokoko.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

struct Sadik{
	char number[7];
	char surname[30];
	char name[30];
	char lastname[30];
	char sex[5];
	char date[30];
	char numGroup[7];
	char ill[13];
};

struct NODE{
	Sadik sd;
	NODE *next;
};

struct LIST{
	int count;
	NODE li;
};

void nonTab(char*);
void InitializeList(NODE**,LIST**);
void Print(NODE*);
void Edit(NODE**);
void Find(NODE*);
void CoMonth(NODE*);
void Insert(NODE**,LIST**, char*, char*, char*, char*, char*, char*, char*, char*);
void InsertFile(NODE**,LIST**);
void DeleteElement(NODE**,LIST**);
void ReadFromFile(NODE**,LIST**);
void SaveToFile(NODE**);

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	NODE *pNode;
	LIST *plist;
	char c;

	InitializeList(&pNode,&plist);
	ReadFromFile(&pNode,&plist);

	while (1){
		system("CLS");
		printf("=============Старунова А.А. - ВИС21 - Вариант 24 - Детсад=============\n\n");
		Print(pNode);
		printf("1. Добавить новую запись\n");
		printf("2. Редактировать запись\n");
		printf("3. Удалить запись\n");
		printf("4. Поиск по месяцу рождения\n");
		printf("5. Вывод сводной таблицы\n");
		printf("Esc. Выход выход из программы\n");
		printf("-------------------------------------------------------------------------\n");
		printf(">>>");

		c = _getch();

		switch (c){
		case '1':{
				system("CLS");
				printf("\t\t-----Добавление новой записи-----\n");
				InsertFile(&pNode,&plist);
				break;
		}
		case '2':{
				system("CLS");
				printf("\t\t-----Редактирование записи записи-----\n");
				Edit(&pNode);
				break;
		}
		case '3':{
				system("CLS");
				printf("\t\t-----Удаление записи-----\n");
				DeleteElement(&pNode,&plist);
				SaveToFile(&pNode);
				break;
		}
		case '4':{
				system("CLS");
				printf("\t\t-----Поиск по дате рождения и печать открыток-----\n\n");
				Find(pNode);
				break;
		}
		case '5':{
				system("CLS");
				printf("\t\t-----Вывод сводной таблицы------\n");
				CoMonth(pNode);
				break;
		}
		case 27: exit(1);
		default:
				printf("Некорретный ввод!!!");
				break;
		}
	}
	return 0;
}

void nonTab(char *c){
	char* pos = strrchr(c, '\n');
	if (pos) c[pos - c] = 0;
}

void InitializeList(NODE **begin,LIST **li){
	*li = new LIST;
	*begin = new NODE;
	(*begin)->next = NULL;
}

void Print(NODE *begin){
	if (begin != NULL){
		NODE *t = begin->next;
		printf("№  Фамилия\tИмя\t   Отчество    \t Пол   Дата Рожд.   №гр.  Сост. здор.\n");
		printf("--------------------------------------------------------------------------\n");
		while (t){
			printf("%-3s%-12s %-10s %-15s %-3s %-13s %-4s %-10s\n", t->sd.number, t->sd.surname, t->sd.name, t->sd.lastname, t->sd.sex, t->sd.date, t->sd.numGroup, t->sd.ill);
			t = t->next;
		}
		printf("--------------------------------------------------------------------------\n");
	}
}

void Edit(NODE **begin){
	NODE *t = *begin;

	char c;
	char number[7];

	printf("Выберите номер для редактирования:");
	gets_s(number);

	while (strcmp(t->sd.number, number) != 0)
		t = t->next;

	printf("\n%-2s.%-12s %-10s %-15s %-3s %-13s %-5s %-7s\n", t->sd.number, t->sd.surname, t->sd.name, t->sd.lastname, t->sd.sex, t->sd.date, t->sd.numGroup, t->sd.ill);
	printf("------------------------------------------------");
	printf("\nВыберите данные для редактирования:\n");
	printf("1. Фамилия\n");
	printf("2. Имя\n");
	printf("3. Отчество\n");
	printf("4. Пол\n");
	printf("5. Дата Рождения\n");
	printf("6. Номер группы\n");
	printf("7. Здоров ли?\n");
	
	switch (c = _getch()){
		case '1':{
			printf("Введите новую фамилию: ");
			gets_s(t->sd.surname);
			break;
		}
		case '2':{
			printf("Введите новое имя: ");
			gets_s(t->sd.name);
			break;
		}
		case '3':{
			printf("Введите новое отчество: ");
			gets_s(t->sd.lastname);
			break;
		}
		case '4':{
			printf("Введите пол: ");
			gets_s(t->sd.sex);
			break;
		}
		case '5':{
			printf("Введите дату рождения: ");
			gets_s(t->sd.date);
			break;
		}
		case '6':{
			printf("Введите номер группы: ");
			gets_s(t->sd.numGroup);
			break;
		}
		case '7':{
			printf("Введите состояние здоровья ");
			gets_s(t->sd.ill);
			break;
		}
		case 27: exit(1);
	}
	SaveToFile(begin);
}

void Find(NODE *begin){
	NODE *t = begin;

	char m[3];
	char mo[4];

	printf("Введите месяц в формате числа (01 для Января и тд): ");
	gets_s(mo);

	while (t){
		m[0] = t->sd.date[3];
		m[1] = t->sd.date[4];
		m[2] = '\0';
		if (strcmp(m, mo) == 0){
			printf("\n%-2s%-12s %-10s %-12s %-12s %-5s\n", t->sd.number, t->sd.surname, t->sd.name, t->sd.lastname, t->sd.date, t->sd.numGroup);
			printf("\nОтправка поздравительной открытки....\n");
			printf("Успешно отправлено!!\n");
		}
		t = t->next;
	}
	printf("\n\n-Не найдено или записей с таким параметром больше нет-\n");
	_getch();
}

void CoMonth(NODE *begin){
	NODE *t = begin->next;
	FILE *table;
	fopen_s(&table, "table.txt", "w");

	char numG[4];
	
	printf("Введите номер группы: ");
	gets_s(numG);

	char masMouth[13][3] = { "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
	char m[3];
	int mc[13] = { 0 };
	int i;
	while (t){
		m[0] = t->sd.date[3];
		m[1] = t->sd.date[4];
		m[2] = '\0';
		for (i = 1; i <= 12; i++){
			if ((strcmp(m, masMouth[i]) == 0) && (strcmp(numG, t->sd.numGroup) == 0))
				mc[i]++;
		}
		t = t->next;
	}
	printf(" Янв.  Фев.  Март  Апр.  Май   Июнь  Июль  Авг.  Сен.  Окт.  Ноя.  Дек.\n");
	fprintf(table, " Янв.  Фев.  Март  Апр.  Май   Июнь  Июль  Авг.  Сен.  Окт.  Ноя.  Дек.\n");

	for (i = 1; i <= 12; i++){
		printf("  %d   ", mc[i]);
		fprintf(table, "  %d   ", mc[i]);
	}
	printf("\nНажмите любую клавишу для возрата >>\n");
	fclose(table);
	_getch();
}

void Insert(NODE **begin, LIST **li, char number[], char surname[], char name[], char lastname[], char sex[], char date[], char numGroup[], char ill[]){
	NODE *ins = new NODE;

	strcpy_s(ins->sd.number, number);
	strcpy_s(ins->sd.surname, surname);
	strcpy_s(ins->sd.name, name);
	strcpy_s(ins->sd.lastname, lastname);
	strcpy_s(ins->sd.sex, sex);
	strcpy_s(ins->sd.date, date);
	strcpy_s(ins->sd.numGroup, numGroup);
	strcpy_s(ins->sd.ill, ill);

	(*li)->count++;

	if (*begin == NULL){
		ins->next = NULL;
		*begin = ins;
		return;
	}

	NODE *temp = *begin;
	while (temp->next){
		temp = temp->next;
	}
	temp->next = ins;
	ins->next = NULL;
}

void InsertFile(NODE **begin,LIST **li){
	FILE *file;
	
	fopen_s(&file, "tab.txt", "a");

	char number[5];
	char surname[30];
	char name[30];
	char lastname[30];
	char sex[3];
	char date[12];
	char numGroup[7];
	char ill[13];
	
	printf("Введите номер: ");
	gets_s(number);
	fputs("\n", file);
	fputs(number, file);
	fputs("\n", file);

	printf("\nФамилия: ");
	gets_s(surname);
	fputs(surname, file); 
	fputs("\n", file);

	printf("Имя: ");
	gets_s(name);
	fputs(name, file);
	fputs("\n", file);

	printf("Отчество: ");
	gets_s(lastname);
	fputs(lastname, file);
	fputs("\n", file);

	printf("Пол (М или Ж): ");
	gets_s(sex);
	fputs(sex, file);
	fputs("\n", file);

	printf("Дата рождения (ДД.ММ.ГГГГ): ");
	gets_s(date);
	fputs(date, file);
	fputs("\n", file);

	printf("Номер группы: ");
	gets_s(numGroup);
	fputs(numGroup, file);
	fputs("\n", file);

	printf("Здоров ли? (здоровый или больной): ");
	gets_s(ill);
	fputs(ill, file);

	Insert(begin, li, number, surname, name, lastname, sex, date, numGroup, ill);

	fclose(file);
}

void DeleteElement(NODE **begin, LIST **li){
	(*li)->count--;

	char k[3];

	printf("Введите номер удаляемой записи: ");
	gets_s(k);

	NODE *t = *begin;
	if (strcmp(t->sd.number, k) == 0){
		*begin = t->next;
		delete t;
		return;
	}

	NODE *t1 = t->next;
	while (t1){
		if (strcmp(t1->sd.number, k) == 0){
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
	
}

void ReadFromFile(NODE **begin,LIST **li){
	FILE *file;

	char number[5];
	char surname[30];
	char name[30];
	char lastname[30];
	char sex[3];
	char date[12];
	char numGroup[7];
	char ill[13];
	
	fopen_s(&file, "tab.txt", "r+");

	while (!feof(file)){
		fgets(number, 5, file);
		nonTab(number);
		fgets(surname, 30, file);
		nonTab(surname);
		fgets(name, 30, file);
		nonTab(name);
		fgets(lastname, 30, file);
		nonTab(lastname);
		fgets(sex, 3, file);
		nonTab(sex);
		fgets(date, 12, file);
		nonTab(date);
		fgets(numGroup, 7, file);
		nonTab(numGroup);
		fgets(ill, 13, file);
		nonTab(ill);

		Insert(begin, li,number, surname, name, lastname, sex, date, numGroup, ill);
	}

	fclose(file);
}

void SaveToFile(NODE **begin){
	FILE *stfile;

	NODE *tt = (*begin)->next;
	
	fopen_s(&stfile, "tab.txt", "w+");

	while (tt){
		fputs(tt->sd.number, stfile);
		fprintf(stfile, "\n");
		fputs(tt->sd.surname, stfile);
		fprintf(stfile, "\n");
		fputs(tt->sd.name, stfile);
		fprintf(stfile, "\n");
		fputs(tt->sd.lastname, stfile);
		fprintf(stfile, "\n");
		fputs(tt->sd.sex, stfile);
		fprintf(stfile, "\n");
		fputs(tt->sd.date, stfile);
		fprintf(stfile, "\n");
		fputs(tt->sd.numGroup, stfile);
		fprintf(stfile, "\n");
		fputs(tt->sd.ill, stfile);
		if (tt->next != NULL)
			fprintf(stfile, "\n");
		tt = tt->next;
	}
	fclose(stfile);
}

