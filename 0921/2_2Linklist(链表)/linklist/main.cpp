#include<iostream>
#include"Linklist.cpp"
using namespace std;
int main()
{
	int data[5] = { 56,89,101,222,256 };
	cout << "Ԫ��Ϊ��";
	for (int i = 0; i < 5; i++)
		cout << data[i] << ",";
	cout << "\n���ڴ���LinkList1...\n";
	LinkList<int> a(data,5);
	//a.PrintLinkList();
	cout << "\n�����������ѯ��λ�ã�";
	int pos, tmp;
	cin >> pos;
	tmp=a.Get(pos-1);
	cout << "λ��" << pos << "��Ӧ����ֵΪ" << tmp;
	cout << "��\n\n����������ѯ����ֵ��";
	cin >> tmp;
	pos = a.Locate(tmp);
	if (pos)
		cout << tmp << "��λ��" << pos << "�ϡ�\n";
	else
		cout << "���޴�����";
	cout << "\n������Ҫ��ӵ����֣�";
	cin >> tmp;
	a.Insert(6,tmp);
	cout << "�ɹ���ӣ�\n";
	a.PrintLinkList();
	cout << "\n������Ҫɾ�����ֵ�λ�ã�";
	cin >> tmp;
	cout<<a.Delete(tmp)<<"��ɾ����";
	int data_[5] = { 9,78,203,522,990 };
	cout << "\n\nԪ��Ϊ��";
	for (int i = 0; i < 5; i++)
		cout << data_[i] << ",";
	cout << "\n���ڴ���LinkList2...\n";
	LinkList<int> b(data_, 5);
	//b.PrintLinkList();
	cout << "\n�ϲ�����\n";
	a.Merge(a, b);
	a.PrintLinkList();
	cout << "\n���ã�\n";
	a.Invert();
	a.PrintLinkList();
	return 0;
}