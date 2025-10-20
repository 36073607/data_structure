#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//图
//图的基本概念
//一.图的定义
//图是由顶点的有穷非空集合和顶点之间边的集合组成的
//通记为G(V,E)，其中G表示一个图，V(vertex:顶点)是图G中顶点的集合，E(edge:边)是边的集合
//V(G) 和 E(G) 通常分别表示图G的顶点集合和边集合

//二.无向图与有向图
//无向图： V(G)={0,1,2,3}   E(G)={(0,1),(0,2),(0,3),(1,2),(1,3),(2,3)}
//有向图:  V(G)={0,1,2}     E(G)={<0,1>,<1,2>,<1,0>}
//<0,1>:由0指向1，0是弧尾，1是弧头 （带箭头是弧头，不带箭头是弧尾）
//(0,1)与(1,0)一致

//三.简单图与多重图
//限制一：图中不能有从顶点到其自身的边
//限制二：同一条边在图中不能出现两次或两次以上   例如：无向图中(0,1)和(1,0)实际为同一条边
//不满足以上两条限制中任意一个的图称为多重图
//（我们目前讨论的全是简单图）

//四.完全图
//完全图：具有最多边数的图
//对于一个具有n个顶点的无向完全图，边数量的最大值为 n(n-1)/2
//对于一个具有n个顶点的有向完全图，边数量的最大值为 n(n-1)

//五.路径和路径长度
//路径：从一个顶点开始，经过一系列的边到达另外一个顶点形成的顶点序列 
//路径长度：路径上边的条数
//回路(环)：起点和终点相同，路径{0,3,1,0}是一个回路(环)

//六.简单路径
//简单路径：如果路径中不出现相同的顶点，则称为简单路径
//eg: 路径0,1,3,2 是一条简单路径      路径0,1,3,1 不是一条简单路径
//简单回路：除第一个顶点和最后一个顶点外，其余顶点不重复出现的回路称为简单回路

//七.顶点的度
//度：对于无向图，顶点的度指的是与顶点相关联边的数目
//入度：在有向图中，对于顶点v，箭头指向v的边的数目
//出度：在有向图中，对于顶点v，从该顶点出发的边的数目

//八.度与边的关系   （重要）
//在无向图中，假设具有n个顶点,e条边
//图中所有顶点度之和等于边数的两倍

//对于有向图，所有顶点的出度之和与入度之和相等，弧的数量也相等 （这里面弧的数量指的是弧头和弧尾，弧头与弧尾数量相等）

//九.子图
//图G的子图H，H满足V(H)是V(G)的子集且E(H)是E(G)的子集

//十.连通图
//连通：在无向图中，如果从顶点V到顶点W有路径，则称顶点V到顶点W是连通的
//如果对于图中任意两个顶点都是连通的，则称此图为连通图

//十一.连通分量
//无向图中的极大连通子图称为连通分量
//要点：子图，联通，含有最大顶点数
//具有极大顶点数的连通子图包含依附于这些顶点的所有边

//十二.强连通图
//强连通图：在有向图中，对于每一对顶点V和顶点W，从V到W和从W到V都有路径，则称该有向图是强连通图
//有向图中的极大强连通子图称为有向图的强连通分量

//十三.生成树
//生成树：指含有图中全部顶点的极小连通子树
//注意：包含所有顶点n,但只有足以构成一棵树的n-1条边

//十四.边的权和网
//在一个图中，每条边可以标注上一个代表某种含义的数值，该数值称为这个边的权值
//网：边上带着权值的图，也称为带权图

//十五.稀疏图与稠密图
//在图论中，稠密图（dense graph）和稀疏图（sparse graph）的概念是根据图中边的数量相对于顶点数量的平方来定义的。
//稠密图是指边的数量接近顶点数量的平方，而稀疏图则是指边的数量远小于顶点数量的平方。

//1.若无向图 G=(V,E) 中含有7个顶点，要保证图G在任何情况下都是连通的，则需要的边数至少是： 16
//思路：6个顶点，要保证任何情况下都是连通的，需要的边数最多是多少？，则再找一个顶点拉一条线就是题目要求的最少边数
//即6个顶点的无向完全图边数+1 ：6*5/2+1=16



//图的存储结构
//邻接矩阵-无向

