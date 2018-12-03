#include "pch.h"
#include "User_Layer.h"
#include <cstdio>
#include <cstdlib>

int(user_layer::ask_for_number)(const char * question)
{
	int flag = 0;
	do
	{
		fseek(stdin, 0, SEEK_SET); // clear input buffer
		system("cls");
		printf(question);
		scanf_s("%d", &flag, sizeof(int));
	} while (flag == 0);
	system("cls");
	return flag;
}
