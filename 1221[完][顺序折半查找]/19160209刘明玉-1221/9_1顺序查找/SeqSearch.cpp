#include<iostream>
#include<stdlib.h>
using namespace std;

//�޼����ڵ�˳�����
int SeqSearch(int r[], int n, int k)
{
	int i = 0;
	while (i < n&&r[i] != k)
		i++;
	if (i < n)
		return i;
	return -1;
}
//�м����ڵ�˳�����
int SeqSearch2(int r[], int n, int k)
{
	int i = 0;
	r[n-1] = k;
	while (r[i] != k)
		i++;
	if (i < n-1)
		return i;
	return -1;
}
int main()
{
	int r1[10], r2[11], i = 0;//r2�м����ڶඨ��һ����Ԫ
	for (; i < 10; i++)
		r2[i]=r1[i] = rand()%50;
	cout << "������飺";
	for (i = 0; i < 10; i++)
		cout << r1[i] << " ";
	cout << endl<<"����������ҵ�ֵ��";
	int k;
	cin >> k;
	cout << "�޼����ڵ�˳����ҽ����";
	if(SeqSearch(r1, 10, k)==-1) 
		cout<<"Not found!";
	else cout << SeqSearch(r1, 10, k)+1;
	cout << "\n�м����ڵ�˳����ҽ����";
	if(-1==SeqSearch2(r2, 11, k))
		cout << "Not found!"; 
	else cout << SeqSearch2(r2, 11, k)+1;
	cout<<endl;
	return 0;
}