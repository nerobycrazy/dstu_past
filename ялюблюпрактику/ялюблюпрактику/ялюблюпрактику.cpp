// Абитуриенты.cpp: определяет точку входа для консольного приложения.
//
// Для корректного отображения русских символов в консоли
// необходимо нажать правой клавишей в левом углу окна консоли
// выбрать "Свойства" и установить шрифт на Lucida Console
// и затем нажать OK
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct zachetka{
	char num[7];			// Номер...
	char Familija[30];		// Фамилия студента
	char Name[30];			// Имя студента
	char Otchestvo[30];		// Отчество студента 
	char Disciplina[30];	// Наименование дисциплины
	char DataSdachi[15];	// Дата сдачи
	char ExamOrZachet[10];	// Экзамен или зачет
	char Mark[15];			// Оценка по экзамену
	char ZachetIliNet[15];	// Зачет или незачет
};

struct NODE{		// Объявление структуры узла
	zachetka base;	// Переменная структуры данных
	NODE *next;		// Указатель на следующий элемент
};

struct LIST{		// Объявление структуры списка
	int len;		// Длина списка
	NODE *top;		// Указатель на вершину списка
};

void Tab(char*);
void Initialize(LIST**);
void Print(NODE*);
void Edit(NODE**);
void Find(NODE*);
void CreateTableS(NODE*);
void AddToList(LIST **pList, zachetka*);
void InsertRecord(LIST**);
void DeleteElement(LIST**);
int ReadFromFile(LIST**);
void SaveToFile(NODE**);

