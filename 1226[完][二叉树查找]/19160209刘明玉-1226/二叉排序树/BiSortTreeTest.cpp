#include"BiSortTree.h"
#include<iostream>
using namespace std;
int main()
{
	int a[6] = { 12,56,89,1,33,47 };
	int n = 6;
	BiSortTree tree(a, n);
	cout << "二叉树为：";
	tree.Print();
	int temp;
	cout << "\n请输入您想查找的值：";
	cin >> temp;
	tree.Search(temp);
	cout << "请输入您想删除的值：";
	cin >> temp;
	tree.Delete(temp);
	tree.Print();
	cout << "\n请输入您想插入的值：";
	cin >> temp;
	tree.Insert(temp);
	tree.Print();
	cout << endl;
	return 0;
}