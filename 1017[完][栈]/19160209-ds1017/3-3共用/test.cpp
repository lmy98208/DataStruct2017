#include<iostream>
#include"SeqStack_.cpp"
using namespace std;
int main()
{
	SeqStack<int, 200> a;
	int k = 0,num1 = 0, num2 = 0;
	cout << "�����롾ջ1���е�Ԫ�ظ���(��С��2)��" ;
	cin >> num1;
	if (num1 <= 2) {
		cerr << "Tooooo SMALL!" << endl;
		exit(1);
	}
	cout << "������" << num1 << "�����֣�" << endl;
	for (int i = 0; i<num1; i++)
	{
		cin >> k;
		a.Push(1,k);
	}
	cout << "�����롾ջ2���е�Ԫ�ظ���(��С��2)��" ;
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

	cout << endl<< "�֡�ջ1����Ԫ��Ϊ" << a.Top(1) << "��" << endl;
	cout << "�֡�ջ2����Ԫ��Ϊ" << a.Top(2) << "��" << endl;

	cout <<endl<< "�֡�ջ1����Ԫ��" << a.Pop(1) << "�ѳ�ջ" << endl;
	cout << "�֡�ջ1����Ԫ��Ϊ" << a.Top(1) << "��" << endl;

	cout << endl<<"�֡�ջ2����Ԫ��" << a.Pop(2) << "�ѳ�ջ" << endl;
	cout<< "�֡�ջ2����Ԫ��Ϊ" << a.Top(2) << "��" << endl;
	return 0;
}