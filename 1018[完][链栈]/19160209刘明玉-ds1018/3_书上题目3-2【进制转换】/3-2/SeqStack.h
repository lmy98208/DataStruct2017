template<class T, int MaxSize>
class SeqStack
{
	T data[MaxSize];
	int top;
public:
	SeqStack();
	void Push(T x);
	T Top();
	T Pop();
	bool IsEmpty();
	bool IsFull();
};

