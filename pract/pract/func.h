#pragma once
#include <iostream>
using namespace std;

#define li cout << "-----������ �� �������-----" << endl
#define qu cout << "-----������ � ��������-----" << endl
#define st cout << "-----������ �� ������-----" << endl
#define br cout << endl

struct node
{
	int num;
	struct  node *next, *prev;
};

//-----���������-----//

//����� ����������� ��������
int interfaces() {
	int num;
	cout << "�������� ���������� �������:" << endl <<
		"1. �������� ������ ������." << endl <<
		"2. �������� ������ �������." << endl <<
		"3. �������� ������ �����." << endl;
	cout << "�������: "; cin >> num;
	return num;
}

//����� ����������� ��� ������
int excon() {
	int num;
	cout << "�������� ���������� �������:" << endl <<
		"1. ����������." << endl <<
		"2. �����." << endl;
	cout << "�������: "; cin >> num;
	return num;
}

//-----������� �� ������ �� �������----//

struct list
{
	node *begin, *end;
	int len;
};

//������������� ����������� ������
void init_list(list *l){
	l->begin = NULL;
	l->end = NULL;
	l->len = 0;
	l = new list;
	cout << "������������� ������..." << endl;
}

//���������� �������� � ����� ������
void add_end_list(list *l, int n){
	node *tmp = new node;
	tmp->num = n;
	tmp->prev = l->end;
	if (l->len == 0) {
		l->begin = tmp;
	}
	l->end = tmp;
	l->len++;
	cout << "���������� �������� " << n << " � ����� ������..." << endl;
}

//���������� �������� � �������� ������
void add_middle_list(list *l, int n, int m) {
	node *tmp = new node, *p = new node, *p1 = new node, *p2 = new node, *p3 = new node;
	int n1 = l->len;
	p = l->end;
	while (l->end) {
		if (n1 == m) {
			p1 = l->end;
			break;
		}
		l->end = l->end->prev;
		n1--;
	}
	if (m == 2) {
		p3 = l->begin;
		p2 = p3->next;
		tmp->num = n;
		tmp->next = p2;
		tmp->prev = p3;
		l->end = tmp;
	}
	else {
		p2 = p1->prev;
		tmp->num = n;
		tmp->next = p1;
		tmp->prev = p2;
		l->end = tmp;
		p2->next = tmp;
		p1->prev = tmp;
	}
	l->len++;
	l->end = p;
	cout << "���������� �������� " << n << " �� " << m << " ����� � ������..." << endl;
}

//���������� �������� � ������ ������
void add_begin_list(list *l, int n) {
	node *tmp = new node;
	tmp->num = n;
	if (l->len == 0) {
		tmp->prev = l->end;
		l->begin = tmp;
	}
	else {
		tmp->next = l->begin;
		l->begin->prev = tmp;
		l->begin = tmp;
	}
	l->len++;
	cout << "���������� �������� " << n << " � ������ ������..." << endl;
}

//����� ��������� ������ � ������ ��� �������� �������
void out_list(list *l, int n) {
	list* tmp = new list;
	node *p = new node, *p1 = new node;
	int n1 = l->len;
	p = l->begin;
	p1 = l->end;
	tmp = l;
	if (n == 0) {
		cout << "����� ������ � �����:" << endl;
		while (tmp->end) {
			if (n1 == 0) {
				break;
			}
			if (n1 == 1) {
				cout << tmp->begin->num << " ";
				break;
			}
			cout << tmp->end->num << " ";
			tmp->end = tmp->end->prev;
			n1--;
		}
	}
	else {
		cout << "����� ������ � ������:" << endl;
		while (tmp->begin) {
			cout << tmp->begin->num << " ";
			tmp->begin = tmp->begin->next;
		}
	}
	cout << endl;
	l->end = p1;
	l->begin = p;
}

