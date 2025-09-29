#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//线性表的定义与特点：
//线性表是n个数据元素的有限序列，其中n个数据是相同数据类型的。
//线性表特点：
//存在唯一的一个被称作“第一个”的数据元素
//存在唯一的一个被称作“最后一个”的数据元素
//除第一个元素外，结构中的每个数据元素均只有一个前驱
//除最后一个元素外，结构中的每个数据元素均只有一个后继


//顺序表
//用一组连续的内存单元依次存储线性表的各个元素，也就是说，逻辑上相邻的元素，实际的物理存储空间也是连续的
#define MAXSIZE 100
typedef int ElemType;

typedef struct SeqList
{
	ElemType data[MAXSIZE];
	int length;
}SeqList;

//1.顺序表-顺序表初始化
void initList(struct SeqList* L)
{
	L->length = 0;
}

int main()
{
	SeqList list;
	initList(&list);

	return 0;
}

//2.顺序表-在尾部添加元素
#define MAXSIZE 100
typedef int ElemType;

typedef struct SeqList
{
	ElemType data[MAXSIZE];
	int length;
}SeqList;

//顺序表初始化
void initList(struct SeqList* L)
{
	L->length = 0;
}
//尾部添加元素
void appendElem(struct SeqList* L,ElemType e)
{
	if (L->length >= MAXSIZE)
	{
		printf("顺序表已满\n");
		return;
	}

	L->data[L->length] = e;
	L->length++;

}

int main()
{
	SeqList list;
	initList(&list);
	appendElem(&list, 88);//88是要添加的数据

	return 0;
}

//3.顺序表-遍历
void listElem(struct SeqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}

}

//4.顺序表-插入元素
//插入元素
int insertElem(struct SeqList* L, int pos, ElemType e)
{
	if (L->length >= MAXSIZE)
	{
		printf("表已经满了\n");
		return 1;
	}
	else if (pos < 1 || pos>L->length)
	{

		printf("插入位置错误\n");
		return 0;
	}
	else if (pos <= L->length)
	{

		for (int i = L->length - 1; i >= pos - 1; i--)//注意有等号根据具体情况而定
		{
			L->data[i + 1] = L->data[i];//注意前面是i+1,后面是i，根据具体情况而定
		}
		L->data[pos - 1] = e;
		L->length++;

	}
	return 1;
}
//O(1) -- O(n)

//5.顺序表-删除元素
void deleteElem(struct SeqList* L, int pos,ElemType* e)//第三个参数意义是告诉我删了什么东西
{
	if (L->length == 0)
	{
		printf("空表\n");
		return;
	}

	if (pos<1 || pos>L->length)
	{
		printf("删除有误,该元素不存在");
		return;
	}

	*e = L->data[pos - 1];//在 C/C++ 语法中，else if 必须紧跟在一个 if 或 else 语句块后面，不能跟在普通语句后面。所有下面不能用else if
	if (pos < L->length)//这里不取等的原因是：当pos=length,按照循环来说就意味着把pos后的元素覆盖到pos上去，但pos与length相等，而length之后的元素是无效的，把无效的元素放到顺序表中就是错的
	{
		for (int i = pos - 1; i < L->length - 1; i++)
		{
			L->data[i] = L->data[i + 1];
		}
	
	}
	L->length--;
}

//6.顺序表-查找
int findElem(struct SeqList* L, ElemType num_find)
{
	if (L->length == 0)
	{
		printf("空列表\n");
		return -1;
	}
	for (int i = 0; i < L->length; i++)
	{
		if (num_find == L->data[i])
			return i+1;
	}
	return -1;
}



//顺序表-动态分配内存地址初始化
#define MAXSIZE 100
typedef int ElemType;
typedef struct SeqList
{
	ElemType* data;//注意与上面的数组区分
	int length;
}SeqList;
//初始化
SeqList* initList() //返回类型是结构体SeqList类型指针
{
	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
	if (L == NULL) // 检查 malloc 是否成功
	{
		printf("内存分配失败\n");
		return NULL;
	}
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (L->data == NULL) // 检查 malloc 是否成功
	{
		printf("内存分配失败\n");
		free(L); // 释放已分配的内存
		return NULL;
	}
	L->length = 0;
	return L;
}
int main()
{
	SeqList* list = initList();//list是个地址
	//这里没有声明一个结构体是因为这个list指针通过这个函数去堆内存当中去创建

	return 0;
} 
//附：其他的一些简单函数
//统计顺序表中元素个数：return length;
//清空顺序表：length = 0;





//链表
//线性表链式存储结构的特点是：可连续可不连续
//每个链表中的元素称为节点(node)
//节点包括两个域：数据域、指针域
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;


//其一 单链表
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

//1.单链表-初始化     创建头节点
Node* intiList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
int main()
{
	Node* list = intiList();//头节点

	return 0;
}

//2.单链表-头插法  每次插数据都是在头节点后面去插入数据
void insertHead(struct Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
}
//头插法的顺序和排列的顺序是相反的