//邻接矩阵-有向

//邻接矩阵-带权值
//边带权值就用权值表示，不带用无穷表示，自身用0表示

//邻接表-无向

//邻接表-有向

//逆邻接表

//十字链表：用横向的方向表达出边的事，用纵向的方向表达入边的事
//顶点结构：data firstin firstout    (firstin:入边表头指针   firstout:出边表头指针)
//边结构： tailvex headvex headlink taillink 
//注：这里的出边指从目标顶点a指向其他顶点
//    这里的入边指从其他顶点指向目标顶点a

//邻接多重表： ivex ilink jvex jlink   （一条边的结构）
//ivex和jvex是某一条边连接的两个顶点的下标
//ilink指同连接顶点ivex的下一条边
//jlink指同连接顶点jvex的下一条边





//深度优先遍历   类似树的前序遍历
typedef char VertexType;
typedef int EdgeType;
#define MAXSIZE 100

typedef struct Mat_Grph
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;

int visited[MAXSIZE];//已经读取过的顶点为1，未读取为0

void creat_grph(Mat_Grph* G)//邻接矩阵
{
	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->edge_num; j++)
		{
			G->arc[i][j] = 0;
		}

	}

	//A-B A-F
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	//B-C B-G B-I
	G->arc[1][2] = 1;
	G->arc[1][6] = 1;
	G->arc[1][8] = 1;

	//C-D C-I
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	//D-E D-G D-H D-I
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][8] = 1;

	//E-F E-H
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	//F-G
	G->arc[5][6] = 1;

	//G-H
	G->arc[6][7] = 1;


	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}

	}

}

void dfs(Mat_Grph* G, int i)//i表示顶点下标
{
	visited[i] = 1;//已访问
	printf("%c", G->vertex[i]);

	for (int j = 0; j < G->vertex_num; j++)
	{
		if (G->arc[i][j] == 1 && visited[j] == 0)
		{
			dfs(G, j);
		}
	}

}

int main()
{
	Mat_Grph G;
	creat_grph(&G);

	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}

	dfs(&G, 0);//0表示第一个顶点a的数组下标

	return 0;
}


//广度优先遍历   类似树的层序遍历
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
#define MAXSIZE 100

typedef struct Mat_Grph
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;

int visited[MAXSIZE];

void creat_grph(Mat_Grph* G)
{
	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[i][j] = 0;
		}

	}

	//A-B A-F
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	//B-C B-G B-I
	G->arc[1][2] = 1;
	G->arc[1][6] = 1;
	G->arc[1][8] = 1;

	//C-D C-I
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	//D-E D-G D-H D-I
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][8] = 1;

	//E-F E-H
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	//F-G
	G->arc[5][6] = 1;

	//G-H
	G->arc[6][7] = 1;


	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void bfs(Mat_Grph* G, int i = 0)//传入图G和顶点a的下标
{
	int queue[MAXSIZE];
	int front = 0;
	int rear = 0;

	queue[rear] = i;//第一个顶点入队
	rear++;
	visited[i] = 1;
	printf("%c", G->vertex[i]);

	while (rear != front)
	{
		i = queue[front];//出队
		front++;

		for (int j = 0; j < G->vertex_num; j++)//遍历所有可能的相邻节点
		{
			if (G->arc[i][j] == 1 && visited[j] == 0)
			{
				visited[j] = 1;
				queue[rear++] = j;
				printf("%c", G->vertex[j]);
			}

		}

	}

}

int main()
{
	Mat_Grph G;
	creat_grph(&G);
	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}
	bfs(&G, 0);

	return 0;
}


//最小生成树-普利姆(Prim)  关注顶点，一个点一个点去找
//这个图的极小连通子图就是它的最小生成树
#define MAXSIZE 100
#define MAX 0x7fffffff //int类型最大值表示无穷
typedef char VertexType;
typedef int EdgeType;

typedef struct Mat_Grph
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;

void creatGrph(Mat_Grph* G)
{
	G->vertex_num = 9;
	G->edge_num = 15;

	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;//对角线上的权值为0，毕竟自己跟自己都形成不了一条边
			}
			else
			{
				G->arc[i][j] = MAX;//其余的边先赋成无限
			}
		}
	}

	//给每条边赋权重值
	//A-B A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;

	//B-C B-G B-I
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;

	//C-D C-I
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;

	//D-E D-G D-H D-I
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;

	//E-F E-H
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;

	//F-G
	G->arc[5][6] = 17;

	//G-H
	G->arc[6][7] = 19;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

