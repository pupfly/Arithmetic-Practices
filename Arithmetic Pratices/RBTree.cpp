#include "RBTree.h"
ptrBTN RBTree::nil = new BinaryTreeNode(COLOR_BLA);
bool RBTree::isEmpty()
{
	return getRoot() == nil;
}
ptrBTN RBTree::insert(int d)
{
	ptrBTN p;
	ptrBTN y = nil;
	ptrBTN x = getRoot();
	//寻找插入点
	while (x != nil)
	{
		y = x;
		if (x->getData() < d)
			x = x->getRightChild();
		else
			x = x->getLeftChild();
	}
	//判断是否为空树
	if (y == nil)
	{
		create(d);
		getRoot()->setParent(nil);
		p = getRoot();
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
		p = n;
	}
	p->setLeftChild(nil);
	p->setRightChild(nil);
	//TODO：在此放置修正操作
	fixInsert(p);
	return p;
}

bool RBTree::del(int d)
{
	ptrBTN n = search(d);
	if (n == nil)
	{
		return false;
	}
	ptrBTN x, y;
	if (n->getLeftChild() == nil || n->getRightChild() == nil)
	{
		y = n;
	}
	else
	{
		y = successor(n);
	}
	if (y->getLeftChild() != nil)
	{
		x = y->getLeftChild();
	}
	else
	{
		x = y->getRightChild();
	}
	if (getParent(y) == nil)
	{
		setRoot(x);
	}
	else if (y == getParent(y)->getLeftChild())
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
	x->setParent(y->getParent());
	if (y->getColor() == COLOR_BLA)
	{//TODO:此处加入删除后的修正操作
		fixDel(x);
	}
	delete y;
	return true;
}

ptrBTN RBTree::search(int d)
{
	return search(getRoot(), d);
}

ptrBTN RBTree::getNil()
{
	return nil;
}

void RBTree::leftRotate(ptrBTN n)
{
	ptrBTN x = n->getRightChild();
	if (n->getParent()->getLeftChild() == n)
	{
		n->getParent()->setLeftChild(x);
	}
	else
	{
		n->getParent()->setRightChild(x);
	}
	//如果n为根，要重新设置根节点
	if (n->getParent() == nil)
	{
		setRoot(x);
	}
	//将x的左孩子设置为n的右孩子
	n->setRightChild(x->getLeftChild());
	//将n设置为x的左孩子
	x->setLeftChild(n);
}

void RBTree::rightRotate(ptrBTN n)
{
	ptrBTN x = n->getLeftChild();
	if (n->getParent()->getLeftChild() == n)
	{
		n->getParent()->setLeftChild(x);
	}
	else
	{
		n->getParent()->setRightChild(x);
	}
	//如果n为根，要重新设置根节点
	if (n->getParent() == nil)
	{
		setRoot(x);
	}
	//将x的右孩子设置为n的左孩子
	n->setLeftChild(x->getRightChild());
	//将n设置为x的右孩子
	x->setRightChild(n);
}

void RBTree::fixInsert(ptrBTN n)
{
	while (n->getParent()->getColor() == COLOR_RED)
	{
		if (n->getParent() == n->getParent()->getParent()->getLeftChild())
		{
			//不必检查n的祖父节点是否为null,循环体中n的父节点是红色，因而不会是根
			ptrBTN y = n->getParent()->getParent()->getRightChild();
			if (y->getColor() == COLOR_RED)
			{
				n->getParent()->setColor(COLOR_BLA);
				y->setColor(COLOR_BLA);
				n->getParent()->getParent()->setColor(COLOR_RED);
				n = n->getParent()->getParent();
				continue;
			}
			else if (n == n->getParent()->getRightChild())
			{
				n = n->getParent();
				leftRotate(n);
			}
			n->getParent()->setColor(COLOR_BLA);
			n->getParent()->getParent()->setColor(COLOR_RED);
			rightRotate(n->getParent()->getParent());
		}
		else
		{
			//不必检查n的祖父节点是否为null,循环体中n的父节点是红色，因而不会是根
			ptrBTN y = n->getParent()->getParent()->getLeftChild();
			if (y->getColor() == COLOR_RED)
			{
				n->getParent()->setColor(COLOR_BLA);
				y->setColor(COLOR_BLA);
				n->getParent()->getParent()->setColor(COLOR_RED);
				n = n->getParent()->getParent();
				continue;
			}
			else if (n == n->getParent()->getLeftChild())
			{
				n = n->getParent();
				rightRotate(n);
			}
			n->getParent()->setColor(COLOR_BLA);
			n->getParent()->getParent()->setColor(COLOR_RED);
			leftRotate(n->getParent()->getParent());
		}
	}
	getRoot()->setColor(COLOR_BLA);
}

