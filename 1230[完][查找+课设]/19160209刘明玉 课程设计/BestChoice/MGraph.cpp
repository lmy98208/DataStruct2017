#include"MGraph.h"
#include"SeqQueue.cpp"
#include<vector>
#include<iostream>
#include<string>
#include <graphics.h>
#include <conio.h>
using namespace std;

template<class T>
void MGraph<T>::PrintSubTree(MGraph<T>&g, vector<EdgeType<T> >tree)
{
	unsigned int i = 0;
	while (i < tree.size())
	{
		cout << tree[i].head << "-->" << tree[i].tail << endl;
		i++;
	}
	
}

template<class T>
void MGraph<T>::Kruskal(vector<EdgeType<T> > &tree)
{
	if (!this->IsConnect())
	{
		cout << "非连通图" << endl;
		return;
	}
	int i;
	vector<EdgeType <T> >graph;
	GetGraph(graph);
	tree.resize(vexnum - 1);
	int *components = new int[edgenum];
	for (i = 0; i<vexnum; i++)
		components[i] = i;
	int k = 0;
	int j = 0;
	while (k<vexnum - 1)
	{
		int h1 = GetVexValueNum(graph[j].head);
		int t1 = GetVexValueNum(graph[j].tail);
		int h2 = components[h1];
		int t2 = components[t1];
		if (h2 != t2)
		{
			tree[k].head = GetVexValue(h1);
			tree[k].tail = GetVexValue(t1);
			tree[k].cost = graph[j].cost;
			k++;
			for (i = 0; i<vexnum; i++)
				if (components[i] == t2)
					components[i] = h2;
		}
		j++;
	}
	delete[]components;
}


template<class T>
void MGraph<T>::GetGraph(vector<EdgeType<T> >&graph)
{
	graph.resize(edgenum);
	int min = 0;
	int k = 0;
	int i, j;
	for (i = 0; i<vexnum; i++)//把所有的非0，非无穷大边加入到向量中，并进行排序
	{
		for (j = 0; j<i; j++)
		{
			if (edges[j][i]<999 && i != j)
			{
				graph[k].head = GetVexValue(j);
				graph[k].tail = GetVexValue(i);
				graph[k].cost = edges[j][i];
				k++;
			}
		}
	}
	EdgeType<T> e;
	for (i = 1; i<edgenum; i++)
	{
		for (j = edgenum - 1; j >= i; j--)
		{
			if (graph[j].cost<graph[j - 1].cost)
			{
				e = graph[j - 1];
				graph[j - 1] = graph[j];
				graph[j] = e;
				e = graph[j];
			}
		}
	}
}

template<class T>
int MGraph<T>::MiniNum(Edge<T>*miniedges)
{
	int i = 0, k;
	float min;
	while (miniedges[i].lowcost == 0)
		i++;
	min = miniedges[i].lowcost;
	k = i;
	for (int j = i + 1; j<vexnum; j++)
	{
		if (miniedges[j].lowcost != 0)
		{
			if (miniedges[j].lowcost<min)
			{
				k = j;
				min = miniedges[j].lowcost;
			}
		}
	}
	return k;
}
template<class T>
void MGraph<T>::Prim(int v)
{
	if (!this->IsConnect())
	{
		cout << "非连通图" << endl;
		return;
	}
	Edge<T>*miniedges = new Edge<T>[vexnum];
	for (int i = 0; i<vexnum; i++)
	{
		miniedges[i].adjvex = GetVexValue(v);
		miniedges[i].lowcost = GetEdgeValue(v, i);
	}
	miniedges[v].lowcost = 0;
	for (int i = 1; i<vexnum; i++)
	{
		int k = MiniNum(miniedges);
		cout << miniedges[k].adjvex << "-->" << GetVexValue(k) << endl;
		miniedges[k].lowcost = 0;
		for (int j = 0; j<vexnum; j++)
		{
			if (GetEdgeValue(k, j) < miniedges[j].lowcost)
			{
				miniedges[j].adjvex = GetVexValue(k);
				miniedges[j].lowcost = GetEdgeValue(k, j);
			}
		}
	}
	delete[]miniedges;
}

template<class T>
void MGraph<T>::DFS(int v, bool *visited, bool flag)
{
	if (flag == 0)
		cout << vexs[v];             //访问第v个顶点
	visited[v] = true;              //设置访问标志为true（已访问）
	for (int i = 0; i < vexnum; i++)//整体上，走完本行
		if ((edges[v][i] != 0) && (edges[v][i] != 999) && !visited[i])//如果存在边，且节点没有访问过，递归访问，
			DFS(i, visited, flag);
}

template<class T>
int MGraph<T>::DFSTraverse(bool flag)
{
	int i = 0;
	bool *visited = new bool[vexnum];   //建立访问标记数组
	for (int v = 0; v < vexnum; v++)
		visited[v] = false;             //初始化访问标志数组（未被访问）
	for (int v = 0; v < vexnum; v++)
		if (!visited[v])
		{
			DFS(v, visited, flag);               //对尚未访问的顶点调用DFS
			i++;
		}
	delete[]visited;
	return i;
}