void prim(Mat_Grph* G)
{
	int i, j, k;//i,j是循环时用的，k用于记录下标
	int min;//经典打擂台，找出最小权值边
	int weight[MAXSIZE];//表示侯选边的权值
	int vex_index[MAXSIZE];//值表示出发点，下标表示到达点

	//先从第一个顶点开始
	weight[0] = 0;
	vex_index[0] = 0;

	for (i = 1; i < G->vertex_num; i++)//由于i=0的情况前面已经说明了，所有此处从1开始
	{
		weight[i] = G->arc[0][i];//其他顶点到A的权重
		vex_index[i] = 0;//都是从A出发
	}

	for (i = 1; i < G->vertex_num; i++)//找到最小的，与之连接    注意此处i从1开始，因为顶点已经加入了，只需循环n-1次即可
	{
		min = MAX;
		j = 0;
		k = 0;
		for (j = 0; j < G->vertex_num; j++)
		{
			if (weight[j] != 0 && weight[j] < min)
			{
				min = weight[j];
				k = j;//用k记录符合要求的下一个顶点的下标
			}

		}
		//printf("(%d %d)\n", vex_index[k], k);
		printf("(%c %c)\n", G->vertex[vex_index[k]], G->vertex[k]);

		weight[k] = 0;//该顶点已经被选完了，不能再作为侯选边

		//找新连接结点的待选路径，更新侯选边权重
		for (j = 0; j < G->vertex_num; j++)
		{
			if (weight[j] > G->arc[k][j] && weight[j] != 0)//这里的k就是新添加的顶点的下标值，不用管-1的问题
			{
				weight[j] = G->arc[k][j];
				vex_index[j] = k;
			}
		}
	}
}

int main()
{
	//Mat_Grph* G = (Mat_Grph*)malloc(sizeof(Mat_Grph));
	Mat_Grph G;
	creatGrph(&G);
	prim(&G);

	return 0;
}


//最小生成树-克鲁斯卡尔(Kruskal)  关注边，总是找权值最小的边
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x7fffffff //int类型最大值表示无穷
typedef char VertexType;
typedef int EdgeType;

typedef struct Mat_Grph
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;

typedef struct Edge
{
	int begin;
	int end;
	int weight;
}Edge;

void creatGrph(Mat_Grph* G)
{
	G->vertex_num = 9;
	G->edge_num = 15;

	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;//对角线上的权值为0，毕竟自己跟自己都形成不了一条边
			}
			else
			{
				G->arc[i][j] = MAX;//其余的边先赋成无限
			}
		}
	}

	//给每条边赋权重值
	//A-B A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;

	//B-C B-G B-I
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;

	//C-D C-I
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;

	//D-E D-G D-H D-I
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;

	//E-F E-H
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;

	//F-G
	G->arc[5][6] = 17;

	//G-H
	G->arc[6][7] = 19;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

void my_BubbleSort(Edge* t, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (t[j].weight > t[j + 1].weight)
			{
				Edge tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
		}

	}

}

int find(int* parent, int index)
{
	while (parent[index] > 0)//这里parent数组中有值时，就让同一条边另一个顶点“代替一下”，类似于逻辑上的成环，形成一个整体
	{
		index = parent[index];
	}
	return index;
}

void Kruskal(Mat_Grph* G)
{
	Edge edges[MAXEDGE];//存入每条边头、尾、权值
	int k = 0;//充当数组下标,最终k的值为数组具体元素
	//根据创建的那张图去创建edges数组
	for (int i = 0; i < G->vertex_num; i++)//j从i+1开始，防止取到对角线
	{
		for (int j = i + 1; j < G->vertex_num; j++)
		{
			edges[k].begin = i;
			edges[k].end = j;
			edges[k].weight = G->arc[i][j];
			k++;
		}

	}

	my_BubbleSort(edges, k);//对边进行排序

	int parent[MAXSIZE];//类似于Prim算法中的vex_index,数组中的值表示一个顶点，数组下标表示与之相连的另一个顶点
	for (int i = 0; i < G->vertex_num; i++)
	{
		parent[i] = 0;
	}

	int n, m;//用于表示顶点
	for (int i = 0; i < G->edge_num; i++)//15条边，循环15次
	{
		n = find(parent, edges[i].begin);
		m = find(parent, edges[i].end);
		if (n != m)//我的理解是它在联通的路里到处转，如果形成回路了就会转回原地，n = m；不成环即n!=m就输出
		{
			parent[n] = m;//让新的结果加入到parent数组中
			printf("(%c %c) %d\n", G->vertex[edges[i].begin], G->vertex[edges[i].end], edges[i].weight);
		}

	}

}

