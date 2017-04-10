#ifndef LUXURY_H
#define LUXURY_H
//#include "Gift.h"
#include <bits/stdc++.h>
using namespace std;
class Luxury:public Gift/*! \brief
*
*
*class for luxury gifts
*/
{
	public:
		/** rating of gift*/
		int r;
		/** difficulty in obtaining gift*/
		int d;
};
#endif
