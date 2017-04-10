#ifndef CRITERIA_H
#define CRITERIA_h
#include "Boy.h"
#include "Girl.h"
#include <bits/stdc++.h>
using namespace std;
class Criteria /*! \brief 
*
*
* the class checks various criteria for matching boys and girls before adding them into a couple*/
{
	public:
		/** member function that checks the criteria for mathing boys and girls*/
		int checkCriteria(Girl *g,Boy *b[100],int nb);
		

};
#endif
