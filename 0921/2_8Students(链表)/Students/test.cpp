#include<iostream>
#include<string>
#include"Linklist.cpp"
#include"Students.h"
using namespace std;
int Menu();

int main()
{
	score s1[2] = { "语文",125,"数学",160 };
	score s2[2] = { "化学",110,"英语",101 };
	score s3[2] = { "生物",62,"物理",88 };
	Student st[3] = { {130412, 201304, "小明",s1} ,
	{ 130407, 201304, "小红",s2 },
	{ 130431, 201304, "小强",s3 } };
	LinkList<Student> p(st,3) ;
	int count = 3;
	cout << "\t*******这是一个简单的学生管理系统**********\n";
	int choice = Menu();
	while (choice)
	{
		switch (choice)
		{
		case 1: {
			cout << "请输入学号、姓名、班级：";
			int number, classid; string name;
			cin >> number >> name >> classid;
			cout << "请输入学科1、成绩1，学科2、成绩2：";
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
			cout << "\t查询信息：\n请输入原学号：";
			int num;
			cin >> num;
			int i;
			for (i = 0; i < 3; i++)
			{
				if (p.Get(i).GetNum() == num)
					break;
			}
			if (i >= 3) cout << "没有此学号。\n";
			else
			{
				cout<<p.Get(i);
			}
			choice = Menu();
			break;
		}
		case 3:
		{
			cout << "\t修改班号：\n请输入要修改的学生的学号：";
			int num;
			cin >> num;
			int i;
			for (i = 0; i < 3; i++)
			{
				if (p.Get(i).GetNum() == num)
					break;
			}
			if (i >= 3) cout << "没有此学号。\n";
			else
			{
				cout << "请输入新班号：";
				int k;
				cin >> k;
				p.Get(i).SetClassNum(k);
				cout << "修改后的学生信息为：\n" << p.Get(i) << endl;
			}
			choice = Menu();
			break;
		}
		case 4:
		{
			cout << "\t修改学号：\n请输入原学号：";
			int num;
			cin >> num;
			int i;
			for (i = 0; i < 3; i++)
			{
				if (p.Get(i).GetNum() == num)
					break;
			}
			if (i >= 3) cout << "没有此学号。\n";
			else
			{
				cout << "请输入新学号：";
				int k;
				cin >> k;
				p.Get(i).SetNum(k);
				cout << "修改后的学生信息为：\n" << p.Get(i) << endl;
			}
			choice = Menu();
			break;
		}
		case 5:
		{
			cout << '\t' << "学号" << '\t' << "姓名" << '\t' << "班级" << '\t' << "成绩\n";
			p.PrintLinkList();
			choice = Menu();
			break;
		}
		case 0:
			break;
		default: {
			cout << "错误输入！请重新输入：";
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
	cout << "1.添加学生信息" << endl;
	cout << "2.查询学生信息" << endl;
	cout << "3.修改学生班号" << endl;
	cout << "4.修改学生学号" << endl;
	cout << "5.输出学生信息明细" << endl;
	cout << "0.安全退出" << endl;
	cout << "\n请选择：";
	cin >> n;
	return(n);
}