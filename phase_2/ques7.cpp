#include <bits/stdc++.h>
#include "Initialize.h"
using namespace std;

int main()
{
	Initialize ob;
	ob.initiate();
	printf("all couples formed are:-\n");
	ob.printcouples();
	int choice;
	choice=rand()%3+1;
	if(choice==1)
		printf("search done using arrays\n");
	else if(choice ==2)
		printf("search done using binary search\n");
	else
		printf("search done using hash table\n");
	ob.search(choice);	
}
