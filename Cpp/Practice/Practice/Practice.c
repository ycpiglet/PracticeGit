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
	struct ProductInfo product[Amount] = { { 100, "사과", 1500 },{ 200, "복숭아", 3000 }, { 300, "파인애플", 4000} };

	for (int i = 0; i < Amount; i++) {
		printf("------------------------\n");
		printf("------------------------\n");
		if (product[i].num != 0) {
			printf("상품번호 : %d\n", product[i].num);
			printf("상품명   : %s\n", product[i].name);
			printf("상품가격 : %d\n", product[i].cost);
		}
		else printf("등록되지 않은 상품입니다!\n"); 
	}
	
	swap(&product[0], &product[1]);

	for (int i = 0; i < Amount; i++) {
		printf("------------------------\n");
		printf("------------------------\n");
		if (product[i].num != 0) {
			printf("상품번호 : %d\n", product[i].num);
			printf("상품명   : %s\n", product[i].name);
			printf("상품가격 : %d\n", product[i].cost);
		}
		else printf("등록되지 않은 상품입니다!\n"); 
	}
	
	return 0;
}