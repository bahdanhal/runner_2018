#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	int str;
	while (1)
	{
		system("CLS");
		printf("\tГлавное меню \n\n\t1. Игра\n\t0: Выход.\n\n\tВы не должны сталкиваться с препятствиями и отбойниками. Управление: a - двигать машину налево, b - направо\n");
		if (!scanf_s("%d", &str))
		{
			printf("Неверное значение");
			break;
		}
		system("CLS");
		switch (str)
		{
		case 1: game(); continue;
		case 0: return 0;
		default: printf("Неверное значение\n ");
			system("pause");
			continue;
		}

	}
}