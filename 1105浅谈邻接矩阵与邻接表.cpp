#define _CRT_SECURE_NO_WARNINGS
//邻接矩阵
#include <stdio.h>
#include <limits>
#define MAXSIZE 100
typedef char VertexType;
typedef int EdgeType;
typedef struct Mat_Graph
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

void creatGraph(Mat_Graph* G)//无向邻接矩阵
{
	printf("输入顶点数目，边数\n");
	scanf("%d %d", &G->vertex_num, &G->edge_num);
	for (int i = 0; i < G->vertex_num; i++)
		scanf(&G->vertex[i]);
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	for (int i = 0; i < G->edge_num ;i++)
	{
		int j, k;
		scanf("%d %d", &j, &k);
		G->arc[j][k] = 1;
		G->arc[k][j] = G->arc[j][k];
	}
}

void creatGraph_w(Mat_Graph* G)//无向网图创建
{
	printf("输入顶点数目，边数\n");
	scanf("%d %d", &G->vertex_num, &G->edge_num);
	for (int i = 0; i < G->vertex_num; i++)
		scanf(&G->vertex[i]);//注意这种写法
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = SHRT_MAX;
		}
	}
	for (int k = 0; k < G->edge_num; k++)
	{
		int i, j, w;
		printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
		scanf("%d %d %d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}

//邻接矩阵的深度优先算法
int visited[MAXSIZE];
void DFS(Mat_Graph* G, int i)
{
	visited[i] = 1;
	printf("%c ", G->vertex[i]);
	for (int j = 0; j < G->vertex_num; j++)
	{
		if (!visited[j] && G->arc[i][j] == 1)
			DFS(G, j);
	}
}

void DFS_Traverse(Mat_Graph* G)//DFS的外部驱动函数
{
	for (int i = 0; i < G->vertex_num; i++)
		visited[i] = 0;
	for (int i = 0; i < G->vertex_num; i++)
	{
		if (!visited[i])//对未访问的顶点调用，若为连通图则只调用一次
			DFS(G, i);
	}
}

//邻接矩阵的广度优先算法
int vistd[MAXSIZE];
void BFS(Mat_Graph* G)
{
	for (int i = 0; i < G->vertex_num; i++)
		vistd[i] = 0;
	int queue[MAXSIZE];
	int front = 0, rear = 0;
	for (int i = 0; i < G->vertex_num; i++)//针对非连通图
	{
		if (!vistd[i])
		{
			vistd[i] = 1;
			printf("%c ", G->vertex[i]);
			queue[rear++] = i;
			while (rear != front)
			{
				int curr = queue[front++];
				for (int j = 0; j < G->vertex_num; j++)
				{
					if (G->arc[curr][j] == 1 && !vistd[j])
					{
						vistd[j] = 1;
						printf("%c ", G->arc[curr][j]);
						queue[rear++] = j;
					}
				}
			}
		}
	}
}



//邻接表
#include <stdio.h>
#include <limits>
#define MAXSIZE 100
typedef char VertexType;
typedef int EdgeType;
typedef struct EdgeNode
{
	int edge_vex;//存储顶点的下标
	EdgeType info;//用于存储权值，对于非网图可以不需要
	EdgeNode* next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode* firstEdge;
}VertexNode;

typedef VertexNode Adj_List[MAXSIZE];

typedef struct Adj_Graph
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
};

void creatAdjGraph(Adj_Graph* G)//无向图邻接表创建
{
	EdgeNode* e;
	printf("输入顶点数和边数:\n");
	scanf("%d %d", &G->vertex_num, &G->edge_num);

	for (int i = 0; i < G->vertex_num; i++)
	{
		scanf(&G->adj_list[i].data);
		G->adj_list[i].firstEdge = NULL;
	}

	for (int k = 0; k < G->edge_num; k++)
	{
		int i, j;
		printf("输入边(vi,vj)上的顶点序号：\n");
		scanf("%d %d", &i, &j);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->edge_vex = j;
		e->next = G->adj_list[i].firstEdge;
		G->adj_list[i].firstEdge = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->edge_vex = i;
		e->next = G->adj_list[j].firstEdge;
		G->adj_list[i].firstEdge = e;
	}
}

//邻接表的深度优先算法
void DFS(Adj_Graph* G, int i)
{
	vistd[i] = 1;
	printf("%c ", G->adj_list[i].data);
	EdgeNode* e;
	e = G->adj_list[i].firstEdge;
	while (e)
	{
		if (!vistd[e->edge_vex])
			DFS(G, e->edge_vex);
		e = e->next;
	}
}

void DFS_Traverse(Adj_Graph* G)
{
	for (int i = 0; i < G->vertex_num; i++)
		vistd[i] = 0;
	for (int i = 0; i < G->vertex_num; i++)
	{
		if (!vistd[i])
			DFS(G, i);
	}
}


//邻接表的广度优先算法
void BFS_Traverse(Adj_Graph* G)
{
	for (int i = 0; i < G->vertex_num; i++)
		vistd[i] = 0;
	EdgeNode* e;
	int queue[MAXSIZE];
	int front = 0, rear = 0;
	for (int i = 0; i < G->vertex_num; i++)
	{
		if (!vistd[i])
		{
			vistd[i] = 1;
			printf("%c ", G->adj_list[i].data);
			queue[rear++] = i;

			while (rear != front)
			{
				int curr = queue[front++];
				e = G->adj_list[curr].firstEdge;
				while (e)
				{
					if (!vistd[e->edge_vex])
					{
						vistd[e->edge_vex] = 1;
						printf("%c ", G->adj_list[e->edge_vex].data);
						queue[rear++] = e->edge_vex;
					}
					e = e->next;
				}
			}
		}
	}

}