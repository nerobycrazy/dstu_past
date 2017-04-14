// academic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>

struct AcademRecords{
	char snameandinit[30];	// Фамилия и инициалы студента
	char number[10];		// Номер зачетки
	char admission[13];		// Допуск к сессии
	char examark[4];		// Оценка
	char date[15];			// Дата сдачи
}; 

struct node{
	AcademRecords rec;
	node *next;
};

struct list{
	int count;
	node *top;
};

void Init(list**);
void Print(node*);
void Edit(node**);
void Find(node*);
void ProgressTable(node*);
void Add(list**, AcademRecords*);
void AddAndPutFile(list**);
void Delete(list**);
void Read(list**);
void SaveToFile(node**);
void DeleteEndStr(char*);

int _tmain(int argc, _TCHAR* argv[])
{
	system("color F0"); //белый фон и черные буквы в консоли
	list *pList;	

	char c; 

	Init(&pList);
	Read(&pList);

	while (1){
		system("CLS");
		Print(pList->top);
		printf("\nMain menu. Plese select option.\n");
		printf("\n1. Add new Record\n");
		printf("2. Edit Record\n");
		printf("3. Delete Record\n");
		printf("4. Search for students not admitted to the exam\n");
		printf("5. Table of student's progress\n");
		c = _getch();
		switch (c){
		case '1':{
					 system("CLS");
					 printf("-Add new record-\n");
					 AddAndPutFile(&pList);
					 break;
		}
		case '2':{
					 system("CLS");
					 printf("-Edit record-\n");
					 Edit(&pList->top);
					 SaveToFile(&pList->top);
					 break;
		}
		case '3':{
					 system("CLS");
					 printf("-Delete record-\n");
					 Print(pList->top);
					 Delete(&pList);
					 SaveToFile(&pList->top);
					 break;
		}
		case '4':{
					 system("CLS");
					 printf("-Search not admitted students-\n");
					 Find(pList->top);
					 break;
		}
		case '5':{
					 system("CLS");
					 printf("-Progress table--\n");
					 ProgressTable(pList->top);
					 break;
		}
		case 27:
			exit(1);
		default:
			printf("Некорретный ввод");
				break;
		}
	}
	return 0;
}

void DeleteEndStr(char *c){
	char* pos = strrchr(c, '\n');
	if (pos) c[pos - c] = 0;
}

void Init(list **li){
	*li = new list;
	(*li)->top = new node;
	(*li)->top->next = NULL;
}

void Print(node *pNode){
		node *t = pNode->next;
		printf(" Surname and Init       Num.    Adm.  Mark\tDate\n");

		while (t){
			printf("%-20s %-10s %-6s %-5s %-13s \n",t->rec.snameandinit, t->rec.number, t->rec.admission, t->rec.examark, t->rec.date);
			t = t->next;
		}
}

void Edit(node **pNode){
	node *t = *(pNode);
	
	char c;
	char mark[8];
	Print(*pNode);
	printf("\nInput please a number of mark book: ");
	gets_s(mark);

	while (strcmp(t->rec.number, mark) != 0)
		t = t->next;

	printf("%s %s %s %s %s \n", t->rec.snameandinit, t->rec.number, t->rec.admission, t->rec.examark, t->rec.date);
	printf("\nSelect a data to edit:\n");
	printf("1. Surname and initials student\n");
	printf("2. Number of mark book\n");
	printf("3. Admission to surrender\n");
	printf("4. Examination mark\n");
	printf("5. Completion Date \n");
	switch (c = _getch()){
	case '1':{
				 printf("Surname and initials student: ");
				 gets_s(t->rec.snameandinit);
				 break;
	}
	case '2':{
				 printf("Number of mark book: ");
				 gets_s(t->rec.number);
				 break;
	}
	case '3':{
				 printf("Admission to surrender: "); 
				 gets_s(t->rec.admission);
				 break;
	}
	case '4':{
				 printf("Examination mark: ");
				 gets_s(t->rec.examark);
				 break;
	}
	case '5':{
				 printf("Completion date: ");
				 gets_s(t->rec.date);
				 break;
	}
	case 27:	 exit(1);

	default:{
				printf("Incorrect input");
				break;
	}
	}
}

