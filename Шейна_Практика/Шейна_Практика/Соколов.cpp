// theatre.cpp: определяет точку входа для консольного приложения.
//
// Для корректного отображения русских символов в консоли
// необходимо нажать правой клавишей в левом углу окна консоли
// выбрать "Свойства" и установить шрифт на Lucida Console
// и затем нажать OK
//
//++

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>

struct Abonents{
	char key[7];		// Поле Ключ для работы с записями
	char fio[30];		// Фамилия И.О. абонента
	char number[15];	// Телефонный номер
	char date[15];		// Дата установки телефона
	char oplata[10];	// Оплачен ли счет
};

struct NODE{
	Abonents data;
	NODE *next;
};

struct LIST{
	int len;
	NODE *top;
};

void CreateList(LIST**);
void Print(NODE*);
void Edit(NODE**);
void Find(NODE*);
void ConnectTable(NODE*);
void AddToList(LIST **pList, Abonents*);
void CreateAndAddToFile(LIST**);
void DeleteElement(LIST**);
void ReadFromFile(LIST**);
void SaveToFile(NODE**);
void z(char*);

int _tmain(int argc, _TCHAR* argv[])
{
	system("color F0");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LIST *pLIST;
	CreateList(&pLIST);
	ReadFromFile(&pLIST);

	char key;
	while (1){
		system("CLS");
		printf("-------------------------------");
		printf("\n1. Вывести таблицу абонентов на экран\n");
		printf("2. Добавить новую запись\n");
		printf("3. Редактировать запись\n");
		printf("4. Удалить запись\n");
		printf("5. Поиск должников\n");
		printf("6. Таблица количества подключений по месяцам\n");
		printf("Esc. Выход\n");
		printf("-------------------------------\n->");
		key = _getch();
		switch (key){
		case '1':{
					 system("CLS");
					 printf("----------------\n");
					 Print(pLIST->top);
					 printf("\nНажмите любую клавишу для возврата...");
					 _getch();
					 break;
		}
		case '2':{
					 system("CLS");
					 printf("-----Меню добавления новой записи-----\n");
					 CreateAndAddToFile(&pLIST);
					 break;
		}
		case '3':{
					 system("CLS");
					 printf("-----Меню редактирования записи-----\n");
					 Edit(&pLIST->top);
					 SaveToFile(&pLIST->top);
					 break;
		}
		case '4':{
					 system("CLS");
					 printf("-----Меню удаления записи по ключу-----\n");
					 DeleteElement(&pLIST);
					 SaveToFile(&pLIST->top);
					 break;
		}
		case '5':{
					 system("CLS");
					 printf("-----Поиск должников-----\n");
					 Find(pLIST->top);
					 break;
		}
		case '6':{
					 system("CLS");
					 printf("-----ТаБлица количества подключений по месяцам------\n");
					 ConnectTable(pLIST->top);
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

void CreateList(LIST **pList){
	*pList = new LIST;
	(*pList)->top = new NODE;
	(*pList)->len = 0;
	(*pList)->top->next = NULL;
}

void Print(NODE *pNode){
	NODE *n = pNode->next;
	while (n){
		printf("%-3s %-20s %-8s %-12s %-6s \n", n->data.key, n->data.fio, n->data.number, n->data.date, n->data.oplata);
		n = n->next;
	}
}

void Edit(NODE **pNode){
	NODE *n = *pNode;
	char c;
	char key[7];

	Print(*pNode);

	printf("\nВведите ключ для редактирования:");
	gets_s(key);

	while (strcmp(n->data.key, key) != 0)
		n = n->next;

	printf("%-3s %-20s %-8s %-12s %-6s \n", n->data.key, n->data.fio, n->data.number, n->data.date, n->data.oplata);
	printf("\nВыберите поле для редактирования:\n");
	printf("1. Фамилия И.О. абонента\n");
	printf("2. Телефонный номер\n");
	printf("3. Дата установки телефона\n");
	printf("4. Оплачен ли счет\n");
	switch (c = _getch()){
	case '1':{
				 printf("Введите Фамилию И.О.: ");
				 gets_s(n->data.fio);
				 break;
	}
	case '2':{
				 printf("Введите телефонный номер: ");
				 gets_s(n->data.number);
				 break;
	}
	case '3':{
				 printf("Введите дату установки телефона: ");
				 gets_s(n->data.date);
				 break;
	}
	case '4':{
				 printf("Введите оплачен ли счет: ");
				 gets_s(n->data.oplata);
				 break;
	}
	case 27:exit(1);

	default:{
				printf("Invalid Key");
				break;
	}
	}
}

void Find(NODE *pNode){
	NODE *n = pNode;

	while (n){
		if (strcmp(n->data.oplata,"Нет")==0){
			printf("%-3s %-20s %-8s %-12s %-6s \n", n->data.key, n->data.fio, n->data.number, n->data.date, n->data.oplata);
			printf("Отправка уведомления об отключении телефона...\n\n");
		}
		n = n->next;
	}
	printf("\n>>>");
	_getch();
}

void ConnectTable(NODE *pNode){
	NODE *t = pNode->next;
	FILE *table;
	fopen_s(&table, "ConnectTable.txt", "w");

	char mas[13][3] = { "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
	char m[3];
	int mc[13] = { 0 };
	int i;
	while (t){
		m[0] = t->data.date[3];
		m[1] = t->data.date[4];
		m[2] = '\0';
		for (i = 1; i <= 12; i++){
			if (strcmp(m, mas[i]) == 0)
				mc[i]++;
		}
		t = t->next;
	}
	system("CLS");
	printf("Янв. Фев. Март Апр. Май  Июнь Июль Авг. Сен. Окт. Ноя. Дек.\n");
	fprintf(table, "Янв. Фев. Март Апр. Май  Июнь Июль Авг. Сен. Окт. Ноя. Дек.\n");
	for (i = 1; i <= 12; i++){
		printf(" %d   ", mc[i]);
		fprintf(table, " %d   ", mc[i]);
	}
	printf("\n");
	fclose(table);
	_getch();
}

void AddToList(LIST **pList, Abonents temp){
	NODE *n = new NODE;
	
	strcpy_s(n->data.key, temp.key);
	strcpy_s(n->data.fio, temp.fio);
	strcpy_s(n->data.number, temp.number);
	strcpy_s(n->data.date, temp.date);
	strcpy_s(n->data.oplata, temp.oplata);

	(*pList)->len++;

	if ((*pList)->top == NULL){
		n->next = NULL;
		(*pList)->top = n;
		return;
	}

	NODE *temp1 = (*pList)->top;
	while (temp1->next){
		temp1 = temp1->next;
	}
	temp1->next = n;
	n->next = NULL;
}

void CreateAndAddToFile(LIST **pList){
	FILE *file;
	Abonents temp1;
	
	fopen_s(&file, "listAbonents.txt", "a");

	printf("Введите ключ: ");
	gets_s(temp1.key);
	fputs("\n", file);
	fputs(temp1.key, file);
	fputs("\n", file);

	printf("Фамилия И.О.: ");
	gets_s(temp1.fio);
	fputs(temp1.fio, file);
	fputs("\n", file);

	printf("Телефонный номер: ");
	gets_s(temp1.number);
	fputs(temp1.number, file);
	fputs("\n", file);

	printf("Дата установки : ");
	gets_s(temp1.date);
	fputs(temp1.date, file);
	fputs("\n", file);

	printf("Оплачен ли счет: ");
	gets_s(temp1.oplata);
	fputs(temp1.oplata, file);
	
	AddToList(pList, temp1);
	fclose(file);
}

void DeleteElement(LIST **pList){

	(*pList)->len--;

	char key[7];
	Print((*pList)->top);
	printf("\nВведите ключ удаляемой записи: ");
	gets_s(key);

	NODE *t = (*pList)->top;
	if (strcmp(t->data.key, key) == 0){
		(*pList)->top = t->next;
		delete t;
		return;
	}

	NODE *t1 = t->next;
	while (t1){
		if (strcmp(t1->data.key, key) == 0){
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
	Abonents temp1;
	fopen_s(&file, "listAbonents.txt", "r+");

	while (!feof(file)){
		fgets(temp1.key, 7, file); z(temp1.key);
		fgets(temp1.fio, 30, file); z(temp1.fio);
		fgets(temp1.number, 15, file); z(temp1.number);
		fgets(temp1.date, 15, file); z(temp1.date);
		fgets(temp1.oplata, 10, file); z(temp1.oplata);

		AddToList(pList, temp1);
	}

	fclose(file);
}

void SaveToFile(NODE **pNode){
	FILE *file;
	fopen_s(&file, "listAbonents.txt", "w");

	NODE *nnode = (*pNode)->next;
	while (nnode){
		fputs(nnode->data.key, file);
		fprintf(file, "\n");
		fputs(nnode->data.fio, file);
		fprintf(file, "\n");
		fputs(nnode->data.number, file); 
		fprintf(file, "\n");
		fputs(nnode->data.date, file);
		fprintf(file, "\n");
		fputs(nnode->data.oplata, file);
		if (nnode->next != NULL)
			fprintf(file, "\n");
		nnode = nnode->next;
	}
	fclose(file);
}


