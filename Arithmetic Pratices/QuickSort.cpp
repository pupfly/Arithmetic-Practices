#include "QuickSort.h"

int particion(int a[], int p, int r)
{
	int j = r - 1;//默认最后一个数据为参照
	int i = p;
	while (i < j)
	{
		while (a[j] >= a[r] && j > i) j--;
		while (a[i] <= a[r] && i < j) i++;
		if (i == j)
		{
			break;
		}
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	if (a[i] > a[r])
	{
		int temp = a[r];
		a[r] = a[i];
		a[i] = temp;
	}
	return i;
}

void QuickSort(int a[], int p, int r)
{
	if (p == r)
	{
		return;
	}
	int q = particion(a, p, r);
	QuickSort(a, p, q);
	QuickSort(a, q + 1, r);
}