int main()
{
	Mat_Grph* G = new(Mat_Grph);
	creatGrph(G);
	Kruskal(G);
	delete G;

	return 0;
}


//总结：最小生成树
//最小生成树的顶点数n与边数e之间的关系：n = e + 1
//克鲁斯卡尔算法针对边，边数少时效率比较高，对稀疏图有优势
//普利姆算法对于边数多的情况，效率会好一些
//克鲁斯卡尔算法的时间复杂度为O(eloge),e是边数
//普利姆算法的时间复杂度为O(n^2),n是顶点





//最短路径-迪杰斯特拉(Dijkstra)
//此算法不是走最短路径的这个路径，而是在不断的去观察每一个顶点
//然后去找初始顶点到每一个顶点最短的权值是多少
//同时也找到达离每一个顶点最近的那一个顶点是谁
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000//下面算法涉及到MAX的加减，故不能设为int类型最大值

typedef int VertexType;
typedef int EdgeType;
typedef struct
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

void createGrph(Mat_Graph* G)
{
	G->vertex_num = 9;
	G->edge_num = 16;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;//这里用数字代表每个顶点
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = MAX;
			}

		}
	}

	G->arc[0][1] = 1;
	G->arc[0][2] = 5;

	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;

	G->arc[3][4] = 2;
	G->arc[3][6] = 3;

	G->arc[4][5] = 3;
	G->arc[4][6] = 6;
	G->arc[4][7] = 9;

	G->arc[5][7] = 5;

	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

int choose(int* found, int* distance, Mat_Graph* G)//这个函数的作用是：在未访问的顶点中，选择当前距离起点最近的顶点。
{
	int min = MAX;
	int minPos = -1;
	for (int i = 0; i < G->vertex_num; i++)
	{
		if (distance[i] < min && found[i] == 0)
		{
			min = distance[i];
			minPos = i;
		}

	}
	return minPos;
}

void dijkstra(Mat_Graph* G, int begin)
{
	int found[MAXSIZE];//记录顶点是否已经走过
	int	path[MAXSIZE];//用于记录两个顶点间的最短路径：数组值与该值对应的下标分别表示两个顶点。例如：path[0]=1,表示到达V0顶点的最近顶点为V1
	int distance[MAXSIZE];//用于记录初始顶点begin到达每一个顶点的最短距离,数组下标表示顶点

	for (int i = 0; i < G->vertex_num; i++)
	{
		found[i] = 0;
		path[i] = -1;//这里用-1表示初始顶点
		distance[i] = G->arc[begin][i];//先把与初始顶点直接相连的边的距离（每条边的权值）放入数组中
	}
	found[begin] = 1;
	distance[begin] = 0;

	int next;//用于记录下一个要观察的顶点
	for (int i = 0; i < G->vertex_num; i++)//循环，找出所有接下来要观察的顶点，并进行后续操作
	{
		next = choose(found, distance, G);//找到要观察的顶点
		if (next == -1)
			break; // 如果没有可达顶点，提前结束
		found[next] = 1;//将要观察的这个顶点设为"已观察"

		for (int j = 0; j < G->vertex_num; j++)//查找 要观察的顶点 是否带来更优的路径
		{
			// 修正条件：检查目标顶点j是否未访问，并且通过next到达j的路径更短
			if (found[j] == 0 && G->arc[next][j] != MAX && distance[next] + G->arc[next][j] < distance[j])
			{
				distance[j] = distance[next] + G->arc[next][j];
				path[j] = next;
			}
			//G->arc[next][j] != MAX 含义：顶点next和顶点j之间存在直接边（不是无穷大）作用：确保两个顶点是连通的
			//防止重复处理（条件1）确保路径存在（条件2）保证最优性（条件3）
		}
	}

	// 打印输出
	for (int i = 0; i < G->vertex_num; i++)// 对每个顶点i，输出从起点begin到i的最短路径信息
	{
		printf("V%d -> V%d : ", begin, i);
		if (distance[i] == MAX)
		{
			printf("Unreachable\n");
		}
		else
		{
			printf("%d\n", distance[i]);

			// 打印路径
			if (i != begin)
			{
				printf("Path: V%d", i);
				int j = i;
				while (path[j] != -1)//-1是起点
				{
					printf(" <- V%d", path[j]);
					j = path[j];
				}
				printf(" <- V%d\n", begin);
			}
			else//当i == begin时（起点到自身），直接输出起点，不需要回溯。
			{
				printf("Path: V%d\n", begin);
			}
		}
		printf("\n");
	}

}

