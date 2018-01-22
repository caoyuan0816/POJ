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

ll N,M;

bool ReCheck(ll x,ll j,ll ans){
    ll use=x*x+100000*x+j*x-100000*j+j*j;
    return use>ans;
}

bool Check(ll x){
    ll sum=0;
    for (ll j=1; j<=N; j++) {
        if (x<(1+100000+j-100000*j+j*j)) {
            continue;
        }
        if (x>=(N*N+100000*N+j*N-100000*j+j*j)) {
            sum+=N;continue;
        }
        
        //二分i
        ll l=1,r=N,mid;
        while (r-l>1) {
            mid=(l+r)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            if (ReCheck(mid,j,x)) {
                r=mid;
            }else{
                l=mid;
            }
        }
        
        //cout<<"j= "<<j<<" i= "<<r<<endl;
        sum+=l;
    }
    return sum>=M;
}

void solve(){
    
    ll l=-1*L_INF/2,r=L_INF/2,mid;
    while (r-l>1) {
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if (Check(mid)) {
            r=mid;
        }else{
            l=mid;
        }
    }
    printf("%lld\n",r);
}

int main(void){
    
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int T;
    scanf("%d",&T);
    rep(T){
        scanf("%lld %lld",&N,&M);
        solve();
    }
    
    return 0;
}