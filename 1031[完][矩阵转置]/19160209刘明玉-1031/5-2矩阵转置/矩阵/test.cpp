#include"SparseMatrix.cpp"

#include<vector>
#include<iostream>
using namespace std;

int main()
{
	cout << "�����������С��С�����Ԫ������";
	int rw, cl, num;
	cin >> rw >> cl >> num;
	Triple<int> tlist[20];
	for (int i = 0; i < num; i++)
	{
		cout << "�������" << i + 1 << "������Ԫ���С��С�Ԫ�ش�С��";
		cin >> tlist[i].r >> tlist[i].c >> tlist[i].elem;
	}
	//Triple<int> tlist[10] = { {0,0,2},{1,2,6},{2,1,10} };

	SparseMatrix<int> a(tlist, rw, cl, num);
	SparseMatrix<int> b(tlist, 0, 0, num);
	SparseMatrix<int> c(tlist, 0, 0, num);
	cout << "ԭ����Ϊ:\n";
	a.print();
	a.trans(b);
	cout << "����ת����\n";
	b.print();
	a.quicktrans(c);
	cout << "����ת�ú�\n";
	c.print();
	return 0;
}