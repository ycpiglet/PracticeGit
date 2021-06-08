/* ������� ���� */
#include <stdio.h>
#include <Windows.h>
#include <string.h>

/* ��ũ�� */
#define END return 0
#define TEST printf("<It is working>\n");
#define CLEAR system("cls")

#define MAX 30

/* ����ü ���� */
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

/* �Լ� ���� */
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
		printf("�̸� : %s\n", q->name);
		printf("ü�� : %d\n", q->hp);
		printf("���� : %d\n", q->mp);
		printf("�̵��ӵ� : %d\n", q->speed);
		printf("�����Ÿ�%d\n", q->range);
		printf("������%s\n", q->position);
		printf("------------------------------\n");
		q = q->link;
	}
	printf("���� �Ϸ�\n");
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

/* ���� */
int main() {

	Champion Champ[MAX] = {
		{ "����", 620, 0, 340, 175, "TOP" },
		{ "������", 562, 500, 335, 125, "MID" },
		{ "���÷�ũ", 540, 282, 345, 125, "TOP" },
		{ "�׶󰡽�", 600, 400,330,125,"JNG" },
		{ "�׷��̺���", 555,325,345,425,"JNG" },
		{ "����",510, 100, 335, 175, "TOP" },
		{ "����", 475,365,335,550,"SUP" },
		{ "������",561,326,350,125,"TOP" },
		{ "��ƿ����",576,400,325,175,"SUP" },
		{ "����",585,275,345,125,"JNG" },
		{ "�ϴ޸�",545,296,335,525,"JNG" },
		{ "����", 540,450,340,550,"MID" },
		{ "�ٸ��콺", 582,263,340,175,"TOP" },
		{ "�巹�̺�",605,361,330,550,"ADC" },
		{ "������", 575,300,340,550,"MID" },
		{ "��ĭ", 540,315,335,300,"SUP" },
		{ "���ӽ�", 564,310,335,125,"JNG" },
		{ "����", 490, 480, 330, 550, "MID" },
		{ "����", 589, 100, 345, 125, "TOP" },
		{ "�ֽ�", 540, 280, 325,600, "ADC" },
		{ "��̶�", 530, 349, 335, 500, "ADC" }
	};

	listChampion_h *List = creatLinkedList();
	
	while(1){
		
		printf("<LOL Dictionary�Դϴ�.>\n\n");
		printf(" 0. ������ ����ü è�Ǿ��� ���� ����Ʈ�� ����\n");
		printf(" 1. ��ϵ� è�Ǿ��� �������� Ȯ��\n");
		printf(" 2. ���ο� è�Ǿ� �߰�\n");
		printf(" 3. ���� è�Ǿ� ����\n");
		printf(" 4. ü�¼����� è�Ǿ� ����\n");
		printf(" 5. �ش� �������� è�Ǿ� ���� Ȯ��\n");
		printf(" 6. �ش� �������� ��� è�Ǿ� ����\n");
		printf(" 7. �ִ� ü���� ���� è�Ǿ� Ȯ��\n\n");

		int amount = 0;
		for (int i = 0; i < MAX; i++) if (Champ[i].name[0] != '\0') amount++;

		printf("<���� ��ϵ� è�Ǿ�(%d)>\n", amount);
		for (int i = 0; i < MAX; i++) if (Champ[i].name[0] != '\0') printf("%s, ", Champ[i].name);

		printf("\n\n- ���ϴ� ����� ��ȣ�� �Է��ϼ��� : ");

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
					printf("�̸� : %s\n", Champ[i].name);
					printf("ü�� : %d\n", Champ[i].hp);
					printf("���� : %d\n", Champ[i].mp);
					printf("�̵��ӵ� : %d\n", Champ[i].speed);
					printf("�����Ÿ� : %d\n", Champ[i].range);
					printf("������ : %s\n", Champ[i].position);
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
			printf("\n1~6�� ��ȣ�� �Է����ּ���!!\n");
		}

		key();
		freeLinkedList(List);
	}
	
	END;
} // end of main

/* �Լ� ���� */

void key() {
	while (1) {
		int key = _getch();

		if (key == 13) {
			break;
		}
		else printf("ENTER�� �Է��ϼ���!! ");
	}
	CLEAR;
}