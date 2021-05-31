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
	cout << "결과는 = " << korea.plus() << endl;

	//숙제 : 생성자, 복사생성자, 소멸자
	

	return 0;
}