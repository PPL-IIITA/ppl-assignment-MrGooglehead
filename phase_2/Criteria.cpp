
#include "Criteria.h"
#include <bits/stdc++.h>
using namespace std;
		int Criteria::checkCriteria(Girl *g,Boy *b[100],int nb)/** member function that checks the criteria for mathing boys and girls*/
		{	
			int greatest=0;
			int index=-1;
			int i=0;
			if(g->criteria==1)
			{
				for(i=0;i<nb;i++)
				{
					if(b[i]->committed==0 && b[i]->attr >= greatest && b[i]->budget >= g->mbudget && g->attr >= b[i]->minattrreq)
					{
						greatest=b[i]->attr;
						index=i; 
					}
				}
				b[index]->committed=1;
				return index;
			}
			else if(g->criteria ==2)
			{
                                for(i=0;i<nb;i++)
                                {
                                        if(b[i]->committed==0 && b[i]->intelligence >= greatest && b[i]->budget >= g->mbudget && g->attr >= b[i]->minattrreq)
                                        {
                                                greatest=b[i]->intelligence;
                                                index=i;
                                        }
                                }
				b[index]->committed=1;
                                return index;
                        }
			else
			{
                                for(i=0;i<nb;i++)
                                {
                                        if(b[i]->committed==0 &&  b[i]->budget >= greatest && b[i]->budget >=g->mbudget && g->attr >= b[i]->minattrreq)
                                        {
                                                greatest=b[i]->budget;
                                                index=i;
                                        }
                                }
				b[index]->committed=1;
                                return index;
                        }
		}