int main()
{
	Mat_Graph* G = new(Mat_Graph);
	createGrph(G);
	int begin = 0;
	dijkstra(G, begin);

	return 0;
}



//最短路径-弗洛伊德(Floyd)
//核心：依次将图中的每个顶点作为“中间点”去做更新
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000//下面算法涉及到MAX的加减，故不能设为int类型最大值

typedef int VertexType;
typedef int EdgeType;
typedef struct
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

void createGrph(Mat_Graph* G)
{
	G->vertex_num = 9;
	G->edge_num = 16;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;//这里用数字代表每个顶点
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = MAX;
			}

		}
	}

	G->arc[0][1] = 1;
	G->arc[0][2] = 5;

	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;

	G->arc[3][4] = 2;
	G->arc[3][6] = 3;

	G->arc[4][5] = 3;
	G->arc[4][6] = 6;
	G->arc[4][7] = 9;

	G->arc[5][7] = 5;

	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void floyd(Mat_Graph* G)
{
	int path[MAXSIZE][MAXSIZE];//保存任意两个点之间的最短路径，注意：数组中的值代表的顶点是终点的前驱点（终点前面那个点）,二维数组两个下标表示从一个顶点到另一个顶点
	//path[i][j],i表示起点，j表示终点，数组中存的值表示从起点到终点要经过的前驱
	int distance[MAXSIZE][MAXSIZE];//保存任意两个点之间的最短路径长度

	//初始化，D(-1)和Path(-1)
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			distance[i][j] = G->arc[i][j];
			path[i][j] = j;//
		}
	}

	// j:起始顶点　i:中转顶点　k:终止顶点
	for (int j = 0; j < G->vertex_num; j++)
	{
		for (int i = 0; i < G->vertex_num; i++)
		{
			for (int k = 0; k < G->vertex_num; k++)
			{
				if (distance[j][k] > distance[j][i] + distance[i][k])//根据distance来更新path
				{
					distance[j][k] = distance[j][i] + distance[i][k];
					path[j][k] = path[j][i];
				}

			}
		}
	}

	int t;// 临时变量，用于追踪路径
	for (int i = 0; i < G->vertex_num; i++) // 遍历所有起始顶点
	{
		for (int j = i + 1; j < G->vertex_num; j++) // 遍历所有终止顶点（j>i，避免重复输出对称路径）
		{
			printf("V%d->V%d weight:%d ", i, j, distance[i][j]);// 输出顶点i到j的最短距离
			t = path[i][j]; // 获取路径中的第一个中间顶点
			printf("path:V%d", i);// 输出起始顶点

			while (t != j)// 关键：沿着路径追踪，直到到达终点j
			{
				printf("->V%d", t);// 输出路径中的顶点
				t = path[t][j];// 移动到路径中的下一个顶点
			}
			printf("->V%d\n", j); // 输出终点
		}
		printf("\n");// 每组起始顶点输出完后换行
	}
}
//输出重要细节：
//循环条件 j = i + 1：
//因为是无向图，distance[i][j] = distance[j][i]
//只输出 i < j 的情况，避免重复输出对称的路径对
//
//	路径追踪逻辑：
//	t = path[i][j] 得到从i出发的第一个顶点
//	t = path[t][j] 沿着路径一步步前进
//	当 t == j 时说明到达终点
//
//	输出格式：
//	先输出距离："V0->V1 weight:5 "
//	再输出完整路径："path:V0->V1->V2"
int main()
{
	Mat_Graph* G = new(Mat_Graph);
	createGrph(G);
	floyd(G);
	delete G;

	return 0;
}




