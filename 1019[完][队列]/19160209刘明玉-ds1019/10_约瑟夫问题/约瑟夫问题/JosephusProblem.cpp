#include<iostream>
#include"SeqQueue.cpp"
using namespace std;

int main()
{
	SeqQueue<int, 150> a;
	cout << "约瑟夫问题：\n";
	cout << "设定为1-3报数，报到3人的出来，其他人继续报。\n";
	cout << "请输入总人数：（1~100）";
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
	cout << "出队顺序为：\n";
	while (!a.IsEmpty())
	{
		int y=a.DeQueue();
		a.EnQueue(y);
		y= a.DeQueue();
		a.EnQueue(y);//报1 2的入队
		if (!a.IsEmpty())
			cout<< a.DeQueue()<<",";//3 出队
	}
	cout << endl;
	return 0;
}