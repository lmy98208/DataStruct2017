#include"BiTree.cpp"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	cout << "�����������Ԫ�صĸ���������*����";
	int num;
	cin >> num;
	vector<char>a(num);
	cout << "������" << num << "��Ԫ�����ݣ�����*����";
	for (int i = 0; i < num; i++)
		cin >> a[i];
	BiTree<char>tree(a);
	cout << "�������б���Ϊ��";
	tree.PreOrder();
	cout << "\n�������б���Ϊ��";
	tree.InOrder();
	cout << "\n�������б���Ϊ��";
	tree.PostOrder();
	cout << "\n�������б���Ϊ��";
	tree.LevelOrder();
	cout << "\n\n�������Ľ����Ϊ��" << tree.Count() << endl;
	cout << "�������ĸ߶�Ϊ��" << tree.Height() << endl;
	char w;
	cout << "������һ����㣨�������Ԫ����ѡ��Ԫ�أ���";
	cin >> w;
	BiNode<char>*tnode = tree.Search(w);
	cout << "\n�ý��ĸ����Ϊ��" << tree.SearchParent(tnode)->data << endl;
	return 0;
}