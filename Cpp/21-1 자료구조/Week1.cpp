#include <stdio.h> // 표준입출력 헤더파일
#include <Windows.h> // Windows API 헤더파일

void printAStar();
void printStars(int Limit);
void recursiveStar(int Limit, int Index);

void main()
{
	//Answer1
	/*int Limit=4;
	for (int i = 0; i < Limit; i++)
	{
		for (int j = 0; j < Limit; j++)
		{
			if (j <= i) printf("*");
		}
		Sleep(1000);
		printf("\n");
	}*/
	
	//Answer2
	/*int Limit;
	printf("*을 반복시키고 싶은 만큼의 숫자를 적으시오 : ");
	scanf("%d", &Limit);
	for (int i = 0; i < Limit; i++)
	{
		for (int j = 0; j < Limit; j++)
		{
			if (j <= i) printf("*");
		}
		Sleep(1000);
		printf("\n");
	}*/

	//Answer3
	/*int Limit;
	printf("*을 반복시키고 싶은 만큼의 숫자를 적으시오 : ");
	scanf("%d", &Limit);
	for (int i = 0; i < Limit; i++)
	{
		int k = 1;
		for (int j = 0; j < Limit; j++)
		{
			if (j <= i) printf("%d", k);
			k++;
		}
		Sleep(1000);
		printf("\n");
	}*/

	//Answer4
	/*int Limit;
	printf("*을 반복시키고 싶은 만큼의 숫자를 적으시오 : ");
	scanf("%d", &Limit);
	for (int i = 0; i < Limit; i++)
	{
		for (int j = 0; j < Limit; j++)
		{
			if (j <= i) printAStar();
		}
		Sleep(1000);
		printf("\n");
	}*/

	//Answer5
	/*int Limit;
	printf("*을 반복시키고 싶은 만큼의 숫자를 적으시오 : ");
	scanf("%d", &Limit);
	printStars(Limit);*/

	//Answer6
	int Limit;
	printf("*을 반복시키고 싶은 만큼의 숫자를 적으시오 : ");
	scanf("%d", &Limit);
	recursiveStar(Limit, 1);
}

void printAStar()
{
	printf("*");
}

void printStars(int Limit)
{
	for (int i = 0; i < Limit; i++)
	{
		for (int j = 0; j < Limit; j++)
		{
			if (j <= i) printf("*");
		}
		Sleep(1000);
		printf("\n");
	}
}

void recursiveStar(int Limit, int Index)
{
	if (Index > Limit)
		return;

	else
	{
		for (int i = 0; i < Index; i++)
		{
			printf("*");
		}
		Sleep(1000);
		printf("\n");
		recursiveStar(Limit, Index+1);
	}
}