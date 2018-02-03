#include"LinkQueue.h"
template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsEmpty()
{
	return rear == front;
}

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsFull_1()//浪费一个空间
{
	return (rear + 1) % MaxSize == front;
}

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsFuLL_2()
{
	return ((flag == 1) && (rear = front));
}


template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::IsFull_3()
{
	return num == MaxSize;
}

template<class T, int MaxSize>
SeqQueue<T, MaxSize>::SeqQueue()
{
	rear = front = 0;
	flag = 0;
	num = 0;
}

template<class T, int MaxSize>
void SeqQueue<T, MaxSize>::EnQueue(T x)//进队
{
	if (IsFull_1())
	{
		cerr << "上溢";
		exit(1);
	}
	rear = (rear + 1) % MaxSize;
	num++;
	if (rear == front) flag = 1;//由进队造成的这个指针相等一定队列已满
	data[rear] = x;
}

template<class T, int MaxSize>
T SeqQueue<T, MaxSize>::DeQueue()//出队
{
	if (IsEmpty())
	{
		cerr << "下溢";
		exit(1);
	}
	front = (front + 1) % MaxSize;
	num--;
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
	return data[front+1];
}