#include "hash.h"
#include "Search.h"
#include <bits/stdc++.h>
using namespace std;

        void hash::searchgf(Boy *by[100],Couple c[100],int nb,int k)
        {
                int a[500];
                int i;
                for(i=0;i<=500;i++)
                        a[i]=-1;
                for(i=0;i<k;i++)
                {
                        a[c[i].b->name-1]=c[i].g->name;
                }
                for(i=0;i<nb;i++)
                {
                        if(a[i]==-1)
                                printf("%d has no gf\n",by[i]->name);
                        else
                                printf("%d has %d as gf\n",by[i]->name,a[i]);
                }
        }