int main()
{
	Node* list = intiList();//头节点
	insertHead(list, 10);
	insertHead(list, 20);

	return 0;
}

//3.单链表-遍历
void listNode(struct Node* L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
//注：头节点和第一个节点不是一回事，头节点是最前面那个头，第一个节点是头节点之后第一个有数据的节点

//4.尾插法
//先获取尾节点地址
Node* gettail(Node* L)
{
	Node* p = L;
	while (p->next != NULL)//注意一定是p->next != NULL, 不是p!=NULL（这样写最终结果返回的是NULL）
		p = p->next;
	return p;
}
//进行尾插法
Node* insertTail(Node* tail, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;

	return p;//p是新的尾节点
}

//5.单链表-在指定位置插入数据
void insertNode(Node* L, int pos, ElemType e)
{
	//从第一个节点处是pos=1,而不是头结点处pos=1

	Node* p = L;//用来保存插入位置的前驱节点
	int i = 0;//遍历链表找到插入位置的前驱节点
	while (i < pos - 1)//循环到你想要插入这个位置的前一个位置
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			printf("只有一个头节点，无法插入新节点\n");
			return;
		}
			
	}
	Node* q = (Node*)malloc(sizeof(Node));//要插入的新节点
	q->data = e;
	q->next = p->next;
	p->next = q;
}

//6.单链表-删除节点
void deleteNode(Node* L, int pos)
{
	Node* p = L;
	int i = 0;
	while (i < pos - 1)//最终p为要删除的节点的前一个节点
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			printf("该节点不存在\n");
			return;
		}
	}

	//p->next = (p->next)->next;  我自己写的

	Node* q = p->next;//创造q指向要删除的元素
	p->next = q->next;//要删除的元素的前驱 指向 要删除元素的后继
	free(q);//别忘了释放堆内存空间
}

//7.单链表-获取链表长度
int listLength(Node* L)
{
	Node* p = L->next;//这里求的链表长度不包括头节点
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

//8.单链表-释放链表   这里指 把头节点之后的所有内容全释放掉，头节点保留
void freeList(Node* L)
{
	Node* p = L->next;
	Node* q = NULL;
	int i = 0;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;//头节点指向空
}


//链表应用
//单链表应用
// [2019] 假设一个链表只给出了头指针list,在不改变链表的前提下，设计一个尽可能高效的算法，查找链表中倒数第k个位置上的节点
//        若查找成功，算法输出该节点的data域的值，并返回1;否则，只返回0
//方法：双指针（快慢指针）
int FindNodeFS(Node* L,int k)
{
	Node* fast = L->next;
	Node* slow = L->next;
	for (int i = 0; i < k; i++)//快指针比慢指针先走k个距离
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}

	printf("%d\n", slow->data);

	return 1;
}

// [2012] 假定采用带头节点的单链表保存单词，当两个单词有相同的后缀时，则可共享相同的后缀存储空间
//        设str1和str2分别指向两个单词所在单链表的头节点，设计一个时间上尽可能高效的算法，找出由str1和str2所指向两个链表共同后缀的起始位置
//方法：双指针（快慢指针）
Node* findIntersectionNode(Node* a, Node* b)
{
	if (a == NULL || b == NULL)
		return NULL;

	int m = listLength(a);
	int n = listLength(b);
	Node* fast = NULL;
	Node* slow = NULL;
	int step = 0;//两个单词之间的差值，可以用于快指针先走的步数
	if (m >= n)
	{
		step = m - n;
		fast = a->next;
		slow = b->next;
	}
	else
	{
		step = n - m;
		fast = b->next;
		slow = a->next;
	}
	for (int i = 0; i < step; i++)
	{
		fast = fast->next;
	}
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return fast;//这里return slow 也一样，因为此时二者位置一样

}


// [2015] 用单链表保存n个整数，节点的结构为[data][link],且|data|<=n(n为正整数).
//        现要求设计一个时间复杂度尽可能高效的算法，对于链表中data的绝对值相等的节点，仅保留第一次出现的节点而删除其余绝对值相等的节点
//思想：用空间换时间
//删除绝对值相同的节点
void removeNode(Node* L, int n)
{
	Node* p = L;
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	int index = 0;
	for (int i = 0; i < n + 1; i++)
	{
		*(arr + i) = 0;
	}
	while (p->next != NULL)
	{
		index = abs(p->next->data);//abs获取绝对值
		if (arr[index] == 0)//*(arr+index)也可以
		{
			arr[index] = 1;
			p = p->next;
		}
		else//p是要删除目标的前一个节点
		{
			Node* temp = p->next;//temp是临时创建的节点，指向要被删除的节点
			p->next = temp->next;
			free(temp);
		}
	}

	free(arr);//释放创造数组的空间
}


//1.单链表应用-反转链表
Node* reverseList(Node* L)
{
	Node* first = NULL;
	Node* second = L->next;
	Node* third = NULL;

	while (second != NULL)
	{
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}

	Node* head = intiList();//创建头节点
	head->next = first;

	return head;
}

