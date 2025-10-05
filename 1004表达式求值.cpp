#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//ö��
//��������ֵһһ�оٳ�����������ֵֻ�����оٳ�����ֵ�ķ�Χ��
//��ö�����г���ÿһ��ֵ����Ϊö��Ԫ��
//ÿһ��ö��Ԫ����ϵͳ������һ������ű�ʾ����ֵ����0��ʼ���ֱ�Ϊ0��1��2��...
//�﷨��
//enum ö����
//{
//	ö��Ԫ��...
//};

enum week
{
	mon,tue,wed,thu,fri,sat,sun
//   0   1   2   3   4   5   6

//  mon=1, tue, wed, thu, fri, sat, sun           ��д mon=1 ʱ ��ϵͳĬ�ϴ�1��ʼ
//    1     2    3    4    5    6    7
};
typedef enum my_bool
{
	mt_false,my_true
//     0       1
}my_bool;//��һ����ṹ��һ��
int main()
{
	enum week a;
	a = mon;

	enum week b = fri;

	my_bool k = my_true;

	printf("%d\n", a);//0
	printf("%d\n", b);//4

	return 0;
}



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;
//��׺���ʽ��ֵ
//����������ջ�������ַ���ջ��Ȼ����������ٽ����ѹ��ջ��
#define MAXSIZE 100
typedef int ElemType;
typedef struct Stack
{
    ElemType* arr;
    int top;
}Stack;

char expr[] = "82/2+56*-";
typedef enum contentType
{
    LEFT_PARE, RIGHT_PARE,
    ADD, SUB, MUL, DIV, MOD,
    EOS, NUM
}contentType;

//ջ-˳��-��̬ ��ʼ��
Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

//ѹջ
void push(Stack* s, ElemType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("����\n");
        return;
    }

    s->top++;
    s->arr[s->top] = e;
}

//��ջ
void pop(Stack* s, ElemType* e)
{
    if (s->top == -1)
    {
        printf("�յ�\n");
        return;
    }
    *e = s->arr[s->top];
    s->top--;
}

//��ȡ�ַ�
contentType getToken(char* symbol, int* index)
{
    *symbol = expr[*index];
    *index = *index + 1;
    switch (*symbol)
    {
    case '(':
        return LEFT_PARE;
    case ')':
        return RIGHT_PARE;
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    case '\0': // ע�⣺�ַ���������
        return EOS;
    default:
        return NUM;
    }
}

//����
void eval(Stack* s)
{
    char symbol;
    int index = 0;
    int op1, op2;
    contentType token;
    token = getToken(&symbol, &index);
    ElemType result;
    while (token != EOS)
    {
        if (token == NUM)
        {
            push(s, symbol - '0');
        }
        else
        {
            pop(s, &op2);
            pop(s, &op1);

            switch (token)
            {
            case ADD:
                push(s, op1 + op2);
                break;
            case SUB:
                push(s, op1 - op2);
                break;
            case MUL:
                push(s, op1 * op2);
                break;
            case DIV:
                push(s, op1 / op2);
                break;
            case MOD:
                push(s, op1 % op2);
                break;
            default:
                break;
            }
        }
        token = getToken(&symbol, &index);
    }
    pop(s, &result);
    printf("%d\n", result);
}

int main()
{
    Stack* s = initStack();
    eval(s);

    return 0;
}





//��׺���ʽת��׺���ʽ
//�������������ж����ȼ���������ȼ�����ջ��Ԫ�أ���ѹ��ջ�У�����ջ��Ԫ�س�ջ�����Ȼ�󽫵�ǰ�����ѹ��ջ��
//����������ջ��ʱ������������ȼ�������������ջ��ʱ������������ȼ�
//����ǲ�������ֱ�����
//����������ţ���ջ��Ԫ�ز��������ţ�������ջ�������ֱ��ջ��Ϊ�����ų�ջ���������������Ҳ��ջ�������ų�ջ�ɲ������
//���ջ��Ԫ���������

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAXSIZE 100

typedef enum contentType
{
    LEFT_PARE, RIGHT_PARE,
    ADD, SUB, MUL, DIV, MOD,
    EOS, NUM
}contentType;

typedef struct Stack
{
    contentType* arr;//ע��
    int top;
}Stack;

char expr[] = "x/(i-j)*y";//��׺���ʽ

Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (contentType*)malloc(sizeof(contentType) * MAXSIZE);
    s->top = 0;
    s->arr[s->top] = EOS; // ջ��ΪEOS
    return s;
}

void push(Stack* s, contentType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("����\n");
        return;
    }
    s->top++;
    s->arr[s->top] = e;
}

void pop(Stack* s, contentType* e)
{
    if (s->top == 0)
    {
        printf("�յ�\n");
        return;
    }
    *e = s->arr[s->top];
    s->top--;
}

contentType getToken(char* symbol, int* index)
{
    *symbol = expr[*index];
    (*index)++;
    switch (*symbol)
    {
    case '(':
        return LEFT_PARE;
    case ')':
        return RIGHT_PARE;
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    case '\0':
        return EOS;
    default:
        return NUM;
    }
}

void token_print(contentType e)
{
    switch (e)
    {
    case ADD:
        printf("+");
        break;
    case SUB:
        printf("-");
        break;
    case MUL:
        printf("*");
        break;
    case DIV:
        printf("/");
        break;
    case MOD:
        printf("%%");
        break;
    default:
        return;
    }
}

void operate(Stack* s)
{
    char symbol;
    int index = 0;
    contentType token;
    // ���ȼ���
    int in_stack[] = { 0,19,12,12,13,13,13,0 };   // ջ�����ȼ�
    int out_stack[] = { 20,19,12,12,13,13,13,0 }; // ջ�����ȼ�
    contentType e;
    token = getToken(&symbol, &index);

    while (token != EOS)
    {
        if (token == NUM)
        {
            printf("%c", symbol);
        }
        else if (token == RIGHT_PARE)
        {
            while (s->arr[s->top] != LEFT_PARE)
            {
                pop(s, &e);
                token_print(e);
            }
            pop(s, &e); // ����������
        }
        else
        {
            while (out_stack[token] <= in_stack[s->arr[s->top]])
            {
                pop(s, &e);
                token_print(e);
            }
            push(s, token);
        }
        token = getToken(&symbol, &index);
    }
    // ���ջ��ʣ�������
    while (s->arr[s->top] != EOS)
    {
        pop(s, &e);
        token_print(e);
    }
}

int main()
{
    Stack* s = initStack();
    printf("%s\n", expr);
    operate(s);
    free(s->arr);
    free(s);
    return 0;
}