int _tmain(int argc, _TCHAR* argv[])
{
	system("color F0");
	system("mode con cols=115 lines=25");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LIST *pLIST;
	Initialize(&pLIST);
	if (ReadFromFile(&pLIST) == 0){
		return 0;
	}
	else
	{
		char key;
		while (1){
			system("CLS");
			printf("---------------------\n");
			printf("1. Показать таблицу\n");
			printf("2. Добавить запись\n");
			printf("3. Редактировать запись\n");
			printf("4. Удалить запись\n");
			printf("5. Поиск по дисциплине\n");
			printf("6. Сводная таблица среднего балла\n");
			printf("7. Сохранение изменений в файл\n");
			printf("Esc. Выход\n");
			printf("--------------------\n->");
			key = _getch();
			switch (key){
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
						 InsertRecord(&pLIST);
						 break;
			}
			case '3':{
						 system("CLS");
						 printf("-----Меню редактирования записи-----\n");
						 Edit(&pLIST->top);
						 break;
			}
			case '4':{
						 system("CLS");
						 printf("-----Меню удаления записи по номеру-----\n");
						 DeleteElement(&pLIST);
						 break;
			}
			case '5':{
						 system("CLS");
						 printf("-----Поиск по дисциплине-----\n");
						 Find(pLIST->top);
						 break;
			}
			case '6':{
						 system("CLS");
						 printf("-----Сводная таблица-----\n");
						 CreateTableS(pLIST->top);
						 break;
			}
			case '7':{
						 printf("Даные успешно записаны в файл!\n");
						 SaveToFile(&pLIST->top);
						 _getch();
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
}

void Tab(char *c){
	char* pos = strrchr(c, '\n');
	if (pos) c[pos - c] = 0;
}

void Initialize(LIST **pList){
	*pList = new LIST;
	(*pList)->top = new NODE;
	(*pList)->len = 0;
	(*pList)->top->next = NULL;
}

void Print(NODE *pNode){
	NODE *n = pNode->next;
	while (n){
		printf("%-2s %-15s %-10s %-15s %-20s %-15s %-10s %-5s %-7s \n", n->base.num, n->base.Familija, n->base.Name, n->base.Otchestvo, n->base.Disciplina, n->base.DataSdachi, n->base.ExamOrZachet, n->base.Mark, n->base.ZachetIliNet);
		n = n->next;
	}
}

void Edit(NODE **pNode){
	NODE *n = *pNode;
	char c;
	char num[7];


	Print(*pNode);
	printf("Введите номер для редактирования:");
	gets_s(num);

	while (strcmp(n->base.num, num) != 0){
		n = n->next;
	}
	printf("%s %s %s %s %s %s %s %s %s \n", n->base.num, n->base.Familija, n->base.Name, n->base.Otchestvo, n->base.Disciplina, n->base.DataSdachi, n->base.ExamOrZachet, n->base.Mark, n->base.ZachetIliNet);
	printf("\nВыберите поле для редактирования\n");
	printf("1. Фамилия\n");
	printf("2. Имя\n");
	printf("3. Отчество\n");
	printf("4. Дисциплина\n");
	printf("5. Дата сдачи\n");
	printf("6. Экзамен или зачет\n");
	printf("7. Оценка\n");
	printf("8. Зачет или Незачет\n");
	switch (c = _getch()){
	case '1':{
				 printf("Введите фамилию: ");
				 gets_s(n->base.Familija);
				 break;
	}
	case '2':{
				 printf("Введите имя: ");
				 gets_s(n->base.Name);
				 break;
	}
	case '3':{
				 printf("Введите отчество: ");
				 gets_s(n->base.Otchestvo);
				 break;
	}
	case '4':{
				 printf("Введите дисциплину: ");
				 gets_s(n->base.Disciplina);
				 break;
	}
	case '5':{
				 printf("Дата сдачи: ");
				 gets_s(n->base.DataSdachi);
				 break;
	}
	case '6':{
				 printf("Экзамен или зачет: ");
				 gets_s(n->base.ExamOrZachet);
				 break;
	}
	case '7':{
				 printf("Оценка: ");
				 gets_s(n->base.Mark);
				 break;
	}
	case '8':{
				 printf("Зачет или Незачет: ");
				 gets_s(n->base.ZachetIliNet);
				 break;
	}
	case 27: exit(1);

	default:{
				printf("Invalid Key");
				break;
	}
	}
}

void Find(NODE *pNode){
	NODE *t = pNode;
	char Dis[30];

	printf("Введите наименование дисциплины: ");
	gets_s(Dis);

	while (t){
		if ((strcmp(t->base.Disciplina, Dis) == 0) && (strcmp(t->base.Mark, "2") || (strcmp(t->base.ZachetIliNet, "Незачет")))) {
			printf("%s %s %s %s %s %s %s %s %s \n", t->base.num, t->base.Familija, t->base.Name, t->base.Otchestvo, t->base.Disciplina, t->base.DataSdachi, t->base.ExamOrZachet, t->base.Mark, t->base.ZachetIliNet);
		}
		t = t->next;
	}
	printf("\n>>>");
	_getch();
}

void CreateTableS(NODE *pNode){
	NODE *t = pNode->next;

	char disc[50][30];
	double sum[50] = { 0 };
	int count[50], i = 0, j;
	bool flag, ex = TRUE;

	for (int k = 0; k<50; k++)
		count[k] = 0;

	strcpy_s(disc[0], t->base.Disciplina);

	while (i<50 && t){
		if (t->next == NULL){
			ex = FALSE;
			break;
		}
		t = t->next;
		flag = TRUE;
		for (j = 0; j <= i; j++){
			if (strcmp(disc[j], t->base.Disciplina) == 0 && t != NULL){
				flag = FALSE;
				break;
			}
		}

		if (flag && t != NULL){
			i++;
			strcpy_s(disc[i], t->base.Disciplina);
		}
	}

	NODE *t1 = pNode->next;
	NODE *t2;
	for (int q = 0; q <= i; q++){
		t2 = t1;
		while (t2){
			if (strcmp(disc[q], t2->base.Disciplina) == 0){
				sum[q] += atof(t2->base.Mark);
				count[q]++;
			}
			t2 = t2->next;
		}
	}
	printf("Дисциплина          Средний балл\n");
	printf("_________________________________\n");
	for (int p = 0; p <= i; p++){
		printf("%-25s%.2f\n", disc[p], (sum[p] / count[p]));
	}
	printf("\nЗначение 0.00 означает, что это зачет БЕЗ оценки!\n");
	FILE *ff;
	if (fopen_s(&ff, "SredniyBall.txt", "w")){
		printf("Ошибка при открытии\n");
		exit(1);
	}

	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-13s", disc[p]);
	}
	fprintf(ff, "\n");
	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-13.2f", sum[p] / count[p]);
	}

	fclose(ff);
	printf("\n>>>");
	_getch();
}

void AddToList(LIST **pList, zachetka temp){
	NODE *n = new NODE;

	strcpy_s(n->base.num, temp.num);
	strcpy_s(n->base.Familija, temp.Familija);
	strcpy_s(n->base.Name, temp.Name);
	strcpy_s(n->base.Otchestvo, temp.Otchestvo);
	strcpy_s(n->base.Disciplina, temp.Disciplina);
	strcpy_s(n->base.DataSdachi, temp.DataSdachi);
	strcpy_s(n->base.ExamOrZachet, temp.ExamOrZachet);
	strcpy_s(n->base.Mark, temp.Mark);
	strcpy_s(n->base.ZachetIliNet, temp.ZachetIliNet);

	(*pList)->len++;

	if ((*pList)->top == NULL){
		n->next = NULL;
		(*pList)->top = n;
		return;
	}

	NODE *noo = (*pList)->top;
	while (noo->next){
		noo = noo->next;
	}
	noo->next = n;
	n->next = NULL;
}

void InsertRecord(LIST **pList){
	zachetka temp1;

	printf("Введите номер: ");
	gets_s(temp1.num);

	printf("Фамилия студента: ");
	gets_s(temp1.Familija);

	printf("Имя студента: ");
	gets_s(temp1.Name);

	printf("Отчество студента : ");
	gets_s(temp1.Otchestvo);

	printf("Сдаваемая дисциплина: ");
	gets_s(temp1.Disciplina);

	printf("Дата сдачи: ");
	gets_s(temp1.DataSdachi);

	printf("Экзамен или зачет: ");
	gets_s(temp1.ExamOrZachet);

	printf("Оценка: ");
	gets_s(temp1.Mark);

	printf("Зачет или Незачет: ");
	gets_s(temp1.ZachetIliNet);

	AddToList(pList, temp1);
}

void DeleteElement(LIST **pList){
	char num[7];
	Print((*pList)->top);
	printf("\nВведите номер удаляемой записи: ");
	gets_s(num);

	NODE *t = (*pList)->top;

	(*pList)->len--;

	if (strcmp(t->base.num, num) == 0){
		(*pList)->top = t->next;
		delete t;
		return;
	}

	NODE *t1 = t->next;
	while (t1){
		if (strcmp(t1->base.num, num) == 0){
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}


}

int ReadFromFile(LIST **pList){
	FILE *file;
	zachetka temp1;

	if (fopen_s(&file, "dbZachetki.txt", "r+")){
		printf("Ошибка чтения файла\n");
		printf("Проверьте наличие файла dbZachetki.txt в папке с программой\n");
		return 0;
	}
	else
	{
		while (!feof(file)){
			fgets(temp1.num, 7, file); Tab(temp1.num);
			fgets(temp1.Familija, 30, file); Tab(temp1.Familija);
			fgets(temp1.Name, 30, file); Tab(temp1.Name);
			fgets(temp1.Otchestvo, 30, file); Tab(temp1.Otchestvo);
			fgets(temp1.Disciplina, 30, file); Tab(temp1.Disciplina);
			fgets(temp1.DataSdachi, 15, file); Tab(temp1.DataSdachi);
			fgets(temp1.ExamOrZachet, 10, file); Tab(temp1.ExamOrZachet);
			fgets(temp1.Mark, 15, file); Tab(temp1.Mark);
			fgets(temp1.ZachetIliNet, 15, file); Tab(temp1.ZachetIliNet);
			AddToList(pList, temp1);
		}
		fclose(file);
		return 1;
	}
}

void SaveToFile(NODE **pNode){
	FILE *file;
	fopen_s(&file, "dbZachetki.txt", "w");

	NODE *x = (*pNode)->next;
	while (x){
		fputs(x->base.num, file);
		fprintf(file, "\n");
		fputs(x->base.Familija, file);
		fprintf(file, "\n");
		fputs(x->base.Name, file);
		fprintf(file, "\n");
		fputs(x->base.Otchestvo, file);
		fprintf(file, "\n");
		fputs(x->base.Disciplina, file);
		fprintf(file, "\n");
		fputs(x->base.DataSdachi, file);
		fprintf(file, "\n");
		fputs(x->base.ExamOrZachet, file);
		fprintf(file, "\n");
		fputs(x->base.Mark, file);
		fprintf(file, "\n");
		fputs(x->base.ZachetIliNet, file);
		if (x->next != NULL)
			fprintf(file, "\n");
		x = x->next;
	}
	fclose(file);
}