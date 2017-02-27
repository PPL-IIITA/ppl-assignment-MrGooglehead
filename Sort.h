#include "Couple.h"
#include <bits/stdc++.h>
using namespace std;
class Sort
{
	public:
		void sortfunc(Couple c[100],int a[100],int n)
		{
                        int i=0,j=0;
                        for(i=0;i<n-1;i++)
                        {
                                for(j=0;j<n-1-i;j++)
                                {
                                        if(a[j]<a[j+1])
                                        {
                                                int t=a[j];
                                                a[j]=a[j+1];
                                                a[j+1]=t;
                                                Couple t2=c[j];
                                                c[j]=c[j+1];
                                                c[j+1]=t2;
                                        }
                                }
                        }
                }

};
