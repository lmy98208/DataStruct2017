#include<iostream>
#include"SeqQueue.cpp"
using namespace std;

int main()
{
	SeqQueue<int, 150> a;
	cout << "Լɪ�����⣺\n";
	cout << "�趨Ϊ1-3����������3�˵ĳ����������˼�������\n";
	cout << "����������������1~100��";
	int n;
	cin >> n;
	if (n < 0 || n>100)
	{
		cerr << "Error!\n";
		exit(1);
	}
	int i = 1;
	for (; i <= n; i++)
		a.EnQueue(i);
	cout << "����˳��Ϊ��\n";
	while (!a.IsEmpty())
	{
		int y=a.DeQueue();
		a.EnQueue(y);
		y= a.DeQueue();
		a.EnQueue(y);//��1 2�����
		if (!a.IsEmpty())
			cout<< a.DeQueue()<<",";//3 ����
	}
	cout << endl;
	return 0;
}