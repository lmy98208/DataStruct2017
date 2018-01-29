#include<iostream>
#include"SeqStack.cpp"
using namespace std;
int main()
{
	SeqStack<int, 100> a;
	int k = 0, num = 0;

	cout << "请输入您想放入栈中的元素个数(不小于3)：";//进行两次出栈
	cin >> num;
	if (num <= 3)
	{
		cout << "Toooooo SMALL!"<<endl;
		exit(1);
	}

	cout<<"请输入"<<num<<"个数字："<< endl;
	for (int i = 0; i<num; i++)
	{
		cin >> k;
		a.Push(k);
	}

	cout << endl<<"现栈顶元素为" << a.Top() << "。" << endl;
	cout << "现栈顶元素" << a.Pop() << "已出栈" << endl;
	cout << endl << "现栈顶元素为" << a.Top() << "。" << endl;
	cout << "现栈顶元素" << a.Pop() << "已出栈" << endl;
	cout << endl << "现栈顶元素为" << a.Top() << "。" << endl;

	cout << endl << "请输入您想放入栈中的一个数字：";
	cin >> k;
	a.Push(k);
	cout << "现栈顶元素为" << a.Top() << "。" << endl;
	return 0;
}