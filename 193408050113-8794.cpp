#include<iostream>
#define MAXVEX 10
#define INF 0
using namespace std;
class MGraph {
public:
	//��ʼ��
	void Init()
	{
		for (int i = 0; i < MAXVEX; i++)
			for (int j = 0;j < MAXVEX; j++)
				arc[i][j] = INF;
	}
	//�����ڽӾ���
	void Great()
	{
		int i, j, k, w;
		cout << "�����붥�����ͱ���:" << endl;
		cin >> vexnum >> edgenum;
		cout << "�����붥����Ϣ:" << endl;
		for (i = 0; i < vexnum; i++) {
			Vertex[i] = i;//�洢���
			cin >> Vername[i];//���붥������
		}
		for (k = 0; k < edgenum; k++) {
			cout << "�������(vi,vj)���±�i,j��Ȩw: ";
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
		vexnum++;//����������
	}
	//ɾ��ĳ������
	void DeleteVex(char ch)
	{
		int i, j, k;
		//����Ѱ�Ҷ���λ��
		for (i = 0; i < vexnum; i++)
			if (ch == Vername[i])
				break;
		//Vername����ѭ������
		for (j = i; j < vexnum - 1; j++)
			Vername[j] = Vername[j + 1];//����
		//arc����ѭ�����ƺ�����
		//����
		for (j = i; j < vexnum - 1; j++)
			for (k = 0; k < vexnum; k++)
				arc[j][k] = arc[j + 1][k];
		//����
		for (j = 0; j < vexnum - 1; j++)
			for (k = i; k < vexnum - 1; k++)
				arc[j][k] = arc[j][k + 1];
		vexnum--;
	}
	//����ĳ����
	void InsertEdge(int i, int j, int w)
	{
		arc[i][j] = w;
		edgenum++;
	}
	//ɾ��ĳ����
	void DeleteEdge(int i, int j)
	{
		arc[i][j] = INF;
		edgenum--;
	}
private:
	int Vertex[MAXVEX];//����洢�ڵ�����
	char Vername[MAXVEX];//����洢�ڵ������
	int arc[MAXVEX][MAXVEX];//�ڽӾ���
	int vexnum;//������
	int edgenum;//����
};
int main()
{
	MGraph MyGraph;
	MyGraph.Init();
	MyGraph.Great();
	MyGraph.Print();

	//���Ӷ���
	char ch;
	cout << "������Ҫ���ӵĶ�����Ϣ: ";
	cin >> ch;
	MyGraph.InsertVex(ch);
	MyGraph.Print();
	//ɾ������
	cout << "������Ҫɾ���Ķ������Ϣ: ";
	cin >> ch;
	MyGraph.DeleteVex(ch);
	MyGraph.Print();
	//����ĳ����
	int i, j, w;
	cout << "������Ҫ���ӵı���Ϣ: ";
	cin >> i >> j >> w;
	MyGraph.InsertEdge(i,j,w);
	MyGraph.Print();
	//ɾ��ĳ����
	cout << "������Ҫɾ���ı���Ϣ: ";
	cin >> i >> j;
	MyGraph.DeleteEdge(i,j);
	MyGraph.Print();
}