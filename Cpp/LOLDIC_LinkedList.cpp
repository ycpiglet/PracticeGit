// 2014132035  정윤철
// 3번째 시험 : LOL DIC

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

void Search_SL(char *Name);
void Insert_SL();
void Delete_SL(char *Name);
void DelateAll_SL(char *Position);
void PrintAll_SL();
void FindMaxHp_SL();
void SortByHp_SL();
void Keyboard();
void Array2LinkedList();

typedef struct Champion {
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
} Champion;

typedef struct championNode {
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
	struct championNode *link;
}cNode;

typedef struct HEAD {
	cNode *head;
}HEAD;

Champion Champ[50];
cNode *champ[22];
char Name[20], Position[10];
int Amount, Key, maxHP, Option, Name_flag;

void main()
{
	Champ[0] = { "가렌", 620, 0, 340, 175, "TOP" };
	Champ[1] = { "갈리오", 562, 500, 335, 125, "MID" };
	Champ[2] = { "갱플랭크", 540, 282, 345, 125, "TOP" };
	Champ[3] = { "그라가스", 600, 400,330,125,"JNG" };
	Champ[4] = { "그레이브즈", 555,325,345,425,"JNG" };
	Champ[5] = { "나르",510, 100, 335, 175, "TOP" };
	Champ[6] = { "나미", 475,365,335,550,"SUP" };
	Champ[7] = { "나서스",561,326,350,125,"TOP" };
	Champ[8] = { "노틸러스",576,400,325,175,"SUP" };
	Champ[9] = { "녹턴",585,275,345,125,"JNG" };
	Champ[10] = { "니달리",545,296,335,525,"JNG" };
	Champ[11] = { "니코", 540,450,340,550,"MID" };
	Champ[12] = { "다리우스", 582,263,340,175,"TOP" };
	Champ[13] = { "다이애나", 570,375,345,150, "MID" };
	Champ[14] = { "드레이븐",605,361,330,550,"ADC" };
	Champ[15] = { "라이즈", 575,300,340,550,"MID" };
	Champ[16] = { "라칸", 540,315,335,300,"SUP" };
	Champ[17] = { "람머스", 564,310,335,125,"JNG" };
	Champ[18] = { "럭스", 490, 480, 330, 550, "MID" };
	Champ[19] = { "럼블", 589, 100, 345, 125, "TOP" };
	Champ[20] = { "애쉬", 540, 280, 325,600, "ADC" };
	Champ[21] = { "사미라", 530, 349, 335, 500, "ADC" };
	
	Array2LinkedList();
	// 각 링크 연결하기
	HEAD *Head; // 더블 포인터
	Head = (HEAD*)malloc(sizeof(HEAD));
	Head->head = champ[0];
	for (int i = 0; i < 21; i++) {
		if (champ[i]->link == NULL) {
			champ[i]->link = champ[i + 1];
		}

		if (i + 1 == 21) {
			champ[i + 1]->link = champ[0];
		}
	}

	while (1) {
		Amount = 0;
		Name_flag = 0;

		printf("LOL Dictionary입니다. \n\n");
		printf("1. Search_SL : 주어진 챔피언의 정보를 출력한다. \n");
		printf("2. Insert_SL_SL : 새로운 챔피언의 정보를 입력받아삽입한다. \n");
		printf("3. Delete_SL : 주어진 챔피언에 대한 정보를 삭제한다. \n");
		printf("4. DelateAll_SL : 주어진 위치의 모든 챔피언 정보를 삭제한다. \n");
		printf("5. PrintAll_SL : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다. \n");
		printf("6. FindMaxHp_SL : 가장 체력이 큰 챔피언의 정보를 출력한다. \n");
		printf("7. SortByHp_SL : 체력이 큰 챔피언부터 순서대로 저장한다. \n\n");

		printf("<사전에 등록된 챔피언>\n");
		for (int i = 0; i < 50; i++) {
			if (champ[i]->name[0] != '\0') {
				Amount++;
				printf("%s, ", champ[i]->name);
			}
		}

		printf("\n\n현재 등록된 챔피언의 수 : %d", Amount);
		printf("\n\n원하는 기능을 고르세요 : ");
		scanf("%d", &Option);
		printf("\n");

		switch (Option) {
		case 1:
			printf("1. Search_SL : 주어진 챔피언의 정보를 출력한다. \n\n");
			printf("검색할 챔피언의 이름을 입력해주세요 : ");
			scanf("%s", Name);
			Search_SL(Name);
			Keyboard();
			break;

		case 2:
			printf("2. Insert_SL_SL : 새로운 챔피언의 정보를 입력받아 삽입한다. \n\n");
			//Insert_SL();
			char NAME[20];
			printf("새로 등록할 챔피언의 정보를 입력해주세요.\n\n");
			printf("이름 : ");
			scanf("%s", NAME);
			for (int i = 0; i < 50; i++)
			{
				if (strcmp(NAME, champ[i]->name) == 0)
				{
					printf("기존에 있는 챔피언입니다.\n");
					return;
				}
				else Name_flag = 1;
			}

			if (Name_flag == 1) {
				cNode *newNode;
				cNode *temp;
				char *name, *position;
				newNode = (cNode*)malloc(sizeof(cNode));
				printf("\n이름 : ");
				scanf("%s", name);
				strcpy(newNode->name, name);
				printf("\n체력 : ");
				scanf("%d", &newNode->hp);
				printf("\n마나 : ");
				scanf("%d", &newNode->mp);
				printf("\n이동속도 : ");
				scanf("%d", &newNode->speed);
				printf("\n사거리 : ");
				scanf("%d", &newNode->range);
				printf("\n포지션 : ");
				scanf("%s", position);
				strcpy(newNode->position, position);
				
				if (Head->head == NULL) {
					Head->head = newNode;
					newNode->link = newNode;
				}

				else {
					temp = Head->head;
					while (temp->link != Head->head) {
						temp = temp->link;
					}
					newNode->link = temp->link;
					temp->link = newNode;
					Head->head = newNode;
				}
			}

			Keyboard();
			break;

		case 3:
			printf("3. Delete_SL : 주어진 챔피언에 대한 정보를 삭제한다. \n\n");
			printf("삭제할 챔피언의 이름을 입력해주세요 : ");
			scanf("%s", Name);
			Delete_SL(Name);
			Keyboard();
			break;

		case 4:
			printf("4. DelateAll_SL : 주어진 위치의 모든 챔피언 정보를 삭제한다. \n\n");
			printf("삭제할 포지션의 이름을 입력해주세요 : ");
			scanf("%s", Position);
			DelateAll_SL(Position);
			Keyboard();
			break;

		case 5:
			printf("5. PrintAll_SL : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다. \n\n");
			PrintAll_SL();
			Keyboard();
			break;

		case 6:
			printf("6. FindMaxHp_SL : 가장 체력이 큰 챔피언의 정보를 출력한다. \n\n");
			FindMaxHp_SL();
			Keyboard();
			break;

		case 7:
			printf("7. SortByHp_SL : 체력이 큰 챔피언부터 순서대로 저장한다. \n\n");
			SortByHp_SL();
			Keyboard();
			break;

		default:
			printf("1 ~ 7까지 입력해주세요. \n");
			Keyboard();
			break;
		}
		system("cls");
	}
}

