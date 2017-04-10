#ifndef SEARCH_H
#define SEARCH_H
#include "Boy.h"
#include "Couple.h"
#include <bits/stdc++.h>
using namespace std;

class Search/*! \brief
*
*
*base class which searches girlfriend of a particular boy
*/
{
	public:
		/** member function for seaching gf*/
		void searchgf(Boy *b[100],Couple c[100],int nb,int k);
};
#endif
