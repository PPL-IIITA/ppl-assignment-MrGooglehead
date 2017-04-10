#ifndef GIRL_H
#define GIRL_H
#include <bits/stdc++.h>
using namespace std;
class Girl /*! \brief 
*
*
* class containing details of a girl */
{
	public:
		 /** contains name of girl */
		int name;
		   /** contains attractiveness of girl */
		int attr;
		  /** contains intelligence of girl */
		int intelligence;
			 /** contains maintainence budget of girl */
		int mbudget;
		 /** contains type of girl */
		int type;
		 /** contains happiness of girl */
		int happiness;
		 /** contains whether girl is committed or not */
		int committed;
		  /** contains ehat criteria of vboy girl wants */
		int criteria;
		/** a constructor initializing committed to 0 */
		Girl()  
		{
			committed=0;
		}
};
#endif
