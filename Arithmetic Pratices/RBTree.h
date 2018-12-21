#pragma once
#include "BinarySearchTree.h"
//���������
class RBTree : public BinarySearchTree
{
private:
	static ptrBTN nil;
public:
	virtual bool isEmpty();					//�ж����Ƿ��
	ptrBTN insert(int);
	virtual bool del(int);					//ɾ������
	virtual ptrBTN search(int);				//��������
	ptrBTN getNil();						//nil��ʱ�ᱻ�ⲿ���뵱���ڱ�ʹ��
	void leftRotate(ptrBTN);
	void rightRotate(ptrBTN);
	void fixInsert(ptrBTN);					//��������
	void fixDel(ptrBTN);					//ɾ������
	virtual void clear(ptrBTN);				//�������
	void preVisit();						//�������
	void midVisit();						//�������
	void postVisit();						//�������
	virtual ptrBTN successor(ptrBTN);		//���Һ��
	virtual ptrBTN predecessor(ptrBTN);		//����ǰ��
	virtual ptrBTN minimum(ptrBTN);			//������С
	virtual ptrBTN maximum(ptrBTN);			//�������
private:
	void preVisit(ptrBTN);					//�������
	void midVisit(ptrBTN);					//�������
	void postVisit(ptrBTN);					//�������
	virtual ptrBTN search(ptrBTN, int);		//��������
public:
	RBTree();
	~RBTree();
};