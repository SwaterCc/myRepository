#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<initializer_list>


typedef struct huffmanItem{
	char c_value = 0;
	int n_value = 0;
	int lchird = -1;
	int rchird = -1;
	int parent = -1;
	bool visited = false;
}item;

typedef struct codeTableItem {
	char c_value;
	std::string code;
};

class huffmanTree
{
public:
	//产生树
	huffmanTree(std::vector<item> elem);
	huffmanTree(const item arr[], size_t n);
	huffmanTree(std::initializer_list<item> list);
	//销毁树
	//~huffmanTree();

	//产生huffman编码
	void huffman_code();

	//test
	void display();
private:
	//构造函数使用
	void createNew(int fst,int sec, item &ret);
	//获得父节点
	void setParent(int fst, int sec,int parent);
	//查找新节点在表中的下表
	int findNewItemPos(const item& elem);
	//前序遍历使用
	//node* pre(node *p);
	////中序遍历使用
	//node* in(node *p);
	////后序遍历使用
	//node* post(node *p);
	//构建huffman编码表
	void make_huffmanTable();
	//遍历
	void findLeaf(int pos , std::vector<codeTableItem> &cti , size_t &n);
	//寻找当前结点有几个父节点
	void findParant(int pos, std::vector<codeTableItem> &cti, size_t &n);
	//输出“数值-编码”形式的字符串
	void show(std::vector<codeTableItem>::iterator it);
	//

private:
	//输入队列
	std::vector<item> input;
	//哈夫曼编码表
	std::vector<codeTableItem> codeTable;
	//输入数据长度
	
};



#endif