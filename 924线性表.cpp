#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//���Ա�Ķ������ص㣺
//���Ա���n������Ԫ�ص��������У�����n����������ͬ�������͵ġ�
//���Ա��ص㣺
//����Ψһ��һ������������һ����������Ԫ��
//����Ψһ��һ�������������һ����������Ԫ��
//����һ��Ԫ���⣬�ṹ�е�ÿ������Ԫ�ؾ�ֻ��һ��ǰ��
//�����һ��Ԫ���⣬�ṹ�е�ÿ������Ԫ�ؾ�ֻ��һ�����


//˳���
//��һ���������ڴ浥Ԫ���δ洢���Ա�ĸ���Ԫ�أ�Ҳ����˵���߼������ڵ�Ԫ�أ�ʵ�ʵ�����洢�ռ�Ҳ��������
#define MAXSIZE 100
typedef int ElemType;

typedef struct SeqList
{
	ElemType data[MAXSIZE];
	int length;
}SeqList;

//1.˳���-˳����ʼ��
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

//2.˳���-��β�����Ԫ��
#define MAXSIZE 100
typedef int ElemType;

typedef struct SeqList
{
	ElemType data[MAXSIZE];
	int length;
}SeqList;

//˳����ʼ��
void initList(struct SeqList* L)
{
	L->length = 0;
}
//β�����Ԫ��
void appendElem(struct SeqList* L,ElemType e)
{
	if (L->length >= MAXSIZE)
	{
		printf("˳�������\n");
		return;
	}

	L->data[L->length] = e;
	L->length++;

}

int main()
{
	SeqList list;
	initList(&list);
	appendElem(&list, 88);//88��Ҫ��ӵ�����

	return 0;
}

//3.˳���-����
void listElem(struct SeqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}

}

//4.˳���-����Ԫ��
//����Ԫ��
int insertElem(struct SeqList* L, int pos, ElemType e)
{
	if (L->length >= MAXSIZE)
	{
		printf("���Ѿ�����\n");
		return 1;
	}
	else if (pos < 1 || pos>L->length)
	{

		printf("����λ�ô���\n");
		return 0;
	}
	else if (pos <= L->length)
	{

		for (int i = L->length - 1; i >= pos - 1; i--)//ע���еȺŸ��ݾ����������
		{
			L->data[i + 1] = L->data[i];//ע��ǰ����i+1,������i�����ݾ����������
		}
		L->data[pos - 1] = e;
		L->length++;

	}
	return 1;
}
//O(1) -- O(n)

//5.˳���-ɾ��Ԫ��
void deleteElem(struct SeqList* L, int pos,ElemType* e)//���������������Ǹ�����ɾ��ʲô����
{
	if (L->length == 0)
	{
		printf("�ձ�\n");
		return;
	}

	if (pos<1 || pos>L->length)
	{
		printf("ɾ������,��Ԫ�ز�����");
		return;
	}

	*e = L->data[pos - 1];//�� C/C++ �﷨�У�else if ���������һ�� if �� else ������棬���ܸ�����ͨ�����档�������治����else if
	if (pos < L->length)//���ﲻȡ�ȵ�ԭ���ǣ���pos=length,����ѭ����˵����ζ�Ű�pos���Ԫ�ظ��ǵ�pos��ȥ����pos��length��ȣ���length֮���Ԫ������Ч�ģ�����Ч��Ԫ�طŵ�˳����о��Ǵ��
	{
		for (int i = pos - 1; i < L->length - 1; i++)
		{
			L->data[i] = L->data[i + 1];
		}
	
	}
	L->length--;
}

//6.˳���-����
int findElem(struct SeqList* L, ElemType num_find)
{
	if (L->length == 0)
	{
		printf("���б�\n");
		return -1;
	}
	for (int i = 0; i < L->length; i++)
	{
		if (num_find == L->data[i])
			return i+1;
	}
	return -1;
}



