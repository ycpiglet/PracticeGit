/* �ܼ� ���� ����Ʈ */
#define _CRT_SECURE_NO_WARNINGS
#define PRINT printf("It it working!!\n");
#define DEVIDE printf("----------------------------------------------------\n");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


/* ����ü ���� */
typedef struct listNode
{
	char data[10];
	struct listNode* link;
}listNode;

typedef struct
{
	listNode* head;
}linkedList_h;


/* �Լ� ���� */
linkedList_h* createLinkedList();
void freeLinkedList(linkedList_h* L);
void printLinkedList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, char* text);
void insertMiddleNode(linkedList_h* L, listNode* pre, char* text);
void insertLastNode(linkedList_h* L, char* text);
void deleteNode(linkedList_h* L, listNode* p);
void sortAscending(linkedList_h* L);
listNode* searchNode(linkedList_h* L, char* text);
void reverse(linkedList_h* L);
void key_Enter();
void visualizeLinkedList(linkedList_h* L);



/* main�� */
int main() {

	int option = 9;
	char data[10], data_pre[10];
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	listNode* pre = data;

	while (1) {
		printf("< �ܼ� ���� ����Ʈ(Singly Linked List) ���α׷��Դϴ�. >\n");
		DEVIDE;
		printf("0. �ܼ� ���� ����Ʈ �����ϱ�\n");
		printf("1. ù ��° ��忡 �����ϱ�\n");
		printf("2. Ư�� ��� �ڿ� �����ϱ�\n");
		printf("3. ������ ��忡 �����ϱ�\n");
		printf("4. ��� ������� ����ϱ�\n");
		printf("5. Ư�� ��� �˻��ϱ�\n");
		printf("6. Ư�� ��� �����ϱ�\n");
		printf("7. ���� ���� ������\n");
		printf("8. ������������ �����ϱ�\n");
		printf("9. �ܼ� ���� ����Ʈ �����ϱ�\n");
		DEVIDE;
		if((L != data) && (option != 9)) visualizeLinkedList(L);
		printf("\n�� �ɼ� �߿��� �������ּ���. : ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:
			L = createLinkedList();
			printf("\n�ܼ� ���� ����Ʈ�� �����Ǿ����ϴ�!\n");
			break;
		case 1:
			printf("- ���� ������ ��忡 �� Data�� �����ּ���. : ");
			scanf("%s", data);
			insertFirstNode(L, data);
			printf("\n��� ������ �Ϸ�Ǿ����ϴ�.\n");
			break;

		case 2:
			printf("- ���� ������ ��忡 �� Data�� �����ּ���. : ");
			scanf("%s", data);
			printf("- �߰��ϰ� ���� ��ġ�� ��忡 �� Data�� �����ּ���. : ");
			scanf("%s", data_pre);
			pre = searchNode(L, data_pre);
			insertMiddleNode(L, pre, data);
			printf("\n��� ������ �Ϸ�Ǿ����ϴ�.\n");
			break;

		case 3:
			printf("- ���� ������ ��忡 �� Data�� �����ּ���. : ");
			scanf("%s", data);
			insertLastNode(L, data);
			printf("\n��� ������ �Ϸ�Ǿ����ϴ�.\n");
			break;

		case 4:
			printLinkedList(L);
			break;

		case 5:
			printf("- �˻��� ����� Data�� �����ּ���. : ");
			scanf("%s", data);
			pre = searchNode(L, data);
			printf("\n��� �˻��� �Ϸ�Ǿ����ϴ�.\n");
			break;

		case 6:
			printf("- ������ ����� Data�� �����ּ���. : ");
			scanf("%s", data);
			deleteNode(L, data);
			printf("\n��� ������ �Ϸ�Ǿ����ϴ�.\n");
			break;

		case 7:
			reverse(L);
			printf("\n���� ����Ʈ�� ������ �ٲ�����ϴ�.\n");
			break;

		case 8:
			sortAscending(L);
			printf("\n��� ��带 ������������ �����߽��ϴ�!!\n");
			break;

		case 9:
			freeLinkedList(L);
			printf("\n���� ����Ʈ�� ��� �����߽��ϴ�!!\n");
			break;

		default:
			printf("���� ��ȣ�Դϴ�. ��Ȯ�� �Է����ּ���!\n");
			break;
		}
		key_Enter();
		system("cls");
	}

	freeLinkedList(L);
	return 0;
}



/* �Լ� ���ǹ� */
linkedList_h* createLinkedList()
{
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void freeLinkedList(linkedList_h* L)
{
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}

}

void printLinkedList(linkedList_h* L)
{
	listNode* p = L->head;
	int i = 0;
	while (p != NULL) {
		printf("%d : %s\n", ++i, p->data);
		p = p->link;
	}
	if (L->head == NULL) printf("\n���� ������ ���� ����Ʈ�� �����ϴ�!\n");
}

void visualizeLinkedList(linkedList_h* L)
{
	listNode* p = L->head;
	printf("\n [HEAD]  ->  ");
	while (p != NULL) {
		printf("%s  ->  ", p->data);
		p = p->link;
	}
	printf("[NULL]\n");
}

void insertFirstNode(linkedList_h* L, char* text)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, text);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, char* text)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, text);
	if (L == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h* L, char* text)
{
	listNode* p = L->head;
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, text);
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = newNode;
}

void sortAscending(linkedList_h* L)
{
	char array[2][10];
	listNode* p = L->head;
	listNode* copy_old = array[0];
	listNode* copy_new = array[1];
	PRINT;
	if (copy_old == NULL) printf("������ ��尡 �����ϴ�.\n");
	else if (copy_old->link == NULL) printf("������ ��尡 �����ϴ�.\n");
	else
	{
		while (copy_old->link != NULL)
		{
			
			strcpy(array[0], p->data);
			strcpy(array[1], p->link->data);
			printf("%s\n", array[0]);
			printf("%s\n", array[1]);
			if (strcmp(array[0], array[1]) > 0)
			{
				copy_old = copy_new;
				copy_new = p;
				p = p->link;
				copy_new->link = copy_old;
				/*temp = p->link;
				p->link = temp->link;
				temp->link = p;
				p = temp;*/

				/*temp = p;
				p = p->link;
				temp->link = p->link;
				p = temp;*/
				//break;

				
			}
			L->head = copy_new;
			//q = q->link;
			
		}
	}
	printf("\n������ �Ϸ��߽��ϴ�.\n");
}

void deleteNode(linkedList_h* L, listNode* p)
{
	listNode* pre;
	if (L->head == NULL) return;
	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL) return;
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
		printf("���� �Ϸ��߽��ϴ�!!\n");
	}
}

listNode* searchNode(linkedList_h* L, char* text)
{
	listNode* temp = L->head;
	while (temp != NULL) {

		int result = strcmp(temp->data, text);
		if (result == 0) {
			printf("\n%s ��带 ã�ҽ��ϴ�!!\n", temp->data);
			return temp;
		}
		else {
			printf("\n�׷� ���� �����ϴ�!!\n");
			temp = temp->link;
		}
	}
	return temp;
}

void reverse(linkedList_h* L)
{
	listNode* p = L->head;
	listNode* copy_old = NULL;
	listNode* copy_new = NULL;

	while (p != NULL)
	{
		copy_old = copy_new;
		copy_new = p;
		p = p->link;
		copy_new->link = copy_old;
	}
	L->head = copy_new;
}

void key_Enter()
{
	printf("\n(Enter�� �Է��ϸ� �������ϴ�)\n");
	while (1) {
		int key = _getch();
		if (key == 13) return;
	}	
}
