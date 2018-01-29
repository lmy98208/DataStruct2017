#include<iostream>
using namespace std;
int main()
{
	cout << "请输入数列的长度：";
	int k;
	cin >> k;
	cout << "请输入数列，以空格分隔。超出长度将被忽略。" << endl;
	int arry[100] = {0};//假设到屏幕输入，数量有限；若为文件，另外考虑
	int i = 0, j = 0;
	for (i = 0; i < k; i++)
		cin >> arry[i];
	cout << endl << "原数列： ";
	for (i = 0; i < k; i++)
	{
		cout << arry[i];
		if (i != (k - 1)) cout << ",";
	}
	cout << endl;
	bool flag = true;
	for (i = 0; i<(k - 1)&&flag; i++)
	{
		flag = false;
		for (j = 0; j<k - 1 - i; j++)
		{
			if (arry[j]>arry[j + 1])
			{
				int temp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = temp;
				flag = true;
			}
		}
	}
	cout << "排序后：  ";
	for (i = 0; i < k; i++)
	{
		cout << arry[i];
		if (i != (k - 1)) cout << ",";
	}
	cout << endl;
	return 0;
}