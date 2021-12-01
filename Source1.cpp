#include "Header.h"
int game()
{
	char** display;
	if (!(display = (char**)malloc(HIGH * sizeof(char*)))) {
		return 0;
	}
//	char display[HIGH][LENGTH];
	for (int i = 0; i < HIGH; i++)
		if (!(*(display + i) = (char*)malloc(LENGTH * sizeof(char)))) //выделение памяти под игровое поле
		{
			for (int k = i - 1; k > -1; k--)
				free(*(display + k));
			free(display);
			printf_s("ошибка выделения памяти");
			system("pause");
			return 0;
		}
	for (int i = 0; i < HIGH; i++)        //заполнение поля пробелами
		for (int j = 0; j < LENGTH; j++)
		{
			*(*(display + i) + j) = ' ';
		}
	for (int i = 0; i < HIGH; i++)			//"отбойники"
	{
		*(*(display + i) + LENGTH / 2 - i - 5) = 47;
		*(*(display + i) + LENGTH / 2 + i + 5) = 92;
	}
	const char carTop[8] = { ' ', 47, '-', '-', '-', 92, ' ', '\0' };		//"верх" машины
	const char carBottom[8] = { '[','.','-','-','-','.',']','\0' };  //"низ" машины
	//статичные элементы
	system("pause");
	int start = LENGTH / 2 - 3; //начальное положение машины
	strcpy_s(display[HIGH - 1] + start, strlen(carBottom) + 1, carBottom);//прорисовка машины
	strcpy_s(display[HIGH - 2] + start, strlen(carBottom) + 1, carTop);	  //
	play(display, start);
	system("pause");
	system("CLS");
	for (int a = 0; a < HIGH; a++)
		free(*(display + a));
	free(display);
	return 0;
}
int play(char** display, int carPoint)
{
	int stat = clock();		//текущее кол-во тактов для начала отсчета
	while (carPoint < LENGTH - 11 && carPoint > 3)		//если вылет за отбойники - игра прекращается
	{
		system("CLS");
		if (_kbhit())	//проверка на нажатие клавиши											//управление
		{
			char ch = _getch();
			if (ch == 'a' || ch == 'A') //cдвиг машины влево
			{
				int a;
				for (a = 0; a < 8; a++)
				{
					display[HIGH - 1][carPoint + a - 1] = display[HIGH - 1][carPoint + a];
					display[HIGH - 2][carPoint + a - 1] = display[HIGH - 2][carPoint + a];
				}
				display[HIGH - 1][carPoint + a] = ' ';
				display[HIGH - 2][carPoint + a] = ' ';
				carPoint--;
			}
			if (ch == 'd' || ch == 'D')	//cдвиг машины вправо
			{
				int a;
				for (a = 8; a > 0; a--)
				{
					display[HIGH - 1][carPoint + a] = display[HIGH - 1][carPoint + a - 1];
					display[HIGH - 2][carPoint + a] = display[HIGH - 2][carPoint + a - 1];
				}
				display[HIGH - 1][carPoint] = ' ';
				display[HIGH - 2][carPoint] = ' ';
				carPoint++;
			}
		}
			//генерация новых и смещение существующих препятствий
		for (int i = 0; i < LENGTH; i++)//если препятствие дошло до нижних строк, то удалить его или завершить игру, если оно задело машину
		{
			if (display[HIGH - 1][i] == '_')
			{
				if (i - carPoint <= 8 && i - carPoint >= -8)
				{
					return 0;
				}
				else
				{
					while (display[HIGH - 1][i] == '_')
					{
						display[HIGH - 1][i] = ' ';
						i++;
					}
					break;
				}
			}
		}
		for(int i = 1; i < HIGH; i++)			//смещение существующих препятствий на один элемент вниз и от -1 до 1 по сторонам
			for (int j = 0; j < LENGTH; j++)
			{
				if (display[HIGH - 1 - i][j] == '_')
				{
					int shift = random();
					while (display[HIGH - 1 - i][j] == '_')
					{
						display[HIGH - 1 - i][j] = ' ';
						display[HIGH - i][j + shift] = '_';
						j++;
					}
					break;
				}
			}
		srand(((clock() + time(nullptr))));
		int create = rand() % 9;
		if (create == 1)
			for (int a = LENGTH / 2 - 4; a < LENGTH / 2 + 5; a++)	//с вероятностью 1 к 9, появится новое препятствие
			{
				display[0][a] = '_';
			}
		for (int p = 0; p < HIGH; p++)			//прорисовка
		{
			for (int j = 0; j < LENGTH; j++)
			{
				printf_s("%c", display[p][j]);
			}
			printf("\n");
		}
		Sleep(50);
	}
	printf("Вы проиграли\n");
	system("pause");
	printf("Вы продержались %d секунд\n", (clock() - stat) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
int random()	//случайное число от -1 до 1
{
	int a;
	srand(((clock() + time(nullptr))));
	a = rand() % 3 - 1;
	return a;
}