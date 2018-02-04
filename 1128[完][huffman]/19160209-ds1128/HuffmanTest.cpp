#include"Huffman.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int choose()
{
	cout << "\n请输入需要编码的位置：";
	int temp;
	cin >> temp;
	return temp;
}
int main()
{
	cout << "请输入Huffman树结点的个数：";
	int num;
	cin >> num;
	while (num < 0)
	{
		cout << "无效输入！\n请输入Huffman树结点的个数：";
		cin >> num;
	}
	//int sum = 2 * num - 1;
	vector<HuffmanNode> a;
	a.resize(num);
	cout << "请依次" << num << "个输入符号和频率:\n";
	int i = 0;
	for (; i < num; i++)
		cin >> a[i].data >> a[i].weight;
	HuffmanTree A(a);
	cout << "位置：\t";
	for (i = 0; i < num; i++)
		cout << i << '\t';
	cout << endl<<"结点：\t";
	int flag = 1; 
	for (i = 0; i < num; i++)
		cout << a[i].data << '\t';
	cout << endl << endl;
	while (flag)
	{
		int tmp = choose();
		if (tmp < 0 || tmp >= num)
		{
			cout << "无效位置！\n";
			break;
		}
		vector<int>code = A.GetCode(tmp);
		cout << "位置"<<tmp<<"上"<<a[tmp].data << "编码结果为：";
		for (unsigned j = 0; j < code.size(); j++)
			cout << code[j];
		cout << endl;
		cout << "其decode结果为：" << A.Decode(code) << endl;
		cout << "是否继续yes/no：";
		char c;
		cin >> c;
		if (c == 'n'||c=='N') flag = 0;
	}
	return 0;
}