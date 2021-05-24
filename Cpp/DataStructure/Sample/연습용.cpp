/* ���� ���� */

#include <stdio.h> // ǥ�� �����
#include <Windows.h> // system("cls");
#include <conio.h> // 

/* ���� ����, ��� ���� */

#define ROW 19
#define COLUMN 19

unsigned int GO[ROW][COLUMN], Matrix[ROW*COLUMN][3];
unsigned int Row, Column, KEY, CntBlack[3], CntWhite[3], max[2];
bool Turn = TRUE;

/* �ٵ��� �׸��� �Լ� */
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

/* Ű���� Enter �Է� ����ϴ� �Լ� */
void KeyInput() {
	while(1) {
		KEY = _getch();
		if (KEY == 13) return;
	}
}

/* �������� ���� ���� ���� ����ϴ� �Լ� */
void Max() {
	// ���� üũ
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
			printf("�浹�� �������� ������ �ֽ��ϴ�. \n");
			}

			else if (GO[i][j] + GO[i][j + 1] == 4) {
			CntBlack[0] = 0;
			CntWhite[0]++;
			printf("�鵹�� �������� ������ �ֽ��ϴ�. \n");*/
		}
	}


	// ���� ���� ���� �����ΰ�?
	for (int i = 0; i < 3; i++) {
		if (CntBlack[i] > max[0]) max[0] = CntBlack[i];
		if (CntWhite[i] > max[1]) max[1] = CntWhite[i];
	}
	printf("\n���ӵ� �浹�� �ִ� ���� : %d\n", max[0]);
	printf("���ӵ� �鵹�� �ִ� ���� : %d\n", max[1]);
	KeyInput();
}

/* ��ǥ �Է¹޴� �Լ� */
void Input() {
	if (Turn) printf("\"��\" �����Դϴ�. ��ǥ�� �Է����ּ���. \n\n");
	else printf("\"��\" �����Դϴ�. ��ǥ�� �Է����ּ���. \n\n");

	printf("��(Row)�� ��ǥ�� �Է��ϼ��� : ");
	scanf("%d", &Row);
	printf("��(Col)�� ��ǥ�� �Է��ϼ��� : ");
	scanf("%d", &Column);

	if (GO[Row][Column] == 0) {
		if (Turn) GO[Row][Column] = 1;
		else GO[Row][Column] = 2;

		Max();
		Turn = !Turn; // ��, �� ���� �ٲٱ�
	}
	else {
		printf("\n�̹� ������ �ֽ��ϴ�. �ٽ� �Է����ּ���. ");
		KeyInput();
	}

	
}



void draw_check01(int c, int r); // ��ǥ �׸��� �Լ�

void main() {

	//draw_check01(19, 19);
	
	DrawLine();
	
	while (1) { // �ݺ� ����
		
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