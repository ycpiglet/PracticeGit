// 2014132035  정윤철
// 5번째 시험 : LOL DIC with Linked List

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

void Search(char *Name);
void Insert();
void Delete(char *Name);
void DeleteAll(char *Position);
void PrintAll();
void FindMaxHp();
void SortByHp();
void Keyboard();

typedef struct Champion {
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
} Champion;

struct NODE {
	struct NODE *next;
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
};

Champion Champ[50];
//struct NODE Node[50];
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

	struct NODE *head = (NODE*)malloc(sizeof(struct NODE));    // 머리 노드 생성
														// 머리 노드는 데이터를 저장하지 않음

	struct NODE *node1 = (NODE*)malloc(sizeof(struct NODE));   // 첫 번째 노드 생성
	struct NODE *node2 = (NODE*)malloc(sizeof(struct NODE));   // 두 번째 노드 생성
	head->next = node1;                                 // 머리 노드 다음은 첫 번째 노드
	*node1 = { node2, "애쉬", 540, 280, 325, 600, "ADC" };
	//node1->hp = 10;                                   // 첫 번째 노드에 10 저장

	//struct NODE *node2 = (NODE*)malloc(sizeof(struct NODE));   // 두 번째 노드 생성
	//node1->next = node2;                                // 첫 번째 노드 다음은 두 번째 노드
	//node2->hp = 20;                                   // 두 번째 노드에 20 저장
	*node2 = { NULL, "사미라", 530, 349, 335, 500, "ADC" };

	//node2->next = NULL;                                 // 두 번째 노드 다음은 노드가 없음(NULL)

	struct NODE *curr = head->next;    // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	while (curr != NULL)               // 포인터가 NULL이 아닐 때 계속 반복
	{
		printf("%d\n", curr->hp);    // 현재 노드의 데이터 출력
		curr = curr->next;             // 포인터에 다음 노드의 주소 저장
	}

	free(node2);    // 노드 메모리 해제
	free(node1);    // 노드 메모리 해제
	free(head);     // 머리 노드 메모리 해제

	

	while (1) {
		Amount = 0;
		Name_flag = 0;

		printf("LOL Dictionary입니다. \n\n");
		printf("1. Search : 주어진 챔피언의 정보를 출력한다. \n");
		printf("2. Insert : 새로운 챔피언의 정보를 입력받아삽입한다. \n");
		printf("3. Delete : 주어진 챔피언에 대한 정보를 삭제한다. \n");
		printf("4. DeleteAll : 주어진 위치의 모든 챔피언 정보를 삭제한다. \n");
		printf("5. PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다. \n");
		printf("6. FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다. \n");
		printf("7. SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다. \n\n");

		printf("<사전에 등록된 챔피언>\n");
		for (int i = 0; i < 50; i++) {
			if (Champ[i].name[0] != '\0') {
				Amount++;
				printf("%s, ", Champ[i].name);
			}
		}
		
		char* Name2 = (char*)malloc(20 * sizeof(char));
		Name2 = Champ[22].name;
		printf("\n\n%p, %s", *Name2, *Champ[22].name);

		printf("\n\n현재 등록된 챔피언의 수 : %d", Amount);
		printf("\n\n원하는 기능을 고르세요 : ");
		scanf("%d", &Option);
		printf("\n");

		switch (Option) {
		case 1:
			printf("1. Search : 주어진 챔피언의 정보를 출력한다. \n\n");
			printf("검색할 챔피언의 이름을 입력해주세요 : ");
			scanf("%s", Name);
			Search(Name);
			Keyboard();
			break;

		case 2:
			printf("2. Insert : 새로운 챔피언의 정보를 입력받아 삽입한다. \n\n");
			Insert();
			Keyboard();
			break;

		case 3:
			printf("3. Delete : 주어진 챔피언에 대한 정보를 삭제한다. \n\n");
			printf("삭제할 챔피언의 이름을 입력해주세요 : ");
			scanf("%s", Name);
			Delete(Name);
			Keyboard();
			break;

		case 4:
			printf("4. DeleteAll : 주어진 위치의 모든 챔피언 정보를 삭제한다. \n\n");
			printf("삭제할 포지션의 이름을 입력해주세요 : ");
			scanf("%s", Position);
			DeleteAll(Position);
			Keyboard();
			break;

		case 5:
			printf("5. PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다. \n\n");
			PrintAll();
			Keyboard();
			break;

		case 6:
			printf("6. FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다. \n\n");
			FindMaxHp();
			Keyboard();
			break;

		case 7:
			printf("7. SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다. \n\n");
			SortByHp();
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

void Search(char *Name) {
	for (int i = 0; i < 50; i++) {
		if (strcmp(Name, Champ[i].name) == 0) {
			printf("\n이름 : %s \n", Champ[i].name);
			printf("체력 : %d \n", Champ[i].hp);
			printf("마나 : %d \n", Champ[i].mp);
			printf("이동속도 : %d \n", Champ[i].speed);
			printf("사거리 : %d \n", Champ[i].range);
			printf("포지션 : %s \n", Champ[i].position);
			Name_flag = 1;
			return;
		}
	}
	if (Name_flag != 1) printf("\n\"%s\"챔피언은 없습니다!", Name);
}

void Insert() {
	char NAME[20];
	printf("새로 등록할 챔피언의 정보를 입력해주세요.\n\n");
	printf("이름 : ");
	scanf("%s", NAME);
	for (int i = 0; i < 50; i++)
	{
		if (strcmp(NAME, Champ[i].name) == 0)
		{
			printf("기존에 있는 챔피언입니다.\n");
			return;
		}
		else Name_flag = 1;
	}

	if (Name_flag == 1) {
		for (int i = 0; i < 50; i++) {
			if (Champ[i].name[0] == '\0') {
				strcpy(Champ[i].name, NAME);
				printf("체력 : ");
				scanf("%d", &Champ[i].hp);
				printf("마나 : ");
				scanf("%d", &Champ[i].mp);
				printf("이동속도 : ");
				scanf("%d", &Champ[i].speed);
				printf("사거리 : ");
				scanf("%d", &Champ[i].range);
				printf("포지션 : ");
				scanf("%s", Champ[i].position);
				printf("\n새로운 챔피언 \"%s\"이 등록되었습니다. \n", Champ[i].name);
				break;
			}
		}
	}
}

void Delete(char *Name) {
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

void DeleteAll(char *Position) {
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

void PrintAll() {
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

void FindMaxHp() {
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

void SortByHp() {
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

void Keyboard() {
	for (;;) {
		Key = _getch();
		if (Key == 13) return;
	}
}