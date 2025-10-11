#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//树
//树是一个或多个结点的有限集合
//存在一个称为根的特定结点
//其余的结点被分为n个互不相交的集合T1,T2,...,Tn，其中的每个集合都是一棵树。
//T1,T2,...Tn称为根结点的子树

//基础概念
//结点：树中的一个独立单元
//结点的度：结点拥有的子树数称为结点的度
//树的度：树内各结点度的最大值
//叶子：度为0的结点或终端结点
//非终端结点：度不为0的结点
//双亲和孩子：结点的子树的根称为该结点的孩子，相应地，该结点称为孩子的双亲
//层次：结点的层次从根开始定义，根为第一层，根的孩子为第二层，以此类推
//树的深度：树的深度是指从根节点到叶节点的最长路径的长度

//树的基本性质
//性质一：树中所有结点数 等于 所有结点的度数之和加1  （有几条边度数就是几）

//性质二：对于度为m的树，第i层上最多有 m^(i-1)个结点

//性质三：对于高度为h，度为m的树，最多有(m^h - 1)/(m - 1)个结点







//二叉树
//二叉树(Binary Tree)是 n(n>=0) 个结点所构成的集合，它或为空树(n=0)，或为非空树。
// 
//对于非空树T:
//(1)有且仅有一个称为根的结点
//(2)除根结点以外的其余结点分为两个互不相交的子集T1和T2，分别称为T的左子树和右子树，且T1和T2本身又都是二叉树
//(3)二叉树每个结点至多只有两棵子树
//(4)二叉树的子树有左右之分，其次序不能任意颠倒

//二叉树的性质 (性质一至性质三常用)
//性质一：二叉树的第i层最多有2^(i-1) (i>=1)个结点

//性质二：深度为k的二叉树最多有 2^k - 1 (k>=1) 个结点

//性质三：对于任何非空的二叉树T，如果叶子结点的个数为N0,而度为2的结点数为N2,则：N0 = N2 + 1
//二叉树中，有： N = N0 + N1 + N2

//性质四：具有n个结点的完全二叉树的深度为 log2(n) + 1 （向下取整）

//性质五：如果对一棵有n个结点的完全二叉树(其深度为log2(n) + 1 (向下取整))的结点按层序编号(从第1层到第log2(n) + 1 (向下取整)，每层左至右)，则对任一结点(1<=i<=n),以下结论成立：
//(1)如果i=1,则结点i是二叉树的根，无双亲；如果结点i>1则其双亲是结点i/2(向下取整)
//(2)如果2i>n,则结点i无左孩子（结点i为叶子结点）；否则其左孩子是结点2i
//(3)如果2i+1>n,则结点i无右孩子；否则其右孩子的结点是2i+1

//特殊二叉树
//特殊二叉树-满二叉树
//满二叉树：深度为k且含有 2^k - 1 个结点的二叉树
//(1)所有的叶子结点只能出现在最后一层
//(2)对于同样深度的二叉树，满二叉树的结点个数最多，叶子结点的数量也是最多的
//(3)如果对满二叉树进行编号，根结点从1开始，从上到下从左到右进行，对于编号为i的结点，若存在左孩子，则左孩子的编号为2i，右孩子编号为2i+1

//特殊二叉树-完全二叉树
//完全二叉树：深度为k的、有n个结点的二叉树，当且仅当其每一个结点都与深度为k的满二叉树中编号从1至n的结点一一对应时，称之为完全二叉树
//(1)叶子结点只可能在层次最大的两层上出现（倒数第一层和倒数第二层）
//(2)对任一结点，若其右分支下的子孙的最大层次为L,则其左分支下的子孙的最大层次必为L或L+1
//总结：没有完整的左子树，就不能有右子树；上一层没有铺满，就不能有下一层
//核心思想：从左至右、从上到下、依次铺排

//满二叉树属于完全二叉树的一种
//一个满二叉树一定是奇数个结点（最开始的根结点）；所有，当完全二叉树共有偶数个结点时，说明有一个度为1的结点




