#include<iostream>
using namespace std;
int main()
{
	cout << "���������е����ָ�����";
	int k;
	cin >> k;
	int arry[100];
	int i = 0, j = 0;
	cout << "���������֣��Կո�ָ���" << endl;
	for (i = 0; i < k; i++)
		cin >> arry[i];
	cout << "ԭ���У�  ";
	for (i = 0; i < k; i++)
	{
		cout<<arry[i];
		if (i != (k-1)) cout<<",";
	}
	cout << endl;
	int lastSwapPos = 0, lastSwapPosTemp = 0;//�Ľ�ð������
	for (i = 0; i<(k-1); i++)
	{
		lastSwapPos = lastSwapPosTemp;
		for (j = 0; j<k-1 - i; j++)
		{
			if (arry[j]>arry[j + 1])
			{
				int temp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = temp;
				lastSwapPosTemp = j;
			}
		}
		if (lastSwapPos == lastSwapPosTemp) break;
	}
	cout << "�����  ";
	for (i = 0; i < k; i++)
	{
		cout << arry[i];
		if (i != (k-1)) cout << ",";
	}
	cout << endl;
	return 0;
}