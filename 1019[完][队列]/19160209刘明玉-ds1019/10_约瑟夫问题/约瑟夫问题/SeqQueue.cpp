#include"SeqQueue.h"

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsFuLL_2()
{
	return (flag && (front == rear));
}

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsEmpty()
{
	return ((flag == 0) && (rear == front));
}

template<class T, int MaxSize>
SeqQueue<T, MaxSize>::SeqQueue()
{
	rear = 0;
	front = 0;
	flag = 0;
}

template<class T, int MaxSize>
void SeqQueue<T, MaxSize>::EnQueue(T x)
{
	if (IsFuLL_2())
	{
		cerr << "上溢";
		exit(1);
	}
	flag = 1;
	rear = (rear + 1) % MaxSize;
	data[rear] = x;
	if (rear == front)
		flag = 1;//进栈使rear与front相等，栈满
}

template<class T, int MaxSize>
T SeqQueue<T, MaxSize>::DeQueue()
{
	if (IsEmpty())
	{
		cerr << "下溢";
		exit(1);
	}
	front = (front + 1) % MaxSize;
	if (front == rear) flag = 0;
	return data[front];
}

template<class T, int MaxSize>
T SeqQueue<T, MaxSize>::GetQueue()
{
	if (IsEmpty())
	{
		cerr << "下溢";
		exit(1);
	}
	return data[front];//不空格子，取data[front]
}