void RBTree::fixDel(ptrBTN x)
{
	while (x != getRoot() && x->getColor() == COLOR_BLA)
	{
		if (x == x->getParent()->getLeftChild())
		{
			ptrBTN w = x->getParent()->getRightChild();
			if (w->getColor() == COLOR_RED)
			{
				w->setColor(COLOR_BLA);
				x->getParent()->setColor(COLOR_RED);
				leftRotate(x->getParent());
				w = x->getParent()->getRightChild();
			}
			if (w->getLeftChild()->getColor() == COLOR_BLA && w->getRightChild()->getColor() == COLOR_BLA)
			{
				w->setColor(COLOR_RED);
				x = x->getParent();
			}
			else if (w->getRightChild()->getColor() == COLOR_BLA)
			{
				w->getLeftChild()->setColor(COLOR_BLA);
				w->setColor(COLOR_RED);
				rightRotate(w);
				w = x->getParent()->getRightChild();
			}
			w->setColor(x->getParent()->getColor());
			x->getParent()->setColor(COLOR_BLA);
			w->getRightChild()->setColor(COLOR_BLA);
			leftRotate(x->getParent());
			x = getRoot();
		}
		else
		{
			ptrBTN w = x->getParent()->getLeftChild();
			if (w->getColor() == COLOR_RED)
			{
				w->setColor(COLOR_BLA);
				x->getParent()->setColor(COLOR_RED);
				rightRotate(x->getParent());
				w = x->getParent()->getLeftChild();
			}
			if (w->getRightChild()->getColor() == COLOR_BLA && w->getLeftChild()->getColor() == COLOR_BLA)
			{
				w->setColor(COLOR_RED);
				x = x->getParent();
			}
			else if (w->getLeftChild()->getColor() == COLOR_BLA)
			{
				w->getRightChild()->setColor(COLOR_BLA);
				w->setColor(COLOR_RED);
				leftRotate(w);
				w = x->getParent()->getLeftChild();
			}
			w->setColor(x->getParent()->getColor());
			x->getParent()->setColor(COLOR_BLA);
			w->getLeftChild()->setColor(COLOR_BLA);
			rightRotate(x->getParent());
			x = getRoot();
		}
	}
	x->setColor(COLOR_BLA);
}

void RBTree::clear(ptrBTN p)
{
	if (p != nil)
	{
		clear(p->getLeftChild());
		clear(p->getRightChild());
		delete p;
	}
}

void RBTree::preVisit()
{
	preVisit(getRoot());
}

void RBTree::midVisit()
{
	midVisit(getRoot());
}

void RBTree::postVisit()
{
	postVisit(getRoot());
}

ptrBTN RBTree::successor(ptrBTN n)
{
	if (n == nil)
	{
		return nil;
	}
	if (n->getRightChild() != nil)
	{
		return minimum(n->getRightChild());
	}
	ptrBTN y = getParent(n);
	while (y != nil && n == y->getRightChild())
	{
		n = y;
		y = getParent(y);
	}
	return y;
}

ptrBTN RBTree::predecessor(ptrBTN n)
{
	if (n == nil)
	{
		return nil;
	}
	if (n->getLeftChild() != nil)
	{
		return maximum(n->getLeftChild());
	}
	ptrBTN y = getParent(n);
	while (y != nil && n == y->getLeftChild())
	{
		n = y;
		y = getParent(y);
	}
	return y;
}

ptrBTN RBTree::minimum(ptrBTN n)
{
	while (n->getLeftChild() != nil)
	{
		n = n->getLeftChild();
	}
	return n;
}

ptrBTN RBTree::maximum(ptrBTN n)
{
	while (n->getRightChild() != nil)
	{
		n = n->getRightChild();
	}
	return n;
}

void RBTree::preVisit(ptrBTN p)
{
	if (p != nil)
	{
		cout << p->getData() << " ";
		preVisit(p->getLeftChild());
		preVisit(p->getRightChild());
	}
}

void RBTree::midVisit(ptrBTN p)
{
	if (p != nil)
	{
		midVisit(p->getLeftChild());
		cout << p->getData() << " ";
		midVisit(p->getRightChild());
	}
}

void RBTree::postVisit(ptrBTN p)
{
	if (p != nil)
	{
		postVisit(p->getLeftChild());
		postVisit(p->getRightChild());
		cout << p->getData() << " ";
	}
}

ptrBTN RBTree::search(ptrBTN p, int d)
{
	if (p == nil)
	{
		return nil;
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

RBTree::RBTree()
{
	setRoot(nil);
}

RBTree::~RBTree()
{
	delete nil;
	clear(getRoot());
	setRoot(nullptr);
}