template<class T>
void MGraph<T>::BFSTraverse()
{
	SeqQueue<int, 100>q;
	bool* visited = new bool[vexnum];
	for (int i = 0; i<vexnum; i++)
		visited[i] = false;
	for (int i = 0; i<vexnum; i++)
	{
		if (!visited[i])
		{
			cout << vexs[i];
			visited[i] = true;
			q.EnQueue(i);
			while (!q.IsEmpty())
			{
				int u = q.DeQueue();
				for (int j = 0; j<vexnum; j++)
				{
					if (edges[u][j] == 1 && !visited[j])
					{
						cout << vexs[j];
						visited[j] = true;
						q.EnQueue(j);
					}
				}
			}
		}
	}
	delete[]visited;
}

template<class T>
void MGraph<T>::PrintEdges()
{
	this->Print();
}

template<class T>
void MGraph<T>::PrintVexs()
{
	cout << "vexs:" << endl;
	for (int i = 0; i < vexnum; i++)
		cout << vexs[i] << " ";
	cout << endl;
}

template <class T>
void MGraph<T>::Print()
{
	cout << "*************************打印***************************\n";
	for (int i = 0; i<vexnum; i++)
		cout << "\t" << vexs[i];
	cout << endl;
	cout << "___________________________________________________" << endl;
	for (int i = 0; i<vexnum; i++)
	{
		cout << vexs[i] << "|" << "\t";
		for (int j = 0; j<vexnum; j++)
		{
			if (edges[i][j] != 999)
			{
				cout << edges[i][j] << "\t";
			}
			else
				cout << "∞" << "\t";
		}
		cout << endl;
	}
	cout << "顶点数:" << vexnum << "个" << endl << "边数:" << edgenum << "条" << endl;
}

template<class T>
T MGraph<T>::GetVexValue(int i)
{
	if (i < vexs.size())
		return vexs[i];
	/*else {
		cout << "Can't found!\n";
		return -1;
	}*/
}

template<class T>
int MGraph<T>::GetVexValueNum(T v)
{
	for (unsigned int i = 0; i<vexs.size(); i++)
	{
		if (vexs[i] == v)
			return i;
	}
	cout << "Can't found!" << endl;
	return -1;
}

template<class T>
int MGraph<T>::GetEdgeValue(int i, int j)
{
	if (i < vexnum && j < vexnum)
	{
		return edges[i][j];
	}
	else
		cout << "Error!" << endl;
	return -1;
}

template<class T>
void MGraph<T>::InsertVex(T v)
{
	int i;
	vexnum++;
	vexs.resize(vexnum);
	vexs[vexnum - 1] = v;
	edges.resize(vexnum);
	for (i = 0; i<vexnum; i++)
		edges[i].resize(vexnum);
	//初始化邻接矩阵
	for (i = 0; i<vexnum; i++)
	{
		edges[i][vexnum - 1] = edges[vexnum - 1][i] = 999;
	}
	this->Print();
}

template<class T>
int MGraph<T>::GetEdgeNum(int n)
{
	int num = 0;
	for (int i = 0; i<vexnum; i++)
	{
		if (edges[n][i] != 0 && edges[n][i] != 999)
		{
			num++;
		}
	}
	return num;
}

template<class T>
void MGraph<T>::RemoveVex(T v)
{
	int n = this->GetVexValueNum(v);
	if (n != -1)
	{
		int num = GetEdgeNum(n);
		vexnum--;
		edgenum = edgenum - num;
		vexs.erase(vexs.begin() + n);
		edges.erase(edges.begin() + n);
		for (int i = 0; i<edges.size(); i++)
		{
			edges[i].erase(edges[i].begin() + n);
		}
		this->Print();
	}
	else cout << "删除失败！输入有误！\n";
}

template<class T>
void MGraph<T>::InsertEdge(EdgeType<T> e)
{
	int i = e.head;
	int j = e.tail;
	if (i != j&&edges[i][j] == 999)
	{
		edges[i][j] = edges[j][i] = e.cost;
		edgenum++;
	}
	else cout << "Error!\n";
}

template<class T>
void MGraph<T>::DeleteEdge(EdgeType<T> e)
{
	int i = e.head;
	int j = e.tail;
	if (i != j)
	{
		edges[i][j] = edges[j][i] = 999;
		edgenum--;
	}
	else cout << "Error!\n";
}

template<class T>
bool MGraph<T>::IsConnect()
{
	int i = this->DFSTraverse(1);
	if (i == 1)
		return true;
	else
		return false;
}

template<class T>
MGraph<T>::MGraph(GraphType t, T v[], int n, int e)
{
	vexnum = n;
	edgenum = e;
	vexs.resize(vexnum);
	edges.resize(vexnum);

	kind = t;
	int i = 0, j = 0;
	for (; i < n; i++)
		vexs[i] = v[i];
	for (i = 0; i < n; i++)
		edges[i].resize(vexnum);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
			if (i == j)
				edges[i][j] = 0;
			else edges[i][j] = 999;
	}
	T va, vb;
	int w;
	ifstream in("data.txt");
	if (!in) {
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	for (i = 0; i<e; i++)
	{
		//cout << "请输入一条边的两个端点：";
		in >> va >> vb;
		//cout << va << "  " << vb << endl << endl;
		//cout << "请输入边的权值：";
		in >> w;
		int a = GetVexValueNum(va);
		int b = GetVexValueNum(vb);
		edges[a][b] = edges[b][a] = w;
	}
	in.close();
}