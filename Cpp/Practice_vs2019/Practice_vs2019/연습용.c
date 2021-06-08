//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct listNode
//{
//	char data[10];
//	struct listNode* link;
//}listNode;
//
//typedef struct linkedList_h
//{
//	listNode* head;
//}linkedList_h;
//
//linkedList_h* createLinkedList();
//void freeLinkedList(linkedList_h* L);
//void printLinkedList(linkedList_h* L);
//void insertLinkedList(linkedList_h* L, char* text);
//
//
///* º»¹® */
//int main() {
//
//	linkedList_h* L = createLinkedList();
//	insertLinkedList(L, "Hello");
//	insertLinkedList(L, "World");
//	
//	
//	
//	printLinkedList(L);
//
//	freeLinkedList(L);
//
//	return 0;
//}
//
//linkedList_h* createLinkedList()
//{
//	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
//	L->head = NULL;
//	return L;
//}
//
//void freeLinkedList(linkedList_h* L)
//{
//	listNode* p;
//	while (L->head != NULL) {
//		p = L->head;
//		L->head = L->head->link;
//		free(p);
//		p = NULL;
//	}
//}
//
//void printLinkedList(linkedList_h* L)
//{
//	listNode* p;
//	int i=0;
//	while (L->head != NULL) {
//		p = L->head;
//		printf("%d. %s\n", ++i, p->data);
//		L->head = L->head->link;
//	}
//}
//
//void insertLinkedList(linkedList_h* L, char* text)
//{
//	listNode* newNode = (listNode*)malloc(sizeof(listNode));
//	strcpy(newNode->data, text);
//	newNode->link = L->head;
//	L->head = newNode;
//}
