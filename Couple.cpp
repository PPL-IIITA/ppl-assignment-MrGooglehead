#include "Couple.h"
#include <bits/stdc++.h>
using namespace std;

		void Couple::makeCouple(Girl g,Boy b)
		{
			boy=b.name;
			girl=g.name;
			bbudget=b.budget;
			gbudget=g.mbudget;
			btype=b.type;
			gtype=g.type;
			battr=b.attr;
			gattr=g.attr;	
			bint=b.intelligence;
			gint=g.intelligence;
		}
		void Couple::allocGifts()/** a member function which allocates gifts to a particular couple */
		{
			i=0;
			j=0;
			k=0;
			l=0;
			Gift G;
			freopen("giftlist.txt","r",stdin);
			int ngifts;
			cin>>ngifts;
			int giftTot=0;
			int bmax=bbudget;
			if(btype==1)
			{		
				while(giftTot <= gbudget)
				{
					cin>>G.id>>G.type>>G.price>>G.r>>G.uc>>G.uv;
					giftTot+=G.price;
					giftBasket[i++]=G.id;
					if(G.type==1)
					{
						essential[j]=G.id;
						essentialGifts[j]=G.price;
						j++;
					}
					else if(G.type==2)
					{
						luxury[k]=G.id;
						luxuryGifts[k]=G.price;
						k++;
					}
					else if(G.type==3)
					{
						utility[l]=G.id;
						utilityGifts[l]=G.price;
						l++;
					}
					bmax-=G.price;
					if(bmax<0)
						bbudget+=G.price+bmax;
					ngifts--;
				}
			}
			else if(btype==3)
			{
				while(giftTot <= gbudget)
                                {
                                        cin>>G.id>>G.type>>G.price>>G.r>>G.uc>>G.uv;
                                        giftTot+=G.price;
                                        giftBasket[i++]=G.id;
                                       	if(G.type==1)
                                        {
                                                essential[j]=G.id;
                                                essentialGifts[j]=G.price;
						j++;
                                        }
                                        else if(G.type==2)
                                        {
                                                luxury[k]=G.id;
                                                luxuryGifts[k]=G.price;
						k++;
                                        }
                                        else if(G.type==3)
                                        {
                                                utility[l]=G.id;
                                                utilityGifts[l]=G.price;
						l++;
                                        }

                                        bmax-=G.price;
                                        if(bmax<0)
                                                bbudget+=G.price+bmax;
					ngifts--;	
                                }
				while(ngifts)
				{
					cin>>G.id>>G.type>>G.price>>G.r>>G.uc>>G.uv;
					if(G.type==2)
					{	
						bmax-=G.price;
						if(bmax>=0)
						{
							giftBasket[i++]=G.id;			
							luxury[k]=G.id;
							luxuryGifts[k]=G.price;
							k++;
							break;
						}
					}
					ngifts--;
				}

			}
			else 
			{
				while(giftTot <= gbudget)
                                {
                                        cin>>G.id>>G.type>>G.price>>G.r>>G.uc>>G.uv;
                                        giftTot+=G.price;
                                        giftBasket[i++]=G.id;
                                       	if(G.type==1)
                                        {
                                                essential[j]=G.id;
                                                essentialGifts[j]=G.price;
						j++;
                                        }
                                        else if(G.type==2)
                                        {
                                                luxury[k]=G.id;
                                                luxuryGifts[k]=G.price;
						k++;
                                        }
                                        else if(G.type==3)
                                        {
                                                utility[l]=G.id;
                                                utilityGifts[l]=G.price;
						l++;
                                        }

                                        bmax-=G.price;
                                        if(bmax<0)
                                                bbudget+=G.price+bmax;
                                        ngifts--;
                                }
				while(bmax>0)
				{
					cin>>G.id>>G.type>>G.price>>G.r>>G.uc>>G.uv;
					bmax-=G.price;
					if(bmax>=0)
					{
						giftBasket[i++]=G.id;
	                                        if(G.type==1)
						{
							essential[j]=G.id;
        	                                        essentialGifts[j]=G.price;
							j++;
						}
                	                        else if(G.type==2)
						{
							luxury[k]=G.id;
                        	                        luxuryGifts[k]=G.price;
							k++;
						}
                                	        else
						{
							utility[l]=G.id;
                                        	        utilityGifts[l]=G.price;
							l++;
						}
					}
				}
			}
		}						
		

		int Couple::calcHappiness(Couple c)/** a member function which calculates happiness of the couple */
		{
			double ghappiness=0,bhappiness=0;
			int eprice=0,lprice=0,tot=0;
			if(c.gtype==1)
			{
				int m=0;
				for(m=0;m<j;m++)
					eprice+=essentialGifts[m];
				for(m=0;m<k;m++)
					lprice+=2*luxuryGifts[m];
				tot=tot+eprice+lprice-gbudget;
				if(tot>0)
					ghappiness=log(log(tot));
					
			}
			else if(c.gtype==2)
			{
				int m=0;
                                for(m=0;m<j;m++)
                                        eprice+=essentialGifts[m];
                                for(m=0;m<k;m++)
                                        lprice+=luxuryGifts[m];
                                tot=tot+eprice+lprice-gbudget;
				if(tot>0)
                                	ghappiness=log(tot);
				
			}
			else
			{
				int m=0;
                                for(m=0;m<j;m++)
                                        eprice+=essentialGifts[m];
                                for(m=0;m<k;m++)
                                        lprice+=luxuryGifts[m];
                                tot=tot+eprice+lprice-gbudget;
                                ghappiness=pow(2.71,tot);
				if(ghappiness>0)
					ghappiness=log(ghappiness);
				
			}
			int total=0;
			if(c.btype==1)
			{
				int m=0;
				for(m=0;m<j;m++)
					total+=essentialGifts[m];
				for(m=0;m<k;m++)
					total+=luxuryGifts[m];
				bhappiness=bbudget-total;
				if(bhappiness>0)
					bhappiness=log(bhappiness);
			}
			else if(c.btype==2)
				bhappiness=ghappiness;
			else
			{
				bhappiness=log(gint);
			}
			happiness=ghappiness+bhappiness;
			return happiness;
		}
		
		int Couple::calcCompatibility(Couple c)/** a member function which calculates compatibility of couple*/
		{
			compatibility=bbudget-gbudget+abs(bint-gint)+abs(battr-gattr);
			return compatibility;
		}
		void Couple::print(Couple c) /** a member function which prints details of gifts exchanged between couples*/
		{
			cout<<"Couple"<<" "<<c.boy<<" "<<c.girl<<"\n";
			int m;
			if(j>0)
			{
				cout<<"essential gifts are"<<" ";
			 	m=0;
				for(m=0;m<j;m++)
					cout<<essential[m]<<" ";
				cout<<"\n";
			}
			if(k>0)
			{
			 	cout<<"luxury gifts are"<<" ";
                       	 	m=0;
                        	for(m=0;m<k;m++)
                                	cout<<luxury[m]<<" ";
				cout<<"\n";
			}
			if(l>0)
			{
			 	cout<<"utility gifts are"<<" ";
                         	m=0;
                        	for(m=0;m<l;m++)
                                	cout<<utility[m]<<" ";
				cout<<"\n";
			}
		}

