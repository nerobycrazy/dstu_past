// vse.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "func.h"

void main()
{
	setlocale(0, ""); a:
	system("CLS");
	int num = interfaces(); br;
	switch (num) {
	case 1:{
		   list list1; li; br;
		   init_list(&list1); br;
		   add_end_list(&list1, 5);
		   add_end_list(&list1, 6);
		   add_begin_list(&list1, 3);
		   add_begin_list(&list1, 2); br;
		   link_list(&list1); br;
		   add_middle_list(&list1, 4, 3); br;
		   out_list(&list1, 1); br;
		   out_list(&list1, 0); br;
		   del_list(&list1, 2); br;
		   out_list(&list1, 1); br;
		   out_list(&list1, 0); br;
		   isempty_list(&list1); br;
		   clear_list(&list1); br;
		   isempty_list(&list1); br;
		   break;
		}
		case 2:{
		   queue queue1; qu; br;
		   init_queue(&queue1); br;
		   add_end_queue(&queue1, 4);
		   add_end_queue(&queue1, 3);
		   add_end_queue(&queue1, 2);
		   add_end_queue(&queue1, 1); br;
		   link_queue(&queue1); br;
		   out_queue(&queue1, 1); br;
		   out_queue(&queue1, 0); br;
		   del_queue(&queue1, 3); br;
		   out_queue(&queue1, 1); br;
		   out_queue(&queue1, 0); br;
		   isempty_queue(&queue1); br;
		   clear_queue(&queue1); br;
		   isempty_queue(&queue1); br;
		   break;
		}
		case 3: {
			stack stack1; st; br;
			init_stack(&stack1); br;
			add_stack(&stack1, 1);
			add_stack(&stack1, 2);
			add_stack(&stack1, 3);
			add_stack(&stack1, 4); br;
			out_stack(&stack1); br;
			del_stack(&stack1, 4);
			out_stack(&stack1); br;
			isempty_stack(&stack1); br;
			clear_stack(&stack1); br;
			isempty_stack(&stack1); br;
			break;
			}
		}
	num = excon();
	switch (num) {
	case 1: goto a;
	case 2: exit(0);
	}
	system("pause");
}

