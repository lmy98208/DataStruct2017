#include<string>
#include<iostream>
using namespace std;

class Goods
{
	string Number;//编码
	string Name;//名称
	double Price;//价格
	int Stock;//库存
	int Low;//最低库存
public:
	Goods(string num, string name, double price, int stock,int low) :
		Number(num), Name(name), Price(price), Stock(stock),Low(low)
	{}
	Goods()
	{
		Number = "0";
		Name = "Null";
		Price = 0.0;
		Stock = 0;
		Low = 0;
	}
	int UpdateStock(int k) { Stock = k; return k; }//修改库存
	double UpdatePrice(double p) { Price = p; }
	string GetNumber() { return Number; }
	string GetName() { return Name; }
	double GetPrice() { return Price; }
	int GetStock() { return Stock; }
	int GetLow() { return Low; }
	//运算符重载
	void operator=(Goods&);
	bool operator==(Goods&);
	bool operator<(Goods&);
	bool operator>(Goods&);
	friend ostream& operator<<(ostream& out, Goods& g);
	friend istream &operator >> (istream &i, Goods &g);
};