//˳���-��̬�����ڴ��ַ��ʼ��
#define MAXSIZE 100
typedef int ElemType;
typedef struct SeqList
{
	ElemType* data;//ע�����������������
	int length;
}SeqList;
//��ʼ��
SeqList* initList() //���������ǽṹ��SeqList����ָ��
{
	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
	if (L == NULL) // ��� malloc �Ƿ�ɹ�
	{
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (L->data == NULL) // ��� malloc �Ƿ�ɹ�
	{
		printf("�ڴ����ʧ��\n");
		free(L); // �ͷ��ѷ�����ڴ�
		return NULL;
	}
	L->length = 0;
	return L;
}
int main()
{
	SeqList* list = initList();//list�Ǹ���ַ
	//����û������һ���ṹ������Ϊ���listָ��ͨ���������ȥ���ڴ浱��ȥ����

	return 0;
} 
//����������һЩ�򵥺���
//ͳ��˳�����Ԫ�ظ�����return length;
//���˳���length = 0;





//����
//���Ա���ʽ�洢�ṹ���ص��ǣ��������ɲ�����
//ÿ�������е�Ԫ�س�Ϊ�ڵ�(node)
//�ڵ����������������ָ����
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;


//��һ ������
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

//1.������-��ʼ��     ����ͷ�ڵ�
Node* intiList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
int main()
{
	Node* list = intiList();//ͷ�ڵ�

	return 0;
}

//2.������-ͷ�巨  ÿ�β����ݶ�����ͷ�ڵ����ȥ��������
void insertHead(struct Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
}
//ͷ�巨��˳������е�˳�����෴��

int main()
{
	Node* list = intiList();//ͷ�ڵ�
	insertHead(list, 10);
	insertHead(list, 20);

	return 0;
}

//3.������-����
void listNode(struct Node* L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
//ע��ͷ�ڵ�͵�һ���ڵ㲻��һ���£�ͷ�ڵ�����ǰ���Ǹ�ͷ����һ���ڵ���ͷ�ڵ�֮���һ�������ݵĽڵ�

//4.β�巨
//�Ȼ�ȡβ�ڵ��ַ
Node* gettail(Node* L)
{
	Node* p = L;
	while (p->next != NULL)//ע��һ����p->next != NULL, ����p!=NULL������д���ս�����ص���NULL��
		p = p->next;
	return p;
}
//����β�巨
Node* insertTail(Node* tail, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;

	return p;//p���µ�β�ڵ�
}

//5.������-��ָ��λ�ò�������
void insertNode(Node* L, int pos, ElemType e)
{
	//�ӵ�һ���ڵ㴦��pos=1,������ͷ��㴦pos=1

	Node* p = L;//�����������λ�õ�ǰ���ڵ�
	int i = 0;//���������ҵ�����λ�õ�ǰ���ڵ�
	while (i < pos - 1)//ѭ��������Ҫ�������λ�õ�ǰһ��λ��
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			printf("ֻ��һ��ͷ�ڵ㣬�޷������½ڵ�\n");
			return;
		}
			
	}
	Node* q = (Node*)malloc(sizeof(Node));//Ҫ������½ڵ�
	q->data = e;
	q->next = p->next;
	p->next = q;
}

//6.������-ɾ���ڵ�
void deleteNode(Node* L, int pos)
{
	Node* p = L;
	int i = 0;
	while (i < pos - 1)//����pΪҪɾ���Ľڵ��ǰһ���ڵ�
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			printf("�ýڵ㲻����\n");
			return;
		}
	}

	//p->next = (p->next)->next;  ���Լ�д��

	Node* q = p->next;//����qָ��Ҫɾ����Ԫ��
	p->next = q->next;//Ҫɾ����Ԫ�ص�ǰ�� ָ�� Ҫɾ��Ԫ�صĺ��
	free(q);//�������ͷŶ��ڴ�ռ�
}

//7.������-��ȡ������
int listLength(Node* L)
{
	Node* p = L->next;//������������Ȳ�����ͷ�ڵ�
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

//8.������-�ͷ�����   ����ָ ��ͷ�ڵ�֮�����������ȫ�ͷŵ���ͷ�ڵ㱣��
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
	L->next = NULL;//ͷ�ڵ�ָ���
}


//����Ӧ��
//������Ӧ��
// [2019] ����һ������ֻ������ͷָ��list,�ڲ��ı������ǰ���£����һ�������ܸ�Ч���㷨�����������е�����k��λ���ϵĽڵ�
//        �����ҳɹ����㷨����ýڵ��data���ֵ��������1;����ֻ����0
//������˫ָ�루����ָ�룩
int FindNodeFS(Node* L,int k)
{
	Node* fast = L->next;
	Node* slow = L->next;
	for (int i = 0; i < k; i++)//��ָ�����ָ������k������
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

// [2012] �ٶ����ô�ͷ�ڵ�ĵ������浥�ʣ���������������ͬ�ĺ�׺ʱ����ɹ�����ͬ�ĺ�׺�洢�ռ�
//        ��str1��str2�ֱ�ָ�������������ڵ������ͷ�ڵ㣬���һ��ʱ���Ͼ����ܸ�Ч���㷨���ҳ���str1��str2��ָ����������ͬ��׺����ʼλ��
//������˫ָ�루����ָ�룩
Node* findIntersectionNode(Node* a, Node* b)
{
	if (a == NULL || b == NULL)
		return NULL;

	int m = listLength(a);
	int n = listLength(b);
	Node* fast = NULL;
	Node* slow = NULL;
	int step = 0;//��������֮��Ĳ�ֵ���������ڿ�ָ�����ߵĲ���
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

	return fast;//����return slow Ҳһ������Ϊ��ʱ����λ��һ��

}


// [2015] �õ�������n���������ڵ�ĽṹΪ[data][link],��|data|<=n(nΪ������).
//        ��Ҫ�����һ��ʱ�临�ӶȾ����ܸ�Ч���㷨������������data�ľ���ֵ��ȵĽڵ㣬��������һ�γ��ֵĽڵ��ɾ���������ֵ��ȵĽڵ�
//˼�룺�ÿռ任ʱ��
//ɾ������ֵ��ͬ�Ľڵ�
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
		index = abs(p->next->data);//abs��ȡ����ֵ
		if (arr[index] == 0)//*(arr+index)Ҳ����
		{
			arr[index] = 1;
			p = p->next;
		}
		else//p��Ҫɾ��Ŀ���ǰһ���ڵ�
		{
			Node* temp = p->next;//temp����ʱ�����Ľڵ㣬ָ��Ҫ��ɾ���Ľڵ�
			p->next = temp->next;
			free(temp);
		}
	}

	free(arr);//�ͷŴ�������Ŀռ�
}


