#include "Generate.h"
#include <bits/stdc++.h>
using namespace std;
		void Generate::generate()/** member function for generating boys and girls*/
		{
			int n;
			ofstream fp;	
			fp.open("file.txt");
			n=rand()%10+90;
			fp<<n<<"\n";
			int i=0;
			int c=0;
			for(i=0;i<n;i++)
			{
				
				int attr=rand()%5+5;
				int intelligence=rand()%5+5;
				int b=rand()%100+50;
				int type=rand()%3+1;
				int min=rand()%1+5;
				fp<<i+1<<" "<<attr<<" "<<intelligence<<" "<<b<<" "<<type<<" "<<min<<" "<<c<<"\n";
			}
			n=rand()%10+45;
			fp<<n<<"\n";
			for(i=0;i<n;i++)
                        {
                                int attr=rand()%4+6;
                                int intelligence=rand()%5+5;
                                int b=rand()%50+50;
                                int type=rand()%3+1;
				int cri=rand()%3+1;
				fp<<i+1<<" "<<attr<<" "<<intelligence<<" "<<b<<" "<<type<<" "<<c<<" "<<cri<<"\n";
			}
		}
