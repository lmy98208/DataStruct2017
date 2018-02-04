#include"InBiThrTree.h"
#include<vector>
#include<iostream>
using namespace std;

template <class T>
BiThrNode<T>* InBiThrTree<T>::Search(BiThrNode<T>*p, T e)
{
	while (p->ltype == LINK)
		p = p->lchild;
	while (p)
	{
		if (p->data == e)
			break;
		p = GetNext(p);
	}
	return p;
}
template <class T>
BiThrNode<T>* InBiThrTree<T>::Search(T e)
{
	return Search(root, e);
}

template <class T>
BiThrNode<T>* InBiThrTree<T>::CreateTree(vector<T>&pre, int &i)
{
	T e = pre[i];
	i++;
	if (e == '*')
		return NULL;
	BiThrNode<T>* p = new BiThrNode<T>;
	p->data = e;
	p->ltype = LINK;
	p->rtype = LINK;
	p->lchild = CreateTree(pre, i);
	p->rchild = CreateTree(pre, i);
	return p;
}
template <class T>
InBiThrTree<T>::InBiThrTree(vector<T>&pre)
{
	int i=0;
	root = CreateTree(pre, i);
}

template <class T>//中序线索化
void InBiThrTree<T>::InThreaded(BiThrNode<T>* &p)
{
	if (p == NULL)
		return;
	InThreaded(p->lchild);
	if (p->lchild == NULL)
	{
		p->ltype = THREAD;
		p->lchild = prenode;
	}
	if (p->rchild == NULL)
		p->rtype = THREAD;
	if (prenode != NULL)
	{
		if (prenode->rtype == THREAD)
			prenode->rchild = p;
	}
	prenode = p;
	InThreaded(p->rchild);
}
template <class T>
void InBiThrTree<T>::InThreaded()
{
	prenode = NULL;
	InThreaded(root);
	prenode->rtype = THREAD;//最后遍历的是最右孩子
}

template <class T>//后继指针
BiThrNode<T>* InBiThrTree<T>::GetNext(BiThrNode<T>* p)
{
	if (p->rtype == THREAD)
		return p->rchild;
	p = p->rchild;
	while (p->ltype == LINK)
		p = p->lchild;
	return p;
}

template <class T>//前驱指针
BiThrNode<T>* InBiThrTree<T>::GetPrev(BiThrNode<T>* p)
{
	if (p->ltype == THREAD)
		return p->lchild;
	p = p->lchild;
	while (p->rtype == LINK)
		p = p->rchild;
	return p;
}

template <class T>//中序遍历中序线索二叉树
void InBiThrTree<T>::Traverse()
{
	BiThrNode<T>* p = root;
	while (p->ltype == LINK)
		p = p->lchild;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = GetNext(p);
	}
}

template <class T>
BiThrNode<T>* InBiThrTree<T>::GetParent(BiThrNode<T>* p)
{
	if (p == NULL)
		return NULL;
	BiThrNode<T>* parent;
	parent = p;
	while (parent->rtype == LINK)
		parent = parent->rchild;
	parent = parent->rchild;
	if (parent&&parent->lchild == p)
		return parent;
	parent = p;
	while (parent->ltype = LINK)
		parent = parent->lchild;
	parent = parent->lchild;
	return parent;
}

template <class T>
void InBiThrTree<T>::Free(BiThrNode<T>* p)
{
	if (p == NULL)
		return;
	if (p->ltype == LINK) Free(p->lchild);
	if (p->rtype == LINK) Free(p->rchild);
	delete p;
}
template <class T>
InBiThrTree<T>::~InBiThrTree()
{
	Free(root);
}