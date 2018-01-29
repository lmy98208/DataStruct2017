#include<iostream>
#include<string>
#include"Linklist.cpp"
#include"Students.h"
using namespace std;
int Menu();

int main()
{
	score s1[2] = { "����",125,"��ѧ",160 };
	score s2[2] = { "��ѧ",110,"Ӣ��",101 };
	score s3[2] = { "����",62,"����",88 };
	Student st[3] = { {130412, 201304, "С��",s1} ,
	{ 130407, 201304, "С��",s2 },
	{ 130431, 201304, "Сǿ",s3 } };
	LinkList<Student> p(st,3) ;
	int count = 3;
	cout << "\t*******����һ���򵥵�ѧ������ϵͳ**********\n";
	int choice = Menu();
	while (choice)
	{
		switch (choice)
		{
		case 1: {
			cout << "������ѧ�š��������༶��";
			int number, classid; string name;
			cin >> number >> name >> classid;
			cout << "������ѧ��1���ɼ�1��ѧ��2���ɼ�2��";
			string course1, course2;
			float g1, g2;
			cin >> course1 >> g1 >> course2 >> g2;
			score tmp[2] = { course1,g1,course2,g2 };
			Student temp(number, classid, name, tmp);
			p.Insert(++count, temp);
			choice = Menu();
			break;
		}
		case 2: {
			cout << "\t��ѯ��Ϣ��\n������ԭѧ�ţ�";
			int num;
			cin >> num;
			int i;
			for (i = 0; i < 3; i++)
			{
				if (p.Get(i).GetNum() == num)
					break;
			}
			if (i >= 3) cout << "û�д�ѧ�š�\n";
			else
			{
				cout<<p.Get(i);
			}
			choice = Menu();
			break;
		}
		case 3:
		{
			cout << "\t�޸İ�ţ�\n������Ҫ�޸ĵ�ѧ����ѧ�ţ�";
			int num;
			cin >> num;
			int i;
			for (i = 0; i < 3; i++)
			{
				if (p.Get(i).GetNum() == num)
					break;
			}
			if (i >= 3) cout << "û�д�ѧ�š�\n";
			else
			{
				cout << "�������°�ţ�";
				int k;
				cin >> k;
				p.Get(i).SetClassNum(k);
				cout << "�޸ĺ��ѧ����ϢΪ��\n" << p.Get(i) << endl;
			}
			choice = Menu();
			break;
		}
		case 4:
		{
			cout << "\t�޸�ѧ�ţ�\n������ԭѧ�ţ�";
			int num;
			cin >> num;
			int i;
			for (i = 0; i < 3; i++)
			{
				if (p.Get(i).GetNum() == num)
					break;
			}
			if (i >= 3) cout << "û�д�ѧ�š�\n";
			else
			{
				cout << "��������ѧ�ţ�";
				int k;
				cin >> k;
				p.Get(i).SetNum(k);
				cout << "�޸ĺ��ѧ����ϢΪ��\n" << p.Get(i) << endl;
			}
			choice = Menu();
			break;
		}
		case 5:
		{
			cout << '\t' << "ѧ��" << '\t' << "����" << '\t' << "�༶" << '\t' << "�ɼ�\n";
			p.PrintLinkList();
			choice = Menu();
			break;
		}
		case 0:
			break;
		default: {
			cout << "�������룡���������룺";
			choice = Menu();
		}
		}
	}
	
	//p.PrintLinkList();
	return 0;
}

int Menu()
{
	int n;
	cout << "1.���ѧ����Ϣ" << endl;
	cout << "2.��ѯѧ����Ϣ" << endl;
	cout << "3.�޸�ѧ�����" << endl;
	cout << "4.�޸�ѧ��ѧ��" << endl;
	cout << "5.���ѧ����Ϣ��ϸ" << endl;
	cout << "0.��ȫ�˳�" << endl;
	cout << "\n��ѡ��";
	cin >> n;
	return(n);
}