//二叉树的存储结构-顺序结构
//除了满二叉树和完全二叉树外，其他场景比较浪费空间

//二叉树的存储结构-链式结构
typedef char ElemType;
typedef struct TreeNode
{
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;
typedef TreeNode* BiTree;//注意

char str[] = "ABDH#K###E##CFI###G#J##";
int index = 0;

void creatTree(BiTree* T)//按照前序遍历创造树
{
	ElemType ch = str[index++];//先使用，后++
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		creatTree(&(*T)->lchild);//&(*T)->lchild不明白的兄弟，可以去看一下C语言的运算符优先级顺序，这个公式会先计算(*T)解引用，再运算  -> 指向结构体成员，再运算&取地址。
		//相当于 ( & ( (*T)->lchild ) )
		creatTree(&(*T)->rchild);
	}
}


//二叉树的遍历-前序遍历   根左右
//先访问根节点，然后访问左分支上遇到的每一个结点，持续这一过程，直到遇到空结点为止
//这时，返回到最近的有右孩子的祖先结点，并从该结点的右孩子开始继续遍历
void preOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//二叉树的遍历-中序遍历   左根右
//先访问根结点，向树的左下方移动，直到遇到空结点为止，然后访问空结点的父结点
//接着继续遍历该结点的右子树，如果右子树没有子树可以遍历，那么继续遍历上一层最后一个未被访问的结点
void inOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	inOrder(T->lchild);
	printf("%c", T->data);
	inOrder(T->rchild);
}

//二叉树的遍历-后序遍历   左右根
//从根结点开始先访问结点的左右儿子，再对该结点进行访问
//这就意味着结点的儿子将在该结点之前输出
void postOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c", T->data);
}



//二叉树遍历性质
//已知前序遍历和中序遍历，可以唯一确定一颗二叉树
//已知中序遍历和后序遍历，可以唯一确定一颗二叉树
//已知前序遍历和后序遍历，是不能确定一颗二叉树的


//采用顺序结构保存二叉树，是按照满二叉树的方式存储
//eg:对于任意一棵高度为5且有10个结点的二叉树，若采用顺序存储结构保存，每个结点占1个存储单元（仅存放结点的数据信息）
//则存放该二叉树需要的存储单元至少是：31个 ---> 2^k - 1


//迭代法遍历二叉树（非递归）


//二叉树前序遍历
//1.根结点入栈
//2.栈顶结点出栈，打印输出当前栈顶结点
//3.把刚出栈的结点的右孩子、左孩子入栈
//
//重复2-3步直到栈空
//总结：从根结点开始：入栈，出栈并输出，再把右孩子、左孩子依次入栈，出栈并输出
#include <iostream>
using namespace std;
typedef char ElemType;

typedef struct TreeNode
{
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

typedef struct Stack
{
	BiTree data;
	Stack* next;
}Stack;

Stack* initStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = NULL;
	s->next = NULL;
	return s;
}

void push(Stack* s, BiTree e)
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

BiTree pop(Stack* s)
{
	if (s->next == NULL)
		return NULL;
	Stack* q = s->next;
	BiTree e = q->data;
	s->next = q->next;
	free(q);
	return e;
}

int isEmpty(Stack* s)
{
	return s->next == NULL;  // 返回1表示空，返回0表示非空
}
//解释：
//•	当 s->next == NULL 时，返回值为 1（true），表示栈空
//•	当 s->next != NULL 时，返回值为 0（false），表示栈非空

char str[] = "ABDH#K###E##CFI###G#J##";//前序
int index = 0;

void creatTree(BiTree* T)//按照前序创建树
{
	char ch = str[index++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		creatTree(&(*T)->lchild);
		creatTree(&(*T)->rchild);
	}
}

