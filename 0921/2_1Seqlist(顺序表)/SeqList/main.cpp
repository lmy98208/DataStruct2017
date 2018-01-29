#include<iostream>
#include"SeqList.cpp"
using namespace std;
int main()
{
	int a[10], b[5], k = 0, j = 0;
	cout << "请输入原始顺序表：（8个数字） " << endl;
	for (int i = 0; i<8; i++)
		cin >> a[i];
	SeqList <int, 100> s(a, 8);//测试构造函数
	cout << "原始顺序表为：";
	s.PrintSeqList();//测试遍历函数
	cout << "请输入你想查找的位置：（数字1-8）";
	cin >> k;
	
	cout << "此位置" << k << "的数值为" << s.Get(k) << "。" << endl;//测试按位查找函数
	cout << "请输入您想查找的值：";
	cin >> k;
	if (s.Locate(k)==0) {
		cout << "没有此数。\n";
		exit(1);
	}
	cout << "您想查找的值" << k << "在第" << s.Locate(k) << "个位置。" << endl;//测试按值查找函数
	cout << "请输入您想在第n个位置插入的数字k(n k):";
	cin >> j >> k;
	s.Insert(j, k);//测试插入函数
	cout << "插入后的顺序为：";
	s.PrintSeqList();
	cout << "请输入你想删除的位置：（数字1-9）";
	cin >> j;
	cout << "删除此位置后的表为：";
	s.Delete(j);//测试删除函数
	s.PrintSeqList();
	s.Differ();
	cout << "删去重复数值后的顺序表为：" << endl;
	s.PrintSeqList();
	k=s.DeleteMin();
	cout << "删除最小值：" << k << endl;
	s.PrintSeqList();
	

	cout << endl << "请您再次输入一个顺序表：（5个数字）" << endl;
	for (k = 0; k < 5; k++)
		cin >> b[k];
	SeqList <int, 100> ss(b, 5);
	s.Sort();//测试排序函数
	ss.Sort();
	cout << "排序后的有序表分别为：" << endl;
	s.PrintSeqList();
	ss.PrintSeqList();
	cout << "归并两个有序表后的结果为：" << endl;
	s.Merge(ss);//测试归并函数
	s.PrintSeqList();
	cout << "请输入（s t），使删除有序表中在给定值s-t间的元素：";
	int p, q;
	cin >> p >> q;
	s.DeleteS_T(p,q);
	s.PrintSeqList();
	return 0;
}