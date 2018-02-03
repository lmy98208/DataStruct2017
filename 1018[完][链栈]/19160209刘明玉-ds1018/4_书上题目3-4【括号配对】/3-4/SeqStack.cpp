#include"SeqStack.h"

template<class T, int MaxSize>
SeqStack<T, MaxSize>::SeqStack()
{
	top = -1;
}

template<class T, int MaxSize>
void SeqStack<T, MaxSize>::Push(T x)
{
	if (IsFull())
	{
		cerr << "ÉÏÒç";
		exit(1);
	}
	data[++top] = x;
}

template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Pop()
{
	int x = 0;
	if (IsEmpty())
	{
		cerr << "ÏÂÒç";
		exit(1);
	}
	x = data[top--];
	return x;
}

template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Top()
{
	if (IsEmpty())
	{
		cerr << "ÏÂÒç";
		exit(1);
	}
	return data[top];
}

template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::IsEmpty()
{
	return top == -1;
}

template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::IsFull()
{
	return top == MaxSize - 1;
}