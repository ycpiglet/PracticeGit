// 1. �ٵ����� �׸���.
// 2. �ٵϵ��� ��ǥ�� �Է¹޴´�.
// 3. 0 ~ 18 ������ ���� �Է¹޴´�.
// 4. ���� ��ġ�� ������ �ʰ� �Ѵ�.
// 5. ���� ���� ������ ����
// 6. ���ο� �ٵ����� �׸���.

#include <stdio.h>
#include <Windows.h>

void InitGo(); // ó�� �ٵ����� �׸��� �Լ�
void Draw(); // ���ο� �ٵ��� �׸���
void Count(); // ���� �� ���� ���� ������ ���� �Լ�
void Input(); // �ٵϵ��� ���� ��ǥ�� �Է¹޴� �Լ�
void Check_XY(); // 0 ~ 18 ������ ���� �Է¹޴� �Լ�

unsigned char Go[19][19]; // 19*19 �ٵ��� ���
unsigned int Turn = 0, CntWhite = 0, CntBlack = 0; // ��/�� ���� flag, ��/�� ���� ���� �����
unsigned int i = 0, j = 0;

void main()
{
	InitGo(); // ó�� �ٵ����� �׸��� �Լ�
	Draw();

	while (1)
	{

		Input(); // �ٵϵ��� ���� ��ǥ�� �Է¹޴� �Լ�
		Check_XY(); // 0 ~ 18 ������ ���� �Է¹޴� �Լ�

		if (Go[i][j] != '+') // ���� ��ġ�� ���̴� ���� ����
		{
			printf("\n�̹� ���� ���� �ֽ��ϴ�.");
			Sleep(1000); // 1�ʰ� ���
		}

		else	Count(); // ���� �� ���� ���� ������ ���� �Լ�

		system("cls"); // ȭ�� Ŭ����
		Draw(); // ���ο� �ٵ��� �׸���
	}
}

void Draw()
{
	for (int a = 0; a < 19; a++)
	{
		for (int b = 0; b < 19; b++)
		{
			printf("%c", Go[a][b]);
		}
		printf("\n");
	}
}

void Count()
{
	if (Turn == 0)
	{
		Go[i][j] = 'B';
		Turn = 1;
		CntBlack++;
	}
	else
	{
		Go[i][j] = 'W';
		Turn = 0;
		CntWhite++;
	}
}

void InitGo()
{
	for (int a = 0; a < 19; a++)
	{
		for (int b = 0; b < 19; b++)
		{
			Go[a][b] = '+';
		}
	}
}

void Input()
{
	printf("\n < �� : %d, ������ : %d > \n\n", CntWhite, CntBlack);
	if (Turn == 0) 		printf("[������] �����Դϴ�. \n\n");
	else printf("[���] �����Դϴ�. \n\n");
	printf("���� ���� ��ǥ�� �Է����ּ���. \n\nx ��ǥ : ");
	scanf("%d", &i);
	printf("y ��ǥ : ");
	scanf("%d", &j);
}

void Check_XY()
{
	if (i > 18)
	{
		printf("\n0 ~ 18 ������ ���� �Է����ּ���\n");
		Sleep(1000);
		system("cls");
		Draw();
		Input();
	}

	else if (j > 18)
	{
		printf("\n0 ~ 18 ������ ���� �Է����ּ���\n");
		Sleep(1000);
		system("cls");
		Draw();
		Input();
	}
}