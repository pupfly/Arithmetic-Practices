#include "BinaryTree.h"

void BinaryTreeNode::setParent(ptrBTN p)
{
	parent = p;
}

void BinaryTreeNode::setData(int d)
{
	data = d;
}

void BinaryTreeNode::setColor(int c)
{
	color = c;
}

void BinaryTreeNode::setLeftChild(ptrBTN node)
{
	leftChild = node;
	if (node != nullptr)
	{
		node->setParent(this);//设置子节点的父节点
	}
}

void BinaryTreeNode::setRightChild(ptrBTN node)
{
	rightChild = node;
	if (node != nullptr)
	{
		node->setParent(this);//设置子节点的父节点
	}
}

int BinaryTreeNode::getData()
{
	return data;
}

int BinaryTreeNode::getColor()
{
	return color;
}

ptrBTN BinaryTreeNode::getParent()
{
	return parent;
}

ptrBTN BinaryTreeNode::getLeftChild()
{
	return leftChild;
}

ptrBTN BinaryTreeNode::getRightChild()
{
	return rightChild;
}

BinaryTreeNode::BinaryTreeNode():data(0),color(COLOR_RED),parent(nullptr),leftChild(nullptr),rightChild(nullptr)
{
}

BinaryTreeNode::BinaryTreeNode(int c)
{
	data = 0;
	color = c;
	parent = nullptr;
	leftChild = nullptr;
	rightChild = nullptr;
}

BinaryTreeNode::~BinaryTreeNode()
{
}

bool BinaryTree::create(int d)
{
	try
	{
		root = new BinaryTreeNode;
		root->setData(d);
		root->setParent(nullptr);//显式设置根节点的父节点
	}
	catch (const std::exception&e)
	{
		cout << "Error：Failed to allocate memory for root" << e.what() << endl;
	}
	return root != nullptr;
}

bool BinaryTree::isEmpty()
{
	return root == nullptr;
}

ptrBTN BinaryTree::getRoot()
{
	return root;
}

void BinaryTree::setRoot(ptrBTN n)
{
	root = n;
}

void BinaryTree::clear(ptrBTN p)
{
	if (p != nullptr)
	{
		clear(p->getLeftChild());
		clear(p->getRightChild());
		delete p;
	}
}

void BinaryTree::clear()
{
	clear(root);
}

int BinaryTree::height(ptrBTN p)
{
	if (p == nullptr)
	{
		return 0;
	}
	int l = height(p->getLeftChild());
	int r = height(p->getRightChild());
	return l > r ? l + 1 : r + 1;
}

int BinaryTree::height()
{
	return height(root);
}

int BinaryTree::sum(ptrBTN p)
{
	if (p == nullptr)
	{
		return 0;
	}
	return 1 + sum(p->getLeftChild()) + sum(p->getRightChild());
}

int BinaryTree::sum()
{
	return sum(root);
}

ptrBTN BinaryTree::getParent(ptrBTN n)
{
	return n->getParent();
}

ptrBTN BinaryTree::getLeftChild(ptrBTN p)
{
	return p->getLeftChild();
}

ptrBTN BinaryTree::getRightChild(ptrBTN p)
{
	return p->getRightChild();
}

void BinaryTree::insertLeftChild(ptrBTN p, ptrBTN n)
{
	p->setLeftChild(n);
}

void BinaryTree::insertRightChild(ptrBTN p, ptrBTN n)
{
	p->setRightChild(n);
}

void BinaryTree::preVisit()
{
	preVisit(root);
}

void BinaryTree::midVisit()
{
	midVisit(root);
}

void BinaryTree::postVisit()
{
	postVisit(root);
}

ptrBTN BinaryTree::successor(ptrBTN n)
{
	if (n == nullptr)
	{
		return nullptr;
	}
	if (n->getRightChild() != nullptr)
	{
		return minimum(n->getRightChild());
	}
	ptrBTN y = getParent(n);
	while (y != nullptr && n == y->getRightChild())
	{
		n = y;
		y = getParent(y);
	}
	return y;
}

ptrBTN BinaryTree::predecessor(ptrBTN n)
{
	if (n == nullptr)
	{
		return nullptr;
	}
	if (n->getLeftChild() != nullptr)
	{
		return maximum(n->getLeftChild());
	}
	ptrBTN y = getParent(n);
	while (y != nullptr && n == y->getLeftChild())
	{
		n = y;
		y = getParent(y);
	}
	return y;
}

ptrBTN BinaryTree::minimum(ptrBTN n)
{
	while (n->getLeftChild() != nullptr)
	{
		n = n->getLeftChild();
	}
	return n;
}

ptrBTN BinaryTree::maximum(ptrBTN n)
{
	while (n->getRightChild() != nullptr)
	{
		n = n->getRightChild();
	}
	return n;
}

void BinaryTree::preVisit(ptrBTN p)
{
	if (p != nullptr)
	{
		cout << p->getData() << " ";
		preVisit(p->getLeftChild());
		preVisit(p->getRightChild());
	}
}

void BinaryTree::midVisit(ptrBTN p)
{
	if (p != nullptr)
	{
		midVisit(p->getLeftChild());
		cout << p->getData() << " ";
		midVisit(p->getRightChild());
	}
}

void BinaryTree::postVisit(ptrBTN p)
{
	if (p != nullptr)
	{
		postVisit(p->getLeftChild());
		postVisit(p->getRightChild());
		cout << p->getData() << " ";
	}
}

BinaryTree::BinaryTree() :root(nullptr)
{
}

BinaryTree::~BinaryTree()
{
	clear(root);
}