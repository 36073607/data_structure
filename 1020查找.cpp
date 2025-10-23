#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//ASL��Average Search Length������ƽ�����ҳ���
//�ڲ��������У���������ʱ���ڹؼ��ֵıȽ��ϣ����԰�ƽ����Ҫ�ʹ�����ֵ�ȽϵĹؼ��ִ�����Ϊƽ�����ҳ��ȡ�

//���Ա�Ĳ���-˳�����
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


//���Ա�Ĳ���-�۰����(���ֲ���)
//ע���۰���ҵ�ǰ���ǣ�
//���ұ����������ģ���һ��ǳ��ؼ������������ʹ���۰��������ȫû������1��
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


//����������(BST)
//������������һ������Ķ���������ͨ������Ľڵ����з�ʽ��ʵ���ˡ�����Ч�ʸߡ�����ɾ������Ŀ�꣬�������������ԣ�
//1.������������һ���ڵ㣬�������������нڵ��ֵ��С�ڸýڵ��ֵ
//2.������������һ���ڵ㣬�������������нڵ��ֵ�����ڸýڵ��ֵ����������������Ҳ����һ�ö���������
//ע�⣺���������������Ŀ�ģ�������Ϊ�����򣬶���Ϊ����߲��ҡ������Լ�ɾ���ؼ��ֵ��ٶ�

//����������-����
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

//-1��ʾ�ս��
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

