#include "NumberTheory.h"

int EuclidGCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return EuclidGCD(b, a % b);
	}
}

void ExtendedEuclidGCD(int& d, int& x, int& y, int a, int b)
{
	if (b == 0)
	{
		d = a, x = 1, y = 0;
		return;
	}
	ExtendedEuclidGCD(d, x, y, b, a % b);
	int t = x;
	x = y;
	y = t - a / b * y;
	return;
}
