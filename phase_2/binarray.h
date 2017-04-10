#ifndef BINARRAY_H
#define BINARRAY_H
#include <bits/stdc++.h>
#include "Search.h"
using namespace std;
class binarray:public Search/*! \brief
*
*
*class searches girlfriend of a boy using binary search
*/
{
        public:
	/**member func to search for gf*/
        void searchgf(Boy *by[100],Couple c[100],int nb,int k);
	/**binary search function*/
	int binarysearch(Couple c[100],int l,int r,Boy *by);
};
#endif
