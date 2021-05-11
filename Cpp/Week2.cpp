// 1. 바둑판을 그린다.
// 2. 바둑돌의 좌표를 입력받는다.
// 3. 0 ~ 18 사이의 값만 입력받는다.
// 4. 같은 위치에 놓이지 않게 한다.
// 5. 놓인 돌의 갯수를 센다
// 6. 새로운 바둑판을 그린다.

#include <stdio.h>
#include <Windows.h>

void InitGo(); // 처음 바둑판을 그리는 함수
void Draw(); // 새로운 바둑판 그리기
void Count(); // 실행 후 놓인 돌의 갯수를 세는 함수
void Input(); // 바둑돌을 놓을 좌표를 입력받는 함수
void Check_XY(); // 0 ~ 18 사이의 값만 입력받는 함수

unsigned char Go[19][19]; // 19*19 바둑판 행렬
unsigned int Turn = 0, CntWhite = 0, CntBlack = 0; // 흑/백 순서 flag, 흑/백 돌의 갯수 세기용
unsigned int i = 0, j = 0;

void main()
{
	InitGo(); // 처음 바둑판을 그리는 함수
	Draw();

	while (1)
	{

		Input(); // 바둑돌을 놓을 좌표를 입력받는 함수
		Check_XY(); // 0 ~ 18 사이의 값만 입력받는 함수

		if (Go[i][j] != '+') // 같은 위치에 놓이는 것을 방지
		{
			printf("\n이미 돌이 놓여 있습니다.");
			Sleep(1000); // 1초간 대기
		}

		else	Count(); // 실행 후 놓인 돌의 갯수를 세는 함수

		system("cls"); // 화면 클리어
		Draw(); // 새로운 바둑판 그리기
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
	printf("\n < 흰돌 : %d, 검은돌 : %d > \n\n", CntWhite, CntBlack);
	if (Turn == 0) 		printf("[검은색] 차례입니다. \n\n");
	else printf("[흰색] 차례입니다. \n\n");
	printf("돌을 놓을 좌표를 입력해주세요. \n\nx 좌표 : ");
	scanf("%d", &i);
	printf("y 좌표 : ");
	scanf("%d", &j);
}

void Check_XY()
{
	if (i > 18)
	{
		printf("\n0 ~ 18 사이의 값을 입력해주세요\n");
		Sleep(1000);
		system("cls");
		Draw();
		Input();
	}

	else if (j > 18)
	{
		printf("\n0 ~ 18 사이의 값을 입력해주세요\n");
		Sleep(1000);
		system("cls");
		Draw();
		Input();
	}
}