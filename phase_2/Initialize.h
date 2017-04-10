#ifndef INITIALIZE_H
#define INITIALIZE_H
#include <bits/stdc++.h>
#include "Boy.h"
#include "Girl.h"
#include "Couple.h"
#include "Gift.h"
using namespace std;

class Initialize/*! \brief
*
*
*class for initializing boys,girl,couples and performing other allocations
*/
{
	public:	
		/**array of boys*/
		Boy *boy[100];
		/** array of girls*/
		Girl *girl[100];	
		/** array of couples*/
		Couple c[100];
		/** array of couples sorted accord. to happiness*/
		Couple c1[100];
		/** array of couples sorted according to compatibility*/
		Couple c2[100];	
		/** array of couples with least happiness*/
		Couple nc[100];
		/** array of couples with happiness < t*/
		Couple tc[100];
		int l;
		int z;
		int nb,ng;
		/** array of gifts*/
		Gift *g[100];
		/** member function for initialization*/
		void initiate();
		/** member func for printing couples*/
		void printi();
		/** no of couples*/
		int k;
		void send(Couple c[100]);
		/** member function for performing breakups with least happiness*/		
		void breakup(int k1);
		/** member func for performing breakups of couples with happiness < t*/
		void breakupt(int t);
		/** allocates new boyfriends to girls*/
		void allocafterbreakupt(int t);
		/** allocates new boufriends to girls*/
		void allocafterbreakup(int k1);
		/** prints new couples*/
		void printnewcouple();
		/** prints new couples*/
		void printnewcouplet();
		/** prints couples*/
		void printcouples();
		/** search for gf accord.to user choice*/
		void search(int choice);
};
#endif

