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
#define MAX_N 50005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;
struct cow{
    ll W,S,sum;
};
cow C[MAX_N];
int N;
ll tot;

bool mycmp(const cow &a,const cow &b){
    return a.sum>b.sum;
}

void solve(){
    sort(C, C+N,mycmp);

    ll risk=-1*L_INF;
    for (int i=0; i<N; i++) {
        if (risk<=(tot-C[i].sum)) {
            risk=tot-C[i].sum;
        }
        tot-=C[i].W;
    }
    printf("%lld\n",risk);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&N);
    tot=0;
    for (int i=0; i<N; i++) {
        scanf("%lld %lld",&C[i].W,&C[i].S);
        C[i].sum=C[i].W+C[i].S;tot+=C[i].W;
    }
    
    solve();
    
    return 0;
}
