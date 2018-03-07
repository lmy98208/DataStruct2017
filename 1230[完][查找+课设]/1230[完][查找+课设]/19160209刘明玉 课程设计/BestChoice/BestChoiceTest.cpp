#include"MGraph.cpp"
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<windows.h>
int x[12] = { 250,300,350,400,350,300,200,150,100,150,200,250 };
int y[12] = { 400,450,500,550,600,650,650,600,550,500,450,550};
int x_[12] = { 250,300,350,400,350,300,200,150,100,150,200,250 };
int y_[12] = { 50,100,150,200,250,300,300,250,200,150,100,200 };
using namespace std;

template <class T>
void printtree(MGraph<T>&mg, vector<EdgeType<T> >tree,string temp[])
{
	initgraph(600, 700);
	int i = 0;
	TCHAR s1[] = _T("1_С��");
	outtextxy(1, 0, s1);
	TCHAR s2[] = _T("2_С��");
	outtextxy(1, 25, s2);
	TCHAR s3[] = _T("3_С��");
	outtextxy(1, 50, s3);
	TCHAR s4[] = _T("4_С��");
	outtextxy(1, 75, s4);
	TCHAR s5[] = _T("5_С��");
	outtextxy(1, 100, s5);
	TCHAR s6[] = _T("6_С��");
	outtextxy(1, 125, s6);
	TCHAR s7[] = _T("7_С��");
	outtextxy(1, 150, s7);
	TCHAR s8[] = _T("8_С��");
	outtextxy(1, 175, s8);
	TCHAR s9[] = _T("9_С��");
	outtextxy(1, 200, s9);
	TCHAR s10[] = _T("10_Сǿ");
	outtextxy(1, 225, s10);
	TCHAR s11[] = _T("11_С��");
	outtextxy(1, 250, s11);
	TCHAR s12[] = _T("12_Сk");
	outtextxy(1, 275, s12);
	int j, k;
	int r = 12;
	int node[12];
	memset(node, 0, sizeof(int) * 12);
	TCHAR minitree[] = _T("��С������ͼ�����");
	outtextxy(100, 370, minitree);//����������ͼ��
	for (i = 0; i < tree.size(); i++)
	{
		for (j = 0; i < tree.size(); j++)
			if (tree[i].head == temp[j])
			{
				node[j] = node[j] + 1;
				break;
			}//�����
		for (k = 0; i < tree.size(); k++)
			if (tree[i].tail == temp[k])
			{
				node[k] = node[k] + 1;
				break;//���յ�
			}
		if (node[j] == 1)//�����
		{
			circle(x[j], y[j], r);
			TCHAR s[5];
			_stprintf_s(s, _T("%d"), j + 1);
			outtextxy(x[j] - 5, y[j] - 5, s);
		}//���������ڵ㣬�򻭵�
		if (node[k] == 1)//���յ�
		{
			circle(x[k], y[k], r);
			TCHAR s[5];
			_stprintf_s(s, _T("%d"), k + 1);
			outtextxy(x[k] - 5, y[k] - 5, s);
		}
		//Ϊ�����ۣ�ͨ���жϸ�����㡢�յ��������ҵĲ�ͬ���������
		if (y[j]<y[k])
			line(x[j], y[j] + r, x[k], y[k] - r);
		else if (y[j]>y[k])
			line(x[j], y[j] - r, x[k], y[k] + r);

		else if (x[j]>x[k]) line(x[j] - r, y[j], x[k] + r, y[k]);
		else line(x[j] + r, y[j], x[k] - r, y[k]);
		TCHAR s[5];
		_stprintf_s(s, _T("%d"), mg.GetEdgeValue(j, k));//��ע����
		outtextxy((x[j] + x[k]) / 2, (y[j] + y[k]) / 2, s);
	}

	TCHAR mgtree[] = _T("��ͨͼ��ͼ�����");
	outtextxy(100, 20, mgtree);//����������ͼ��
	for (i = 0; i < mg.VexterNum(); i++)//����
	{
		circle(x_[i], y_[i], r);
		TCHAR tmp[5];
		_stprintf_s(tmp, _T("%d"), i + 1);
		outtextxy(x_[i] - 5, y_[i] - 5, tmp);
	}
	for(i=0;i<mg.VexterNum();i++)
		for (j = 1 + i; j < mg.VexterNum(); j++)
			if (mg.GetEdgeValue(i, j) < 999)
			{
				//Ϊ�����ۣ�ͨ���жϸ�����㡢�յ��������ҵĲ�ͬ���������
				if (y_[i]<y_[j])
					line(x_[i], y_[i] + r, x_[j], y_[j] - r);
				else if (y_[i]>y_[j])
					line(x_[i], y_[i] - r, x_[j], y_[j] + r);
				else if (x_[i]>x_[j]) line(x_[i] - r, y_[i], x_[j] + r, y_[j]);
				else line(x_[i]+r, y_[i], x_[j]-r, y_[j]);
				
				TCHAR tmp[5];
				_stprintf_s(tmp, _T("%d"), mg.GetEdgeValue(i,j));
				outtextxy((x_[i] + x_[j]) / 2, (y_[i] + y_[j]) / 2, tmp);
			}
	int num;
	std::cin >> num;
	closegraph();
}


int main()
{
	bool flag = true;
	string temp[12] = { "С��","С��","С��","С��","С��","С��" ,"С��","С��","С��","Сǿ","С��","Сk"};
	//cout<<temp[4]<<endl;
	GraphType type = undigraph;
	MGraph<string> mg(type, temp, 12, 22);
	cout << endl << "��ӡ��" << endl;
	mg.Print();
	cout << endl << "��С��������Prim����" << endl;
	mg.Prim(0);
	cout << endl << "��С��������Kruskal����" << endl;
	vector< EdgeType<string> > tree;
	mg.Kruskal(tree);
	mg.PrintSubTree(mg, tree);
	cout << "�Ƿ�Ҫ��ͼ�������y/n\n";
	cout << "��ͼ��������水�����+�س������ء�\n";
	char choice;
	std::cin >> choice;
	if (choice == 'y')
		printtree(mg, tree,temp);
	return 0;
}

