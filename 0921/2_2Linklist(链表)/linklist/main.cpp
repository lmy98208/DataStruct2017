#include<iostream>
#include"Linklist.cpp"
using namespace std;
int main()
{
	int data[5] = { 56,89,101,222,256 };
	cout << "元素为：";
	for (int i = 0; i < 5; i++)
		cout << data[i] << ",";
	cout << "\n正在创建LinkList1...\n";
	LinkList<int> a(data,5);
	//a.PrintLinkList();
	cout << "\n请输入您想查询的位置：";
	int pos, tmp;
	cin >> pos;
	tmp=a.Get(pos-1);
	cout << "位置" << pos << "对应的数值为" << tmp;
	cout << "。\n\n请输入您查询的数值：";
	cin >> tmp;
	pos = a.Locate(tmp);
	if (pos)
		cout << tmp << "在位置" << pos << "上。\n";
	else
		cout << "查无此数。";
	cout << "\n请输入要添加的数字：";
	cin >> tmp;
	a.Insert(6,tmp);
	cout << "成功添加！\n";
	a.PrintLinkList();
	cout << "\n请输入要删除数字的位置：";
	cin >> tmp;
	cout<<a.Delete(tmp)<<"已删除。";
	int data_[5] = { 9,78,203,522,990 };
	cout << "\n\n元素为：";
	for (int i = 0; i < 5; i++)
		cout << data_[i] << ",";
	cout << "\n正在创建LinkList2...\n";
	LinkList<int> b(data_, 5);
	//b.PrintLinkList();
	cout << "\n合并两表：\n";
	a.Merge(a, b);
	a.PrintLinkList();
	cout << "\n逆置：\n";
	a.Invert();
	a.PrintLinkList();
	return 0;
}