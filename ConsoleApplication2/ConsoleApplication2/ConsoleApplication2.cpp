// ���������� �. ���21 ������� 12
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

struct PCaudit{
	char order[6]; //���������� �����
	char number[6]; // ����� ���������
	char surname[30]; // ������� ��������������
	char name[30]; // ��� ��������������
	char lastname[30]; //�������� ��������������
	char typePC[20]; //��� ����������� (MidiTower,FullTower,SlimTower) 
	char date[20]; // ���� ���������
	char invertNum[20]; // ����������� �����
	char linkPC[20]; // ���������� ��� ������� PC
};

struct NODE{
	PCaudit au; 
	NODE *next;
};

struct LIST{
	int len; //����� ������
	NODE *top; //��������� �� ������� ������
};

void nonTab(char*);
void InitializeList(LIST**);
void Print(NODE*);
void Edit(NODE**);
void Find(NODE*);
void CountPC(NODE*);
void Insert(LIST**, char*, char*, char*, char*, char*, char*, char*, char*, char*);
void InsertFile(LIST**);
void DeleteElement(LIST**);
void ReadFromFile(LIST**);
void SaveToFile(NODE**);

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LIST *plist;
	char c;

	InitializeList(&plist);
	ReadFromFile(&plist);

	while (1){
		system("CLS");
		printf("==========���������� ������ - ���21 - ������� 12 - ����. ���������=============\n\n");
		Print(plist->top);
		printf("1. �������� ����� ������\n");
		printf("2. ������������� ������\n");
		printf("3. ������� ������\n");
		printf("4. ����� ��������� �� ������ ��������������\n");
		printf("5. �������� ������� ����� �� � ������ ���������\n");
		printf("Esc. ����� ����� �� ���������\n");
		printf("-------------------------------------------------------------------------\n");
		printf(">>>");

		c = _getch();

		switch (c){
		case '1':{
					 system("CLS");
					 printf("\t\t-----���������� ����� ������-----\n");
					 InsertFile(&plist);
					 break;
		}
		case '2':{
					 system("CLS");
					 printf("\t\t-----�������������� ������ ������-----\n");
					 Edit(&plist->top);
					 break;
		}
		case '3':{
					 system("CLS");
					 printf("\t\t-----�������� ������-----\n");
					 DeleteElement(&plist);
					 SaveToFile(&plist->top);
					 break;
		}
		case '4':{
					 system("CLS");
					 printf("\t\t-----����� ��������� �� ������� ��������������-----\n\n");
					 Find(plist->top);
					 break;
		}
		case '5':{
					 system("CLS");
					 printf("\t\t-----������� ����� �� �� ����������------\n");
					 CountPC(plist->top);
					 break;
		}
		case 27: exit(1);
		default:
			printf("����������� ����!!!");
			break;
		}
	}
	return 0;
}

void nonTab(char *c){
	char* pos = strrchr(c, '\n');
	if (pos) c[pos - c] = 0;
}

void InitializeList(LIST **nList){
	*nList = new LIST;
	(*nList)->top = new NODE;
	(*nList)->top->next = NULL;
}

void Print(NODE *nNode){
		NODE *t = nNode->next;
		printf("--------------------------------------------------------------------------\n");
		while (t){
			printf("%s. %s %s %s %s %s %s %s %s\n", t->au.order, t->au.number, t->au.surname, t->au.name, t->au.lastname, t->au.typePC, t->au.date, t->au.invertNum, t->au.linkPC);
			t = t->next;
		}
		printf("--------------------------------------------------------------------------\n");
}

