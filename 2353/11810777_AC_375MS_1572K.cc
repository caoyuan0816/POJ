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