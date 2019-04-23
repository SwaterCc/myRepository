#include "Char_BTree.h"

CharBTree::CharBTree(string str)
{
	pos = 1;
	tree = '*' + str;
	//root = new TNode;
	root=initBTree(root, pos);
}

TNode* CharBTree::initBTree(TNode *node,int pos)
{
	if (pos >= tree.size())
	{
		return nullptr;
	}
	if (tree[pos] != '#')
	{
		node = new TNode;
		node->value = tree[pos];
		node->lchild = initBTree(node->lchild, pos * 2);
		node->rchild = initBTree(node->rchild, pos * 2 + 1);
	}
	else
		node = nullptr;

	

	return node;
}

CharBTree::~CharBTree()
{
	cout << "~" << endl;
}

void CharBTree::PreOrder(TNode *node)
{
	if (node == nullptr)
		return;
	//访问根结点
	cout << node->value << " ";
	//访问左子树
	PreOrder(node->lchild);
	//访问右子树
	PreOrder(node->rchild);
}
