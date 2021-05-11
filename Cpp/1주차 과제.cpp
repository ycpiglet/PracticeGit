// 2014132035 정윤철
// 2021.03.09.화요일 (자료구조)

#include <stdio.h>
//#include <Windows.h>
#include <stdlib.h>

void printAStar();
void printStars(int Limit);
void recursiveStar(int Limit, int Index);

void main()
{
	//Answer1
	int Limit = 4;
	for (int i = 0; i < Limit; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		_sleep(1000);
		printf("\n");
	}

	//Answer2
	/*int Limit;
	printf("출력할 Asterisk의 갯수를 입력하시오 : ");
	scanf_s("%d", &Limit);
	for (int i = 0; i < Limit; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		Sleep(1000);
		printf("\n");
	}*/

	//Answer3
	/*int Limit;
	printf("출력할 숫자열의 갯수를 입력하시오 : ");
	scanf_s("%d", &Limit);
	for (int i = 0; i < Limit; i++)
	{
		int k = 1;
		for (int j = 0; j <= i; j++)
		{

			printf("%d", k);
			k++;
		}
		Sleep(1000);
		printf("\n");
	}*/


	//Answer4
	/*int Limit;
	printf("출력할 Asterisk의 갯수를 입력하시오 : ");
	scanf_s("%d", &Limit);
	for (int i = 0; i < Limit; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printAStar();
		}
		Sleep(1000);
		printf("\n");
	}*/

	//Answer5
	/*int Limit;
	printf("출력할 Asterisk의 갯수를 입력하시오 : ");
	scanf_s("%d", &Limit);
	printStars(Limit);*/

	//Answer6
	/*int Limit;
	printf("출력할 Asterisk의 갯수를 입력하시오 : ");
	scanf_s("%d", &Limit);
	recursiveStar(Limit, 1);*/
}

//void printAStar()
//{
//	printf("*");
//}
//
//void printStars(int Limit)
//{
//	for (int i = 0; i < Limit; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printAStar();
//		}
//		Sleep(1000);
//		printf("\n");
//	}
//}
//
//void recursiveStar(int Limit, int Index)
//{
//	if (Limit < Index)
//		return;
//
//	else
//	{
//		for (int i = 0; i < Index; i++)
//		{
//			printf("*");
//		}
//		Sleep(1000);
//		printf("\n");
//		recursiveStar(Limit, Index + 1);
//	}
//}