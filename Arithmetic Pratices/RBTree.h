#pragma once
#include "BinarySearchTree.h"
//红黑树声明
class RBTree : public BinarySearchTree
{
private:
	static ptrBTN nil;
public:
	virtual bool isEmpty();					//判断树是否空
	ptrBTN insert(int);
	virtual bool del(int);					//删除数据
	virtual ptrBTN search(int);				//查找数据
	ptrBTN getNil();						//nil有时会被外部代码当做哨兵使用
	void leftRotate(ptrBTN);
	void rightRotate(ptrBTN);
	void fixInsert(ptrBTN);					//插入修正
	void fixDel(ptrBTN);					//删除修正
	virtual void clear(ptrBTN);				//清空子树
	void preVisit();						//先序遍历
	void midVisit();						//中序遍历
	void postVisit();						//后序遍历
	virtual ptrBTN successor(ptrBTN);		//查找后继
	virtual ptrBTN predecessor(ptrBTN);		//查找前驱
	virtual ptrBTN minimum(ptrBTN);			//子树最小
	virtual ptrBTN maximum(ptrBTN);			//子树最大
private:
	void preVisit(ptrBTN);					//先序遍历
	void midVisit(ptrBTN);					//中序遍历
	void postVisit(ptrBTN);					//后序遍历
	virtual ptrBTN search(ptrBTN, int);		//查找数据
public:
	RBTree();
	~RBTree();
};