#include <stdio.h>
#include <Windows.h>

#define OBJ 'C' // 어떤 문자를 이동시킬 것인가?
#define BREADTH 80 // 가로로 얼만큼 이동시킬 것인가?

void main()
{
	int k=0, j = 0;
	char ch;
	
	while (j < BREADTH) { // 5. 단계 1~4를 BREADTH 만큼 반복한다.
		scanf("%c", &ch);
		system("cls"); // 1. 화면을 지운다.
		printf("Enter 누른 횟수 : %d \n", k);
		if (ch == 10)
		{
			k++;
			for (int i = 0; i < j; i++) { // 2. 공백의 갯수를 j개 만큼 출력한다.
				printf(" ");
			} // end of for
			printf("%C", OBJ); // 3. 문자를 출력한다.
			j++; // 2. 공백의 갯수를 하나 늘린다.
			Sleep(100); // 너무 빠르니 잠깐 쉰다. 즉, 이동 속도를 조절한다.
		}
	} // end of while
}

// d를 누르면 움직이게
// 화살표를 누르면 가능하게
// Enter 키를 안 눌러도 가능하게끔
// 위, 아래로 움직이게끔 