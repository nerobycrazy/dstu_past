#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

using namespace std;
enum estate { notfound, found, returned };
enum etype { other, cloth, documents, food, electronics };

typedef struct info {
	char name[30];
	char date[11];
	char itemname[15];
	etype itemtype;
	int duration;
	estate state;
};
typedef struct item {
	struct info *data;
	struct item *next;
};
item *ptr, *first;
int menuselect;

struct info * todata(char nname[30], char ndate[11], char nitemname[15],
	etype nitemtype, int nduration, estate nstate) // заргузка данных в структуру info
{
	struct info * tempdata;
	tempdata = (struct info*)malloc(sizeof(info));
	strcpy_s(tempdata->name, nname);
	strcpy_s(tempdata->date, ndate);
	strcpy_s(tempdata->itemname, nitemname);
	tempdata->itemtype = nitemtype;
	tempdata->duration = nduration;
	tempdata->state = nstate;
	return(tempdata);
}

struct item * additem(item *&itm, info *tempdata) // добавление элемента после текущего
{
	struct item *temp;
	temp = (struct item*)malloc(sizeof(item));
	temp->data = tempdata;

	if (itm != NULL) //если элемент существует, то вставляем новый после него
	{
		struct item *p;
		p = itm->next;
		itm->next = temp;
		temp->next = p;
	}
	else
	{
		itm = temp;
		itm->next = NULL;
	}
	return(temp);
}
void gets_rus(char *str, int n)
{
	SetConsoleCP(1251); //ф-я Setlocale почему-то не распространяется на ввод с клавиатуры
	gets_s(str, n - 1);   // поэтому меняем кодировку консоли на время ввода
	SetConsoleCP(866);  // и возвращаем обратно после ввода
}
struct info * readdata()
{
	char name[30] = "неизвестно";
	char date[11] = "неизвестно";
	char itemname[15] = "неизвестно";
	etype itemtype = other;
	int duration = 7;
	estate state = notfound;

	printf("\nВведите имя: ");
	gets_rus(name, 31);
	printf("Введите дату: ");
	gets_rus(date, 12);
	printf("Введите название вещи: ");
	gets_rus(itemname, 15);
	printf("Выберите тип вещи: 1-Одежда, 2-Документы, 3-Провизия, 4-Электроника, 0-Другое\n");
	switch (_getch())
	{
	case '1': {itemtype = cloth; break; }
	case '2': {itemtype = documents; break; }
	case '3': {itemtype = food; break; }
	case '4': {itemtype = electronics; break; }
	case '0': {itemtype = other; break; }
	}
	printf("Укажите продолжительность поиска(дней): ");
	scanf_s("%d", &duration);
	getchar(); //получаем последний символ потока stdin
	printf("Выберите статус вещи: 0-Не найдено, 1-Найдено, 2-Возвращено хозяину");
	switch (_getch())
	{
	case '0': {state = notfound; break; }
	case '1': {state = found; break; }
	case '2': {state = returned; break; }
	}
	return(todata(name, date, itemname, itemtype, duration, state));

}
void deleteitem(item *&itm)
{
	struct item *p;
	if (itm->next != NULL)
	{
		p = itm->next;
		itm->next = p->next;
		free(p);
	}
}
void printlist(item *itm) // Вывод списка на экран
{
	//itm = itm->next;
	while (itm != NULL)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //получение дескриптора устройства вывода
		if (ptr == itm)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11)); //смена цвета текста на 14(желтый)
			_putch('>');
		}
		else
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); //смена цвета текста на 15(белый)
			_putch(' ');
		}
		printf("%-14s\t%-11s\t%-14s\t%d\t%d\t%d\n", itm->data->name, itm->data->date, itm->data->itemname, itm->data->itemtype, itm->data->duration, itm->data->state);
		itm = itm->next;
	}
}

void filesave(struct item *itm, char *path)
{
	FILE *fp;
	fopen_s(&fp, path, "wb+");
	while (itm != NULL)
	{
		fwrite(itm->data, sizeof(struct info), 1, fp);
		itm = itm->next;
	}
	fclose(fp);
}
struct item * fileload(char *path)
{
	FILE *fp;
	if (fopen_s(&fp, path, "rb+")) //если файл успешно открыт, fopen_s вернет 0
	{
		printf("Ошибка при открытии файла.\n");
		exit(1);
	}
	struct item *temp = NULL;
	for (;;)
	{
		struct info *tempd;
		tempd = (struct info*)malloc(sizeof(info));

		fread(tempd, sizeof(struct info), 1, fp);
		if (!feof(fp))
			additem(temp, tempd);
		else
			break;
	}
	fclose(fp);
	return(temp);
}

