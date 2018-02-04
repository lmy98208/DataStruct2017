#include"MGraph.h"
#include"SeqQueue.cpp"
#include<vector>
#include<iostream>
using namespace std;

template<class T>
void MGraph<T>::Floyd(int path[][MAXV], int D[][MAXV])
{
	for (int i = 0; i<vexnum; i++)
		for (int j = 0; j<vexnum; j++)
		{
			if (i == j)
				D[i][j] = 0;
			else
				D[i][j] = GetEdgeValue(i, j);
			if (D[i][j]<999)
				path[i][j] = j;
			else path[i][j] = -1;
		}
	for (int k = 0; k<vexnum; k++)
		for (int i = 0; i<vexnum; i++)
			for (int j = 0; j<vexnum; j++)
				if (D[i][k] + D[k][j]<D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = path[i][k];
				}
	cout << "·����������D��\n";
	int i = 0, j = 0;
	for (; i < vexnum; i++)
	{
		cout << "\t";
		for (; j < vexnum; j++)
		{
			//if (D[i][j] == 999)cout << "��\t";else
			cout << D[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "·����������path��\n";
	for (i=0; i < vexnum; i++)
	{
		cout << "\t";
		for (j=0; j < vexnum; j++)
			cout << path[i][j] << "\t";
		cout << endl;
	}
}

template<class T>
void MGraph<T>::Dijkstra(int v)
{ 
	bool* s = new bool[vexnum];
	for (int i = 0; i<vexnum; i++)
	{
		s[i] = false;
		dist[i] = GetEdgeValue(v, i);
		if (dist[i]<999 || i == v)
			path[i] = v;
		else path[i] = -1;
	}
	dist[v] = 0;
	int k=0;
	s[v] = true;
	for (int i = 0; i<vexnum; i++)
	{
		int min = 999;
		for (int j = 0; j<vexnum; j++)
			if (!s[j] && dist[j]<min)
			{
				k = j;
				min = dist[j];
			}
		s[k] = true;
		for (int w = 0; w<vexnum; w++)
			if (!s[w] && dist[w]>dist[k] + GetEdgeValue(k, w))
			{
				dist[w] = dist[k] + GetEdgeValue(k, w);
				path[w] = k;
			}
	}
	delete[]s;
}
template<class T>
void MGraph<T>::PrintPath(MGraph<T>& g, int v)
{
	int count = 0;
	int temp[10];
	cout << 0 << "��" << v << "���·��Ϊ��" <<0;
	int j = v-1;
	temp[count++] = j;
	while (j != 0)
	{
		temp[count++] = path[j];
		j = path[j];//·������һ����Ϊ�µ��±�
	}
	for (count--; count >= 0; count--)
		cout << "-->" << temp[count]+1;
	cout << endl << "·������Ϊ��" << dist[v-1] << endl;;
}

template<class T>
void MGraph<T>::PrintSubTree(MGraph<T>&g, vector<EdgeType<T> >tree)
{
	int i = 0;
	while (i < tree.size())
	{
		cout << g.GetVexValue(tree[i].head) << "-->" << g.GetVexValue(tree[i].tail) << endl;
		i++;
	}
}

template<class T>
void MGraph<T>::Kruskal(vector<EdgeType<T> > &tree)
{
	if (!this->IsConnect())
	{
		cout << "����ͨͼ" << endl;
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
	for (i = 0; i<vexnum; i++)//�����еķ�0���������߼��뵽�����У�����������
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
	int i = 0, k, min;
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
		cout << "����ͨͼ" << endl;
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
		cout << vexs[v];             //���ʵ�v������
	visited[v] = true;              //���÷��ʱ�־Ϊtrue���ѷ��ʣ�
	for (int i = 0; i < vexnum; i++)//�����ϣ����걾��
		if ((edges[v][i] != 0) && (edges[v][i] != 999) && !visited[i])//������ڱߣ��ҽڵ�û�з��ʹ����ݹ���ʣ�
			DFS(i, visited, flag);
}

template<class T>
int MGraph<T>::DFSTraverse(bool flag)
{
	int i = 0;
	bool *visited = new bool[vexnum];   //�������ʱ������
	for (int v = 0; v < vexnum; v++)
		visited[v] = false;             //��ʼ�����ʱ�־���飨δ�����ʣ�
	for (int v = 0; v < vexnum; v++)
		if (!visited[v])
		{
			DFS(v, visited, flag);               //����δ���ʵĶ������DFS
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
	cout << "**********************��ӡ************************\n";
	for (int i = 0; i<vexnum; i++)
		cout << "\t" << vexs[i];
	cout << endl;
	cout << "______________________________________________" << endl;
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
				cout << "��" << "\t";
		}
		cout << endl;
	}
	cout << "������:" << vexnum << "��" << endl << "����:" << edgenum << "��" << endl;
}

template<class T>
T MGraph<T>::GetVexValue(int i)
{
	if (i < vexs.size())
		return vexs[i];
	else {
		cout << "Can't foud!\n";
		return -1;
	}
}

template<class T>
int MGraph<T>::GetVexValueNum(T v)
{
	for (int i = 0; i<vexs.size(); i++)
	{
		if (vexs[i] == v)
			return i;
	}
	cout << "Can't found" << endl;
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
								//��ʼ���ڽӾ���
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
		edgenum =edgenum - num;
		vexs.erase(vexs.begin() + n);
		edges.erase(edges.begin() + n);
		for (int i = 0; i<edges.size(); i++)
		{
			edges[i].erase(edges[i].begin() + n);
		}
		this->Print();
	}
	else cout << "ɾ��ʧ�ܣ���������\n";
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
	for (; i<n; i++)
		vexs[i] = v[i];
	for (i = 0; i < n; i++)
		edges[i].resize(vexnum);
	for (i = 0; i<n; i++)
	{
		for (j=0; j<n; j++)
			if (i == j)
				edges[i][j] = 0;
			else edges[i][j] = 999;
	}
	int va, vb, w;
	for (i = 0; i<e; i++)
	{
		cout << "������һ���ߵ������˵㣺";
		cin >> va >> vb;
		cout << "������ߵ�Ȩֵ��";
		cin >> w;
		edges[va][vb] = edges[vb][va] = w;
	}
}