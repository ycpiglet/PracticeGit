// 2014132035  ����ö
// 3��° ���� : LOL DIC

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

	while (1) {
		Amount = 0;
		Name_flag = 0;
		Count = 0;
		Index = 0;
		//int *prtMax = Champ[0].hp;

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

		printf("\n\n���� ��ϵ� è�Ǿ��� �� : %d", Amount);
		printf("\n\n���ϴ� ����� ������ : ");
		scanf("%d", &Option);
		printf("\n");

		switch (Option) {
		case 1:
			printf("1. Search : �־��� è�Ǿ��� ������ ����Ѵ�. \n\n");
			printf("�˻��� è�Ǿ��� �̸��� �Է����ּ��� : ");
			scanf("%s", Name);
			Search_R(Name);
			if (Name_flag == 1) {
				printf("\n�̸� : %s \n", Champ[Index].name);
				printf("ü�� : %d \n", Champ[Index].hp);
				printf("���� : %d \n", Champ[Index].mp);
				printf("�̵��ӵ� : %d \n", Champ[Index].speed);
				printf("��Ÿ� : %d \n", Champ[Index].range);
				printf("������ : %s \n", Champ[Index].position);
			}
			Keyboard();
			break;

		case 2:
			printf("2. Insert : ���ο� è�Ǿ��� ������ �Է¹޾� �����Ѵ�. \n\n");
			printf("�˻��� è�Ǿ��� �̸��� �Է����ּ��� : ");
			scanf("%s", Name);
			Insert_R(Name);
			Keyboard();
			break;

		case 3:
			printf("3. Delete : �־��� è�Ǿ� ���� ������ �����Ѵ�. \n\n");
			printf("������ è�Ǿ��� �̸��� �Է����ּ��� : ");
			scanf("%s", Name);
			Delete_R(Name);
			Keyboard();
			break;

		case 4:
			printf("4. DeleteAll : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�. \n\n");
			printf("������ �������� �̸��� �Է����ּ��� : ");
			scanf("%s", Position);
			DeleteAll_R(Position);
			Keyboard();
			break;

		case 5:
			printf("5. PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�. \n\n");
			PrintAll_R();
			Keyboard();
			break;

		case 6:
			printf("6. FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�. \n\n");
			FindMaxHp_R();
			printf("�̸� : %s \n", Champ[Index].name);
			printf("ü�� : %d \n", Champ[Index].hp);
			printf("���� : %d \n", Champ[Index].mp);
			printf("�̵��ӵ� : %d \n", Champ[Index].speed);
			printf("��Ÿ� : %d \n", Champ[Index].range);
			printf("������ : %s \n", Champ[Index].position);
			Keyboard();
			break;

		case 7:
			printf("7. SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�. \n\n");
			SortByHp_R();
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
		printf("������ �ִ� è�Ǿ��Դϴ�.\n");
		return;
	}
	else {
		if (Champ[Count].name[0] == '\0') {
			strcpy(Champ[Count].name, Name);
			printf("ü�� : ");
			scanf("%d", &Champ[Count].hp);
			printf("���� : ");
			scanf("%d", &Champ[Count].mp);
			printf("�̵��ӵ� : ");
			scanf("%d", &Champ[Count].speed);
			printf("��Ÿ� : ");
			scanf("%d", &Champ[Count].range);
			printf("������ : ");
			scanf("%s", Champ[Count].position);
			printf("\n���ο� è�Ǿ� \"%s\"�� ��ϵǾ����ϴ�. \n", Champ[Count].name);
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
		printf("\n\"%s\"è�Ǿ��� �����߽��ϴ�.\n", Name);
		return;
	}
	else {
		Count++;
		if (Count > 50) {
			printf("\n\"%s\"è�Ǿ��� �����ϴ�!", Name);
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
			printf("\n\"%s\"�������� ��� �����߽��ϴ�!", Position);
			return;
		}
		else DeleteAll_R(Position);
	}
}

void PrintAll_R() {
	if (Champ[Count].speed != 0) {
		printf("\n�̸� : %s \n", Champ[Count].name);
		printf("ü�� : %d \n", Champ[Count].hp);
		printf("���� : %d \n", Champ[Count].mp);
		printf("�̵��ӵ� : %d \n", Champ[Count].speed);
		printf("��Ÿ� : %d \n", Champ[Count].range);
		printf("������ : %s \n", Champ[Count].position);
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