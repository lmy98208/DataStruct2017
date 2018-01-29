#include"Goods.h"
#include<iostream>
using namespace std;

void Goods::operator=(Goods &g)
{
	//Goods temp;
	Number = g.Number;
	Name = g.Name;
	Price = g.Price;
	Stock = g.Stock;
	Low = g.Low;
}

//修改当前库存量

bool Goods::operator==(Goods &g)
{
	return Number == g.Number;
}

bool Goods::operator<(Goods &g)
{
	if (Number < g.Number)
		return true;
	return false;
}

bool Goods::operator>(Goods & g)
{
	if (Number > g.Number)
		return true;
	return false;
}

ostream& operator<<(ostream& out, Goods& g) {
	return out << '\t' << g.Number << '\t' << g.Name << '\t'
		<< g.Price << '\t' << g.Stock << '\t' << g.Low << endl;
}

istream &operator >> (istream &i, Goods &g)
{
	return i >> g.Number >> g.Name >> g.Price >> g.Stock >> g.Low;
}