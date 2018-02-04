#define MAXV 100
#include<iostream>
#include<vector>
using namespace std;
enum GraphType { undigraph, digraph, undinetwork, dinetwork };


template <class T>
struct Edge
{
	T adjvex;
	float lowcost;
};

template<class T>
class EdgeType
{
public:
	T head, tail;
	int cost;
	EdgeType() {}
	EdgeType(T h, T t, int c)
	{
		head = h; tail = t; cost = c;
	}
};

template<class T>
class MGraph
{
private:
	int vexnum, edgenum;
	GraphType kind;
	vector<vector<int> >edges;//�ڽӾ���
	vector<T>vexs;//�����
	void DFS(int v, bool *visited,bool flag);//��ͨ������������ȱ���
public:
	MGraph(GraphType t, T v[], int n, int e);
	~MGraph() {};
	void Print();
	bool IsConnect();
	int VexterNum() { return vexnum; }//����ͼ�еĶ�������
	int EdgeNum() { return edgenum; }//����ͼ�еı�����
	T GetVexValue(int i);//��i�������ֵ
	int GetVexValueNum(T v);//�������ֵ�����
	int GetEdgeValue(int i, int j);//����i-j��Ȩֵ
	int GetEdgeNum(int n);//����ÿ��������صı���Ŀ
	void InsertVex(T v);//���붥��
	void RemoveVex(T v);//ɾ������
	void InsertEdge(EdgeType<T> e);//�����
	void DeleteEdge(EdgeType<T> e);//ɾ����
	int DFSTraverse(bool flag);//������ȱ���6
	void BFSTraverse();//������ȱ���
	void PrintEdges();//�����ڽӾ���
	void PrintVexs();//���������
	int MiniNum(Edge<T>*miniedges);
	void Prim(int v);//Prim�㷨����С������
	void PrintSubTree(MGraph<T>&g, vector<EdgeType<T> >tree);
	void Kruskal(vector<EdgeType<T> > &tree);//Kruskal�㷨������С������
	void GetGraph(vector<EdgeType<T> >&graph);
	void Dijkstra(int v);//��Դ��С·��
	void PrintPath(MGraph<T>&g, int v);//���Dijikstra�Ľ��
	void Floyd(int path[][MAXV], int D[][MAXV]);//��������֮�����·��
};
