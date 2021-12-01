#include "Header.h"
int game()
{
	char** display;
	if (!(display = (char**)malloc(HIGH * sizeof(char*)))) {
		return 0;
	}
//	char display[HIGH][LENGTH];
	for (int i = 0; i < HIGH; i++)
		if (!(*(display + i) = (char*)malloc(LENGTH * sizeof(char)))) //��������� ������ ��� ������� ����
		{
			for (int k = i - 1; k > -1; k--)
				free(*(display + k));
			free(display);
			printf_s("������ ��������� ������");
			system("pause");
			return 0;
		}
	for (int i = 0; i < HIGH; i++)        //���������� ���� ���������
		for (int j = 0; j < LENGTH; j++)
		{
			*(*(display + i) + j) = ' ';
		}
	for (int i = 0; i < HIGH; i++)			//"���������"
	{
		*(*(display + i) + LENGTH / 2 - i - 5) = 47;
		*(*(display + i) + LENGTH / 2 + i + 5) = 92;
	}
	const char carTop[8] = { ' ', 47, '-', '-', '-', 92, ' ', '\0' };		//"����" ������
	const char carBottom[8] = { '[','.','-','-','-','.',']','\0' };  //"���" ������
	//��������� ��������
	system("pause");
	int start = LENGTH / 2 - 3; //��������� ��������� ������
	strcpy_s(display[HIGH - 1] + start, strlen(carBottom) + 1, carBottom);//���������� ������
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
	int stat = clock();		//������� ���-�� ������ ��� ������ �������
	while (carPoint < LENGTH - 11 && carPoint > 3)		//���� ����� �� ��������� - ���� ������������
	{
		system("CLS");
		if (_kbhit())	//�������� �� ������� �������											//����������
		{
			char ch = _getch();
			if (ch == 'a' || ch == 'A') //c���� ������ �����
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
			if (ch == 'd' || ch == 'D')	//c���� ������ ������
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
			//��������� ����� � �������� ������������ �����������
		for (int i = 0; i < LENGTH; i++)//���� ����������� ����� �� ������ �����, �� ������� ��� ��� ��������� ����, ���� ��� ������ ������
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
		for(int i = 1; i < HIGH; i++)			//�������� ������������ ����������� �� ���� ������� ���� � �� -1 �� 1 �� ��������
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
			for (int a = LENGTH / 2 - 4; a < LENGTH / 2 + 5; a++)	//� ������������ 1 � 9, �������� ����� �����������
			{
				display[0][a] = '_';
			}
		for (int p = 0; p < HIGH; p++)			//����������
		{
			for (int j = 0; j < LENGTH; j++)
			{
				printf_s("%c", display[p][j]);
			}
			printf("\n");
		}
		Sleep(50);
	}
	printf("�� ���������\n");
	system("pause");
	printf("�� ������������ %d ������\n", (clock() - stat) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
int random()	//��������� ����� �� -1 �� 1
{
	int a;
	srand(((clock() + time(nullptr))));
	a = rand() % 3 - 1;
	return a;
}