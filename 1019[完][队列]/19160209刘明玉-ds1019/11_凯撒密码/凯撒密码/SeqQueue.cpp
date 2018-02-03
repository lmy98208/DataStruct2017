#include"SeqQueue.h"

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsFuLL_3()
{
	return count==MaxSize;
}

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsEmpty()
{
	return count==0;
}

template<class T, int MaxSize>
SeqQueue<T, MaxSize>::SeqQueue()
{
	rear = 0;
	front = 0;
	count = 0;
}

template<class T, int MaxSize>
void SeqQueue<T, MaxSize>::EnQueue(T x)
{
	if (IsFuLL_3())
	{
		cerr << "上溢";
		exit(1);
	}
	count++;
	rear = (rear + 1) % MaxSize;
	data[rear] = x;
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
	count--;
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