#include"LinkStack.h"
#include<iostream>
using namespace std;

template<class T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

template<class T>
void LinkStack<T>::Push(T x)
{
	Node<T>* s = new Node<T>;
	s->data = x;
	s->next = top;
	top = s;
}

template<class T>
T LinkStack<T>::Pop()
{
	if (IsEmpty())
	{
		cerr << "ÏÂÒç";
		exit(1);
	}
	int x = top->data;
	Node<T>* p = top;
	top = top->next;
	delete p;
	return x;
}

template<class T>
T LinkStack<T>::Top()
{
	if (IsEmpty())
	{
		cerr << "ÏÂÒç";
		exit(1);
	}
	return top->data;
}

template<class T>
bool LinkStack<T>::IsEmpty()
{
	return top == NULL;
}

template<class T>
LinkStack<T>::~LinkStack()
{
	Node<T>* p = top;
	while (p)
	{
		Node<T>* q = p;
		p = p->next;
		delete q;
	}
	top = NULL;
}