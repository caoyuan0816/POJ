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
ll H_prime[250001],tot_p;
bool is_H_prime[250001];
ll H_semi_prime[250001],tot_sp;
ll N;

void do_first(){
    tot_p=0;
    fill(is_H_prime, is_H_prime+250001, true);
    is_H_prime[0]=is_H_prime[1]=true;
    for (ll i=1; i<250001; i++) {
        if (is_H_prime[i]) {
            ll u=i*4+1;
            H_prime[tot_p++]=u;
            for (ll j=(u)*(u); j<=1000001; j+=4*(u)) {
                is_H_prime[(j-1)/4]=false;
            }
        }
    }
    
    tot_sp=0;
    for (ll i=0; i<250001; i++) {
        if (!is_H_prime[i]) {
            long long v=i*4+1;
            double q=sqrt(v);
            for (ll j=0; j<tot_p && H_prime[j]<=q; j++) {
                if ((v)%H_prime[j]==0) {
                    ll u=(v)/H_prime[j];
                    if (u%4==1 && is_H_prime[(u-1)/4]) {
                        H_semi_prime[tot_sp++]=v;
                        break;
                    }
                    if (u%4==1 && !is_H_prime[(u-1)/4]) {
                        break;
                    }
                }
            }
        }
    }
}

void solve(){
    printf("%lld %ld\n",N,lower_bound(H_semi_prime, H_semi_prime+tot_sp, N+1)-H_semi_prime);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    do_first();
    
    while (scanf("%lld",&N) && N!=0) {
        solve();
    }
    
    return 0;
}