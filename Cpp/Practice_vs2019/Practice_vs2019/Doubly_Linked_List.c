/* 이중 연결 리스트 */
#define _CRT_SECURE_NO_WARNINGS
#define PRINT printf("작동중\n");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

/* 구조체 선언 */
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

/* 함수 선언 */
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
	insertNode_DL(DL, NULL, "월");
	p = searchNode_DL(DL, "월");
	insertNode_DL(DL, p, "화");
	p = searchNode_DL(DL, "월");
	insertNode_DL(DL, p, "수");
	printDoublyLinkedList(DL);
	visualizeDoublyLinkedList(DL);
	p = searchNode_DL(DL, "월");
	deleteNode_DL(DL, p);
	visualizeDoublyLinkedList(DL);
	printf("\n");
	return 0;
}

/* 함수 정의 */
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
		// 삽입 자리에 다음 노드가 있는 경우
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
	printf("이중 연결 리스트 출력을 완료했습니다. \n");
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
		printf("리스트가 존재하지 않습니다. ");
		return; // 공백 리스트인 경우 삭제 연산 중단
	}
	else if (old == NULL) {
		printf("삭제할 노드가 존재하지 않습니다. ");
		return; // 삭제할 노드가 없는 경우 삭제 연산 중단
	}
	else {
		PRINT;
		old->Rlink->Llink = old->Llink;
		old->Llink->Rlink = old->Rlink;
		free(old);
		printf("\n노드 삭제를 완료했습니다! \n");
	}
	
}
