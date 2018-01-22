#include <cstdio>
#include <cmath>
#include <iostream>

#define pi acos(-1.0)

using namespace std;

static double ans[10000];

int main(void)
{
	int p,e,i,d,n,ti=0;
	
	while(1)
	{
		ti++;
		scanf("%d%d%d%d",&p,&e,&i,&d);

		if(p==-1 && e==-1 && i==-1 && d==-1)
			return 0;
		
		n=(5544*p+14421*e+1288*i-d+21252)%21252;
		if(n==0)
			n=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",ti,n);
	}


return 0;	
}