//小结：
//最小生成树是指在一个加权连通图中，包含图中所有顶点且边的权值之和最小的树。
//它关注的是如何以最小的成本连接图中所有的顶点。最小生成树的算法包括Kruskal算法和Prim算法。
//这两种算法都是通过贪心策略来确保每次添加到树中的边都是当前可选边中权值最小的，从而保证最终生成的树的总权值最小。
//
//最短路径则是指在加权图中，从一个顶点到另一个顶点的路径中，边的权值之和最小的路径。
//它关注的是在图中找到两个特定顶点之间的最经济的路径。
//常用的最短路径算法有Dijkstra算法和Floyd算法。Dijkstra算法适用于单源最短路径问题，即从一个顶点出发到图中所有其他顶点的最短路径；
//而Floyd算法适用于任意两点间的最短路径问题。
//
//两者的主要区别在于：
//
//最小生成树的目标是连接图中所有顶点，使得所有顶点都被连通，且形成的树的边的总权值最小。
//它不保证任意两点之间的路径是最短的，而是保证整个图的全局最优。
//
//最短路径的目标是找到从一个顶点到另一个顶点的最短路径，它只关心特定两点间的最优解，而不考虑整个图的连通性。
//
//在实际应用中，如果问题是要连接网络中的所有节点，如电网、通信网络的建设，通常会使用最小生成树算法。
//如果问题是要找到两个城市之间的最短行驶路线，那么就会使用最短路径算法。






//拓扑排序：        注意：此处把一个邻接矩阵转换为邻接表
//在一个表示工程的有向图中，用顶点表示活动，用弧表示活动之间的优先级，这样的有向图为顶点表示活动的网，我们称为AOV网
//核心思想：持续寻找入度为0的顶点，然后入栈、出栈
//拓扑排序的顺序就是出栈的顺序，但由于许多顶点优先级相等，所以未必只有唯一的一种顺序
#include <iostream>
using namespace std;
typedef int VertextType;
typedef int EdgeType;
#define MAXSIZE 100

typedef struct Mat_Graph//邻接矩阵
{
	VertextType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

typedef struct EdgeNode
{
	int edge_vex;//目标顶点的下标
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertextNode
{
	int in;//顶点的入度是几
	VertextType data;
	EdgeNode* next;
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];//adjacency毗邻邻接，注意这个新知识点
//这行代码的意思是：定义一个新类型Adj_List，它是一个包含MAXSIZE个VertextNode元素的数组类型。
//Adj_List graph;  等价于 VertexNode graph[MAXSIZE];

typedef struct Adj_Graph//邻接表
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
}Adj_Graph;

typedef Adj_Graph* Adj_List_Graph;

void createGraph(Mat_Graph* G)//创建邻接矩阵
{
	G->vertex_num = 14;
	G->edge_num = 20;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;
	}
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	//邻接矩阵中，i表示起始顶点，j表示终止顶点
	G->arc[0][4] = 1;
	G->arc[0][5] = 1;
	G->arc[0][11] = 1;
	G->arc[1][2] = 1;
	G->arc[1][4] = 1;
	G->arc[1][8] = 1;
	G->arc[2][5] = 1;
	G->arc[2][6] = 1;
	G->arc[2][9] = 1;
	G->arc[3][2] = 1;
	G->arc[3][13] = 1;
	G->arc[4][7] = 1;
	G->arc[5][8] = 1;
	G->arc[5][12] = 1;
	G->arc[6][5] = 1;
	G->arc[8][7] = 1;
	G->arc[9][10] = 1;
	G->arc[9][11] = 1;
	G->arc[10][13] = 1;
	G->arc[12][9] = 1;

}

