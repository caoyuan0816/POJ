#include <iostream>
#include <algorithm>
#include <cstdio>

#define MY_MIN 0

using namespace std;

static int dp[13000];

int main(void)
{
	int N,V,i,j,w,p;

	scanf("%d%d",&N,&V);

	scanf("%d%d",&w,&p);
	for(j=1;j<=V;j++)
	{
		if(j>=w)
			dp[j]=p;
	}

	for(i=2;i<=N;i++)
	{
		scanf("%d%d",&w,&p);
		for(j=V;j>=1;j--)
		{
			if(j-w>0)
				dp[j]=max(dp[j],dp[j-w]+p);
			else if(j-w==0)
				dp[j]=max(p,dp[j]);
			else
				dp[j]=dp[j];
		}
	}
	int fee=MY_MIN;
	
	for(i=N,j=1;j<=V;j++)
	{
		fee=max(fee,dp[j]);
	}

	cout<<fee<<endl;

return 0;	
}