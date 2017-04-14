// BirzhaTryda.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

typedef struct info{
	char name[20];
	char DateOfBirth[12];
	char DateOfReceipt[12];
	char sex[10];
	char valliere[10];
	int RecNumb;
}INFO, *pINFO;

typedef struct node{
	struct info *info;
	struct node *next;
}NODE, *pNODE;


typedef struct list{
	struct node *top;
	int len;
}LIST, *pLIST;


pLIST CreateList();
int IsEmpty(pLIST MyList);
pNODE GetPointer(pLIST MyList);
int Add(pLIST MyList, pNODE MyNode, int RecNumb, char name[], char DateOfBirth[], char DateOfReceipt[], char sex[], char valliere[]);
int LoadFromFile(pLIST MyList, pNODE MyNode);
void Show(pLIST MyList);
int DelNode(pLIST MyList, pNODE MyNode, int date);
void ClearList(pLIST MyList);
void DeleteList(pLIST MyList);
pNODE find(pLIST pL, int date);
int DelRecord(pLIST MyList, pNODE MyNode, int Rec, int col);
int NewRecord(pLIST MyList, int i);
int ChangeRecord(pLIST MyList, pNODE MyNode);
void SaveChanges(pNODE MyNode);
int SearchAnimal(pLIST MyList);
int YOBTable(pLIST MyList);
void Menu(pLIST MyList, int col);


int _tmain(int argc, _TCHAR* argv[])
{
	pLIST MyList;
	int i;
	MyList = CreateList();
	i = LoadFromFile(MyList, GetPointer(MyList));
	Menu(MyList, i);
	DeleteList(MyList);
	return 0;
}


pLIST CreateList()
{
	pLIST NewList;
	NewList = (pLIST)malloc(sizeof(LIST));
	if (!NewList) return NULL;
	NewList->top = NULL;
	NewList->len = 0;
	return NewList;
}


int IsEmpty(pLIST MyList)
{
	if (MyList->top) return 0;
	return 1;
}


pNODE GetPointer(pLIST MyList)
{
	pNODE p = MyList->top;
	if (IsEmpty(MyList)) return NULL;
	while (p->next){
		p = p->next;
	}
	return p;
}


void Menu(pLIST MyList, int col)
{
	char key[2];
	bool flag = true;
	int Rec;
	while (flag)
	{
		system("cls");
		Show(MyList);
		printf("\n1)Add record\n");
		printf("2)Change record\n");
		printf("3)Delte record\n");
		printf("4)Search Animal\n");
		printf("5)The table of the unemployed on year of birth\n");
		printf("6)Exit\n\n");
		printf("Enter>> ");
		gets_s(key);
		switch (atoi(key))
		{
		case 1:system("cls");
			col = NewRecord(MyList, col);
			break;
		case 2:system("cls");
			Show(MyList);
			ChangeRecord(MyList, MyList->top);
			break;
		case 3:system("cls");
			Show(MyList);
			printf("Enter a record number: ");
			scanf_s("%d", &Rec);
			system("cls");
			col = DelRecord(MyList, find(MyList, Rec), Rec, col);
			printf("Record is successfully removed\n");
			break;
		case 4:system("cls");
			SearchAnimal(MyList);
			break;
		case 5:system("cls");
			YOBTable(MyList);
			break;
		case 6:flag = false;
			break;
		default: printf("Incorrect item number\n");
		}
	}
}

int YOBTable(pLIST MyList)
{
	pNODE MyNode = MyList->top;
	pINFO pI = MyNode->info;
	FILE *out;
	char yob[50][6], date[12], key[4];
	int count[50], i, j, n = 0;
	bool flag = true;
	for (i = 0; i<49; i++)
		count[i] = 0;
	strcpy_s(date, pI->DateOfBirth);
	_strrev(date);
	strncpy_s(yob[n], date, 4);
	_strrev(yob[n]);
	n++;
	MyNode = MyNode->next;
	while (MyNode)
	{
		pI = MyNode->info;
		for (j = 0; j<n; j++)
		if (strstr(pI->DateOfBirth, yob[j]))
		{
			flag = false;
			break;
		}
		else
			flag = true;
		if (flag)
		{
			strcpy_s(date, pI->DateOfBirth);
			_strrev(date);
			strncpy_s(yob[n], date, 4);
			_strrev(yob[n]);
			n++;
		}
		MyNode = MyNode->next;
	}

	for (i = 0; i <= n; i++)
	{
		MyNode = MyList->top;
		while (MyNode)
		{
			pI = MyNode->info;
			if (strstr(pI->DateOfBirth, yob[i]))
				count[i]++;
			MyNode = MyNode->next;
		}
	}
	printf("Years\t");
	for (i = 0; i<n; i++)
		printf("%s\t", yob[i]);
	printf("\n");
	printf("Amount\t");
	for (i = 0; i<n; i++)
		printf(" %d\t", count[i]);

	printf("\n\n1)Save to file\n");
	printf("2)Back to main menu\n");
	gets_s(key);
	switch (atoi(key))
	{
	case 1:fopen_s(&out, "TableOnYearOfBirth.txt", "w");
		fprintf(out, "Years\t");
		for (i = 0; i<n; i++)
			fprintf(out, "%s\t", yob[i]);
		fprintf(out, "\n");
		fprintf(out, "Amount\t");
		for (i = 0; i<n; i++)
			fprintf(out, " %d\t", count[i]);
		fclose(out);
		break;
	case 2:return 0;
		break;
	default:printf("Incorrect item number\n");
	}
	return 1;
}

