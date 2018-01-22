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
#define MAX_N 355

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;
const int eps=10e-8;

int N;
int v[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void solve(){
    dp[0][1]=v[0][1];
    int ans=v[0][1];
    for (int i=1; i<N; i++) {
        for (int j=1; j<=i+1; j++) {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+v[i][j];
            ans=max(dp[i][j], ans);
        }
    }
    printf("%d\n",ans);
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    memset(v, 0, sizeof(v));
    memset(dp, 0, sizeof(dp));
    
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        for (int j=1; j<=i+1; j++) {
            scanf("%d",&v[i][j]);
        }
    }
    solve();
    
    return 0;
}
