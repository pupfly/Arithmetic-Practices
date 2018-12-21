#pragma once
#include "BinaryTree.h"
//二叉搜索树定义
class BinarySearchTree : public BinaryTree
{
public:
	virtual ptrBTN insert(int);				//插入数据
	virtual ptrBTN insertDir(int);			//插入数据
	virtual ptrBTN search(int);				//查找数据
	virtual bool del(int);					//删除数据
public:
	BinarySearchTree();
	~BinarySearchTree();
private:
	virtual ptrBTN insert(ptrBTN, int);
	virtual ptrBTN search(ptrBTN, int);		//查找数据
};