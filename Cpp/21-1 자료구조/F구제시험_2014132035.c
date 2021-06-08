// 2021.06.08(화) 자료구조 F 구제 시험
// (o) 1. words.txt에 저장된 영어 단어들을 단방향 연결 리스트에 저장하라. 
// (x) 2. 문자열을 입력 받아 해당 문자열로 시작하는 모든 단어를 삭제하라.
// (x) 3. 두 개의 문자열 str1과 str2을 연결 리스트에 삽입하되, str2의 앞자리에 삽입하라. 만약 st2가 연결 리스트에 존재하지 않는 경우에는 맨 뒤에 삽입하라. 만약 str1이 이미 연결 리스트에 존재하는 경우에는 메시지를 출력하고 삽입하지 않는다.
// (o) 4. 연결 리스트에 존재하는 전체 단어와 총 단어의 개수를 출력하라.
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
	
	LinkedList_h* L = createLinkedList(); // 연결 리스트 생성
	FILE* f; // 파일 열기
	f = fopen("words.txt", "r"); // 파일 모드 : 읽기
	int count = 1778; // 단어 갯수
	int i = 0; // 줄 번호
	char str[1778][20];
	while (1) {
		printf("------------------------------------------------------\n");
		printf("자료구조 F 구제 시험\n");
		printf("1. 연결 리스트 생성하기\n");
		printf("2. 문자열 입력받고 전부 삭제하기\n");
		printf("3. 노드 앞에 삽입하기\n");
		printf("4. 연결 리스트 출력하기 (모든 단어, 갯수)\n");
		printf("------------------------------------------------------\n");

		char existWord[20];
		char newWord[20];

		int option = 10;
		printf("원하는 기능의 번호를 입력해주세요 : ");
		scanf("%d", &option);
		switch (option) {

		case 1:
			printf("\n1. 연결 리스트 생성하기\n\n");
			while (feof(f) == 0) { // 끝 만나면
				fgets(str[i], 20, f); // 문자열 읽기
				//printf("%s", str[i]);
				insertFirstNode(L, str[i]);
				i++;
				if (i > 1778) break;
			}
				printf("\n단방향 연결 리스트를 생성했습니다.\n\n");
			break;

		case 2:
			printf("\n2. 문자열 입력받고 전부 삭제하기\n\n");
			printf("삭제할 단어를 입력하세요 : ");
			scanf("%s", existWord);
			deleteNode(L, existWord);
			break;

		case 3:
			
			printf("\n3. 노드 앞에 삽입하기\n\n");
			printf("기준점이 될 단어를 입력하세요 : ");
			scanf("%s", existWord);
			printf("새로 입력한 단어를 입력하세요 : ");
			scanf("%s", newWord);
			insertNode(L, existWord, newWord);
			break;

		case 4:
			printf("\n4. 연결 리스트 출력하기 (모든 단어, 갯수)\n\n");
			printLinkedList(L);
			break;

		default:
			printf("\n없는 번호입니다.\n");
			break;
		}
		key_Enter();
		system("cls");
	}
	
	printf("\n\n");
	fclose(f); // 파일 닫기
	freeLinkedList(L); // 연결 리스트 해제
	return 0; // 종료
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
	printf("전체 갯수 : %d\n\n", count);
}

void deleteNode(LinkedList_h* L, char* text)
{
	ListNode* p = L->head;
	ListNode* temp;
	while (p->link != NULL) {
		temp = p->link;
		if (strcmp(p->link->data, text) == 0) {
			p->link = p->link->link; // 다음 노드로 변경
			free(temp);
			printf("\n%s를 삭제했습니다.\n", text);
			return;
		}
		//else {
		//	printf("\n그런 단어는 없습니다.\n");
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
	printf("\n연결 리스트 해제\n");
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
	strcpy(newNode->data, newWord); // 문자열 복사
	while (p != NULL) {
		printf("작동중\n");
		pre = p;
		sub = p->link;
		if (strcmp(sub->data, newWord) == 0) { // 단어가 이미 존재하면
			printf("\n이미 존재하는 단어입니다.\n");
		}

		else if (strcmp(sub->data, existWord) == 0) { // 단어가 일치하면
			pre->link = newNode;
			newNode->link = sub; // 링크 복사
			printf("\n삽입을 완료했습니다.\n");
			return;
		}

		if (p->link == NULL) { // 기준 단어가 없으면
			p->link = newNode;
			newNode->link = NULL;
			printf("\n맨 뒤에 삽입했습니다.\n");
		}

		p = p->link; // 다음 순서로 이동
	}
	printf("\n그런 단어는 없습니다.\n");
}

void key_Enter()
{
	printf("\n            (Enter)를 입력하세요.\n");
	int key = _getch();
	while (key != 13) {
		if (key == 13) return;
		printf("            (Enter)를 입력하세요.\n");
	}
}
