#include"Huffman.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int choose()
{
	cout << "\n��������Ҫ�����λ�ã�";
	int temp;
	cin >> temp;
	return temp;
}
int main()
{
	cout << "������Huffman�����ĸ�����";
	int num;
	cin >> num;
	while (num < 0)
	{
		cout << "��Ч���룡\n������Huffman�����ĸ�����";
		cin >> num;
	}
	//int sum = 2 * num - 1;
	vector<HuffmanNode> a;
	a.resize(num);
	cout << "������" << num << "��������ź�Ƶ��:\n";
	int i = 0;
	for (; i < num; i++)
		cin >> a[i].data >> a[i].weight;
	HuffmanTree A(a);
	cout << "λ�ã�\t";
	for (i = 0; i < num; i++)
		cout << i << '\t';
	cout << endl<<"��㣺\t";
	int flag = 1; 
	for (i = 0; i < num; i++)
		cout << a[i].data << '\t';
	cout << endl << endl;
	while (flag)
	{
		int tmp = choose();
		if (tmp < 0 || tmp >= num)
		{
			cout << "��Чλ�ã�\n";
			break;
		}
		vector<int>code = A.GetCode(tmp);
		cout << "λ��"<<tmp<<"��"<<a[tmp].data << "������Ϊ��";
		for (unsigned j = 0; j < code.size(); j++)
			cout << code[j];
		cout << endl;
		cout << "��decode���Ϊ��" << A.Decode(code) << endl;
		cout << "�Ƿ����yes/no��";
		char c;
		cin >> c;
		if (c == 'n'||c=='N') flag = 0;
	}
	return 0;
}