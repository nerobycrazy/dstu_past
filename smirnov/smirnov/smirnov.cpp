// variant20.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>

using namespace std;

struct Products{
	char key[8];			// Поле Ключ
	char Item[20];			// Выпускаемое изделие
	char ModelNumber[20];	// Номер модели
	char DateDevelop[20];	// Дата выпуска
	char SellingPrice[15];	// Отпускная цена
	char IsExport[15];		// Поставляется ли на экспорт
};

typedef struct node{
	Products data;
	struct node *next;
} NODE, *pNODE;

struct LIST{
	int len;
	pNODE top;
};

void Initialize(LIST**);
void Print(pNODE);
void Edit(pNODE*);
void AddToList(LIST **pList, Products*);
void AddToFile(LIST**);
void DeleteElement(LIST**);
void Find(pNODE);
void CreateCountTable(pNODE);
void ReadFromFile(LIST**);
void SaveToFile(pNODE*);
void DelEndOfStr(char*);

int _tmain(int argc, _TCHAR* argv[])
{
	system("color F0");

	LIST *pLIST;

	Initialize(&pLIST);
	ReadFromFile(&pLIST);

	char key;
	while (1){
		system("CLS");
		printf("-----------------Zavod--------------\n");
		Print(pLIST->top);
		printf("\n----Vyberite odin iz punktov menju------\n");
		printf("1. Dobavit' novuju zapis'\n");
		printf("2. Izmenit' zapis'\n");
		printf("3. Udalit' zapis'\n");
		printf("4. Poisk detaley na export\n");
		printf("5. Vyvod tablicy izdelij \n");
		printf("Esc. EXIT\n");
		printf("-------------------------------\n-->");
		key = _getch();
		switch (key){
		case '1':{
					 system("CLS");
					 AddToFile(&pLIST);
					 break;
		}
		case '2':{
					 system("CLS");
					 Edit(&pLIST->top);
					 SaveToFile(&pLIST->top);
					 break;
		}
		case '3':{
					 system("CLS");
					 DeleteElement(&pLIST);
					 SaveToFile(&pLIST->top);
					 break;
		}
		case '4':{
					 system("CLS");
					 Find(pLIST->top);
					 break;
		}
		case '5':{
					 system("CLS");
					 CreateCountTable(pLIST->top);
					 break;
		}
		case 27: exit(1);
		default:
			printf("INVALID");
			break;
		}
	}
	return 0;
}

void DelEndOfStr(char *c){
	char* pos = strrchr(c, '\n');
	if (pos) c[pos - c] = 0;
}

void Initialize(LIST **pList){
	*pList = new LIST;
	(*pList)->top = new NODE;
	(*pList)->top->next = NULL;
}

void Print(pNODE nodik){
	pNODE n = nodik->next;
	while (n){
		printf("%-7s %-15s %-10s %-12s %-8s %-7s \n", n->data.key, n->data.Item, n->data.ModelNumber, n->data.DateDevelop, n->data.SellingPrice, n->data.IsExport);
		n = n->next;
	}
}

void Edit(pNODE *nodik){
	pNODE n = *nodik;

	char c;
	char key[8];

	Print(*nodik);

	printf("----------------------------------\n");
	printf("Vvedite kljuch dlja izmenenija - ");
	gets_s(key);

	while (strcmp(n->data.key, key) != 0)
		n = n->next;

	printf("%s %s %s %s %s %s \n", n->data.key, n->data.Item, n->data.ModelNumber, n->data.DateDevelop, n->data.SellingPrice, n->data.IsExport);
	printf("\nVyberite chto udaljat':\n");
	printf("1. Vypuskaemoe izdelie\n");
	printf("2. Nomer modeli\n");
	printf("3. Data razrabotki\n");
	printf("4. Otpusknaja cena\n");
	printf("5. Postavljaetsja li izdelie na jeksport\n");
	switch (c = _getch()){
	case '1':{
				 printf("Enter Vypuskaemoe izdelie: ");
				 gets_s(n->data.Item);
				 break;
	}
	case '2':{
				 printf("Enter Nomer modeli: ");
				 gets_s(n->data.ModelNumber);
				 break;
	}
	case '3':{
				 printf("Enter Data razrabotki : ");
				 gets_s(n->data.DateDevelop);
				 break;
	}
	case '4':{
				 printf("Enter Otpusknaja cena: ");
				 gets_s(n->data.SellingPrice);
				 break;
	}
	case '5':{
				 printf("Enter Export or Not ");
				 gets_s(n->data.IsExport);
				 break;
	}
	case 27:exit(1);

	default:{
				printf("INVALID");
				break;
	}
	}
}

void Find(pNODE nodik){
	pNODE bibi = nodik;

	while (bibi){
		if (strcmp(bibi->data.IsExport, "Export") == 0){
			printf("%-7s %-15s %-10s %-12s %-8s %-7s \n", bibi->data.key, bibi->data.Item, bibi->data.ModelNumber, bibi->data.DateDevelop, bibi->data.SellingPrice, bibi->data.IsExport);
		}
		bibi = bibi->next;
	}
	printf("\n>>>");

	_getch();
}

