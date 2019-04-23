#include"Char_BTree.h"

int main(void)
{
	CharBTree p("ABC#DEF");
	p.PreOrder(p.Root());

	cin.get();
}