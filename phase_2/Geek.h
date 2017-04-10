#ifndef GEEK_H
#define GEEK_H
#include <bits/stdc++.h>
#include "Boy.h"
using namespace std;

class Geek: public Boy/*! \brief
*
*
*class for geeky boys
*/
{
public:
	
	int giveGifts(Gift giftbasket[100],Girl g);
};
#endif
