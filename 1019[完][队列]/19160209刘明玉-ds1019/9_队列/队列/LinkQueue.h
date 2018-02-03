template<class T,int MaxSize>
class SeqQueue
{
private:
	int front, rear;
	T data[MaxSize];
	int num;
	int flag;
public:
	SeqQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	bool IsEmpty();
	bool IsFull_1();
	bool IsFuLL_2();
	bool IsFull_3();
}; 