void preOrder(BiTree T)//�����ã�ȷ�������������ܹ���ȷ����
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//���Ҷ������������Ƿ����ָ��ֵ value
//����T:��ǰ���������
//����value:Ҫ���ҵ�ֵ1
//����parent:��ǰ�ڵ�ĸ����
//����pos:ָ�����������1�����ҵ��Ľڵ�
//����ֵ��1��ʾ�ҵ���0��ʾδ�ҵ�
int search_bst(BiTree T, int value, BiTree parent, BiTree* pos)
{
	if (T == NULL)
	{
		*pos = parent;//�ݹ鵽�ս�㣬����ʧ�ܣ�������㷵�أ��������ݿ����ڲ��룩
		return 0;
	}

	if (value == T->data)
	{
		*pos = T;//�ҵ�Ŀ��ֵ
		return 1;
	}
	else if (value > T->data)
	{
		return search_bst(T->rchild, value, T, pos);//Ҫ���ҵ�ֵ�ȵ�ǰ�ڵ�С������������
	}
	else if (value < T->data)
	{
		return search_bst(T->lchild, value, T, pos);//Ҫ����1��ֵ�ȵ�ǰ�ڵ������������
	}
	//ע��ݹ�ʱ����parentΪT
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


//����������-����
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

void preOrder(BiTree T)//�����ã�ȷ�������������ܹ���ȷ����
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//���Ҷ������������Ƿ����ָ��ֵ value
//����T:��ǰ���������
//����value:Ҫ���ҵ�ֵ1
//����parent:��ǰ�ڵ�ĸ����
//����pos:ָ�����������1�����ҵ��Ľڵ�
//����ֵ��1��ʾ�ҵ���0��ʾδ�ҵ�
int search_bst(BiTree T, int value, BiTree parent, BiTree* pos)
{
	if (T == NULL)
	{
		*pos = parent;//�ݹ鵽�ս�㣬����ʧ�ܣ�������㷵�أ��������ݿ����ڲ��룩
		return 0;
	}

	if (value == T->data)
	{
		*pos = T;//�ҵ�Ŀ��ֵ
		return 1;
	}
	else if (value > T->data)
	{
		return search_bst(T->rchild, value, T, pos);//Ҫ���ҵ�ֵ�ȵ�ǰ�ڵ�С������������
	}
	else if (value < T->data)
	{
		return search_bst(T->lchild, value, T, pos);//Ҫ����1��ֵ�ȵ�ǰ�ڵ������������
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

		if (pos == NULL)//����������Ϊ��
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

	preOrder(T);//�鿴��ǰ���ṹ
	printf("\n");

	insert_bst(&T, 99);//����һ����ֵ99
	preOrder(T);//�ٴβ鿴

	return 0;
}


//����������-ɾ��
//Ҷ�ӽ��ֱ��ɾ���Խṹ����Ӱ��
//��һ�����ӵĽ�㣬ɾ����ֱ�ӡ��ӳи�ҵ��
//�������ӵĽ�㣬������������С�ڵ�������������ڵ���棨ѡһ�ַ������ɣ�
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

void preOrder(BiTree T)//�����ã�ȷ�������������ܹ���ȷ����
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//���Ҷ������������Ƿ����ָ��ֵ value
//����T:��ǰ���������
//����value:Ҫ���ҵ�ֵ1
//����parent:��ǰ�ڵ�ĸ����
//����pos:ָ�����������1�����ҵ��Ľڵ�
//����ֵ��1��ʾ�ҵ���0��ʾδ�ҵ�
int search_bst(BiTree T, int value, BiTree parent, BiTree* pos)
{
	if (T == NULL)
	{
		*pos = parent;//�ݹ鵽�ս�㣬����ʧ�ܣ�������㷵�أ��������ݿ����ڲ��룩
		return 0;
	}

	if (value == T->data)
	{
		*pos = T;//�ҵ�Ŀ��ֵ
		return 1;
	}
	else if (value > T->data)
	{
		return search_bst(T->rchild, value, T, pos);//Ҫ���ҵ�ֵ�ȵ�ǰ�ڵ�С������������
	}
	else if (value < T->data)
	{
		return search_bst(T->lchild, value, T, pos);//Ҫ����1��ֵ�ȵ�ǰ�ڵ������������
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

		if (pos == NULL)//����������Ϊ��
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
	BiTree record = NULL;//��¼����������ġ�����������㡱
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
	else//Ҫɾ���Ľ�����Һ��Ӷ���,������á����������ڵ㡱�滻
	{
		temp = *t;//����������tempΪrecord�ĸ����
		record = (*t)->lchild;
		while (record->rchild != NULL)// �ҵ������������ڵ㣨���ҽڵ㣩
		{
			temp = record;
			record = record->rchild;
		}

		(*t)->data = record->data;// ��record��ֵ�滻Ҫɾ���Ľڵ��ֵ

		// ɾ��record�ڵ�
		if (temp != *t)
		{
			temp->rchild = record->lchild;
			//���record�����ӣ�������Ӹ�record�ĸ����temp
		}
		else
		{
			temp->lchild = record->lchild;
			//�� record �ڵ�ǡ����Ҫɾ���ڵ��ֱ������ʱ���� temp == *t����
			//�� record ���������ҽӵ� temp��Ҳ����Ҫɾ���Ľڵ㣩������λ��
			//���������Ƴ� record �ڵ��ͬʱ�������� record ���ܴ��ڵ�������
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

	preOrder(T);//�鿴��ǰ���ṹ
	printf("\n");

	insert_bst(&T, 99);//����һ����ֵ99
	preOrder(T);//�ٴβ鿴
	printf("\n");

	delete_bst(&T, 49);
	preOrder(T);
	printf("\n");

	return 0;
}



//�۰�����ж���
//����n��������ȫ�����������Ϊ[log2(n)]+1

//�۰���ҵ�ʱ�临�Ӷȣ�O(log2(n))
//�������������ҵ�ʱ�临�Ӷȣ�O(n)


//ƽ������� (AVL��) Balanced Binary Tree
//ƽ���������һ�� ���������� ������һ���������������������ĸ߶�֮��ľ���ֵ������1
//ƽ������(Balance Factor):�Ǻ������ƽ��̶ȵ�ָ��
//ƽ������ = �������ĸ߶� - �������ĸ߶�

//ƽ�������ƽ�����
//��С��ƽ���������� ����� ���ϻ��ݣ���һ��ʧ��ĵ㣬��ʧ���ƽ����������е���ʱ����Ҫ���ҵ���С��ƽ������
//LL�ͣ�RR�ͣ�LR�ͣ�RL��
//���ù���������ͣ�ֱ����ȭ������ʦ���������ڿ��ԣ��Ǵ���ʵ�֣�
// �ҵ���С��ƽ�������ĸ����a���Ըý�����һ�����b(Ѱ����С��ƽ���������ϻ��ݵĵ����ڶ�����㣬������һ�����Ϊ��С��ƽ�������ĸ����)Ϊ�ᣬ
// �Ƚ�a,b��С������ƽ��������Ķ�������Ϊ������ת��bΪ�µĸ��ڵ�
// ���в�����ƽ��������Ľ�㣬�Լ�����һ��

//һ�����ݵ���λ���䵱ƽ��������ĸ����
