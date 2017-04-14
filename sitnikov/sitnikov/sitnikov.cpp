// sitnikov.cpp: определяет точку входа для консольного приложения.
//
// Дл корректного отображения русских шрифтов
// В свойствах консоли необходимо изменить шрифт
// На Lucida Console
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>

#define clear system("CLS")		//Очистка экрана

using namespace std;

struct Air{				//Объявление структуры данных
	char Flight[20];	//Название рейса
	char City[30];		//Город прибытия
	char date[12];		//Дата вылета
	char time[10];		//Время вылета
	char prom[5];		//Наличие промежуточных посадок
};

struct node{			//Объявление структуры узла
	Air data;			//Объявление переменной структуры данных
	node *next;			//Указатель на следующий элемент списка
};

struct list{			//Объявление структуры списка
	int count;			//Количество элементов списка
	node *top;			//Объявление переменной струтуры узла
};

void Init(list**);
bool IsEmpty(node*);
void Print(node*);
void Insert(list**, Air*);
void DelElem(list**, char*);
void Free(list **);
void DelN(char*, char);
void InputFromFile(list **);
void AddElem(list **);
void DelFlight(list **);
void Change(node **);
void SearchDate(node *);
void CreateTable(node *);

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);			// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	// установка кодовой страницы win-cp 1251 в поток вывода
	list *begin = NULL;

	char key;

	Init(&begin);

	InputFromFile(&begin);
	
	while (1){
		clear;
		Print(begin->top);
		printf("\nВыберите операцию:\n");
		printf("1 Добавление рейса\n");
		printf("2 Удаление рейса\n");
		printf("3 Редактирование рейса\n");
		printf("4 Поиск рейса по дате\n");
		printf("5 Создание таблицы количества рейсов по городам прибытия\n");
		printf("Esc Завершение работы приложения\n");
		key = _getch();

		switch (key){
		case '1':
			clear;
			AddElem(&begin);
			clear;
			Print(begin->top);
			break;
		case '2':
			DelFlight(&begin);
			clear;
			Print(begin->top);
			break;
		case '3':
			Change(&begin->top);
			Print(begin->top);
			break;
		case '4':
			SearchDate(begin->top);
			break;
		case '5':
			clear;
			CreateTable(begin->top);
			break;
		case 27:
			exit(1);
		default:
			printf("Такой оперaции не существует\n");
			break;
		}
	}

	Free(&begin);

	return 0;
}

void Init(list **begin){
	*begin = new list;
	(*begin)->top = new node;
	(*begin)->top->next = NULL;
}

bool IsEmpty(node *begin){
	if (!begin)
		return false;
	else
		return true;
}

void Print(node *begin){
	node *t = begin->next;
	printf("№ рейса   Город прибытия\t   Дата вылета    Время вылета  Промеж. рейс\n");
	while (t){
		printf("%-10s", t->data.Flight);
		printf("%-25s", t->data.City);
		printf("%-15s", t->data.date);
		printf("%-15s", t->data.time);
		printf("%-7s", t->data.prom);
		printf("\n");
		t = t->next;
	}
}

void Insert(list **lst, Air f1){
	node *nd = new node;

	strcpy_s(nd->data.Flight, f1.Flight);
	strcpy_s(nd->data.City, f1.City);
	strcpy_s(nd->data.date, f1.date);
	strcpy_s(nd->data.time, f1.time);
	strcpy_s(nd->data.prom, f1.prom);

	(*lst)->count++;

	if ((*lst)->top == NULL){
		nd->next = NULL;
		(*lst)->top = nd;
		return;
	}

	node *t = (*lst)->top;

	while (t->next){
		t = t->next;
	}

	t->next = nd;
	nd->next = NULL;
}

