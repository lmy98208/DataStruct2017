#include<iostream>
#include"SeqStack_.cpp"
using namespace std;
int main()
{
	SeqStack<int, 200> a;
	int k = 0,num1 = 0, num2 = 0;
	cout << "请输入【栈1】中的元素个数(不小于2)：" ;
	cin >> num1;
	if (num1 <= 2) {
		cerr << "Tooooo SMALL!" << endl;
		exit(1);
	}
	cout << "请输入" << num1 << "个数字：" << endl;
	for (int i = 0; i<num1; i++)
	{
		cin >> k;
		a.Push(1,k);
	}
	cout << "请输入【栈2】中的元素个数(不小于2)：" ;
	cin >> num2;
	if (num2 <= 2) {
		cerr << "Tooooo SMALL!" << endl;
		exit(1);
	}

	for (int i = 0; i<num2; i++)
	{
		cin >> k;
		a.Push(2, k);
	}

	cout << endl<< "现【栈1】顶元素为" << a.Top(1) << "。" << endl;
	cout << "现【栈2】顶元素为" << a.Top(2) << "。" << endl;

	cout <<endl<< "现【栈1】顶元素" << a.Pop(1) << "已出栈" << endl;
	cout << "现【栈1】顶元素为" << a.Top(1) << "。" << endl;

	cout << endl<<"现【栈2】顶元素" << a.Pop(2) << "已出栈" << endl;
	cout<< "现【栈2】顶元素为" << a.Top(2) << "。" << endl;
	return 0;
}