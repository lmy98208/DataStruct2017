#include<iostream>
using namespace std;

int main()
{
	cout << "请输入你想输入的数字个数（>0）。\n";
	int k=0, arry[100] = { 0 }, arry_[100] = { 0 };//第二个数组用于拷贝	
	cin >> k;//判断输入是否合法
	while (k <= 0) {
		cout << "error!Again!\n";
		cin >> k;
	}
	cout << "请输入数字。\n";
	int i = 0, j = 0;
	for (i = 0; i < k; i++)
		cin >> arry[i];
	cout << "当前数组为：";
	for (i = 0; i < k; i++)
	{
		cout << arry[i];
		if (i != (k - 1)) cout << ",";
		else cout << endl;
	}
	cout << "请输入循环左移的位数。\n";

	cin >> j;//判断输入是否合法
	while (j <= 0) {
		cout << "error!Again!\n";
		cin >> j;
	}

	for (i = 0; i < k; i++)
		arry_[(i+j)%k] = arry[i];
	cout << "当前数组为：";
	for (i = 0; i < k; i++)
	{
		cout << arry_[i];
		if (i != (k - 1)) cout << ",";
		else cout << endl;
	}
	return 0;
}