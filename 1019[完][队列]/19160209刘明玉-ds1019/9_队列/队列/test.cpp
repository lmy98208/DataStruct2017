#include"LinkQueue.cpp"
#include<iostream>
using namespace std;

int main()
{
	SeqQueue<int, 5> a;
	cout << "�������������е�Ԫ�ظ���(1~5)��";
	int k;
	cin >> k;
	if (k > 5 || k < 1)
	{
		cerr << "Error!\n";
		exit(1);
	}
	cout << "������" << k << "��Ԫ�أ�\n";
	for (int i = 0; i < k; i++)
	{
		int j;
		cin >> j;
		a.EnQueue(j);
	}
	cout << "��ͷԪ��Ϊ��" << a.GetQueue() << endl;
	cout << "������...\n";
	a.DeQueue();
	cout << "��ͷԪ��Ϊ��" << a.GetQueue() << endl;
	cout << "������...\n";
	a.DeQueue();
	cout << "��ͷԪ��Ϊ��" << a.GetQueue() << endl;
	return 0;
}