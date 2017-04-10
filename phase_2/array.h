#ifndef ARRAY_H
#define ARRAY_H
#include <bits/stdc++.h>
#include "Search.h"
using namespace std;
class array:public Search
/*! \brief
*
*
*class searches for gf with the help of array/linked list
*/

{
	public:

	void searchgf(Boy *by[100],Couple c[100],int nb,int k);
};
#endif
