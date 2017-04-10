#include <bits/stdc++.h>
#include "Initialize.h"
using namespace std;
int main()
{
        Initialize ob;
        ob.initiate();
        int t=rand()%5;
	int i;
	for(i=0;i<t;i++)
	{
	        ob.breakupt(t);
        	ob.allocafterbreakupt(t);
       		ob.printnewcouplet();
	}
}


