#include <stdio.h>
#include <Windows.h>

#define OBJ 'C' // � ���ڸ� �̵���ų ���ΰ�?
#define BREADTH 80 // ���η� ��ŭ �̵���ų ���ΰ�?

void main()
{
	int k=0, j = 0;
	char ch;
	
	while (j < BREADTH) { // 5. �ܰ� 1~4�� BREADTH ��ŭ �ݺ��Ѵ�.
		scanf("%c", &ch);
		system("cls"); // 1. ȭ���� �����.
		printf("Enter ���� Ƚ�� : %d \n", k);
		if (ch == 10)
		{
			k++;
			for (int i = 0; i < j; i++) { // 2. ������ ������ j�� ��ŭ ����Ѵ�.
				printf(" ");
			} // end of for
			printf("%C", OBJ); // 3. ���ڸ� ����Ѵ�.
			j++; // 2. ������ ������ �ϳ� �ø���.
			Sleep(100); // �ʹ� ������ ��� ����. ��, �̵� �ӵ��� �����Ѵ�.
		}
	} // end of while
}

// d�� ������ �����̰�
// ȭ��ǥ�� ������ �����ϰ�
// Enter Ű�� �� ������ �����ϰԲ�
// ��, �Ʒ��� �����̰Բ� 