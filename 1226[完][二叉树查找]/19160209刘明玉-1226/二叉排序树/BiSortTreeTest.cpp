#include"BiSortTree.h"
#include<iostream>
using namespace std;
int main()
{
	int a[6] = { 12,56,89,1,33,47 };
	int n = 6;
	BiSortTree tree(a, n);
	cout << "������Ϊ��";
	tree.Print();
	int temp;
	cout << "\n������������ҵ�ֵ��";
	cin >> temp;
	tree.Search(temp);
	cout << "����������ɾ����ֵ��";
	cin >> temp;
	tree.Delete(temp);
	tree.Print();
	cout << "\n��������������ֵ��";
	cin >> temp;
	tree.Insert(temp);
	tree.Print();
	cout << endl;
	return 0;
}