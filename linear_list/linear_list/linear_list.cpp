// bank bank.cpp: определяет точку входа для консольного приложения.
//
// Для отображения русских символов в консоли
// необходимо зайти в свойства консоли
// (правой клавишей мыши по левом верхнему углу окна консоли)
// и изменить шрифт на Lucida Console
//
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>

struct BANK{
	char name_org[20];	// Наименование организации
	char number_p[15];	// Номер платежного получения
	char date[15];		// Дата его поступления
	char otmetka[3];	// Отметка об его выполнении (+ или -)
};

struct NODE{
	BANK org;
	NODE *next;
};

struct list{
	int length;
	NODE *top;
};

void Init(list**);
void Print(NODE*);
void Edit(NODE**);
void Find(NODE*);
void PayTable(NODE*);
void Add(list**, BANK*);
void PutFile(list**);
void Delete(list**);
void Read(list**);
void SaveToFile(NODE**);
void DES(char*);

int _tmain(int argc, _TCHAR* argv[])
{
	system("color F0");
	list *pList;	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char c; 

	Init(&pList);
	Read(&pList);

	while (1){
		system("CLS");
		Print(pList->top);
		printf("\n-Основное меню для работы с таблицей-\n");
		printf("\n1. Добавить новую запись\n");
		printf("2. Редактировать имеющиеся записи\n");
		printf("3. Удалить запись\n");
		printf("4. Поиск платежей организации\n");
		printf("5. Таблица платежей по месяцам\n");
		c = _getch();
		switch (c){
		case '1':{
					 system("CLS");
					 PutFile(&pList);
					 break;
		}
		case '2':{
					 system("CLS");
					 Edit(&pList->top);
					 SaveToFile(&pList->top);
					 break;
		}
		case '3':{
					 system("CLS");
					 Print(pList->top);
					 Delete(&pList);
					 SaveToFile(&pList->top);
					 break;
		}
		case '4':{
					 system("CLS");
					 Find(pList->top);
					 break;
		}
		case '5':{
					 system("CLS");
					 PayTable(pList->top);
					 break;
		}
		case 27:
			exit(1);
		default:
			printf("Некорретный ввод!!!");
				break;
		}
	}
	return 0;
}

void DES(char *c){
	char* position = strrchr(c, '\n');
	if (position) c[position - c] = 0;
}

void Init(list **pList){
	*pList = new list;
	(*pList)->top = new NODE;
	(*pList)->length = 0;
	(*pList)->top->next = NULL;
}

void Print(NODE *pNODE){
		NODE *t = pNODE->next;
		printf(" Наимен. орг-ции      Номер п/п      Дата поступл.   Отм.\n\n");
		while (t){
			printf(" %-20s %-15s %-15s %-4s\n", t->org.name_org, t->org.number_p, t->org.date, t->org.otmetka);
			t = t->next;
		}
}

void Edit(NODE **pNODE){
	NODE *t = *(pNODE);
	
	char c;
	char f[15];
	Print(*pNODE);
	printf("\nВведите Номер п/п для редактирования записи: ");
	gets_s(f);

	while (strcmp(t->org.number_p, f) != 0)
		t = t->next;

	printf(" %-20s %-15s %-15s %-4s\n", t->org.name_org, t->org.number_p, t->org.date, t->org.otmetka);
	printf("\nЧто вы хотели бы изменить?:\n");
	printf("1. Наименование организации\n");
	printf("2. Номер п/п \n");
	printf("3. Дата поступления \n");
	printf("4. Отметка о выполнении (+ или -)\n");
	switch (c = _getch()){
	case '1':{
				 printf("Наименование организации: ");
				 gets_s(t->org.name_org);
				 break;
	}
	case '2':{
				 printf("Номер п/п: ");
				 gets_s(t->org.number_p);
				 break;
	}
	case '3':{
				 printf("Дата поступления: "); 
				 gets_s(t->org.date);
				 break;
	}
	case '4':{
				 printf("Отметка о выполнении: ");
				 gets_s(t->org.otmetka);
				 break;
	}
	case 27:	 exit(1);

	default:{
				printf("-");
				break;
	}
	}
}

