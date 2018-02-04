#include "BiSortTree.h"
#include"SeqQueue.cpp"
#include<iostream>
using namespace std;

void BiSortTree::Insert(BiNode *& ptr, int k)
{
	if (ptr == NULL)//�����
	{
		ptr = new BiNode;
		ptr->key = k;
		ptr->lchild = ptr->rchild = NULL;
	}
	else
	{
		if (k < ptr->key)        //�ȸ����С�Ĳ���������
			Insert(ptr->lchild, k);
		else if (k>ptr->key)     //�ȸ�����Ĳ���������
			Insert(ptr->rchild, k);
	}
}

BiNode * BiSortTree::Search(BiNode * ptr, int k)
{
	if (ptr == NULL)  //�ݹ����
		return NULL;
	else if (ptr->key == k)
		return ptr;
	else if (k < ptr->key)
		return Search(ptr->lchild, k);
	else
		return Search(ptr->rchild, k);
}

void BiSortTree::Delete(BiNode *& ptr, int k)
{
	BiNode* temp;
	if (ptr != NULL)
	{
		if (k < ptr->key)
			Delete(ptr->lchild, k);   //����ֵk�ȵ�ǰֵС������������������
		else if (k>ptr->key)
			Delete(ptr->rchild, k);   //����ֵk�ȵ�ǰֵ������������������
		else
		{
			if (ptr->lchild != NULL && ptr->rchild != NULL)  //˫֧�ڵ�
			{
				//Ѱ�������������Һ���
				temp = ptr->lchild;
				while (temp->rchild != NULL)
					temp = temp->rchild;
				ptr->key = temp->key;
				Delete(ptr->lchild, temp->key);
			}
			else
			{
				temp = ptr;
				if (ptr->lchild == NULL)
					ptr = ptr->rchild;
				else if (ptr->rchild == NULL)
					ptr = ptr->lchild;
				delete temp;
			}
		}
	}
}

void BiSortTree::Free(BiNode * p)
{
	if (p == NULL)
		return;
	Free(p->lchild);
	Free(p->rchild);
	delete p;
}

void BiSortTree::Print()
{
	if (root == NULL)
		return;
	SeqQueue<BiNode*, 20 >Q;
	Q.EnQueue(root);
	while (!Q.IsEmpty())
	{
		BiNode*p = Q.DeQueue();
		cout << p->key<<" ";
		if (p->lchild != NULL)
			Q.EnQueue(p->lchild);
		if (p->rchild != NULL)
			Q.EnQueue(p->rchild);
	}
}

BiSortTree::BiSortTree(int a[], int n)
{
	root = NULL;
	for (int i = 0; i < n; i++)
		Insert(root, a[i]);
}

BiSortTree::~BiSortTree()
{
	Free(root);
}

void BiSortTree::Insert(int k)
{
	Insert(root, k);
}

void BiSortTree::Search(int k)
{
	if (Search(root, k) == NULL)
		cout << "δ���ҵ���" << endl;
	else
		cout << "�ҵ��ˣ�" << Search(root, k)->key << endl;
}

void BiSortTree::Delete(int k)
{
	Delete(root, k);
}
