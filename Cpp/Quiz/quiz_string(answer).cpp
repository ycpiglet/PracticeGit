#include <stdio.h>
#include <string.h>

int main() {

	char a[10] = "Apple";
	char b[10] = "Banana";
	char temp[10];

	printf("--------------------------\n");
	printf("<변경 전 과일>\n");
	printf("첫 번째 과일 : %s\n", a);
	printf("두 번째 과일 : %s\n", b);
	printf("-------------------------\n");

	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);

	printf("--------------------------\n");
	printf("<1. strcpy로 변경 후>\n");
	printf("첫 번째 과일 : %s\n", a);
	printf("두 번째 과일 : %s\n", b);
	printf("-------------------------\n");

	for (int i = 0; i < 10; i++) {
		temp[i] = a[i];
		a[i] = b[i];
		b[i] = temp[i];
	}
	printf("--------------------------\n");
	printf("<2. 배열로 변경 후>\n");
	printf("첫 번째 과일 : %s\n", a);
	printf("두 번째 과일 : %s\n", b);
	printf("-------------------------\n");

	for (int i = 0; i < 10; i++) {
		*(temp + i) = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = *(temp + i);
	}

	printf("--------------------------\n");
	printf("<3. 포인터로 변경 후>\n");
	printf("첫 번째 과일 : %s\n", a);
	printf("두 번째 과일 : %s\n", b);
	printf("-------------------------\n");

	struct Fruit {
		int number;
		char name[10];
	};

	/* 구조체 사용해보기 */
	Fruit c = { 1, "Apple" };
	Fruit d = { 2, "Banana" };
	Fruit tmp;

	printf("-------------------------\n");
	printf("과일 번호 : %d, 과일 이름 : %s\n", c.number, c.name);
	printf("과일 번호 : %d, 과일 이름 : %s\n", d.number, d.name);
	printf("-------------------------\n");

	tmp = c;
	c = d;
	d = tmp;

	printf("-------------------------\n");
	printf("과일 번호 : %d, 과일 이름 : %s\n", c.number, c.name);
	printf("과일 번호 : %d, 과일 이름 : %s\n", d.number, d.name);
	printf("-------------------------\n");

	tmp.number = c.number;
	c.number = d.number;
	d.number = tmp.number;

	strcpy(tmp.name, c.name);
	strcpy(c.name, d.name);
	strcpy(d.name, tmp.name);

	printf("-------------------------\n");
	printf("과일 번호 : %d, 과일 이름 : %s\n", c.number, c.name);
	printf("과일 번호 : %d, 과일 이름 : %s\n", d.number, d.name);
	printf("-------------------------\n");

	return 0;
}