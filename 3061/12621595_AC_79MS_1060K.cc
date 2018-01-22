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
#define MAX_N 100005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int N,S;
int num[MAX_N];

void solve(){
    int s=0,t=0,sum=0;
    int res=N+1;
    while (true) {
        while (t<N && sum<S) {
            sum+=num[t++];
            
        }
        if (sum<S) {
            break;
        }
        res=min(res,t-s);
        sum-=num[s++];
    }
    if (res>N) {
        printf("0\n");
    }else{
        printf("%d\n",res);
    }
    
    
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int T;
    scanf("%d",&T);
    rep(T){
        scanf("%d %d",&N,&S);
        for (int i=0; i<N; i++) {
            scanf("%d",&num[i]);
        }
        solve();
    }
    
    return 0;
}
