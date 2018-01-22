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
		if(Coo>100)
			return 0;
	}

return 0;
}

/*
#include <iostream>
#include <cstdio>
using namespace std;

int fee[101][501],dp[101][501],ans[50000] ;
struct point
{
      int x,y ;
} way[101][501] ;
int main()
{
      int m,n ;
      scanf("%d%d",&m,&n) ;
      for (int i=1 ; i<=m ; i++){
            for (int j=1 ; j<=n ; j++){
                  scanf("%d",&fee[i][j]) ;
            }
      }
      for (int j=1 ; j<=n ; j++){
            dp[1][j] = fee[1][j] ;
            way[1][j].x = j ;
            way[1][j].y = 0 ;
      }
      for (int i=2 ; i<=m ; i++){
            for (int j=1 ; j<=n ; j++){
                  dp[i][j] = fee[i][j] + dp[i-1][j]  ;
                  way[i][j].x = j ;
                  way[i][j].y = i-1 ;
            }
            for (int j=2 ; j<=n ; j++){
                  if (dp[i][j]>dp[i][j-1] + fee[i][j]){
                        dp[i][j] = dp[i][j-1] + fee[i][j] ;
                        way[i][j].x = j-1 ;
                        way[i][j].y = i ;
                  }
            }
            for (int j=n-1 ; j>=1 ; j--){
                  if (dp[i][j]>dp[i][j+1] + fee[i][j]){
                        dp[i][j] = dp[i][j+1] + fee[i][j] ;
                        way[i][j].x = j+1 ;
                        way[i][j].y = i ;
                  }
            }
      }
      int temp=dp[m][1],tempx = 1 ;
      for (int j=2 ; j<=n ; j++){
            if (temp>dp[m][j]){
                  temp = dp[m][j] ;
                  tempx = j ;
            }
      }
      int end=1,temp1,temp2 ;
      int tempy = m ;
      while (tempy){
            ans[end++] = tempx ;
            temp1 = tempx , temp2 = tempy;
            tempx = way[temp2][temp1].x ;
            tempy = way[temp2][temp1].y ;
      }
      while (--end){
            printf ("%d\n",ans[end]) ;
      }
    return 0;
}
*/