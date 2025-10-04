#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//1.递归求1-n之和
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

//2.递归求斐波那契数列
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);

}
