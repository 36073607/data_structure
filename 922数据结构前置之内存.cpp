#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
//内存分类：
// 
//C程序编译后，会以三种形式使用内存：
//1.静态/全局内存
//静态声明的变量和全局变量使用这部分内存，这些变量在程序开始运行时分配，直到程序终才消失
//2.自动内存（栈内存）
//函数内部声明的变量使用这部分内存，在函数被调用时才创建
//3.动态内存（堆内存）
//根据需求编写代码动态分配内存，可以编写代码释放，内存中的内容直到释放才消失

//动态内存分配
//在C语言中，动态分配内存的基本步骤：
//1.使用malloc(memory allocate)函数分配内存，malloc帮助我们在内在堆内存中开辟一片空间，以地址返回
//void* malloc(size_t size)
//如果成功，会返回从堆内存上分配的内存指针
//如果失败，会返回空指针
//注：sizeof的返回值类型就是size_t  通配符：%zu
//注：void* 表示的是一个通用数据类型的指针,我们可以在接到返回值时做一个强制转换

//2.使用分配的内存

//3.使用free函数释放内存

//样例
int main()
{
    int* p = (int*)malloc(sizeof(int));
    if (p == NULL) // 检查 malloc 是否成功分配内存
    {
        printf("内存分配失败\n");
        return -1; // 返回错误码
    }
    *p = 15;
    printf("%d\n", *p);
    free(p);

    return 0;
}

int main()
{
    char* s;
    s = (char*)malloc(sizeof(10));//开辟10个字节的空间
    strcpy(s, "helloworld");
    printf("%s\n", s);

    return 0;
}

int main()
{
    int* arr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}

typedef struct
{
    int x;
    int y;
}po;
int main()
{
    po* p = (po*)malloc(sizeof(po));//结构体变量在内存中占用多少字节？涉及补位的概念
    p->x = 5;
    p->y = 10;
    cout << p->x << " " << p->y;

    return 0;
}
//推荐书：深入理解C指针


