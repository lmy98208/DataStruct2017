#include"SeqStack.cpp"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	SeqStack <int, 100> a;
	cout << "��������ģ�";
	string str;
	int tmp = 0;
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len / 2; i++)
		a.Push(str[i]);
	if (len & 1)
		tmp = (len + 1) / 2;
	else 
		tmp = len / 2;
	for (int j = tmp; j < len; j++)
		if (a.Pop() != str[j])
			break;
	if (a.IsEmpty()) cout << str << "�ǻ��ģ�\n";
	else cout <<str<< "���ǻ��ģ�\n";
	return 0;
}