void drawmenu()
{
	char* menu[8] = { "\n   загрузить ", " сохранить ", " изменить ", " добавить ", " удалить\n\n", "\tсписок возвращенных ", "\tчисло заявок по типам\n", "______________________________________________________________\n\n" };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //получение дескриптора устройства вывода
	for (int i = 0; i <= 7; i++)
	{
		if (i == menuselect)
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
		else
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
		printf("%s", menu[i]);
	}
}
void kbhandler() //обработчик нажатий клавиш
{
	switch (_getch())
	{
	case 224: // нажатие стрелок
	{
				  switch (_getch())
				  {
				  case 80:  //стрелка вниз
				  {
								if (ptr->next != NULL)
									ptr = ptr->next;
								else
									ptr = first;
								break;
				  }
				  case 72: //стрелка вверх
				  {
							   //deleteitem(ptr);
							   break;
				  }
				  case 75: //стрелка влево
				  {
							   menuselect = (menuselect + 6) % 7;
							   break;
				  }
				  case 77: //стрелка вправо
				  {
							   menuselect = (menuselect + 1) % 7;
							   break;
				  }
				  }
				  break;
	}
	case 13:  // нажатие Enter
	{
				  switch (menuselect)
				  {
				  case 0: {
							  first = fileload("struct1.txt");
							  ptr = first;
							  break;
				  }

				  case 1:
				  {
							filesave(first, "struct2.txt");
							break;
				  }
				  case 2:
				  {
							ptr->data = readdata();
							break;
				  }
				  case 3:
				  {
							ptr = additem(ptr, readdata());
							break;
				  }
				  case 4:
				  {
							deleteitem(ptr);
							break;
				  }
				  case 5:
				  {
							system("cls");
							_putch('\n');
							struct item *itm = first;
							while (itm != NULL)
							{
								if (itm->data->state == returned)
									printf(" %-14s\t%-11s\t%-14s\t%d\t%d\t%d\n", itm->data->name, itm->data->date, itm->data->itemname, itm->data->itemtype, itm->data->duration, itm->data->state);
								itm = itm->next;
							}
							_putch('\n');
							system("pause");
							break;
				  }
				  case 6:
				  {
							byte *arr[5] = { 0, 0, 0, 0, 0 };
							struct item *itm = first;
							while (itm != NULL)
							{
								++arr[itm->data->itemtype];
								itm = itm->next;
							}
							//system("cls");
							_putch('\n');
							for (int i = 0; i <= 4; i++)
								printf("%d  ", arr[i]);
							_putch('\n');
							system("pause");
							break;
				  }

				  }
				  break;
	}
	}

	system("cls");
	drawmenu();
	printlist(first);
}
void main()
{
	//_configthreadlocale(_DISABLE_PER_THREAD_LOCALE);
	setlocale(LC_ALL, "Rus");
	first = NULL;
	/*
	additem(first, todata("Петров П.П.", "21.06.2016", "Паспорт  ", documents, 30, notfound));
	additem(first, todata("Сидоров С.С.", "29.05.2016", "Шляпа   ", cloth, 14, returned));
	additem(first, todata("Иванов И.И.", "04.07.2016", "Куртка  ", cloth, 21, found));
	additem(first, todata("Поркшеян В.М.", "08.06.2016", "Свитер   ", cloth, 14, notfound));
	additem(first, todata("Месхи Б.Ч.", "15.06.2016", "Галстук  ", cloth, 21, returned));
	additem(first, todata("Путин В.В.", "19.06.2016", "Плеер   ", electronics, 7, found));
	additem(first, todata("Медведев Д.А.", "31.05.2016", "СНИЛС    ", documents, 60, returned));
	additem(first, todata("Обама Б.Х.", "02.07.2016", "Фотоаппарат", electronics, 14, notfound));
	additem(first, todata("Джигурда Н.Б.", "02.07.2016", "Макароны ", food, 5, found));
	additem(first, todata("Ромашкин И.Р.", "07.07.2016", "Ключи    ", other, 60, found));
	additem(first, todata("Рыжикова С.Н.", "30.06.2016", "Кольцо   ", other, 90, notfound));
	additem(first, todata("Астахов И.Д.", "01.07.2016", "Телефон  ", electronics, 21, found));
	*/
	//system("mode con cols=128 lines=30"); //размер консольного окна
	first = fileload("struct1.txt");
	ptr = first;
	drawmenu();
	printlist(first);
	//filesave(first, "struct2.txt");
	for (;;) kbhandler();
	system("pause");
}