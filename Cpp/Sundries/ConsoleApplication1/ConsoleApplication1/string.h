

class Date
{
	int year;
	int month;
	int day;
public:
	Date();
	Date(int _year, int _month, int _day);
	void setDate(int _year, int _month, int _day)
	{
		year = _year, month = _month, day = _day;
	}
	int getDate() { return year, month, day; }
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
};

class Product :public Date
{
private:
	string name;
	string company;
	int price;
public:
	Product();
	Product(string _name, string _company, int _price, int _year, int _month, int _day) :Date(_year, _month, _day)
	{
		name = _name;
		company = _company;
		price = _price;
	}

	void setProduct(string _name, string _company, int _price, int _year, int _month, int _day)
	{
		name = _name;
		company = _company;
		price = _price;
	}
	int getProduct() { return name, company, price; }
	void display();
};
