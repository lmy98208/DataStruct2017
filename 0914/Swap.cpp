#include<iostream>
using namespace std;
void Swap_xor(int p, int q)//���
{
	p = p^q;
	q = q^p;
	p = p^q;
	cout << "������ p=" << p << " q=" << q << endl;
}
void Swap_count(int p, int q)//�����Ӽ�
{
	p = p + q;
	q = p - q;
	p = p - q;
	cout << "������ p=" << p << " q=" << q << endl;
}
int main()
{
	cout << "�������������֣��Կո�ָ���" << endl;
	int p, q;
	cin >> p >> q;
	cout << "����ǰ�� p=" << p
		<< " q=" << q << endl;
	Swap_xor(p, q);
	Swap_count(p, q);
	return 0;
}