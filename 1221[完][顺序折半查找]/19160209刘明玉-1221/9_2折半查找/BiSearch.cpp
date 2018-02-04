#include<iostream>
#include<stdlib.h>
using namespace std;
//�۰���ҷǵݹ��㷨
int BiSearch(int r[], int n, int k)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (r[mid] == k)
			return mid;
		else if (r[mid] < k)
			low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}
//�۰���ҵݹ��㷨
int BiSearch2(int r[], int low, int high, int k)
{
	if (low>high)
		return -1;
	else
	{
		int mid = (low + high) / 2;
		if (r[mid] == k)
			return mid;
		else
			if (r[mid] < k)
				return BiSearch2(r, mid + 1, high, k);
			else
				return BiSearch2(r, low, mid - 1, k);
	}
}

int main()
{
	int r1[10] = { 1,5,10,12,19,32,49,56,101,125 }, i = 0;
	cout << "���飺";
	for (i = 0; i < 10; i++)
		cout << r1[i] << " ";
	cout << endl << "����������ҵ�ֵ��";
	int k;
	cin >> k;
	cout << "�۰���ҷǵݹ��㷨�����";
	if (BiSearch(r1, 10, k) == -1)
		cout << "Not found!";
	else cout << BiSearch(r1, 10, k) + 1;
	cout << "\n�۰���ҵݹ��㷨�����";
	if (-1 == BiSearch2(r1, 0, 10, k))
		cout << "Not found!";
	else cout << BiSearch2(r1, 0, 10, k) + 1;
	cout << endl;
	return 0;
}
