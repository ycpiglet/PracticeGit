/* ���� ���� ����Ʈ */
#define _CRT_SECURE_NO_WARNINGS
#define PRINT printf("�۵���\n");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

/* ����ü ���� */
typedef struct listNode_DL
{
	struct listNode_DL* Llink;
	char data[10];
	struct listNode_DL* Rlink;
}listNode_DL;

typedef struct doublyLinkedList_h
{
	struct listNode_DL* head;
}doublyLinkedList_h;

/* �Լ� ���� */
doublyLinkedList_h* createDoublyLinkedList_h();
void insertNode_DL(doublyLinkedList_h* DL, listNode_DL* pre, char* text);
void printDoublyLinkedList(doublyLinkedList_h* DL);
void visualizeDoublyLinkedList(doublyLinkedList_h* DL);
listNode_DL* searchNode_DL(doublyLinkedList_h* DL, char* text);
void freeDoublyLinkedList(doublyLinkedList_h* DL);
void deleteNode_DL(doublyLinkedList_h* DL, listNode_DL* old);

/* main */
int main() {
	
	doublyLinkedList_h* DL;
	listNode_DL* p;
	PRINT;
	DL = createDoublyLinkedList_h();
	insertNode_DL(DL, NULL, "��");
	p = searchNode_DL(DL, "��");
	insertNode_DL(DL, p, "ȭ");
	p = searchNode_DL(DL, "��");
	insertNode_DL(DL, p, "��");
	printDoublyLinkedList(DL);
	visualizeDoublyLinkedList(DL);
	p = searchNode_DL(DL, "��");
	deleteNode_DL(DL, p);
	visualizeDoublyLinkedList(DL);
	printf("\n");
	return 0;
}

/* �Լ� ���� */
doublyLinkedList_h* createDoublyLinkedList_h()
{
	doublyLinkedList_h* DL = (doublyLinkedList_h*)malloc(sizeof(doublyLinkedList_h));
	DL->head = NULL;
	return DL;
}

void insertNode_DL(doublyLinkedList_h* DL, listNode_DL* pre, char* text)
{
	listNode_DL* newNode_DL = (listNode_DL*)malloc(sizeof(listNode_DL));
	strcpy(newNode_DL->data, text);
	if (DL->head == NULL) {
		newNode_DL->Rlink = NULL;
		newNode_DL->Llink = NULL;
		DL->head = newNode_DL;
	}
	else {
		newNode_DL->Rlink = pre->Rlink;
		pre->Rlink = newNode_DL;
		newNode_DL->Llink = pre;
		// ���� �ڸ��� ���� ��尡 �ִ� ���
		if (newNode_DL->Rlink != NULL) {
			newNode_DL->Rlink->Llink = newNode_DL;
		}
	}
}

void printDoublyLinkedList(doublyLinkedList_h* DL)
{
	listNode_DL* p = DL->head;
	//printf()
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->Rlink;
	}
	printf("���� ���� ����Ʈ ����� �Ϸ��߽��ϴ�. \n");
}

void visualizeDoublyLinkedList(doublyLinkedList_h* DL)
{
	listNode_DL* p = DL->head;
	printf("\n [HEAD]  <-->  ");
	while (p != NULL) {
		printf("%s  <-->  ", p->data);
		if (p->Rlink == NULL) break;
		p = p->Rlink;
	}
	printf("[NULL]\n");
}

listNode_DL* searchNode_DL(doublyLinkedList_h* DL, char* text)
{
	listNode_DL* p = DL->head;
	while (p != NULL) {
		if (strcmp(p->data, text) == 0) return p;
		else p = p->Rlink;
	}
	return p;
}

void deleteNode_DL(doublyLinkedList_h* DL, listNode_DL* old)
{
	if (DL->head == NULL) {
		printf("����Ʈ�� �������� �ʽ��ϴ�. ");
		return; // ���� ����Ʈ�� ��� ���� ���� �ߴ�
	}
	else if (old == NULL) {
		printf("������ ��尡 �������� �ʽ��ϴ�. ");
		return; // ������ ��尡 ���� ��� ���� ���� �ߴ�
	}
	else {
		PRINT;
		old->Rlink->Llink = old->Llink;
		old->Llink->Rlink = old->Rlink;
		free(old);
		printf("\n��� ������ �Ϸ��߽��ϴ�! \n");
	}
	
}
