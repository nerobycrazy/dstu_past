// Stack_and_other.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include <iostream>
#include <malloc.h>

typedef struct Node					// указатель на Стек
{
	char value;
	struct Node*next;
} NODE, *pNODE;

typedef struct stack				// Стек
{
	pNODE begin;
	int len;
} STACK, *pSTACK;

pSTACK createStack(void){			//Создание пустого стека
	pSTACK pS;
	pS = (pSTACK)malloc(sizeof(STACK));
	pS->begin = NULL;
	pS->len = 0; 
	return pS;
}

int isEmpty(pSTACK pS){				//Проверяка наличия элементов в стеке
	if (pS->begin)
		return 0;
	else
		return 1;
}

void push(pSTACK pS, char c){		//Добавление нового элемента
	pNODE p = (pNODE)malloc(sizeof(NODE));
	p->value = c;
	p->next = pS->begin;
	pS->begin = p;					//Выделение памяти для след. элемента
	pS->len++;
}

char pop(pSTACK pS){				//Извлечение элементов
	pNODE p = pS->begin;
	char c = p->value;
	pS->begin = p->next;
	free(p);
	pS->len--;
	return c;
}

void print(pSTACK pS){				//Вывод содержимого стека
	pNODE p = pS->begin;
	if (isEmpty(pS)) printf("Stack is Clear"); 
	while (p){
		printf("%c ", p->value);
		p = p->next;
	}
	printf("\n");
}

void clearStack(pSTACK pS){			//Очистка стека
	pNODE p = pS->begin;
	while (p) {
		p = p->next;				//разрыв связи с удал элементом
		pop(pS);
	}
	free(pS);
}

int main(int argc, char *argv[]) {
	char c;

	pSTACK pS = createStack();

	for (c = 'a'; c <= 'z'; c++)
		push(pS, c);
	print(pS);
	while (!isEmpty(pS)){
		pop(pS);
		print(pS);
	}
	return 0;
}
