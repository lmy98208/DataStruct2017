#include<iostream>
using namespace std;
int main()
{

	cout << "����ǰ��";
	int a[] = { 3,1,4,7,2,8,5 };
	int i = 0;
	for (; i < 7; i++)
		cout << a[i]<<" ";
	cout << endl;
	cout << "������ֽ�����";
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
		cout << "û������" << k << endl;
		exit(1);
	}
	i = 0;
	int j = 6;//i��ǰj�ں�
	while (i < j)
	{
		while (a[j] > temp&&i<j)
			j--;	
		a[pos] = a[j];//pos��¼�ֽ�ֵ��λ�ú���һ�����ƶ�ֵ��λ��
		pos = j;
		while (a[i] < temp&&i<j)
			i++;
		a[pos] = a[i];
		pos = i;
	}
	a[j]=k;
	cout << "�����";
	for (i = 0; i < 7; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}