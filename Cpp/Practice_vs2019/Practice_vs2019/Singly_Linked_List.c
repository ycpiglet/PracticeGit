/* 단순 연결 리스트 */
#define _CRT_SECURE_NO_WARNINGS
#define PRINT printf("It it working!!\n");
#define DEVIDE printf("----------------------------------------------------\n");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


/* 구조체 선언 */
typedef struct listNode
{
	char data[10];
	struct listNode* link;
}listNode;

typedef struct
{
	listNode* head;
}linkedList_h;


/* 함수 선언 */
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



/* main문 */
int main() {

	int option = 9;
	char data[10], data_pre[10];
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	listNode* pre = data;

	while (1) {
		printf("< 단순 연결 리스트(Singly Linked List) 프로그램입니다. >\n");
		DEVIDE;
		printf("0. 단순 연결 리스트 생성하기\n");
		printf("1. 첫 번째 노드에 삽입하기\n");
		printf("2. 특정 노드 뒤에 삽입하기\n");
		printf("3. 마지막 노드에 삽입하기\n");
		printf("4. 노드 순서대로 출력하기\n");
		printf("5. 특정 노드 검색하기\n");
		printf("6. 특정 노드 삭제하기\n");
		printf("7. 연결 순서 뒤집기\n");
		printf("8. 오름차순으로 정렬하기\n");
		printf("9. 단순 연결 리스트 해제하기\n");
		DEVIDE;
		if((L != data) && (option != 9)) visualizeLinkedList(L);
		printf("\n위 옵션 중에서 선택해주세요. : ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:
			L = createLinkedList();
			printf("\n단순 연결 리스트가 생성되었습니다!\n");
			break;
		case 1:
			printf("- 새로 생성할 노드에 들어갈 Data를 적어주세요. : ");
			scanf("%s", data);
			insertFirstNode(L, data);
			printf("\n노드 생성이 완료되었습니다.\n");
			break;

		case 2:
			printf("- 새로 생성할 노드에 들어갈 Data를 적어주세요. : ");
			scanf("%s", data);
			printf("- 추가하고 싶은 위치의 노드에 들어갈 Data를 적어주세요. : ");
			scanf("%s", data_pre);
			pre = searchNode(L, data_pre);
			insertMiddleNode(L, pre, data);
			printf("\n노드 생성이 완료되었습니다.\n");
			break;

		case 3:
			printf("- 새로 생성할 노드에 들어갈 Data를 적어주세요. : ");
			scanf("%s", data);
			insertLastNode(L, data);
			printf("\n노드 생성이 완료되었습니다.\n");
			break;

		case 4:
			printLinkedList(L);
			break;

		case 5:
			printf("- 검색할 노드의 Data를 적어주세요. : ");
			scanf("%s", data);
			pre = searchNode(L, data);
			printf("\n노드 검색이 완료되었습니다.\n");
			break;

		case 6:
			printf("- 삭제할 노드의 Data를 적어주세요. : ");
			scanf("%s", data);
			deleteNode(L, data);
			printf("\n노드 삭제가 완료되었습니다.\n");
			break;

		case 7:
			reverse(L);
			printf("\n연결 리스트의 순서가 바뀌었습니다.\n");
			break;

		case 8:
			sortAscending(L);
			printf("\n모든 노드를 오름차순으로 정렬했습니다!!\n");
			break;

		case 9:
			freeLinkedList(L);
			printf("\n연결 리스트를 모두 해제했습니다!!\n");
			break;

		default:
			printf("없는 번호입니다. 정확히 입력해주세요!\n");
			break;
		}
		key_Enter();
		system("cls");
	}

	freeLinkedList(L);
	return 0;
}



/* 함수 정의문 */
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
	if (L->head == NULL) printf("\n현재 생성된 연결 리스트가 없습니다!\n");
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
	if (copy_old == NULL) printf("정렬할 노드가 없습니다.\n");
	else if (copy_old->link == NULL) printf("정렬할 노드가 없습니다.\n");
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
	printf("\n정렬을 완료했습니다.\n");
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
		printf("삭제 완료했습니다!!\n");
	}
}

listNode* searchNode(linkedList_h* L, char* text)
{
	listNode* temp = L->head;
	while (temp != NULL) {

		int result = strcmp(temp->data, text);
		if (result == 0) {
			printf("\n%s 노드를 찾았습니다!!\n", temp->data);
			return temp;
		}
		else {
			printf("\n그런 노드는 없습니다!!\n");
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
	printf("\n(Enter를 입력하면 지워집니다)\n");
	while (1) {
		int key = _getch();
		if (key == 13) return;
	}	
}
