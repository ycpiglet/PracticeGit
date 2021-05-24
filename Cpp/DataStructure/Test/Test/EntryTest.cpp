#include <stdio.h>

struct fruit {
	char name[10];
	int number;
	int year;
};

int main() {
	printf("\n포인터 연습 \n\n");

	int i = 5;
	int *ptr = &i;
	printf("i의 주소 = %p \n", ptr);
	printf("i의 값 = %d \n", i);

	int **dp = &ptr;
	printf("\n\n");
	printf("포인터 변수 prt의 주소 = %p", dp);

	printf("\n\n");
	char a[6] = "Hello";  // char형 배열 6개 만들고, 거기다가 문자열 Hello의 주소값을 대입
	char b[6] = { 'H', 'e', 'l', 'l', 'o' }; // 정석
	printf("문자열 a = %s \n", a);
	printf("문자열 b = %s", b);

	printf("\n\n");
	char *ptr1 = a; // 주소값도 자료형태를 그대로 따라가야한다 
	char *ptr2 = &a[0];
	printf("a의 6번째 원소의 주소 = %p \n", ptr1);

	printf("\n\n");
	char *ptr3 = "Hello"; // ptr3 = Apple 문자열의 시작 주소

	char *f[10]; // 포인터 배열
				 // 배열 포인터는 거의 안 씀

	struct fruit Apple;
	Apple = { "사과", 3, 5 }; // 구조체 초기값 리스트
	Apple.name = "자두";
	Apple.number = 4;
	Apple.year = 6; // 구조체 멤버 접근

	struct fruit *sptr;
	sptr = &Apple;
	sptr->name = "바나나";
	printf("%s \n", sptr->name);




	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");


	return 0;
}