void Search_SL(char *Name) {
	for (int i = 0; i < 50; i++) {
		if (strcmp(Name, champ[i]->name) == 0) {
			printf("\n이름 : %s \n", champ[i]->name);
			printf("체력 : %d \n", champ[i]->hp);
			printf("마나 : %d \n", champ[i]->mp);
			printf("이동속도 : %d \n", champ[i]->speed);
			printf("사거리 : %d \n", champ[i]->range);
			printf("포지션 : %s \n", champ[i]->position);
			Name_flag = 1;
			return;
		}
	}
	if (Name_flag != 1) printf("\n\"%s\"챔피언은 없습니다!", Name);
}

void Insert_SL() {
	char NAME[20];
	printf("새로 등록할 챔피언의 정보를 입력해주세요.\n\n");
	printf("이름 : ");
	scanf("%s", NAME);
	for (int i = 0; i < 50; i++)
	{
		if (strcmp(NAME, champ[i]->name) == 0)
		{
			printf("기존에 있는 챔피언입니다.\n");
			return;
		}
		else Name_flag = 1;
	}

	if (Name_flag == 1) {
		cNode *newNode;
		cNode *temp;
		char *name, *position;
		newNode = (cNode*)malloc(sizeof(cNode));
		printf("\n이름 : ");
		scanf("%s", name);
		strcpy(newNode->name, name);
		printf("\n체력 : ");
		scanf("%d", newNode->hp);
		printf("\n마나 : ");
		scanf("%d", newNode->mp);
		printf("\n이동속도 : ");
		scanf("%d", newNode->speed);
		printf("\n사거리 : ");
		scanf("%d", newNode->range);
		printf("\n포지션 : ");
		scanf("%s", position);
		strcpy(newNode->position, position);
		
	}
}

