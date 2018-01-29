#include"SeqList.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T, int MaxSize>
SeqList <T, MaxSize>::SeqList()//构造函数
{
	length = 0;
}

template<class T, int MaxSize>
SeqList <T, MaxSize>::SeqList(T a[], int n)//构造函数
{
	int i;
	if (n>MaxSize)
	{
		cerr << "参数非法";
		exit(1);
	}
	for (i = 0; i<n; i++)
		data[i] = a[i];
	length = n;
}

template<class T, int MaxSize>
int SeqList <T, MaxSize>::ListLength()//长度接口
{
	return length;
}

template<class T, int MaxSize>
T SeqList <T, MaxSize>::Get(int pos)//按位查找
{
	if (pos<1 || pos>length)
	{
		cerr << "查找位置非法";
		exit(1);
	}
	return data[pos - 1];
}

template<class T, int MaxSize>
int SeqList <T, MaxSize>::Locate(T item)//按值查找
{
	for (int i = 0; i<length; i++)
		if (data[i] == item)
			return i + 1;
	return 0;
}

template<class T, int MaxSize>
void SeqList <T, MaxSize>::PrintSeqList()//输出表
{
	for (int i = 0; i<length; i++)
		cout << data[i] << " ";
	cout << endl;
}

template<class T, int MaxSize>
void SeqList <T, MaxSize>::Insert(int i, T item)//插入
{
	if (length >= MaxSize)
	{
		cerr << "上溢";
		exit(1);
	}
	if (i<1 || i>length + 1)
	{
		cerr << "插入位置非法";
		exit(1);
	}
	for (int j = length - 1; j >= i - 1; j--)
		data[j + 1] = data[j];
	data[i - 1] = item;
	length++;
}

template<class T, int MaxSize>
T SeqList <T, MaxSize>::Delete(int i)//删除
{
	if (length == 0)
	{
		cerr << "下溢";
		exit(1);
	}
	if (i<1 || i>length)
	{
		cerr << "删除位置非法";
		exit(1);
	}
	T x = data[i - 1];
	for (int j = i; j<length; j++)
		data[j - 1] = data[j];
	length--;
	return x;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::UpdateData(int n, T tmp)
{
	data[n - 1] = tmp;
}

template<class T, int MaxSize>
void SeqList <T, MaxSize>::Sort()
{
	for (int i = 0; i<length - 1; i++)
		for (int j = 0; j<length - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				T temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
}

template<class T, int MaxSize>
void SeqList <T, MaxSize>::Merge(SeqList b)//排序
{
	int i = 0, j = 0, len = 0;
	int c[200];//maxsize为100，两个数组相加最多200
	while ((i < length) && (j < b.ListLength()))
	{
		if (data[i] < b.data[j])
			c[len++] = data[i++];
		else c[len++] = b.data[j++];
	}
	//b表没有排完时
	while (j <b.ListLength())
		c[len++] = b.data[j++];
	//a表没有排完时
	while (i<length)
		c[len++] = data[i++];
	length = len;//更新长度
	for (i = 0; i < length; i++)
		data[i] = c[i];
}

template<class T, int MaxSize>
int SeqList<T, MaxSize>::DeleteMin()
{
	int min = data[0], pos = 0;
	if (length == 0)
	{
		cerr << "error!";
		exit(1);//顺序表为空，退出运行
	}
	for (int i = 1; i < length; i++)
	{
		if (min > data[i])
		{
			min = data[i];
			pos = i;//pos记录最小值的位置
		}
	}
	data[pos] = data[length - 1];
	return min;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::DeleteS_T(int s, int t)
{
	if (s >= t)
	{
		cout << "s要小于t！";
		exit(0);
	}
	int i = 0, pos1 = 0, pos2 = 0;
	for (i = 0; i < length; i++)
	{
		if (data[i] <= s) pos1 = i;//找到删除区间的前面的前一个数
		else break;
	}
	for (; i < length; i++)
	{
		if (data[i] < t) pos2 = i;//找到删除区间的后面
		else break;
	}
	int count = pos2 - pos1;
	int j = pos1 + 1;//记录第一个要删的位置
	for (i = pos2 + 1; i < length; i++)
		data[j++] = data[i];
	length = length - count;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::Differ()
{
	int num[65536] = { 0 };//位置对应数值，判断是否重复
	memset(num, 0, 65536 * sizeof(int));
	int j = 0;//标记新data[]的最后一位
	int count = 0;//记录删除数值的个数
	for (int i = 0; i < length; i++)
	{
		if (num[data[i]] == 0) {
			num[data[i]]++;
			data[j++] = data[i];
		}
		else count++;
	}
	length = length - count;
}
