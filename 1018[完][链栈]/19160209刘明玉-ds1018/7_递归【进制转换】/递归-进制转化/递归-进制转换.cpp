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
	cout << "请输入一个十进制正整数：";
	cin >> k;
	if (k < 0) 
	{
		cerr << "Error!\n";
		exit(1);
	}
	cout << "请输入目的进制S（S=2,8，16）：";
	int s;
	cin >> s;
	if (s != 2 && s != 8 && s != 16)
	{
		cerr << "Error!\n";
		exit(1);
	}
	cout << k << "的" << s << "进制数为" << TenToS(k, s) << endl;
	return 0;
}