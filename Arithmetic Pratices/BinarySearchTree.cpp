#include "BinarySearchTree.h"

ptrBTN BinarySearchTree::insert(int d)
{
	if (isEmpty())
	{
		create(d);
		return getRoot();
	}
	else
	{
		return insert(getRoot(), d);
	}
}

ptrBTN BinarySearchTree::insertDir(int d)
{
	ptrBTN y = nullptr;
	ptrBTN x = getRoot();
	//寻找插入点
	while (x != nullptr)
	{
		y = x;
		if (x->getData() < d)
			x = x->getRightChild();
		else
			x = x->getLeftChild();
	}
	//判断是否为空树
	if (y == nullptr)
	{
		create(d);
		return getRoot();
	}
	else 
	{//插入数据
		ptrBTN n = new BinaryTreeNode;
		n->setData(d);
		if (y->getData() > d)
		{
			y->setLeftChild(n);
		}
		else
		{
			y->setRightChild(n);
		}
		return n;
	}	
}

ptrBTN BinarySearchTree::search(int d)
{
	return search(getRoot(), d);
}

bool BinarySearchTree::del(int d)
{
	ptrBTN n = search(d);
	if (n == nullptr)
	{
		return false;
	}
	ptrBTN x, y;
	if (n->getLeftChild() == nullptr || n->getRightChild() == nullptr)
	{
		y = n;
	}
	else
	{
		y = successor(n);
	}
	if (y->getLeftChild() != nullptr)
	{
		x = y->getLeftChild();
	}
	else
	{
		x = y->getRightChild();
	}
	if (getParent(y) == nullptr)
	{
		setRoot(x);
	}
	else if(y == getParent(y)->getLeftChild())
	{
		getParent(y)->setLeftChild(x);
	}
	else
	{
		getParent(y)->setRightChild(x);
	}
	if (y != n)
	{
		n->setData(y->getData());
	}
	//防止如果是红黑树，要将树根的父节点设置为nil
	if (x != nullptr)
	{
		x->setParent(y->getParent());
	}
	delete y;
	return true;
}

ptrBTN BinarySearchTree::search(ptrBTN p, int d)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	else if (p->getData() == d)
	{
		return p;
	}
	else if (p->getData() < d)
	{
		return search(p->getRightChild(), d);
	}
	else
	{
		return search(p->getLeftChild(), d);
	}
}

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
}

ptrBTN BinarySearchTree::insert(ptrBTN n, int d)
{
	if (d > n->getData())
	{
		if (n->getRightChild() == nullptr)
		{
			ptrBTN p = new BinaryTreeNode;
			p->setData(d);
			n->setRightChild(p);
			return p;
		}
		else
		{
			return insert(n->getRightChild(), d);
		}
	}
	else
	{
		if (n->getLeftChild() == nullptr)
		{
			ptrBTN p = new BinaryTreeNode;
			p->setData(d);
			n->setLeftChild(p);
			return p;
		}
		else
		{
			return insert(n->getLeftChild(), d);
		}
	}
}
