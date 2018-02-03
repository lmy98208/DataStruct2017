template <class T>
struct Node
{
	T data;
	Node <T>* next;
};

template<class T>
class LinkStack
{
	Node<T>* top;//栈顶指针
public:
	LinkStack();//构造函数
	~LinkStack();//析构函数
	void Push(T x);//入栈
	T Pop();//出栈
	T Top();//取栈顶元素
	bool IsEmpty();//判空
};