void Find(node *pNode){
	node *t = pNode;
	while (t){
		if (strcmp(t->rec.admission, "No") == 0){
			printf("%s %s %s %s %s \n", t->rec.snameandinit, t->rec.number, t->rec.admission, t->rec.examark, t->rec.date);
		}
		t = t->next;
	}
	printf("\nNothing else\n");
	_getch();
}

void ProgressTable(node *pNode){
	node *t = pNode->next;
	FILE *table;
	fopen_s(&table,"ProgressTable.txt", "w");

	char mas[6][2] = { "0", "1", "2", "3", "4", "5" };
	char m[2];
	int mc[6] = { 0 };
	int i;

	while (t){
		m[0] = t->rec.examark[0];
		m[1] = '\0';
		for (i = 0; i <= 5; i++){
			if (strcmp(m, mas[i]) == 0)
				mc[i]++;
		}
		t = t->next;
	}
	system("CLS");
	printf("'0'	'1'	'2'	'3'	'4'	'5'\n");
	fprintf(table,"'0'	'1'	'2'	'3'	'4'	'5'\n");
	for (i = 0; i <= 5; i++){
		printf(" %d	", mc[i]);
		fprintf(table, " %d	", mc[i]);
	}
	printf("\n");
	fclose(table);
	_getch();
}

void Add(list **pList, AcademRecords add){
	node *ins = new node;
	
	strcpy_s(ins->rec.snameandinit, add.snameandinit);
	strcpy_s(ins->rec.number, add.number);
	strcpy_s(ins->rec.admission, add.admission);
	strcpy_s(ins->rec.examark, add.examark);
	strcpy_s(ins->rec.date, add.date);

	(*pList)->count++;
	
	if ((*pList)->top == NULL){
		ins->next = NULL;
		(*pList)->top = ins;
		return;
	}
	
	node *temp = (*pList)->top;
	while (temp->next){
		temp = temp->next;
	}
	temp->next = ins;
	ins->next = NULL;
}

void AddAndPutFile(list **pList){
	FILE *file;
	AcademRecords inse;
	fopen_s(&file, "academic.txt", "a");

	printf("Surname and initials student: "); 
	gets_s(inse.snameandinit);  
	fputs("\n", file); 
	fputs(inse.snameandinit, file); 
	fputs("\n", file);

	printf("Number of mark book: ");
	gets_s(inse.number);
	fputs(inse.number, file);
	fputs("\n", file);
	
	printf("Admission to surrender: ");
	gets_s(inse.admission);
	fputs(inse.admission, file);
	fputs("\n", file);

	printf("Examination mark: ");
	gets_s(inse.examark);
	fputs(inse.examark, file);
	fputs("\n", file);

	printf("Completion Date: ");
	gets_s(inse.date); 
	fputs(inse.date, file);

	Add(pList, inse);
	fclose(file);
}

void Delete(list **pList){
	(*pList)->count--;

	char k[8];
	printf("\nInput number of mark book: ");
	gets_s(k);

	node *t = (*pList)->top;
	if (strcmp(t->rec.number,k)==0){
		(*pList)->top = t->next;
		delete t;
		return;
	}

	node *t1 = t->next;
	while (t1){
		if (strcmp(t1->rec.number, k) == 0){
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
	AcademRecords ss;
	fopen_s(&file, "academic.txt", "r+");
	
	while (!feof(file)){
		fgets(ss.snameandinit, 30, file); 
		DeleteEndStr(ss.snameandinit);
		fgets(ss.number, 10, file); 
		DeleteEndStr(ss.number);
		fgets(ss.admission, 13, file); 
		DeleteEndStr(ss.admission);
		fgets(ss.examark, 4, file);
		DeleteEndStr(ss.examark);
		fgets(ss.date, 15, file);
		DeleteEndStr(ss.date);

		Add(pList, ss);
	}

	fclose(file);
}

void SaveToFile(node **pNode){
	FILE *file;
	fopen_s(&file, "academic.txt", "w");

	node *tt = (*pNode)->next;
	while (tt){
		fputs(tt->rec.snameandinit, file); fprintf(file, "\n");
		fputs(tt->rec.number, file); fprintf(file, "\n");
		fputs(tt->rec.admission, file); fprintf(file, "\n");
		fputs(tt->rec.examark, file); fprintf(file, "\n");
		fputs(tt->rec.date, file);
		if (tt->next != NULL)
			fprintf(file, "\n");
		tt = tt->next;
	}
	fclose(file);
}

