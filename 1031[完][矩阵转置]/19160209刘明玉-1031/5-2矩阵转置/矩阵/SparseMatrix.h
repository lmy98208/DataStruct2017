#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct Triple
{
	int r, c;
	T elem;
};

template <class T>
class SparseMatrix
{
	vector<Triple<T> >triList;
	int rows, cols, num;
public:
	SparseMatrix();
	SparseMatrix(Triple<T> *tlist, int rs, int cs, int n);
	void trans(SparseMatrix&B);
	void quicktrans(SparseMatrix&C);
	//SparseMatrix& plus(SparseMatrix&B);
	//SparseMatrix& mult(SparseMatrix&B);
	void print();
};
