#include<iostream>
#include"SeqList.cpp"
using namespace std;
int main()
{
	int a[10], b[5], k = 0, j = 0;
	cout << "������ԭʼ˳�����8�����֣� " << endl;
	for (int i = 0; i<8; i++)
		cin >> a[i];
	SeqList <int, 100> s(a, 8);//���Թ��캯��
	cout << "ԭʼ˳���Ϊ��";
	s.PrintSeqList();//���Ա�������
	cout << "������������ҵ�λ�ã�������1-8��";
	cin >> k;
	
	cout << "��λ��" << k << "����ֵΪ" << s.Get(k) << "��" << endl;//���԰�λ���Һ���
	cout << "������������ҵ�ֵ��";
	cin >> k;
	if (s.Locate(k)==0) {
		cout << "û�д�����\n";
		exit(1);
	}
	cout << "������ҵ�ֵ" << k << "�ڵ�" << s.Locate(k) << "��λ�á�" << endl;//���԰�ֵ���Һ���
	cout << "�����������ڵ�n��λ�ò��������k(n k):";
	cin >> j >> k;
	s.Insert(j, k);//���Բ��뺯��
	cout << "������˳��Ϊ��";
	s.PrintSeqList();
	cout << "����������ɾ����λ�ã�������1-9��";
	cin >> j;
	cout << "ɾ����λ�ú�ı�Ϊ��";
	s.Delete(j);//����ɾ������
	s.PrintSeqList();
	s.Differ();
	cout << "ɾȥ�ظ���ֵ���˳���Ϊ��" << endl;
	s.PrintSeqList();
	k=s.DeleteMin();
	cout << "ɾ����Сֵ��" << k << endl;
	s.PrintSeqList();
	

	cout << endl << "�����ٴ�����һ��˳�����5�����֣�" << endl;
	for (k = 0; k < 5; k++)
		cin >> b[k];
	SeqList <int, 100> ss(b, 5);
	s.Sort();//����������
	ss.Sort();
	cout << "�����������ֱ�Ϊ��" << endl;
	s.PrintSeqList();
	ss.PrintSeqList();
	cout << "�鲢����������Ľ��Ϊ��" << endl;
	s.Merge(ss);//���Թ鲢����
	s.PrintSeqList();
	cout << "�����루s t����ʹɾ����������ڸ���ֵs-t���Ԫ�أ�";
	int p, q;
	cin >> p >> q;
	s.DeleteS_T(p,q);
	s.PrintSeqList();
	return 0;
}