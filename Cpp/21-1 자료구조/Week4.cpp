// 2014132035  정윤철
// 3번째 시험 : LOL DIC

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

void Search_R(char *Name);
void Insert_R(char *Name);
void Delete_R(char *Name);
void DeleteAll_R(char *Position);
void PrintAll_R();
void FindMaxHp_R();
void SortByHp_R();
void Keyboard();

typedef struct Champion {
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
} Champion;

Champion Champ[50];
//Champion *ptr = &Champ[Count];
char Name[20], Position[10];
int Count, Amount, Key, maxHP, Option, Name_flag, Index;

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

	while (1) {
		Amount = 0;
		Name_flag = 0;
		Count = 0;
		Index = 0;
		//int *prtMax = Champ[0].hp;

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

		printf("\n\n현재 등록된 챔피언의 수 : %d", Amount);
		printf("\n\n원하는 기능을 고르세요 : ");
		scanf("%d", &Option);
		printf("\n");

		switch (Option) {
		case 1:
			printf("1. Search : 주어진 챔피언의 정보를 출력한다. \n\n");
			printf("검색할 챔피언의 이름을 입력해주세요 : ");
			scanf("%s", Name);
			Search_R(Name);
			if (Name_flag == 1) {
				printf("\n이름 : %s \n", Champ[Index].name);
				printf("체력 : %d \n", Champ[Index].hp);
				printf("마나 : %d \n", Champ[Index].mp);
				printf("이동속도 : %d \n", Champ[Index].speed);
				printf("사거리 : %d \n", Champ[Index].range);
				printf("포지션 : %s \n", Champ[Index].position);
			}
			Keyboard();
			break;

		case 2:
			printf("2. Insert : 새로운 챔피언의 정보를 입력받아 삽입한다. \n\n");
			printf("검색할 챔피언의 이름을 입력해주세요 : ");
			scanf("%s", Name);
			Insert_R(Name);
			Keyboard();
			break;

		case 3:
			printf("3. Delete : 주어진 챔피언에 대한 정보를 삭제한다. \n\n");
			printf("삭제할 챔피언의 이름을 입력해주세요 : ");
			scanf("%s", Name);
			Delete_R(Name);
			Keyboard();
			break;

		case 4:
			printf("4. DeleteAll : 주어진 위치의 모든 챔피언 정보를 삭제한다. \n\n");
			printf("삭제할 포지션의 이름을 입력해주세요 : ");
			scanf("%s", Position);
			DeleteAll_R(Position);
			Keyboard();
			break;

		case 5:
			printf("5. PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다. \n\n");
			PrintAll_R();
			Keyboard();
			break;

		case 6:
			printf("6. FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다. \n\n");
			FindMaxHp_R();
			printf("이름 : %s \n", Champ[Index].name);
			printf("체력 : %d \n", Champ[Index].hp);
			printf("마나 : %d \n", Champ[Index].mp);
			printf("이동속도 : %d \n", Champ[Index].speed);
			printf("사거리 : %d \n", Champ[Index].range);
			printf("포지션 : %s \n", Champ[Index].position);
			Keyboard();
			break;

		case 7:
			printf("7. SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다. \n\n");
			SortByHp_R();
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

void Search_R(char *Name) {
	if (strcmp(Name, Champ[Count].name) == 0) {
		Index = Count;
		Name_flag = 1;
	}
	else {
		Count++;
		if (Count > 50)	return;
		else Search_R(Name);
	}
}

void Insert_R(char *Name) {
	if (strcmp(Name, Champ[Count].name) == 0) {
		printf("기존에 있는 챔피언입니다.\n");
		return;
	}
	else {
		if (Champ[Count].name[0] == '\0') {
			strcpy(Champ[Count].name, Name);
			printf("체력 : ");
			scanf("%d", &Champ[Count].hp);
			printf("마나 : ");
			scanf("%d", &Champ[Count].mp);
			printf("이동속도 : ");
			scanf("%d", &Champ[Count].speed);
			printf("사거리 : ");
			scanf("%d", &Champ[Count].range);
			printf("포지션 : ");
			scanf("%s", Champ[Count].position);
			printf("\n새로운 챔피언 \"%s\"이 등록되었습니다. \n", Champ[Count].name);
		}
		else {
			Count++;
			if (Count > 50)	return;
			else Insert_R(Name);
		}
	}
}

void Delete_R(char *Name) {
	if (strcmp(Name, Champ[Count].name) == 0)
	{
		Champ[Count].name[0] = '\0';
		Champ[Count].hp = 0;
		Champ[Count].mp = 0;
		Champ[Count].speed = 0;
		Champ[Count].range = 0;
		Champ[Count].position[0] = '\0';
		printf("\n\"%s\"챔피언을 삭제했습니다.\n", Name);
		return;
	}
	else {
		Count++;
		if (Count > 50) {
			printf("\n\"%s\"챔피언은 없습니다!", Name);
			return;
		}
		else Delete_R(Name);
	}
}

void DeleteAll_R(char *Position) {
	if (strcmp(Position, Champ[Count].position) == 0)
	{
		Champ[Count].name[0] = '\0';
		Champ[Count].hp = 0;
		Champ[Count].mp = 0;
		Champ[Count].speed = 0;
		Champ[Count].range = 0;
		Champ[Count].position[0] = '\0';
		Count++;
		if (Count > 50)	return;
		else DeleteAll_R(Position);
	}
	else {
		Count++;
		if (Count > 50) {
			printf("\n\"%s\"포지션을 모두 삭제했습니다!", Position);
			return;
		}
		else DeleteAll_R(Position);
	}
}

void PrintAll_R() {
	if (Champ[Count].speed != 0) {
		printf("\n이름 : %s \n", Champ[Count].name);
		printf("체력 : %d \n", Champ[Count].hp);
		printf("마나 : %d \n", Champ[Count].mp);
		printf("이동속도 : %d \n", Champ[Count].speed);
		printf("사거리 : %d \n", Champ[Count].range);
		printf("포지션 : %s \n", Champ[Count].position);
		Count++;
		if (Count > 50) return;
		else PrintAll_R();
	}
	else {
		Count++;
		if (Count > 50) return;
		else PrintAll_R();
	}
}

void FindMaxHp_R() {
	if (Champ[Index].hp > Champ[Count+1].hp) {
		Index = Index;
	}
	else Index = Count + 1;
		
	//ptr->hp = Champ[Count+1].hp;
	
	Count++;
	if (Count > 49) return;
	else FindMaxHp_R();
}

void SortByHp_R() {
	Champion _Champ;
	if (Champ[Count].hp > Champ[Count + 1].hp) {
		Count++;
		if (Count > 50) return;
		else SortByHp_R();
	}
	else {
		_Champ = Champ[Count];
		Champ[Count] = Champ[Count + 1];
		Champ[Count + 1] = _Champ;
		Count++;
		if (Count > 50) return;
		else SortByHp_R();
	}
}

void Keyboard() {
	for (;;) {
		Key = _getch();
		if (Key == 13) break;
	}
}