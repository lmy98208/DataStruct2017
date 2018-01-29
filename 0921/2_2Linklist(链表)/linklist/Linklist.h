template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template<class T>
class LinkList
{
	Node<T> * head;//ͷָ��
public:
	LinkList();//��������ͷ���Ŀ�����
	LinkList(T a[], int n);//��������n��Ԫ�صĵ�����
	~LinkList();//��������
	int ListLength();//������
	T Get(int pos);//��λ����
	int Locate(T item);
	void PrintLinkList();
	void Insert(int i, T item);
	T Delete(int i);

	void Invert();//����
	void Merge(LinkList<T>&L1, LinkList<T>&L2);//�ϲ�
};
