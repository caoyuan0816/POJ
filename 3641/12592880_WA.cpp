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
#define MAX_N 10005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;

ll P,A;
int S=50;

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

bool Witness(ll a, ll n, ll d,ll r){
    ll y,x=pow_mod(a, d, n);
    while (r--) {
        y=mult_mod(x, x, n);
        if (y==1 && x!=1 && x!=n-1) {
            return true;
        }
        x=y;
    }
    if (y!=1) {
        return true;
    }
    return false;
}

bool Miller_Rabin(ll n){
    if (n<2) {
        return false;
    }
    if (n==2) {
        return true;
    }
    if ((n&1)==0) {
        return false;
    }
    ll d=n-1,r=0;        //分解n-1为 d*2^r
    while ((d&1)==0) {
        r++;d>>=1;
    }
    for (int i=0; i<S; i++) {
        ll a=(rand()%(n-1))+1;   //a -> [1,n-1]
        if (Witness(a, n, d, r)) {
            return false;
        }
    }
    return true;
}

void solve(){
    if (!Miller_Rabin(P) && pow_mod(A, P, P)==A) {
        printf("yse\n");
    }else{
        printf("no\n");
    }
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%lld %lld",&P,&A) && !(P==0 && A==0)) {
        solve();
    }
    
    return 0;
}