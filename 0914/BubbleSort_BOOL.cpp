#include<iostream>
using namespace std;
int main()
{
	cout << "���������еĳ��ȣ�";
	int k;
	cin >> k;
	cout << "���������У��Կո�ָ����������Ƚ������ԡ�" << endl;
	int arry[100] = {0};//���赽��Ļ���룬�������ޣ���Ϊ�ļ������⿼��
	int i = 0, j = 0;
	for (i = 0; i < k; i++)
		cin >> arry[i];
	cout << endl << "ԭ���У� ";
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
	cout << "�����  ";
	for (i = 0; i < k; i++)
	{
		cout << arry[i];
		if (i != (k - 1)) cout << ",";
	}
	cout << endl;
	return 0;
}