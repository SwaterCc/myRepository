#pragma once
#include<iostream>
using namespace std;

typedef struct TNode {
	char value;
	TNode* lchild;
	TNode* rchild;
};

class CharBTree {
public:
	//构造一棵树
	CharBTree(string str);
	/*
	   node 是结点
	   c 是结点的数据域
	*/
	//创建树
	TNode* initBTree(TNode *node, int pos);
	//销毁一颗树
	~CharBTree();
	//遍历
	//前序遍历
	void PreOrder(TNode *node);
	//中序遍历
	//void InOrder();
	////后序遍历
	//void PostOrder();
	////不常用操作
	////寻找输入节点的父节点
	//char Find_Parent(TNode *node);
	////根据条件寻找输入节点的子节点
	//char Find_Child(TNode *node,char LR);
	////求树的最大深度
	//int BTreeHigh();
	////插入节点
	//void insertChild(TNode *node,char LR);

	TNode* Root() { return root; }
private:
	string tree;
	TNode *root;
	int pos;
};