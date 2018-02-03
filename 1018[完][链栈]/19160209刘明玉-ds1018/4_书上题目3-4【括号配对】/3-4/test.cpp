#include<iostream>
#include<string>
#include"SeqStack.cpp"
using namespace std;

int IsMatch(int a, char b)//�Ƚϵ�ǰ������ջ�������Ƿ�ƥ��
{
	if (a == '('&&b == ')')
		return 1;
	else if (a == '['&&b == ']')
		return 1;
	else if (a == '{'&&b == '}')
		return 1;
	else
		return 0;
}
int main()
{
	SeqStack<int, 100> a;
	cout << "������һ�����ʽ��";
	string str;
	cin >> str;
	int flag = 1;
	int k = str.size();
	for (int i = 0; i < k; i++)
	{
		switch (str[i])
		{
		case '(':
		case '[':
		case '{':
			a.Push(str[i]);//������ȫ����ջ
			break;
		case ')':
		case ']':
		case '}':
			if (a.IsEmpty())//��������������ŵ�ջΪ�գ���ȱ��������
			{
				cout << "ȱ�������ţ�\n";
				exit(1);
			}
			else
			{
				if (IsMatch(a.Top(), str[i]))//������ƥ���������ų�ջ
					int m=a.Pop();
				else 
				{
					cout << "�����Ų�ƥ�䣡\n";//����Ϊ�����Ų�ƥ��
					exit(1);
				}
			}
		default: break;//���������ַ���������
		}
	}

	if (a.IsEmpty()) cout << "����ƥ�䣡\n";//����ʱջ����ƥ��
	else cout << "ȱ�������ţ�\n";//����ʱջ�����������ţ���ȱ��������

	return 0;

}