void DelElem(list **lst, char Flight[]){
	(*lst)->count--;

	if ((*lst)->top == NULL)
		return;

	node *t = (*lst)->top;
	if (strcmp(t->data.Flight, Flight) == 0){
		(*lst)->top = t->next;
		delete t;
		return;
	}

	node *t1 = t->next;
	while (t1){
		if (strcmp(t1->data.Flight, Flight) == 0){
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}

void Free(list **begin){
	if ((*begin)->top == NULL)
		return;

	node *t = (*begin)->top;
	node *t1;
	while (t){
		t1 = t;
		t = t->next;
		delete t1;
	}
	delete begin;
	*begin = NULL;
}

void DelN(char str[], char x){
	int i = 0;
	int j = i;
	while (str[i]){
		if (str[i] != x)
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

void InputFromFile(list **lst){
	FILE *f;
	Air f1;
	char x = '\n';	//удаляемый символ

	if (fopen_s(&f, "Air.txt", "r")){
		printf("Ошибка при открытии\n");
		exit(1);
	}

	while (!feof(f)){
		fgets(f1.Flight, 20, f);
		fgets(f1.City, 30, f);
		fgets(f1.date, 12, f);
		fgets(f1.time, 10, f);
		fgets(f1.prom, 5, f);

		DelN(f1.Flight, x);
		DelN(f1.City, x);
		DelN(f1.date, x);
		DelN(f1.time, x);
		DelN(f1.prom, x);

		Insert(lst, f1);
	}
	fclose(f);
}

void AddElem(list **lst){
	FILE *f;
	Air f1;

	printf("Введите параметры рейса:\n");
	
	printf("Рейс (XX 0000) : ");
	gets_s(f1.Flight);

	printf("Город прибытия: ");
	gets_s(f1.City);

	printf("Дата вылета (ДД.ММ.ГГГГ): ");
	gets_s(f1.date);

	printf("Время вылета (Ч:ММ:СС): ");
	gets_s(f1.time);

	printf("Наличие промежуточных посадок (Да/Нет): ");
	gets_s(f1.prom);

	Insert(lst, f1);

	if (fopen_s(&f, "Air.txt", "a")){
		printf("Ошибка при открытии\n");
		exit(1);
	}

	fprintf(f, "\n");
	fputs(f1.Flight, f);
	fprintf(f, "\n");
	fputs(f1.City, f);
	fprintf(f, "\n");
	fputs(f1.date, f);
	fprintf(f, "\n");
	fputs(f1.time, f);
	fprintf(f, "\n");
	fputs(f1.prom, f);
	fclose(f);
}

void DelFlight(list **lst){
	FILE *f;
	char Flight[20];

	printf("Введите название рейса: ");
	gets_s(Flight);
	DelElem(lst, Flight);

	if (fopen_s(&f, "Air.txt", "w")){
		printf("Ошибка при открытии\n");
		exit(1);
	}

	if ((*lst)->top != NULL){
		node *t = (*lst)->top->next;
		while (t){
			fputs(t->data.Flight, f);
			fprintf(f, "\n");
			fputs(t->data.City, f);
			fprintf(f, "\n");
			fputs(t->data.date, f);
			fprintf(f, "\n");
			fputs(t->data.time, f);
			fprintf(f, "\n");
			fputs(t->data.prom, f);
			if (t->next != NULL)
				fprintf(f, "\n");
			t = t->next;
		}
	}
	fclose(f);
}

void Change(node **timetable){
	FILE *f;
	char Flight[20];
	char City[30];
	char date[12];
	char time[10];
	char prom[5];
	char key;

	printf("Введите название рейса: ");
	gets_s(Flight);
	clear;
	node *t1 = *timetable;
	while (t1 && strcmp(t1->data.Flight, Flight) != 0){
		t1 = t1->next;
	}

	if (t1 == NULL)
		printf("Таких рейсов не найдено\n");
	else{
		printf("%-10s", t1->data.Flight);
		printf("%-25s", t1->data.City);
		printf("%-15s", t1->data.date);
		printf("%-15s", t1->data.time);
		printf("%-7s", t1->data.prom);
		printf("\n");
		printf("Изменению подлежит:\n1 Номер рейса\n2 Город прибытия\n3 Дата вылета\n4 Время вылета\n5 Наличие промежуточных посадок\nВыберите изменяемое поле: ");
		key = _getche();
		switch (key){
		case '1':
			printf("\nНовый номер рейса: ");
			gets_s(Flight);
			strcpy_s(t1->data.Flight, Flight);
			break;
		case '2':
			printf("\nНовый город прибытия: ");
			gets_s(City);
			strcpy_s(t1->data.City, City);
			break;
		case '3':
			printf("\nНовая дата прибытия: ");
			gets_s(date);
			strcpy_s(t1->data.date, date);
			break;
		case '4':
			printf("\nНовое время прибытия: ");
			gets_s(time);
			strcpy_s(t1->data.time, time);
			break;
		case '5':
			printf("\nНаличие промежуточных посадок: ");
			gets_s(prom);
			strcpy_s(t1->data.prom, prom);
			break;
		default:
			clear;
			printf("\nТакого поля не существует\n");
			_getch();
		}
	}
	printf("\n");

	if (fopen_s(&f, "Air.txt", "w")){
		printf("Ошибка при открытии\n");
		exit(1);
	}

	if (*timetable != NULL){
		node *t = (*timetable)->next;
		while (t){
			fputs(t->data.Flight, f);
			fprintf(f, "\n");
			fputs(t->data.City, f);
			fprintf(f, "\n");
			fputs(t->data.date, f);
			fprintf(f, "\n");
			fputs(t->data.time, f);
			fprintf(f, "\n");
			fputs(t->data.prom, f);
			if (t->next != NULL)
				fprintf(f, "\n");
			t = t->next;
		}
	}
	fclose(f);
}

void SearchDate(node *timetable){
	if (timetable != NULL){
		char date[12];
		node *t = timetable->next;
		printf("Введите дату для поиска: ");
		gets_s(date);
		clear;
			printf("Найденные записи:\n\n");
		while (t){
			if (strcmp(t->data.date, date) == 0){
				printf("%-10s", t->data.Flight);
				printf("%-25s", t->data.City);
				printf("%-15s", t->data.date);
				printf("%-15s", t->data.time);
				printf("%-7s", t->data.prom);
				printf("\n");
			}
			t = t->next;
		}
	}
	printf(">>Для возрата нажмите любую клавишу<<"); _getch();
}

void CreateTable(node *timetable){
	node *t = timetable->next;
	char cities[50][30];
	int count[50], i = 0, j;
	bool flag, ex = TRUE;

	for (int k = 0; k<50; k++)
		count[k] = 0;

	strcpy_s(cities[0], t->data.City);

	while (i<50 && t){
		if (t->next == NULL){
			ex = FALSE;
			break;
		}
		t = t->next;
		flag = TRUE;
		for (j = 0; j <= i; j++){
			if (strcmp(cities[j], t->data.City) == 0 && t != NULL){
				flag = FALSE;
				break;
			}
		}

		if (flag && t != NULL){
			i++;
			strcpy_s(cities[i], t->data.City);
		}
	}

	node *t1 = timetable->next;
	node *t2;
	for (int q = 0; q <= i; q++){
		t2 = t1;
		while (t2){
			if (strcmp(cities[q], t2->data.City) == 0)
				count[q]++;
			t2 = t2->next;
		}
	}

	for (int p = 0; p <= i; p++){
		printf("%-30s%-5d\n", cities[p], count[p]);
	}

	FILE *ff;
	if (fopen_s(&ff, "TableOfCities.txt", "w")){
		printf("Ошибка при открытии\n");
		exit(1);
	}

	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-25s", cities[p]);
	}
	fprintf(ff, "\n");
	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-25d", count[p]);
	}

	fclose(ff);
	printf(">>Для возврата нажмите любую клавишу<<");
	_getch();
}
