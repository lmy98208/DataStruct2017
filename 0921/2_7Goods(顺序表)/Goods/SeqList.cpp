#include"SeqList.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T, int MaxSize>
SeqList <T, MaxSize>::SeqList()//���캯��
{
	length = 0;
}

template<class T, int MaxSize>
SeqList <T, MaxSize>::SeqList(T a[], int n)//���캯��
{
	int i;
	if (n>MaxSize)
	{
		cerr << "�����Ƿ�";
		exit(1);
	}
	for (i = 0; i<n; i++)
		data[i] = a[i];
	length = n;
}

template<class T, int MaxSize>
int SeqList <T, MaxSize>::ListLength()//���Ƚӿ�
{
	return length;
}

template<class T, int MaxSize>
T SeqList <T, MaxSize>::Get(int pos)//��λ����
{
	if (pos<1 || pos>length)
	{
		cerr << "����λ�÷Ƿ�";
		exit(1);
	}
	return data[pos - 1];
}

template<class T, int MaxSize>
int SeqList <T, MaxSize>::Locate(T item)//��ֵ����
{
	for (int i = 0; i<length; i++)
		if (data[i] == item)
			return i + 1;
	return 0;
}

template<class T, int MaxSize>
void SeqList <T, MaxSize>::PrintSeqList()//�����
{
	for (int i = 0; i<length; i++)
		cout << data[i] << " ";
	cout << endl;
}

template<class T, int MaxSize>
void SeqList <T, MaxSize>::Insert(int i, T item)//����
{
	if (length >= MaxSize)
	{
		cerr << "����";
		exit(1);
	}
	if (i<1 || i>length + 1)
	{
		cerr << "����λ�÷Ƿ�";
		exit(1);
	}
	for (int j = length - 1; j >= i - 1; j--)
		data[j + 1] = data[j];
	data[i - 1] = item;
	length++;
}

template<class T, int MaxSize>
T SeqList <T, MaxSize>::Delete(int i)//ɾ��
{
	if (length == 0)
	{
		cerr << "����";
		exit(1);
	}
	if (i<1 || i>length)
	{
		cerr << "ɾ��λ�÷Ƿ�";
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
void SeqList <T, MaxSize>::Merge(SeqList b)//����
{
	int i = 0, j = 0, len = 0;
	int c[200];//maxsizeΪ100����������������200
	while ((i < length) && (j < b.ListLength()))
	{
		if (data[i] < b.data[j])
			c[len++] = data[i++];
		else c[len++] = b.data[j++];
	}
	//b��û������ʱ
	while (j <b.ListLength())
		c[len++] = b.data[j++];
	//a��û������ʱ
	while (i<length)
		c[len++] = data[i++];
	length = len;//���³���
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
		exit(1);//˳���Ϊ�գ��˳�����
	}
	for (int i = 1; i < length; i++)
	{
		if (min > data[i])
		{
			min = data[i];
			pos = i;//pos��¼��Сֵ��λ��
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
		cout << "sҪС��t��";
		exit(0);
	}
	int i = 0, pos1 = 0, pos2 = 0;
	for (i = 0; i < length; i++)
	{
		if (data[i] <= s) pos1 = i;//�ҵ�ɾ�������ǰ���ǰһ����
		else break;
	}
	for (; i < length; i++)
	{
		if (data[i] < t) pos2 = i;//�ҵ�ɾ������ĺ���
		else break;
	}
	int count = pos2 - pos1;
	int j = pos1 + 1;//��¼��һ��Ҫɾ��λ��
	for (i = pos2 + 1; i < length; i++)
		data[j++] = data[i];
	length = length - count;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::Differ()
{
	int num[65536] = { 0 };//λ�ö�Ӧ��ֵ���ж��Ƿ��ظ�
	memset(num, 0, 65536 * sizeof(int));
	int j = 0;//�����data[]�����һλ
	int count = 0;//��¼ɾ����ֵ�ĸ���
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
