#include <iostream>
#include <string>
#include "string.h"

using namespace std;

int main()
{
	Product *p = new Product; //��ü ����

	p->setProduct("�����", "���", 700, 2011, 4, 21); //��ǰ��, ������, ����, ������������

	p->display();

	Product p1("Ȩ����", "�Ե�", 1200, 2011, 4, 21);

	p1.display(); // ��ü ����

	delete p; //��ü �Ҹ�

	return 0;
}