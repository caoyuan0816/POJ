//
//  main.cpp
//  test
//
//  Created by Yuan on 14-1-29.
//  Copyright (c) 2014年 Yuan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 1005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const int eps=10e-8;

int N;
int dp[MAX_N][MAX_N];

void solve(){
    for (int i=0; i<N; i++) {
        for (int j=1; j<N; j++) {
            dp[i][j]+=dp[i][j-1];
        }
    }
    int res=MIN;
    for (int j=0; j<N; j++) {
        res=max(res, dp[0][j]);
        for (int i=1; i<N; i++) {
            dp[i][j]=max(dp[i][j],dp[i-1][j]+dp[i][j]);
            res=max(res, dp[i][j]);
        }
    }
//    for (int i=0; i<N; i++) {
//        for (int j=0; j<N; j++) {
//            cout<<dp[i][j]<<"  ";
//        }cout<<endl;
//    }
    
    printf("%d\n",res);
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d",&dp[i][j]);
        }
    }
    if(N==1){
        printf("%d\n",dp[0][0]);
        return 0;
    }
    
    solve();
    
    return 0;
}
