#include<iostream>
#include<vector>
using namespace std;

struct HuffmanNode
{
	char data;
	double weight;
	int parent, lchild, rchild;
};

class HuffmanTree
{
private:
	vector<HuffmanNode> hufftree;
	int n;
public:
	HuffmanTree(vector<HuffmanNode>&leafs);
	~HuffmanTree() {}
	vector <int> GetCode(int i);
	string Decode(vector<int>&source);
	void SelectSmall(int&least, int&less, int i);
};
