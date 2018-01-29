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
		cerr << "����";
		exit(1);
	}
	if(i==1) 
		data[++top1] = x;
	else 		
		data[--top2] = x;//�жϺ�����ջ
}

template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Pop(int i)
{
	int x = 0;
	if (IsEmpty(i))
	{
		cerr << "����";
		exit(1);
	}
	if(i==1) //�жϺ���Ҫ��ջ
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
		cerr << "����";
		exit(1);
	}
	if(i==1)//�жϺ��ߵ�ջ��
	return 
		data[top1];
	else return data[top2];
}

template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::IsEmpty(int i)//�ж�Ҫ��ջ��ջ���Ƿ�Ϊ��
{
	if(i==1)
	return top1 == -1;
	else return top2 == MaxSize;
}

template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::IsFull()//�ж�����ջ�Ƿ�����
{
	return top1+1 == top2;
}