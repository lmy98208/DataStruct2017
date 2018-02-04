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
	cout << endl << "打印：" << endl;
	mg.Print();
	cout << endl << "遍历邻接矩阵：" << endl;
	mg.PrintEdges();                             //遍历邻接矩阵1
	cout << endl << "遍历邻接表：" << endl;
	mg.PrintVexs();
	cout << endl << "深度遍历测试：" << endl;
	mg.DFSTraverse(flag);
	cout << endl << "广度遍历测试：" << endl;
	mg.BFSTraverse();

	cout << endl << "顶点表中的第2个顶点的值：" << endl;
	cout << mg.GetVexValue(2);                        
	cout << endl << "顶点表中值‘3’的序号：" << endl;
	cout << mg.GetVexValueNum(3);                        
	cout << endl << "邻接矩阵中第3个顶点到第2个顶点的权值：" << endl;
	int cost=mg.GetEdgeValue(3, 2);  
	if (cost == 999) cout << "∞";
	else cout << cost;
	cout << endl <<  "插入一个顶点'5'：" << endl;
	mg.InsertVex('5');                           
	cout << endl << "删除一个顶点'5'：" << endl;
	mg.RemoveVex('5'); 
	EdgeType<int> e = { 0,2,10 };
	cout << endl << "插入一条权为10边0-2：" << endl;
	mg.InsertEdge(e);
	mg.Print();
	cout << endl << "删除此条权为10边0-2：" << endl;
	mg.DeleteEdge(e);
	mg.Print();
	
	cout << endl << "最小生成树（Prim）：" << endl;
	mg.Prim(0);
	cout << endl << "最小生成树（Kruskal）：" << endl;
	vector< EdgeType<int> > tree;
	mg.Kruskal(tree);            
	mg.PrintSubTree(mg,tree);

	cout << endl << "单源（3）最短路径：（Dijkstra）：" << endl;
	mg.Dijkstra(0);
	//cout << path[0]<<path[1]<<path[2]<<path[3]<<path[4];
	mg.PrintPath(mg,3);//测试结果

	cout << "每对顶点之间的最短路径（Floyd）：" << endl;
	int pathh[10][MAXV], D[10][MAXV];
	mg.Floyd(pathh, D);

	return 0;
}