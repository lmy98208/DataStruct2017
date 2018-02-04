#include<iostream>
#include<vector>
#include"InBiThrTree.cpp"
using namespace std;
BiThrNode<char>*prenode = NULL;

int main()
{
	cout << "请输入二叉树元素的个数（包括*）：";
	int num;
	cin >> num;
	vector<char>a(num);
	cout << "请输入" << num << "个元素数据（包括*）：";
	for (int i = 0; i < num; i++)
		cin >> a[i];
	InBiThrTree<char> tree(a);
	tree.InThreaded();
	cout << "正在生成二叉树...\n";
	cout << "二叉树为：";
	tree.Traverse();
	cout << "\n请输入一个二叉树中的元素：";
	char ce;
	cin >> ce;
	BiThrNode<char>* node=tree.Search(ce);
	cout << "元素的前驱为：" << tree.GetPrev(node)->data << endl;
	cout << "元素的后继为：" << tree.GetNext(node)->data << endl;
	cout << "元素的父结点为：" << tree.GetParent(node)->data << endl;
	return 0;
}