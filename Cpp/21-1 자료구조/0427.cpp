/* 오목 게임 */

#include <stdio.h> // 표준 입출력
#include <Windows.h> // system("cls");
#include <conio.h> // 

/* 전역 변수, 상수 설정 */

#define ROW 19
#define COLUMN 19

unsigned int GO[ROW][COLUMN], Matrix[ROW*COLUMN][3];
unsigned int Row, Column, KEY, CntBlack[3], CntWhite[3], max[2];
bool Turn = TRUE;

/* 바둑판 그리는 함수 */
void DrawLine() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if(GO[i][j] == 0) printf("+");
			else if (GO[i][j] == 1) printf("B");
			else if (GO[i][j] == 2) printf("W");
		}
		printf("\n");
	}
	printf("\n");
}

/* 키보드 Enter 입력 대기하는 함수 */
void KeyInput() {
	while(1) {
		KEY = _getch();
		if (KEY == 13) return;
	}
}

/* 연속으로 놓인 돌의 갯수 출력하는 함수 */
void Max() {
	// 가로 체크
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN - 1; j++) {
			if (GO[i][j] == 1) {
				if (GO[i][j + 1] == 2) CntBlack[0] = 7;

				else if (GO[i][j + 1] == 0) {
					if (GO[i][j + 2] == 1) CntBlack[0]++;
					else CntBlack[0] = 0;
				}

				else CntBlack[0]++;
			}

			else if (GO[i][j] == 2) {
				if (GO[i][j + 1] == 1) CntWhite[0] = 0;

				else if (GO[i][j + 1] == 0) {
					if (GO[i][j + 2] == 1) CntWhite[0]++;
					else CntWhite[0] = 0;
				}

				else CntWhite[0]++;
			}

			/*else if (GO[i][j] + GO[i][j + 1] == 2) {
			CntWhite[0] = 0;
			CntBlack[0]++;
			printf("흑돌이 연속으로 놓여져 있습니다. \n");
			}

			else if (GO[i][j] + GO[i][j + 1] == 4) {
			CntBlack[0] = 0;
			CntWhite[0]++;
			printf("백돌이 연속으로 놓여져 있습니다. \n");*/
		}
	}


	// 제일 많은 것은 무엇인가?
	for (int i = 0; i < 3; i++) {
		if (CntBlack[i] > max[0]) max[0] = CntBlack[i];
		if (CntWhite[i] > max[1]) max[1] = CntWhite[i];
	}
	printf("\n연속된 흑돌의 최대 갯수 : %d\n", max[0]);
	printf("연속된 백돌의 최대 갯수 : %d\n", max[1]);
	KeyInput();
}

/* 좌표 입력받는 함수 */
void Input() {
	if (Turn) printf("\"흑\" 차례입니다. 좌표를 입력해주세요. \n\n");
	else printf("\"백\" 차례입니다. 좌표를 입력해주세요. \n\n");

	printf("행(Row)의 좌표를 입력하세요 : ");
	scanf("%d", &Row);
	printf("열(Col)의 좌표를 입력하세요 : ");
	scanf("%d", &Column);

	if (GO[Row][Column] == 0) {
		if (Turn) GO[Row][Column] = 1;
		else GO[Row][Column] = 2;

		Max();
		Turn = !Turn; // 흑, 백 차례 바꾸기
	}
	else {
		printf("\n이미 놓여져 있습니다. 다시 입력해주세요. ");
		KeyInput();
	}

	
}



void draw_check01(int c, int r); // 좌표 그리기 함수

void main() {

	//draw_check01(19, 19);
	
	DrawLine();
	
	while (1) { // 반복 실행
		
		Input();
		
		//KeyInput();
		system("cls");
		DrawLine();
	}
}

void draw_check01(int c, int r)

{

	int i, j;

	unsigned char a = 0xa6;

	unsigned char b[12];

	for (i = 1; i < 12; i++)

		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);

	for (i = 0; i < c - 1; i++)

		printf("%c%c", a, b[8]);

	printf("%c%c", a, b[4]);

	printf("\n");

	for (i = 0; i < r - 1; i++)

	{

		printf("%c%c", a, b[7]);

		for (j = 0; j < c - 1; j++)

			printf("%c%c", a, b[11]);

		printf("%c%c", a, b[9]);

		printf("\n");

	}

	printf("%c%c", a, b[6]);

	for (i = 0; i < c - 1; i++)

		printf("%c%c", a, b[10]);

	printf("%c%c", a, b[5]);

	printf("\n");

}