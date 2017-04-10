#ifndef COUPLE_H
#define COUPLE_H
#include "Boy.h"
#include "Girl.h"
#include "Gift.h"
#include <bits/stdc++.h>
using namespace std;
class Couple/*! \brief
*
*
*class contains various attributes of couple
*/

{
	public:
		/** contains details of boy in couple*/
		Boy *b;
		/** contains details of girl in girl*/
		Girl *g;
		/**contains total happiness of couple*/
		int happiness;
		/** contains compatibility of couple*/
		int compatibility;
		/** contains ids of gifts*/
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
		void print(Couple c);	
		/** member function which creates couples*/
		void makeCouple(Boy *b1,Girl *g1);
		void allocGifts(Gift *G[100]);
		int calcHappiness(Couple C);
		int calcCompatibility(Couple C);
};
#endif 
