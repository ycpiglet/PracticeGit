#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

void Search(char *Name);
void Insert();
void Delete(char *Name);
void DeleteAll(char *Position);
void Keyboard();

unsigned char Name[20], Position[10];
unsigned int Number, Compare=50, Key, MaxHP, Option;

typedef struct Champion {
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
} Champion;

Champion Champ[22];

void main() {
	Champ[0] = { "°¡·»", 100, 100, 100, 100, "TOP" };
} // main¹® Á¾·á



void Search(char *Name) {

}

void Keyboard() {
	Key = getch();
	for (;;) {
		if (Key == 13) break;
	}
}