// Ксенафонтова Дарья, ВИС21, ВАРИАНТ 15
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct regGai{
	char key[7];
	char surname[30];
	char name[30];
	char lastname[30];
	char markaAvto[20];
	char date[20];
	char info[20];
	char engine[20];
};

struct NODE{
	regGai item;
	NODE *next;
};

struct LIST{
	int len;
	NODE *top;
};

void z(char*);
void Print(NODE*);
void EditList(NODE**);
void FindAuto(NODE*);
void CountM(NODE*);
void Add(LIST**, char*, char*, char*, char*, char*, char*, char*, char*);
void AddFile(LIST**);
void DeleteElement(LIST**);
void ReadFromFile(LIST**);
void SaveToFile(NODE**);

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	LIST *pLIST;
	
	pLIST = new LIST;
	pLIST->top = new NODE;
	pLIST->top->next = NULL;

	ReadFromFile(&pLIST);

	char c;
	while (1){
		system("CLS");
		printf("Основное меню\n");
		printf("-------------------------------");
		printf("\n1. Вывод таблицы на экран\n");
		printf("2. Добавить запись\n");
		printf("3. Редактировать запись\n");
		printf("4. Удалить запись\n");
		printf("5. Поиск владельцев подержанных авто\n");
		printf("6. Таблица числа машин по году выпуска\n");
		printf("Esc. Выход\n");
		printf("-------------------------------\n->");
		c = _getch();
		switch (c){
		case '1':{
				system("CLS");
				printf("-----Основная таблица-----\n");
				Print(pLIST->top);
				printf("\nНажмите любую клавишу для возврата...");
				_getch();
				break;
		}
		case '2':{
				system("CLS");
				printf("-----Меню добавления новой записи-----\n");
				AddFile(&pLIST);
				break;
		}
		case '3':{
				system("CLS");
				printf("-----Меню редактирования записи-----\n");
				EditList(&pLIST->top);
				SaveToFile(&pLIST->top);
				break;
		}
		case '4':{
				system("CLS");
				printf("-----Меню удаления записи по номеру-----\n");
				DeleteElement(&pLIST);
				SaveToFile(&pLIST->top);
				break;
		}
		case '5':{
				system("CLS");
				printf("-----Поиск подержанных авто-----\n");
				FindAuto(pLIST->top);
				break;
		}
		case '6':{
				system("CLS");
				printf("-----ТаБлица числа авто по году выпуска------\n");
				CountM(pLIST->top);
				break;
		}
		case 27: exit(1);
		default:
			printf("Invalid key");
			break;
		}
	}
	return 0;
}

void z(char *c){
	char* pos = strrchr(c, '\n');
	if (pos) c[pos - c] = 0;
}

void Print(NODE *pNode){
		NODE *li = pNode->next;
		while (li){
			printf("%s.%s %s %s %s %s %s %s\n",li->item.key, li->item.surname, li->item.name, li->item.lastname, li->item.markaAvto, li->item.date, li->item.info, li->item.engine);
			li = li->next;
		}
}

void EditList(NODE **pNode){
	NODE *li = *pNode;

	char c;
	char key[7];
	Print(*pNode);
	printf("----------------------------------\n");
	printf("Введите номер для редактирования:");
	gets_s(key);

	while (strcmp(li->item.key, key) != 0)
		li = li->next;

	printf("\n%s.%s %s %s %s %s %s %s\n", li->item.key, li->item.surname, li->item.name, li->item.lastname, li->item.markaAvto, li->item.date, li->item.info, li->item.engine);
	printf("\nВыберите поле для редактирования:\n");
	printf("1. Фамилия\n");
	printf("2. Имя\n");
	printf("3. Отчество\n");
	printf("4. Марка автомобиля\n");
	printf("5. Дата покупки автомобиля\n");
	printf("6. Состояние автомобиля\n");
	printf("7. Объем двигателя\n");
	switch (c = _getch()){
	case '1':{
			printf("Введите новую фамилию: ");
			gets_s(li->item.surname);
			break;
	}
	case '2':{
			printf("Введите новое имя: ");
			gets_s(li->item.name);
			break;
	}
	case '3':{
			printf("Введите новое отчество: ");
			gets_s(li->item.lastname);
			break;
	}
	case '4':{
			printf("Введите марку автомобиля: ");
			gets_s(li->item.markaAvto);
			break;
	}
	case '5':{
			printf("Введите дату покупки: ");
			gets_s(li->item.date);
			break;
	}
	case '6':{
			printf("Введите состояние автомобился(Новая/Подержанная): ");
			gets_s(li->item.info);
			break;
	}
	case '7':{
			printf("Введите объем двигателя: "); 
			gets_s(li->item.engine);
			break;
	}
	case 27:exit(1);
	}
}

void FindAuto(NODE *pNode){
	NODE *t = pNode;
	char mark[7];

	while (t){
		if (strcmp(t->item.info, "Подержанная") == 0){
			printf("%s.%s %s %s %s %s %s %s\n", t->item.key, t->item.surname, t->item.name, t->item.lastname, t->item.markaAvto, t->item.date, t->item.info, t->item.engine);
		}
		t = t->next;
	}
	printf("\n>>>");
	_getch();
}

