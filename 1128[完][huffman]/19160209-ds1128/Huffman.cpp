#include"Huffman.h"
#include<vector>
#include<iostream>
using namespace std;

void HuffmanTree::SelectSmall(int&least, int&less, int i)
{
	int j;
	for (j = 0; j < i; j++)//j为第一个根节点下标
		if (hufftree[j].parent == -1)
			break;
	for (least = j, j++; j < i; j++)//j++ 从后一个节点比较
		if (hufftree[j].parent == -1 && hufftree[j].weight < hufftree[least].weight)
			least = j;
	for (j = 0; j < i; j++)
		if (hufftree[j].parent == -1 && j != least)
			break;
	for (less = j, j++; j < i; j++)
		if (hufftree[j].parent == -1 && j != least&&hufftree[j].weight < hufftree[less].weight)
			less = j;
}

HuffmanTree::HuffmanTree(vector<HuffmanNode>&leafs)
{
	n = leafs.size();
	hufftree.resize(2 * n - 1);
	for (int i = 0; i<n; i++)
	{
		hufftree[i].data = leafs[i].data;
		hufftree[i].weight = leafs[i].weight;
		hufftree[i].parent = hufftree[i].lchild = hufftree[i].rchild = -1;
	}
	for (int i = n; i < 2 * n - 1; i++)
	{
		int least, less;
		SelectSmall(least, less, i);
		hufftree[least].parent = hufftree[less].parent = i;
		hufftree[i].parent = -1;
		hufftree[i].rchild = less;
		hufftree[i].lchild = least;
		hufftree[i].weight = hufftree[least].weight + hufftree[less].weight;
	}
}

vector<int>HuffmanTree::GetCode(int i)
{
	vector<int> code;
	int p = i;
	int parent = hufftree[i].parent;
	while (parent != -1)
	{
		if (hufftree[parent].lchild == p)
			code.insert(code.begin(), 0);
		else
			code.insert(code.begin(), 1);
		p = parent;
		parent = hufftree[parent].parent;
	}
	return code;
}

string HuffmanTree::Decode(vector<int>&source)
{
	string target = "";
	int root = hufftree.size() - 1;
	int p = root;
	for (unsigned int i = 0; i<source.size(); i++)
	{
		if (source[i] == 0)
			p = hufftree[p].lchild;
		else
			p = hufftree[p].rchild;
		if (hufftree[p].lchild == -1 && hufftree[p].rchild == -1)
		{
			target = target + hufftree[p].data;
			p = root;
		}
	}
	return target;
}