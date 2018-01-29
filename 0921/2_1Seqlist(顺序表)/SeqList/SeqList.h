template<class T, int MaxSize>
class SeqList
{
	T data[MaxSize];
	int length;
public:
	SeqList();//����
	SeqList(T a[], int n);
	int ListLength();//���Ƚӿ�
	T Get(int pos);//��λ����
	int Locate(T item);//��ֵ����
	void PrintSeqList();//����
	void Insert(int i, T item);//����
	T Delete(int i);//ɾ��
	/****��չ****/
	void Sort();//����
	void Merge(SeqList b);//�鲢�����
	int DeleteMin();
	void DeleteS_T(int s,int t);
	void Differ();
}; 