int SearchAnimal(pLIST MyList)
{
	pNODE MyNode = MyList->top;
	pINFO pI;
	char sp[40];
	printf("Enter the name animal: ");
	gets_s(sp);
	system("cls");
	printf("On request '%s' have been found\n\n\n", sp);
	printf_s("N     Name    DateOfBirth   DateOfReceipt      Sex     Valliere\n\n");
	while (MyNode)
	{
		pI = MyNode->info;
		if (!strcmp(sp, pI->name))
			printf("%-4d %-11s%-11s%-15s%-12s%-6s\n", pI->RecNumb, pI->name, pI->DateOfBirth, pI->DateOfReceipt, pI->sex, pI->valliere);
		MyNode = MyNode->next;
	}
	printf("\nPress button for return to main menu\n");
	_getch();
	return 1;
}

int NewRecord(pLIST MyList, int i)
{
	FILE *out;
	char name[20], DateOfBirth[12], DateOfReceipt[12], sex[3], valliere[6];
	system("cls");
	printf("Enter a name: ");
	gets_s(name);
	printf("Enter date of birth (DD.MM.YYYY): ");
	gets_s(DateOfBirth);
	printf("Enter date of receipt (DD.MM.YYYY): ");
	gets_s(DateOfReceipt);
	printf("Enter a sex(M/F): ");
	gets_s(sex);
	printf("Enter valliere: ");
	gets_s(valliere);
	Add(MyList, GetPointer(MyList), i, name, DateOfBirth, DateOfReceipt, sex, valliere);
	fopen_s(&out, "input.txt", "a");
	fprintf_s(out, "\n%s\n%s\n%s\n%s\n%s", name, DateOfBirth, DateOfReceipt, sex, valliere);
	fclose(out);
	i++;
	return i;
}

int ChangeRecord(pLIST MyList, pNODE MyNode)
{
	pNODE p = MyNode;
	pINFO pI = p->info;
	char key[2], Rec[4], exp[4];
	printf("Enter number of record which you want to change: ");
	gets_s(Rec);
	system("cls");
	while (MyNode && MyNode->info->RecNumb != atoi(Rec)) MyNode = MyNode->next;
	pI = MyNode->info;
	while (1)
	{
		printf("Name      DateOfBirth     DateOfReceipt     Sex   Valliere\n\n");
		printf("%-11s%-11s%-15s%-12s%-4s%\n\n", pI->name, pI->DateOfBirth, pI->DateOfReceipt, pI->sex, pI->valliere);
		printf("Select item which you want to change:\n");
		printf("1)Name\n");
		printf("2)DayOfBirth\n");
		printf("3)DayOfReceipt\n");
		printf("4)Sex\n");
		printf("5)Valliere\n");
		printf("6)Back to main menu\n");
		printf("\nEnter>> ");
		gets_s(key);
		switch (atoi(key))
		{
		case 1: printf("\nLast: %s\n", pI->name);
			printf("New: ");
			gets_s(pI->name);
			break;
		case 2: printf("\nLast: %s\n", pI->DateOfBirth);
			printf("New: ");
			gets_s(pI->DateOfBirth);
			break;
		case 3: printf("\nLast: %s\n", pI->DateOfReceipt);
			printf("New: ");
			gets_s(pI->DateOfReceipt);
			break;
		case 4: printf("\nLast: %s\n", pI->sex);
			printf("New: ");
			gets_s(pI->sex);
			break;
		case 5: printf("\nLast: %s\n", pI->valliere);
			printf("New: ");
			gets_s(pI->valliere);
			break;
		case 6: system("cls");
			return 1;
		default: printf("Incorrect item number!");
		}
		system("cls");
		printf("Data are successfully changed!!!\n\n");
		SaveChanges(p);
	}
	return 1;
}

