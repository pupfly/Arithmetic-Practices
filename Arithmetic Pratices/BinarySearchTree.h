#pragma once
#include "BinaryTree.h"
//��������������
class BinarySearchTree : public BinaryTree
{
public:
	virtual ptrBTN insert(int);				//��������
	virtual ptrBTN insertDir(int);			//��������
	virtual ptrBTN search(int);				//��������
	virtual bool del(int);					//ɾ������
public:
	BinarySearchTree();
	~BinarySearchTree();
private:
	virtual ptrBTN insert(ptrBTN, int);
	virtual ptrBTN search(ptrBTN, int);		//��������
};