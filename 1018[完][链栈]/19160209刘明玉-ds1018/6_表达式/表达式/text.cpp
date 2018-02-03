#include<iostream>
#include"SeqStack.cpp"
#include<string>
#include<math.h>
using namespace std;

double Expression_Eval();
double Operate(double a, char b, double c);
int GetPriority(char ch);

int main()
{
	//cout << "��������ʽ���ԡ�@����β����";
	cout << "��������ʽ���Իس���β����";
	double k=Expression_Eval();
	cout << "���Ϊ" << k << endl;
	return 0;
}
double Operate(double a, char b, double c)
{
	switch (b)
	{
	case '+': 
		return (a + c);
		break;
	case '-':
		return (a - c);
		break;
	case '*': 
		return (a*c);
		break;
	case '/':
		return (a / c);
		break;
	}
}

int GetPriority(char ch)//���������Ӧ�����ȼ���ĺ���������
{
	switch (ch)
	{
	case'+':
		return 0;
		break;
	case'-':
		return 1;
		break;
	case'*':
		return 2;
		break;
	case'/':
		return 3;
		break;
	case'(':
		return 4;
		break;
	case')':
		return 5;
		break;
	case'@':
		return 6;
		break;
	}
}


double Expression_Eval()
{
	int Precede[7][7] = {//�����ȼ�ת��Ϊ������ʽ
		{ '>', '>', '<', '<', '<', '>', '>' },
		{ '>', '>', '<', '<', '<', '>', '>' },
		{ '>', '>', '>', '>', '<', '>', '>' },
		{ '>', '>', '>', '>', '<', '>', '>' },
		{ '<', '<', '<', '<', '<', '=', '0' },
		{ '>', '>', '>', '>', '0', '>', '>' },
		{ '<', '<', '<', '<', '<', '0', '=' }
	};
	SeqStack<char, 100> OPTR;
	SeqStack<double, 100> OPND;
	OPTR.Push('@');
	char ch = getchar();
	
	while (ch != '\n'|| OPTR.Top() != '@')
	{
		if(ch >= '0'&&ch <= '9')//�Ľ���ʮ���ϵ�����
		{
			int i = 0, a[8] = { 0 };
			while (ch >= '0'&&ch <= '9')//�������е�����
			{
				a[i++] = (ch - '0');
				ch = getchar();
			}
			double sum = 0;
			for (int j = i-1; j >=0 ; j--)
				sum += a[j] * pow(10, i-j-1);
			//cout << sum << endl;
			OPND.Push(sum);
		}
		else
		{
			char pre_op = OPTR.Top();
			switch (Precede[GetPriority(pre_op)][GetPriority(ch)])
			{
			case'<':
				OPTR.Push(ch);
				ch = getchar();
				break;
			case'=':
				OPTR.Pop();
				ch = getchar();
				break;
			case'>':
				double b = OPND.Pop();
				double a = OPND.Pop();
				pre_op = OPTR.Pop();
				OPND.Push(Operate(a, pre_op, b));
				break;
			}
		}
	}
	return OPND.Top();
}