// 前序遍历（根-左-右）
void preOrderOperate(Stack* s, BiTree T)
{
	if (T == NULL)
		return;

	push(s, T);  // 先将根节点入栈
	while (!isEmpty(s))  // 当栈不为空时
	{
		BiTree curr = pop(s);  // 弹出当前节点
		printf("%c ", curr->data);  // 访问当前节点

		// 由于栈是后进先出，为了保证左子树先于右子树遍历
		// 需要先压入右子树，再压入左子树
		if (curr->rchild != NULL)
			push(s, curr->rchild);
		if (curr->lchild != NULL)
			push(s, curr->lchild);
	}
}



//线索二叉树
//通过遍历可以得到二叉树的线性排列
//但这样的线性序列只有在遍历时才能得到
//将二叉树线索化得到线索二叉树可以解决这个问题
//线索化：利用叶结点的空余空间记录前驱、后继
//注：一定要先选择一种遍历顺序，再进行线性排列
//右孩子为空值的结点，用来记录后继
//左孩子为空值的结点，用来记录前驱

//线索二叉树-存储结构
typedef char ElemType;
typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	int ltag;//ltag为0时，指向该结点左孩子；为1时，指向该结点的前驱
	int rtag;//rtag为0时，指向该结点右孩子；为1时，指向该结点的后继
}ThreadNode;
typedef ThreadNode* ThreadTree;


//注意：
//0.创建一棵树
//1.确定遍历顺序，把这棵树线索化
// 
//2.头结点的lchild指向二叉树的根    （自己创造一个头结点）
//3.头结点的rchild指向遍历的最后一个结点
//4.第一个结点的lchild指向头结点
//5.最后一个结点的rchild指向头结点
// 
//6.最终用一个普通的循环语句遍历线索二叉树


//线索二叉树-中序遍历线索化
typedef char ElemType;

typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	int ltag;//ltag为0时，指向该结点左孩子；为1时，指向该结点的前驱
	int rtag;//rtag为0时，指向该结点右孩子；为1时，指向该结点的后继
}ThreadNode;

typedef ThreadNode* ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";//前序遍历：#代表空
int index = 0;

ThreadTree prev = NULL;//记录每一次线索化的过程中上一个访问的结点
// 确保全局变量 prev 被正确初始化

//造树--按照前序遍历创造，因为给的字符串就是按照前序遍历给的
void creatTree(ThreadTree* T)//二级指针
{
	char ch = str[index++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (ThreadTree)malloc(sizeof(ThreadNode));

		(*T)->data = ch;

		creatTree(&(*T)->lchild);
		if ((*T)->lchild != NULL)
		{
			(*T)->ltag = 0;
		}

		creatTree(&(*T)->rchild);
		if ((*T)->rchild != NULL)
		{
			(*T)->rtag = 0;
		}
	}
}

void threading(ThreadTree T);//声明

//开始线索化
void inOrderThreading(ThreadTree T,ThreadTree* head)
{
	//头结点
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	(*head)->rchild = (*head);//这里本应指向最后一个结点，但这里还没正式线索化，只能委屈一下指向它自己；并防止在正式初始化时prev->lchild为空导致错误

	if (T == NULL)//传来了一个空树
	{
		(*head)->lchild = *head;
	}
	else//正常情况
	{
		(*head)->lchild = T;
		::prev = (*head);
		//•	prev：可能指向局部或全局变量，容易产生歧义。
		//• ::prev：只指向全局变量，编译器不会再混淆。

		threading(T);//正式线索化

		//最后一个结点线索化，这里的prev指的是最后一个访问的结点
		::prev->rchild = *head;
		::prev->rtag = 1;

		//头结点右孩子指向最后一个结点
		(*head)->rchild = ::prev;
	}

}

