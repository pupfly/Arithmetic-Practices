#include "ShellSort.h"

void ShellSort(int a[], int len)
{
	int temp;
	for (int k = len / 2; k > 0; k /= 2)
	{
		for (int i = k; i < len; i++)
		{
			for (int j = i; j >= k; j -= k)
			{
				if (a[j] < a[j - k])
				{
					temp = a[j];
					a[j] = a[j - k];
					a[j - k] = temp;
				}
			}
		}
	}
}
