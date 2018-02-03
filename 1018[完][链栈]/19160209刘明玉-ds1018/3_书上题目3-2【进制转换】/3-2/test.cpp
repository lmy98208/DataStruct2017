#include<iostream>
#include"SeqStack.cpp"
using namespace std;
int main()
{
	SeqStack<int, 100> a;
	cout << "请输入一个十进制整数：";
	int k = 0, i = 0, count = 0;
	cin >> k;
	cout << "请输入您的目标进制（2~16）：";
	cin >> i;
	if (i < 2 || i>16) { 
		cerr << "Error!\n";
		exit(1);
	}
	while (k)
	{
		int tmp = k%i;
		a.Push(tmp);
		k = k / i;
		count++;
	}
	cout << "结果为：";
	for (int j = 0; j < count; j++)
	{
		int p = a.Pop();
		if (p > 9) {
			p = p + 'A' - 10;
			printf("%C", p);
		}
		else cout << p;
	}
	cout << endl;
	return 0;
}