//正式线索化-按照中序遍历来去做这个线索化-中序线索化
void threading(ThreadTree T)
{
	if (T != NULL)
	{
		threading(T->lchild);
		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = ::prev;
		}
		if (::prev->rchild == NULL)
		{
			::prev->rtag = 1;
			::prev->rchild = T;
		}
		::prev = T;
		threading(T->rchild);
	}

}
//由于左孩子需要指向前面的指针，所以用 现在 = 过去（时间往前走）
//由于右孩子需要指向后面的指针，所以用 过去=现在（时间往后走）
//毕竟不可能知道未来

//注：函数的先后顺序并不影响，有需要时声明即可；主要是在主函数内的顺序决定哪个函数先被执行
//所以，prev最开始就是指向头结点head

void inOrder(ThreadTree T)
{
	ThreadTree curr = T->lchild;//curr指向根结点
	while (curr != T)//curr不指向头结点
	{
		while (curr->ltag == 0)//找到中序遍历时的第一个结点
		{
			curr = curr->lchild;
		}
		printf("%c", curr->data);
		while (curr->rtag == 1 && curr->rchild != T)//注意这里是等于1,指 通过线索 找 线索化后的下一个结点
		{
			curr = curr->rchild;
			printf("%c", curr->data);
		}
		//转向右子树
		curr = curr->rchild;//类似于node=node->next
	}
	printf("\n");
}

int main()
{
	ThreadTree head;
	ThreadTree T;
	//创建
	creatTree(&T);
	//线索化
	inOrderThreading(T,&head);
	//基于线索遍历
	inOrder(head);

	return 0;
}





//哈夫曼树
//基本概念
//路径：从树中一个结点到另一个结点之间的分支构成这两个结点之间的路径 （画出的二叉树中两个圈之间那条线段）
//路径长度：路径上的分支数目 （一个结点到另一个结点 经历了几条线）
//树的路径长度：从树根到每一个结点的路径长度之和
//结点的权：在实际应用中，给树中的结点赋予代表某种含义的数值   （权重）
//结点的带权路径长度：从该结点到树根之间的路径长度与该结点权的乘积
//树的带权路径长度(WPL)：树中所有叶子结点的带权路径长度之和

//树的带权路径长度越少，二叉树的效率越高

//定义
//带权路径长度（WPL）最小的二叉树称为哈夫曼树

//构造哈夫曼树（同一层一定是小的在左边）
//1.先把有权值的叶子结点按照从小到大的顺序排列成一个有序序列
//2.取两个最小权值的结点作为一个新结点N1的子结点
//3.将结点N1替换刚刚取出的两个结点，并加入到有序序列中（依旧从小到大加入），其中N1的权值为两个结点权值之和
//4.重复步骤2，取两个最小权值的结点作为一个新结点N2的子结点
//5.重复步骤3，将结点N2替换刚刚取出的两个结点，并加入到有序序列中
//6.重复步骤2、3，直到有序序列中只剩下一个新结点Nn


//哈夫曼编码
//步骤：
//1.先画出哈夫曼树
//2.画完树，给每个结点左边分叉（左路径）放0，右边分叉（右路径）放1
//3.叶子结点编码为 从根结点到叶子结点的路径上的01排列

//前缀编码：任意一个编码都不是其他编码的前缀就叫做前缀编码 （老婆饼里没有老婆）
//eg: 110和1100就不是前缀编码，因为110可以充当1100前缀


//例题：对n个互不相同的符号进行哈夫曼编码，若生成的哈夫曼树共有115个结点，则n的值为：  58
//法一：
//1.哈夫曼树相比于普通的二叉树特殊点是哈夫曼树的结点的度只有0和2没有1，2度结点数加0度结点数等于总结点数
//2.又因为没有1度结点而且0度结点的度为0，所以整个哈夫曼树的度数只由2度结点组成，等于2度结点数乘以2（因为一个2度结点有两个度）  （注意这里的思路）
//3.总度数又等于结点数减一，所以总度数为115-1=114，除以2得2度结点数57，那么0度结点数（叶子节点数）为115-57=58，n即为58
//法二：
//1.因为哈夫曼树没有度为1的结点，所以N1 = 0
//2.N1+N2+N0=N 且 N0=N2+1 , N=115
//3.2*N2+1=115,N2=57
//4.所以度为0的结点，即符号所在的结点为115-57=58





