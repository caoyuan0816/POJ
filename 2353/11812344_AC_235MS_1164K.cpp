#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define MY_MAX 1999999999;

using namespace std;

static long long a[110][510];
static long long dp[110][510];
static long long  ans[50000],kk=0;
static long long  fee=MY_MAX;

int main(void)
{
	int M,N,i,j,d;
	long long p;

	scanf("%d%d",&M,&N);
	if(M==0 && N==0){
		return 0;}
	if(N==1)
	{
		for(j=0;j<M;j++)
			printf("1\n");return 0;
	}
	if(M==1)
	{
		fee=1999999999;
		for(i=0;i<N;i++)
		{
			scanf("%lld",&p);
			if(p<fee){
				fee=p;
				j=i;
			}
		}printf("%d\n",j+1);return 0;
	}

	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}

	for(i=0;i<N;i++)
	{
		dp[0][i]=a[0][i];
	}

	for(i=0;i<N;i++)
	{
		dp[1][i]=dp[0][i]+a[1][i];
	}

	for(i=1;i<M-1;i++)
	{
		for(j=0;j<N-1;j++)
		{
			dp[i][j+1]=min(dp[i][j]+a[i][j+1],dp[i][j+1]);
		}
		for(j=N-1;j>=1;j--)
		{
			dp[i][j-1]=min(dp[i][j]+a[i][j-1],dp[i][j-1]);
		}
		for(j=0;j<N;j++)
		{
			dp[i+1][j]=dp[i][j]+a[i+1][j];
		}
	}

	i=M-1;
	long long use1,use=MY_MAX;
	for(j=0;j<N;j++)
	{
		if(dp[i][j]<use)
		{
			use=dp[i][j];
			use1=j;
		}
	}ans[kk++]=use1;

	for(i=M-1;i>0;i--)
	{
		while(1)
		{
			if(use1==0)
			{
				if(dp[i-1][use1]<=dp[i][use1+1])
				{
					ans[kk++]=use1;
					break;
				}
				else
				{
					ans[kk++]=use1+1;
					use1=use1+1;
					continue;
				}
			}
			else if(use1==N-1)
			{
				if(dp[i-1][use1]<=dp[i][use1-1])
				{
					ans[kk++]=use1;
					break;
				}
				else
				{
					ans[kk++]=use1-1;
					use1=use1-1;
					continue;
				}
			}
			else
			{
				if(dp[i-1][use1]<=dp[i][use1+1] && dp[i-1][use1]<=dp[i][use1-1])
				{
					ans[kk++]=use1;
					break;
				}
				else if(dp[i][use1-1]<=dp[i-1][use1] && dp[i][use1-1]<=dp[i][use1+1])
				{
					ans[kk++]=use1-1;
					use1=use1-1;
					continue;
				}
				else
				{
					ans[kk++]=use1+1;
					use1=use1+1;
					continue;
				}
			}
		}
	}

	for(i=kk-1;i>=0;i--)
		printf("%lld\n",ans[i]+1);

return 0;
}
