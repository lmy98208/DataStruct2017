#include<iostream>
using namespace std;
int main()
{

	cout << "排序前：";
	int a[] = { 3,1,4,7,2,8,5 };
	int i = 0;
	for (; i < 7; i++)
		cout << a[i]<<" ";
	cout << endl;
	cout << "请输入分界数：";
	int k, temp;
	cin >> k;
	int pos = 0; 
	for (i = 0; i < 7; i++)
		if (a[i] == k)
		{
			temp = k;
			pos = i;
			break;
		}
	if (i == 7)
	{
		cout << "没有数字" << k << endl;
		exit(1);
	}
	i = 0;
	int j = 6;//i在前j在后
	while (i < j)
	{
		while (a[j] > temp&&i<j)
			j--;	
		a[pos] = a[j];//pos记录分界值的位置和上一个被移动值的位置
		pos = j;
		while (a[i] < temp&&i<j)
			i++;
		a[pos] = a[i];
		pos = i;
	}
	a[j]=k;
	cout << "排序后：";
	for (i = 0; i < 7; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}