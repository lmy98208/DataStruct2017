#include<iostream>
#include"node.h"
int main()
{
	int a[7] = { 2,56,23,10,59,19,21 };
	int i = 0;
	TmpNode test(a,7);
	test.print();
	cout << "����������鿴�ĵ�����n����㣺";
	int k;
	cin >> k;
	if (k <= 0 || k > 7)
	{
		cout << "error!\n";
		exit(1);
	}
	cout << "1.������" << k << "������Ӧ��Ԫ��Ϊ��";
	cout << test.LastNnode(k)->data << endl;
	cout << "2.������" << k << "������Ӧ��Ԫ��Ϊ��";
	cout << test.LastNnode2(k)->data << endl;
	return 0;
}