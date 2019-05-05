#include "DynamicProgramming.h"
using namespace std;
void MaxChainOrder(int p[], int n)
{
	//���������������̬����ĵ�0��Ԫ�ض���ʹ��
	//��̬������������m[n][n]
	int **m = new int*[n + 1];				//mΪָ�����飬ÿһ��Ԫ�ض���һ������ָ��
	for (int i = 0; i < n + 1; i++)
	{
		m[i] = new int[n + 1];				//m[i]ָ��һ����������
	}
	//��̬������������s[n][n]
	int **s = new int*[n + 1];				//sΪָ�����飬ÿһ��Ԫ�ض���һ������ָ��
	for (int i = 0; i < n + 1; i++)
	{
		s[i] = new int[n + 1];				//s[i]ָ��һ����������
	}
	//TODO:�ڴ˷��ö�̬�滮����
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
	//��ӡ���
	cout << "����ȫ���ŷ�����" << endl;
	PrintMatrixParenthesis(m, s, 1, n);
	//������������m[n][n]
	for (int i = 0; i < n + 1; i++)
	{
		delete[] m[i];
	}
	delete[] m;
	//������������s[n][n]
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
	//���������������̬����ĵ�0��Ԫ�ض���ʹ��
	//��̬������������c[m][n]
	size_t m = x.length();
	size_t n = y.length();
	int **c = new int*[m + 1];				//cΪָ�����飬ÿһ��Ԫ�ض���һ������ָ��
	for (size_t i = 0; i < m + 1; i++)
	{
		c[i] = new int[n + 1];				//c[i]ָ��һ����������
	}
	//��̬������������b[m][n]
	int **b = new int*[m + 1];				//bΪָ�����飬ÿһ��Ԫ�ض���һ������ָ��
	for (size_t i = 0; i < m + 1; i++)
	{
		b[i] = new int[n + 1];				//b[i]ָ��һ����������
	}
	//TODO:�ڴ˷��ö�̬�滮����
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
	//��ӡ���
	cout << "����������г��ȣ�" << c[m][n] << endl;
	cout << "��������������ݣ�";
	PrintLCS(b, x, x.length(), y.length());
	//������������c[m][n]
	for (size_t i = 0; i < m + 1; i++)
	{
		delete[] c[i];
	}
	delete[] c;
	//������������b[m][n]
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

//���Ŷ��������
void OptimalBST(vector<int> p, vector<int> q)
{
	int n = (int)p.size();
	//��̬������������m[n][n]
	int **e = new int*[n + 2];				//mΪָ�����飬ÿһ��Ԫ�ض���һ������ָ��
	for (int i = 0; i <= n + 1; i++)
	{
		e[i] = new int[n + 1];				//m[i]ָ��һ����������
	}
	//��̬������������s[n][n]
	int **w = new int*[n + 1];				//sΪָ�����飬ÿһ��Ԫ�ض���һ������ָ��
	for (int i = 0; i <= n + 1; i++)
	{
		w[i] = new int[n + 1];				//s[i]ָ��һ����������
	}
	//TODO:�ڴ˷��ö�̬�滮����

	//������������m[n][n]
	for (int i = 0; i <= n + 1; i++)
	{
		delete[] e[i];
	}
	delete[] e;
	//������������s[n][n]
	for (int i = 0; i <= n + 1; i++)
	{
		delete[] w[i];
	}
	delete[] w;
}