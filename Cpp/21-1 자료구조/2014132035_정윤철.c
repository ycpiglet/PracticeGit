#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

#define CLEAR system("cls")
#define TEST printf("<동작 테스트>\n")
#define MAX 20

typedef struct PersonInfo {
	char name[10];
	int age;
	char ID[10];
	int Team;
	int score;
}PersonInfo;

typedef struct Node {
	char name[10];
	int age;
	char ID[10];
	int Team;
	int score;
	struct Node* link;
}Node;

typedef struct Node_h {
	struct Node* head;
}Node_h;

Node_h* creatLinkedList() {
	Node_h* List = (Node_h*)malloc(sizeof(Node_h));
	return List;
};

void freeLinkedList(Node_h* List) {
	Node* temp;
	while (List->head != NULL) {
		temp = List->head;
		List->head = List->head->link;
		free(temp);
		temp = NULL;
	}
};

void printLinkedList(Node_h* List) {
	Node* temp = List->head;
	while (temp != NULL) {
		printf("------------------------------------\n");
		printf("name : %s\n", temp->name);
		printf("age : %d\n", temp->age);
		printf("ID : %s\n", temp->ID);
		printf("Team : %d\n", temp->Team);
		printf("score : %d\n", temp->score);
		printf("------------------------------------\n");
		temp = temp->link;
	}
};

void copyPersonInfo(Node_h* List, PersonInfo member) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcmp(newNode->name, member.name);
	strcmp(newNode->ID, member.ID);
	newNode->age = member.age;
	newNode->Team = member.Team;
	newNode->score = member.score;
	newNode->link = List->head;
};

void SearchByID_List() {

};

void Key() {
	int KEY = _getch();
	while (1) {
		if (KEY == 13) return;
		else printf("ENTER를 입력하세요!! ");
	}
};

int main() {
	
	PersonInfo member[20] = {
		{"Lee JY", 17, "jylee", 5, 83},
		{"Yoon JH", 55, "wulong", 5, 66},
		{"Song IH", 18, "ihsong", 5, 17},
		{"Kong K", 43, "kskong", 5, 42},
		{"Chang JW", 24, "jwc", 2, 54},
		{"Lee HG", 44, "hgl", 7, 78},
		{"Lee YH", 42, "louis", 7, 32},
		{"Ko HJ", 47, "hjko", 7, 22},
		{"Kim JK", 42, "doublepar", 13, 82},
		{"Oh WS", 55, "oh", 13, 46},
		{"Lim Cj", 29, "scjlim", 13, 15},
		{"Kim YS", 55, "kimys", 13, 66},
		{"Kim YS", 52, "yskim", 13, 93},
		{"Lee DH", 46, "dstin", 9, 73},
		{"Jung NH", 42, "nhjung", 8, 29},
		{"Jin HS", 33, "hsjin", 8, 82},
		{"Kim KC", 17, "ken", 8, 27},
		{"Sung WJ", 22, "wjsung", 15, 32},
		{"Lee JY", 64, "jay", 15, 73},
		{"Kime YS", 55, "yes", 15, 60}
	};

	int amount=0;

	for (int i = 0; i < 20; i++) {
		if (member[i].name[0] != '\0') {
			amount++;
		}
	}

	while (1) {

		printf(" 0. 구조체를 연결 리스트로 복사 및 출력\n");
		printf(" 1. 함수 SerachByID() 실행\n");
		printf(" 2. 함수 DeleteByTeamNumber() 실행\n");
		printf(" 3. 구조체 내용 출력\n");+
		printf(" 4. (미정)\n");

		printf("\n인원수 : %d\n", amount);

		printf("\n원하는 기능의 번호를 입력하세요 : ");

		int input;
		scanf("%d", &input);
		printf("\n\n");

		Node_h* List = creatLinkedList();
		Node* newNode = (Node*)malloc(sizeof(Node));

		switch(input) {
			case 0:
				
				/*strcmp(newNode->name, member[0].name);
				strcmp(newNode->ID, member[0].ID);
				newNode->age = member[0].age;
				newNode->Team = member[0].Team;
				newNode->score = member[0].score;
				newNode->link = List->head;
				printf("------------------------------------\n");
				printf("name : %s\n", member[0].name);
				printf("age : %d\n", member[0].age);
				printf("ID : %s\n", member[0].ID);
				printf("Team : %d\n", member[0].Team);
				printf("scoew : %d\n", member[0].score);
				printf("------------------------------------\n");*/

				for (int i = 0; i < 20; i++) {
					strcmp(newNode->name, member[i].name);
					strcmp(newNode->ID, member[i].ID);
					newNode->age = member[i].age;
					newNode->Team = member[i].Team;
					newNode->score = member[i].score;
					newNode->link = List->head;
					printf("------------------------------------\n");
					printf("name : %s\n", member[i].name);
					printf("age : %d\n", member[i].age);
					printf("ID : %s\n", member[i].ID);
					printf("Team : %d\n", member[i].Team);
					printf("scoew : %d\n", member[i].score);
					printf("------------------------------------\n");
				}
				break;

			case 1:
				TEST;
				break;

			case 2:
				TEST;
				break;

			case 3:
				for (int i = 0; i < 20; i++) {
					printf("------------------------------------\n");
					printf("name : %s\n", member[i].name);
					printf("age : %d\n", member[i].age);
					printf("ID : %s\n", member[i].ID);
					printf("Team : %d\n", member[i].Team);
					printf("scoew : %d\n", member[i].score);
					printf("------------------------------------\n");
				}
				break;

			default:
				TEST;
				break;
		}

		Key();
		freeLinkedList(List);
		CLEAR;
	 }

	return 0;
}