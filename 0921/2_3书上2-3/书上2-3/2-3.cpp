#include<iostream>
using namespace std;
int main()
{
	int a[8] = { 0,1,5,6,9,5,45,100 };
	int i = 0, count = 0;
	cout << "ԭ����Ϊ��";
	for (i = 0; i < 8; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "����������ɾ�������֣�";
	int k = 0, pos_prev = 0, pos = 0;
	cin >> k;
	while (pos < 8)
	{
		if (a[pos] != k)
		{
			a[pos_prev++] = a[pos++];
			count++;
		}
		else pos++;
	}
	if (count == 8) cout << "����" << k << "�����ڣ�" << endl;
	else for (i = 0; i < count; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}