#include<iostream>
using namespace std;
void Swap_xor(int p, int q)//亦或
{
	p = p^q;
	q = q^p;
	p = p^q;
	cout << "交换后： p=" << p << " q=" << q << endl;
}
void Swap_count(int p, int q)//算数加减
{
	p = p + q;
	q = p - q;
	p = p - q;
	cout << "交换后： p=" << p << " q=" << q << endl;
}
int main()
{
	cout << "请输入两个数字，以空格分隔。" << endl;
	int p, q;
	cin >> p >> q;
	cout << "交换前： p=" << p
		<< " q=" << q << endl;
	Swap_xor(p, q);
	Swap_count(p, q);
	return 0;
}