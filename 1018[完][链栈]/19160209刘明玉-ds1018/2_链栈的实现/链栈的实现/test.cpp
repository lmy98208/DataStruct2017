#include"LinkStack.cpp"
#include<iostream>
using namespace std;

int main()
{
	LinkStack<int> a;
	cout << "�������������ջ�е�Ԫ�ظ���(��С��1)��";
	int k;
	cin >> k;
	if (k <= 1) {
		cerr << "Toooo SMALL!" << endl;
		exit(1);
	}
	int tmp;
	cout << "������" << k << "�����֣�" << endl;
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		a.Push(tmp);
	}
	cout << "��ջ��Ϊ" << a.Top()<<"��";
	cout << endl << "ջ��Ԫ��" << a.Pop() << "�ѳ�ջ��";
	cout << endl << "��ջ��Ϊ" << a.Top() << "��" << endl;
	return 0;
}