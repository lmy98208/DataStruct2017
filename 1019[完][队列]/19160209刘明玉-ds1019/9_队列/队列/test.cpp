#include"LinkQueue.cpp"
#include<iostream>
using namespace std;

int main()
{
	SeqQueue<int, 5> a;
	cout << "请输入您想入列的元素个数(1~5)：";
	int k;
	cin >> k;
	if (k > 5 || k < 1)
	{
		cerr << "Error!\n";
		exit(1);
	}
	cout << "请输入" << k << "个元素：\n";
	for (int i = 0; i < k; i++)
	{
		int j;
		cin >> j;
		a.EnQueue(j);
	}
	cout << "队头元素为：" << a.GetQueue() << endl;
	cout << "出列中...\n";
	a.DeQueue();
	cout << "队头元素为：" << a.GetQueue() << endl;
	cout << "出列中...\n";
	a.DeQueue();
	cout << "队头元素为：" << a.GetQueue() << endl;
	return 0;
}