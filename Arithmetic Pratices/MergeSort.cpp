#include "MergeSort.h"

void Merge(int a[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int* a1 = new int[n1 + 1];
	int* a2 = new int[n2 + 1];

	for (int i = 0; i < n1; i++)
	{
		a1[i] = a[p + i];
	}

	for (int i = 0; i < n2; i++)
	{
		a2[i] = a[q + 1 + i];
	}

	a2[n2] = a1[n1] = MY_INFINITE;

	int i1 = 0;
	int i2 = 0;

	for (int i = p; i <= r; i++)
	{
		if (a1[i1] <= a2[i2])
		{
			a[i] = a1[i1++];
		}
		else
		{
			a[i] = a2[i2++];
		}
	}
	delete[] a1, a2;
}

void MergeSort(int a[], int p, int r)
{
	if (p >= r)
	{
		return;
	}
	int q = (p + r) / 2;
	MergeSort(a, p, q);
	MergeSort(a, q + 1, r);
	Merge(a, p, q, r);
}
