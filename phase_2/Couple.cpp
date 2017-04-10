#include "Couple.h"
#include "Boy.h"
#include "Gift.h"
#include "Girl.h"
#include "Miser.h"
#include "Generous.h"
#include "Geek.h"
#include <bits/stdc++.h>
using namespace std;

	void Couple::makeCouple(Boy *b1,Girl *g1)/**member function which creates couples*/
	{
		b=b1;
		g=g1;
	}
	void Couple::allocGifts(Gift *G[100])/** a member function which allocates gifts to a particular couple */
		{
			i=0;
			j=0;
			k=0;
			l=0;
			
			freopen("giftlist.txt","r",stdin);
			int ngifts;
			cin>>ngifts;
			int giftTot=0;
			int bmax=b->budget;
			int m=0;
			if(b->type==1)
			{		
				while(giftTot <= g->mbudget)
				{
						
					giftTot+=G[m]->price;
					giftBasket[i++]=G[m]->id;
					if(G[m]->type==1)
					{
						essential[j]=G[m]->id;
						essentialGifts[j]=G[m]->price;
						j++;
					}
					else if(G[m]->type==2)
					{
						luxury[k]=G[m]->id;
						luxuryGifts[k]=G[m]->price;
						k++;
					}
					else if(G[m]->type==3)
					{
						utility[l]=G[m]->id;
						utilityGifts[l]=G[m]->price;
						l++;
					}
					bmax-=G[m]->price;
					if(bmax<0)
						b->budget+=G[m]->price+bmax;
					
					m++;
				}
			}
			else if(b->type==3)
			{
				while(giftTot <= g->mbudget)
                                {
                                        
                                        giftTot+=G[m]->price;
                                        giftBasket[i++]=G[m]->id;
                                       	if(G[m]->type==1)
                                        {
                                                essential[j]=G[m]->id;
                                                essentialGifts[j]=G[m]->price;
						j++;
                                        }
                                        else if(G[m]->type==2)
                                        {
                                                luxury[k]=G[m]->id;
                                                luxuryGifts[k]=G[m]->price;
						k++;
                                        }
                                        else if(G[m]->type==3)
                                        {
                                                utility[l]=G[m]->id;
                                                utilityGifts[l]=G[m]->price;
						l++;
                                        }

                                        bmax-=G[m]->price;
                                        if(bmax<0)
                                                b->budget+=G[m]->price+bmax;
					ngifts--;	
					m++;
                                }
				while(ngifts)
				{
					if(G[m]->type==2)
					{	
						bmax-=G[m]->price;
						if(bmax>=0)
						{
							giftBasket[i++]=G[m]->id;			
							luxury[k]=G[m]->id;
							luxuryGifts[k]=G[m]->price;
							k++;
							break;
						}
					}
					ngifts--;
					m++;
				}

			}
			else 
			{
				while(giftTot <= g->mbudget)
                                {
                                       
                                        giftTot+=G[m]->price;
                                        giftBasket[i++]=G[m]->id;
                                       	if(G[m]->type==1)
                                        {
                                                essential[j]=G[m]->id;
                                                essentialGifts[j]=G[m]->price;
						j++;
                                        }
                                        else if(G[m]->type==2)
                                        {
                                                luxury[k]=G[m]->id;
                                                luxuryGifts[k]=G[m]->price;
						k++;
                                        }
                                        else if(G[m]->type==3)
                                        {
                                                utility[l]=G[m]->id;
                                                utilityGifts[l]=G[m]->price;
						l++;
                                        }

                                        bmax-=G[m]->price;
                                        if(bmax<0)
                                                b->budget+=G[m]->price+bmax;
                                        ngifts--;
					m++;
                                }
				while(bmax>0)
				{
					
					bmax-=G[m]->price;
					if(bmax>=0)
					{
						giftBasket[i++]=G[m]->id;
	                                        if(G[m]->type==1)
						{
							essential[j]=G[m]->id;
        	                                        essentialGifts[j]=G[m]->price;
							j++;
						}
                	                        else if(G[m]->type==2)
						{
							luxury[k]=G[m]->id;
                        	                        luxuryGifts[k]=G[m]->price;
							k++;
						}
                                	        else
						{
							utility[l]=G[m]->id;
                                        	        utilityGifts[l]=G[m]->price;
							l++;
						}
					}
					m++;
				}
			}
		}						
		

	

		int Couple::calcHappiness(Couple c)/** a member function which calculates happiness of the couple */
		{
			double ghappiness=0,bhappiness=0;
			int eprice=0,lprice=0,tot=0;
			if(c.g->type==1)
			{
				int m=0;
				for(m=0;m<j;m++)
					eprice+=essentialGifts[m];
				for(m=0;m<k;m++)
					lprice+=2*luxuryGifts[m];
				tot=tot+eprice+lprice-g->mbudget;
				if(tot>0)
					ghappiness=log(log(tot));
					
			}
			else if(c.g->type==2)
			{
				int m=0;
                                for(m=0;m<j;m++)
                                        eprice+=essentialGifts[m];
                                for(m=0;m<k;m++)
                                        lprice+=luxuryGifts[m];
                                tot=tot+eprice+lprice-g->mbudget;
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
                                tot=tot+eprice+lprice-g->mbudget;
                                ghappiness=pow(2.71,tot);
				if(ghappiness>0)
					ghappiness=log(ghappiness);
				
			}
			int total=0;
			if(c.b->type==1)
			{
				int m=0;
				for(m=0;m<j;m++)
					total+=essentialGifts[m];
				for(m=0;m<k;m++)
					total+=luxuryGifts[m];
				bhappiness=b->budget-total;
				if(bhappiness>0)
					bhappiness=log(bhappiness);
			}
			else if(c.b->type==2)
				bhappiness=ghappiness;
			else
			{
				bhappiness=log(g->intelligence);
			}
			happiness=ghappiness+bhappiness;
			return happiness;
		}
		
		int Couple::calcCompatibility(Couple c)/** a member function which calculates compatibility of couple*/
		{
			compatibility=b->budget-g->mbudget+abs(b->intelligence-g->intelligence)+abs(b->attr-g->attr);
			return compatibility;
		}
/*		void Couple::print(Couple c) ** a member function which prints details of gifts exchanged between couples
		{
			cout<<"Couple"<<" "<<c.b->name<<" "<<c.g->name<<"\n";
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

			


*/
