#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class fruit
{
public:
	

	int cost;
	string name;

	int plus();
private:

};

int fruit::plus() {
	return cost + name.size();
}


int main() {

	fruit korea;
	korea.name = "apple";
	korea.cost = 1000;

	cout << korea.cost << endl;
	cout << "����� = " << korea.plus() << endl;

	//���� : ������, ���������, �Ҹ���
	

	return 0;
}