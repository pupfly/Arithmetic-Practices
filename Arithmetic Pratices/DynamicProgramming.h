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
//�����������ż�ȫ���ŷ���
void MaxChainOrder(int p[], int n);
void PrintMatrixParenthesis(int**, int**, int, int);
//����������еļ���
void LCS_Length(string, string);
void PrintLCS(int**, string, size_t, size_t);
//���Ŷ��������
void OptimalBST(vector<double>, vector<double>);
void ConstructOptimalBST(int**, int, int);
//������ʽƥ��
bool isMatch(string s, string p);