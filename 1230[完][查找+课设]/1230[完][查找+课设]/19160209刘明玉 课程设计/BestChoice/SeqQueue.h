template<class T, int MaxSize>
class SeqQueue
{
private:
	int front, rear;
	T data[MaxSize];
public:
	SeqQueue();
	~SeqQueue() {}
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	bool IsEmpty();
	bool IsFull_1();
};