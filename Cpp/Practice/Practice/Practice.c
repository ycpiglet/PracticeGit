#include <stdio.h> // standard input output
#include <string.h> // string library
#include <conio.h> //

#define Amount 5

struct ProductInfo {
	int num;
	char name[100];
	int cost;
};

void swap(struct ProductInfo *p, struct ProductInfo *q) {
	struct ProductInfo tmp = *p;
	*p = *q;
	*q = tmp;
}

void key() {
	_getch();

}

int main() {
	struct ProductInfo product[Amount] = { { 100, "���", 1500 },{ 200, "������", 3000 }, { 300, "���ξ���", 4000} };

	for (int i = 0; i < Amount; i++) {
		printf("------------------------\n");
		printf("------------------------\n");
		if (product[i].num != 0) {
			printf("��ǰ��ȣ : %d\n", product[i].num);
			printf("��ǰ��   : %s\n", product[i].name);
			printf("��ǰ���� : %d\n", product[i].cost);
		}
		else printf("��ϵ��� ���� ��ǰ�Դϴ�!\n"); 
	}
	
	swap(&product[0], &product[1]);

	for (int i = 0; i < Amount; i++) {
		printf("------------------------\n");
		printf("------------------------\n");
		if (product[i].num != 0) {
			printf("��ǰ��ȣ : %d\n", product[i].num);
			printf("��ǰ��   : %s\n", product[i].name);
			printf("��ǰ���� : %d\n", product[i].cost);
		}
		else printf("��ϵ��� ���� ��ǰ�Դϴ�!\n"); 
	}
	
	return 0;
}