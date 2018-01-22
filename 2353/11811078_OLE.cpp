#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define MY_MAX 9999999;

using namespace std;

static int a[110][510];
static int dp[110][510];
static int lu1,lu2,fu,fee=MY_MAX;
static int Coo=0;

int main(void)
{
	int M,N,i,j;

	scanf("%d%d",&M,&N);

	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	for(i=0;i<N;i++)
	{
		dp[0][i]=a[0][i];
	}

	for(i=0;i<N;i++)
	{
		dp[1][i]=dp[0][i]+a[1][i];
		if(dp[1][i]<fee)
		{
			fee=dp[1][i];
			lu1=i+1;
		}
		
	}printf("%d\n%d\n",lu1,lu1);


	for(i=1;i<M-1;i++)
	{
		fee=MY_MAX;
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
			if(fee>dp[i+1][j])
			{
				fee=dp[i+1][j];
				lu2=j+1;
				fu=abs(lu1-lu2);
			}
			else if(fee==dp[i+1][j] && abs(lu1-(j+1))<fu)
			{
				fu=abs(lu1-(j+1));
				lu2=j+1;
			}
			
		}
		//cout<<"lu1= "<<lu1<<"lu2= "<<lu2<<endl;
		if(lu1>lu2){
			for(j=lu1-1;j>=lu2;j--)
				printf("%d\n",j);Coo++;}
		else{
			for(j=lu1+1;j<=lu2;j++)
				printf("%d\n",j);Coo++;}
		
		lu1=lu2;printf("%d\n",lu1);Coo++;
		if(Coo>10e9)
			return 0;
	}

return 0;
}