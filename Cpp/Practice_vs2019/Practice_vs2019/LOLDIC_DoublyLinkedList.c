#define _CRT_SECURE_NO_WARNINGS
#define PRINT printf("\n ���� ��");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>


typedef struct Champion 
{
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
} Champion;

typedef struct ListNode_DL
{
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
	struct ListNode_DL* Llink;
	struct ListNode_DL* Rlink;
}ListNode_DL;

typedef struct LinkedList_h_DL
{
	struct ListNode_DL* head;
}LinkedList_h_DL;

LinkedList_h_DL* Array2LinkedList(Champion* Champ);
void printDoublyLinkedList(LinkedList_h_DL* DL);
LinkedList_h_DL* createDoublyLinkedList();
void insertNode_DL(LinkedList_h_DL* DL, ListNode_DL* pre, Champion* Champ);
void insert(LinkedList_h_DL* DL, ListNode_DL* pre, char* name, int hp, int mp, int speed, int range, char* position);
void insertFirstNode_DL(LinkedList_h_DL* DL, char* name, int hp, int mp, int speed, int range, char* position);
void sortByMaxHp(LinkedList_h_DL* DL);

int main() {
	Champion Champ[22] = {
		{ "����", 620, 0, 340, 175, "TOP" }
		,{ "������", 562, 500, 335, 125, "MID" }
		,{ "���÷�ũ", 540, 282, 345, 125, "TOP" }
		,{ "�׶󰡽�", 600, 400,330,125,"JNG" }
		,{ "�׷��̺���", 555,325,345,425,"JNG" }
		,{ "����",510, 100, 335, 175, "TOP" }
		,{ "����", 475,365,335,550,"SUP" }
		,{ "������",561,326,350,125,"TOP" }
		,{ "��ƿ����",576,400,325,175,"SUP" }
		,{ "����",585,275,345,125,"JNG" }
		, { "�ϴ޸�",545,296,335,525,"JNG" }
		, { "����", 540,450,340,550,"MID" }
		, { "�ٸ��콺", 582,263,340,175,"TOP" }
		, { "���ֳ̾�", 570,375,345,150, "MID" }
		, { "�巹�̺�",605,361,330,550,"ADC" }
		, { "������", 575,300,340,550,"MID" }
		, { "��ĭ", 540,315,335,300,"SUP" }
		, { "���ӽ�", 564,310,335,125,"JNG" }
		, { "����", 490, 480, 330, 550, "MID" }
		, { "����", 589, 100, 345, 125, "TOP" }
		, { "�ֽ�", 540, 280, 325,600, "ADC" }
		, { "��̶�", 530, 349, 335, 500, "ADC" }
	};
	
	/*for (int i = 0; i < 22; i++) {
		printf("%s\n", Champ[i].name);
	}*/
	
	LinkedList_h_DL* DL = createDoublyLinkedList();
	insert(DL, NULL, Champ[0].name, 620, 0, 340, 175, Champ[0].position);
	
	
	for (int i = 1; i < 22; i++) {
		insertFirstNode_DL(DL, Champ[i].name, Champ[i].hp, Champ[i].mp, Champ[i].speed, Champ[i].range, Champ[i].position);
	}
	printDoublyLinkedList(DL);
	printf("\n\n");
	//ü�� ������ ����
	sortByMaxHp(DL);
	printDoublyLinkedList(DL);

	return 0;
}

