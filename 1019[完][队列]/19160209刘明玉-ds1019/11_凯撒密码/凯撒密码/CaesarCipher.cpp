#include<iostream>
#include"SeqQueue.cpp"
#include<string>
using namespace std;

int main()
{
	SeqQueue<char, 100> Letters;
	cout << "请输入凯撒密码的偏移量：";
	int offset;
	cin >> offset;
	int flag = 1;
	while (flag)//直至用户选择退出时将flag=0
	{
		cout << "*****************************"<<endl;//菜单界面
		cout << "1.明文->密文；\n2.密文->明文\n3.退出\n请选择(输入数字)：\n";
		int num;
		cin >> num;
		if (num != 1 && num != 2 && num != 3)
		{
			cerr << "Error!\n";
			exit(1);
		}
		if (num == 3)
		{
			flag = 0;
			continue;
		}
		char ch = getchar();
		cout << "请输入：";
		ch = getchar();
		switch (num)
		{
		case 1:
		{
			while (ch != '\n')
			{
				Letters.EnQueue(ch + (offset % 26));
				ch = getchar();
			}
			break;
		}
		case 2:
		{
			while (ch != '\n')
			{
				Letters.EnQueue(ch - (offset % 26));
				ch = getchar();
			}
			break;
		}
		}
		if (flag)
		{
			cout << "结果为：";
			while (!Letters.IsEmpty())
				cout<<Letters.DeQueue();
			cout <<endl<<
				"*****************************"<< endl;
		}
	}
	return 0;
}