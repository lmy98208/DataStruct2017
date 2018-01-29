#include"SeqStack_.h"

template<class T, int MaxSize>
SeqStack<T, MaxSize>::SeqStack()
{
	top1 = -1;
	top2 = MaxSize;
}

template<class T, int MaxSize>
void SeqStack<T, MaxSize>::Push(int i,T x)
{
	if (IsFull())
	{
		cerr << "上溢";
		exit(1);
	}
	if(i==1) 
		data[++top1] = x;
	else 		
		data[--top2] = x;//判断何者入栈
}

template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Pop(int i)
{
	int x = 0;
	if (IsEmpty(i))
	{
		cerr << "下溢";
		exit(1);
	}
	if(i==1) //判断何者要出栈
		x = data[top1--];
	else 
		x = data[top2++];
	return x;
}

template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Top(int i)
{
	if (IsEmpty(i))
	{
		cerr << "下溢";
		exit(1);
	}
	if(i==1)//判断何者的栈顶
	return 
		data[top1];
	else return data[top2];
}

template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::IsEmpty(int i)//判断要出栈的栈中是否为空
{
	if(i==1)
	return top1 == -1;
	else return top2 == MaxSize;
}

template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::IsFull()//判断整个栈是否已满
{
	return top1+1 == top2;
}