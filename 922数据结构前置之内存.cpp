#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
//�ڴ���ࣺ
// 
//C�������󣬻���������ʽʹ���ڴ棺
//1.��̬/ȫ���ڴ�
//��̬�����ı�����ȫ�ֱ���ʹ���ⲿ���ڴ棬��Щ�����ڳ���ʼ����ʱ���䣬ֱ�������ղ���ʧ
//2.�Զ��ڴ棨ջ�ڴ棩
//�����ڲ������ı���ʹ���ⲿ���ڴ棬�ں���������ʱ�Ŵ���
//3.��̬�ڴ棨���ڴ棩
//���������д���붯̬�����ڴ棬���Ա�д�����ͷţ��ڴ��е�����ֱ���ͷŲ���ʧ

//��̬�ڴ����
//��C�����У���̬�����ڴ�Ļ������裺
//1.ʹ��malloc(memory allocate)���������ڴ棬malloc�������������ڶ��ڴ��п���һƬ�ռ䣬�Ե�ַ����
//void* malloc(size_t size)
//����ɹ����᷵�شӶ��ڴ��Ϸ�����ڴ�ָ��
//���ʧ�ܣ��᷵�ؿ�ָ��
//ע��sizeof�ķ���ֵ���;���size_t  ͨ�����%zu
//ע��void* ��ʾ����һ��ͨ���������͵�ָ��,���ǿ����ڽӵ�����ֵʱ��һ��ǿ��ת��

//2.ʹ�÷�����ڴ�

//3.ʹ��free�����ͷ��ڴ�

//����
int main()
{
    int* p = (int*)malloc(sizeof(int));
    if (p == NULL) // ��� malloc �Ƿ�ɹ������ڴ�
    {
        printf("�ڴ����ʧ��\n");
        return -1; // ���ش�����
    }
    *p = 15;
    printf("%d\n", *p);
    free(p);

    return 0;
}

int main()
{
    char* s;
    s = (char*)malloc(sizeof(10));//����10���ֽڵĿռ�
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
    po* p = (po*)malloc(sizeof(po));//�ṹ��������ڴ���ռ�ö����ֽڣ��漰��λ�ĸ���
    p->x = 5;
    p->y = 10;
    cout << p->x << " " << p->y;

    return 0;
}
//�Ƽ��飺�������Cָ��


