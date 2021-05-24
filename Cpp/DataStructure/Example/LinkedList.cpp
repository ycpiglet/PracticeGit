#include <stdio.h> // standard input ouutput
#include <string.h> // string
#include <stdlib.h> // memory allocation

// Linear Linked List
typedef struct Node {
	char data[4];
	Node *link;
}Node;

// ���� ����Ʈ�� ù ���� ����� Head ����
typedef struct {
	Node *head;
}HEAD;

// ������ ���� ����Ʈ�� �����ϴ� �Լ�
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

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� �Լ�
void freeLinkedList(HEAD *L) {
	Node *p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
	}
}

// ���� ����Ʈ�� ������� ����ϴ� �Լ�
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

// ù ��° ���� �����ϴ� ����
void insertFirstNode(HEAD *L, char *x) {
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

// ��带 pre �ڿ� �����ϴ� ����
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

// ������ ��带 �����ϴ� ����
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
	printf("���� ����Ʈ ����! \n");
	printList(L);
	getchar();

	printf("����Ʈ�� [��]��� �����ϱ�! \n");
	insertFirstNode(L, "��");
	printList(L);
	getchar();

	printf("����Ʈ�� [��]��� �����ϱ�! \n");
	insertLastNode(L, "��");
	printList(L);
	getchar();

	printf("����Ʈ�� [��]��� �����ϱ�! \n");
	insertFirstNode(L, "��");
	printList(L);
	getchar();

	/*printf("����Ʈ�� [��]��� �����ϱ�! \n");
	insertMiddleNode(L, "��");
	printList(L);
	getchar();*/

	printf("����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����! \n");
	freeLinkedList(L);
	printList(L);
	getchar();

	return 0; // end of the programme
}