//1.������Ӧ��-��ת����
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

	Node* head = intiList();//����ͷ�ڵ�
	head->next = first;

	return head;
}

//2.������Ӧ��-ɾ�������м�ڵ�
//ע��������ڵ����Ϊż���������м������ڵ���ƫ����Ľڵ�Ϊ�м�ڵ�
// ͨ������Ҫ ɾ��/���� ĳһ���ڵ��ʱ��һ��Ҫ���ҵ�����ǰ�ýڵ�
//����������ָ��
//��ָ����ٶ�����ָ�����������ָ������·�̣���ָ���Ȼ���м�
//ͬ����������ȷֵ㣬���ָ��һ����������ָ��һ��һ��
void delMiddleNode(Node* head)
{
	Node* fast = head->next;
	Node* slow = head;//����ָ����ͷ�ڵ㣬ʹ���������м�ָ���ǰһ��
	while (fast != NULL && fast->next != NULL)//fast!=NULL����������Ϊż����fast->next!=NULL����������Ϊ����
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* temp = slow->next;
	slow->next = temp->next;
	free(temp);
}

//����ָ�볣��˼��С�᣺
//1.һ���ָ����ָ�Ķ�����Ҫ����ĳ����������ָ����ܼ�����ǰ��
//2.����ָ��һ���ߣ���ÿ�ο�ָ���ߵľ��붼����ָ���
//3.��ָ������n����Ȼ�����ָ����һ����



// [2019] �����Ա�L=(a1,a2,a3,...,a n-2,a n-1,a n)���ô�ͷ�ڵ�ĵ�������
//        �����һ���ռ临�Ӷ�ΪO(1)��ʱ���Ͼ����ܸ�Ч���㷨����������L�еĸ��ڵ㣬�õ����Ա�L' = (a1,a n,a2,a n-1,a3,a n-2,...)
//̫��������⣬Ҫ�����࿴����
void reOrderList(Node* head)
{
	Node* fast = head->next;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}//�ҵ��м�ڵ��ǰһ���ڵ�

	Node* first = NULL;
	Node* second = slow->next;
	slow->next = NULL;//��������м����
	Node* third = NULL;
	while (second != NULL)
	{
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}//��ת����

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



//����ѭ������
//�ڵ������У��б�����Ϊp!=NULL��p->next!=NULL����ѭ���������е��б�����Ϊp!=L��p->next!=L
//�ж������Ƿ��л� ----����ָ��
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

//�����л���������
//��ȷ�����м����ڵ㣬˵���ղ�fast��slow������n��
//������fast��slowָ��ͷ�ڵ㣬fast��slow����n����Ȼ��ͬ����
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



//˫������
//��˫������Ľڵ���������ָ����һ��ָ��ֱ�Ӻ�̣���һ��ָ��ֱ��ǰ��
typedef int ElemType;
typedef struct doubleNode
{
	ElemType data = 0;
	struct doubleNode* prev, * next;
}doubleNode;

//˫������-��ʼ������
doubleNode* d_initList()
{
	doubleNode* head = (doubleNode*)malloc(sizeof(doubleNode));
	head->data = 0;
	head->prev = 0;
	head->next = 0;
	return head;
}

//˫������-ͷ�巨
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

//˫������-����
void listNode(doubleNode* L)
{
	doubleNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

}

//˫������-β�巨
doubleNode* insertTail(doubleNode* tail,ElemType e)
{
	doubleNode* p = (doubleNode*)malloc(sizeof * p);
	p->data = e;
	p->next = NULL;
	p->prev = tail;
	tail->next = p;

	return p;
}

//˫������-��ָ��λ�ò�������
void insertdoubleNode(doubleNode* L,int pos,ElemType e)
{
	doubleNode* p = L;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;//pΪĿ��λ�õ�ǰһ���ڵ�
		if (p == NULL||p->next==NULL)
			return;
	}
	doubleNode* q = (doubleNode*)malloc(sizeof * q);//qΪҪ�����Ԫ��
	q->data = e;
	q->next = p->next;
	q->prev = p;

	p->next = q;
	p->next->prev = q;
}

//˫������-ɾ���ڵ�
void doubleNodeDel(doubleNode* L, int pos)
{
	doubleNode* p = L;
	for (int i = 0; i < pos - 1; i++)//�����Ҵ�ɾԪ�ص�ǰ���ڵ㣻�����Ҵ�ɾԪ�صĺ�̽ڵ�ͬ��
	{
		p = p->next;
		if (p == NULL || p->next == NULL)
			return;
	}
	doubleNode* q = p->next;//ָ���ɾ�ڵ�
	p->next = q->next;
	q->next->prev = p;
	free(q);
	q == NULL;
}
