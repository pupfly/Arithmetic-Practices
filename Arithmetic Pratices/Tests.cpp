#include "Tests.h"

void TestSorts()
{
	int t[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	PrintArray(t, GET_ARRAY_ELEMENTS_NUM(t), "����tԭʼ���ݣ�");
	MergeSort(t, 0, GET_ARRAY_ELEMENTS_NUM(t) - 1);
	PrintArray(t, GET_ARRAY_ELEMENTS_NUM(t), "����t�鲢��������");
	int t1[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	BubbleSort(t1, GET_ARRAY_ELEMENTS_NUM(t1));
	PrintArray(t1, GET_ARRAY_ELEMENTS_NUM(t1), "����t1ð����������");
	int t2[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	ShellSort(t2, GET_ARRAY_ELEMENTS_NUM(t2));
	PrintArray(t2, GET_ARRAY_ELEMENTS_NUM(t2), "����t2ϣ����������");
	int t3[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	QuickSort(t3, 0, GET_ARRAY_ELEMENTS_NUM(t3) - 1);
	PrintArray(t3, GET_ARRAY_ELEMENTS_NUM(t3), "����t3���Ž����");
	int t4[] = { 1,2,5,4,8,6,9,2,10,2,4,1,2,-9,12,-7,3,5,2,1,5,2,8,-12 };
	SelectSort(t4, GET_ARRAY_ELEMENTS_NUM(t4));
	PrintArray(t4, GET_ARRAY_ELEMENTS_NUM(t4), "����t4ѡ����������");
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
		cout << "������YoungSearchDir�ҵ���" << key << ",λ�ã���" << x << "," << y << "��" << endl;
	}
	r = YoungSearch(a, key, 7, 4, x, y);
	if (r)
	{
		cout << "������YoungSearch �ҵ���" << key << ",λ�ã���" << x << "," << y << "��" << endl;
	}
}

void TestBinaryTree()
{
	BinarySearchTree r;
	cout << "���Զ�����������" << endl;
	int d[] = { 5,3,8,2,4,1,10,6,7,9 };
	for (int i = 0; i < GET_ARRAY_ELEMENTS_NUM(d); i++)
	{
		r.insertDir(d[i]);
		cout << "�������ݣ�" << d[i] << endl;
	}
	cout << "���������" << endl;
	r.preVisit();
	cout << endl << "���������" << endl;
	r.midVisit();
	cout << endl << "���������" << endl;
	r.postVisit();
	cout << endl;
	cout << "����������" << endl;
	int t_d = 8;
	ptrBTN t = r.search(t_d);
	if (t != nullptr)
	{
		cout << "�ҵ�λ�ã�" << t << "�����ݣ�" << t->getData() << endl;
		ptrBTN tt = r.getParent(t);
		cout << "����getParent():" << endl;
		cout << "�ҵ���" << t->getData() << " �ĸ��ڵ㣺" << tt << ",�ڵ����ݣ�" << tt->getData() << endl;
	}
	else
	{
		cout << "δ�ҵ���" << t_d << endl;
	}
	cout << "���Ժ�̲��ң�" << endl;
	cout << "�ҵ���" << t_d << "�ĺ��Ϊ��" << r.successor(r.search(t_d)) << ",�ڵ����ݣ�" << (r.successor(r.search(t_d)) != nullptr ? r.successor(r.search(t_d))->getData() : 0) << endl;
	cout << "����ǰ�����ң�" << endl;
	cout << "�ҵ���" << t_d << "��ǰ��Ϊ��" << r.predecessor(r.search(t_d)) << ",�ڵ����ݣ�" << (r.predecessor(r.search(t_d)) != nullptr ? r.predecessor(r.search(t_d))->getData() : 0) << endl;
	cout << "����ɾ����" << endl;
	bool dr = r.del(t_d);
	cout << "ɾ����" << t_d << "�Ľ����" << dr << endl;
	cout << "ɾ����������������" << endl;
	r.preVisit();
	cout << endl;
	cout << "ɾ����������������" << endl;
	r.midVisit();
	cout << endl;
	cout << "ɾ����������������" << endl;
	r.postVisit();
	cout << endl;
}

void TestRBTree()
{
	RBTree r;
	cout << "���Ժ������" << endl;
	int d[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < GET_ARRAY_ELEMENTS_NUM(d); i++)
	{
		r.insert(d[i]);
		cout << "�������ݣ�" << d[i] << endl;
	}
	cout << "���������" << endl;
	r.preVisit();
	cout << endl << "���������" << endl;
	r.midVisit();
	cout << endl << "���������" << endl;
	r.postVisit();
	cout << endl;
	cout << "����������" << endl;
	int t_d = 41;
	ptrBTN t = r.search(t_d);
	if (t != r.getNil())
	{
		cout << "�ҵ�λ�ã�" << t << "�����ݣ�" << t->getData() << endl;
		ptrBTN tt = r.getParent(t);
		cout << "����getParent():" << endl;
		cout << "�ҵ���" << t->getData() << " �ĸ��ڵ㣺" << tt << ",�ڵ����ݣ�" << tt->getData() << endl;
	}
	else
	{
		cout << "δ�ҵ���" << t_d << endl;
	}
	cout << "���Ժ�̲��ң�" << endl;
	cout << "�ҵ���" << t_d << "�ĺ��Ϊ��" << r.successor(r.search(t_d)) << ",�ڵ����ݣ�" << (r.successor(r.search(t_d)) != r.getNil() ? r.successor(r.search(t_d))->getData() : 0) << endl;
	cout << "����ǰ�����ң�" << endl;
	cout << "�ҵ���" << t_d << "��ǰ��Ϊ��" << r.predecessor(r.search(t_d)) << ",�ڵ����ݣ�" << (r.predecessor(r.search(t_d)) != r.getNil() ? r.predecessor(r.search(t_d))->getData() : 0) << endl;
	cout << "����ɾ����" << endl;
	bool dr = r.del(t_d);
	cout << "ɾ����" << t_d << "�Ľ����" << dr << endl;
	cout << "ɾ����������������" << endl;
	r.preVisit();
	cout << endl;
	cout << "ɾ����������������" << endl;
	r.midVisit();
	cout << endl;
	cout << "ɾ����������������" << endl;
	r.postVisit();
	cout << endl;
}

void TestDynamicProgramming()
{
	//������������и���������Ϣ
	cout << "���Ծ�����������ȫ���ŷ�����̬�滮��" << endl;
	int MatrixDimension[] = { 30,35,15,5,10,20,25 };
	PrintArray(MatrixDimension, GET_ARRAY_ELEMENTS_NUM(MatrixDimension), "����ά����Ϣ:");
	MaxChainOrder(MatrixDimension, GET_ARRAY_ELEMENTS_NUM(MatrixDimension) - 1);
	cout << endl;
	cout << "��������������ж�̬�滮��" << endl;
	LCS_Length("abcdefg", "aebtcyduehf");
	cout << endl;
	cout << "�������Ŷ�����������̬�滮��" << endl;
	OptimalBST({ 0.15, 0.10, 0.05, 0.10, 0.20 }, { 0.05,0.10,0.05,0.05,0.05,0.10 });
}