void Delete_SL(char *Name) {
	for (int i = 0; i < 50; i++)
	{
		if (strcmp(Name, Champ[i].name) == 0)
		{
			Champ[i].name[0] = '\0';
			Champ[i].hp = 0;
			Champ[i].mp = 0;
			Champ[i].speed = 0;
			Champ[i].range = 0;
			Champ[i].position[0] = '\0';
			printf("\n\"%s\"챔피언을 삭제했습니다.\n", Name);
			Name_flag = 1;
			return;
		}
		else Name_flag = 0;
	}

	if (Name_flag != 1) printf("\n\"%s\"챔피언은 없습니다!", Name);
}

void DelateAll_SL(char *Position) {
	for (int i = 0; i < 50; i++)
	{
		if (strcmp(Position, Champ[i].position) == 0)
		{
			Champ[i].name[0] = '\0';
			Champ[i].hp = 0;
			Champ[i].mp = 0;
			Champ[i].speed = 0;
			Champ[i].range = 0;
			Champ[i].position[0] = '\0';
			Name_flag = 1;
		}
	}

	if (Name_flag != 1) printf("\"%s\"포지션은 없습니다!", Position);
	else printf("\"%s\"포지션을 삭제했습니다.", Position);
}

void PrintAll_SL() {
	for (int i = 0; i < 50; i++) {
		if (Champ[i].speed != 0) {
			printf("\n이름 : %s \n", Champ[i].name);
			printf("체력 : %d \n", Champ[i].hp);
			printf("마나 : %d \n", Champ[i].mp);
			printf("이동속도 : %d \n", Champ[i].speed);
			printf("사거리 : %d \n", Champ[i].range);
			printf("포지션 : %s \n", Champ[i].position);
		}
	}
}

void FindMaxHp_SL() {
	for (int i = 0; i < 50; i++) {
		if (Champ[i].hp >= maxHP)
		{
			maxHP = Champ[i].hp;
		}
	}

	for (int i = 0; i < 50; i++) {
		if (maxHP == Champ[i].hp) {
			printf("이름 : %s \n", Champ[i].name);
			printf("체력 : %d \n", Champ[i].hp);
			printf("마나 : %d \n", Champ[i].mp);
			printf("이동속도 : %d \n", Champ[i].speed);
			printf("사거리 : %d \n", Champ[i].range);
			printf("포지션 : %s \n", Champ[i].position);
		}
	}
}

void SortByHp_SL() {
	Champion _Champ;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < i; j++) {
			if (Champ[i].hp >= Champ[j].hp) {
				_Champ = Champ[i];
				Champ[i] = Champ[j];
				Champ[j] = _Champ;
			}
		}
	}
	printf("정렬이 완료되었습니다. \n");
}

void Array2LinkedList() {
	// 구조체 내용 복사하기 (챔피언 스텟)
	for (int i = 0; i < 22; i++) {
		champ[i] = (cNode*)malloc(sizeof(cNode));
		strcpy(champ[i]->name, Champ[i].name);
		champ[i]->hp = Champ[i].hp;
		champ[i]->mp = Champ[i].mp;
		champ[i]->speed = Champ[i].speed;
		champ[i]->range = Champ[i].range;
		strcpy(champ[i]->position, Champ[i].position);
		//printf("%s \n", champ[i]->name);
	}
	
}

void Keyboard() {
	for (;;) {
		Key = _getch();
		if (Key == 13) return;
	}
}