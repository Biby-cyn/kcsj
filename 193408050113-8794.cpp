#include<iostream>
#define MAXVEX 10
#define INF 0
using namespace std;
class MGraph {
public:
	//初始化
	void Init()
	{
		for (int i = 0; i < MAXVEX; i++)
			for (int j = 0;j < MAXVEX; j++)
				arc[i][j] = INF;
	}
	//创建邻接矩阵
	void Great()
	{
		int i, j, k, w;
		cout << "请输入顶点数和边数:" << endl;
		cin >> vexnum >> edgenum;
		cout << "请输入顶点信息:" << endl;
		for (i = 0; i < vexnum; i++) {
			Vertex[i] = i;//存储序号
			cin >> Vername[i];//输入顶点名字
		}
		for (k = 0; k < edgenum; k++) {
			cout << "请输入边(vi,vj)的下标i,j和权w: ";
			cin >> i >> j >> w;
			arc[j][i] = arc[i][j] = w;
		}

	}
	void Print()
	{
		for (int i = 0; i < vexnum; i++) {
			for (int j = 0; j < vexnum; j++)
				printf("%4d", arc[i][j]);
			cout << endl;
		}
	}
	void InsertVex(char ch)
	{
		Vertex[vexnum] = vexnum;
		Vername[vexnum] = ch;
		vexnum++;//顶点数自增
	}
	//删除某个顶点
	void DeleteVex(char ch)
	{
		int i, j, k;
		//遍历寻找顶点位置
		for (i = 0; i < vexnum; i++)
			if (ch == Vername[i])
				break;
		//Vername数组循环左移
		for (j = i; j < vexnum - 1; j++)
			Vername[j] = Vername[j + 1];//覆盖
		//arc数组循环左移和上移
		//上移
		for (j = i; j < vexnum - 1; j++)
			for (k = 0; k < vexnum; k++)
				arc[j][k] = arc[j + 1][k];
		//左移
		for (j = 0; j < vexnum - 1; j++)
			for (k = i; k < vexnum - 1; k++)
				arc[j][k] = arc[j][k + 1];
		vexnum--;
	}
	//增加某条边
	void InsertEdge(int i, int j, int w)
	{
		arc[i][j] = w;
		edgenum++;
	}
	//删除某条边
	void DeleteEdge(int i, int j)
	{
		arc[i][j] = INF;
		edgenum--;
	}
private:
	int Vertex[MAXVEX];//这个存储节点的序号
	char Vername[MAXVEX];//这个存储节点的名字
	int arc[MAXVEX][MAXVEX];//邻接矩阵
	int vexnum;//顶点数
	int edgenum;//边数
};
int main()
{
	MGraph MyGraph;
	MyGraph.Init();
	MyGraph.Great();
	MyGraph.Print();

	//增加顶点
	char ch;
	cout << "请输入要增加的顶点信息: ";
	cin >> ch;
	MyGraph.InsertVex(ch);
	MyGraph.Print();
	//删除顶点
	cout << "请输入要删除的顶点的信息: ";
	cin >> ch;
	MyGraph.DeleteVex(ch);
	MyGraph.Print();
	//增加某条边
	int i, j, w;
	cout << "请输入要增加的边信息: ";
	cin >> i >> j >> w;
	MyGraph.InsertEdge(i,j,w);
	MyGraph.Print();
	//删除某条边
	cout << "请输入要删除的边信息: ";
	cin >> i >> j;
	MyGraph.DeleteEdge(i,j);
	MyGraph.Print();
}