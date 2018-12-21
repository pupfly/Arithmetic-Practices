#include "BubbleSort.h"

void BubbleSort(int a[], int len)
{
	int temp;
	for (int i = 1; i < len; i++)
	{
		for(int j = 0;j < len - i;j++)
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	}
}