LinkedList_h_DL* Array2LinkedList(Champion* Champ)
{
	//ListNode_DL* newNode;
	//LinkedList_h_DL* DL = NULL;;
	//for (int i = 0; i < 22; i++) {
	//	//ListNode_DL* newNode[i] = (ListNode_DL*)malloc(sizeof(ListNode_DL));
	//	strcpy(newNode->name, Champ[i].name);
	//	newNode>hp = Champ[i].hp;
	//	newNode->mp = Champ[i].mp;
	//	newNode->speed = Champ[i].speed;
	//	newNode->range = Champ[i].range;
	//	strcpy(newNode->position, Champ[i].position);
	//	if (i == 0) {
	//		DL->head = newNode;
	//		newNode->Rlink = NULL;
	//		newNode->Llink = NULL;
	//	}
	//	else if (i == 21) {
	//		newNode->Rlink = NULL;
	//		newNode->Llink = newNode[i - 1];
	//	}
	//	else {
	//		newNode->Rlink = newNode[i + 1];
	//		newNode->Llink = newNode[i - 1];
	//	}
	//}
	//printf("\n ����ü ���簡 �Ϸ�Ǿ����ϴ�. \n");

	//return DL;
}

void printDoublyLinkedList(LinkedList_h_DL* DL)
{
	ListNode_DL* p = DL->head;
	printf(" [HEAD]  <-->  ");
	while (p != NULL) {
		printf("%s  <-->  ", p->name);
		p = p->Rlink;
	}
	printf("[NULL]\n");
}

LinkedList_h_DL* createDoublyLinkedList()
{	
	LinkedList_h_DL* DL = (LinkedList_h_DL**)malloc(sizeof(LinkedList_h_DL));
	DL->head = NULL;
	return DL;
}

void insertNode_DL(LinkedList_h_DL* DL, ListNode_DL* pre, Champion* Champ)
{
	ListNode_DL* newNode = (ListNode_DL*)malloc(sizeof(ListNode_DL));
	
	strcpy(newNode->name, Champ->name);
	newNode->hp = Champ->hp;
	newNode->mp = Champ->mp;
	newNode->speed = Champ->speed;
	newNode->range = Champ->range;
	strcpy(newNode->position, Champ->position);

	if (DL->head == NULL) {
		DL->head = newNode;
		newNode->Llink = NULL;
		newNode->Rlink = NULL;
	}
	else {
		newNode->Rlink = pre->Rlink;
		pre->Rlink = newNode;
		newNode->Llink = pre;
		if (newNode->Rlink != NULL) {
			newNode->Rlink->Llink = newNode;
		};
	}
}

void insert(LinkedList_h_DL* DL, ListNode_DL* pre, char* name, int hp, int mp, int speed, int range, char* position)
{
	ListNode_DL* newNode_DL = (ListNode_DL*)malloc(sizeof(ListNode_DL));
	strcpy(newNode_DL->name, name);
	newNode_DL->hp = hp;
	newNode_DL->mp = mp;
	newNode_DL->speed = speed;
	newNode_DL->range = range;
	strcpy(newNode_DL->position, position);
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

void insertFirstNode_DL(LinkedList_h_DL* DL, char* name, int hp, int mp, int speed, int range, char* position)
{
	ListNode_DL* newNode_DL = (ListNode_DL*)malloc(sizeof(ListNode_DL));
	strcpy(newNode_DL->name, name);
	newNode_DL->hp = hp;
	newNode_DL->mp = mp;
	newNode_DL->speed = speed;
	newNode_DL->range = range;
	strcpy(newNode_DL->position, position);

	newNode_DL->Rlink = DL->head;
	newNode_DL->Rlink->Llink = newNode_DL;
	newNode_DL->Llink = NULL;
	DL->head = newNode_DL;
}

void sortByMaxHp(LinkedList_h_DL* DL)
{
	ListNode_DL* p = DL->head;
	ListNode_DL* pre = NULL, * sub = NULL;
	ListNode_DL* temp = NULL;
	while (p->Rlink != NULL) {
		pre = p;
		sub = p->Rlink;
		if (sub->hp > pre->hp) {
			temp->Rlink = sub->Rlink;
			sub->Rlink = sub->Llink;
			pre->Llink->Rlink = pre->Rlink;
			pre->Llink = pre->Rlink;
			pre->Rlink = temp->Rlink;
		}
		p = p->Rlink;
	}
	printf("\n������ �Ϸ��߽��ϴ�.\n");
}
