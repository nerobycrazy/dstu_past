#pragma once
#include <iostream>
using namespace std;

#define li cout << "-----РАБОТА СО СПИСКОМ-----" << endl
#define qu cout << "-----РАБОТА С ОЧЕРЕДЬЮ-----" << endl
#define st cout << "-----РАБОТА СО СТЕКОМ-----" << endl
#define br cout << endl

struct node
{
	int num;
	struct  node *next, *prev;
};

//-----ИНТЕРФЕЙС-----//

//Выбор подходящего варианта
int interfaces() {
	int num;
	cout << "Выберите подходящий вариант:" << endl <<
		"1. Показать работу списка." << endl <<
		"2. Показать работу очереди." << endl <<
		"3. Показать работу стека." << endl;
	cout << "Введите: "; cin >> num;
	return num;
}

//Выбор продолжения или выхода
int excon() {
	int num;
	cout << "Выберите подходящий вариант:" << endl <<
		"1. Продолжить." << endl <<
		"2. Выйти." << endl;
	cout << "Введите: "; cin >> num;
	return num;
}

//-----Функции по работе со списком----//

struct list
{
	node *begin, *end;
	int len;
};

//Инициализация двусвязного списка
void init_list(list *l){
	l->begin = NULL;
	l->end = NULL;
	l->len = 0;
	l = new list;
	cout << "Инициализация списка..." << endl;
}

//Добавление элемента в конец списка
void add_end_list(list *l, int n){
	node *tmp = new node;
	tmp->num = n;
	tmp->prev = l->end;
	if (l->len == 0) {
		l->begin = tmp;
	}
	l->end = tmp;
	l->len++;
	cout << "Добавление элемента " << n << " в конец списка..." << endl;
}

//Добавление элемента в середину списка
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
	cout << "Добавление элемента " << n << " на " << m << " место в списке..." << endl;
}

//Добавление элемента в начало списка
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
	cout << "Добавление элемента " << n << " в начало списка..." << endl;
}

//Вывод элементов списка в прямом или обратном порядке
void out_list(list *l, int n) {
	list* tmp = new list;
	node *p = new node, *p1 = new node;
	int n1 = l->len;
	p = l->begin;
	p1 = l->end;
	tmp = l;
	if (n == 0) {
		cout << "Вывод списка с конца:" << endl;
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
		cout << "Вывод списка с начала:" << endl;
		while (tmp->begin) {
			cout << tmp->begin->num << " ";
			tmp->begin = tmp->begin->next;
		}
	}
	cout << endl;
	l->end = p1;
	l->begin = p;
}

//Настройка ссылок на элементы
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
	cout << "Производится настройка ссылок..." << endl;
}

//Удаление элемента
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
	cout << "Удаление " << n << " элемента из списка..." << endl;
	l->end = p4;
	l->len = n1 - 1;
}

//Проверка на пустоту списка
void isempty_list(list *l) {
	if (l->len > 0) {
		cout << "Список не пуст, в нём " << l->len << endl;
	}
	else cout << "Список пуст" << endl;
}

//Полная очиска списка
void clear_list(list *l) {
	node *tmp = new node;
	while (l->begin)
	{
		tmp = l->begin;
		l->begin = l->begin->next;
		l->len--;
		delete[] tmp;
	}
	cout << "Очищение списка..." << endl;
}

//-----Функции по работе с очередью----//

struct queue
{
	node *begin, *end;
	int len;
};

//Инициализация двусвязной очереди
void init_queue(queue *l) {
	l->begin = NULL;
	l->end = NULL;
	l->len = 0;
	cout << "Инициализация очереди..." << endl;
}

//Добавление элемента в конец списка
void add_end_queue(queue *l, int n) {
	node *tmp = new node;
	tmp->num = n;
	tmp->prev = l->end;
	if (l->len == 0) {
		l->begin = tmp;
	}
	l->end = tmp;
	l->len++;
	cout << "Добавление элемента " << n << " в конец очереди..." << endl;
}

//Удаление элемента в очереде
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
	cout << "Удаление " << n << " элемента из очереди..." << endl;
	l->end = p4;
	l->len = n1 - 1;
}

//Проверка на пустоту очереди
void isempty_queue(queue *l) {
	if (l->len > 0) {
		cout << "Очередь не пуста, в ней " << l->len << endl;
	}
	else cout << "Очередь пуста." << endl;
}

//Вывод элементов списка в прямом или обратном порядке
void out_queue(queue *l, int n) {
	queue* tmp = new queue;
	node *p = new node, *p1 = new node;
	int n1 = l->len;
	p = l->begin;
	p1 = l->end;
	tmp = l;
	if (n == 0) {
		cout << "Вывод очереди с конца:" << endl;
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
		cout << "Вывод очереди с начала:" << endl;
		while (tmp->begin) {
			cout << tmp->begin->num << " ";
			tmp->begin = tmp->begin->next;
		}
	}
	cout << endl;
	l->end = p1;
	l->begin = p;
}

//Полная очиска очереди
void clear_queue(queue *l) {
	node *tmp = new node;
	while (l->begin)
	{
		tmp = l->begin;
		l->begin = l->begin->next;
		l->len--;
		delete[] tmp;
	}
	cout << "Очищение очереди..." << endl;
}

//Настройка ссылок на элементы
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
	cout << "Производится настройка ссылок..." << endl;
}

//-----Функции по работе со стеком----//

struct stack
{
	node *top;
	int len;
};

//Инициализация стека
void init_stack(stack *l) {
	l->top = NULL;
	l->len = 0;
	cout << "Инициализация стека..." << endl;
}

//Добавление элемента в стек
void add_stack(stack *l, int n) {
	node *tmp = new node;
	tmp->num = n;
	tmp->next = l->top;
	l->top = tmp;
	l->len++;
	cout << "Добавление элемента " << n << " в стек..." << endl;
}

//Удаление элемента в очереде
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
	cout << "Удаление " << n << " элемента из стека..." << endl;
	l->len--;
}

//Проверка на пустоту очереди
void isempty_stack(stack *l) {
	if (l->len > 0) {
		cout << "Стек не пуст, в нём " << l->len << endl;
	}
	else cout << "Стек пуст." << endl;
}

//Вывод элементов списка в прямом или обратном порядке
void out_stack(stack *l) {
	node *p = new node, *tmp = new node;
	p = l->top;
	tmp = l->top;
	cout << "Вывод стека:" << endl;
	do {
		cout << tmp->num << " ";
		tmp = tmp->next;
	} while (tmp);
	l->top = p; br;
}

//Полная очиска очереди
void clear_stack(stack *l) {
	node *tmp = new node;
	while (l->top)
	{
		tmp = l->top;
		l->top = l->top->next;
		l->len--;
		delete[] tmp;
	}
	cout << "Очищение стека..." << endl;
}