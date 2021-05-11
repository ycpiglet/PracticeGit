// 2014132035  정윤철
// 21.03.16 2주차 과제 제출

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
	printf("\n< 흰돌 : %d, 검은돌 : %d >\n", CntWhite, CntBlack);
	if (Turn == 0) printf("\n[검은색] 차례입니다. \n");
	else printf("\n[흰색] 차례입니다. \n");

	printf("\n");
	printf("바둑돌을 놓을 좌표를 입력해주세요. \n\n");
	printf("행(Row) 좌표 :");
	scanf("%d", &Row);
	printf("열(Column) 좌표 :");
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
		printf("0 ~ 18 사이의 값을 입력해주세요.");
		printf("\n");
		Sleep(1000);
		system("cls");
		Draw();
		Input();
	}


	else if (Column > 18)
	{
		printf("\n");
		printf("0 ~ 18 사이의 값을 입력해주세요.");
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
		printf("이미 돌이 놓여있습니다.");
		printf("\n");
		Sleep(1000);
	}

	else Mark();
}