//2.单链表应用-删除链表中间节点
//注：若链表节点个数为偶数个，则中间两个节点中偏靠后的节点为中间节点
// 通常我们要 删除/插入 某一个节点的时候，一定要先找到它的前置节点
//方法：快慢指针
//快指针的速度是慢指针的两倍，快指针走完路程，慢指针必然在中间
//同理，如果是三等分点，则快指针一次三步，慢指针一次一步
void delMiddleNode(Node* head)
{
	Node* fast = head->next;
	Node* slow = head;//让慢指针在头节点，使其最终在中间指针的前一个
	while (fast != NULL && fast->next != NULL)//fast!=NULL限制了链表为偶数，fast->next!=NULL限制了链表为奇数
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* temp = slow->next;
	slow->next = temp->next;
	free(temp);
}

//快慢指针常见思想小结：
//1.一般快指针所指的对象需要满足某个条件，慢指针才能继续往前走
//2.快慢指针一起走，但每次快指针走的距离都比慢指针多
//3.快指针先走n步，然后快慢指针再一起走



// [2019] 设线性表L=(a1,a2,a3,...,a n-2,a n-1,a n)采用带头节点的单链表保存
//        请设计一个空间复杂度为O(1)且时间上尽可能高效的算法，重新排列L中的各节点，得到线性表L' = (a1,a n,a2,a n-1,a3,a n-2,...)
//太难了这道题，要反复多看多练
void reOrderList(Node* head)
{
	Node* fast = head->next;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}//找到中间节点的前一个节点

	Node* first = NULL;
	Node* second = slow->next;
	slow->next = NULL;//把链表从中间打折
	Node* third = NULL;
	while (second != NULL)
	{
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}//反转链表

	Node* p1 = head->next;
	Node* q1 = first;
	Node* p2 = NULL, * q2 = NULL;
	while (p1 != NULL && q1 != NULL)
	{
		p2 = p1->next;
		q2 = q1->next;

		p1->next = q1;
		q1->next = p2;

		p1 = p2;
		q1 = q2;
	}

}



//单向循环链表
//在单链表中，判别条件为p!=NULL或p->next!=NULL，而循环单链表中的判别条件为p!=L或p->next!=L
//判断链表是否有环 ----快慢指针
int isCycle(Node* head)
{
	Node* fast = head;
	Node* slow = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return 1;
		}
	}
	return 0;
}

//链表有环入口在哪里？
//先确定环有几个节点，说明刚才fast比slow多走了n步
//重新让fast与slow指向头节点，fast比slow先走n步，然后同步走
Node* findEntrance(Node* L)
{
	Node* fast = L;
	Node* slow = L;
	int count = 1;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			fast = fast->next;
			while (fast != slow)
			{
				fast = fast->next;
				count++;
			}

			fast = L;
			slow = L;

			for (int i = 0; i < count; i++)
			{
				fast = fast->next;
			}
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}

			return fast;

		}

	}
	
	return NULL;
	
}



//双向链表
//在双向链表的节点中有两个指针域，一个指向直接后继，另一个指向直接前驱
typedef int ElemType;
typedef struct doubleNode
{
	ElemType data = 0;
	struct doubleNode* prev, * next;
}doubleNode;

//双向链表-初始化链表
doubleNode* d_initList()
{
	doubleNode* head = (doubleNode*)malloc(sizeof(doubleNode));
	head->data = 0;
	head->prev = 0;
	head->next = 0;
	return head;
}

//双向链表-头插法
void inserthead(doubleNode* L, ElemType e)
{
	doubleNode* p = (doubleNode*)malloc(sizeof(doubleNode));
	p->data = e;
	p->prev = L;
	p->next = L->next;
	if (L->next != NULL)
	{
		L->next->prev = p;
	}
	L->next = p;
}

//双向链表-遍历
void listNode(doubleNode* L)
{
	doubleNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

}

//双向链表-尾插法
doubleNode* insertTail(doubleNode* tail,ElemType e)
{
	doubleNode* p = (doubleNode*)malloc(sizeof * p);
	p->data = e;
	p->next = NULL;
	p->prev = tail;
	tail->next = p;

	return p;
}

//双向链表-在指定位置插入数据
void insertdoubleNode(doubleNode* L,int pos,ElemType e)
{
	doubleNode* p = L;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;//p为目标位置的前一个节点
		if (p == NULL||p->next==NULL)
			return;
	}
	doubleNode* q = (doubleNode*)malloc(sizeof * q);//q为要插入的元素
	q->data = e;
	q->next = p->next;
	q->prev = p;

	p->next = q;
	p->next->prev = q;
}

//双向链表-删除节点
void doubleNodeDel(doubleNode* L, int pos)
{
	doubleNode* p = L;
	for (int i = 0; i < pos - 1; i++)//这里找待删元素的前驱节点；这里找待删元素的后继节点同理
	{
		p = p->next;
		if (p == NULL || p->next == NULL)
			return;
	}
	doubleNode* q = p->next;//指向待删节点
	p->next = q->next;
	q->next->prev = p;
	free(q);
	q == NULL;
}
