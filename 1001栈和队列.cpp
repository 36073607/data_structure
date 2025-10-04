#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//栈的定义与实现
//栈是一个特殊的线性表，只能在表尾进行插入或删除操作
//因此对栈来说，表尾端有其特殊含义，称为栈顶(top)；相应地，表头端称为栈底(bottom)。不含元素的空表称为空栈。
//栈的修改是按照后进先出的原则进行的，因此，栈又称为后进先出的线性表
//后进先出，先进后出：后进的内容先出去，先进的内容后出去

//栈是限制插入和删除只能操作在一个位置的表，该位置是表的末端，叫做栈顶。
//对栈的基本操作有 进栈/压栈(push) 和 出栈(Pop) ，前者相当于插入，后者则是删除最后插入的元素


//栈的顺序结构实现
#define MAXSIZE 100//在宏定义中，不需要使用等号
typedef int ElemType;
typedef struct Stack
{
	ElemType data[MAXSIZE];
	int top;
}Stack;
//栈顶的下标值称作栈顶指针


//栈的顺序结构-初始化
void initStack(Stack* s)
{
	s->top = -1;
}


//栈的顺序结构-判断栈是否为空
int isEmpty(Stack* s)
{
	if (s->top == -1)
	{
		printf("空\n");
		return 1;
	}
	else
		return 0;
}


//栈的顺序结构-进栈/压栈
int push(Stack* s, ElemType e)
{
	if (s->top >= MAXSIZE - 1)
	{
		printf("满了\n");
		return 0;
	}
	
	s->top++;
	s->data[s->top] = e;
	return 1;
}


//栈的顺序结构-出栈
int pop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}


//栈的顺序结构-获取栈顶元素
int getTop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("空的\n");
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



//栈的顺序结构初始化-动态分配内存
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




//栈的链式结构实现
//若把头节点视为栈底，但是删除元素就是O(n)了，每次都要遍历，但是如果是头插法，插入和删除都是O(1)
//所以尾节点是栈底，第一个节点是栈顶
//压栈-->头插法   出栈-->删除第一个节点
typedef int ElemType;
typedef struct Stack
{
	ElemType data;
	struct Stack* next;
}Stack;
//栈的链式结构实现-初始化
Stack* iniStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}

//栈的链式结构实现-判断栈是否为空
int is_Empty(Stack* s)
{
	if (s->next == NULL)
	{
		printf("空\n");
		return 0;
	}
	return 1;
}

//栈的链式结构实现-进栈/压栈 (头插法)
void pushStack(Stack* s, ElemType e)
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}


//栈的链式结构实现-出栈
void popStack(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("空\n");
		return;
	}

	*e = s->next->data;//获取栈顶数据
	Stack* tmp = s->next;
	s->next = tmp->next;
	free(tmp);

}


//栈的链式结构实现-获取栈顶元素
void getTop(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("空\n");
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






//队列(queue)
//队列是一种先进先出的线性表
//它只允许在表的一端进行插入，而在另一端删除元素
//在队列中，允许插入的一端称为队尾(rear)，允许删除的一端称为队头(front)
//假设队列为q=(a1,a2,...,an)，那么，a1就是队头元素，an就是队尾元素
//队列中的元素是按照a1,a2,...,an的顺序进入的，退出队列也只能按照这个次序依次退出
#define MAXSIZE 100
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

//队列的顺序结构-初始化
void initQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

//队列的顺序结构-判断队列是否为空
int isQ_Empty(Queue* Q)
{
	if (Q->front == Q->rear)//队列进行多次进出队列操作后，若队头与队尾相等，则队列为空
	{
		printf("空\n");
		return 1;
	}
	else 
	{
		return 0;
	}
	
}

//队列的顺序结构-出队
ElemType dequeue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		printf("空\n");
		return 0;
	}

	ElemType e = Q->data[Q->front];
	Q->front++;//队头的下标增加，给他覆盖掉
	return e;
}

//队列的顺序结构-调整队列(一些数据已经出队，需要将队列中其他数据往前移，使队头的下标从0开始)
int queueFull(Queue* Q)
{
	if (Q->front > 0)//我真的满了么？
	{
		int difference = Q->front;//差值，剩下的元素需要一次挪这么多步长
		for (int i = Q->front; i <= Q->rear; i++)
		{
			Q->data[i - difference] = Q->data[i];//核心
		}
		Q->front = 0;
		Q->rear = Q->rear - difference;
		return 1;
	}
	else
	{
		printf("真的满了\n");
		return 0;
	}
}

//队列的顺序结构-入队
void equeue(Queue* Q, ElemType e)
{
	if (Q->rear >= MAXSIZE)
	{
		if (!queueFull(Q))
		{
			printf("满了\n");
			return;
		}
	}
	Q->data[Q->rear] = e;
	Q->rear++;
}

//队列的顺序结构-获取队头数据
int getHead(Queue* Q,ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
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








//队列的顺序结构-循环队列
#define MAXSIZE 100
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

//队列的顺序结构-初始化
void initQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

//队列的顺序结构-循环队列-判断队列是否为空
int isQ_Empty(Queue* Q)
{
	if (Q->front == Q->rear)//队列进行多次进出队列操作后，若队头与队尾相等，则队列为空
	{
		printf("空\n");
		return 1;
	}
	else
	{
		return 0;
	}

}

//队列的顺序结构-循环队列-入队
int equeue(Queue* Q, ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//eg:0 1 3 4 5 6, front=0,rear=6,MAXSIZE=7
	{
		printf("满了\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;//重点
	return 1;
}

//及其注意：
//默认情况下，通常我们的代码逻辑是 队尾指针总是指向队尾元素的下一个位置  （这导致循环队列有个bug,无法被填满）
//如果想让队尾指针指向队尾元素，则应让队尾的起始位置在 MAXSIZE-1 这里 (当然最终也会出现同样的bug)
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
	Q->rear = (Q->rear + 1) % MAXSIZE;//入队先让队尾移动
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("满了\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	return 1;
}

//队列的顺序结构-循环队列-出队
int dequeue(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}

//队列的顺序结构-循环队列-获取队头数据
int getHead(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}





//队列的链式结构
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

//队列的链式结构-初始化
Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));//创建队列
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));//创建头节点
	node->data = 0;
	node->next = NULL;

	q->front = node;
	q->rear = node;
	return q;
}

//队列的链式结构-判断队列是否为空
int isEmpty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

//队列的链式结构-入队
//如果你认为首节点是队头，那么就用尾插法
//如果你认为首节点是队尾，那么就用头插法
//这里用尾插法
void equeue(Queue* q, ElemType e)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;//尾插法，node为新的尾节点
	q->rear->next = node;//头节点的next指向第一个节点node
	q->rear = node;//队尾指向第一个节点

}

//队列的链式结构-出队
void dequeue(Queue* Q, ElemType* e)
{
	QueueNode* node = Q->front->next;//指向第一个节点
	*e = node->data;
	Q->front->next = node->next;//队头指向第二个节点
	if (node == Q->rear)//如果要删除的节点是队尾，即队列中除头节点外只有一个节点
	{
		Q->rear = Q->front;
	}
	free(node);

}

////队列的链式结构-获取队头元素
ElemType getFront(Queue* q)
{
	if (isEmpty(q))
	{
		printf("空的\n");
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





//番外：双端队列
//两头进两头出/两头进一头出/一头进两头出
