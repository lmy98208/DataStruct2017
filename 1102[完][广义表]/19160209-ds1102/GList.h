enum GListNodeType {ATOM,LIST};
template <class T>
struct GListNode
{
	GListNodeType type;
	union
	{
		T data;
		GListNode* sublist;
	};
	GListNode<T>*next;
};

template<class T>
class GList
{
private:
	GListNode<T>*head;
	GListNode<T>*DoCreate(char s[], int &i);
	GListNode<T>*Copy(GListNode<T>* p);
	void Traverse(GListNode<T>* p);
	void Free(GListNode<T>* p);
	int Depth(GListNode<T>* p);
public:
	GList();
	GList(char s[]);
	GList(GList<T>&gl);
	~GList();
	void Traverse();
	int Length();
	int Depth();
};
