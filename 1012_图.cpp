#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//ͼ
//ͼ�Ļ�������
//һ.ͼ�Ķ���
//ͼ���ɶ��������ǿռ��ϺͶ���֮��ߵļ�����ɵ�
//ͨ��ΪG(V,E)������G��ʾһ��ͼ��V(vertex:����)��ͼG�ж���ļ��ϣ�E(edge:��)�Ǳߵļ���
//V(G) �� E(G) ͨ���ֱ��ʾͼG�Ķ��㼯�Ϻͱ߼���

//��.����ͼ������ͼ
//����ͼ�� V(G)={0,1,2,3}   E(G)={(0,1),(0,2),(0,3),(1,2),(1,3),(2,3)}
//����ͼ:  V(G)={0,1,2}     E(G)={<0,1>,<1,2>,<1,0>}
//<0,1>:��0ָ��1��0�ǻ�β��1�ǻ�ͷ ������ͷ�ǻ�ͷ��������ͷ�ǻ�β��
//(0,1)��(1,0)һ��

//��.��ͼ�����ͼ
//����һ��ͼ�в����дӶ��㵽������ı�
//���ƶ���ͬһ������ͼ�в��ܳ������λ���������   ���磺����ͼ��(0,1)��(1,0)ʵ��Ϊͬһ����
//������������������������һ����ͼ��Ϊ����ͼ
//������Ŀǰ���۵�ȫ�Ǽ�ͼ��

//��.��ȫͼ
//��ȫͼ��������������ͼ
//����һ������n�������������ȫͼ�������������ֵΪ n(n-1)/2
//����һ������n�������������ȫͼ�������������ֵΪ n(n-1)

//��.·����·������
//·������һ�����㿪ʼ������һϵ�еıߵ�������һ�������γɵĶ������� 
//·�����ȣ�·���ϱߵ�����
//��·(��)�������յ���ͬ��·��{0,3,1,0}��һ����·(��)

//��.��·��
//��·�������·���в�������ͬ�Ķ��㣬���Ϊ��·��
//eg: ·��0,1,3,2 ��һ����·��      ·��0,1,3,1 ����һ����·��
//�򵥻�·������һ����������һ�������⣬���ඥ�㲻�ظ����ֵĻ�·��Ϊ�򵥻�·

//��.����Ķ�
//�ȣ���������ͼ������Ķ�ָ�����붥��������ߵ���Ŀ
//��ȣ�������ͼ�У����ڶ���v����ͷָ��v�ıߵ���Ŀ
//���ȣ�������ͼ�У����ڶ���v���Ӹö�������ıߵ���Ŀ

//��.����ߵĹ�ϵ   ����Ҫ��
//������ͼ�У��������n������,e����
//ͼ�����ж����֮�͵��ڱ���������

//��������ͼ�����ж���ĳ���֮�������֮����ȣ���������Ҳ��� �������满������ָ���ǻ�ͷ�ͻ�β����ͷ�뻡β������ȣ�

//��.��ͼ
//ͼG����ͼH��H����V(H)��V(G)���Ӽ���E(H)��E(G)���Ӽ�

//ʮ.��ͨͼ
//��ͨ��������ͼ�У�����Ӷ���V������W��·������ƶ���V������W����ͨ��
//�������ͼ�������������㶼����ͨ�ģ���ƴ�ͼΪ��ͨͼ

//ʮһ.��ͨ����
//����ͼ�еļ�����ͨ��ͼ��Ϊ��ͨ����
//Ҫ�㣺��ͼ����ͨ��������󶥵���
//���м��󶥵�������ͨ��ͼ������������Щ��������б�

//ʮ��.ǿ��ͨͼ
//ǿ��ͨͼ��������ͼ�У�����ÿһ�Զ���V�Ͷ���W����V��W�ʹ�W��V����·������Ƹ�����ͼ��ǿ��ͨͼ
//����ͼ�еļ���ǿ��ͨ��ͼ��Ϊ����ͼ��ǿ��ͨ����

//ʮ��.������
//��������ָ����ͼ��ȫ������ļ�С��ͨ����
//ע�⣺�������ж���n,��ֻ�����Թ���һ������n-1����

//ʮ��.�ߵ�Ȩ����
//��һ��ͼ�У�ÿ���߿��Ա�ע��һ������ĳ�ֺ������ֵ������ֵ��Ϊ����ߵ�Ȩֵ
//�������ϴ���Ȩֵ��ͼ��Ҳ��Ϊ��Ȩͼ

