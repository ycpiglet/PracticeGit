/* Circular Linked List */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

/* 구조체 선언 */
typedef struct listNode
{
	char data[10];
	struct listNode* link;
}listNode;

typedef struct linkedlist_h
{
	struct listNode* head;
}linkedlist_h;

/* 함수 선언 */

linkedlist_h* createLinkedList();
void insertFirstNode(linkedlist_h* CL, char* text);
void insertMiddleNode(linkedlist_h* CL, listNode* pre, char* text);
void deleteNode_text(linkedlist_h* CL, char* text);
void deleteNode_pre(linkedlist_h* CL, listNode* pre);
void printLinkedLiset(linkedlist_h* CL);
void visualizeLinkedList(linkedlist_h* CL);
listNode* searchNode(linkedlist_h* L, char* text);
void freeLinkedList(linkedlist_h* CL);
void key_Enter();

/* main */
int main() {

	char data[10];
	linkedlist_h* CL = data;
	listNode* p;
	CL = createLinkedList();

	printf("< 원형 연결 리스트(Circular Linked List) 프로그램입니다. >\n");
	insertFirstNode(CL, "Hello");
	insertFirstNode(CL, "World");
	insertFirstNode(CL, "GOOD");
	printLinkedLiset(CL);
	visualizeLinkedList(CL);

	/*while (1)
	{


		key_Enter();
		system("cls");
	}*/

	//freeLinkedList(CL);
	return 0;
}

linkedlist_h* createLinkedList()
{
	linkedlist_h* CL = (linkedlist_h*)malloc(sizeof(linkedlist_h));
	CL->head = NULL;
	
	return CL;
}

/* 함수 정의 */
void insertFirstNode(linkedlist_h* CL, char* text)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	listNode* temp;
	strcpy(newNode->data, text);
	if (CL->head == NULL) 
	{
		CL->head = newNode;
		newNode->link = newNode;
	}
	else
	{
		temp = CL->head;
		while (temp->link != CL->head)
			temp = temp->link;
		newNode->link = temp->link;
		temp->link = newNode;
		CL->head = newNode;
	}
}

void printLinkedLiset(linkedlist_h* CL)
{
	listNode* p = CL->head;
	do 
	{
		printf("%s\n", p->data);
		p = p->link;
	} while (p != CL->head);
}

void visualizeLinkedList(linkedlist_h* CL)
{
	listNode* p = CL->head;
	printf("\n [HEAD]  ->  ");
	do 
	{
		printf("%s  ->  ", p->data);
		p = p->link;
	} while (p != CL->head );
	printf("\n");
}

void freeLinkedList(linkedlist_h* CL)
{
	listNode* p;
	while (CL->head != NULL)
	{
		p = CL->head;
		CL->head = CL->head->link;
		free(p);		
	}
	printf("\n원형 연결 리스트를 모두 해제했습니다!\n");
}

void key_Enter()
{
	int key = _getch();
	while (1) {
		if (key == 13) return;
		else printf("\nEnter를 입력하세요. \n");
	}
}
