#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "LOLDIC.txt"

int main(int argc , char *argv[]) { 
	FILE *file; file = fopen(FILENAME , "r"); 
	clock_t start1, end1;
	float res1;
	int i;

	printf("%6s%6s%6s%6s\n", "������", "�̸�", "ü��", "���ݷ�", "����");

	start1 = clock();
	if (file == NULL) { 
		printf("%s: ������ ������ �ʽ��ϴ�.\n" , FILENAME); 
		return 0;
	} 

	while(1) { 
		int iValue = fgetc(file);
		if (iValue == EOF) break;
		else printf("%c" , iValue);
	} 

	printf("\n");
	fclose(file);
	end1 = clock();
	res1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("�ҿ�� �ð� : %.5f", res1);

	return 0; 
}