//ʮ��.ϡ��ͼ�����ͼ
//��ͼ���У�����ͼ��dense graph����ϡ��ͼ��sparse graph���ĸ����Ǹ���ͼ�бߵ���������ڶ���������ƽ��������ġ�
//����ͼ��ָ�ߵ������ӽ�����������ƽ������ϡ��ͼ����ָ�ߵ�����ԶС�ڶ���������ƽ����

//1.������ͼ G=(V,E) �к���7�����㣬Ҫ��֤ͼG���κ�����¶�����ͨ�ģ�����Ҫ�ı��������ǣ� 16
//˼·��6�����㣬Ҫ��֤�κ�����¶�����ͨ�ģ���Ҫ�ı�������Ƕ��٣���������һ��������һ���߾�����ĿҪ������ٱ���
//��6�������������ȫͼ����+1 ��6*5/2+1=16



//ͼ�Ĵ洢�ṹ
//�ڽӾ���-����

//�ڽӾ���-����

//�ڽӾ���-��Ȩֵ
//�ߴ�Ȩֵ����Ȩֵ��ʾ�������������ʾ��������0��ʾ

//�ڽӱ�-����

//�ڽӱ�-����

//���ڽӱ�

//ʮ�������ú���ķ�������ߵ��£�������ķ�������ߵ���
//����ṹ��data firstin firstout    (firstin:��߱�ͷָ��   firstout:���߱�ͷָ��)
//�߽ṹ�� tailvex headvex headlink taillink 
//ע������ĳ���ָ��Ŀ�궥��aָ����������
//    ��������ָ����������ָ��Ŀ�궥��a

//�ڽӶ��ر� ivex ilink jvex jlink   ��һ���ߵĽṹ��
//ivex��jvex��ĳһ�������ӵ�����������±�
//ilinkָͬ���Ӷ���ivex����һ����
//jlinkָͬ���Ӷ���jvex����һ����





//������ȱ���   ��������ǰ�����
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

int visited[MAXSIZE];//�Ѿ���ȡ���Ķ���Ϊ1��δ��ȡΪ0

void creat_grph(Mat_Grph* G)//�ڽӾ���
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

void dfs(Mat_Grph* G, int i)//i��ʾ�����±�
{
	visited[i] = 1;//�ѷ���
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

	dfs(&G, 0);//0��ʾ��һ������a�������±�

	return 0;
}


//������ȱ���   �������Ĳ������
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

void bfs(Mat_Grph* G, int i = 0)//����ͼG�Ͷ���a���±�
{
	int queue[MAXSIZE];
	int front = 0;
	int rear = 0;

	queue[rear] = i;//��һ���������
	rear++;
	visited[i] = 1;
	printf("%c", G->vertex[i]);

	while (rear != front)
	{
		i = queue[front];//����
		front++;

		for (int j = 0; j < G->vertex_num; j++)//�������п��ܵ����ڽڵ�
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


//��С������-����ķ(Prim)  ��ע���㣬һ����һ����ȥ��
//���ͼ�ļ�С��ͨ��ͼ����������С������
#define MAXSIZE 100
#define MAX 0x7fffffff //int�������ֵ��ʾ����
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
				G->arc[i][j] = 0;//�Խ����ϵ�ȨֵΪ0���Ͼ��Լ����Լ����γɲ���һ����
			}
			else
			{
				G->arc[i][j] = MAX;//����ı��ȸ�������
			}
		}
	}

	//��ÿ���߸�Ȩ��ֵ
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
	int i, j, k;//i,j��ѭ��ʱ�õģ�k���ڼ�¼�±�
	int min;//�������̨���ҳ���СȨֵ��
	int weight[MAXSIZE];//��ʾ��ѡ�ߵ�Ȩֵ
	int vex_index[MAXSIZE];//ֵ��ʾ�����㣬�±��ʾ�����

	//�ȴӵ�һ�����㿪ʼ
	weight[0] = 0;
	vex_index[0] = 0;

	for (i = 1; i < G->vertex_num; i++)//����i=0�����ǰ���Ѿ�˵���ˣ����д˴���1��ʼ
	{
		weight[i] = G->arc[0][i];//�������㵽A��Ȩ��
		vex_index[i] = 0;//���Ǵ�A����
	}

	for (i = 1; i < G->vertex_num; i++)//�ҵ���С�ģ���֮����    ע��˴�i��1��ʼ����Ϊ�����Ѿ������ˣ�ֻ��ѭ��n-1�μ���
	{
		min = MAX;
		j = 0;
		k = 0;
		for (j = 0; j < G->vertex_num; j++)
		{
			if (weight[j] != 0 && weight[j] < min)
			{
				min = weight[j];
				k = j;//��k��¼����Ҫ�����һ��������±�
			}

		}
		//printf("(%d %d)\n", vex_index[k], k);
		printf("(%c %c)\n", G->vertex[vex_index[k]], G->vertex[k]);

		weight[k] = 0;//�ö����Ѿ���ѡ���ˣ���������Ϊ��ѡ��

		//�������ӽ��Ĵ�ѡ·�������º�ѡ��Ȩ��
		for (j = 0; j < G->vertex_num; j++)
		{
			if (weight[j] > G->arc[k][j] && weight[j] != 0)//�����k��������ӵĶ�����±�ֵ�����ù�-1������
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


//��С������-��³˹����(Kruskal)  ��ע�ߣ�������Ȩֵ��С�ı�
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x7fffffff //int�������ֵ��ʾ����
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
				G->arc[i][j] = 0;//�Խ����ϵ�ȨֵΪ0���Ͼ��Լ����Լ����γɲ���һ����
			}
			else
			{
				G->arc[i][j] = MAX;//����ı��ȸ�������
			}
		}
	}

	//��ÿ���߸�Ȩ��ֵ
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
	while (parent[index] > 0)//����parent��������ֵʱ������ͬһ������һ�����㡰����һ�¡����������߼��ϵĳɻ����γ�һ������
	{
		index = parent[index];
	}
	return index;
}

