#include<iostream>
using namespace std;

int main()
{
	cout << "������������������ָ�����>0����\n";
	int k=0, arry[100] = { 0 }, arry_[100] = { 0 };//�ڶ����������ڿ���	
	cin >> k;//�ж������Ƿ�Ϸ�
	while (k <= 0) {
		cout << "error!Again!\n";
		cin >> k;
	}
	cout << "���������֡�\n";
	int i = 0, j = 0;
	for (i = 0; i < k; i++)
		cin >> arry[i];
	cout << "��ǰ����Ϊ��";
	for (i = 0; i < k; i++)
	{
		cout << arry[i];
		if (i != (k - 1)) cout << ",";
		else cout << endl;
	}
	cout << "������ѭ�����Ƶ�λ����\n";

	cin >> j;//�ж������Ƿ�Ϸ�
	while (j <= 0) {
		cout << "error!Again!\n";
		cin >> j;
	}

	for (i = 0; i < k; i++)
		arry_[(i+j)%k] = arry[i];
	cout << "��ǰ����Ϊ��";
	for (i = 0; i < k; i++)
	{
		cout << arry_[i];
		if (i != (k - 1)) cout << ",";
		else cout << endl;
	}
	return 0;
}