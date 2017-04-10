#include "Initialize.h"
#include "Search.h"
#include "array.h"
#include "binarray.h"
#include "hash.h"
#include <bits/stdc++.h>
#include "GenerateGifts.h"
#include "Choosy.h"
#include "Normal.h"
#include "Desperate.h"
#include "Miser.h"
#include "Generous.h"
#include "Geek.h"
#include "Generate.h"
#include "Essential.h"
#include "Luxury.h"
#include "Utility.h"
#include "Couple.h"
#include "Criteria.h"
#include "Criteria2.h"
#include "Sort.h"
using namespace std;
	
	void Initialize::send(Couple c1[100])
	{
		int i;
		for(i=0;i<k;i++)
			c1[i]=c[i];
	}

	void Initialize::initiate()
	{
		GenerateGifts gg;
	 	gg.generate();
		ifstream fp;
		fp.open("giftlist.txt");
		int ngifts;
		fp>>ngifts;
		int i;
		for(i=0;i<ngifts;i++)
		{
			int id,type,price,r,uc,uv;
			fp>>id>>type>>price>>r>>uc>>uv;
			if(type==1)
				g[i]=new Essential;
			else if(type==2)
				g[i]=new Luxury;
			else
				g[i]= new Utility;
			g[i]->price=price;
			g[i]->id=id;
			
		}
		fp.close();
		Generate G;
		G.generate();
	
		fp.open("file.txt");
		int j=0;
		nb=0;
		ng=0;

		k=0;
  	      Criteria ob;
    //  		Couple c[100];
 	       fp>>nb;

		i=0;
       		while(i<nb)
        	{
			int name,attr,intelligence,budget,type,minattrreq,committed;
			
                	fp>>name>>attr>>intelligence>>budget>>type>>minattrreq>>committed;
			if(type==1)
			{
				boy[i]=new Miser;
				boy[i]->name=name;
				boy[i]->attr=attr;
				boy[i]->intelligence=intelligence;
				boy[i]->budget=budget;
				boy[i]->type=type;
				boy[i]->minattrreq=minattrreq;
				boy[i]->committed=committed;
			}
			else if(type==2)
			{
			
				boy[i]=new Generous;
                                boy[i]->name=name;
                                boy[i]->attr=attr;
                                boy[i]->intelligence=intelligence;
                                boy[i]->budget=budget;
                                boy[i]->type=type;
                                boy[i]->minattrreq=minattrreq;
                                boy[i]->committed=committed;
			}
			else
			{
				boy[i]=new Geek;
                                boy[i]->name=name;
                                boy[i]->attr=attr;
                                boy[i]->intelligence=intelligence;
                                boy[i]->budget=budget;
                                boy[i]->type=type;
                                boy[i]->minattrreq=minattrreq;
                                boy[i]->committed=committed;
			}
                	i++;
        	}
       		 fp>>ng;
		j=0;
      		 while(j<ng)
        	{	
			int name,attr,intelligence,mbudget,type,committed,criteria;
                	fp>>name>>attr>>intelligence>>mbudget>>type>>committed>>criteria;
			if(type==1)
			{
				girl[j]=new Choosy;
				girl[j]->name=name;
                               	girl[j]->attr=attr;
                                girl[j]->intelligence=intelligence;
                                girl[j]->mbudget=mbudget;
                                girl[j]->type=type;
         
                                girl[j]->committed=committed;
				girl[j]->criteria=criteria;
			}
			else if(type==2)
			{
				girl[j]=new Normal;
				girl[j]->name=name;
                                girl[j]->attr=attr;
                                girl[j]->intelligence=intelligence;
                                girl[j]->mbudget=mbudget;
                                girl[j]->type=type;
                               
                                girl[j]->committed=committed;
				girl[j]->criteria=criteria;
			}
			else
			{
				
				girl[j]=new Desperate;
				girl[j]->name=name;
                                girl[j]->attr=attr;
                                girl[j]->intelligence=intelligence;
                                girl[j]->mbudget=mbudget;
                                girl[j]->type=type;
                                
                                girl[j]->committed=committed;
				girl[j]->criteria=criteria;
			}
                	j++;
        	}
		for(i=0;i<ng;i++)
	        {
        	        int bfin;
          	     	bfin=ob.checkCriteria((girl[i]),boy,nb);
        	       	if(bfin!=-1)
			{	
                	        c[k++].makeCouple(boy[bfin],girl[i]);
			}

        	}

		for(i=0;i<k;i++)
		{
			c[i].allocGifts(g);
		}
	
		int happiness[100];
		int compatibility[100];
		for(i=0;i<k;i++)
	        {
            	   	happiness[i]=abs(c[i].calcHappiness(c[i]));
        	       
        	        compatibility[i]=c[i].calcCompatibility(c[i]);
       		 }
	
		 for(i=0;i<k;i++)
       		 {
                	c1[i]=c[i];
                	c2[i]=c[i];
        	}
		
	        Sort s;
     		s.sortfunc(c1,happiness,k);
	        s.sortfunc(c2,compatibility,k);
	      

		printf("\n");

	}
	void Initialize::printi()
        {
		int i=0;
		int k1=rand()%5;
		cout<<"k happiest couples:-"<<"\n";
                for(i=0;i<k1;i++)
                         cout<<c1[i].b->name<<" "<<c1[i].g->name<<"\n";
		cout<<"k most compatible couples:-"<<"\n";
               for(i=0;i<k1;i++)
                        cout<<c2[i].b->name<<" "<<c2[i].g->name<<"\n";
        }
		
	void Initialize::printcouples()
        {
               int i=0;
               for(i=0;i<k;i++)
                        cout<<c[i].b->name<<" "<<c[i].g->name<<"\n";
        }

	void Initialize::breakup(int k1)
	{

		printf("least k happy couples before breakup:-\n");
		int i=k-1;
		int j=0;
		while(j<k1)
		{
			cout<<c1[i].b->name<<" "<<c1[i].g->name<<"\n";
			c1[i].b->committed=0;
			c1[i].g->committed=0;
			j++;
			i--;
		}
		
	}
	void Initialize::allocafterbreakup(int k1)
	{
		int i=k-1;
                int j=0;
		l=0;
		Criteria2 ob;
                while(j<k1)
                {
			int bfin;
                        bfin=ob.checkCriteria(c1[i].g,c1[i].b,boy,nb);
                        if(bfin!=-1)
                        {
                                nc[l++].makeCouple(boy[bfin],c1[i].g);
                        }
                        j++;
                        i--;
                }
	}
	void Initialize::printnewcouple()
	{
		printf("new couples formed after breakup:-\n");
		int i;
		for(i=0;i<l;i++)
			printf("%d %d\n",nc[i].b->name,nc[i].g->name);
	}
	void Initialize::breakupt(int t)
        {

                printf("couples with happiness less than t:-\n");
                int i;
                for(i=0;i<k;i++)
                {
			if(c1[i].happiness<t)
                        {
				cout<<c1[i].b->name<<" "<<c1[i].g->name<<"\n";
                	        c1[i].b->committed=0;
                        	c1[i].g->committed=0;
                      	}
	       }

        }

	void Initialize::allocafterbreakupt(int t)
        {
                int i=0;
                z=0;
                Criteria2 ob;
                for(i=0;i<k;i++)
                {
			if(c1[i].happiness<t)
                        {
				int bfin;
                       		bfin=ob.checkCriteria(c1[i].g,c1[i].b,boy,nb);
                	        if(bfin!=-1)
                       		{
                                	tc[z++].makeCouple(boy[bfin],c1[i].g);
                        	}
                        }	
                }
        }
	void Initialize::printnewcouplet()
        {
                printf("new couples formed after breakup:-\n");
                int i;
                for(i=0;i<z;i++)
                        printf("%d %d\n",tc[i].b->name,tc[i].g->name);
        }
	
	void Initialize::search(int choice)
	{
		Search *ob;
		if(choice==1)
		{
			array *ob1=(array *)ob;
			ob1->searchgf(boy,c,nb,k);
		}
		else if(choice ==2)
		{
			binarray *ob1=(binarray *)ob;
			ob1->searchgf(boy,c,nb,k);
		}
		else
		{
			hash *ob1=(hash *)ob;
			ob1->searchgf(boy,c,nb,k);
		}
	}
