#include<iostream>
using namespace std;

int TenToS(int n, int s)
{
	if (n < s) return n;
	return n%s + 10 * TenToS(n / s, s);
}

int main()
{
	int k;
	cout << "������һ��ʮ������������";
	cin >> k;
	if (k < 0) 
	{
		cerr << "Error!\n";
		exit(1);
	}
	cout << "������Ŀ�Ľ���S��S=2,8��16����";
	int s;
	cin >> s;
	if (s != 2 && s != 8 && s != 16)
	{
		cerr << "Error!\n";
		exit(1);
	}
	cout << k << "��" << s << "������Ϊ" << TenToS(k, s) << endl;
	return 0;
}