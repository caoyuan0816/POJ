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

int N,K;
int X[MAX_N];

bool Check(int t){
    int sum=0;
    for (int i=0; i<N; i++) {
        if (X[i]-t>0) {
            sum+=ceil((double)(X[i]-t)/(double)K);
        }
        if (sum>t) {
            return false;
        }
    }
    return true;
}

void solve(){
    
    int l=0,r=G_INF,mid;
    while (r-l>1) {
        mid=(l+r)/2;
        if (Check(mid)) {
            r=mid;
        }else{
            l=mid;
        }
    }

    printf("%d\n",r);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&N);
    int use=0;
    for (int i=0; i<N; i++) {
        scanf("%d",&X[i]);
        use=max(use,X[i]);
    }
    scanf("%d",&K);K--;
    if (K==0) {
        printf("%d\n",use);
        return 0;
    }
    
    solve();
    
    return 0;
}