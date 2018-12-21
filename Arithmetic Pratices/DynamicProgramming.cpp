#include "DynamicProgramming.h"
using namespace std;
void MaxChainOrder(int p[], int n)
{
	//下面申请的两个动态数组的第0个元素都不使用
	//动态申请整型数组m[n][n]
	int **m = new int*[n + 1];				//m为指针数组，每一个元素都是一个整型指针
	for (int i = 0; i < n + 1; i++)			
	{
		m[i] = new int[n + 1];				//m[i]指向一个整型数组
	}
	//动态申请整型数组s[n][n]
	int **s = new int*[n + 1];				//s为指针数组，每一个元素都是一个整型指针
	for (int i = 0; i < n + 1; i++)
	{
		s[i] = new int[n + 1];				//s[i]指向一个整型数组
	}
	//TODO:在此放置动态规划代码
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;
			m[i][j] = MY_INFINITE;
			for (int k = i; k <= j - 1; k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	//打印结果
	cout << "最优全括号方案：" << endl;
	PrintMatrixParenthesis(m, s, 1, n);
	//销毁整型数组m[n][n]
	for (int i = 0; i < n + 1; i++)
	{
		delete[] m[i];
	}
	delete[] m;
	//销毁整型数组s[n][n]
	for (int i = 0; i < n + 1; i++)
	{
		delete[] s[i];
	}
	delete[] s;
}

void PrintMatrixParenthesis(int **m, int **s, int i, int j)
{
	if (i == j)
	{
		cout << "A" << i;
	}
	else
	{
		cout << "(";
		PrintMatrixParenthesis(m, s, i, s[i][j]);
		PrintMatrixParenthesis(m, s, s[i][j] + 1, j);
		cout << ")";
	}
}