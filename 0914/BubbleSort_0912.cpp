#include<iostream>
using namespace std;
int main()
{
	cout << "请输入数列的数字个数：";
	int k;
	cin >> k;
	int arry[100]={0};
	int i = 0, j = 0;
	cout << "请输入数字，以空格分隔。多于" <<k<<"位的数将被忽略。" <<endl;
	for (i = 0; i < k; i++)
		cin >> arry[i];
	cout << "原数列：  ";
	for (i = 0; i < k; i++)
	{
		cout<<arry[i];
		if (i != (k-1)) cout<<",";
	}
	cout << endl;
	for (i = 0; i<(k-1); i++)
	{
		for (j = 0; j<k-1 - i; j++)
		{
			if (arry[j]>arry[j + 1])
			{
				int temp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = temp;
			}
		}
	}
	cout << "排序后：  ";
	for (i = 0; i < k; i++)
	{
		cout << arry[i];
		if (i != (k-1)) cout << ",";
	}
	cout << endl;
	return 0;
}
