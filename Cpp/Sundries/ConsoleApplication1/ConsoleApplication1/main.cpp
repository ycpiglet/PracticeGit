#include <iostream>
#include <string>
#include "string.h"

using namespace std;

int main()
{
	Product *p = new Product; //按眉 积己

	p->setProduct("货快兵", "丑缴", 700, 2011, 4, 21); //惑前疙, 力炼荤, 啊拜, 力炼斥岿老免仿

	p->display();

	Product p1("权繁杭", "吩单", 1200, 2011, 4, 21);

	p1.display(); // 按眉 积己

	delete p; //按眉 家戈

	return 0;
}