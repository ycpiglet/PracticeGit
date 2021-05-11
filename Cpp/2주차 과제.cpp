// 2014132035  ����ö
// 21.03.16 2���� ���� ����

#include <stdio.h>
#include <Windows.h>

void InitGo();
void Input();
void Draw();
void Mark();
void Check_XY();
void Check_Stone();

unsigned char Go[19][19];
unsigned int X, Y, Turn, CntBlack, CntWhite;

void main()
{
	InitGo();
	Draw();

	while (1)
	{
		Input();
		Check_XY();
		Check_Stone();
		system("cls");
		Draw();
	}

}

void InitGo()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
			Go[i][j] = '+';
	}
}

void Draw()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
			printf("%c", Go[i][j]);
		printf("\n");
	}
}

void Input()
{
	printf("\n< �� : %d, ������ : %d >\n", CntWhite, CntBlack);
	if (Turn == 0) printf("\n[������] �����Դϴ�. \n");
	else printf("\n[���] �����Դϴ�. \n");
	
	printf("\n");
	printf("�ٵϵ��� ���� ��ǥ�� �Է����ּ���. \n\n");
	printf("X ��ǥ :");
	scanf("%d", &X);
	printf("Y ��ǥ :");
	scanf("%d", &Y);
}

void Mark()
{
	if (Turn == 0)
	{
		Go[X][Y] = 'B';
		CntBlack++;
		Turn = 1;
	}
	else
	{
		Go[X][Y] = 'W';
		CntWhite++;
		Turn = 0;
	}
}

void Check_XY()
{
	if (X > 18)
	{
		printf("\n");
		printf("0 ~ 18 ������ ���� �Է����ּ���.");
		printf("\n");
		Sleep(1000);
		system("cls");
		Draw();
		Input();
	}
	

	else if (Y > 18)
	{
		printf("\n");
		printf("0 ~ 18 ������ ���� �Է����ּ���.");
		printf("\n");
		Sleep(1000);
		system("cls");
		Draw();
		Input();
	}
}

void Check_Stone()
{
	if (Go[X][Y] != '+')
	{
		printf("\n");
		printf("�̹� ���� �����ֽ��ϴ�.");
		printf("\n");
		Sleep(1000);
	}

	else Mark();
}