#include"MGraph.cpp"
#include<iostream>
#include<vector>
using namespace std;
int path[6], dist[10];

int main()
{
	bool flag = true;
	int temp[5] = { 0,1,2,3,4 };
	GraphType type = undigraph;
	MGraph<int> mg(type,temp,5,7);
	cout << endl << "��ӡ��" << endl;
	mg.Print();
	cout << endl << "�����ڽӾ���" << endl;
	mg.PrintEdges();                             //�����ڽӾ���1
	cout << endl << "�����ڽӱ�" << endl;
	mg.PrintVexs();
	cout << endl << "��ȱ������ԣ�" << endl;
	mg.DFSTraverse(flag);
	cout << endl << "��ȱ������ԣ�" << endl;
	mg.BFSTraverse();

	cout << endl << "������еĵ�2�������ֵ��" << endl;
	cout << mg.GetVexValue(2);                        
	cout << endl << "�������ֵ��3������ţ�" << endl;
	cout << mg.GetVexValueNum(3);                        
	cout << endl << "�ڽӾ����е�3�����㵽��2�������Ȩֵ��" << endl;
	int cost=mg.GetEdgeValue(3, 2);  
	if (cost == 999) cout << "��";
	else cout << cost;
	cout << endl <<  "����һ������'5'��" << endl;
	mg.InsertVex('5');                           
	cout << endl << "ɾ��һ������'5'��" << endl;
	mg.RemoveVex('5'); 
	EdgeType<int> e = { 0,2,10 };
	cout << endl << "����һ��ȨΪ10��0-2��" << endl;
	mg.InsertEdge(e);
	mg.Print();
	cout << endl << "ɾ������ȨΪ10��0-2��" << endl;
	mg.DeleteEdge(e);
	mg.Print();
	
	cout << endl << "��С��������Prim����" << endl;
	mg.Prim(0);
	cout << endl << "��С��������Kruskal����" << endl;
	vector< EdgeType<int> > tree;
	mg.Kruskal(tree);            
	mg.PrintSubTree(mg,tree);

	cout << endl << "��Դ��3�����·������Dijkstra����" << endl;
	mg.Dijkstra(0);
	//cout << path[0]<<path[1]<<path[2]<<path[3]<<path[4];
	mg.PrintPath(mg,3);//���Խ��

	cout << "ÿ�Զ���֮������·����Floyd����" << endl;
	int pathh[10][MAXV], D[10][MAXV];
	mg.Floyd(pathh, D);

	return 0;
}