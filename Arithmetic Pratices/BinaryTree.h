#pragma once
#include<iostream>
#define COLOR_RED 0
#define COLOR_BLA 1
using namespace std;
class BinaryTreeNode;
typedef BinaryTreeNode* ptrBTN;
//二叉树节点定义
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
//二叉树定义
class BinaryTree
{
public:
	bool create(int);						//创建树
	virtual bool isEmpty();					//判断树是否空
	ptrBTN getRoot();						//获取根节点
	void setRoot(ptrBTN);					//设置根节点
	void clear();							//清空树
	virtual void clear(ptrBTN);				//清空子树
	int height(ptrBTN);						//计算子树的高度
	int height();							//计算树的高度
	int sum(ptrBTN);						//计算子树的节点数
	int sum();								//计算树的节点数
	ptrBTN getParent(ptrBTN);				//获取父节点
	ptrBTN getLeftChild(ptrBTN);			//返回某节点左子树
	ptrBTN getRightChild(ptrBTN);			//返回某节点右子树
	void insertLeftChild(ptrBTN, ptrBTN);	//给某节点插入左子树
	void insertRightChild(ptrBTN, ptrBTN);	//给某节点插入右子树
	virtual void preVisit();				//先序遍历
	virtual void midVisit();				//中序遍历
	virtual void postVisit();				//后序遍历
	virtual ptrBTN successor(ptrBTN);		//查找后继
	virtual ptrBTN predecessor(ptrBTN);		//查找前驱
	virtual ptrBTN minimum(ptrBTN);			//子树最小
	virtual ptrBTN maximum(ptrBTN);			//子树最大
private:
	virtual void preVisit(ptrBTN);			//先序遍历
	virtual void midVisit(ptrBTN);			//中序遍历
	virtual void postVisit(ptrBTN);			//后序遍历
public:
	BinaryTree();
	~BinaryTree();
private:
	ptrBTN root;
};
