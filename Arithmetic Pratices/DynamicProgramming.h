#pragma once
#include <climits>
#ifndef MY_INFINITE
#define MY_INFINITE INT_MAX
#endif // !MY_INFINITE
#include <iostream>
#define DIR_UP			0
#define DIR_LEFT		1
#define DIR_DIAgonal	2
//�����������ż�ȫ���ŷ���
void MaxChainOrder(int p[], int n);
void PrintMatrixParenthesis(int**, int**, int, int);
//����������еļ���
void LCS_Length(char *, char *);
void PrintLCS(int**, char*, int, int);