void Edit(NODE **nNode){
	NODE *t = *nNode;

	char c;
	char order[4];

	printf("�������� ���������� ����� ��� ��������������:");
	gets_s(order);

	while (strcmp(t->au.order, order) != 0)
		t = t->next;

	printf("\n%s.%s %s %s %s %s %s %s %s\n", t->au.order, t->au.number, t->au.surname, t->au.name, t->au.lastname, t->au.typePC, t->au.date, t->au.invertNum, t->au.linkPC);
	printf("------------------------------------------------");
	printf("\n�������� ������ ��� ��������������:\n");
	printf("1. �������\n");
	printf("2. ���\n");
	printf("3. ��������\n");
	printf("4. ��� ����������\n");
	printf("5. ���� ��������� �����������\n");
	printf("6. ����������� �����\n");
	printf("7. ���������� ��� �������?\n");
	printf("8. ����� ���������\n");

	switch (c = _getch()){
	case '1':{
				 printf("������� ����� �������: ");
				 gets_s(t->au.surname);
				 break;
	}
	case '2':{
				 printf("������� ����� ���: ");
				 gets_s(t->au.name);
				 break;
	}
	case '3':{
				 printf("������� ����� ��������: ");
				 gets_s(t->au.lastname);
				 break;
	}
	case '4':{
				 printf("������� ��� ����������: ");
				 gets_s(t->au.typePC);
				 break;
	}
	case '5':{
				 printf("������� ���� ���������: ");
				 gets_s(t->au.date);
				 break;
	}
	case '6':{
				 printf("������� ����������� �����: ");
				 gets_s(t->au.invertNum);
				 break;
	}
	case '7':{
				 printf("������� ������� ����������� � ����(���. ��� �������): ");
				 gets_s(t->au.linkPC);
				 break;
	}
	case '8':{
				 printf("������� ����� ���������: ");
				 gets_s(t->au.number);
				 break;
	}
	case 27: exit(1);
	}
	SaveToFile(nNode);
}

void Find(NODE *nNode){
	NODE *t = nNode;

	char surname[20];

	printf("������� ������� ��������������: ");
	gets_s(surname);

	while (t){
		if (strcmp(t->au.surname, surname) == 0){
			printf("\n%s %s %s %s\n", t->au.number, t->au.surname, t->au.name, t->au.lastname);
		}
		t = t->next;
	}
	printf("\n\n-�� ������� ��� ������� � ����� ���������� ������ ���-\n");
	_getch();
}

void CountPC(NODE *nNode){
	NODE *t = nNode->next;
	char auditor[50][30];
	int count[50], i = 0, j;
	bool flag, ex = TRUE;

	for (int k = 0; k<50; k++)
		count[k] = 0;

	strcpy_s(auditor[0], t->au.number);

	while (i<50 && t){
		if (t->next == NULL){
			ex = FALSE;
			break;
		}
		t = t->next;
		flag = TRUE;
		for (j = 0; j <= i; j++){
			if (strcmp(auditor[j], t->au.number) == 0 && t != NULL){
				flag = FALSE;
				break;
			}
		}

		if (flag && t != NULL){
			i++;
			strcpy_s(auditor[i], t->au.number);
		}
	}

	NODE *t1 = nNode->next;
	NODE *t2;
	for (int q = 0; q <= i; q++){
		t2 = t1;
		while (t2){
			if (strcmp(auditor[q], t2->au.number) == 0)
				count[q]++;
			t2 = t2->next;
		}
	}
	printf("� �����.    ���-�� ��\n");
	for (int p = 0; p <= i; p++){
		printf("%5s\t\t%-5d\n", auditor[p], count[p]);
	}

	FILE *fail;
	if (fopen_s(&fail, "CountOfPC.txt", "w")){
		printf("������ ��� ��������\n");
		exit(1);
	}

	for (int p = 0; p <= i; p++){
		fprintf(fail, "%-5s", auditor[p]);
	}
	fprintf(fail, "\n");
	for (int p = 0; p <= i; p++){
		fprintf(fail, "%-5d", count[p]);
	}

	printf("\n������� ����� ������� ��� ������� >>\n");
	fclose(fail);
	_getch();
}

void Insert(LIST **nList, char order[], char number[], char surname[], char name[], char lastname[], char typePC[], char date[], char invertNum[], char linkPC[]){
	NODE *ins = new NODE;

	strcpy_s(ins->au.order, order);
	strcpy_s(ins->au.number, number);
	strcpy_s(ins->au.surname, surname);
	strcpy_s(ins->au.name, name);
	strcpy_s(ins->au.lastname, lastname);
	strcpy_s(ins->au.typePC, typePC);
	strcpy_s(ins->au.date, date);
	strcpy_s(ins->au.invertNum, invertNum);
	strcpy_s(ins->au.linkPC, linkPC);

	(*nList)->len++;

	if ((*nList)->top == NULL){
		ins->next = NULL;
		(*nList)->top = ins;
		return;
	}

	NODE *temp = (*nList)->top;
	while (temp->next){
		temp = temp->next;
	}
	temp->next = ins;
	ins->next = NULL;
}