void creat_adj_graph(Mat_Graph* G, Adj_List_Graph* ALG)
{
	*ALG = new(Adj_Graph);
	(*ALG)->vertex_num = G->vertex_num;
	(*ALG)->edge_num = G->edge_num;

	for (int i = 0; i < G->vertex_num; i++)//对邻接表简单处理
	{
		(*ALG)->adj_list[i].in = 0;
		(*ALG)->adj_list[i].data = G->vertex[i];
		(*ALG)->adj_list[i].next = NULL;
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (G->arc[i][j] == 1)
			{
				EdgeNode* e = new(EdgeNode);
				e->edge_vex = j;

				//下面进行头插法:
				e->next = (*ALG)->adj_list[i].next;
				(*ALG)->adj_list[i].next = e;
				//i 表示边的起点（源顶点）
				//这行代码将新创建的边节点 e 插入到顶点 i 的邻接链表中

				(*ALG)->adj_list[j].in++;
				//j 表示边的终点（目标顶点）
				//这行代码增加顶点 j 的入度（in - degree）
				//表示"顶点 j 的入边数量增加1"
			}

		}
	}

}

int top = -1;
int stack[MAXSIZE];

void push(int e)
{
	if (top >= MAXSIZE)
	{
		printf("满了\n");
		return;
	}
	top++;
	stack[top] = e;
}

int pop()
{
	if (top == -1)
	{
		printf("空的\n");
		return 0;
	}
	int ret = stack[top];
	top--;
	return ret;
}

int is_empty()
{
	if (top == -1)
	{
		return 0;
	}
	return 1;
}

void topological_sort(Adj_List_Graph ALG)//进行拓扑排序
{
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (ALG->adj_list[i].in == 0)
		{
			push(i);
		}
	}

	while (::is_empty())
	{
		int curr = pop();
		printf("V%d -> ", ALG->adj_list[curr].data);
		EdgeNode* e = ALG->adj_list[curr].next;

		while (e != NULL)
		{
			int k = e->edge_vex;
			ALG->adj_list[k].in--;
			if (ALG->adj_list[k].in == 0)
			{
				push(k);
			}
			e = e->next;
		}

	}

}

int main()
{
	Mat_Graph* G = new(Mat_Graph);
	createGraph(G);

	Adj_List_Graph* ALG = new(Adj_List_Graph);
	creat_adj_graph(G, ALG);

	topological_sort(*ALG);

	delete G;
	delete ALG;

	return 0;
}






//关键路径：最长路径
//在一个表示工程的带权有向图中，用顶点表示事件，用有向边表示活动，用边上的权值表示活动的持续时间
//这种有向图的边表示活动的网，我们称为AOE

//etv:事件最早发生的时间(earliest time of vertex)，取最大值确保另一事件能够发生
//ltv:事件最晚发生的时间(lastest time of vertex)，取最小值确保另一事件能够发生

//AOE网的性质：
//只有在进入某顶点的活动都已经结束，该顶点所代表的事件才发生；
//只有在某顶点所代表的事件发生后，从该顶点出发的各活动才开始；

//最早发生时间和最晚发生时间相同的顶点之间连个线就是关键路径

//关键路径上的所有活动都是关键活动， 它是决定整个工程的关键因素，因此可以通过加快关键活动来缩短整个工期。但是也不能任意缩短，因为一旦缩短到一定的程度，该关键活动就可能变成非关键活动了
//网中的关键路径不唯一，对于有好几条关键路径的网，只加快其中某一条关键路径上的活动并不能缩短工期。只有加快存在于所有关键路径上的关键活动才能达到缩短工期的目的。

#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAX 0x7fffffff
typedef int VertextType;
typedef int EdgeType;

typedef struct Mat_Graph//邻接矩阵
{
	VertextType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

typedef struct EdgeNode
{
	int edge_vex;
	int weight;
	EdgeNode* next;
}EdgeNode;

typedef struct VertextNode
{
	int in;
	VertextType data;
	EdgeNode* next;
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];

typedef struct Adj_Graph//邻接表
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
}Adj_Graph;

typedef struct Adj_Graph* Adj_List_Graph;

void creatGraph(Mat_Graph* G)
{
	G->vertex_num = 10;
	G->edge_num = 13;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = MAX;
			}
		}
	}

	G->arc[0][1] = 3;
	G->arc[0][2] = 4;
	G->arc[1][3] = 5;
	G->arc[1][4] = 6;
	G->arc[2][3] = 8;
	G->arc[2][5] = 7;
	G->arc[3][4] = 3;
	G->arc[4][6] = 9;
	G->arc[4][7] = 4;
	G->arc[5][7] = 6;
	G->arc[6][9] = 2;
	G->arc[7][8] = 5;
	G->arc[8][9] = 3;

}