//树与二叉树的转换
//A.树转化为二叉树
//1.加线，在所有兄弟结点之间加一条线
//2.去线，对树中的每一个结点，只保留它与第一个孩子结点的连线，删除它与其它孩子结点之间的连线
//3.层次调整，以树的根结点为轴心，将整棵树顺时针旋转一定角度，使之层次分明
//注意：第一个孩子是二叉树结点的左孩子；兄弟转过来的孩子是结点的右孩子

//B.二叉树转化为树
//1.加线，若某个结点的左孩子存在，则将这个左孩子的所有右孩子结点都作为此结点的孩子，将该结点与这些右孩子结点用线连起来
//2.去线，删除二叉树中所有结点与其右孩子结点的连线
//3.调整，转一下




//森林与二叉树的转换
//A.森林转化为二叉树
//1.将森林中每一棵树转化为二叉树
//2.第一棵二叉树不动，从第二棵树开始，依次把后一棵二叉树的根结点作为前一棵二叉树的根结点的右孩子，然后用线连起来

//B.二叉树转化为森林
//1.抹掉二叉树根结点右链上的所有结点之间的“双亲—右孩子”关系
//2.拆开
//3.二叉树转换成树
//注：直接按照步骤将二叉树还原为森林即可，即使还原的结果只有一棵树


//树的遍历：先根遍历、后根遍历
//Q:为什么没有二叉树中的中序遍历？
//A:中序遍历左子树，访问根结点，中序遍历右结点。
//  而在普通树中并不一定只有左右两颗子树

//注：树的先根遍历和转化的二叉树的前序遍历一致
//    树的后根遍历和转化的二叉树的中序遍历一致



//森林的遍历：前序遍历、中序遍历
//森林的中序遍历其实是对森林的每棵树进行后序遍历 （就这个遍历特殊）

//遍历的对应关系：
//  树         森林       二叉树
//先根遍历   前序遍历    前序遍历
//后根遍历   中序遍历    中序遍历


//1.已知一棵有2011个结点的树，其叶结点个数为116，该树对应的二叉树中无右孩子的结点个数是：1896
//思路：画出一棵特殊的树：让叶结点全在同一层，然后转化为二叉树

//2.将森林F转换为对应的二叉树T,F中叶结点的个数等于：T中左孩子指针为空的结点个数
//思路：动手画个森林（两棵树也是森林），在转化为二叉树，一个一个按选项对比即可

//3.若森林F有15条边、25个结点，则F包含树的个数是：
//思路：随便画森林观察森林中每棵树边数与结点数的关系 --> 结点数比边数大1   ，所以：森林中 边数+数的个数=结点数






//层序遍历
#include<iostream>
#include<cstdlib>//malloc
#include<cstdio>//printf
using namespace std;
typedef char TreeType;
typedef struct TreeNode
{
	TreeType data;
	TreeNode* lchild;
	TreeNode* rchild;
};

typedef TreeNode* BiTree;

typedef struct QueueNode
{
	TreeNode* data;
	QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

Queue* initQueue()
{
	QueueNode* head = (QueueNode*)malloc(sizeof(QueueNode));
	Queue* q = (Queue*)malloc(sizeof(Queue));
	head->data = NULL;
	head->next = NULL;

	q->front = head;
	q->rear = head;
	return q;
}

int isEmpty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	return 0;
}

void equeue(Queue* q, TreeNode* e)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;
	q->rear->next = node;
	q->rear = node;

}

void dequeue(Queue* q, BiTree* e)
{
	// 先检查队列是否为空，避免对 NULL 解引用
	if (isEmpty(q))
	{
		*e = NULL;
		return;
	}

	QueueNode* tmp = q->front->next; // 原第一个节点（要删除的结点）
	*e = tmp->data;
	q->front->next = tmp->next;
	if (tmp == q->rear)
	{
		q->rear = q->front;
	}
	free(tmp);
}

