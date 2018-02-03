#include"SparseMatrix.h"
#include<iomanip>
#include<vector>
#include<iostream>
using namespace std;

template <class T>
SparseMatrix<T>::SparseMatrix()
{
	rows = cols = num = 0;
}

template <class T>
SparseMatrix<T>::SparseMatrix(Triple<T> *tlist, int rs, int cs, int n)
{
	rows = rs;
	cols = cs;
	num = n;
	triList.resize(num);
	for (int i = 0; i < num; i++)
	{
		triList[i].r = tlist[i].r;
		triList[i].c = tlist[i].c;
		triList[i].elem = tlist[i].elem;
	}
}

template <class T>
void SparseMatrix<T>::quicktrans(SparseMatrix<T> &B)
{
	B.rows = cols;
	B.cols = rows;
	B.num = num;
	B.triList.resize(num);
	if (num == 0)
		return ;
	int col;
	int *cnum = new int[cols];
	int *cpot = new int[cols];
	for (col = 0; col < cols; col++)
		cnum[col] = 0;
	for (int p = 0; p < num; p++)
		++cnum[triList[p].c];
	cpot[0] = 0;
	for (col = 1; col < cols; col++)
		cpot[col] = cpot[col - 1] + cnum[col - 1];
	for (int p = 0; p < num; p++)
	{
		col = triList[p].c;
		int q = cpot[col];
		B.triList[q].r = triList[p].c;
		B.triList[q].c = triList[p].r;
		B.triList[q].elem = triList[p].elem;
		++cpot[col];
	}
	delete[] cnum;
	delete[] cpot;
}

template <class T>
void SparseMatrix<T>::trans(SparseMatrix<T> &B)
{
	B.rows = cols;
	B.cols = rows;
	B.num = num;
	B.triList.resize(num);
	if (num == 0)
		return;
	int q = 0, p;
	for (int col = 0; col<cols; col++)
		for (p = 0; p<num; p++)
			if (triList[p].c == col)
			{
				B.triList[q].r = triList[p].c;
				B.triList[q].c = triList[p].r;
				B.triList[q].elem = triList[p].elem;
				++q;
			}
}

template <class T>
void SparseMatrix<T>::print()
{
	for (int i = 0; i < num; i++)
		cout << triList[i].r << " "
		<< triList[i].c << " "
		<< setw(4) << triList[i].elem << endl;
}