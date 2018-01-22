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
#define MAX_N 1000000

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;
const int eps=10e-8;

int N;
int dp[MAX_N];

void solve(){
    dp[1]=1;
    dp[2]=2;
    for (int i=3; i<=N; i++) {
        if (i%2!=0) {
            dp[i]=dp[i-1]%1000000000;
        }else{
            dp[i]=(dp[i-2]+dp[i/2])%1000000000;
        }
    }
    printf("%d\n",dp[N]);
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&N);
    solve();
    
    return 0;
}
