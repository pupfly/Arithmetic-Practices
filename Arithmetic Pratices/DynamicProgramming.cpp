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

void LCS_Length(string x, string y)
{
	//下面申请的两个动态数组的第0个元素都不使用
	//动态申请整型数组c[m][n]
	size_t m = x.length();
	size_t n = y.length();
	int **c = new int*[m + 1];				//c为指针数组，每一个元素都是一个整型指针
	for (size_t i = 0; i < m + 1; i++)
	{
		c[i] = new int[n + 1];				//c[i]指向一个整型数组
	}
	//动态申请整型数组b[m][n]
	int **b = new int*[m + 1];				//b为指针数组，每一个元素都是一个整型指针
	for (size_t i = 0; i < m + 1; i++)
	{
		b[i] = new int[n + 1];				//b[i]指向一个整型数组
	}
	//TODO:在此放置动态规划代码
	for (size_t i = 1; i <= m; i++)
	{
		c[i][0] = 0;
	}
	for (size_t j = 0; j <= n; j++)
	{
		c[0][j] = 0;
	}
	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = DIR_DIAgonal;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = DIR_UP;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = DIR_LEFT;
			}
		}
	}
	//打印结果
	cout << "最长公共子序列长度：" << c[m][n] << endl;
	cout << "最长公共子序列内容：";
	PrintLCS(b, x, x.length(), y.length());
	//销毁整型数组c[m][n]
	for (size_t i = 0; i < m + 1; i++)
	{
		delete[] c[i];
	}
	delete[] c;
	//销毁整型数组b[m][n]
	for (size_t i = 0; i < m + 1; i++)
	{
		delete[] b[i];
	}
	delete[] b;
}

void PrintLCS(int **b, string x, size_t i, size_t j)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (b[i][j] == DIR_DIAgonal)
	{
		PrintLCS(b, x, i - 1, j - 1);
		cout << x[i - 1];
	}
	else if (b[i][j] == DIR_UP)
	{
		PrintLCS(b, x, i - 1, j);
	}
	else
	{
		PrintLCS(b, x, i, j - 1);
	}
}

//最优二叉查找树
void OptimalBST(vector<double> p, vector<double> q)
{
	int n = p.size();
	//动态申请整型数组e[n][n]
	double **e = new double*[n + 2];				//m为指针数组，每一个元素都是一个整型指针
	for (int i = 0; i <= n + 1; i++)
	{
		e[i] = new double[n + 1];				//m[i]指向一个整型数组
	}
	//动态申请整型数组w[n][n]
	double **w = new double*[n + 2];				//s为指针数组，每一个元素都是一个整型指针
	for (int i = 0; i <= n + 1; i++)
	{
		w[i] = new double[n + 1];				//s[i]指向一个整型数组
	}
	//动态申请整型数组root[n][n]
	int **root = new int*[n + 1];				//root为指针数组，每一个元素都是一个整型指针
	for (int i = 0; i <= n; i++)
	{
		root[i] = new int[n + 1];				//root[i]指向一个整型数组
	}
	//TODO:在此放置动态规划代码
	for (int i = 1; i <= n + 1; i++)
	{
		e[i][i - 1] = q[i - 1];
		w[i][i - 1] = q[i - 1];
	}
	for (int l = 1; l <= n; l++)
	{
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
			for (int r = i; r <= j; r++)
			{
				double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
				if (t < e[i][j])
				{
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
	//打印结果
	cout << "k" << root[1][n] << "是根" << endl;
	ConstructOptimalBST(root, 1, n);
	//销毁整型数组e[n][n]
	for (int i = 0; i <= n + 1; i++)
	{
		delete[] e[i];
	}
	delete[] e;
	//销毁整型数组w[n][n]
	for (int i = 0; i <= n + 1; i++)
	{
		delete[] w[i];
	}
	delete[] w;
	//销毁整型数组root[n][n]
	for (int i = 0; i <= n; i++)
	{
		delete[] root[i];
	}
	delete[] root;
}

void ConstructOptimalBST(int **root, int i, int j)
{
	if (root[i][j] > i && root[i][j] < j)
	{
		cout << "k" << root[i][root[i][j] - 1] << "是k" << root[i][j] << "的左孩子" << endl;
		ConstructOptimalBST(root, i, root[i][j] - 1);
		cout << "k" << root[root[i][j] + 1][j] << "是k" << root[i][j] << "的右孩子" << endl;
		ConstructOptimalBST(root, root[i][j] + 1, j);
	}
	else if (root[i][j] == i && root[i][j] == j)
	{
		cout << "d" << i - 1 << "是k" << i << "的左孩子" << endl;
		cout << "d" << i << "是k" << i << "的右孩子" << endl;
	}
	else if (root[i][j] == i)
	{
		cout << "k" << root[root[i][j] + 1][j] << "是k" << root[i][j] << "的右孩子" << endl;
		ConstructOptimalBST(root, root[i][j] + 1, j);
		cout << "d" << i - 1 << "是k" << i << "的左孩子" << endl;
	}
	else
	{
		cout << "k" << root[i][root[i][j] - 1] << "是k" << root[i][j] << "的左孩子" << endl;
		ConstructOptimalBST(root, i, root[i][j] - 1);
		cout << "d" << j << "是k" << j << "的右孩子" << endl;
	}
}
