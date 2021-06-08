#include <stdio.h>
#include <string.h>

int main() {

	char a[10] = "Apple";
	char b[10] = "Banana";
	char temp[10];

	printf("--------------------------\n");
	printf("<���� �� ����>\n");
	printf("ù ��° ���� : %s\n", a);
	printf("�� ��° ���� : %s\n", b);
	printf("-------------------------\n");

	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);

	printf("--------------------------\n");
	printf("<1. strcpy�� ���� ��>\n");
	printf("ù ��° ���� : %s\n", a);
	printf("�� ��° ���� : %s\n", b);
	printf("-------------------------\n");

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

	return 0;
}