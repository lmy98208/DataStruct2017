#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};

class TmpNode
{
	node* head;
public:
	TmpNode() { head = NULL; }
	TmpNode(int arry[], int i);
	node* LastNnode(int i);
	node* LastNnode2(int i);
	void print();
	~TmpNode() {}
}; 
