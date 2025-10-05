#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//枚举
//将变量的值一一列举出来，变量的值只限于列举出来的值的范围内
//在枚举中列出的每一个值，称为枚举元素
//每一个枚举元素由系统定义了一个用序号表示的数值，从0开始，分别为0，1，2，...
//语法：
//enum 枚举名
//{
//	枚举元素...
//};

enum week
{
	mon,tue,wed,thu,fri,sat,sun
//   0   1   2   3   4   5   6

//  mon=1, tue, wed, thu, fri, sat, sun           当写 mon=1 时 ，系统默认从1开始
//    1     2    3    4    5    6    7
};
typedef enum my_bool
{
	mt_false,my_true
//     0       1
}my_bool;//这一块与结构体一致
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
//后缀表达式求值
//遇到数字入栈，遇到字符出栈，然后计算结果，再将结果压回栈中
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

//栈-顺序-动态 初始化
Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

//压栈
void push(Stack* s, ElemType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("满了\n");
        return;
    }

    s->top++;
    s->arr[s->top] = e;
}

//出栈
void pop(Stack* s, ElemType* e)
{
    if (s->top == -1)
    {
        printf("空的\n");
        return;
    }
    *e = s->arr[s->top];
    s->top--;
}

//获取字符
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
    case '\0': // 注意：字符串结束符
        return EOS;
    default:
        return NUM;
    }
}

//处理
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





//中缀表达式转后缀表达式
//如果是运算符，判断优先级，如果优先级大于栈顶元素，则压入栈中；否则将栈顶元素出栈输出，然后将当前运算符压入栈中
//当左括号在栈外时，属于最高优先级，当左括号在栈里时，属于最低优先级
//如果是操作数，直接输出
//如果是右括号，且栈顶元素不是左括号，持续出栈并输出，直到栈顶为左括号出栈结束，最后将左括号也出栈（左括号出栈可不输出）
//最后将栈中元素依次输出

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
    contentType* arr;//注意
    int top;
}Stack;

char expr[] = "x/(i-j)*y";//中缀表达式

Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (contentType*)malloc(sizeof(contentType) * MAXSIZE);
    s->top = 0;
    s->arr[s->top] = EOS; // 栈底为EOS
    return s;
}

void push(Stack* s, contentType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("满了\n");
        return;
    }
    s->top++;
    s->arr[s->top] = e;
}

void pop(Stack* s, contentType* e)
{
    if (s->top == 0)
    {
        printf("空的\n");
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
    // 优先级表
    int in_stack[] = { 0,19,12,12,13,13,13,0 };   // 栈内优先级
    int out_stack[] = { 20,19,12,12,13,13,13,0 }; // 栈外优先级
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
            pop(s, &e); // 弹出左括号
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
    // 清空栈中剩余运算符
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



