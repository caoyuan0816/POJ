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
#define MAX_N 45005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;

ll M,N;
ll A[MAX_N],B[MAX_N];

int S=20;

ll mult_mod(ll a,ll b,ll mod){
    a%=mod;
    b%=mod;
    ll res=0;
    while (b) {
        if (b&1) {
            res+=a;res%=mod;
        }
        a<<=1;
        if (a>=mod) {
            a%=mod;
        }
        b>>=1;
    }
    return res;
}

ll pow_mod (ll x, ll n ,ll mod){
    x%=mod;
    ll res=1;
    while (n>0) {
        if (n&1) {
            res=mult_mod(res, x, mod);
        }
        x=mult_mod(x, x, mod);
        n>>=1;
    }
    return res;
}

void solve(){
    ll res=0;
    for (int i=0; i<N; i++) {
        res=(res+pow_mod(A[i], B[i], M))%M;
    }
    printf("%lld\n",res);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int T;
    scanf("%d",&T);
    rep(T){
        scanf("%lld %lld",&M,&N);
        for (int i=0; i<N; i++) {
            scanf("%lld %lld",&A[i],&B[i]);
        }
        solve();
    }
    
    return 0;
}