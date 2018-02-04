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
	BiNode<T>* CreateByPre(vector<T>&pre, int &i);//先序序列构造
	BiNode<T>* CreateByPreMid(vector<T>&pre, vector<T>&mid,
		int ipre, int imid, int n);//先、中序序列构造

	BiNode<T>* Copy(BiNode<T>*p);//拷贝构造
	void Free(BiNode<T>* p);//析构
	int Count(BiNode<T>* p);//节点个数
	int Height(BiNode<T>* p);//高度
	BiNode<T>* Search(BiNode<T>*p, T e);//按值查找
	BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* p, 
		BiNode<T>*child);//查找父节点
	void PreOrder(BiNode<T> *p);//先序查找
	void InOrder(BiNode<T> *p);//中序查找
	void PostOrder(BiNode<T> *p);//后序查找
public:
	BiTree() { root = NULL; }//无参构造函数
	BiTree(vector <T>&pre);//由先序序列构造二叉树
	BiTree(vector <T>&pre, vector<T>&mid);//由先序、中序序列构造二叉树

	BiTree(BiTree<T>&tree);//拷贝
	~BiTree();//析构
	void PreOrder();//先序遍历
	void InOrder();//中序遍历
	void PostOrder();//后序遍历
	void LevelOrder();//层序遍历
	int Count();//结点个数
	int Height();//高度
	BiNode<T>* Search(T e);//按值查找
	BiNode<T>* SearchParent(BiNode<T>*child);//查找指定节点的父节点
};