int DelRecord(pLIST MyList, pNODE MyNode, int Rec, int col)
{
	pNODE p = MyList->top;
	pINFO pI = p->info;
	if (MyNode == NULL) return 0;
	if (pI->RecNumb == Rec)
	{
		p = MyNode->next;
		MyList->top = p;
	}
	else
	{
		pNODE p = MyNode->next;
		MyNode->next = MyNode->next->next;
		free(p);
	}
	MyList->len--;
	SaveChanges(p);
	col--;
	return col;
}

void SaveChanges(pNODE MyNode)
{
	FILE *out;
	pINFO pI;
	fopen_s(&out, "input.txt", "w");
	while (MyNode)
	{
		pI = MyNode->info;
		fprintf_s(out, "%s\n%s\n%s\n%s\n%s", pI->name, pI->DateOfBirth, pI->DateOfReceipt, pI->sex, pI->valliere);
		MyNode = MyNode->next;
	}
	fclose(out);
}

int Add(pLIST MyList, pNODE MyNode, int RecNumb, char name[], char DateOfBirth[], char DateOfReceipt[], char sex[], char valliere[])
{
	pNODE pnew, p = MyList->top;
	pINFO pI;
	pnew = (pNODE)malloc(sizeof(NODE));
	pI = (pINFO)malloc(sizeof(INFO));
	if (!pnew) return 0;
	MyList->len++;
	pI->RecNumb = RecNumb;
	strcpy_s(pI->name, name);
	strcpy_s(pI->DateOfBirth, DateOfBirth);
	strcpy_s(pI->DateOfReceipt, DateOfReceipt);
	strcpy_s(pI->sex, sex);
	strcpy_s(pI->valliere, valliere);

	pnew->info = pI;
	if (IsEmpty(MyList))
	{
		pnew->next = p;
		MyList->top = pnew;
		return 1;
	}
	pnew->next = MyNode->next;
	MyNode->next = pnew;
	return 1;
}

int LoadFromFile(pLIST MyList, pNODE MyNode)
{
	FILE *in;
	int i = 1;
	char name[20], DateOfBirth[12], DateOfReceipt[12], sex[3], valliere[6], *place;
	fopen_s(&in, "input.txt", "r");
	while (!feof(in))
	{
		fgets(name, 20, in);
		place = strchr(name, '\n');
		name[place - name] = name[place - name + 1];

		fgets(DateOfBirth, 12, in);
		place = strchr(DateOfBirth, '\n');
		DateOfBirth[place - DateOfBirth] = DateOfBirth[place - DateOfBirth + 1];

		fgets(DateOfReceipt, 12, in);
		place = strchr(DateOfReceipt, '\n');
		DateOfReceipt[place - DateOfReceipt] = DateOfReceipt[place - DateOfReceipt + 1];

		fgets(sex, 10, in);
		place = strchr(sex, '\n');
		sex[place - sex] = sex[place - sex + 1];

		fgets(valliere, 10, in);

		Add(MyList, GetPointer(MyList), i, name, DateOfBirth, DateOfReceipt, sex, valliere);
		i++;
	}
	fclose(in);
	return i;
}

void Show(pLIST MyList)
{
	pNODE p = MyList->top;
	pINFO pI;
	printf_s("N   Name       DateOfBirth    DateOfReceipt    Sex  Valliere\n");
	while (p){
		pI = p->info;
		printf_s("%-3d %-11s%-15s%-19s%-6s%s", pI->RecNumb, pI->name, pI->DateOfBirth, pI->DateOfReceipt, pI->sex, pI->valliere);
		p = p->next;
	}
	printf("\n");
}

pNODE find(pLIST pL, int date)
{
	pNODE p = pL->top;
	if (IsEmpty(pL)) return NULL;
	if (p->info->RecNumb == date) return p;
	while (p&&p->next->info->RecNumb != date) p = p->next;
	return p;
}

int DelNode(pLIST pL, pNODE pN)
{
	if (pN == NULL) return 0;
	else
	{
		pNODE p = pN->next;
		pN->next = pN->next->next;
		delete p;
	}
	pL->len--;
	return 1;
}

void ClearList(pLIST MyList)
{
	pNODE p = MyList->top;
	while (p->next != NULL)
	{
		DelNode(MyList, p);
		MyList->len--;
	}
	MyList->top = NULL;
}

void DeleteList(pLIST MyList)
{
	ClearList(MyList);
	free(MyList);
}