void CountM(NODE *pNode){
	NODE *t = pNode->next;
	char years[50][6];
	int count[50], i = 0, j;
	bool flag, ex = TRUE;

	for (int k = 0; k<50; k++)
		count[k] = 0;
	char tyear[6];

	tyear[0] = t->item.date[6];
	tyear[1] = t->item.date[7];
	tyear[2] = t->item.date[8];
	tyear[3] = t->item.date[9];
	tyear[4] = '\0';

	strcpy_s(years[0], tyear);

	while (i<50 && t){
		if (t->next == NULL){
			ex = FALSE;
			break;
		}
		t = t->next;
		flag = TRUE;
		for (j = 0; j <= i; j++){
			tyear[0] = t->item.date[6];
			tyear[1] = t->item.date[7];
			tyear[2] = t->item.date[8];
			tyear[3] = t->item.date[9];
			tyear[4] = '\0';
			if (strcmp(years[j], tyear) == 0 && t != NULL){
				flag = FALSE;
				break;
			}
		}

		if (flag && t != NULL){
			i++;
			strcpy_s(years[i], tyear);
		}
	}

	NODE *t1 = pNode->next;
	NODE *t2;
	for (int q = 0; q <= i; q++){
		t2 = t1;
		while (t2){
			tyear[0] = t2->item.date[6];
			tyear[1] = t2->item.date[7];
			tyear[2] = t2->item.date[8];
			tyear[3] = t2->item.date[9];
			tyear[4] = '\0';
			if (strcmp(years[q], tyear) == 0)
				count[q]++;
			t2 = t2->next;
		}
	}
	printf("Год     Число автомобилей\n");
	for (int p = 0; p <= i; p++){
		printf("%-15s%-5d\n", years[p], count[p]);
	}

	FILE *ff;
	if (fopen_s(&ff, "TableOfYears.txt", "w")){
		printf("Ошибка при открытии\n");
		exit(1);
	}

	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-10s", years[p]);
	}
	fprintf(ff, "\n");
	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-10d", count[p]);
	}
	
	fclose(ff);
	printf("\n>>>");
	_getch();
}

void Add(LIST **pList, char key[], char surname[], char name[], char lastname[], char markaAvto[], char date[], char info[], char engine[]){
	NODE *newli = new NODE;

	strcpy_s(newli->item.key, key);
	strcpy_s(newli->item.surname, surname);
	strcpy_s(newli->item.name, name);
	strcpy_s(newli->item.lastname, lastname);
	strcpy_s(newli->item.markaAvto, markaAvto);
	strcpy_s(newli->item.date, date);
	strcpy_s(newli->item.info, info);
	strcpy_s(newli->item.engine, engine);
	(*pList)->len++;
	
	if ((*pList)->top == NULL){
		newli->next = NULL;
		(*pList)->top = newli;
		return;
	}

	NODE *temp = (*pList)->top;
	while (temp->next){
		temp = temp->next;
	}
	temp->next = newli;
	newli->next = NULL;
}

void AddFile(LIST **pList){
	FILE *file;
	char key[7];
	char surname[30];
	char name[30];
	char lastname[30];
	char markaAvto[20];
	char date[20];
	char info[20];
	char engine[20];

	fopen_s(&file, "Table.txt", "a");

	printf("Введите номер(макс. 5 симв.): "); gets_s(key);
	fputs("\n", file);
	fputs(key, file);
	fputs("\n", file);

	printf("Фамилия: ");
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
	
	printf("Марка автомобиля: ");
	gets_s(markaAvto);
	fputs(markaAvto, file);
	fputs("\n", file);
	
	printf("Дата покупки (ДД.ММ.ГГГГ): ");
	gets_s(date);
	fputs(date, file);
	fputs("\n", file);
	
	printf("Техническое состояние(Новая/Подержанная): ");
	gets_s(info);
	fputs(info, file);
	fputs("\n", file);
	
	printf("Объем двигателя (в см3): ");
	gets_s(engine);
	fputs(engine, file);

	Add(pList, key, surname, name, lastname, markaAvto, date, info, engine);
	
	fclose(file);
}

void DeleteElement(LIST **pList){
	(*pList)->len--;
	
	char key[7];
	Print((*pList)->top);
	printf("\nВведите номер удаляемой записи: ");
	gets_s(key);

	NODE *t = (*pList)->top;
	if (strcmp(t->item.key, key) == 0){
		(*pList)->top = t->next;
		delete t;
		return;
	}

	NODE *t1 = t->next;
	while (t1){
		if (strcmp(t1->item.key, key) == 0){
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}

void ReadFromFile(LIST **pList){
	FILE *file;
	char key[7];
	char surname[30];
	char name[30];
	char lastname[30];
	char markaAvto[20];
	char date[20];
	char info[20];
	char engine[20];

	fopen_s(&file, "Table.txt", "r+");

	while (!feof(file)){
		fgets(key, 7, file); z(key);
		fgets(surname, 30, file); z(surname);
		fgets(name, 30, file); z(name);
		fgets(lastname, 30, file); z(lastname);
		fgets(markaAvto, 20, file); z(markaAvto);
		fgets(date, 20, file); z(date);
		fgets(info, 20, file);	z(info);
		fgets(engine, 20, file); z(engine);
		Add(pList, key, surname, name, lastname, markaAvto, date, info, engine);
	}

	fclose(file);
}

void SaveToFile(NODE **pNode){
	FILE *file;
	fopen_s(&file, "Table.txt", "w+");

	NODE *li = (*pNode)->next;
	while (li){
		fputs(li->item.key, file); fprintf(file, "\n");
		fputs(li->item.surname, file); fprintf(file, "\n");
		fputs(li->item.name, file); fprintf(file, "\n");
		fputs(li->item.lastname, file); fprintf(file, "\n");
		fputs(li->item.markaAvto, file); fprintf(file, "\n");
		fputs(li->item.date, file); fprintf(file, "\n");
		fputs(li->item.info, file); fprintf(file, "\n");
		fputs(li->item.engine, file);
		if (li->next != NULL)
			fprintf(file, "\n");
		li = li->next;
	}
	fclose(file);
}

