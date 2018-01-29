#include<string>
#include<iostream>
using namespace std;

class Goods
{
	string Number;//����
	string Name;//����
	double Price;//�۸�
	int Stock;//���
	int Low;//��Ϳ��
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
	int UpdateStock(int k) { Stock = k; return k; }//�޸Ŀ��
	double UpdatePrice(double p) { Price = p; }
	string GetNumber() { return Number; }
	string GetName() { return Name; }
	double GetPrice() { return Price; }
	int GetStock() { return Stock; }
	int GetLow() { return Low; }
	//���������
	void operator=(Goods&);
	bool operator==(Goods&);
	bool operator<(Goods&);
	bool operator>(Goods&);
	friend ostream& operator<<(ostream& out, Goods& g);
	friend istream &operator >> (istream &i, Goods &g);
};