#include<iostream>
#include"SeqStack.cpp"
using namespace std;
int main()
{
	SeqStack<int, 100> a;
	int k = 0, num = 0;

	cout << "�������������ջ�е�Ԫ�ظ���(��С��3)��";//�������γ�ջ
	cin >> num;
	if (num <= 3)
	{
		cout << "Toooooo SMALL!"<<endl;
		exit(1);
	}

	cout<<"������"<<num<<"�����֣�"<< endl;
	for (int i = 0; i<num; i++)
	{
		cin >> k;
		a.Push(k);
	}

	cout << endl<<"��ջ��Ԫ��Ϊ" << a.Top() << "��" << endl;
	cout << "��ջ��Ԫ��" << a.Pop() << "�ѳ�ջ" << endl;
	cout << endl << "��ջ��Ԫ��Ϊ" << a.Top() << "��" << endl;
	cout << "��ջ��Ԫ��" << a.Pop() << "�ѳ�ջ" << endl;
	cout << endl << "��ջ��Ԫ��Ϊ" << a.Top() << "��" << endl;

	cout << endl << "�������������ջ�е�һ�����֣�";
	cin >> k;
	a.Push(k);
	cout << "��ջ��Ԫ��Ϊ" << a.Top() << "��" << endl;
	return 0;
}