void creat_adj_graph(Mat_Graph* G, Adj_List_Graph* ALG)
{
	(*ALG)->vertex_num = G->vertex_num;
	(*ALG)->edge_num = G->edge_num;
	for (int i = 0; i < (*ALG)->vertex_num; i++)
	{
		(*ALG)->adj_list[i].data = G->vertex[i];
		(*ALG)->adj_list[i].in = 0;
		(*ALG)->adj_list[i].next = NULL;
	}

	for (int i = 0; i < (*ALG)->vertex_num; i++)
	{
		for (int j = 0; j < (*ALG)->vertex_num; j++)
		{
			if (G->arc[i][j] != 0 && G->arc[i][j] < MAX)
			{
				EdgeNode* e = new(EdgeNode);
				e->edge_vex = j;
				e->weight = G->arc[i][j];

				e->next = (*ALG)->adj_list[i].next;
				(*ALG)->adj_list[i].next = e;
				(*ALG)->adj_list[j].in++;
			}
		}

	}
}

void critical_path(Adj_List_Graph ALG)
{
	int top1 = -1;
	int top2 = -1;
	int stack1[MAXSIZE];//正常做事顺序，用来做拓扑排序或计算最早发生时间
	int stack2[MAXSIZE];//倒着的顺序，用来计算最晚发生时间
	//最晚发生时间是从后往前算的，做拓扑排序是从前往后的
	//每一次拓扑排序出栈后压入另一个栈
	//最后将另一个栈中的内容挨个出栈，达到逆序的效果
	int etv[MAXSIZE];//最早发生时间    etv[i] 表示事件i的最早发生时间，i通常是拓扑排序中的顶点序号
	int ltv[MAXSIZE];//最晚发生时间
	int curr = 0;//保存出栈的内容
	int k = 0;//k当作下标用

	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (ALG->adj_list[i].in == 0)
		{
			stack1[++top1] = i;
		}
	}
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		etv[i] = 0;
	}
	printf("toop: ");
	while (top1 != -1)
	{
		curr = stack1[top1--];
		printf("V%d - > ", ALG->adj_list[curr].data);

		top2++;
		stack2[top2] = curr;

		EdgeNode* e;
		e = ALG->adj_list[curr].next;
		while (e != NULL)
		{
			k = e->edge_vex;//k：由当前事件curr通过边e指向的下一个事件
			ALG->adj_list[k].in--;
			if (ALG->adj_list[k].in == 0)
			{
				stack1[++top1] = k;
			}

			if (etv[curr] + e->weight > etv[k])//curr最早发生时间+通过边e指向的下一个事件(顶点)k的时间，与 事件(顶点)k的最早发生时间比较
			{
				etv[k] = etv[curr] + e->weight;
				//etv[curr]：事件curr的最早发生时间
				//e->weight：从curr到k的活动的持续时间（权重）
				//etv[k]：事件k的最早发生时间
			}

			e = e->next;
		}
	}
	printf("End\n");
	printf("etv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", etv[i]);
	}
	printf("End\n");


	for (int i = 0; i < ALG->vertex_num; i++)
	{
		ltv[i] = etv[ALG->vertex_num - 1];
	}
	while (top2 != -1)
	{
		curr = stack2[top2--];
		EdgeNode* e;
		e = ALG->adj_list[curr].next;
		while (e != NULL)
		{
			k = e->edge_vex;
			if (ltv[curr] > ltv[k] - e->weight)
			{
				ltv[curr] = ltv[k] - e->weight;
			}
			e = e->next;
		}
	}
	printf("ltv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", ltv[i]);
	}
	printf("End\n");

	int flag = 1;
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (etv[i] == ltv[i])
		{
			if (!flag)
			{
				printf(" -> ");
			}
			printf("%d", i);
			flag = 0;
		}
	}

}

int main()
{
	Mat_Graph* G = new(Mat_Graph);
	creatGraph(G);

	Adj_List_Graph ALG = new(Adj_Graph);
	creat_adj_graph(G, &ALG);

	critical_path(ALG);

	delete ALG;
	delete G;

	return 0;
}

