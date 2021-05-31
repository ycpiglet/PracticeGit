#include <stdio.h>
#include <string.h>

void inputFruit(char *fruit1, char *fruit2) {
	printf("ù ��° ���� : ");
	scanf("%s", fruit1);
	printf("�� ��° ���� : ");
	scanf("%s", fruit2);
	printf("\n");
}

void printFruits(char *Fruti1, char *Fruit2) {
	printf("--------------------------\n");
	printf("<���� �� ����>\n");
	printf("ù ��° ���� : %s\n", Fruti1);
	printf("�� ��° ���� : %s\n", Fruit2);
	printf("--------------------------\n");
}

void swapFruits(char *Fruit1, char *Fruit2) {
	char temp[10];
	printf(" strcpy�� ����!!\n");
	strcpy(temp, Fruit1);
	strcpy(Fruit1, Fruit2);
	strcpy(Fruit2, temp);
}

int main() {

	char a[10];
	char b[10];
	char temp[10];

	/* ���� �Է� */
	inputFruit(a, b);

	swapFruits(a, b);
	printFruits(a, b);

	for (int i = 0; i < 10; i++) {
		temp[i] = a[i];
		a[i] = b[i];
		b[i] = temp[i];
	}
	printf("--------------------------\n");
	printf("<2. �迭�� ���� ��>\n");
	printf("ù ��° ���� : %s\n", a);
	printf("�� ��° ���� : %s\n", b);
	printf("-------------------------\n");

	for (int i = 0; i < 10; i++) {
		*(temp + i) = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = *(temp + i);
	}

	printf("--------------------------\n");
	printf("<3. �����ͷ� ���� ��>\n");
	printf("ù ��° ���� : %s\n", a);
	printf("�� ��° ���� : %s\n", b);
	printf("-------------------------\n");

	struct Fruit {
		int number;
		char name[10];
	};

	/* ����ü ����غ��� */
	Fruit c = { 1, "Apple" };
	Fruit d = { 2, "Banana" };
	Fruit tmp;

	printf("-------------------------\n");
	printf("���� ��ȣ : %d, ���� �̸� : %s\n", c.number, c.name);
	printf("���� ��ȣ : %d, ���� �̸� : %s\n", d.number, d.name);
	printf("-------------------------\n");

	tmp = c;
	c = d;
	d = tmp;

	printf("-------------------------\n");
	printf("���� ��ȣ : %d, ���� �̸� : %s\n", c.number, c.name);
	printf("���� ��ȣ : %d, ���� �̸� : %s\n", d.number, d.name);
	printf("-------------------------\n");

	tmp.number = c.number;
	c.number = d.number;
	d.number = tmp.number;

	strcpy(tmp.name, c.name);
	strcpy(c.name, d.name);
	strcpy(d.name, tmp.name);

	printf("-------------------------\n");
	printf("���� ��ȣ : %d, ���� �̸� : %s\n", c.number, c.name);
	printf("���� ��ȣ : %d, ���� �̸� : %s\n", d.number, d.name);
	printf("-------------------------\n");

}

