#include<iostream>
#include<vector>
#include"InBiThrTree.cpp"
using namespace std;
BiThrNode<char>*prenode = NULL;

int main()
{
	cout << "�����������Ԫ�صĸ���������*����";
	int num;
	cin >> num;
	vector<char>a(num);
	cout << "������" << num << "��Ԫ�����ݣ�����*����";
	for (int i = 0; i < num; i++)
		cin >> a[i];
	InBiThrTree<char> tree(a);
	tree.InThreaded();
	cout << "�������ɶ�����...\n";
	cout << "������Ϊ��";
	tree.Traverse();
	cout << "\n������һ���������е�Ԫ�أ�";
	char ce;
	cin >> ce;
	BiThrNode<char>* node=tree.Search(ce);
	cout << "Ԫ�ص�ǰ��Ϊ��" << tree.GetPrev(node)->data << endl;
	cout << "Ԫ�صĺ��Ϊ��" << tree.GetNext(node)->data << endl;
	cout << "Ԫ�صĸ����Ϊ��" << tree.GetParent(node)->data << endl;
	return 0;
}