// 2014132035  ����ö
// 3��° ���� : LOL DIC

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
	Champ[0] = { "����", 620, 0, 340, 175, "TOP" };
	Champ[1] = { "������", 562, 500, 335, 125, "MID" };
	Champ[2] = { "���÷�ũ", 540, 282, 345, 125, "TOP" };
	Champ[3] = { "�׶󰡽�", 600, 400,330,125,"JNG" };
	Champ[4] = { "�׷��̺���", 555,325,345,425,"JNG" };
	Champ[5] = { "����",510, 100, 335, 175, "TOP" };
	Champ[6] = { "����", 475,365,335,550,"SUP" };
	Champ[7] = { "������",561,326,350,125,"TOP" };
	Champ[8] = { "��ƿ����",576,400,325,175,"SUP" };
	Champ[9] = { "����",585,275,345,125,"JNG" };
	Champ[10] = { "�ϴ޸�",545,296,335,525,"JNG" };
	Champ[11] = { "����", 540,450,340,550,"MID" };
	Champ[12] = { "�ٸ��콺", 582,263,340,175,"TOP" };
	Champ[13] = { "���ֳ̾�", 570,375,345,150, "MID" };
	Champ[14] = { "�巹�̺�",605,361,330,550,"ADC" };
	Champ[15] = { "������", 575,300,340,550,"MID" };
	Champ[16] = { "��ĭ", 540,315,335,300,"SUP" };
	Champ[17] = { "���ӽ�", 564,310,335,125,"JNG" };
	Champ[18] = { "����", 490, 480, 330, 550, "MID" };
	Champ[19] = { "����", 589, 100, 345, 125, "TOP" };
	Champ[20] = { "�ֽ�", 540, 280, 325,600, "ADC" };
	Champ[21] = { "��̶�", 530, 349, 335, 500, "ADC" };
	
	Array2LinkedList();
	// �� ��ũ �����ϱ�
	HEAD *Head; // ���� ������
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

		printf("LOL Dictionary�Դϴ�. \n\n");
		printf("1. Search_SL : �־��� è�Ǿ��� ������ ����Ѵ�. \n");
		printf("2. Insert_SL_SL : ���ο� è�Ǿ��� ������ �Է¹޾ƻ����Ѵ�. \n");
		printf("3. Delete_SL : �־��� è�Ǿ� ���� ������ �����Ѵ�. \n");
		printf("4. DelateAll_SL : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�. \n");
		printf("5. PrintAll_SL : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�. \n");
		printf("6. FindMaxHp_SL : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�. \n");
		printf("7. SortByHp_SL : ü���� ū è�Ǿ���� ������� �����Ѵ�. \n\n");

		printf("<������ ��ϵ� è�Ǿ�>\n");
		for (int i = 0; i < 50; i++) {
			if (champ[i]->name[0] != '\0') {
				Amount++;
				printf("%s, ", champ[i]->name);
			}
		}

		printf("\n\n���� ��ϵ� è�Ǿ��� �� : %d", Amount);
		printf("\n\n���ϴ� ����� ������ : ");
		scanf("%d", &Option);
		printf("\n");

		switch (Option) {
		case 1:
			printf("1. Search_SL : �־��� è�Ǿ��� ������ ����Ѵ�. \n\n");
			printf("�˻��� è�Ǿ��� �̸��� �Է����ּ��� : ");
			scanf("%s", Name);
			Search_SL(Name);
			Keyboard();
			break;

		case 2:
			printf("2. Insert_SL_SL : ���ο� è�Ǿ��� ������ �Է¹޾� �����Ѵ�. \n\n");
			//Insert_SL();
			char NAME[20];
			printf("���� ����� è�Ǿ��� ������ �Է����ּ���.\n\n");
			printf("�̸� : ");
			scanf("%s", NAME);
			for (int i = 0; i < 50; i++)
			{
				if (strcmp(NAME, champ[i]->name) == 0)
				{
					printf("������ �ִ� è�Ǿ��Դϴ�.\n");
					return;
				}
				else Name_flag = 1;
			}

			if (Name_flag == 1) {
				cNode *newNode;
				cNode *temp;
				char *name, *position;
				newNode = (cNode*)malloc(sizeof(cNode));
				printf("\n�̸� : ");
				scanf("%s", name);
				strcpy(newNode->name, name);
				printf("\nü�� : ");
				scanf("%d", &newNode->hp);
				printf("\n���� : ");
				scanf("%d", &newNode->mp);
				printf("\n�̵��ӵ� : ");
				scanf("%d", &newNode->speed);
				printf("\n��Ÿ� : ");
				scanf("%d", &newNode->range);
				printf("\n������ : ");
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
			printf("3. Delete_SL : �־��� è�Ǿ� ���� ������ �����Ѵ�. \n\n");
			printf("������ è�Ǿ��� �̸��� �Է����ּ��� : ");
			scanf("%s", Name);
			Delete_SL(Name);
			Keyboard();
			break;

		case 4:
			printf("4. DelateAll_SL : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�. \n\n");
			printf("������ �������� �̸��� �Է����ּ��� : ");
			scanf("%s", Position);
			DelateAll_SL(Position);
			Keyboard();
			break;

		case 5:
			printf("5. PrintAll_SL : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�. \n\n");
			PrintAll_SL();
			Keyboard();
			break;

		case 6:
			printf("6. FindMaxHp_SL : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�. \n\n");
			FindMaxHp_SL();
			Keyboard();
			break;

		case 7:
			printf("7. SortByHp_SL : ü���� ū è�Ǿ���� ������� �����Ѵ�. \n\n");
			SortByHp_SL();
			Keyboard();
			break;

		default:
			printf("1 ~ 7���� �Է����ּ���. \n");
			Keyboard();
			break;
		}
		system("cls");
	}
}

