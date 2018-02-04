#include<iostream>
#include"GList.h"
using namespace std;
template<class T>
GList<T>::GList()
{
	head = new GListNode<T>;
	head->type = LIST;
	head->sublist = head->next = NULL;
}

template<class T>
GListNode<T>* GList<T>::DoCreate(char s[], int &i)
{
	GListNode<T>* p;
	while (s[i] == ' ' || s[i] == ',')
		i++;
	char e = s[i];
	i++;

	if (e == '(')
	{
		p = new GListNode<T>;
		p->type = LIST;
		p->sublist = DoCreate(s, i);
		p->next = DoCreate(s, i);
		return p;
	}
	if (e == ')' || e == '\0')
		return NULL;
	p = new GListNode<T>;
	p->type = ATOM;
	p->data = e;
	p->next = DoCreate(s, i);
	return p;
}

template <class T>
GList<T>::GList(char s[])
{
	int i = 0;
	head = DoCreate(s, i);
}

template<class T>
void GList<T>::Traverse(GListNode<T>*p)
{
	if (p == NULL)
		return;
	if (p->type == ATOM)
		cout << p->data;
	else
	{
		cout << '(';
		Traverse(p->sublist);
		cout << ')';
	}
	if (p->next)
		cout << ",";
	Traverse(p->next);
}
template<class T>
void GList<T>::Traverse()
{
	Traverse(head);
}

template<class T>
GListNode<T>*GList<T>::Copy(GListNode<T>* p)
{
	if (p == NULL)
		return NULL;
	GListNode<T>*newp = new GListNode<T>;
	newp->type = p->type;
	if (p->type == LIST)
		newp->sublist = Copy(p->sublist);
	else
		newp->data = p->data;
	newp->next = Copy(p->next);
	return newp;
}
template<class T>
GList<T>::GList(GList<T>&gl)
{
	head = Copy(gl.head);
}

template<class T>
int GList<T>::Length()
{
	GListNode<T>*p;
	int n = 0;
	p = head->sublist;
	while (p)
	{
		p = p->next;
		n++;
	}
	return n;
}

template<class T>
int GList<T>::Depth(GListNode<T>*p)
{
	if (p->type == ATOM)
		return 0;
	int maxdepth = 0;
	GListNode<T>*q;
	q = p->sublist;
	while (q)
	{
		int depth = Depth(q);
		if (depth > maxdepth)
			maxdepth = depth;
		q = q->next;
	}
	return ++maxdepth;
}
template<class T>
int GList<T>::Depth()
{
	return Depth(head);
}

template <class T>
void GList<T>::Free(GListNode<T>*p)
{
	if (p == NULL)
		return;
	if (p->type == LIST)
		Free(p->sublist);
	Free(p->next);
	delete p;
}
template<class T>
GList<T>::~GList()
{
	Free(head);
}