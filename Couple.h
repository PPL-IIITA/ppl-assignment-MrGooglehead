#ifndef COUPLE_H
#define COUPLE_H
#include "Girl.h"
#include "Boy.h"
#include "Gift.h"
#include <bits/stdc++.h>
using namespace std;
class Couple /*! \brief 
*
*
* this class contains details of the couple formed.It contains their members and their details as well as their repective happiness and compatibiliy */
{
	public:
		/** contains name of boy in the couple */
		int boy;
		/** contains name of girl in the couple */
		int girl;
		/** contains happiness of couple */
		int happiness;
		/** contains compatibility couple */
		int compatibility;
		/** contains budget of boy in the couple */
		int bbudget;
		/** contains budget of girl in the couple */
		int gbudget;
		/** contains type of boy in the couple */
		int btype;
		/** contains type of girl in the couple */
		int gtype;
		/** contains attractiveness  of boy in the couple */
		int battr;
		/** contains attractiveness of girl in the couple */
		int gattr;
		/** contains intelligence of boy in the couple */
		int bint;
		/** contains intelligence of girl in the couple */
		int gint;
		/** gift basket of couple*/
		int giftBasket[100];
		/** essential gifts of couple*/
		int essentialGifts[100];
		/** luxury gifts of couple*/
		int luxuryGifts[100];
		/**utility gifts of couple*/
		int utilityGifts[100];
		int i,j,k,l;
		int essential[100];
		int luxury[100];
		int utility[100];
		/** a member function which makes couples according to the criteria given*/
		void makeCouple(Girl g,Boy b);
		/** a member function which allocates gifts to a particular couple */
		void allocGifts();
		/** a member function which calculates happiness of the couple */
		int calcHappiness(Couple c);
		/** a member function which calculates compatibility of couple*/
		int calcCompatibility(Couple c);
		/** a member function which prints details of gifts exchanged between couples*/
		void print(Couple c); 

	

				
};
#endif
