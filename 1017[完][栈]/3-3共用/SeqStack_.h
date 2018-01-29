template<class T, int MaxSize>
class SeqStack
{
	T data[MaxSize];
	int top1;
	int top2;
public:
	SeqStack();
	void Push(int i,T x);
	T Top(int i);
	T Pop(int i);
	bool IsEmpty(int i);
	bool IsFull();
};
