#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//1.�ݹ���1-n֮��
int fun(int x)
{
	if (x > 1)
	{
		return fun(x - 1) + x;
	}
	else if (x == 1)
	{
		return 1;
	}

}

//2.�ݹ���쳲���������
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);

}
