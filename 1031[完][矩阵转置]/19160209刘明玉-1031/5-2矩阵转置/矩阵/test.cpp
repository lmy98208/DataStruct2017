#include"SparseMatrix.cpp"

#include<vector>
#include<iostream>
using namespace std;

int main()
{
	cout << "请输入矩阵的行、列、非零元个数：";
	int rw, cl, num;
	cin >> rw >> cl >> num;
	Triple<int> tlist[20];
	for (int i = 0; i < num; i++)
	{
		cout << "请输入第" << i + 1 << "个非零元的行、列、元素大小：";
		cin >> tlist[i].r >> tlist[i].c >> tlist[i].elem;
	}
	//Triple<int> tlist[10] = { {0,0,2},{1,2,6},{2,1,10} };

	SparseMatrix<int> a(tlist, rw, cl, num);
	SparseMatrix<int> b(tlist, 0, 0, num);
	SparseMatrix<int> c(tlist, 0, 0, num);
	cout << "原矩阵为:\n";
	a.print();
	a.trans(b);
	cout << "朴素转换后：\n";
	b.print();
	a.quicktrans(c);
	cout << "快速转置后：\n";
	c.print();
	return 0;
}