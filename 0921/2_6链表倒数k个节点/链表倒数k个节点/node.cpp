#include "node.h"
#include<iostream>
using namespace std;

TmpNode::TmpNode(int arry[], int i)
{
	head = new node;
	node *prev = head;
	for (int j = 0; j < i; j++)
	{
		node *p=new node ;
		p->data = arry[j];
		prev->next=p;
		prev = p;
	}
	prev->next = NULL;
}

node * TmpNode::LastNnode(int i)
{
	int count=0;
	node *p = head;
	while (p->next != NULL)
	{
		p = p->next;
		count++;
	}
	int j = 0;
	p = head;
	while (j < (count - i))
	{
		p = p->next;
		j++;
	}
	return p->next;
}

node * TmpNode::LastNnode2(int i)
{
	int count = 0;
	node* p = head;
	node* prev;
	for (; count < i; count++)
		p = p->next;
	prev = head;//ʹprev��p���i�����
	while (p != NULL)
	{
		p = p->next;
		prev = prev->next;
	}
	return prev;
}

void TmpNode::print()
{
	node *p;
	for (p = head->next; p != NULL; p = p->next)
		cout << p->data << " ";
	cout << endl;
}
