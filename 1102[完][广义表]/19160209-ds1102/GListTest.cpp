#include<iostream>
#include"GList.cpp"
using namespace std;
int main()
{
	cout << "����������a��";
	char s[100];
	cin >> s;
	GList<char> a(s);
	cout << "�������ɡ�\n";
	cout << "��ȣ�"<<a.Depth();
	cout << "\n���ȣ�" << a.Length();
	cout << "\n������";
	a.Traverse();
	cout << "\n��������b��";
	GList<char> b(a);
	b.Traverse();
	cout << endl;
	return 0;
}