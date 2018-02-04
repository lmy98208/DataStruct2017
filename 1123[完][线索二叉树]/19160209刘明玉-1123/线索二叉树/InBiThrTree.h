#include<vector>
#include<iostream>
using namespace std;
enum BiThrNodeType { LINK, THREAD };

template <class T>
struct BiThrNode
{
	BiThrNodeType ltype, rtype;
	T data;
	BiThrNode<T> *lchild, *rchild;
};

template <class T>
class InBiThrTree
{
private:
	BiThrNode<T> *root;
	BiThrNode<T>* CreateTree(vector<T>&pre, int &i);
	void Free(BiThrNode<T>* p);
	void InThreaded(BiThrNode<T>* &p);
	BiThrNode<T>* Search(BiThrNode<T>*p, T e);
public:
	InBiThrTree(){ root = NULL; }
	InBiThrTree(vector<T>&pre);
	void InThreaded();
	~InBiThrTree();
	BiThrNode<T>* GetNext(BiThrNode<T>* p);
	BiThrNode<T>* GetPrev(BiThrNode<T>* p);
	void Traverse();
	BiThrNode<T>* GetParent(BiThrNode<T>* p);
	BiThrNode<T>* Search(T e);
};
