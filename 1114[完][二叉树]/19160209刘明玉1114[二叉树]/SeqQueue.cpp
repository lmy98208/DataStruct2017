#include"SeqQueue.h"

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsFull_1()
{
	return (rear + 1) % MaxSize == front;
}

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsEmpty()
{
	return rear == front;
}

template<class T, int MaxSize>
SeqQueue<T, MaxSize>::SeqQueue()
{
	rear = front = 0;
}

template<class T, int MaxSize>
void SeqQueue<T, MaxSize>::EnQueue(T x)
{
	if (IsFull_1())
	{
		cerr << "����";
		exit(1);
	}
	rear = (rear + 1) % MaxSize;
	data[rear] = x;
}

template<class T, int MaxSize>
T SeqQueue<T, MaxSize>::DeQueue()
{
	if (IsEmpty())
	{
		cerr << "����";
		exit(1);
	}
	front = (front + 1) % MaxSize;
	return data[front];
}

template<class T, int MaxSize>
T SeqQueue<T, MaxSize>::GetQueue()
{
	if (IsEmpty())
	{
		cerr << "����";
		exit(1);
	}
	return data[front + 1];
}