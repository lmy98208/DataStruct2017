#include<iostream>
#include<stdlib.h>
using namespace std;

//无监视哨的顺序查找
int SeqSearch(int r[], int n, int k)
{
	int i = 0;
	while (i < n&&r[i] != k)
		i++;
	if (i < n)
		return i;
	return -1;
}
//有监视哨的顺序查找
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
	int r1[10], r2[11], i = 0;//r2有监视哨多定义一个单元
	for (; i < 10; i++)
		r2[i]=r1[i] = rand()%50;
	cout << "随机数组：";
	for (i = 0; i < 10; i++)
		cout << r1[i] << " ";
	cout << endl<<"请输入待查找的值：";
	int k;
	cin >> k;
	cout << "无监视哨的顺序查找结果：";
	if(SeqSearch(r1, 10, k)==-1) 
		cout<<"Not found!";
	else cout << SeqSearch(r1, 10, k)+1;
	cout << "\n有监视哨的顺序查找结果：";
	if(-1==SeqSearch2(r2, 11, k))
		cout << "Not found!"; 
	else cout << SeqSearch2(r2, 11, k)+1;
	cout<<endl;
	return 0;
}