void Find(NODE *pNODE){
	NODE *t = pNODE;
	char nameorg[20];
	Print(pNODE);
	printf("Введите название организации: ");
	gets_s(nameorg);

	while (t){
		if (strcmp(t->org.name_org,nameorg)==0){
			printf("%-20s %-15s %-15s %-4s\n", t->org.name_org, t->org.number_p, t->org.date, t->org.otmetka);
		}
		t = t->next;
	}
	printf("\n>>>end");
	_getch();
}

void PayTable(NODE *pNODE){
	NODE *t = pNODE->next;
	FILE *table;
	fopen_s(&table, "paytable.txt", "w");

	char mas[13][3] = { "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
	char m[3];
	int mc[13] = { 0 };
	int i;
	while (t){
		m[0] = t->org.date[3];
		m[1] = t->org.date[4];
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

void Add(list **pList, BANK add){
	NODE *ins = new NODE;
	
	strcpy_s(ins->org.name_org, add.name_org);
	strcpy_s(ins->org.number_p, add.number_p);
	strcpy_s(ins->org.date, add.date);
	strcpy_s(ins->org.otmetka, add.otmetka);


	(*pList)->length++;
	
	if ((*pList)->top == NULL){
		ins->next = NULL;
		(*pList)->top = ins;
		return;
	}
	
	NODE *temp = (*pList)->top;
	while (temp->next){
		temp = temp->next;
	}
	temp->next = ins;
	ins->next = NULL;
}

void PutFile(list **pList){
	FILE *file;
	BANK inse;
	fopen_s(&file, "bankbank.txt", "a");

	printf("Наименование орг-ции: "); 
	gets_s(inse.name_org);  
	fputs("\n", file); 
	fputs(inse.name_org, file); 
	fputs("\n", file);

	printf("Номер п/п: ");
	gets_s(inse.number_p);
	fputs(inse.number_p, file);
	fputs("\n", file);
	
	printf("Дата поступления: ");
	gets_s(inse.date);
	fputs(inse.date, file);
	fputs("\n", file);

	printf("Дата заезда проживающего: ");
	gets_s(inse.date);
	fputs(inse.date, file);
	fputs("\n", file);

	printf("Отметка о выполнении (+ или -): ");
	gets_s(inse.otmetka); 
	fputs(inse.otmetka, file);

	Add(pList, inse);
	fclose(file);
}

void Delete(list **pList){
	(*pList)->length--;

	char number[15];
	printf("\nВведите номер п/п для удаления: ");
	gets_s(number);

	NODE *t = (*pList)->top;
	if (strcmp(t->org.number_p,number)==0){
		(*pList)->top = t->next;
		delete t;
		return;
	}

	NODE *t1 = t->next;
	while (t1){
		if (strcmp(t1->org.number_p, number) == 0){
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}

void Read(list **pList){
	FILE *file;
	BANK ss;
	fopen_s(&file, "bankbank.txt", "r+");
	
	while (!feof(file)){
		fgets(ss.name_org, 20, file); 
		DES(ss.name_org);
		fgets(ss.number_p, 15, file); 
		DES(ss.number_p);
		fgets(ss.date, 15, file); 
		DES(ss.date);
		fgets(ss.otmetka, 3, file);
		DES(ss.otmetka);
		Add(pList, ss);
	}

	fclose(file);
}

void SaveToFile(NODE **pNODE){
	FILE *file;
	fopen_s(&file, "bankbank.txt", "w");

	NODE *temp = (*pNODE)->next;
	while (temp){
		fputs(temp->org.name_org, file); fprintf(file, "\n");
		fputs(temp->org.number_p, file); fprintf(file, "\n");
		fputs(temp->org.date, file); fprintf(file, "\n");
		fputs(temp->org.otmetka, file);
		if (temp->next != NULL)
			fprintf(file, "\n");
		temp = temp->next;
	}
	fclose(file);
}

