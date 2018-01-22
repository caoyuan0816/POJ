#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define MY_MIN 1

using namespace std;

static int a[10000000];
static int dp[10000000];
static long long Ccount=0;
static int ans=MY_MIN;

int main(void)
{
	int i,j,d,k=0;
	while(1)
	{
		while(1)
		{
			scanf("%d",&d);
			if(d==-1)
				{
					k++;break;
				}
			a[Ccount++]=d;
		}
		if(Ccount==0)
			return 0;
		for(i=0;i<Ccount;i++)
		{
			dp[i]=1;
			for(j=0;j<i;j++)
			{
				if(a[j]>a[i])
					dp[i]=max(dp[i],dp[j]+1);
				ans=max(ans,dp[i]);
			}
		}
		if(k!=1)
			putchar('\n');
		printf("Test #%d:\n  maximum possible interceptions: %d\n",k,ans);
		Ccount=0;ans=MY_MIN;
	}

return 0;	
}