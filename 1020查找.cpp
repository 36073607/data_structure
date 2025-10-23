#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//ASL（Average Search Length），即平均查找长度
//在查找运算中，由于所费时间在关键字的比较上，所以把平均需要和待查找值比较的关键字次数称为平均查找长度。

//线性表的查找-顺序查找
int search(int* arr, int sz, int value)
{
	for (int i = 0; i < sz; i++)
	{
		if (arr[i] == value)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 15,54,76,6,9,45,12 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int pos = search(arr, sz, 6);
	printf("%d\n", pos);

	return 0;
}


//线性表的查找-折半查找(二分查找)
//注：折半查找的前提是：
//查找表必须是有序的，这一点非常关键。无序的数据使用折半查找是完全没有意义1的
int Binary_search(int* arr, int sz, int value)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > value)
		{
			right = mid--;
		}
		else if (arr[mid] < value)
		{
			left = mid++;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[] = { 2,13,22,38,46,58,66,77,85,98 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int pos = Binary_search(arr, sz, 66);
	printf("%d\n", pos);

	return 0;
}


//二叉排序树(BST)
//二叉排序树是一种特殊的二叉树，它通过巧妙的节点排列方式，实现了“查找效率高、插入删除灵活”的目标，它满足以下特性：
//1.对于树中任意一个节点，其左子树上所有节点的值都小于该节点的值
//2.对于树中任意一个节点，其右子树上所有节点的值都大于该节点的值，且左右子树本身也都是一棵二叉排序树
//注意：构造二叉排序树的目的，并不是为了排序，而是为了提高查找、插入以及删除关键字的速度

//二叉排序树-查找
#include <iostream>
using namespace std;
typedef int TreeType;
typedef struct TreeNode
{
	TreeType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

//-1表示空结点
int treeArr[] = { 70,55,49,30,-1,39,-1,-1,53,-1,-1,-1,80,75,-1,-1,98,95,-1,-1,-1 };//preorder
int index = 0;

void creatTree(BiTree* T)//preorder
{
	TreeType num = treeArr[index++];
	if (num == -1)
	{
		*T = NULL;
	}
	else
	{
		*T = new(TreeNode);
		(*T)->data = num;
		creatTree(&(*T)->lchild);
		creatTree(&(*T)->rchild);
	}
}

void preOrder(BiTree T)//调试用，确保二叉排序树能够正确生成
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//查找二叉排序树中是否包含指定值 value
//参数T:当前子树根结点
//参数value:要查找的值1
//参数parent:当前节点的父结点
//参数pos:指针变量，用于1返回找到的节点
//返回值：1表示找到，0表示未找到
int search_bst(BiTree T, int value, BiTree parent, BiTree* pos)
{
	if (T == NULL)
	{
		*pos = parent;//递归到空结点，查找失败，将父结点返回（后面内容可用于插入）
		return 0;
	}

	if (value == T->data)
	{
		*pos = T;//找到目标值
		return 1;
	}
	else if (value > T->data)
	{
		return search_bst(T->rchild, value, T, pos);//要查找的值比当前节点小，往左子树找
	}
	else if (value < T->data)
	{
		return search_bst(T->lchild, value, T, pos);//要查找1的值比当前节点大，往右子树找
	}
	//注意递归时参数parent为T
}

int main()
{
	BiTree T;
	creatTree(&T);

	BiTree Binary_search;
	int found = search_bst(T, 53, NULL, &Binary_search);
	if (found)
	{
		printf("Found: %d\n", Binary_search->data);
	}
	else
	{
		printf("Not found\n");
	}

	preOrder(T);

	return 0;
}


//二叉排序树-插入
#include <iostream>
using namespace std;
typedef int TreeType;
typedef struct TreeNode
{
	TreeType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

void preOrder(BiTree T)//调试用，确保二叉排序树能够正确生成
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//查找二叉排序树中是否包含指定值 value
//参数T:当前子树根结点
//参数value:要查找的值1
//参数parent:当前节点的父结点
//参数pos:指针变量，用于1返回找到的节点
//返回值：1表示找到，0表示未找到
int search_bst(BiTree T, int value, BiTree parent, BiTree* pos)
{
	if (T == NULL)
	{
		*pos = parent;//递归到空结点，查找失败，将父结点返回（后面内容可用于插入）
		return 0;
	}

	if (value == T->data)
	{
		*pos = T;//找到目标值
		return 1;
	}
	else if (value > T->data)
	{
		return search_bst(T->rchild, value, T, pos);//要查找的值比当前节点小，往左子树找
	}
	else if (value < T->data)
	{
		return search_bst(T->lchild, value, T, pos);//要查找1的值比当前节点大，往右子树找
	}

}

void insert_bst(BiTree* T, TreeType value)
{
	BiTree pos = NULL;
	BiTree parent = NULL;
	BiTree curr = NULL;

	int ret = search_bst(*T, value, parent, &pos);

	if (ret == 0)
	{
		curr = new TreeNode;
		curr->data = value;
		curr->lchild = NULL;
		curr->rchild = NULL;

		if (pos == NULL)//二叉排序树为空
		{
			*T = curr;
		}
		else if (pos->data > value)
		{
			pos->lchild = curr;
		}
		else if (pos->data < value)
		{
			pos->rchild = curr;
		}
	}
	else
	{
		return;
	}
}

int main()
{
	BiTree T = NULL;

	int treeArr[] = { 70,55,49,30,39,53,80,75,98,95 };//preorder
	int sz = sizeof(treeArr) / sizeof(treeArr[0]);
	for (int i = 0; i < sz; i++)
	{
		insert_bst(&T, treeArr[i]);
	}

	preOrder(T);//查看当前树结构
	printf("\n");

	insert_bst(&T, 99);//插入一个新值99
	preOrder(T);//再次查看

	return 0;
}


//二叉排序树-删除
//叶子结点直接删，对结构不会影响
//有一个孩子的结点，删除后直接“子承父业”
//两个孩子的结点，用右子树中最小节点或左子树中最大节点代替（选一种方法即可）
#include <iostream>
using namespace std;
typedef int TreeType;
typedef struct TreeNode
{
	TreeType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

void preOrder(BiTree T)//调试用，确保二叉排序树能够正确生成
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//查找二叉排序树中是否包含指定值 value
//参数T:当前子树根结点
//参数value:要查找的值1
//参数parent:当前节点的父结点
//参数pos:指针变量，用于1返回找到的节点
//返回值：1表示找到，0表示未找到
int search_bst(BiTree T, int value, BiTree parent, BiTree* pos)
{
	if (T == NULL)
	{
		*pos = parent;//递归到空结点，查找失败，将父结点返回（后面内容可用于插入）
		return 0;
	}

	if (value == T->data)
	{
		*pos = T;//找到目标值
		return 1;
	}
	else if (value > T->data)
	{
		return search_bst(T->rchild, value, T, pos);//要查找的值比当前节点小，往左子树找
	}
	else if (value < T->data)
	{
		return search_bst(T->lchild, value, T, pos);//要查找1的值比当前节点大，往右子树找
	}

}

void my_delete(BiTree* t);

void insert_bst(BiTree* T, TreeType value)
{
	BiTree pos = NULL;
	BiTree parent = NULL;
	BiTree curr = NULL;

	int ret = search_bst(*T, value, parent, &pos);

	if (ret == 0)
	{
		curr = new TreeNode;
		curr->data = value;
		curr->lchild = NULL;
		curr->rchild = NULL;

		if (pos == NULL)//二叉排序树为空
		{
			*T = curr;
		}
		else if (pos->data > value)
		{
			pos->lchild = curr;
		}
		else if (pos->data < value)
		{
			pos->rchild = curr;
		}
	}
	else
	{
		return;
	}
}

int delete_bst(BiTree* T, TreeType value)
{
	if (*T == NULL)
	{
		printf("not found\n");
	}
	else if (value > (*T)->data)
	{
		return delete_bst(&(*T)->rchild, value);
	}
	else if (value < (*T)->data)
	{
		return delete_bst(&(*T)->lchild, value);
	}
	else
	{
		my_delete(T);
		return 1;
	}
}

void my_delete(BiTree* t)
{
	BiTree temp = NULL;
	BiTree record = NULL;//记录第三种情况的“左子树最大结点”
	if ((*t)->lchild == NULL)
	{
		temp = *t;
		*t = temp->rchild;
		delete temp;
	}
	else if ((*t)->rchild == NULL)
	{
		temp = *t;
		*t = temp->lchild;
		delete temp;
	}
	else//要删除的结点左、右孩子都有,这里采用“左子树最大节点”替换
	{
		temp = *t;//第三种情况里，temp为record的父结点
		record = (*t)->lchild;
		while (record->rchild != NULL)// 找到左子树的最大节点（最右节点）
		{
			temp = record;
			record = record->rchild;
		}

		(*t)->data = record->data;// 用record的值替换要删除的节点的值

		// 删除record节点
		if (temp != *t)
		{
			temp->rchild = record->lchild;
			//如果record有左孩子，则把左孩子给record的父结点temp
		}
		else
		{
			temp->lchild = record->lchild;
			//当 record 节点恰好是要删除节点的直接左孩子时（即 temp == *t）：
			//将 record 的左子树挂接到 temp（也就是要删除的节点）的左孩子位置
			//这样就在移除 record 节点的同时，保留了 record 可能存在的左子树
		}
		delete record;
	}

}

int main()
{
	BiTree T = NULL;

	int treeArr[] = { 70,55,49,30,39,53,80,75,98,95 };//preorder
	int sz = sizeof(treeArr) / sizeof(treeArr[0]);
	for (int i = 0; i < sz; i++)
	{
		insert_bst(&T, treeArr[i]);
	}

	preOrder(T);//查看当前树结构
	printf("\n");

	insert_bst(&T, 99);//插入一个新值99
	preOrder(T);//再次查看
	printf("\n");

	delete_bst(&T, 49);
	preOrder(T);
	printf("\n");

	return 0;
}



//折半查找判定树
//具有n个结点的完全二叉树的深度为[log2(n)]+1

//折半查找的时间复杂度：O(log2(n))
//二叉排序树查找的时间复杂度：O(n)


//平衡二叉树 (AVL树) Balanced Binary Tree
//平衡二叉树是一种 二叉排序树 ，任意一个结点的左子树与右子树的高度之差的绝对值不超过1
//平衡因子(Balance Factor):是衡量结点平衡程度的指标
//平衡因子 = 左子树的高度 - 右子树的高度

//平衡二叉树平衡调整
//最小不平衡子树：从 插入点 向上回溯，第一个失衡的点，对失衡的平衡二叉树进行调整时，需要先找到最小不平衡子树
//LL型，RR型，LR型，RL型
//不用管上面的类型，直接乱拳打死牢师傅：（用于考试，非代码实现）
// 找到最小不平衡子树的根结点a，以该结点的下一个结点b(寻找最小不平衡子树向上回溯的倒数第二个结点，倒数第一个结点为最小不平衡子树的根结点)为轴，
// 比较a,b大小，按照平衡二叉树的定义以轴为中心旋转，b为新的根节点
// 若有不满足平衡二叉树的结点，自己调整一下

//一般数据的中位数充当平衡二叉树的根结点
