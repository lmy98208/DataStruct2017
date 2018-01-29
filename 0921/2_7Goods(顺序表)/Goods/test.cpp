#include<iostream>
#include<fstream>
#include<sstream>
#include"SeqList.cpp"
#include"Goods.h"
using namespace std;

int Menu()
{
	int n;
	cout << "*********************Menu*******************\n";
	cout << "1.打印库存表" << endl;
	cout << "2.修改及新增记录" << endl;
	cout << "3.删除指定记录" << endl;
	cout << "4.按商品代号排序" << endl;
	cout << "0.安全退出" << endl;
	cout << "*********************End********************\n";
	cout << "\n请选择：";
	cin >> n;
	return n;
}

int main()
{
	ifstream in("data.txt");
	if (!in) {
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	int count = 0, pos = 0;
	Goods str_arry[100];
	string str;
	while (getline(in, str))
	{
		istringstream sin(str);
		while (sin >> str_arry[count]) {
			count++;
		}
		pos++;
	}

	SeqList<Goods, 100> a(str_arry, pos);
	string n_index;//存放输入商品编号
	//Goods temp;//在进行各项处理方式时用到的临时商品记录
	ofstream out("data.txt");

	int choice=Menu() ;
	while (choice)
	{
		switch (choice)
		{
		case 1:
		{
			cout << "\t" << "商品编号" << "\t" << "商品名称" << "\t"
				<< "价格" << "\t" << "库存" << "\t" << "最低库存" << endl;
			a.PrintSeqList();
			break;
		}
		case 2:
		{
			cout << "请输入商品编号：";
			string index;
			cin >> index;
			Goods temp(index, "null", 0.0, 0, 0);
			int n = a.Locate(temp);
			if (n)
			{
				temp = a.Get(n);//按位查找
				cout << "请输入当前库存：";
				int p, q;
				cin >> p;
				q=temp.UpdateStock(p);
				a.UpdateData(n,temp);
				cout << "修改成功！\n";
			}
			else {
				cout << "正在创建一条新纪录。\n请输入商品的编码、名称、价格、库存、最低库存：\n";
				string name, number;
				double price;
				int stock, low;
				cin >> number >> name >> price >> stock >> low;
				Goods temp(number, name, price, stock, low);
				a.Insert(++pos, temp);
				cout << "添加成功！\n";
			}
			break;
		}
		case 3:
		{
			string in;
			cout << "请输入需要删除的商品的编号：";
			cin >> in;
			Goods temp(in, "null", 0.0, 0, 0);
			int n = a.Locate(temp);//该商品记录的位置
			cout<<a.Delete(n);
			cout << "\n此条记录删除成功！" << endl;
			break;
		}
		case 4:
		{
			a.Sort();
			cout << "Sorted!\n";
			cout << "\t" << "商品编号" << "\t" << "商品名称" << "\t"
				<< "价格" << "\t" << "库存" << "\t" << "最低库存" << endl;
			a.PrintSeqList();
			break;
		}
		case 0:
		{
			
			break;
		}
		default:cout << "请输入正确的序号！\n";
			break;
		}
		choice = Menu();
	}
	if (!out)
	{
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	for (int i = 1; i <= a.ListLength(); i++)//将库存表的信息读入文件
	{
		out << a.Get(i);
	}
	cout << "Updated！" << endl;
	cout << "************End***********" << endl;
	
	return 0;
}