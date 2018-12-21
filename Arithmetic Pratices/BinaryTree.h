#pragma once
#include<iostream>
#define COLOR_RED 0
#define COLOR_BLA 1
using namespace std;
class BinaryTreeNode;
typedef BinaryTreeNode* ptrBTN;
//�������ڵ㶨��
class BinaryTreeNode
{
private:
	int data;
	int color;
	ptrBTN parent;
	ptrBTN leftChild;
	ptrBTN rightChild;
public:
	void setParent(ptrBTN);
	void setData(int);
	void setColor(int);
	void setLeftChild(ptrBTN);
	void setRightChild(ptrBTN);
	int getData();
	int getColor();
	ptrBTN getParent();
	ptrBTN getLeftChild();
	ptrBTN getRightChild();
	BinaryTreeNode();
	BinaryTreeNode(int);
	~BinaryTreeNode();
};
//����������
class BinaryTree
{
public:
	bool create(int);						//������
	virtual bool isEmpty();					//�ж����Ƿ��
	ptrBTN getRoot();						//��ȡ���ڵ�
	void setRoot(ptrBTN);					//���ø��ڵ�
	void clear();							//�����
	virtual void clear(ptrBTN);				//�������
	int height(ptrBTN);						//���������ĸ߶�
	int height();							//�������ĸ߶�
	int sum(ptrBTN);						//���������Ľڵ���
	int sum();								//�������Ľڵ���
	ptrBTN getParent(ptrBTN);				//��ȡ���ڵ�
	ptrBTN getLeftChild(ptrBTN);			//����ĳ�ڵ�������
	ptrBTN getRightChild(ptrBTN);			//����ĳ�ڵ�������
	void insertLeftChild(ptrBTN, ptrBTN);	//��ĳ�ڵ����������
	void insertRightChild(ptrBTN, ptrBTN);	//��ĳ�ڵ����������
	virtual void preVisit();				//�������
	virtual void midVisit();				//�������
	virtual void postVisit();				//�������
	virtual ptrBTN successor(ptrBTN);		//���Һ��
	virtual ptrBTN predecessor(ptrBTN);		//����ǰ��
	virtual ptrBTN minimum(ptrBTN);			//������С
	virtual ptrBTN maximum(ptrBTN);			//�������
private:
	virtual void preVisit(ptrBTN);			//�������
	virtual void midVisit(ptrBTN);			//�������
	virtual void postVisit(ptrBTN);			//�������
public:
	BinaryTree();
	~BinaryTree();
private:
	ptrBTN root;
};
