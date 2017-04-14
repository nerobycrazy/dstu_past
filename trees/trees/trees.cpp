// trees.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>

struct Tree{
	int item;
	Tree *left;
	Tree *right;
};

void Insert(Tree **NewTree, int data){
	if ((*NewTree) == NULL){
		(*NewTree) = new Tree;
		(*NewTree)->item = data;
		(*NewTree)->left = (*NewTree)->right = NULL;
		return;
	}
	if (data < ((*NewTree)->item))
		Insert(&(*NewTree)->left, data);
	else
		Insert(&(*NewTree)->right, data);
}


void Print(Tree *NewTree){
	if (NewTree == NULL)
		return;
	else
	{
		Print(NewTree->left);
		printf("%4ld  ", NewTree->item);
		Print(NewTree->right);
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	//rand()%39+1
	Tree *NewTree = NULL;

	Insert(&NewTree, 8);
	Insert(&NewTree, 5);
	Insert(&NewTree, 12);
	Insert(&NewTree, 16);
	Insert(&NewTree, 4);
	Insert(&NewTree, 9);
	Insert(&NewTree, 11);
	Insert(&NewTree, 23);
	Insert(&NewTree, 10);
	Insert(&NewTree, 6);
	Print(NewTree);	
	return 0;
}