int queueSize(Queue* q)
{
	int size = 0;
	QueueNode* tmp = q->front->next; // 从第一个有效节点开始
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
}

char str[] = "ABDH##I##EJ###CF##G##";//前序遍历：#代表空
int index = 0;

void creatTree(BiTree* T)
{
	TreeType ch = str[index++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		creatTree(&(*T)->lchild);
		creatTree(&(*T)->rchild);
	}

}

int maxDepth(Queue* q, TreeNode* T)
{
	if (T == NULL)
	{
		return 0;
	}
	equeue(q, T);
	int depth = 0;
	while (!isEmpty(q))
	{
		int count = queueSize(q);
		while (count > 0)
		{
			TreeNode* curr = NULL;
			dequeue(q, &curr);
			if (curr != NULL)
			{
				if (curr->lchild != NULL)
				{
					equeue(q, curr->lchild);
				}
				if (curr->rchild != NULL)
				{
					equeue(q, curr->rchild);
				}
			}
			count--;
		}
		depth++;
	}

	return depth;
}

int main()
{
	Queue* q = initQueue();

	TreeNode* T;
	creatTree(&T);

	int ret = maxDepth(q, T);
	printf("%d\n", ret);

	return 0;
}




//1.[2014] 给定一棵二叉树T,采用二叉链表存储，请设计求T的WPL的算法
//思路：1.判断是否为叶子结点   2.确定叶子结点所在层数
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
using namespace std;
#define MAXSIZE 1000

typedef int ElemType;

typedef struct TreeNode
{
	ElemType weight;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

int weight[] = { 100, 42, 15, -1, -1, 27, -1, -1, 58, 28, 13, 5, -1, -1, 8, -1, -1, 15, -1, -1, 30, -1, -1 };
int index = 0;

void creatTree(BiTree* T)
{
	int tmp = weight[index++];
	if (tmp == -1)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->weight = tmp;
		creatTree(&(*T)->lchild);
		creatTree(&(*T)->rchild);
	}
}

int WPL(BiTree T)
{
	BiTree SeqQueue[MAXSIZE];//创建顺序结构队列
	int front = 0;
	int rear = 0;

	SeqQueue[rear++] = T;//根结点入队
	int depth = 0;
	int value = 0;
	while (front != rear)
	{
		int count = rear - front;
		while (count > 0)
		{
			BiTree curr = NULL;

			curr = SeqQueue[front];
			front++;//出队

			if (curr->lchild != NULL)
			{
				SeqQueue[rear++] = curr->lchild;
			}
			if (curr->rchild != NULL)
			{
				SeqQueue[rear++] = curr->rchild;
			}

			if (curr->lchild == NULL && curr->rchild == NULL)
			{
				value += depth * curr->weight;
			}
			count--;
		}
		depth++;
	}

	return value;
}

int main()
{
	BiTree T;
	creatTree(&T);
	int ret = WPL(T);
	printf("%d\n", ret);

	return 0;
}


//2.[2016] 如果一棵非空k(k>=2)叉树T中每个非叶结点都有k个孩子，则称T为正则k叉树
//        (1)若T有m个非叶结点，则T中的叶结点有多少个？
//        (2)若T的高度为h（单节点的树h=1），则T的结点树最多为多少个？最少为多少个？

//思路：先找特殊值，自己画一画，看看能不能推出普遍规律

//（1）：总结点数 N = N0 + Nk
//       由于树的性质：结点数等于结点的度数+1，且正则k叉树中结点的度数均有非叶节点提供
//       即：N = km + 1
//       联立得：N0 = km - m + 1

//（2）：最多：k^0+k^1+k^2+...+k^(h-1) = (1-k^h)/(1-k);
//       最少：第一层一个，其他每层都3个，共 1+k(h-1) 个

