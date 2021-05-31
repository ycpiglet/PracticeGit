#include <stdio.h>
#include <string.h>

void inputFruit(char *fruit1, char *fruit2) {
	printf("첫 번째 과일 : ");
	scanf("%s", fruit1);
	printf("두 번째 과일 : ");
	scanf("%s", fruit2);
	printf("\n");
}

void printFruits(char *Fruti1, char *Fruit2) {
	printf("--------------------------\n");
	printf("<변경 후 과일>\n");
	printf("첫 번째 과일 : %s\n", Fruti1);
	printf("두 번째 과일 : %s\n", Fruit2);
	printf("--------------------------\n");
}

void swapFruits(char *Fruit1, char *Fruit2) {
	char temp[10];
	printf(" strcpy로 변경!!\n");
	strcpy(temp, Fruit1);
	strcpy(Fruit1, Fruit2);
	strcpy(Fruit2, temp);
}

int main() {

	char a[10];
	char b[10];
	char temp[10];

	/* 과일 입력 */
	inputFruit(a, b);

	swapFruits(a, b);
	printFruits(a, b);

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

}

