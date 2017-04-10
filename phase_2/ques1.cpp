//#include "Boy.h"
//#include "Girl.h"
#include "Criteria.h"
#include "Couple.h"
#include "Generate.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	Boy b[100];
	Girl g[100];
	Generate G;
	G.generate();
	freopen("file.txt","r",stdin);
	int nb=0,ng=0,k=0,i=0,j=0;
	Criteria ob;
	Couple c[100];
	cin>>nb;
	while(i<nb)
	{
		cin>>b[i].name>>b[i].attr>>b[i].intelligence>>b[i].budget>>b[i].type>>b[i].minattrreq>>b[i].committed;
		i++;
	}
	cin>>ng;
	while(j<ng)
	{
		cin>>g[j].name>>g[j].attr>>g[j].intelligence>>g[j].mbudget>>g[j].type>>g[j].committed>>g[j].criteria;
		j++;
	}
	for(i=0;i<ng;i++)
	{
		int bfin;
		bfin=ob.checkCriteria(g[i],b,nb);
		if(bfin!=-1)
			c[k++].makeCouple(g[i],b[bfin]);
	}
	freopen("couple.txt","w",stdout);
	cout<<k<<"\n";
	for(i=0;i<k;i++)
		cout<<c[i].boy<<" "<<c[i].girl<<" "<<c[i].bbudget<<" "<<c[i].gbudget<<" "<<c[i].btype<<" "<<c[i].gtype<<" "<<c[i].battr<<" "<<c[i].gattr<<" "<<c[i].bint<<" "<<c[i].gint<<"\n";		

	return 0;
}
