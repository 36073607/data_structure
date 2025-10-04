#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//ջ�Ķ�����ʵ��
//ջ��һ����������Ա�ֻ���ڱ�β���в����ɾ������
//��˶�ջ��˵����β���������⺬�壬��Ϊջ��(top)����Ӧ�أ���ͷ�˳�Ϊջ��(bottom)������Ԫ�صĿձ��Ϊ��ջ��
//ջ���޸��ǰ��պ���ȳ���ԭ����еģ���ˣ�ջ�ֳ�Ϊ����ȳ������Ա�
//����ȳ����Ƚ����������������ȳ�ȥ���Ƚ������ݺ��ȥ

//ջ�����Ʋ����ɾ��ֻ�ܲ�����һ��λ�õı���λ���Ǳ��ĩ�ˣ�����ջ����
//��ջ�Ļ��������� ��ջ/ѹջ(push) �� ��ջ(Pop) ��ǰ���൱�ڲ��룬��������ɾ���������Ԫ��


//ջ��˳��ṹʵ��
#define MAXSIZE 100//�ں궨���У�����Ҫʹ�õȺ�
typedef int ElemType;
typedef struct Stack
{
	ElemType data[MAXSIZE];
	int top;
}Stack;
//ջ�����±�ֵ����ջ��ָ��


//ջ��˳��ṹ-��ʼ��
void initStack(Stack* s)
{
	s->top = -1;
}


//ջ��˳��ṹ-�ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* s)
{
	if (s->top == -1)
	{
		printf("��\n");
		return 1;
	}
	else
		return 0;
}


//ջ��˳��ṹ-��ջ/ѹջ
int push(Stack* s, ElemType e)
{
	if (s->top >= MAXSIZE - 1)
	{
		printf("����\n");
		return 0;
	}
	
	s->top++;
	s->data[s->top] = e;
	return 1;
}


//ջ��˳��ṹ-��ջ
int pop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("�յ�\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}


//ջ��˳��ṹ-��ȡջ��Ԫ��
int getTop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("�յ�\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}

int main()
{
	Stack s;
	initStack(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	ElemType e;
	pop(&s, &e);
	printf("%d\n", e);
	getTop(&s, &e);
	printf("%d\n", e);

	return 0;
}



//ջ��˳��ṹ��ʼ��-��̬�����ڴ�
#define MAXSIZE 1000
typedef int ElemType;
typedef struct Stack
{
	int* data;
	int top;
};
Stack* initStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	s->top = -1;

	return s;
}




//ջ����ʽ�ṹʵ��
//����ͷ�ڵ���Ϊջ�ף�����ɾ��Ԫ�ؾ���O(n)�ˣ�ÿ�ζ�Ҫ���������������ͷ�巨�������ɾ������O(1)
//����β�ڵ���ջ�ף���һ���ڵ���ջ��
//ѹջ-->ͷ�巨   ��ջ-->ɾ����һ���ڵ�
typedef int ElemType;
typedef struct Stack
{
	ElemType data;
	struct Stack* next;
}Stack;
//ջ����ʽ�ṹʵ��-��ʼ��
Stack* iniStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}

//ջ����ʽ�ṹʵ��-�ж�ջ�Ƿ�Ϊ��
int is_Empty(Stack* s)
{
	if (s->next == NULL)
	{
		printf("��\n");
		return 0;
	}
	return 1;
}

//ջ����ʽ�ṹʵ��-��ջ/ѹջ (ͷ�巨)
void pushStack(Stack* s, ElemType e)
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}


//ջ����ʽ�ṹʵ��-��ջ
void popStack(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("��\n");
		return;
	}

	*e = s->next->data;//��ȡջ������
	Stack* tmp = s->next;
	s->next = tmp->next;
	free(tmp);

}


//ջ����ʽ�ṹʵ��-��ȡջ��Ԫ��
void getTop(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("��\n");
		return;
	}

	*e = s->next->data;
}

int main()
{

	Stack* s = iniStack();
	pushStack(s, 10);
	pushStack(s, 20);
	pushStack(s, 30);

	ElemType e;
	getTop(s, &e);
	printf("%d\n", e);

	popStack(s, &e);
	printf("%d\n", e);

	return 0;
}






//����(queue)
//������һ���Ƚ��ȳ������Ա�
//��ֻ�����ڱ��һ�˽��в��룬������һ��ɾ��Ԫ��
//�ڶ����У���������һ�˳�Ϊ��β(rear)������ɾ����һ�˳�Ϊ��ͷ(front)
//�������Ϊq=(a1,a2,...,an)����ô��a1���Ƕ�ͷԪ�أ�an���Ƕ�βԪ��
//�����е�Ԫ���ǰ���a1,a2,...,an��˳�����ģ��˳�����Ҳֻ�ܰ���������������˳�
#define MAXSIZE 100
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

//���е�˳��ṹ-��ʼ��
void initQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

//���е�˳��ṹ-�ж϶����Ƿ�Ϊ��
int isQ_Empty(Queue* Q)
{
	if (Q->front == Q->rear)//���н��ж�ν������в���������ͷ���β��ȣ������Ϊ��
	{
		printf("��\n");
		return 1;
	}
	else 
	{
		return 0;
	}
	
}

//���е�˳��ṹ-����
ElemType dequeue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		printf("��\n");
		return 0;
	}

	ElemType e = Q->data[Q->front];
	Q->front++;//��ͷ���±����ӣ��������ǵ�
	return e;
}

