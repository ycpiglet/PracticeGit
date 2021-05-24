#include <stdio.h> // standard input ouutput
#include <string.h> // string
#include <stdlib.h> // memory allocation

// Linear Linked List
typedef struct Node {
	char data[4];
	Node *link;
}Node;

// 연결 리스트의 첫 번재 노드인 Head 생성
typedef struct {
	Node *head;
}HEAD;

// 공백의 연결 리스트를 생성하는 함수
HEAD *createLinkedList(void) {
	HEAD *L;
	L = (HEAD*)malloc(sizeof(HEAD));
	L->head = NULL;
	return L;
}

Node *makeLinkedList() {
	Node *First = (Node *)malloc(sizeof(Node));
	First->link = NULL;
	return First;
}

// 연결 리스트의 전체 메모리를 해제하는 함수
void freeLinkedList(HEAD *L) {
	Node *p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
	}
}

// 연결 리스트를 순서대로 출력하는 함수
void printList(HEAD *L) {
	Node *p;
	printf("L=(");
	p = L->head;

	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(HEAD *L, char *x) {
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(HEAD *L, Node *pre, char *x) {
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data, x);

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

// 마지막 노드를 삽입하는 연산
void insertLastNode(HEAD *L, char *x) {
	Node *newNode;
	Node *temp;
	newNode = (Node*) malloc(sizeof(Node));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	temp = L->head;
	while (temp->link != NULL) temp = temp->link;
	temp->link = newNode;
}

int main() { // start the program

	HEAD *L;
	L = createLinkedList();
	printf("공백 리스트 생성! \n");
	printList(L);
	getchar();

	printf("리스트에 [수]노드 삽입하기! \n");
	insertFirstNode(L, "수");
	printList(L);
	getchar();

	printf("리스트에 [금]노드 삽입하기! \n");
	insertLastNode(L, "금");
	printList(L);
	getchar();

	printf("리스트에 [월]노드 삽입하기! \n");
	insertFirstNode(L, "월");
	printList(L);
	getchar();

	/*printf("리스트에 [월]노드 삽입하기! \n");
	insertMiddleNode(L, "월");
	printList(L);
	getchar();*/

	printf("리스트 공간을 해제하여 공백 리스트로 만들기! \n");
	freeLinkedList(L);
	printList(L);
	getchar();

	return 0; // end of the programme
}