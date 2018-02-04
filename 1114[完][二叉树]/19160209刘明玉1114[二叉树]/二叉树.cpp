#include"BiTree.cpp"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	cout << "请输入二叉树元素的个数（包括*）：";
	int num;
	cin >> num;
	vector<char>a(num);
	cout << "请输入" << num << "个元素数据（包括*）：";
	for (int i = 0; i < num; i++)
		cin >> a[i];
	BiTree<char>tree(a);
	cout << "先序序列遍历为：";
	tree.PreOrder();
	cout << "\n中序序列遍历为：";
	tree.InOrder();
	cout << "\n后序序列遍历为：";
	tree.PostOrder();
	cout << "\n层序序列遍历为：";
	tree.LevelOrder();
	cout << "\n\n二叉树的结点数为：" << tree.Count() << endl;
	cout << "二叉树的高度为：" << tree.Height() << endl;
	char w;
	cout << "请输入一个结点（在输入的元素中选择元素）：";
	cin >> w;
	BiNode<char>*tnode = tree.Search(w);
	cout << "\n该结点的父结点为：" << tree.SearchParent(tnode)->data << endl;
	return 0;
}