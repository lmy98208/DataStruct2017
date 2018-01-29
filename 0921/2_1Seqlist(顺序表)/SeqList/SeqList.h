template<class T, int MaxSize>
class SeqList
{
	T data[MaxSize];
	int length;
public:
	SeqList();//构造
	SeqList(T a[], int n);
	int ListLength();//长度接口
	T Get(int pos);//按位查找
	int Locate(T item);//按值查找
	void PrintSeqList();//遍历
	void Insert(int i, T item);//插入
	T Delete(int i);//删除
	/****扩展****/
	void Sort();//排序
	void Merge(SeqList b);//归并有序表
	int DeleteMin();
	void DeleteS_T(int s,int t);
	void Differ();
}; 