void Kruskal(Mat_Grph* G)
{
	Edge edges[MAXEDGE];//����ÿ����ͷ��β��Ȩֵ
	int k = 0;//�䵱�����±�,����k��ֵΪ�������Ԫ��
	//���ݴ���������ͼȥ����edges����
	for (int i = 0; i < G->vertex_num; i++)//j��i+1��ʼ����ֹȡ���Խ���
	{
		for (int j = i + 1; j < G->vertex_num; j++)
		{
			edges[k].begin = i;
			edges[k].end = j;
			edges[k].weight = G->arc[i][j];
			k++;
		}

	}

	my_BubbleSort(edges, k);//�Ա߽�������

	int parent[MAXSIZE];//������Prim�㷨�е�vex_index,�����е�ֵ��ʾһ�����㣬�����±��ʾ��֮��������һ������
	for (int i = 0; i < G->vertex_num; i++)
	{
		parent[i] = 0;
	}

	int n, m;//���ڱ�ʾ����
	for (int i = 0; i < G->edge_num; i++)//15���ߣ�ѭ��15��
	{
		n = find(parent, edges[i].begin);
		m = find(parent, edges[i].end);
		if (n != m)//�ҵ������������ͨ��·�ﵽ��ת������γɻ�·�˾ͻ�ת��ԭ�أ�n = m�����ɻ���n!=m�����
		{
			parent[n] = m;//���µĽ�����뵽parent������
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


//�ܽ᣺��С������
//��С�������Ķ�����n�����e֮��Ĺ�ϵ��n = e + 1
//��³˹�����㷨��Աߣ�������ʱЧ�ʱȽϸߣ���ϡ��ͼ������
//����ķ�㷨���ڱ�����������Ч�ʻ��һЩ
//��³˹�����㷨��ʱ�临�Ӷ�ΪO(eloge),e�Ǳ���
//����ķ�㷨��ʱ�临�Ӷ�ΪO(n^2),n�Ƕ���





//���·��-�Ͻ�˹����(Dijkstra)
//���㷨���������·�������·���������ڲ��ϵ�ȥ�۲�ÿһ������
//Ȼ��ȥ�ҳ�ʼ���㵽ÿһ��������̵�Ȩֵ�Ƕ���
//ͬʱҲ�ҵ�����ÿһ�������������һ��������˭
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000//�����㷨�漰��MAX�ļӼ����ʲ�����Ϊint�������ֵ

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
		G->vertex[i] = i;//���������ִ���ÿ������
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

int choose(int* found, int* distance, Mat_Graph* G)//��������������ǣ���δ���ʵĶ����У�ѡ��ǰ�����������Ķ��㡣
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
	int found[MAXSIZE];//��¼�����Ƿ��Ѿ��߹�
	int	path[MAXSIZE];//���ڼ�¼�������������·��������ֵ���ֵ��Ӧ���±�ֱ��ʾ�������㡣���磺path[0]=1,��ʾ����V0������������ΪV1
	int distance[MAXSIZE];//���ڼ�¼��ʼ����begin����ÿһ���������̾���,�����±��ʾ����

	for (int i = 0; i < G->vertex_num; i++)
	{
		found[i] = 0;
		path[i] = -1;//������-1��ʾ��ʼ����
		distance[i] = G->arc[begin][i];//�Ȱ����ʼ����ֱ�������ıߵľ��루ÿ���ߵ�Ȩֵ������������
	}
	found[begin] = 1;
	distance[begin] = 0;

	int next;//���ڼ�¼��һ��Ҫ�۲�Ķ���
	for (int i = 0; i < G->vertex_num; i++)//ѭ�����ҳ����н�����Ҫ�۲�Ķ��㣬�����к�������
	{
		next = choose(found, distance, G);//�ҵ�Ҫ�۲�Ķ���
		if (next == -1)
			break; // ���û�пɴﶥ�㣬��ǰ����
		found[next] = 1;//��Ҫ�۲�����������Ϊ"�ѹ۲�"

		for (int j = 0; j < G->vertex_num; j++)//���� Ҫ�۲�Ķ��� �Ƿ�������ŵ�·��
		{
			// �������������Ŀ�궥��j�Ƿ�δ���ʣ�����ͨ��next����j��·������
			if (found[j] == 0 && G->arc[next][j] != MAX && distance[next] + G->arc[next][j] < distance[j])
			{
				distance[j] = distance[next] + G->arc[next][j];
				path[j] = next;
			}
			//G->arc[next][j] != MAX ���壺����next�Ͷ���j֮�����ֱ�ӱߣ�������������ã�ȷ��������������ͨ��
			//��ֹ�ظ���������1��ȷ��·�����ڣ�����2����֤�����ԣ�����3��
		}
	}

	// ��ӡ���
	for (int i = 0; i < G->vertex_num; i++)// ��ÿ������i����������begin��i�����·����Ϣ
	{
		printf("V%d -> V%d : ", begin, i);
		if (distance[i] == MAX)
		{
			printf("Unreachable\n");
		}
		else
		{
			printf("%d\n", distance[i]);

			// ��ӡ·��
			if (i != begin)
			{
				printf("Path: V%d", i);
				int j = i;
				while (path[j] != -1)//-1�����
				{
					printf(" <- V%d", path[j]);
					j = path[j];
				}
				printf(" <- V%d\n", begin);
			}
			else//��i == beginʱ����㵽������ֱ�������㣬����Ҫ���ݡ�
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



//���·��-��������(Floyd)
//���ģ����ν�ͼ�е�ÿ��������Ϊ���м�㡱ȥ������
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000//�����㷨�漰��MAX�ļӼ����ʲ�����Ϊint�������ֵ

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
		G->vertex[i] = i;//���������ִ���ÿ������
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
	int path[MAXSIZE][MAXSIZE];//��������������֮������·����ע�⣺�����е�ֵ����Ķ������յ��ǰ���㣨�յ�ǰ���Ǹ��㣩,��ά���������±��ʾ��һ�����㵽��һ������
	//path[i][j],i��ʾ��㣬j��ʾ�յ㣬�����д��ֵ��ʾ����㵽�յ�Ҫ������ǰ��
	int distance[MAXSIZE][MAXSIZE];//��������������֮������·������

	//��ʼ����D(-1)��Path(-1)
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			distance[i][j] = G->arc[i][j];
			path[i][j] = j;//
		}
	}

	// j:��ʼ���㡡i:��ת���㡡k:��ֹ����
	for (int j = 0; j < G->vertex_num; j++)
	{
		for (int i = 0; i < G->vertex_num; i++)
		{
			for (int k = 0; k < G->vertex_num; k++)
			{
				if (distance[j][k] > distance[j][i] + distance[i][k])//����distance������path
				{
					distance[j][k] = distance[j][i] + distance[i][k];
					path[j][k] = path[j][i];
				}

			}
		}
	}

	int t;// ��ʱ����������׷��·��
	for (int i = 0; i < G->vertex_num; i++) // ����������ʼ����
	{
		for (int j = i + 1; j < G->vertex_num; j++) // ����������ֹ���㣨j>i�������ظ�����Գ�·����
		{
			printf("V%d->V%d weight:%d ", i, j, distance[i][j]);// �������i��j����̾���
			t = path[i][j]; // ��ȡ·���еĵ�һ���м䶥��
			printf("path:V%d", i);// �����ʼ����

			while (t != j)// �ؼ�������·��׷�٣�ֱ�������յ�j
			{
				printf("->V%d", t);// ���·���еĶ���
				t = path[t][j];// �ƶ���·���е���һ������
			}
			printf("->V%d\n", j); // ����յ�
		}
		printf("\n");// ÿ����ʼ������������
	}
}
//�����Ҫϸ�ڣ�
//ѭ������ j = i + 1��
//��Ϊ������ͼ��distance[i][j] = distance[j][i]
//ֻ��� i < j ������������ظ�����ԳƵ�·����
//
//	·��׷���߼���
//	t = path[i][j] �õ���i�����ĵ�һ������
//	t = path[t][j] ����·��һ����ǰ��
//	�� t == j ʱ˵�������յ�
//
//	�����ʽ��
//	��������룺"V0->V1 weight:5 "
//	���������·����"path:V0->V1->V2"
int main()
{
	Mat_Graph* G = new(Mat_Graph);
	createGrph(G);
	floyd(G);
	delete G;

	return 0;
}




//С�᣺
//��С��������ָ��һ����Ȩ��ͨͼ�У�����ͼ�����ж����ұߵ�Ȩֵ֮����С������
//����ע�����������С�ĳɱ�����ͼ�����еĶ��㡣��С���������㷨����Kruskal�㷨��Prim�㷨��
//�������㷨����ͨ��̰�Ĳ�����ȷ��ÿ����ӵ����еı߶��ǵ�ǰ��ѡ����Ȩֵ��С�ģ��Ӷ���֤�������ɵ�������Ȩֵ��С��
//
//���·������ָ�ڼ�Ȩͼ�У���һ�����㵽��һ�������·���У��ߵ�Ȩֵ֮����С��·����
//����ע������ͼ���ҵ������ض�����֮�����õ�·����
//���õ����·���㷨��Dijkstra�㷨��Floyd�㷨��Dijkstra�㷨�����ڵ�Դ���·�����⣬����һ�����������ͼ������������������·����
//��Floyd�㷨�������������������·�����⡣
//
//���ߵ���Ҫ�������ڣ�
//
//��С��������Ŀ��������ͼ�����ж��㣬ʹ�����ж��㶼����ͨ�����γɵ����ıߵ���Ȩֵ��С��
//������֤��������֮���·������̵ģ����Ǳ�֤����ͼ��ȫ�����š�
//
//���·����Ŀ�����ҵ���һ�����㵽��һ����������·������ֻ�����ض����������Ž⣬������������ͼ����ͨ�ԡ�
//
//��ʵ��Ӧ���У����������Ҫ���������е����нڵ㣬�������ͨ������Ľ��裬ͨ����ʹ����С�������㷨��
//���������Ҫ�ҵ���������֮��������ʻ·�ߣ���ô�ͻ�ʹ�����·���㷨��






//��������        ע�⣺�˴���һ���ڽӾ���ת��Ϊ�ڽӱ�
//��һ����ʾ���̵�����ͼ�У��ö����ʾ����û���ʾ�֮������ȼ�������������ͼΪ�����ʾ����������ǳ�ΪAOV��
//����˼�룺����Ѱ�����Ϊ0�Ķ��㣬Ȼ����ջ����ջ
//���������˳����ǳ�ջ��˳�򣬵�������ඥ�����ȼ���ȣ�����δ��ֻ��Ψһ��һ��˳��
#include <iostream>
using namespace std;
typedef int VertextType;
typedef int EdgeType;
#define MAXSIZE 100

typedef struct Mat_Graph//�ڽӾ���
{
	VertextType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

typedef struct EdgeNode
{
	int edge_vex;//Ŀ�궥����±�
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertextNode
{
	int in;//���������Ǽ�
	VertextType data;
	EdgeNode* next;
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];//adjacency�����ڽӣ�ע�������֪ʶ��
//���д������˼�ǣ�����һ��������Adj_List������һ������MAXSIZE��VertextNodeԪ�ص��������͡�
//Adj_List graph;  �ȼ��� VertexNode graph[MAXSIZE];

typedef struct Adj_Graph//�ڽӱ�
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
}Adj_Graph;

typedef Adj_Graph* Adj_List_Graph;

void createGraph(Mat_Graph* G)//�����ڽӾ���
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
	//�ڽӾ����У�i��ʾ��ʼ���㣬j��ʾ��ֹ����
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

	for (int i = 0; i < G->vertex_num; i++)//���ڽӱ�򵥴���
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

				//�������ͷ�巨:
				e->next = (*ALG)->adj_list[i].next;
				(*ALG)->adj_list[i].next = e;
				//i ��ʾ�ߵ���㣨Դ���㣩
				//���д��뽫�´����ı߽ڵ� e ���뵽���� i ���ڽ�������

				(*ALG)->adj_list[j].in++;
				//j ��ʾ�ߵ��յ㣨Ŀ�궥�㣩
				//���д������Ӷ��� j ����ȣ�in - degree��
				//��ʾ"���� j �������������1"
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
		printf("����\n");
		return;
	}
	top++;
	stack[top] = e;
}

int pop()
{
	if (top == -1)
	{
		printf("�յ�\n");
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

void topological_sort(Adj_List_Graph ALG)//������������
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






//�ؼ�·�����·��
//��һ����ʾ���̵Ĵ�Ȩ����ͼ�У��ö����ʾ�¼���������߱�ʾ����ñ��ϵ�Ȩֵ��ʾ��ĳ���ʱ��
//��������ͼ�ı߱�ʾ����������ǳ�ΪAOE

//etv:�¼����緢����ʱ��(earliest time of vertex)��ȡ���ֵȷ����һ�¼��ܹ�����
//ltv:�¼���������ʱ��(lastest time of vertex)��ȡ��Сֵȷ����һ�¼��ܹ�����

//AOE�������ʣ�
//ֻ���ڽ���ĳ����Ļ���Ѿ��������ö�����������¼��ŷ�����
//ֻ����ĳ������������¼������󣬴Ӹö�������ĸ���ſ�ʼ��

//���緢��ʱ���������ʱ����ͬ�Ķ���֮�������߾��ǹؼ�·��

//�ؼ�·���ϵ����л���ǹؼ���� ���Ǿ����������̵Ĺؼ����أ���˿���ͨ���ӿ�ؼ���������������ڡ�����Ҳ�����������̣���Ϊһ�����̵�һ���ĳ̶ȣ��ùؼ���Ϳ��ܱ�ɷǹؼ����
//���еĹؼ�·����Ψһ�������кü����ؼ�·��������ֻ�ӿ�����ĳһ���ؼ�·���ϵĻ���������̹��ڡ�ֻ�мӿ���������йؼ�·���ϵĹؼ�����ܴﵽ���̹��ڵ�Ŀ�ġ�

#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAX 0x7fffffff
typedef int VertextType;
typedef int EdgeType;

typedef struct Mat_Graph//�ڽӾ���
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

typedef struct Adj_Graph//�ڽӱ�
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
	int stack1[MAXSIZE];//��������˳�����������������������緢��ʱ��
	int stack2[MAXSIZE];//���ŵ�˳����������������ʱ��
	//������ʱ���ǴӺ���ǰ��ģ������������Ǵ�ǰ�����
	//ÿһ�����������ջ��ѹ����һ��ջ
	//�����һ��ջ�е����ݰ�����ջ���ﵽ�����Ч��
	int etv[MAXSIZE];//���緢��ʱ��    etv[i] ��ʾ�¼�i�����緢��ʱ�䣬iͨ�������������еĶ������
	int ltv[MAXSIZE];//������ʱ��
	int curr = 0;//�����ջ������
	int k = 0;//k�����±���

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
			k = e->edge_vex;//k���ɵ�ǰ�¼�currͨ����eָ�����һ���¼�
			ALG->adj_list[k].in--;
			if (ALG->adj_list[k].in == 0)
			{
				stack1[++top1] = k;
			}

			if (etv[curr] + e->weight > etv[k])//curr���緢��ʱ��+ͨ����eָ�����һ���¼�(����)k��ʱ�䣬�� �¼�(����)k�����緢��ʱ��Ƚ�
			{
				etv[k] = etv[curr] + e->weight;
				//etv[curr]���¼�curr�����緢��ʱ��
				//e->weight����curr��k�Ļ�ĳ���ʱ�䣨Ȩ�أ�
				//etv[k]���¼�k�����緢��ʱ��
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

