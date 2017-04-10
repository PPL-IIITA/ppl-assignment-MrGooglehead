#include "GenerateGifts.h"
#include <bits/stdc++.h>
using namespace std;
		void GenerateGifts::generate()/**member function for randomly generating gifts and later sorting them*/
		{
			ofstream fp;
			fp.open("giftlist.txt");
			int n;	
			n=rand()%10+95;
			fp<<n<<"\n";
			int i=0;
			int id[200];
			int t[200];
			int p[200];
			int rt[200];
			int ucl[200];
			int uvl[200];
			for(i=0;i<n;i++)
			{
				id[i]=i+1;
				int type;
				type=rand()%3+1;
				t[i]=type;
				int price;
				price=rand()%20+10;
				p[i]=price;
				int r=0,uc=0,uv=0;
				if(type==2)
					r=rand()%5+5;
				else if(type==3)
				{
					uc=rand()%3+1;
					uv=rand()%10+40;
				}
				rt[i]=r;
				ucl[i]=uc;
				uvl[i]=uv;
				fp<<i+1<<" "<<type<<" "<<price<<" "<<r<<" "<<uc<<" "<<uv<<"\n";
			}
			fp.close();
			int j=0;
			for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-1-i;j++)
				{
					if(p[j]>p[j+1])
					{
						int t1=p[j];	
						p[j]=p[j+1];
						p[j+1]=t1;
			
						t1=id[j];
						id[j]=id[j+1];
						id[j+1]=t1;
			
						t1=t[j];
						t[j]=t[j+1];
						t[j+1]=t1;
			
						t1=rt[j];
						rt[j]=rt[j+1];
						rt[j+1]=t1;
			
						t1=ucl[j];
						ucl[j]=ucl[j+1];
						ucl[j+1]=t1;
		
						t1=uvl[j];
						uvl[j]=uvl[j+1];		
						uvl[j+1]=t1;
					}
				}
			}
			fp.open("giftlist.txt");
			fp<<n<<"\n";
			for(i=0;i<n;i++)
				fp<<id[i]<<" "<<t[i]<<" "<<p[i]<<" "<<rt[i]<<" "<<ucl[i]<<" "<<uvl[i]<<"\n";
		
		}