//���е�˳��ṹ-��������(һЩ�����Ѿ����ӣ���Ҫ������������������ǰ�ƣ�ʹ��ͷ���±��0��ʼ)
int queueFull(Queue* Q)
{
	if (Q->front > 0)//���������ô��
	{
		int difference = Q->front;//��ֵ��ʣ�µ�Ԫ����Ҫһ��Ų��ô�ಽ��
		for (int i = Q->front; i <= Q->rear; i++)
		{
			Q->data[i - difference] = Q->data[i];//����
		}
		Q->front = 0;
		Q->rear = Q->rear - difference;
		return 1;
	}
	else
	{
		printf("�������\n");
		return 0;
	}
}

//���е�˳��ṹ-���
void equeue(Queue* Q, ElemType e)
{
	if (Q->rear >= MAXSIZE)
	{
		if (!queueFull(Q))
		{
			printf("����\n");
			return;
		}
	}
	Q->data[Q->rear] = e;
	Q->rear++;
}

//���е�˳��ṹ-��ȡ��ͷ����
int getHead(Queue* Q,ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("�յ�\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}

int main()
{
	Queue queue;
	initQueue(&queue);
	equeue(&queue, 10);
	equeue(&queue, 20);
	equeue(&queue, 30);
	equeue(&queue, 40);
	equeue(&queue, 50);

	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));

	ElemType e;
	getHead(&queue, &e);
	printf("%d\n", e);

	return 0;
}








//���е�˳��ṹ-ѭ������
#define MAXSIZE 100
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

//���е�˳��ṹ-��ʼ��
void initQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

//���е�˳��ṹ-ѭ������-�ж϶����Ƿ�Ϊ��
int isQ_Empty(Queue* Q)
{
	if (Q->front == Q->rear)//���н��ж�ν������в���������ͷ���β��ȣ������Ϊ��
	{
		printf("��\n");
		return 1;
	}
	else
	{
		return 0;
	}

}

//���е�˳��ṹ-ѭ������-���
int equeue(Queue* Q, ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//eg:0 1 3 4 5 6, front=0,rear=6,MAXSIZE=7
	{
		printf("����\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;//�ص�
	return 1;
}

//����ע�⣺
//Ĭ������£�ͨ�����ǵĴ����߼��� ��βָ������ָ���βԪ�ص���һ��λ��  ���⵼��ѭ�������и�bug,�޷���������
//������ö�βָ��ָ���βԪ�أ���Ӧ�ö�β����ʼλ���� MAXSIZE-1 ���� (��Ȼ����Ҳ�����ͬ����bug)
typedef struct Queue
{
	ElemType* data;
	int front;
	int rear;
}Queue;
Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	q->front = 0;
	q->rear = MAXSIZE - 1;
	return q;
}
int equeue(Queue* Q, ElemType e)
{
	Q->rear = (Q->rear + 1) % MAXSIZE;//������ö�β�ƶ�
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("����\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	return 1;
}

//���е�˳��ṹ-ѭ������-����
int dequeue(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("�յ�\n");
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}

//���е�˳��ṹ-ѭ������-��ȡ��ͷ����
int getHead(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("�յ�\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}





//���е���ʽ�ṹ
typedef int ElemType;
typedef struct QueueNode
{
	ElemType data;
	struct QueueNode* next;
}QueueNode;
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

//���е���ʽ�ṹ-��ʼ��
Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));//��������
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));//����ͷ�ڵ�
	node->data = 0;
	node->next = NULL;

	q->front = node;
	q->rear = node;
	return q;
}

//���е���ʽ�ṹ-�ж϶����Ƿ�Ϊ��
int isEmpty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

//���е���ʽ�ṹ-���
//�������Ϊ�׽ڵ��Ƕ�ͷ����ô����β�巨
//�������Ϊ�׽ڵ��Ƕ�β����ô����ͷ�巨
//������β�巨
void equeue(Queue* q, ElemType e)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;//β�巨��nodeΪ�µ�β�ڵ�
	q->rear->next = node;//ͷ�ڵ��nextָ���һ���ڵ�node
	q->rear = node;//��βָ���һ���ڵ�

}

//���е���ʽ�ṹ-����
void dequeue(Queue* Q, ElemType* e)
{
	QueueNode* node = Q->front->next;//ָ���һ���ڵ�
	*e = node->data;
	Q->front->next = node->next;//��ͷָ��ڶ����ڵ�
	if (node == Q->rear)//���Ҫɾ���Ľڵ��Ƕ�β���������г�ͷ�ڵ���ֻ��һ���ڵ�
	{
		Q->rear = Q->front;
	}
	free(node);

}

////���е���ʽ�ṹ-��ȡ��ͷԪ��
ElemType getFront(Queue* q)
{
	if (isEmpty(q))
	{
		printf("�յ�\n");
		return -1;
	}

	return q->front->next->data;
}

int main()
{
	Queue* q = initQueue();
	equeue(q, 10);
	equeue(q, 20);
	equeue(q, 30);
	equeue(q, 40);
	equeue(q, 50);

	ElemType e;
	dequeue(q, &e);
	printf("%d\n", e);
	dequeue(q, &e);
	printf("%d\n", e);

	printf("%d\n", getFront(q));

	return 0;
}





//���⣺˫�˶���
//��ͷ����ͷ��/��ͷ��һͷ��/һͷ����ͷ��
