#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

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

Champion Champ[50];
char Name[20], Position[10];
int Compare = 50, Number, Key, maxHP, Option;

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
	Champ[15] = { "������", 575,300,340,550,"MID"};
	Champ[16] = { "��ĭ", 540,315,335,300,"SUP" };
	Champ[17] = { "���ӽ�", 564,310,335,125,"JNG" };
	Champ[18] = { "����", 490, 480, 330, 550, "MID" };
	Champ[19] = { "����", 589, 100, 345, 125, "TOP" };
	Champ[20] = { "�ֽ�", 540, 280, 325,600, "ADC" };
	Champ[21] = { "��̶�", 530, 349, 335, 500, "ADC" };

	while (1)
	{
		printf("LOL Dictionary�Դϴ�.");
		printf("\n"); printf("\n");
		printf("1. è�Ǿ� ���� Ȯ���ϱ�");
		printf("\n");
		printf("2. ���ο� è�Ǿ� ����ϱ�");
		printf("\n");
		printf("3. è�Ǿ� �����ϱ�");
		printf("\n");
		printf("4. �ش� �������� ��� è�Ǿ� �����ϱ�");
		printf("\n");
		printf("5. ��� è�Ǿ��� ������ Ȯ���ϱ�");
		printf("\n");
		printf("6. ���� ü���� ū è�Ǿ��� ������ Ȯ���ϱ�");
		printf("\n");
		printf("7. ü���� ū è�Ǿ���� ������� �����ϱ�");
		printf("\n"); printf("\n");
		printf("<������ ��ϵ� è�Ǿ�>");
		printf("\n");
		int Number = 0;
		for (int i = 0; i < 50; i++)
		{
			if (Champ[i].speed != 0){
				printf("%s, ", Champ[i].name);
				Number++;
			}
		}
		printf("\n");
		printf("\n");
		printf("���� ��ϵ� è�Ǿ� �� : %d", Number);
		printf("\n");
		printf("\n");
		printf("����ϰ� ���� ����� ������ : ");
		scanf("%d", &Option);
		printf("\n");

		switch (Option)
		{
			case 1:
				printf("1. è�Ǿ� ���� Ȯ���ϱ�");
				printf("\n"); printf("\n");
				printf("�˻��Ͻ� è�Ǿ��� �̸��� �Է����ּ��� : ");
				scanf("%s", Name);
				printf("\n");
				Search(Name);
				Keyboard();
				break;

			case 2:
				printf("2. ���ο� è�Ǿ� ����ϱ�");
				printf("\n"); printf("\n");
				Insert();
				Keyboard();
				break;

			case 3:
				printf("3. è�Ǿ� �����ϱ�");
				printf("\n"); printf("\n");
				printf("�����Ͻ� è�Ǿ��� �̸��� �Է����ּ��� : ");
				scanf("%s", Name);
				printf("\n");
				Delete(Name);
				Keyboard();
				break;

			case 4:
				printf("4. �ش� �������� ��� è�Ǿ� �����ϱ�");
				printf("\n"); printf("\n");
				printf("�����Ͻ� ������ �Է����ּ��� : ");
				scanf("%s", Position);
				printf("\n");
				DeleteAll(Position);
				Keyboard();
				break;

			case 5:
				printf("5. ��� è�Ǿ��� ������ Ȯ���ϱ�");
				printf("\n"); printf("\n");
				PrintAll();
				Keyboard();
				break;

			case 6:
				printf("6. ���� ü���� ū è�Ǿ��� ������ Ȯ���ϱ�");
				printf("\n"); printf("\n");
				FindMaxHp();
				Keyboard();
				break;

			case 7:
				printf("7. ü���� ū è�Ǿ���� ������� �����ϱ�");
				printf("\n"); printf("\n");
				SortByHp();
				Keyboard();
				break;
		}
		system("cls");
	}
}

void Search(char *Name) {
	for (int i = 0; i < 50; i++)
	{
		Compare = strcmp(Name, Champ[i].name);
		if (Compare == 0)
		{
			printf("������ �Է��Ͻ� è�Ǿ��� �����Դϴ�. \n\n");
			printf("�̸� : %s \n", Champ[i].name);
			printf("ü�� : %d \n", Champ[i].hp);
			printf("���� : %d \n", Champ[i].mp);
			printf("�̵��ӵ� : %d \n", Champ[i].speed);
			printf("�����Ÿ� : %d \n", Champ[i].range);
			printf("������ : %s \n", Champ[i].position);
		}
	}	
}

void Insert() {
	Number++;
	printf("è�Ǿ��� ������ �Է����ּ���.");
	printf("\n"); printf("\n");
	printf("�̸� : ");
	scanf("%s", Champ[Number].name);
	printf("ü�� : ");
	scanf("%d", &Champ[Number].hp);
	printf("���� : ");
	scanf("%d", &Champ[Number].mp);
	printf("�̵��ӵ� : ");
	scanf("%d", &Champ[Number].speed);
	printf("�����Ÿ� : ");
	scanf("%d", &Champ[Number].range);
	printf("������ : ");
	scanf("%s", Champ[Number].position);
}

void Delete(char *Name) {
	for (int i = 0; i < 50; i++)
	{
		Compare = strcmp(Name, Champ[i].name);
		if (Compare == 0)
		{
			Champ[i].name[0] = '\0';
			Champ[i].hp = 0;
			Champ[i].mp = 0;
			Champ[i].speed = 0;
			Champ[i].range = 0;
			Champ[i].position[0] = '\0';
		}
	}
	printf("è�Ǿ� \"%s\"�� �����߽��ϴ�.", Name);
}

void DeleteAll(char *Position) {
	for (int i = 0; i < 50; i++)
	{
		Compare = strcmp(Position, Champ[i].position);
		if (Compare == 0)
		{
			Champ[i].name[0] = '\0';
			Champ[i].hp = 0;
			Champ[i].mp = 0;
			Champ[i].speed = 0;
			Champ[i].range = 0;
			Champ[i].position[0] = '\0';
		}
	}
	printf("%s è�Ǿ��� ��� �����߽��ϴ�.", Position);
}

void PrintAll() {
	for (int i = 0; i < 50; i++)
	{
			printf("�Է��Ͻ� è�Ǿ��� �����Դϴ�. \n\n");
			printf("�̸� : %s \n", Champ[i].name);
			printf("ü�� : %d \n", Champ[i].hp);
			printf("���� : %d \n", Champ[i].mp);
			printf("�̵��ӵ� : %d \n", Champ[i].speed);
			printf("�����Ÿ� : %d \n", Champ[i].range);
			printf("������ : %s \n", Champ[i].position);
	}
}

void FindMaxHp() {
	for (int i = 0; i < 50; i++)
	{
		if (Champ[i].hp >= maxHP)
		{
			maxHP = Champ[i].hp;
		}
	}
	for (int i = 0; i < 50; i++) {
		if (Champ[i].hp == maxHP)
		{
			printf("ü���� ���� ���� è�Ǿ��� \"%s\"�Դϴ�. \n\n", Champ[i].name);
			printf("�̸� : %s \n", Champ[i].name);
			printf("ü�� : %d \n", Champ[i].hp);
			printf("���� : %d \n", Champ[i].mp);
			printf("�̵��ӵ� : %d \n", Champ[i].speed);
			printf("�����Ÿ� : %d \n", Champ[i].range);
			printf("������ : %s \n", Champ[i].position);
		}
	}
}

void SortByHp() {
	Champion _Champ;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (Champ[i].hp >= Champ[j].hp)
			{
				_Champ = Champ[i];
				Champ[i] = Champ[j];
				Champ[j] = _Champ;
			}
		}
	}
	printf("ü���� ū ������� �����߽��ϴ�.");
}

void Keyboard() {
	for (;;)
	{
		Key = getch();
		if (Key == 13) break;
	}
}