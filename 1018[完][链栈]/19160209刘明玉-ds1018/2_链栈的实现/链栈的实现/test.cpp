#include"LinkStack.cpp"
#include<iostream>
using namespace std;

int main()
{
	LinkStack<int> a;
	cout << "请输入你想放入栈中的元素个数(不小于1)：";
	int k;
	cin >> k;
	if (k <= 1) {
		cerr << "Toooo SMALL!" << endl;
		exit(1);
	}
	int tmp;
	cout << "请输入" << k << "个数字：" << endl;
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		a.Push(tmp);
	}
	cout << "现栈顶为" << a.Top()<<"。";
	cout << endl << "栈顶元素" << a.Pop() << "已出栈。";
	cout << endl << "现栈顶为" << a.Top() << "。" << endl;
	return 0;
}