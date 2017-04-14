// Safonovskaya.cpp
//
#include "stdafx.h"
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
struct biblioteka{
	char id[8];			// Поле-ключ для работы с записями
	char famillie[30];	// Фамилия автора
	char name[30];		// Имя автора
	char dadname[30];   // Отчество автора
	char book[30];		// Название книги
	char language[15];	// Описываемый язык
	char year[10];		// Год издания
	char price[10];		// Цена
	char buydate[15];	// Дата приобретения
	char usefull[10];	// Использование книги в своей работе	 
};
typedef struct node{
	biblioteka data;
	struct node *next;
} NODE, *pNODE;
struct LIST{
	pNODE top;
	int len;
};
void Initialize(LIST**);
void Print(pNODE);
void Edit(pNODE*);
void AddToList(LIST **pList, biblioteka*);
void AddToFile(LIST**);
void Delete(LIST**);
void Find(pNODE);
void LanguageTable(pNODE);
void ReadFromFile(LIST**);
void SaveToFile(pNODE*);
void DelEndOfStr(char*);

int _tmain(int argc, _TCHAR* argv[])
{
	system("color F0");
	system("mode con cols=115 lines=25");
	LIST *pLIST;
	Initialize(&pLIST);
	ReadFromFile(&pLIST);
	char key;
	while (1){
		system("CLS");
		printf("-----------------Informatics Library--------------\n");
		Print(pLIST->top);
		printf("\n-------Please select one of the items------\n");
		printf("1. Add new record\n");
		printf("2. Edit record\n");
		printf("3. Delete record\n");
		printf("4. Find books by author\n");
		printf("5. Table number of books on programming language\n");
		printf("Esc. Quit the programm\n");
		printf("-------------------------------\n>>>");
		key = _getch();
		switch (key){
		case '1':{
					 system("CLS");
					 printf("+  Add a new record  +\n");
					 AddToFile(&pLIST);
					 break;
		}
		case '2':{
					 system("CLS");
					 printf("+  Edit record menu  +\n");
					 Edit(&pLIST->top);
					 SaveToFile(&pLIST->top);
					 break;
		}
		case '3':{
					 system("CLS");
					 printf("+  Delete record  +\n");
					 Delete(&pLIST);
					 SaveToFile(&pLIST->top);
					 break;
		}
		case '4':{
					 system("CLS");
					 printf("+  Search books by author  +\n");
					 Find(pLIST->top);
					 break;
		}
		case '5':{
					 system("CLS");
					 printf("+ Table Table Table  +\n");
					 LanguageTable(pLIST->top);
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
void Initialize(LIST **pList){
	*pList = new LIST;
	(*pList)->top = new NODE;
	(*pList)->top->next = NULL;
}
void DelEndOfStr(char *c){
	char* pos = strrchr(c, '\n');
	if (pos) c[pos - c] = 0;
}
void Print(pNODE tNode){
	pNODE temp = tNode->next;
	while (temp){
		printf("%-5s %-10s %-10s %-10s %-28s %-13s %-6s %-5s %-13s %s \n", temp->data.id, temp->data.famillie, temp->data.name, temp->data.dadname, temp->data.book, temp->data.language, temp->data.year, temp->data.price, temp->data.buydate, temp->data.usefull);
		temp = temp->next;
	}
}
void Edit(pNODE *tNode){
	pNODE node = *tNode;
	char c;
	char id[8];
	Print(*tNode);
	printf("----------------------------------\n");
	printf("Please Enter a ID>>> ");
	gets_s(id);
	while (strcmp(node->data.id, id) != 0)
		node = node->next;
	printf("%s %s %s %s %s %s %s %s %s %s \n", node->data.id, node->data.famillie, node->data.name, node->data.dadname, node->data.book, node->data.language, node->data.year, node->data.price, node->data.buydate, node->data.usefull);
	printf("\nSelect the edit box:\n");
	printf("1. Last name\n");
	printf("2. First name\n");
	printf("3. Middle name\n");
	printf("4. Book title\n");
	printf("5. Described language\n");
	printf("6. The year of publishing\n");
	printf("7. Price\n");
	printf("8. Date of purchase\n");
	printf("9. Did you use it in your work\n");
	switch (c = _getch()){
	case '1':{
			printf("Enter Last name : ");
			gets_s(node->data.famillie);
			break;
	}
	case '2':{
			printf("Enter First name : ");
			gets_s(node->data.name);
			break;
	}
	case '3':{
			printf("Enter Middle name : ");
			gets_s(node->data.dadname);
			break;
	}
	case '4':{
			printf("Enter Book title : ");
			gets_s(node->data.book);
			break;
	}
	case '5':{
			printf("Enter described language : ");
			gets_s(node->data.language);
			break;
	}
	case '6':{
			printf("Enter the year of publishing: ");
			gets_s(node->data.year);
			break;
	}
	case '7':{
			printf("Enter price: ");
			gets_s(node->data.price);
			break;
	}
	case '8':{
			printf("Enter date of purchase: ");
			gets_s(node->data.buydate);
			break;
	}
	case '9':{
			printf("Did you use it in your work?: ");
			gets_s(node->data.usefull);
			break;
	}
	case 27:exit(1);
	default:{
			printf("Invalid Key");
			break;
	}
	}
}
void AddToList(LIST **pList, biblioteka bib){
	pNODE n = new NODE;
	strcpy_s(n->data.id, bib.id);
	strcpy_s(n->data.famillie, bib.famillie);
	strcpy_s(n->data.name, bib.name);
	strcpy_s(n->data.dadname, bib.dadname);
	strcpy_s(n->data.book, bib.book);
	strcpy_s(n->data.language, bib.language);
	strcpy_s(n->data.year, bib.year);
	strcpy_s(n->data.price, bib.price);
	strcpy_s(n->data.buydate, bib.buydate);
	strcpy_s(n->data.usefull, bib.usefull);
	(*pList)->len++;
	if ((*pList)->top == NULL){
		n->next = NULL;
		(*pList)->top = n;
		return;
	}
	pNODE n1 = (*pList)->top;
	while (n1->next){
		n1 = n1->next;
	}
	n1->next = n;
	n->next = NULL;
}
void AddToFile(LIST **pList){
	FILE *file;
	biblioteka bib1;
	fopen_s(&file, "Biblioteka.txt", "a");

	printf("Enter ID: ");
	gets_s(bib1.id);
	fputs("\n", file);
	fputs(bib1.id, file);
	fputs("\n", file);

	printf("Last name author: ");
	gets_s(bib1.famillie);
	fputs(bib1.famillie, file);
	fputs("\n", file);

	printf("First name author: ");
	gets_s(bib1.name);
	fputs(bib1.name, file);
	fputs("\n", file);

	printf("Middle name author : ");
	gets_s(bib1.dadname);
	fputs(bib1.dadname, file);
	fputs("\n", file);

	printf("Book title: ");
	gets_s(bib1.book);
	fputs(bib1.book, file);
	fputs("\n", file);

	printf("Described language: ");
	gets_s(bib1.language);
	fputs(bib1.language, file);
	fputs("\n", file);

	printf("Year of publishing: ");
	gets_s(bib1.year);
	fputs(bib1.year, file);
	fputs("\n", file);

	printf("Price: ");
	gets_s(bib1.price);
	fputs(bib1.price, file);
	fputs("\n", file);

	printf("Date of purchase: ");
	gets_s(bib1.buydate);
	fputs(bib1.buydate, file);
	fputs("\n", file);

	printf("Did you use it in your work: ");
	gets_s(bib1.usefull);
	fputs(bib1.usefull, file);

	AddToList(pList, bib1);
	fclose(file);
}
void Delete(LIST **pList){
	(*pList)->len--;
	char id[8];
	Print((*pList)->top);
	printf("\nPlease enter ID: ");
	gets_s(id);
	pNODE t = (*pList)->top;
	if (strcmp(t->data.id, id) == 0){
		(*pList)->top = t->next;
		delete t;
		return;
	}
	pNODE t1 = t->next;
	while (t1){
		if (strcmp(t1->data.id, id) == 0){
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}
void Find(pNODE tNode){
	pNODE temp = tNode;
	char LNAu[20];
	printf("Please input author last name: ");
	gets_s(LNAu);
	while (temp){
		if (strcmp(temp->data.famillie, LNAu) == 0){
			printf("%s %s %s %s %s %s %s %s %s %s \n", temp->data.id, temp->data.famillie, temp->data.name, temp->data.dadname, temp->data.book, temp->data.language, temp->data.year, temp->data.price, temp->data.buydate, temp->data.usefull);
		}
		temp = temp->next;
	}
	printf("Nothing else");
	_getch();
}
void LanguageTable(pNODE tNode){
	pNODE t = tNode->next;
	char lang[50][15];
	int count[50], i = 0, j;
	bool flag, ex = TRUE;
	for (int k = 0; k<50; k++)
		count[k] = 0;
	strcpy_s(lang[0], t->data.language);
	while (i < 50 && t){
		if (t->next == NULL){
			ex = FALSE;
			break;
		}
		t = t->next;
		flag = TRUE;
		for (j = 0; j <= i; j++){
			if (strcmp(lang[j], t->data.language) == 0 && t != NULL){
				flag = FALSE;
				break;
			}
		}
		if (flag && t != NULL){
			i++;
			strcpy_s(lang[i], t->data.language);
		}
	}
	pNODE t1 = tNode->next;
	pNODE t2;
	for (int q = 0; q <= i; q++){
		t2 = t1;
		while (t2){
			if (strcmp(lang[q], t2->data.language) == 0){
				count[q]++;
			}
			t2 = t2->next;
		}
	}
	for (int p = 0; p <= i; p++){
		printf(" %-10s", lang[p]);
	}
	printf("\n");
	for (int p = 0; p <= i; p++){
		printf(" %-10d", count[p]);
	}
	FILE *ff;
	if (fopen_s(&ff, "CountLngBks.txt", "w")){
		printf("Read error\n");
		exit(1);
	}
	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-13s", lang[p]);
	}
	fprintf(ff, "\n");
	for (int p = 0; p <= i; p++){
		fprintf(ff, "%-13d", count[p]);
	}
	fclose(ff);
	printf("\n>>>");
	_getch();
}
void ReadFromFile(LIST **pList){
	FILE *file;
	biblioteka bib2;
	fopen_s(&file, "Biblioteka.txt", "r+");

	while (!feof(file)){
		fgets(bib2.id, 8, file);
		DelEndOfStr(bib2.id);
		fgets(bib2.famillie, 30, file);
		DelEndOfStr(bib2.famillie);
		fgets(bib2.name, 30, file);
		DelEndOfStr(bib2.name);
		fgets(bib2.dadname, 30, file);
		DelEndOfStr(bib2.dadname);
		fgets(bib2.book, 30, file);
		DelEndOfStr(bib2.book);
		fgets(bib2.language, 15, file);
		DelEndOfStr(bib2.language);
		fgets(bib2.year, 10, file);
		DelEndOfStr(bib2.year);
		fgets(bib2.price, 100, file);
		DelEndOfStr(bib2.price);
		fgets(bib2.buydate, 15, file);
		DelEndOfStr(bib2.buydate);
		fgets(bib2.usefull, 10, file);
		DelEndOfStr(bib2.usefull);
		AddToList(pList, bib2);
	}
	fclose(file);
}
void SaveToFile(pNODE *tNode){
	FILE *file;
	fopen_s(&file, "Biblioteka.txt", "w+");

	pNODE node = (*tNode)->next;
	while (node){
		fputs(node->data.id, file);
		fprintf(file, "\n");
		fputs(node->data.famillie, file);
		fprintf(file, "\n");
		fputs(node->data.name, file);
		fprintf(file, "\n");
		fputs(node->data.dadname, file);
		fprintf(file, "\n");
		fputs(node->data.book, file);
		fprintf(file, "\n");
		fputs(node->data.language, file);
		fprintf(file, "\n");
		fputs(node->data.year, file);
		fprintf(file, "\n");
		fputs(node->data.price, file);
		fprintf(file, "\n");
		fputs(node->data.buydate, file);
		fprintf(file, "\n");
		fputs(node->data.usefull, file);
		if (node->next != NULL)
			fprintf(file, "\n");
		node = node->next;
	}
	fclose(file);
}