void CreateCountTable(pNODE nodik){
	pNODE bibi = nodik->next;
	FILE *fail;
	fopen_s(&fail, "dbCountMonth.txt", "w");

	char Month[13][3] = { "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
	char m[3];
	int mc[13] = { 0 };
	int i;

	while (bibi){
		m[0] = bibi->data.DateDevelop[3];
		m[1] = bibi->data.DateDevelop[4];
		m[2] = '\0';
		for (i = 1; i <= 12; i++){
			if (strcmp(m, Month[i]) == 0)
				mc[i]++;
		}
		bibi = bibi->next;
	}
	system("CLS");
	printf(" Jan.  Feb.  Mrch  Apr.  May   June  July  Aug.  Sep.  Oct.  Nov.  Dec.\n");
	fprintf(fail, " Янв.  Фев.  Март  Апр.  Май   Июнь  Июль  Авг.  Сен.  Окт.  Ноя.  Дек.\n");
	for (i = 1; i <= 12; i++){
		printf("| %d | ", mc[i]);
		fprintf(fail, "  %d   ", mc[i]);
	}
	printf("\n");
	fclose(fail);
	_getch();
}

void AddToList(LIST **pList, Products temp){
	pNODE nov = new NODE;

	strcpy_s(nov->data.key, temp.key);
	strcpy_s(nov->data.Item, temp.Item);
	strcpy_s(nov->data.ModelNumber, temp.ModelNumber);
	strcpy_s(nov->data.DateDevelop, temp.DateDevelop);
	strcpy_s(nov->data.SellingPrice, temp.SellingPrice);
	strcpy_s(nov->data.IsExport, temp.IsExport);

	(*pList)->len++;

	if ((*pList)->top == NULL){
		nov->next = NULL;
		(*pList)->top = nov;
		return;
	}

	pNODE temp1 = (*pList)->top;
	while (temp1->next){
		temp1 = temp1->next;
	}
	temp1->next = nov;
	nov->next = NULL;
}

void AddToFile(LIST **pList){
	FILE *file;
	Products temp1;

	fopen_s(&file, "ZavodDBase.txt", "a");

	printf("Enter key (000**): ");
	gets_s(temp1.key);
	fputs("\n", file);
	fputs(temp1.key, file);
	fputs("\n", file);

	printf("Izdelie name: ");
	gets_s(temp1.Item);
	fputs(temp1.Item, file);
	fputs("\n", file);

	printf("Nomer modeli: ");
	gets_s(temp1.ModelNumber);
	fputs(temp1.ModelNumber, file);
	fputs("\n", file);

	printf("Data razrabotki : ");
	gets_s(temp1.DateDevelop);
	fputs(temp1.DateDevelop, file);
	fputs("\n", file);

	printf("Otpusknaja cena: ");
	gets_s(temp1.SellingPrice);
	fputs(temp1.SellingPrice, file);
	fputs("\n", file);

	printf("Export or Not: ");
	gets_s(temp1.IsExport);
	fputs(temp1.IsExport, file);
	
	AddToList(pList, temp1);
	fclose(file);
}

void DeleteElement(LIST **pList){
	(*pList)->len--;

	char key[7];
	Print((*pList)->top);

	printf("\nVvedite key: ");
	gets_s(key);

	pNODE t = (*pList)->top;
	if (strcmp(t->data.key, key) == 0){
		(*pList)->top = t->next;
		delete t;
		return;
	}

	pNODE t1 = t->next;
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
	Products temp1;
	fopen_s(&file, "ZavodDBase.txt", "r+");

	while (!feof(file)){
		fgets(temp1.key, 8, file);
		DelEndOfStr(temp1.key);

		fgets(temp1.Item, 20, file);
		DelEndOfStr(temp1.Item);

		fgets(temp1.ModelNumber, 20, file);
		DelEndOfStr(temp1.ModelNumber);

		fgets(temp1.DateDevelop, 20, file);
		DelEndOfStr(temp1.DateDevelop);

		fgets(temp1.SellingPrice, 15, file);
		DelEndOfStr(temp1.SellingPrice);

		fgets(temp1.IsExport, 15, file);
		DelEndOfStr(temp1.IsExport);

		AddToList(pList, temp1);
	}

	fclose(file);
}

void SaveToFile(pNODE *nodik){
	FILE *file;

	fopen_s(&file, "ZavodDBase.txt", "w+");

	pNODE li = (*nodik)->next;
	while (li){
		fputs(li->data.key, file);
		fprintf(file, "\n");
		fputs(li->data.Item, file);
		fprintf(file, "\n");
		fputs(li->data.ModelNumber, file);
		fprintf(file, "\n");
		fputs(li->data.DateDevelop, file);
		fprintf(file, "\n");
		fputs(li->data.SellingPrice, file);
		fprintf(file, "\n");
		fputs(li->data.IsExport, file);
		if (li->next != NULL)
			fprintf(file, "\n");
		li = li->next;
	}
	fclose(file);
}


