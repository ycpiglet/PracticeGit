#include <stdio.h>

struct fruit {
	char name[10];
	int number;
	int year;
};

int main() {
	printf("\n������ ���� \n\n");

	int i = 5;
	int *ptr = &i;
	printf("i�� �ּ� = %p \n", ptr);
	printf("i�� �� = %d \n", i);

	int **dp = &ptr;
	printf("\n\n");
	printf("������ ���� prt�� �ּ� = %p", dp);

	printf("\n\n");
	char a[6] = "Hello";  // char�� �迭 6�� �����, �ű�ٰ� ���ڿ� Hello�� �ּҰ��� ����
	char b[6] = { 'H', 'e', 'l', 'l', 'o' }; // ����
	printf("���ڿ� a = %s \n", a);
	printf("���ڿ� b = %s", b);

	printf("\n\n");
	char *ptr1 = a; // �ּҰ��� �ڷ����¸� �״�� ���󰡾��Ѵ� 
	char *ptr2 = &a[0];
	printf("a�� 6��° ������ �ּ� = %p \n", ptr1);

	printf("\n\n");
	char *ptr3 = "Hello"; // ptr3 = Apple ���ڿ��� ���� �ּ�

	char *f[10]; // ������ �迭
				 // �迭 �����ʹ� ���� �� ��

	struct fruit Apple;
	Apple = { "���", 3, 5 }; // ����ü �ʱⰪ ����Ʈ
	Apple.name = "�ڵ�";
	Apple.number = 4;
	Apple.year = 6; // ����ü ��� ����

	struct fruit *sptr;
	sptr = &Apple;
	sptr->name = "�ٳ���";
	printf("%s \n", sptr->name);




	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");


	return 0;
}

