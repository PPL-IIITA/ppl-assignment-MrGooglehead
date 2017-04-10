#ifndef HASH_H
#define HASH_H
#include <bits/stdc++.h>
#include "Search.h"
using namespace std;
class hash:public Search/*! \brief
*
*
*class searches girlfriend of a boy using hashtables(open addressing)
*/
{
        public:
	/** function which searches for gf*/ 
        void searchgf(Boy *by[100],Couple c[100],int nb,int k);
};
#endif

