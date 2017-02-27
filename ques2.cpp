#include "Criteria.h"
#include "Couple.h"
#include "Sort.h"
#include "GenerateGifts.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	GenerateGifts gg;
        gg.generate();
	int k;
	cin>>k;
	freopen("couple.txt","r",stdin);
	int n,i=0;
	cin>>n;
	Couple c[100],c1[100],c2[100];
	int happiness[100];
	int compatibility[100];		
	for(i=0;i<n;i++)
	{
		cin>>c[i].boy>>c[i].girl>>c[i].bbudget>>c[i].gbudget>>c[i].btype>>c[i].gtype>>c[i].battr>>c[i].gattr>>c[i].bint>>c[i].gint;
	}
	for(i=0;i<n;i++)
		c[i].allocGifts();
	for(i=0;i<n;i++)
	{
		happiness[i]=c[i].calcHappiness(c[i]);
		compatibility[i]=c[i].calcCompatibility(c[i]);
	}
	for(i=0;i<n;i++)
	{
		c1[i]=c[i];
		c2[i]=c[i];
	}
	Sort s;
	s.sortfunc(c1,happiness,n);
	cout<<"k happiest couples:-"<<"\n";
	for(i=0;i<k;i++)
		 cout<<c1[i].boy<<" "<<c1[i].girl<<"\n";
	s.sortfunc(c2,compatibility,n);
	cout<<"k most compatible couples:-"<<"\n";
	for(i=0;i<k;i++)
		cout<<c2[i].boy<<" "<<c2[i].girl<<"\n";
	cout<<"Gift exchange details:-"<<"\n";
	for(i=0;i<n;i++)
		c[i].print(c[i]);
	return 0;		
}
