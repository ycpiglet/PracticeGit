// 2021.06.08(ȭ) �ڷᱸ�� F ���� ����
// (o) 1. words.txt�� ����� ���� �ܾ���� �ܹ��� ���� ����Ʈ�� �����϶�. 
// (x) 2. ���ڿ��� �Է� �޾� �ش� ���ڿ��� �����ϴ� ��� �ܾ �����϶�.
// (x) 3. �� ���� ���ڿ� str1�� str2�� ���� ����Ʈ�� �����ϵ�, str2�� ���ڸ��� �����϶�. ���� st2�� ���� ����Ʈ�� �������� �ʴ� ��쿡�� �� �ڿ� �����϶�. ���� str1�� �̹� ���� ����Ʈ�� �����ϴ� ��쿡�� �޽����� ����ϰ� �������� �ʴ´�.
// (o) 4. ���� ����Ʈ�� �����ϴ� ��ü �ܾ�� �� �ܾ��� ������ ����϶�.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

typedef struct ListNode {
	char data[20];
	struct ListNode* link;
}ListNode;

typedef struct LinkedList_h {
	struct ListNode* head;
}LinkedList_h;


LinkedList_h* createLinkedList();
void printLinkedList(LinkedList_h* L);
void deleteNode(LinkedList_h* L, char* text);
void freeLinkedList(LinkedList_h* L);
void insertFirstNode(LinkedList_h* L, char* text);
void insertNode(LinkedList_h* L, char* existWord, char* newWord);
void key_Enter();

int main() {
	
	LinkedList_h* L = createLinkedList(); // ���� ����Ʈ ����
	FILE* f; // ���� ����
	f = fopen("words.txt", "r"); // ���� ��� : �б�
	int count = 1778; // �ܾ� ����
	int i = 0; // �� ��ȣ
	char str[1778][20];
	while (1) {
		printf("------------------------------------------------------\n");
		printf("�ڷᱸ�� F ���� ����\n");
		printf("1. ���� ����Ʈ �����ϱ�\n");
		printf("2. ���ڿ� �Է¹ް� ���� �����ϱ�\n");
		printf("3. ��� �տ� �����ϱ�\n");
		printf("4. ���� ����Ʈ ����ϱ� (��� �ܾ�, ����)\n");
		printf("------------------------------------------------------\n");

		char existWord[20];
		char newWord[20];

		int option = 10;
		printf("���ϴ� ����� ��ȣ�� �Է����ּ��� : ");
		scanf("%d", &option);
		switch (option) {

		case 1:
			printf("\n1. ���� ����Ʈ �����ϱ�\n\n");
			while (feof(f) == 0) { // �� ������
				fgets(str[i], 20, f); // ���ڿ� �б�
				//printf("%s", str[i]);
				insertFirstNode(L, str[i]);
				i++;
				if (i > 1778) break;
			}
				printf("\n�ܹ��� ���� ����Ʈ�� �����߽��ϴ�.\n\n");
			break;

		case 2:
			printf("\n2. ���ڿ� �Է¹ް� ���� �����ϱ�\n\n");
			printf("������ �ܾ �Է��ϼ��� : ");
			scanf("%s", existWord);
			deleteNode(L, existWord);
			break;

		case 3:
			
			printf("\n3. ��� �տ� �����ϱ�\n\n");
			printf("�������� �� �ܾ �Է��ϼ��� : ");
			scanf("%s", existWord);
			printf("���� �Է��� �ܾ �Է��ϼ��� : ");
			scanf("%s", newWord);
			insertNode(L, existWord, newWord);
			break;

		case 4:
			printf("\n4. ���� ����Ʈ ����ϱ� (��� �ܾ�, ����)\n\n");
			printLinkedList(L);
			break;

		default:
			printf("\n���� ��ȣ�Դϴ�.\n");
			break;
		}
		key_Enter();
		system("cls");
	}
	
	printf("\n\n");
	fclose(f); // ���� �ݱ�
	freeLinkedList(L); // ���� ����Ʈ ����
	return 0; // ����
}

LinkedList_h* createLinkedList()
{
	LinkedList_h* L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	L->head = NULL;
	return L;
}

void printLinkedList(LinkedList_h* L)
{
	int count = 0;
	ListNode* p = L->head;
	while (p != NULL) {
		printf("%d. %s", count, p->data);
		p = p->link;
		count++;
	}
	printf("��ü ���� : %d\n\n", count);
}

void deleteNode(LinkedList_h* L, char* text)
{
	ListNode* p = L->head;
	ListNode* temp;
	while (p->link != NULL) {
		temp = p->link;
		if (strcmp(p->link->data, text) == 0) {
			p->link = p->link->link; // ���� ���� ����
			free(temp);
			printf("\n%s�� �����߽��ϴ�.\n", text);
			return;
		}
		//else {
		//	printf("\n�׷� �ܾ�� �����ϴ�.\n");
		//	return;
		//}
		p = p->link;
	}
}

void freeLinkedList(LinkedList_h* L)
{
	ListNode* p = L->head;
	ListNode* pre;
	while (p->link != NULL) {
		pre = p;
		p = p->link;
		free(pre);
	}
	printf("\n���� ����Ʈ ����\n");
}

void insertFirstNode(LinkedList_h* L, char* text)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, text);
	newNode->link = L->head;
	L->head = newNode;
}

void insertNode(LinkedList_h* L, char* existWord, char* newWord)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* p = L->head;
	ListNode* pre;
	ListNode* sub;
	printf("%s %s", existWord, newWord);
	strcpy(newNode->data, newWord); // ���ڿ� ����
	while (p != NULL) {
		printf("�۵���\n");
		pre = p;
		sub = p->link;
		if (strcmp(sub->data, newWord) == 0) { // �ܾ �̹� �����ϸ�
			printf("\n�̹� �����ϴ� �ܾ��Դϴ�.\n");
		}

		else if (strcmp(sub->data, existWord) == 0) { // �ܾ ��ġ�ϸ�
			pre->link = newNode;
			newNode->link = sub; // ��ũ ����
			printf("\n������ �Ϸ��߽��ϴ�.\n");
			return;
		}

		if (p->link == NULL) { // ���� �ܾ ������
			p->link = newNode;
			newNode->link = NULL;
			printf("\n�� �ڿ� �����߽��ϴ�.\n");
		}

		p = p->link; // ���� ������ �̵�
	}
	printf("\n�׷� �ܾ�� �����ϴ�.\n");
}

void key_Enter()
{
	printf("\n            (Enter)�� �Է��ϼ���.\n");
	int key = _getch();
	while (key != 13) {
		if (key == 13) return;
		printf("            (Enter)�� �Է��ϼ���.\n");
	}
}
