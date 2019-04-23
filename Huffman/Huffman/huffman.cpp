#include "huffman.h"
#include "tools.h"
#include<algorithm>
#include<string>
#include<functional>
huffmanTree::huffmanTree(std::vector<item> elem):input(elem),codeTable(elem.size())
{
	
	
	int fst_min = 0, sec_min = 1;

	item retItem;
	sort(input.begin(), input.end(), mysort);
	int count = input.size()-1;
	while (count-- > 0)
	{
		input[fst_min].visited = true;
		input[sec_min].visited = true;
		createNew(fst_min, sec_min,retItem);
		input.push_back(retItem);
		sort(input.begin(), input.end(), mysort);
		int pos = findNewItemPos(retItem);
		setParent(fst_min, sec_min,pos);
		fst_min = fst_min + 2;
		sec_min = sec_min + 2;
	}
	std::cout << "创建完成" << std::endl;
}

void huffmanTree::huffman_code()
{
	make_huffmanTable();
	std::cout << "char\tcode\t" << std::endl;
	for (int i = 0; i < codeTable.end()-codeTable.begin(); i++)
	{
		std::cout << codeTable[i].c_value << "\t";
		std::cout << codeTable[i].code << std::endl;
	}
}

void huffmanTree::display()
{
	auto it = input.begin();
	int i = 0;
	std::cout << "pos\tchar\twpl\tlchild\trchild\tparent\tvistit\t" << std::endl;
	for (it = input.begin(); it != input.end(); it++,i++)
	{
		std::cout <<i<<"\t" <<it->c_value << "\t" << it->n_value << "\t" << it->lchird << "\t" <<
			it->rchird << "\t" << it->parent << "\t" << it->visited << std::endl;
	}
}

void huffmanTree::createNew(int fst, int sec, item &ret)
{
	ret.c_value = '#';
	ret.n_value = input[fst].n_value + input[sec].n_value;
	ret.lchird = fst;
	ret.rchird = sec;
}

void huffmanTree::setParent(int fst, int sec, int parent)
{
	input[fst].parent = parent;
	input[sec].parent = parent;
}

int huffmanTree::findNewItemPos(const item & elem)
{
	
	auto it=find_if(input.begin(), input.end(), std::bind(findItem, std::placeholders::_1, elem));
	int len = it - input.begin();
	return len;
}

void huffmanTree::make_huffmanTable()
{
	size_t count = 0;
	findLeaf(input[input.size() - 1].lchird, codeTable, count);
	findLeaf(input[input.size() - 1].rchird, codeTable, count);
}

void huffmanTree::findLeaf(int pos , std::vector<codeTableItem> &cti , size_t &n)
{
	auto node = input[pos];

	if (pos % 2 == 0)
		cti[n].code += '0';
	else
		cti[n].code += '1';
	
	size_t old = n;

	if (node.lchird == -1 && node.rchird == -1)
	{
		cti[n++].c_value = node.c_value;
		return;
	}
	

	findLeaf(node.lchird, cti, n);
	if (n != old && n < 5)
	{
		findParant(pos, cti, n);
	}
	findLeaf(node.rchird, cti, n);
	if (n != old && n < 5)
	{
		findParant(pos, cti, n);
	}
}

void huffmanTree::findParant(int pos, std::vector<codeTableItem>& cti, size_t & n)
{
	if (pos < 0)
		return;

	int p = input[pos].parent;
	
	if (p > 0)
	{
		if (pos % 2 == 0)
			cti[n].code = '0' + cti[n].code;
		else
			cti[n].code = '1' + cti[n].code;
		findParant(p, cti, n);
	}
	else
		return;
}


