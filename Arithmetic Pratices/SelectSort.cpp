#include "SelectSort.h"

void SelectSort(int a[], int size)
{
	for (int i = 0; i < size - 2; i++)
	{
		int max = i;
		for (int j = i; j < size - 1; j++)
		{
			if (a[j] > a[max])
			{
				max = j;
			}
		}
		if (max != i)
		{
			int t = a[i];
			a[i] = a[max];
			a[max] = t;
		}
	}
}