//��������� ������ �� ��������
void link_list(list *l) {
	node *p = new node, *p1 = new node;
	int n;
	n = l->len;
	p = l->end;
	p1 = p;
	l->end->next = NULL;
	l->end = l->end->prev;
	while (l->end) {
		if (l->len == 1) break;
		l->end->next = p1;
		p1 = l->end;
		l->end = l->end->prev;
		l->len--;
	}
	l->end = p;
	l->len = n;
	cout << "������������ ��������� ������..." << endl;
}

//�������� ��������
void del_list(list *l, int n) {
	list *tmp = new list;
	node*p = new node, *p1 = new node, *p3 = new node, *p4 = new node;
	int n1;
	p4 = l->end;
	n1 = l->len;
	tmp = l;
	while (tmp->end) {
		if (n == 1) {
			p3 = tmp->begin;
			tmp->begin = tmp->begin->next;
			tmp->begin->prev = NULL;
			delete[] p3;
			break;
		}
		else if (n == n1) {
			p = tmp->end;
			tmp->end = tmp->end->prev;
			tmp->end->next = NULL;
			delete[] p;
			break;
		}
		else if (tmp->len == n) {
			p3 = tmp->end->prev;
			p1 = tmp->end->next;
			p = tmp->end;
			p3->next = p1;
			p1->prev = p3;
			delete[] p;
			break;
		}
		p = tmp->end;
		tmp->end = tmp->end->prev;
		tmp->len--;
	}
	cout << "�������� " << n << " �������� �� ������..." << endl;
	l->end = p4;
	l->len = n1 - 1;
}

//�������� �� ������� ������
void isempty_list(list *l) {
	if (l->len > 0) {
		cout << "������ �� ����, � �� " << l->len << endl;
	}
	else cout << "������ ����" << endl;
}

//������ ������ ������
void clear_list(list *l) {
	node *tmp = new node;
	while (l->begin)
	{
		tmp = l->begin;
		l->begin = l->begin->next;
		l->len--;
		delete[] tmp;
	}
	cout << "�������� ������..." << endl;
}

//-----������� �� ������ � ��������----//

struct queue
{
	node *begin, *end;
	int len;
};

//������������� ���������� �������
void init_queue(queue *l) {
	l->begin = NULL;
	l->end = NULL;
	l->len = 0;
	cout << "������������� �������..." << endl;
}

//���������� �������� � ����� ������
void add_end_queue(queue *l, int n) {
	node *tmp = new node;
	tmp->num = n;
	tmp->prev = l->end;
	if (l->len == 0) {
		l->begin = tmp;
	}
	l->end = tmp;
	l->len++;
	cout << "���������� �������� " << n << " � ����� �������..." << endl;
}

//�������� �������� � �������
void del_queue(queue *l, int n) {
	queue *tmp = new queue;
	node*p = new node, *p1 = new node, *p3 = new node, *p4 = new node;
	int n1;
	p4 = l->end;
	n1 = l->len;
	tmp = l;
	while (tmp->end) {
		if (n == 1) {
			p3 = tmp->begin;
			tmp->begin = tmp->begin->next;
			tmp->begin->prev = NULL;
			delete[] p3;
			break;
		}
		else if (n == n1) {
			p = tmp->end;
			tmp->end = tmp->end->prev;
			tmp->end->next = NULL;
			delete[] p;
			break;
		}
		else if (tmp->len == n) {
			p3 = tmp->end->prev;
			p1 = tmp->end->next;
			p = tmp->end;
			p3->next = p1;
			p1->prev = p3;
			delete[] p;
			break;
		}
		p = tmp->end;
		tmp->end = tmp->end->prev;
		tmp->len--;
	}
	cout << "�������� " << n << " �������� �� �������..." << endl;
	l->end = p4;
	l->len = n1 - 1;
}

//�������� �� ������� �������
void isempty_queue(queue *l) {
	if (l->len > 0) {
		cout << "������� �� �����, � ��� " << l->len << endl;
	}
	else cout << "������� �����." << endl;
}

