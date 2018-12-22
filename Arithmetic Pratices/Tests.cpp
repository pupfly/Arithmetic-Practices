#include "Tests.h"

void TestSorts()
{
	int t[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	PrintArray(t, GET_ARRAY_ELEMENTS_NUM(t), "数组t原始数据：");
	MergeSort(t, 0, GET_ARRAY_ELEMENTS_NUM(t) - 1);
	PrintArray(t, GET_ARRAY_ELEMENTS_NUM(t), "数组t归并排序结果：");
	int t1[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	BubbleSort(t1, GET_ARRAY_ELEMENTS_NUM(t1));
	PrintArray(t1, GET_ARRAY_ELEMENTS_NUM(t1), "数组t1冒泡排序结果：");
	int t2[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	ShellSort(t2, GET_ARRAY_ELEMENTS_NUM(t2));
	PrintArray(t2, GET_ARRAY_ELEMENTS_NUM(t2), "数组t2希尔排序结果：");
	int t3[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	QuickSort(t3, 0, GET_ARRAY_ELEMENTS_NUM(t3) - 1);
	PrintArray(t3, GET_ARRAY_ELEMENTS_NUM(t3), "数组t3快排结果：");
	int t4[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	SelectSort(t4, GET_ARRAY_ELEMENTS_NUM(t4));
	PrintArray(t4, GET_ARRAY_ELEMENTS_NUM(t4), "数组t4选择排序结果：");
}

void TestSearch()
{
	int x, y;
	int key = 13;
	bool r;
	int a[][7] = { { 1,2,8,9,15,22,38 },{ 2,5,9,12,16,25,42 },{ 4,7,13,15,21,28,46 },{ 7,9,16,18,24,32,52 } };
	r = YoungSearchDir(a, key, 7, 4, x, y);
	if (r)
	{
		cout << "方法：YoungSearchDir找到：" << key << ",位置：（" << x << "," << y << "）" << endl;
	}
	r = YoungSearch(a, key, 7, 4, x, y);
	if (r)
	{
		cout << "方法：YoungSearch 找到：" << key << ",位置：（" << x << "," << y << "）" << endl;
	}
}

void TestBinaryTree()
{
	BinarySearchTree r;
	cout << "测试二叉搜索树：" << endl;
	int d[] = { 5,3,8,2,4,1,10,6,7,9 };
	for (int i = 0; i < GET_ARRAY_ELEMENTS_NUM(d); i++)
	{
		r.insertDir(d[i]);
		cout << "插入数据：" << d[i] << endl;
	}
	cout << "先序遍历：" << endl;
	r.preVisit();
	cout << endl << "中序遍历：" << endl;
	r.midVisit();
	cout << endl << "后序遍历：" << endl;
	r.postVisit();
	cout << endl;
	cout << "测试搜索：" << endl;
	int t_d = 8;
	ptrBTN t = r.search(t_d);
	if (t != nullptr)
	{
		cout << "找到位置：" << t << "，内容：" << t->getData() << endl;
		ptrBTN tt = r.getParent(t);
		cout << "测试getParent():" << endl;
		cout << "找到：" << t->getData() << " 的父节点：" << tt << ",节点数据：" << tt->getData() << endl;
	}
	else
	{
		cout << "未找到：" << t_d << endl;
	}
	cout << "测试后继查找：" << endl;
	cout << "找到：" << t_d << "的后继为：" << r.successor(r.search(t_d)) << ",节点数据：" << (r.successor(r.search(t_d)) != nullptr ? r.successor(r.search(t_d))->getData() : 0) << endl;
	cout << "测试前驱查找：" << endl;
	cout << "找到：" << t_d << "的前驱为：" << r.predecessor(r.search(t_d)) << ",节点数据：" << (r.predecessor(r.search(t_d)) != nullptr ? r.predecessor(r.search(t_d))->getData() : 0) << endl;
	cout << "测试删除：" << endl;
	bool dr = r.del(t_d);
	cout << "删除：" << t_d << "的结果：" << dr << endl;
	cout << "删除后的树先序遍历：" << endl;
	r.preVisit();
	cout << endl;
	cout << "删除后的树中序遍历：" << endl;
	r.midVisit();
	cout << endl;
	cout << "删除后的树后序遍历：" << endl;
	r.postVisit();
	cout << endl;
}

void TestRBTree()
{
	RBTree r;
	cout << "测试红黑树：" << endl;
	int d[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < GET_ARRAY_ELEMENTS_NUM(d); i++)
	{
		r.insert(d[i]);
		cout << "插入数据：" << d[i] << endl;
	}
	cout << "先序遍历：" << endl;
	r.preVisit();
	cout << endl << "中序遍历：" << endl;
	r.midVisit();
	cout << endl << "后序遍历：" << endl;
	r.postVisit();
	cout << endl;
	cout << "测试搜索：" << endl;
	int t_d = 41;
	ptrBTN t = r.search(t_d);
	if (t != r.getNil())
	{
		cout << "找到位置：" << t << "，内容：" << t->getData() << endl;
		ptrBTN tt = r.getParent(t);
		cout << "测试getParent():" << endl;
		cout << "找到：" << t->getData() << " 的父节点：" << tt << ",节点数据：" << tt->getData() << endl;
	}
	else
	{
		cout << "未找到：" << t_d << endl;
	}
	cout << "测试后继查找：" << endl;
	cout << "找到：" << t_d << "的后继为：" << r.successor(r.search(t_d)) << ",节点数据：" << (r.successor(r.search(t_d)) != r.getNil() ? r.successor(r.search(t_d))->getData() : 0) << endl;
	cout << "测试前驱查找：" << endl;
	cout << "找到：" << t_d << "的前驱为：" << r.predecessor(r.search(t_d)) << ",节点数据：" << (r.predecessor(r.search(t_d)) != r.getNil() ? r.predecessor(r.search(t_d))->getData() : 0) << endl;
	cout << "测试删除：" << endl;
	bool dr = r.del(t_d);
	cout << "删除：" << t_d << "的结果：" << dr << endl;
	cout << "删除后的树先序遍历：" << endl;
	r.preVisit();
	cout << endl;
	cout << "删除后的树中序遍历：" << endl;
	r.midVisit();
	cout << endl;
	cout << "删除后的树后序遍历：" << endl;
	r.postVisit();
	cout << endl;
}

void TestDynamicProgramming()
{
	//在下面的数组中给出测试信息
	cout << "测试矩阵链乘最优全括号方案动态规划：" << endl;
	int MatrixDimension[] = { 30,35,15,5,10,20,25 };
	PrintArray(MatrixDimension, GET_ARRAY_ELEMENTS_NUM(MatrixDimension), "矩阵维度信息:");
	MaxChainOrder(MatrixDimension, GET_ARRAY_ELEMENTS_NUM(MatrixDimension) - 1);
	cout << endl;
	cout << "测试最长公共子序列动态规划：" << endl;
	LCS_Length("abcdefg", "aebtcyduehf");
	cout << endl;
	cout << "测试最优二叉搜索树动态规划：" << endl;
	OptimalBST({ 0.15, 0.10, 0.05, 0.10, 0.20 }, { 0.05,0.10,0.05,0.05,0.05,0.10 });
}
