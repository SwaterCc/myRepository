#include"huffman.h"
#include<string>
using namespace std;


int main(void)
{
	vector<item> vt;
	vt.push_back(item{ 'a',1});
	vt.push_back(item{ 'b',4 });
	vt.push_back(item{ 'c',5 });
	vt.push_back(item{ 'd',3 });
	vt.push_back(item{ 'e',11 });
	vt.push_back(item{ 'f',11 });
	vt.push_back(item{ 'h',42 });
	vt.push_back(item{ 'm',52 });
	vt.push_back(item{ 'i',34 });
	vt.push_back(item{ 'n',12 });
	huffmanTree theTree(vt);
	theTree.display();
	theTree.huffman_code();

	
	cin.get();
}