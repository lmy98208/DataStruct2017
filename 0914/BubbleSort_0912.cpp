#include<iostream>
using namespace std;
int main()
{
	cout << "���������е����ָ�����";
	int k;
	cin >> k;
	int arry[100]={0};
	int i = 0, j = 0;
	cout << "���������֣��Կո�ָ�������" <<k<<"λ�����������ԡ�" <<endl;
	for (i = 0; i < k; i++)
		cin >> arry[i];
	cout << "ԭ���У�  ";
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
	cout << "�����  ";
	for (i = 0; i < k; i++)
	{
		cout << arry[i];
		if (i != (k-1)) cout << ",";
	}
	cout << endl;
	return 0;
}
