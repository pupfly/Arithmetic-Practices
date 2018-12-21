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