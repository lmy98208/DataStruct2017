#include<iostream>
#include"SeqQueue.cpp"
#include<string>
using namespace std;

int main()
{
	SeqQueue<char, 100> Letters;
	cout << "�����뿭�������ƫ������";
	int offset;
	cin >> offset;
	int flag = 1;
	while (flag)//ֱ���û�ѡ���˳�ʱ��flag=0
	{
		cout << "*****************************"<<endl;//�˵�����
		cout << "1.����->���ģ�\n2.����->����\n3.�˳�\n��ѡ��(��������)��\n";
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
		cout << "�����룺";
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
			cout << "���Ϊ��";
			while (!Letters.IsEmpty())
				cout<<Letters.DeQueue();
			cout <<endl<<
				"*****************************"<< endl;
		}
	}
	return 0;
}