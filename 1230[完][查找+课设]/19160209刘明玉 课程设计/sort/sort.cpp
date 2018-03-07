#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include"stdlib.h"
#include"time.h"
using namespace std;
int maxnum=1000000;
int r1[1000000] = { 0 },temp[1000000];
int shell[1000000] = { 0 }, quick[1000000] = { 0 }, heap[1000001] = { 0 },
merge[1000001] = { 0 };
//ջ���https://www.zhihu.com/question/37047634/answer/70170894
void ShellSort(int r[], int n);
int Partition(int r[], int i, int j);
void QuickSort(int r[],int i,int j);
void Sift(int r[], int k, int m);
void HeapSort(int r[], int n);
void Merge(int r[],int r1[],int s,int m,int t);
void MergePass(int r[], int r1[], int n, int h);
void MergeSort(int r[], int n); 

int main()
{
	ofstream out("data.txt");
	if (!out) {
		cout << "Can't open the file!" << endl;
		exit(0);
	}

	int count = 0;
	srand((unsigned)time(NULL));
	
	//˳�������򲿷�
	/*for (count = 0; count < maxnum; count++)
		temp[count] = rand();
	ShellSort(temp, maxnum);
	*/

	//��������򲿷�
	for (count=0; count < maxnum; count++)
		out <<rand()<<"\t";
	out.close();
	cout << "��������" << maxnum << "�������...\n";
	cout << "����д���ļ�...\n";
	ifstream in("data.txt");
	if (!in)
	{
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	count = 0;
	int text=0;
	while (in >> text)
	{
		shell[count++]=text;
		//cout << text << "\t";
	}
	in.close();
	
	cout << "���ڶ����ļ��е�����...\n";
	
	int heapPos = 1, mergePos = 1;
	for (count = 0; count < maxnum; count++)
	{
		//in >> shell[count];
		quick[count] = shell[count];
		heap[heapPos++] = shell[count];
		merge[mergePos++] = shell[count];
	}
	double time;
	clock_t start, finish;
	start= clock();
	ShellSort(shell,maxnum);
	finish = clock();
	time= (double)(finish - start) / CLOCKS_PER_SEC;
	//for (count = 0; count < maxnum; count++)
	//	cout << shell[count]<<"\t";
	cout << "\tϣ�����������..."<<time<<"s\n";

	start = clock();
	QuickSort(quick, 0, maxnum-1);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\t�������������..." << time << "s\n";
	
	start = clock();
	HeapSort(heap,maxnum);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\t�����������..." << time << "s\n";

	start = clock();
	MergeSort(merge,maxnum);
	finish = clock(); 
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\t�鲢���������..." << time << "s\n";
	
	ofstream out1("data.txt", ios::app);//ios::app��ʾ��ԭ�ļ�ĩβ׷��
	if (!out1) {
		cout << "Can't open the file!" << endl;
		exit(0);
	}

	out1 << "\n��ShellSort��\n";
	for (count=0; count < maxnum; count++)
		out1<< shell[count] << "\t";
	out1 << "\n\n��QuickSort��\n";
	for (count=0; count < maxnum; count++)
		out1<< quick[count] << "\t";
	out1 << "\n\n��HeapSort��\n";
	for (count=1; count <= maxnum; count++)
		out1 << heap[count] << "\t";
	out1 << "\n\n��MergeSort��\n";
	for (count=1; count <= maxnum; count++)
		out1 << merge[count] << "\t";
	
	out1.close();
	cout << "������ɣ���鿴�ļ�data.txt\n";
	return 0;
}

void ShellSort(int r[], int n)
{
	int j;
	for (int d = n / 2; d >= 1; d = d / 2)
	{
		for (int i = d; i < n; i++)
		{
			int temp = r[i];
			for ( j = i - d; j >= 0 && temp < r[j]; j = j - d)
				r[j + d] = r[j];
			r[j + d] = temp;
		}
	}
}

int Partition(int r[], int i, int j)
{
	int temp = r[i];
	while (i < j)
	{
		while (i < j&&r[j] >= temp)
			j--;
		if (i < j)
			r[i++] = r[j];
		while (i < j&&r[i] <= temp)
			i++;
		if (i < j)
			r[j--] = r[i];
	}
	r[i] = temp;
	return i;
}

void QuickSort(int r[], int i, int j)
{
	if (i < j)
	{
		int pivot = Partition(r, i, j);
		QuickSort(r, i, pivot - 1);
		QuickSort(r, pivot + 1, j);
	}
}

void Sift(int r[], int k, int m)
{
	int i = k;
	int j = 2 * i;
	while (j <= m)
	{
		if (j < m&&r[j] < r[j + 1])
			j++;
		if (r[i] > r[j])
			break;
		else {
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i = j;
			j = 2 * i;
		}
	}
}

void HeapSort(int r[], int n)
{
	for (int i = n / 2; i >= 1; i--)
		Sift(r, i, n);
	for (int i = 1; i < n; i++)
	{
		int temp = r[1];
		r[1] = r[n - i + 1];
		r[n - i + 1] = temp;
		Sift(r, 1, n - i);
	}
}

void Merge(int r[], int r1[], int s, int m, int t)
{
	int i = s;
	int j = m + 1;
	int k = s;
	while (i <= m&&j <= t)
	{
		if (r[i] <= r[j])
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];
	}
	while (i <= m)
		r1[k++] = r[i++];
	while (j <= t)
		r1[k++] = r[j++];
}

void MergePass(int r[], int r1[], int n, int h)
{
	int i = 1;
	while (i <= n - 2*h + 1)
	{
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i += 2 * h;
	}
	if (i < n - h + 1)
		Merge(r, r1, i, i +h -1, n);
	else
		for (int k = i; k <= n; k++)
			r1[k] = r[k];
}

void MergeSort(int r[], int n)
{
	int h = 1;
	while (h < n)
	{
		MergePass(r, r1, n, h);
		h = 2 * h;
		MergePass(r1, r, n, h);
		h = 2 * h;
	}
}
