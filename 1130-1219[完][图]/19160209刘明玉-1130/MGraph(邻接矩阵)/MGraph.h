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
	vector<vector<int> >edges;//邻接矩阵
	vector<T>vexs;//顶点表
	void DFS(int v, bool *visited,bool flag);//联通分量的深度优先遍历
public:
	MGraph(GraphType t, T v[], int n, int e);
	~MGraph() {};
	void Print();
	bool IsConnect();
	int VexterNum() { return vexnum; }//返回图中的定点数量
	int EdgeNum() { return edgenum; }//返回图中的边数量
	T GetVexValue(int i);//第i个顶点的值
	int GetVexValueNum(T v);//顶点表中值的序号
	int GetEdgeValue(int i, int j);//返回i-j的权值
	int GetEdgeNum(int n);//返回每个顶点相关的边数目
	void InsertVex(T v);//插入顶点
	void RemoveVex(T v);//删除顶点
	void InsertEdge(EdgeType<T> e);//插入边
	void DeleteEdge(EdgeType<T> e);//删除边
	int DFSTraverse(bool flag);//深度优先遍历6
	void BFSTraverse();//广度优先遍历
	void PrintEdges();//遍历邻接矩阵
	void PrintVexs();//遍历顶点表
	int MiniNum(Edge<T>*miniedges);
	void Prim(int v);//Prim算法求最小生成树
	void PrintSubTree(MGraph<T>&g, vector<EdgeType<T> >tree);
	void Kruskal(vector<EdgeType<T> > &tree);//Kruskal算法构造最小生成树
	void GetGraph(vector<EdgeType<T> >&graph);
	void Dijkstra(int v);//单源最小路径
	void PrintPath(MGraph<T>&g, int v);//输出Dijikstra的结果
	void Floyd(int path[][MAXV], int D[][MAXV]);//求各定点对之间最短路径
};
