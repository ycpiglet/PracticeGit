// 2014132035  정윤철
// 21.03.16 2주차 과제 제출

#include <stdio.h>
#include <Windows.h>
#include <string.h>

void InitGo();
void Input();
void Draw();
void Mark();
void Check_XY();
void Check_Stone();

unsigned char Go[19][19];
unsigned int X, Y, Turn, CntBlack, CntWhite;
int CntBlack_Row, CntWhite_Row, CntBlack_Col, CntWhite_Col; // 
int Row_B[19], Row_W[19], Column_B[19], Column_W[19], Diagonal_R[19], Diagonal_L[19]; // 가로, 세로, 대각선 합
int X_old, Y_old, Long;
int Count_B, Count_W, Long_B_Row[19], Long_W_Row[19], Long_B_Col[19], Long_W_Col[19];

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
		for (int i = 0; i < 19; i++) {
			Count_B = 0;
			Count_W = 0;
			for (int j = 0; j < 19; j++) {
				
				if (Go[i][j] == 'B') {
					Count_B++;
					Count_W = 0;
					if (Long_B_Row[i] < Count_B) Long_B_Row[i] = Count_B;
				}
				else if (Go[i][j] == 'W') {
					Count_W++;
					Count_B = 0;
					if (Long_W_Row[i] < Count_W) Long_W_Row[i] = Count_W;
				}
			}
		}

		for (int i = 0; i < 19; i++) {
			Count_B = 0;
			Count_W = 0;
			for (int j = 0; j < 19; j++) {
				
				if (Go[j][i] == 'B') {
					Count_B++;
					Count_W = 0;
					if (Long_B_Col[i] < Count_B) Long_B_Col[i] = Count_B;
				}
				else if (Go[j][i] == 'W') {
					Count_W++;
					Count_B = 0;
					if (Long_W_Col[i] < Count_W) Long_W_Col[i] = Count_W;
				}
			}
		}
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
		printf("	<가로줄 %d>  흰돌 : %d,  검은돌 : %d, \t<세로줄 %d>  흰돌 : %d, 검은돌  : %d, \t가로연속 : ", i, Row_W[i], Row_B[i], i, Column_W[i], Column_B[i]);
		if (Long_B_Row[i] == Long_W_Row[i]) printf("%d개 , 세로연속 :\t", Long_B_Row[i]);
		else if (Long_B_Row[i] > Long_W_Row[i]) printf("흑 %d, 세로연속 :\t", Long_B_Row[i]);
		else printf("백 %d, 세로연속	 :\t", Long_W_Row[i]);

		if (Long_B_Col[i] == Long_W_Col[i]) printf("%d개 , ", Long_B_Col[i]);
		else if (Long_B_Col[i] > Long_W_Col[i]) printf("흑 %d, ", Long_B_Col[i]);
		else printf("백 %d, ", Long_W_Col[i]);
		
		for(int i=0;i<19)
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
	printf("X 좌표 :");
	scanf("%d", &Y);
	printf("Y 좌표 :");
	scanf("%d", &X);
}

void Mark()
{
	if (Turn == 0)
	{
		Go[X][Y] = 'B';
		Row_B[X]++;
		Column_B[Y]++;
		CntBlack++;
		Turn = 1;
	}
	else
	{
		Go[X][Y] = 'W';
		Row_W[X]++;
		Column_W[Y]++;
		CntWhite++;
		Turn = 0;
	}
}

void Check_XY()
{
	if (X > 18)
	{
		printf("\n");
		printf("0 ~ 18 사이의 값을 입력해주세요.");
		printf("\n");
		Sleep(1000);
		system("cls");
		Draw();
		Input();
	}


	else if (Y > 18)
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
	if (Go[X][Y] != '+')
	{
		printf("\n");
		printf("이미 돌이 놓여있습니다.");
		printf("\n");
		Sleep(1000);
	}

	else Mark();
}