void InsertFile(LIST **nList){
	FILE *file;

	fopen_s(&file, "Audit.txt", "a");

	char order[6]; //���������� �����
	char number[6]; // ����� ���������
	char surname[30]; // ������� ��������������
	char name[30]; // ��� ��������������
	char lastname[30]; //�������� ��������������
	char typePC[20]; //��� ����������� (MidiTower,FullTower,SlimTower) 
	char date[20]; // ���� ���������
	char invertNum[20]; // ����������� �����
	char linkPC[20]; // ���������� ��� ������� PC

	printf("������� �����: ");
	gets_s(order);
	fputs("\n", file);
	fputs(order, file);
	fputs("\n", file);

	printf("\n������� ����� ���������: ");
	gets_s(number);
	fputs(number, file);
	fputs("\n", file);

	printf("\n������� ��������������: ");
	gets_s(surname);
	fputs(surname, file);
	fputs("\n", file);

	printf("��� ��������������: ");
	gets_s(name);
	fputs(name, file);
	fputs("\n", file);

	printf("�������� ��������������: ");
	gets_s(lastname);
	fputs(lastname, file);
	fputs("\n", file);

	printf("��� �����������(Middle,Full,Slim): ");
	gets_s(typePC);
	fputs(typePC, file);
	fputs("\n", file);

	printf("���� ��������� (��.��.����): ");
	gets_s(date);
	fputs(date, file);
	fputs("\n", file);

	printf("����������� �����: ");
	gets_s(invertNum);
	fputs(invertNum, file);
	fputs("\n", file);

	printf("���������� ��� �������: ");
	gets_s(linkPC);
	fputs(linkPC, file);

	Insert(nList, order, number, surname, name, lastname, typePC, date, invertNum, linkPC);

	fclose(file);
}

void DeleteElement(LIST **nList){
	(*nList)->len--;

	char k[4];

	printf("������� ����� ��������� ������: ");
	gets_s(k);

	NODE *t = (*nList)->top;

	if (strcmp(t->au.order, k) == 0){
		(*nList)->top = t->next;
		delete t;
		return;
	}

	NODE *t1 = t->next;
	while (t1){
		if (strcmp(t1->au.order, k) == 0){
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}

void ReadFromFile(LIST **nList){
	FILE *file;

	char order[6]; //���������� �����
	char number[6]; // ����� ���������
	char surname[30]; // ������� ��������������
	char name[30]; // ��� ��������������
	char lastname[30]; //�������� ��������������
	char typePC[20]; //��� ����������� (MidiTower,FullTower,SlimTower) 
	char date[20]; // ���� ���������
	char invertNum[20]; // ����������� �����
	char linkPC[20]; // ���������� ��� ������� PC

	fopen_s(&file, "Audit.txt", "r+");

	while (!feof(file)){
		fgets(order, 6, file);
		nonTab(order);
		fgets(number, 6, file);
		nonTab(number);
		fgets(surname, 30, file);
		nonTab(surname);
		fgets(name, 30, file);
		nonTab(name);
		fgets(lastname, 30, file);
		nonTab(lastname);
		fgets(typePC, 20, file);
		nonTab(typePC);
		fgets(date, 20, file);
		nonTab(date);
		fgets(invertNum, 20, file);
		nonTab(invertNum);
		fgets(linkPC, 20, file);
		nonTab(linkPC);

		Insert(nList, order, number, surname, name, lastname, typePC, date, invertNum, linkPC);
	}

	fclose(file);
}

void SaveToFile(NODE **nList){
	FILE *stfile;

	NODE *tt = (*nList)->next;

	fopen_s(&stfile, "Audit.txt", "w+");

	while (tt){
		fputs(tt->au.order, stfile);
		fprintf(stfile, "\n");
		fputs(tt->au.number, stfile);
		fprintf(stfile, "\n");
		fputs(tt->au.surname, stfile);
		fprintf(stfile, "\n");
		fputs(tt->au.name, stfile);
		fprintf(stfile, "\n");
		fputs(tt->au.lastname, stfile);
		fprintf(stfile, "\n");
		fputs(tt->au.typePC, stfile);
		fprintf(stfile, "\n");
		fputs(tt->au.date, stfile);
		fprintf(stfile, "\n");
		fputs(tt->au.invertNum, stfile);
		fprintf(stfile, "\n");
		fputs(tt->au.linkPC, stfile);
		if (tt->next != NULL)
			fprintf(stfile, "\n");
		tt = tt->next;
	}
	fclose(stfile);
}

