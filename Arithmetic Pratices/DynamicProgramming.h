#pragma once
#include <climits>
#include <string>
#include <vector>
#ifndef MY_INFINITE
#define MY_INFINITE INT_MAX
#endif // !MY_INFINITE
#include <iostream>
#define DIR_UP			0
#define DIR_LEFT		1
#define DIR_DIAgonal	2
using namespace std;
//矩阵链乘最优加全括号方案
void MaxChainOrder(int p[], int n);
void PrintMatrixParenthesis(int**, int**, int, int);
//最长公共子序列的计算
void LCS_Length(string, string);
void PrintLCS(int**, string, size_t, size_t);
//最优二叉查找树
void OptimalBST(vector<int>, vector<int>);