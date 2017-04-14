// Stack_and_other.cpp: ���������� ����� ����� ��� ����������� ����������.
#include "stdafx.h"
#include <iostream>
#include <malloc.h>

typedef struct Node					// ��������� �� ����
{
	char value;
	struct Node*next;
} NODE, *pNODE;

typedef struct stack				// ����
{
	pNODE begin;
	int len;
} STACK, *pSTACK;

pSTACK createStack(void){			//�������� ������� �����
	pSTACK pS;
	pS = (pSTACK)malloc(sizeof(STACK));
	pS->begin = NULL;
	pS->len = 0; 
	return pS;
}

int isEmpty(pSTACK pS){				//��������� ������� ��������� � �����
	if (pS->begin)
		return 0;
	else
		return 1;
}

void push(pSTACK pS, char c){		//���������� ������ ��������
	pNODE p = (pNODE)malloc(sizeof(NODE));
	p->value = c;
	p->next = pS->begin;
	pS->begin = p;					//��������� ������ ��� ����. ��������
	pS->len++;
}

char pop(pSTACK pS){				//���������� ���������
	pNODE p = pS->begin;
	char c = p->value;
	pS->begin = p->next;
	free(p);
	pS->len--;
	return c;
}

void print(pSTACK pS){				//����� ����������� �����
	pNODE p = pS->begin;
	if (isEmpty(pS)) printf("Stack is Clear"); 
	while (p){
		printf("%c ", p->value);
		p = p->next;
	}
	printf("\n");
}

void clearStack(pSTACK pS){			//������� �����
	pNODE p = pS->begin;
	while (p) {
		p = p->next;				//������ ����� � ���� ���������
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
