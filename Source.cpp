#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	int str;
	while (1)
	{
		system("CLS");
		printf("\t������� ���� \n\n\t1. ����\n\t0: �����.\n\n\t�� �� ������ ������������ � ������������� � �����������. ����������: a - ������� ������ ������, b - �������\n");
		if (!scanf_s("%d", &str))
		{
			printf("�������� ��������");
			break;
		}
		system("CLS");
		switch (str)
		{
		case 1: game(); continue;
		case 0: return 0;
		default: printf("�������� ��������\n ");
			system("pause");
			continue;
		}

	}
}