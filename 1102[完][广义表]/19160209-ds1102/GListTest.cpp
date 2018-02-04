#include<iostream>
#include"GList.cpp"
using namespace std;
int main()
{
	cout << "请输入广义表a：";
	char s[100];
	cin >> s;
	GList<char> a(s);
	cout << "正在生成…\n";
	cout << "深度："<<a.Depth();
	cout << "\n长度：" << a.Length();
	cout << "\n遍历：";
	a.Traverse();
	cout << "\n拷贝构造b：";
	GList<char> b(a);
	b.Traverse();
	cout << endl;
	return 0;
}