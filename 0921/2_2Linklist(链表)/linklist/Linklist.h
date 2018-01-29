template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template<class T>
class LinkList
{
	Node<T> * head;//头指针
public:
	LinkList();//建立带有头结点的空链表
	LinkList(T a[], int n);//建立带有n的元素的单链表
	~LinkList();//析构函数
	int ListLength();//链表长度
	T Get(int pos);//按位查找
	int Locate(T item);
	void PrintLinkList();
	void Insert(int i, T item);
	T Delete(int i);

	void Invert();//逆置
	void Merge(LinkList<T>&L1, LinkList<T>&L2);//合并
};
