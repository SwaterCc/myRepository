#include"tools.h"
bool mysort(const item& d1, const item& d2)
{
	return d1.n_value < d2.n_value;
}

bool findItem(const item & i,const item &mod)
{
	if (i.c_value == mod.c_value&&i.n_value == mod.n_value&&i.visited == mod.visited)
		return true;
	return false;
}
