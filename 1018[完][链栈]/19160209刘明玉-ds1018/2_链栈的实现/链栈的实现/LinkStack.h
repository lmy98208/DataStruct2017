template <class T>
struct Node
{
	T data;
	Node <T>* next;
};

template<class T>
class LinkStack
{
	Node<T>* top;//ջ��ָ��
public:
	LinkStack();//���캯��
	~LinkStack();//��������
	void Push(T x);//��ջ
	T Pop();//��ջ
	T Top();//ȡջ��Ԫ��
	bool IsEmpty();//�п�
};
