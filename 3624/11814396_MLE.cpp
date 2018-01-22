#include <iostream>
#include <algorithm>
#include <cstdio>

#define MY_MIN 0

using namespace std;

static int dp[3500][13000];

int main(void)
{
	int N,V,i,j,w,p;

	scanf("%d%d",&N,&V);

	scanf("%d%d",&w,&p);
	for(j=1;j<=V;j++)
	{
		if(j>=w)
			dp[1][j]=p;
	}

	for(i=2;i<=N;i++)
	{
		scanf("%d%d",&w,&p);
		for(j=1;j<=V;j++)
		{
			if(j-w>0)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+p);
			else if(j==w)
				dp[i][j]=max(p,dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	int fee=MY_MIN;
	
	for(i=N,j=1;j<=V;j++)
	{
		fee=max(fee,dp[i][j]);
	}

	cout<<fee<<endl;

return 0;	
}