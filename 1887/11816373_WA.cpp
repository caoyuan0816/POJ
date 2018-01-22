#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define MY_MIN 1

using namespace std;

static int a[10000000];
static int dp[10000000];
static int Ccount=0;
static int ans=MY_MIN;

int find(int b){
	int h;
	for(h=b-1;h>=0;h--){
		if(a[h]>a[b])
			{return h;}
	}
return -1;
}

int main(void)
{
	int i,d,k=1;
	dp[0]=1;
	while(1)
	{
		scanf("%d",&d);
		if(d==-1)
		{	
			if(Ccount!=0 && k!=1)
				putchar('\n');
			if(Ccount==0)
				return 0;
			else
			{
				printf("Test #%d:\n  maximum possible interceptions: %d\n",k,ans);
				ans=MY_MIN;
				k++;
				Ccount=0;
				dp[0]=1;
				continue;
			}
			
		}

		if(Ccount==0)
		{
				a[Ccount++]=d;
				continue;
		}
		else
		{
			a[Ccount++]=d;

			if(a[Ccount-1]<a[Ccount-2])
			{
				dp[Ccount-1]=dp[Ccount-2]+1;
			}
			else
			{
				d=find(Ccount-1);
				if(d!=-1)
					dp[Ccount-1]=dp[d]+1;
				else
					dp[Ccount-1]=1;
			}

			ans=max(ans,dp[Ccount-1]);
		}
	}

return 0;	
}