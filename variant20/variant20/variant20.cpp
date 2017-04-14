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

struct Tovar{
	char key[8];		// Поле Ключ
	char product[30];	// Наименование изделия
	char name[30];		// Конкретное название продукта
	char dateManif[20]; // Дата изготовления 
	char slife[20];		//Срок годности
	char firm[30];		// Фирма изготовитель
	char country[30];	// Страна изготовления
	char DoesDoc[30];	// Соответствует ли маркировка документации
};

typedef struct node{
	Tovar data;
	struct node *next;
} NODE,*pNODE;

struct LIST{
	int len;
	pNODE top;
};

void Initialize(LIST**);
void Print(pNODE);
void Edit(pNODE*);
void AddToList(LIST **pList, Tovar*);
void AddToFile(LIST**);
void DeleteElement(LIST**);
void Find(pNODE);
void TableTovar(pNODE);
void ReadFromFile(LIST**);
void SaveToFile(pNODE*);
void DelEndOfStr(char*);

int _tmain(int argc, _TCHAR* argv[])
{
	system("color F0");
	system("mode con cols=110 lines=25");
	LIST *pLIST;

	Initialize(&pLIST);
	ReadFromFile(&pLIST);

	char key;
	while (1){
		system("CLS");
		printf("-----------------Foodstuffs--------------\n");
		Print(pLIST->top);
		printf("\n>>>>>>Please select one of the items>>>>>>>\n");
		printf("1. Add new record\n");
		printf("2. Edit record\n");
		printf("3. Delete record\n");
		printf("4. Search expired goods\n");
		printf("5. Table of products by name manufacturer\n");
		printf("Esc. Quit the programm\n");
		printf("-------------------------------\n>>>");
		key = _getch();
		switch (key){
		case '1':{
				system("CLS");
				printf("<<<<  Add a new entry Menu  >>>>\n");
				AddToFile(&pLIST);
				break;
		}
		case '2':{
				system("CLS");
				printf("<<<< Menu editing records  >>>>\n");
				Edit(&pLIST->top);
				SaveToFile(&pLIST->top);
				break;
		}
		case '3':{
				system("CLS");
				printf("<<<<  Menu delete records by key  >>>>\n");
				DeleteElement(&pLIST);
				SaveToFile(&pLIST->top);
				break;
		}
		case '4':{
				system("CLS");
				printf("<<<< Menu Search expired goods >>>>\n");
				Find(pLIST->top);
				break;
		}
		case '5':{
				system("CLS");
				printf("<<<< Table of products by name manufacturer >>>>\n");
				TableTovar(pLIST->top);
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

void DelEndOfStr(char *c){
	char* pos = strrchr(c, '\n');
	if (pos) c[pos - c] = 0;
}

void Initialize(LIST **pList){
	*pList = new LIST;
	(*pList)->top = new NODE;
	(*pList)->top->next = NULL;
}

void Print(pNODE newN){
	pNODE n = newN->next;
	while (n){
		printf("%-7s %-20s %-15s %-12s %-12s %-15s %-15s %-3s \n", n->data.key, n->data.product, n->data.name, n->data.dateManif, n->data.slife, n->data.firm, n->data.country, n->data.DoesDoc);
		n = n->next;
	}
}

void Edit(pNODE *newN){
	pNODE n = *newN;
	char c;
	char key[7];

	Print(*newN);

	printf("----------------------------------\n");
	printf("Please Enter a key>>> ");
	gets_s(key);

	while (strcmp(n->data.key, key) != 0)
		n = n->next;

	printf("%s %s %s %s %s %s %s %s \n", n->data.key, n->data.product, n->data.name, n->data.dateManif, n->data.slife, n->data.firm, n->data.country, n->data.DoesDoc);
	printf("\nSelect the edit box:\n");
	printf("1. Product name\n");
	printf("2. Specific name of the product\n");
	printf("3. Date of manufacture\n");
	printf("4. Shelf life\n");
	printf("5. Manufacturer\n");
	printf("6. Country of manufacture\n");
	printf("7. Does labeling doc. product\n");
	switch (c = _getch()){
	case '1':{
				 printf("Enter Product name : ");
				 gets_s(n->data.product);
				 break;
	}
	case '2':{
				 printf("Enter Specific name of the product : ");
				 gets_s(n->data.name);
				 break;
	}
	case '3':{
				 printf("Enter the Date of manufacture : ");
				 gets_s(n->data.dateManif);
				 break;
	}
	case '4':{
				 printf("Enter Shelf life: ");
				 gets_s(n->data.slife);
				 break;
	}
	case '5':{
				 printf("Enter the Manufacturer: ");
				 gets_s(n->data.firm);
				 break;
	}
	case '6':{
				 printf("Enter Country of manufacture: ");
				 gets_s(n->data.country);
				 break;
	}
	case '7':{
				 printf("Does labeling documentation product: ");
				 gets_s(n->data.DoesDoc);
				 break;
	}
	case 27:exit(1);

	default:{
				printf("Invalid Key");
				break;
	}
	}
}

void Find(pNODE newN){
	pNODE t = newN;
	// Получение сегодняшней даты
	time_t t2;
	tm *tk;
	tk = new tm;
	time(&t2);
	localtime_s(tk, &t2);
	printf("Now date: %d.%d.%d\n\n", tk->tm_mday, tk->tm_mon + 1, tk->tm_year + 1900);
	//
	char day[3];
	char mon[3];
	char year[5];

	int iday = 0, imon = 0, iyear = 0;
	t = t->next;
	while (t){
		
		day[0] = t->data.slife[0];
		day[1] = t->data.slife[1];
		day[2] = '\0';

		iday = atoi(day);

		mon[0] = t->data.slife[3];
		mon[1] = t->data.slife[4];
		mon[2] = '\0';
		
		imon = atoi(mon);

		year[0] = t->data.slife[6];
		year[1] = t->data.slife[7];
		year[2] = t->data.slife[8];
		year[3] = t->data.slife[9];
		year[4] = '\0';

		iyear = atoi(year);

		if (iyear<(tk->tm_year + 1900) || (iyear == (tk->tm_year + 1900) && (imon<(tk->tm_mon + 1))) || (iyear == (tk->tm_year + 1900) && (imon == (tk->tm_mon + 1)) && (iday<tk->tm_mday))){
			printf("%-7s %-20s %-15s %-12s %-12s %-15s %-15s %-3s \n", t->data.key, t->data.product, t->data.name, t->data.dateManif, t->data.slife, t->data.firm, t->data.country, t->data.DoesDoc);
		}
		t = t->next;
	}
	printf("\n>>>");
	
	_getch();
}

void TableTovar(pNODE newN){
	pNODE t = newN->next;

	char firm[50][20];
	
	int count[50], i = 0, j;
	bool flag, ex = TRUE;

	for (int k = 0; k<50; k++)
		count[k] = 0;

	strcpy_s(firm[0], t->data.firm);

	while (i<50 && t){
		if (t->next == NULL){
			ex = FALSE;
			break;
		}
		t = t->next;
		flag = TRUE;
		for (j = 0; j <= i; j++){
			if (strcmp(firm[j], t->data.firm) == 0 && t != NULL){
				flag = FALSE;
				break;
			}
		}

		if (flag && t != NULL){
			i++;
			strcpy_s(firm[i], t->data.firm);
		}
	}

	pNODE t1 = newN->next;
	pNODE t2;
	for (int q = 0; q <= i; q++){
		t2 = t1;
		while (t2){
			if (strcmp(firm[q], t2->data.firm) == 0){
				count[q]++;
			}
			t2 = t2->next;
		}
	}
	printf(" Manufacturer    Count of product\n");
	for (int p = 0; p <= i; p++){
		printf(" %-20s%-10d\n", firm[p], count[p]);
	}

	FILE *ff;
	if (fopen_s(&ff, "cntitem.txt", "w")){
		printf("Read error\n");
		exit(1);
	}

	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-13s", firm[p]);
	}
	fprintf(ff, "\n");
	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-13d", count[p]);
	}

	fclose(ff);
	printf("\n>>>");
	_getch();
}

void AddToList(LIST **pList, Tovar temp){
	pNODE n = new NODE;

	strcpy_s(n->data.key, temp.key);
	strcpy_s(n->data.product, temp.product);
	strcpy_s(n->data.name, temp.name);
	strcpy_s(n->data.dateManif, temp.dateManif);
	strcpy_s(n->data.slife, temp.slife);
	strcpy_s(n->data.firm, temp.firm);
	strcpy_s(n->data.country, temp.country);
	strcpy_s(n->data.DoesDoc, temp.DoesDoc);

	(*pList)->len++;

	if ((*pList)->top == NULL){
		n->next = NULL;
		(*pList)->top = n;
		return;
	}

	pNODE temp1 = (*pList)->top;
	while (temp1->next){
		temp1 = temp1->next;
	}
	temp1->next = n;
	n->next = NULL;
}

void AddToFile(LIST **pList){
	FILE *file;
	Tovar temp1;

	fopen_s(&file, "dbItems.txt", "a");

	printf("Enter key: ");
	gets_s(temp1.key);
	fputs("\n", file);
	fputs(temp1.key, file);
	fputs("\n", file);

	printf("Product name: ");
	gets_s(temp1.product);
	fputs(temp1.product, file);
	fputs("\n", file);

	printf("Specific name of the product: ");
	gets_s(temp1.name);
	fputs(temp1.name, file);
	fputs("\n", file);

	printf("The date of manufacture : ");
	gets_s(temp1.dateManif);
	fputs(temp1.dateManif, file);
	fputs("\n", file);

	printf("Shelf life: ");
	gets_s(temp1.slife);
	fputs(temp1.slife, file);
	fputs("\n", file);

	printf("The manufacturer: ");
	gets_s(temp1.firm);
	fputs(temp1.firm, file);
	fputs("\n", file);

	printf("Country of manufacture: ");
	gets_s(temp1.country);
	fputs(temp1.country, file);
	fputs("\n", file);

	printf("Does labeling documentation product: ");
	gets_s(temp1.DoesDoc);
	fputs(temp1.DoesDoc, file);

	AddToList(pList, temp1);
	fclose(file);
}

void DeleteElement(LIST **pList){
	(*pList)->len--;

	char key[7];
	Print((*pList)->top);
	
	printf("\nEnter key: ");
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
	Tovar temp1;
	fopen_s(&file, "dbItems.txt", "r+");

	while (!feof(file)){
		fgets(temp1.key, 8, file); 
		DelEndOfStr(temp1.key);

		fgets(temp1.product, 30, file);
		DelEndOfStr(temp1.product);

		fgets(temp1.name, 30, file); 
		DelEndOfStr(temp1.name);
		
		fgets(temp1.dateManif, 20, file); 
		DelEndOfStr(temp1.dateManif);
		
		fgets(temp1.slife, 20, file); 
		DelEndOfStr(temp1.slife);
		
		fgets(temp1.firm, 30, file); 
		DelEndOfStr(temp1.firm);

		fgets(temp1.country, 30, file);
		DelEndOfStr(temp1.country);

		fgets(temp1.DoesDoc, 5, file);
		DelEndOfStr(temp1.DoesDoc);

		AddToList(pList, temp1);
	}

	fclose(file);
}

void SaveToFile(pNODE *newN){
	FILE *file;

	fopen_s(&file, "dbItems.txt", "w+");

	pNODE li = (*newN)->next;
	while (li){
		fputs(li->data.key, file);
		fprintf(file, "\n");
		fputs(li->data.product, file);
		fprintf(file, "\n");
		fputs(li->data.name, file);
		fprintf(file, "\n");
		fputs(li->data.dateManif, file);
		fprintf(file, "\n");
		fputs(li->data.slife, file);
		fprintf(file, "\n");
		fputs(li->data.firm, file);
		fprintf(file, "\n");
		fputs(li->data.country, file);
		fprintf(file, "\n");
		fputs(li->data.DoesDoc, file);
		if (li->next != NULL)
			fprintf(file, "\n");
		li = li->next;
	}
	fclose(file);
}


