#ifndef BOY_H
#define BOY_H
#include <bits/stdc++.h>
using namespace std;

class Boy  /*! \brief
*
*
*class contains various attributes of a boy such as name,attractiveness,intelligence,budget etc.
*/


{
	public:
		/** atrribute containing name of boy */
		int name; 
		/** atrribute containing attractiveness of boy */
		int attr; 
		/** atrribute containing intelligece of boy */
		int intelligence;
		 /** atrribute containing budget of boy */
		int budget;
 		/** atrribute containing type of boy */
		int type;
		 /** atrribute containing happiness of boy */
		int happiness;
		/** atrribute containing minimum attractive requirements of boy */
		int minattrreq; 
		/** attribute containing whether boy is committed or not */
		int committed;	
		 /** a constructor that initialises committed variable to 0 */
		Boy()
		{
			committed=0;
		}
};
#endif
