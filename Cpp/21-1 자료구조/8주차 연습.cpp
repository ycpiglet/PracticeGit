// 2014132035  ����ö
// 21.03.16 2���� ���� ����

#include <stdio.h>
#include <Windows.h>

void DrawLine();
void Input();
void Draw();
void Mark();
void Check_RowColumn();
void Check_Stone();

unsigned char Go[19][19];
unsigned int Row, Column, Turn, CntBlack, CntWhite;

void main()
{
	DrawLine();
	Draw();

	while (1)
	{
		Input();
		Check_RowColumn();
		Check_Stone();
		system("cls");
		Draw();
	}

}

void DrawLine()
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
	printf("��(Row) ��ǥ :");
	scanf("%d", &Row);
	printf("��(Column) ��ǥ :");
	scanf("%d", &Column);
}

void Mark()
{
	if (Turn == 0)
	{
		Go[Row][Column] = 'B';
		CntBlack++;
		Turn = 1;
	}
	else
	{
		Go[Row][Column] = 'W';
		CntWhite++;
		Turn = 0;
	}
}

void Check_RowColumn()
{
	if (Row > 18)
	{
		printf("\n");
		printf("0 ~ 18 ������ ���� �Է����ּ���.");
		printf("\n");
		Sleep(1000);
		system("cls");
		Draw();
		Input();
	}


	else if (Column > 18)
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
	if (Go[Row][Column] != '+')
	{
		printf("\n");
		printf("�̹� ���� �����ֽ��ϴ�.");
		printf("\n");
		Sleep(1000);
	}

	else Mark();
}