//����� ��������� ������ � ������ ��� �������� �������
void out_queue(queue *l, int n) {
	queue* tmp = new queue;
	node *p = new node, *p1 = new node;
	int n1 = l->len;
	p = l->begin;
	p1 = l->end;
	tmp = l;
	if (n == 0) {
		cout << "����� ������� � �����:" << endl;
		while (tmp->end) {
			if (n1 == 0) {
				break;
			}
			if (n1 == 1) {
				cout << tmp->begin->num << " ";
				break;
			}
			cout << tmp->end->num << " ";
			tmp->end = tmp->end->prev;
			n1--;
		}
	}
	else {
		cout << "����� ������� � ������:" << endl;
		while (tmp->begin) {
			cout << tmp->begin->num << " ";
			tmp->begin = tmp->begin->next;
		}
	}
	cout << endl;
	l->end = p1;
	l->begin = p;
}

//������ ������ �������
void clear_queue(queue *l) {
	node *tmp = new node;
	while (l->begin)
	{
		tmp = l->begin;
		l->begin = l->begin->next;
		l->len--;
		delete[] tmp;
	}
	cout << "�������� �������..." << endl;
}

//��������� ������ �� ��������
void link_queue(queue *l) {
	node *p = new node, *p1 = new node;
	int n;
	n = l->len;
	p = l->end;
	p1 = p;
	l->end->next = NULL;
	l->end = l->end->prev;
	while (l->end) {
		if (l->len == 1) break;
		l->end->next = p1;
		p1 = l->end;
		l->end = l->end->prev;
		l->len--;
	}
	l->end = p;
	l->len = n;
	cout << "������������ ��������� ������..." << endl;
}

//-----������� �� ������ �� ������----//

struct stack
{
	node *top;
	int len;
};

//������������� �����
void init_stack(stack *l) {
	l->top = NULL;
	l->len = 0;
	cout << "������������� �����..." << endl;
}

//���������� �������� � ����
void add_stack(stack *l, int n) {
	node *tmp = new node;
	tmp->num = n;
	tmp->next = l->top;
	l->top = tmp;
	l->len++;
	cout << "���������� �������� " << n << " � ����..." << endl;
}

//�������� �������� � �������
void del_stack(stack *l, int n) {
	stack *tmp = new stack;
	node*p = new node, *p1 = new node, *p3 = new node, *p4 = new node;
	int n1;
	p = l->top;
	n1 = 1;
	tmp = l;
	while (tmp->top) {
		if (n == 1) {
			p1 = tmp->top;
			tmp->top = tmp->top->next;
			delete[] p1;
			l->top = tmp->top;
			break;
		}
		else if (n1 == n - 1) {
			p1 = tmp->top;
			p3 = tmp->top->next;
			p4 = p3->next;
			p1->next = p4;
			delete[] p3;
			l->top = p;
			break;
		}
		else if (n == tmp->len&&n1 == n - 1) {
			p1 = tmp->top;
			tmp->top = tmp->top->next;
			p3 = tmp->top;
			p1->next = NULL;
			delete[] p3;
			l->top = p;
			break;
		}
		tmp->top = tmp->top->next;
		n1++;
	}
	cout << "�������� " << n << " �������� �� �����..." << endl;
	l->len--;
}

//�������� �� ������� �������
void isempty_stack(stack *l) {
	if (l->len > 0) {
		cout << "���� �� ����, � �� " << l->len << endl;
	}
	else cout << "���� ����." << endl;
}

//����� ��������� ������ � ������ ��� �������� �������
void out_stack(stack *l) {
	node *p = new node, *tmp = new node;
	p = l->top;
	tmp = l->top;
	cout << "����� �����:" << endl;
	do {
		cout << tmp->num << " ";
		tmp = tmp->next;
	} while (tmp);
	l->top = p; br;
}

//������ ������ �������
void clear_stack(stack *l) {
	node *tmp = new node;
	while (l->top)
	{
		tmp = l->top;
		l->top = l->top->next;
		l->len--;
		delete[] tmp;
	}
	cout << "�������� �����..." << endl;
}