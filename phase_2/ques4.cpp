#include <bits/stdc++.h>
#include "Initialize.h"
using namespace std;
int main()
{
	Initialize ob;
	ob.initiate();
	int k=rand()%5;
	ob.breakup(k);
	ob.allocafterbreakup(k);
	ob.printnewcouple();
}
			
