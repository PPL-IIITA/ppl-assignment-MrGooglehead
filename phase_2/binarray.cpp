#include "binarray.h"
#include "Search.h"
#include "Couple.h"
#include <bits/stdc++.h>
using namespace std;

        void binarray::searchgf(Boy *by[100],Couple c[100],int nb,int k)
	{
		Couple c1[100];
		int i=0;
		int j=0;
		for(i=0;i<k;i++)
			c1[i]=c[i];
		for(i=0;i<k-1;i++)
		{
			for(j=0;j<k-1-i;j++)
			{
				if(c1[j].b->name > c1[j+1].b->name)
				{
					Couple t=c1[j];
					c1[j]=c1[j+1];
					c1[j+1]=t;
				}
			}
		}
		for(i=0;i<nb;i++)
		{	
			int p;
			p=binarysearch(c1,0,k-1,by[i]);		
			if(p==-1)
				printf("%d has no gf\n",by[i]->name);
			else
				printf("%d has %d as gf\n",by[i]->name,c1[p].g->name);
		}
			
	}	
	int binarray::binarysearch(Couple c[100],int l,int r,Boy *by)
	{
		while (l <= r)
 		 {
  		  int m = l + (r-l)/2;
		if (c[m].b->name==by->name) 
   			     return m;  
   		if (c[m].b->name < by->name) 
      			 	l = m + 1;
		else
        		 r = m - 1; 
  		}
 		 return -1; 	
	}
