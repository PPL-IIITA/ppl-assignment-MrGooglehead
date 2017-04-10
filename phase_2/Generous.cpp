#include "Gift.h"
#include "Essential.h"
#include "Luxury.h"
#include "Utility.h"
#include "Generous.h"
#include "Girl.h"
#include <bits/stdc++.h>

using namespace std;

        int Generous::giveGifts(Gift Giftbasket[100],Girl g)
        {
		printf("allocating\n");
                freopen("giftlist.txt","r",stdin);
                int ngifts;
                cin>>ngifts;
                int giftTot=0;
                int bmax=budget;
                int tid,ttype,tprice,tvalue,tr,td,tuc,tuv;
                int k=0;
                while(giftTot <= g.mbudget)
                {
                        cin>>tid>>ttype>>tprice>>tvalue>>tr>>td>>tuc>>tuv;
                        giftTot+=tprice;
                        if(ttype==1)
                        {
                                Essential ob;
                                ob.id=tid;
				ob.type=1;
                                ob.price=tprice;
                                ob.value=tvalue;
                                Giftbasket[k++]=ob;
                        }
                        else if (ttype==2)
                        {
                                Luxury ob;
                                ob.id=tid;
				ob.type=2;
                                ob.price=tprice;
                                ob.value=tvalue;
                                ob.r=tr;
                                ob.d=td;
                                Giftbasket[k++]=ob;
                        }
                        else
                        {
                                Utility ob;
                                ob.id=tid;
				ob.type=3;
                                ob.price=tprice;
                                ob.value=tvalue;
				 ob.uc=tuc;
                                ob.uv=tuv;
                                Giftbasket[k++]=ob;
                        }
                        bmax-=tprice;
                        if(bmax<0)
                                budget+=tprice+bmax;
                        ngifts--;
                }
		while(bmax>0)
		{
			cin>>tid>>ttype>>tprice>>tvalue>>tr>>td>>tuc>>tuv;
                       	bmax-=tprice;
			if(bmax>=0)
			{
                        	if(ttype==1)
                      	  	{
                        	        Essential ob;
                        	        ob.id=tid;
					ob.type=1;
                              		ob.price=tprice;
                            		ob.value=tvalue;
                                	Giftbasket[k++]=ob;
                        	}
                       		 else if (ttype==2)
                        	{
                                	Luxury ob;
                              		ob.id=tid;
					ob.type=2;
                               		ob.price=tprice;
                                	ob.value=tvalue;
                               		 ob.r=tr;
                             	   	ob.d=td;
                        	        Giftbasket[k++]=ob;
                        	}
                        	else
                        	{
                                	Utility ob;
                                	ob.id=tid;
                               		ob.price=tprice;
					ob.type=3;
                                	ob.value=tvalue;
                                 	ob.uc=tuc;
                                	ob.uv=tuv;
                                	Giftbasket[k++]=ob;
                        	}	
			}
			else
				break;
		}
		printf("done allocating\n");
		return k;
        }  				
