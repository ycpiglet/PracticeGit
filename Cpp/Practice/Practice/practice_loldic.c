/* 헤더파일 참조 */
#include <stdio.h>
#include <Windows.h>
#include <string.h>

/* 매크로 */
#define END return 0
#define TEST printf("<It is working>\n");
#define CLEAR system("cls")

#define MAX 30

/* 구조체 정의 */
typedef struct Node {
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
	struct Node *link;
}listChampion;

typedef struct Head {
	listChampion *head;
}listChampion_h;

typedef struct Champion {
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
} Champion;

/* 함수 선언 */
void key();

listChampion_h *creatLinkedList() {
	listChampion_h *List = (listChampion_h*)malloc(sizeof(listChampion));
	List->head = NULL;
	return List;
}

void copyChampion(listChampion_h *p, Champion q) {
	listChampion *newChamp = (listChampion*)malloc(sizeof(listChampion));
	newChamp->hp = q.hp;
	newChamp->mp = q.mp;
	newChamp->speed = q.speed;
	newChamp->range = q.range;
	strcpy(newChamp->name, q.name);
	strcpy(newChamp->position, q.position);
	newChamp->link = p->head;
	p->head = newChamp;
}

void printfListChampion(listChampion_h *p) {
	listChampion *q;
	q = p->head;
	while (q != NULL) {
		printf("------------------------------\n");
		printf("이름 : %s\n", q->name);
		printf("체력 : %d\n", q->hp);
		printf("마나 : %d\n", q->mp);
		printf("이동속도 : %d\n", q->speed);
		printf("사정거리%d\n", q->range);
		printf("포지션%s\n", q->position);
		printf("------------------------------\n");
		q = q->link;
	}
	printf("복사 완료\n");
}


void freeLinkedList(listChampion_h *p) {
	listChampion *q;
	while (q != NULL) {
		q = p->head;
		p->head = p->head->link;
		free(q);
		q = NULL;
	}
}

/* 본문 */
int main() {

	Champion Champ[MAX] = {
		{ "가렌", 620, 0, 340, 175, "TOP" },
		{ "갈리오", 562, 500, 335, 125, "MID" },
		{ "갱플랭크", 540, 282, 345, 125, "TOP" },
		{ "그라가스", 600, 400,330,125,"JNG" },
		{ "그레이브즈", 555,325,345,425,"JNG" },
		{ "나르",510, 100, 335, 175, "TOP" },
		{ "나미", 475,365,335,550,"SUP" },
		{ "나서스",561,326,350,125,"TOP" },
		{ "노틸러스",576,400,325,175,"SUP" },
		{ "녹턴",585,275,345,125,"JNG" },
		{ "니달리",545,296,335,525,"JNG" },
		{ "니코", 540,450,340,550,"MID" },
		{ "다리우스", 582,263,340,175,"TOP" },
		{ "드레이븐",605,361,330,550,"ADC" },
		{ "라이즈", 575,300,340,550,"MID" },
		{ "라칸", 540,315,335,300,"SUP" },
		{ "람머스", 564,310,335,125,"JNG" },
		{ "럭스", 490, 480, 330, 550, "MID" },
		{ "럼블", 589, 100, 345, 125, "TOP" },
		{ "애쉬", 540, 280, 325,600, "ADC" },
		{ "사미라", 530, 349, 335, 500, "ADC" }
	};

	listChampion_h *List = creatLinkedList();
	
	while(1){
		
		printf("<LOL Dictionary입니다.>\n\n");
		printf(" 0. 기존의 구조체 챔피언을 연결 리스트로 복사\n");
		printf(" 1. 등록된 챔피언의 세부정보 확인\n");
		printf(" 2. 새로운 챔피언 추가\n");
		printf(" 3. 기존 챔피언 삭제\n");
		printf(" 4. 체력순으로 챔피언 정렬\n");
		printf(" 5. 해당 포지션의 챔피언 정보 확인\n");
		printf(" 6. 해당 포지션의 모든 챔피언 삭제\n");
		printf(" 7. 최대 체력을 가진 챔피언 확인\n\n");

		int amount = 0;
		for (int i = 0; i < MAX; i++) if (Champ[i].name[0] != '\0') amount++;

		printf("<현재 등록된 챔피언(%d)>\n", amount);
		for (int i = 0; i < MAX; i++) if (Champ[i].name[0] != '\0') printf("%s, ", Champ[i].name);

		printf("\n\n- 원하는 기능의 번호를 입력하세요 : ");

		int input;
		scanf("%d", &input);

		printf("\n\n");

		switch (input) {
		case 0:
			for (int i = 0; i < amount; i++) {
				copyChampion(List, Champ[i]);
			}
			printfListChampion(List);
			break;

		case 1:
			for (int i = 0; i < amount; i++) {
				if (Champ[i].name[0] != '\0') {
					printf("------------------------------\n");
					printf("이름 : %s\n", Champ[i].name);
					printf("체력 : %d\n", Champ[i].hp);
					printf("마나 : %d\n", Champ[i].mp);
					printf("이동속도 : %d\n", Champ[i].speed);
					printf("사정거리 : %d\n", Champ[i].range);
					printf("포지션 : %s\n", Champ[i].position);
					printf("------------------------------\n");
				}
			}
			break;

		case 2:
			TEST;
			break;

		case 3:
			TEST;
			break;

		case 4:
			TEST;
			break;

		case 5:
			TEST;
			break;

		case 6:
			TEST;
			break;

		case 7:
			TEST;
			break;

		default:
			printf("\n1~6의 번호를 입력해주세요!!\n");
		}

		key();
		freeLinkedList(List);
	}
	
	END;
} // end of main

/* 함수 정의 */

void key() {
	while (1) {
		int key = _getch();

		if (key == 13) {
			break;
		}
		else printf("ENTER를 입력하세요!! ");
	}
	CLEAR;
}