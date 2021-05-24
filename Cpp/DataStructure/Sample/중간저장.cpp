// 2014132035  ����ö
// 5��° ���� : LOL DIC with Linked List

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

	struct NODE *head = (NODE*)malloc(sizeof(struct NODE));    // �Ӹ� ��� ����
														// �Ӹ� ���� �����͸� �������� ����

	struct NODE *node1 = (NODE*)malloc(sizeof(struct NODE));   // ù ��° ��� ����
	struct NODE *node2 = (NODE*)malloc(sizeof(struct NODE));   // �� ��° ��� ����
	head->next = node1;                                 // �Ӹ� ��� ������ ù ��° ���
	*node1 = { node2, "�ֽ�", 540, 280, 325, 600, "ADC" };
	//node1->hp = 10;                                   // ù ��° ��忡 10 ����

	//struct NODE *node2 = (NODE*)malloc(sizeof(struct NODE));   // �� ��° ��� ����
	//node1->next = node2;                                // ù ��° ��� ������ �� ��° ���
	//node2->hp = 20;                                   // �� ��° ��忡 20 ����
	*node2 = { NULL, "��̶�", 530, 349, 335, 500, "ADC" };

	//node2->next = NULL;                                 // �� ��° ��� ������ ��尡 ����(NULL)

	struct NODE *curr = head->next;    // ���� ����Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
	while (curr != NULL)               // �����Ͱ� NULL�� �ƴ� �� ��� �ݺ�
	{
		printf("%d\n", curr->hp);    // ���� ����� ������ ���
		curr = curr->next;             // �����Ϳ� ���� ����� �ּ� ����
	}

	free(node2);    // ��� �޸� ����
	free(node1);    // ��� �޸� ����
	free(head);     // �Ӹ� ��� �޸� ����

	

	while (1) {
		Amount = 0;
		Name_flag = 0;

		printf("LOL Dictionary�Դϴ�. \n\n");
		printf("1. Search : �־��� è�Ǿ��� ������ ����Ѵ�. \n");
		printf("2. Insert : ���ο� è�Ǿ��� ������ �Է¹޾ƻ����Ѵ�. \n");
		printf("3. Delete : �־��� è�Ǿ� ���� ������ �����Ѵ�. \n");
		printf("4. DeleteAll : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�. \n");
		printf("5. PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�. \n");
		printf("6. FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�. \n");
		printf("7. SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�. \n\n");

		printf("<������ ��ϵ� è�Ǿ�>\n");
		for (int i = 0; i < 50; i++) {
			if (Champ[i].name[0] != '\0') {
				Amount++;
				printf("%s, ", Champ[i].name);
			}
		}
		
		char* Name2 = (char*)malloc(20 * sizeof(char));
		Name2 = Champ[22].name;
		printf("\n\n%p, %s", *Name2, *Champ[22].name);

		printf("\n\n���� ��ϵ� è�Ǿ��� �� : %d", Amount);
		printf("\n\n���ϴ� ����� ������ : ");
		scanf("%d", &Option);
		printf("\n");

		switch (Option) {
		case 1:
			printf("1. Search : �־��� è�Ǿ��� ������ ����Ѵ�. \n\n");
			printf("�˻��� è�Ǿ��� �̸��� �Է����ּ��� : ");
			scanf("%s", Name);
			Search(Name);
			Keyboard();
			break;

		case 2:
			printf("2. Insert : ���ο� è�Ǿ��� ������ �Է¹޾� �����Ѵ�. \n\n");
			Insert();
			Keyboard();
			break;

		case 3:
			printf("3. Delete : �־��� è�Ǿ� ���� ������ �����Ѵ�. \n\n");
			printf("������ è�Ǿ��� �̸��� �Է����ּ��� : ");
			scanf("%s", Name);
			Delete(Name);
			Keyboard();
			break;

		case 4:
			printf("4. DeleteAll : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�. \n\n");
			printf("������ �������� �̸��� �Է����ּ��� : ");
			scanf("%s", Position);
			DeleteAll(Position);
			Keyboard();
			break;

		case 5:
			printf("5. PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�. \n\n");
			PrintAll();
			Keyboard();
			break;

		case 6:
			printf("6. FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�. \n\n");
			FindMaxHp();
			Keyboard();
			break;

		case 7:
			printf("7. SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�. \n\n");
			SortByHp();
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

void Search(char *Name) {
	for (int i = 0; i < 50; i++) {
		if (strcmp(Name, Champ[i].name) == 0) {
			printf("\n�̸� : %s \n", Champ[i].name);
			printf("ü�� : %d \n", Champ[i].hp);
			printf("���� : %d \n", Champ[i].mp);
			printf("�̵��ӵ� : %d \n", Champ[i].speed);
			printf("��Ÿ� : %d \n", Champ[i].range);
			printf("������ : %s \n", Champ[i].position);
			Name_flag = 1;
			return;
		}
	}
	if (Name_flag != 1) printf("\n\"%s\"è�Ǿ��� �����ϴ�!", Name);
}

void Insert() {
	char NAME[20];
	printf("���� ����� è�Ǿ��� ������ �Է����ּ���.\n\n");
	printf("�̸� : ");
	scanf("%s", NAME);
	for (int i = 0; i < 50; i++)
	{
		if (strcmp(NAME, Champ[i].name) == 0)
		{
			printf("������ �ִ� è�Ǿ��Դϴ�.\n");
			return;
		}
		else Name_flag = 1;
	}

	if (Name_flag == 1) {
		for (int i = 0; i < 50; i++) {
			if (Champ[i].name[0] == '\0') {
				strcpy(Champ[i].name, NAME);
				printf("ü�� : ");
				scanf("%d", &Champ[i].hp);
				printf("���� : ");
				scanf("%d", &Champ[i].mp);
				printf("�̵��ӵ� : ");
				scanf("%d", &Champ[i].speed);
				printf("��Ÿ� : ");
				scanf("%d", &Champ[i].range);
				printf("������ : ");
				scanf("%s", Champ[i].position);
				printf("\n���ο� è�Ǿ� \"%s\"�� ��ϵǾ����ϴ�. \n", Champ[i].name);
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
			printf("\n\"%s\"è�Ǿ��� �����߽��ϴ�.\n", Name);
			Name_flag = 1;
			return;
		}
		else Name_flag = 0;
	}

	if (Name_flag != 1) printf("\n\"%s\"è�Ǿ��� �����ϴ�!", Name);
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

	if (Name_flag != 1) printf("\"%s\"�������� �����ϴ�!", Position);
	else printf("\"%s\"�������� �����߽��ϴ�.", Position);
}

void PrintAll() {
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

void FindMaxHp() {
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
	printf("������ �Ϸ�Ǿ����ϴ�. \n");
}

void Keyboard() {
	for (;;) {
		Key = _getch();
		if (Key == 13) return;
	}
}