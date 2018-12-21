#include "YoungSearch.h"
#include<iostream>

bool YoungSearch(int a[][7], int key, int w, int h, int& target_x, int& target_y, int x, int y)
{
	if (x < 0 || y < 0 || x >= h ||  y >= w)
	{
		return false;
	}
	if (a[x][y] == key)
	{
		target_x = x;
		target_y = y;
		return true;
	}
	int i = y;
	if (a[x][y] < key)
	{
		while (++i < w && a[x][i] < key);
		if (i == w)
		{
			return YoungSearch(a,key, w, h, target_x, target_y, x + 1, i - 1);
		}
		else if (a[x][i] == key)
		{
			target_x = x;
			target_y = i;
			return true;
		}
		else
		{
			return YoungSearch(a, key, w, h, target_x, target_y, x + 1, i);
		}
	}
	else
	{
		while (--i > -1 && a[x][i] > key);
		if (i == -1)
		{
			return YoungSearch(a, key, w, h, target_x, target_y, x + 1, i + 1);
		}
		else if (a[x][i] == key)
		{
			target_x = x;
			target_y = i;
			return true;
		}
		else
		{
			return YoungSearch(a, key, w, h, target_x, target_y, x + 1, i);
		}
	}
}

bool YoungSearchDir(int a[][7], int key, int w, int h, int & target_x, int & target_y)
{
	int x = 0;
	int y = w;
	while (x < h && y > -1)
	{
		while (--y > -1 && a[x][y] > key);
		if (y == -1 || a[x][y] == key)
		{
			break;
		}
		while (a[x][y] < key && ++x < h);
		if (x == h || a[x][y] == key)
		{
			break;
		}
	}
	if (x < h && y > -1 && a[x][y] == key)
	{
		target_x = x;
		target_y = y;
		return true;
	}
	return false;
}
