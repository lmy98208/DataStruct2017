#include<iostream>
#include<fstream>
#include<sstream>
#include"SeqList.cpp"
#include"Goods.h"
using namespace std;

int Menu()
{
	int n;
	cout << "*********************Menu*******************\n";
	cout << "1.��ӡ����" << endl;
	cout << "2.�޸ļ�������¼" << endl;
	cout << "3.ɾ��ָ����¼" << endl;
	cout << "4.����Ʒ��������" << endl;
	cout << "0.��ȫ�˳�" << endl;
	cout << "*********************End********************\n";
	cout << "\n��ѡ��";
	cin >> n;
	return n;
}

int main()
{
	ifstream in("data.txt");
	if (!in) {
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	int count = 0, pos = 0;
	Goods str_arry[100];
	string str;
	while (getline(in, str))
	{
		istringstream sin(str);
		while (sin >> str_arry[count]) {
			count++;
		}
		pos++;
	}

	SeqList<Goods, 100> a(str_arry, pos);
	string n_index;//���������Ʒ���
	//Goods temp;//�ڽ��и����ʽʱ�õ�����ʱ��Ʒ��¼
	ofstream out("data.txt");

	int choice=Menu() ;
	while (choice)
	{
		switch (choice)
		{
		case 1:
		{
			cout << "\t" << "��Ʒ���" << "\t" << "��Ʒ����" << "\t"
				<< "�۸�" << "\t" << "���" << "\t" << "��Ϳ��" << endl;
			a.PrintSeqList();
			break;
		}
		case 2:
		{
			cout << "��������Ʒ��ţ�";
			string index;
			cin >> index;
			Goods temp(index, "null", 0.0, 0, 0);
			int n = a.Locate(temp);
			if (n)
			{
				temp = a.Get(n);//��λ����
				cout << "�����뵱ǰ��棺";
				int p, q;
				cin >> p;
				q=temp.UpdateStock(p);
				a.UpdateData(n,temp);
				cout << "�޸ĳɹ���\n";
			}
			else {
				cout << "���ڴ���һ���¼�¼��\n��������Ʒ�ı��롢���ơ��۸񡢿�桢��Ϳ�棺\n";
				string name, number;
				double price;
				int stock, low;
				cin >> number >> name >> price >> stock >> low;
				Goods temp(number, name, price, stock, low);
				a.Insert(++pos, temp);
				cout << "��ӳɹ���\n";
			}
			break;
		}
		case 3:
		{
			string in;
			cout << "��������Ҫɾ������Ʒ�ı�ţ�";
			cin >> in;
			Goods temp(in, "null", 0.0, 0, 0);
			int n = a.Locate(temp);//����Ʒ��¼��λ��
			cout<<a.Delete(n);
			cout << "\n������¼ɾ���ɹ���" << endl;
			break;
		}
		case 4:
		{
			a.Sort();
			cout << "Sorted!\n";
			cout << "\t" << "��Ʒ���" << "\t" << "��Ʒ����" << "\t"
				<< "�۸�" << "\t" << "���" << "\t" << "��Ϳ��" << endl;
			a.PrintSeqList();
			break;
		}
		case 0:
		{
			
			break;
		}
		default:cout << "��������ȷ����ţ�\n";
			break;
		}
		choice = Menu();
	}
	if (!out)
	{
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	for (int i = 1; i <= a.ListLength(); i++)//���������Ϣ�����ļ�
	{
		out << a.Get(i);
	}
	cout << "Updated��" << endl;
	cout << "************End***********" << endl;
	
	return 0;
}