void Search_SL(char *Name) {
	for (int i = 0; i < 50; i++) {
		if (strcmp(Name, champ[i]->name) == 0) {
			printf("\n�̸� : %s \n", champ[i]->name);
			printf("ü�� : %d \n", champ[i]->hp);
			printf("���� : %d \n", champ[i]->mp);
			printf("�̵��ӵ� : %d \n", champ[i]->speed);
			printf("��Ÿ� : %d \n", champ[i]->range);
			printf("������ : %s \n", champ[i]->position);
			Name_flag = 1;
			return;
		}
	}
	if (Name_flag != 1) printf("\n\"%s\"è�Ǿ��� �����ϴ�!", Name);
}

void Insert_SL() {
	char NAME[20];
	printf("���� ����� è�Ǿ��� ������ �Է����ּ���.\n\n");
	printf("�̸� : ");
	scanf("%s", NAME);
	for (int i = 0; i < 50; i++)
	{
		if (strcmp(NAME, champ[i]->name) == 0)
		{
			printf("������ �ִ� è�Ǿ��Դϴ�.\n");
			return;
		}
		else Name_flag = 1;
	}

	if (Name_flag == 1) {
		cNode *newNode;
		cNode *temp;
		char *name, *position;
		newNode = (cNode*)malloc(sizeof(cNode));
		printf("\n�̸� : ");
		scanf("%s", name);
		strcpy(newNode->name, name);
		printf("\nü�� : ");
		scanf("%d", newNode->hp);
		printf("\n���� : ");
		scanf("%d", newNode->mp);
		printf("\n�̵��ӵ� : ");
		scanf("%d", newNode->speed);
		printf("\n��Ÿ� : ");
		scanf("%d", newNode->range);
		printf("\n������ : ");
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
			printf("\n\"%s\"è�Ǿ��� �����߽��ϴ�.\n", Name);
			Name_flag = 1;
			return;
		}
		else Name_flag = 0;
	}

	if (Name_flag != 1) printf("\n\"%s\"è�Ǿ��� �����ϴ�!", Name);
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

	if (Name_flag != 1) printf("\"%s\"�������� �����ϴ�!", Position);
	else printf("\"%s\"�������� �����߽��ϴ�.", Position);
}

void PrintAll_SL() {
	for (int i = 0; i < 50; i++) {
		if (Champ[i].speed != 0) {
			printf("\n�̸� : %s \n", Champ[i].name);
			printf("ü�� : %d \n", Champ[i].hp);
			printf("���� : %d \n", Champ[i].mp);
			printf("�̵��ӵ� : %d \n", Champ[i].speed);
			printf("��Ÿ� : %d \n", Champ[i].range);
			printf("������ : %s \n", Champ[i].position);
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
			printf("�̸� : %s \n", Champ[i].name);
			printf("ü�� : %d \n", Champ[i].hp);
			printf("���� : %d \n", Champ[i].mp);
			printf("�̵��ӵ� : %d \n", Champ[i].speed);
			printf("��Ÿ� : %d \n", Champ[i].range);
			printf("������ : %s \n", Champ[i].position);
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
	printf("������ �Ϸ�Ǿ����ϴ�. \n");
}

void Array2LinkedList() {
	// ����ü ���� �����ϱ� (è�Ǿ� ����)
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