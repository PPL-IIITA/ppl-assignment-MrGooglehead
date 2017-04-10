#include "Gift.h"
#include "Essential.h"
#include "Luxury.h"
#include "Utility.h"
#include "Geek.h"
#include "Girl.h"
#include <bits/stdc++.h>
using namespace std;

        int Geek::giveGifts(Gift Giftbasket[100],Girl g)
        {
                freopen("giftlist.txt","r",stdin);
                int ngifts;
                cin>>ngifts;
                int giftTot=0;
                int bmax=budget;
                int tid,ttype,tprice,tvalue,tr,td,tuc,tuv;
                int k=0;
		printf("allocating\n");
                while(giftTot <= g.mbudget)
                {
                        cin>>tid>>ttype>>tprice>>tvalue>>tr>>td>>tuc>>tuv;
                        giftTot+=tprice;
                        if(ttype==1)
                        {
                                Essential ob;
                                ob.id=tid;
                                ob.price=tprice;
				ob.type=1;
                                ob.value=tvalue;
                                Giftbasket[k++]=ob;
                        }
                        else if (ttype==2)
                        {
                                Luxury ob;
                                ob.id=tid;
                                ob.price=tprice;
				ob.type=2;
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
		printf("extra gift\n");
		while(ngifts)
		{
			cin>>tid>>ttype>>tprice>>tvalue>>tr>>td>>tuc>>tuv;
			if (ttype==2)
                        {
				bmax-=tprice;
				if(bmax>=0)
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
					break;
			}
			ngifts--;
		}
		printf("done allocating\n");
		return k;
	}
