struct BiNode
{
	int key;
	BiNode* lchild, *rchild;
};
class BiSortTree
{
	BiNode* root;
	void Insert(BiNode *&ptr, int k);
	BiNode* Search(BiNode* ptr, int k);
	void Delete(BiNode *&ptr, int k);
	void Free(BiNode *ptr);
public:
	void Print();
	BiSortTree(int a[], int n);
	~BiSortTree();
	void Insert(int k);
	void Search(int k);
	void Delete(int k);
};