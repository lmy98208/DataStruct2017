#include<vector>
#include<iostream>
using namespace std;
template <class T>
struct BiNode
{
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
};

template <class T>
class BiTree
{
private:
	BiNode<T>* root;
	BiNode<T>* CreateByPre(vector<T>&pre, int &i);//�������й���
	BiNode<T>* CreateByPreMid(vector<T>&pre, vector<T>&mid,
		int ipre, int imid, int n);//�ȡ��������й���

	BiNode<T>* Copy(BiNode<T>*p);//��������
	void Free(BiNode<T>* p);//����
	int Count(BiNode<T>* p);//�ڵ����
	int Height(BiNode<T>* p);//�߶�
	BiNode<T>* Search(BiNode<T>*p, T e);//��ֵ����
	BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* p, 
		BiNode<T>*child);//���Ҹ��ڵ�
	void PreOrder(BiNode<T> *p);//�������
	void InOrder(BiNode<T> *p);//�������
	void PostOrder(BiNode<T> *p);//�������
public:
	BiTree() { root = NULL; }//�޲ι��캯��
	BiTree(vector <T>&pre);//���������й��������
	BiTree(vector <T>&pre, vector<T>&mid);//�������������й��������

	BiTree(BiTree<T>&tree);//����
	~BiTree();//����
	void PreOrder();//�������
	void InOrder();//�������
	void PostOrder();//�������
	void LevelOrder();//�������
	int Count();//������
	int Height();//�߶�
	BiNode<T>* Search(T e);//��ֵ����
	BiNode<T>* SearchParent(BiNode<T>*child);//����ָ���ڵ�ĸ��ڵ�
};

