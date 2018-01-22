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
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;
typedef pair<ll, ll> P;
int tot,tot_p;
int prime[10005];
bool is_prime[10005];
P fac[MAX_N];
ll N;

void make_prime(){
    fill(is_prime, is_prime+10005, true);
    tot_p=0;
    is_prime[0]=is_prime[1]=false;
    for (int i=2; i<10005; i++) {
        if (is_prime[i]) {
            prime[tot_p++]=i;
            for (int j=2*i; j<10005; j+=i) {
                is_prime[j]=false;
            }
        }
    }
}

ll mult(ll n){
    ll res=1;
    for (ll i=1; i<=n; i++) {
        res*=i;
    }
    return res;
}

void solve(){
    tot=0;
    ll use=N;
    for (int i=0; i<tot_p; i++) {
        if (prime[i]>N) {
            break;
        }
        if (use%prime[i]==0) {
            int tmp=0;
            while (use%prime[i]==0) {
                tmp++;
                use/=prime[i];
            }
            fac[tot++]=P(prime[i],tmp);
        }
    }if (use!=1) {
        fac[tot++]=P(use,1);
    }
    ll sum=0,down=1;
    for (int i=0; i<tot; i++) {
        sum+=fac[i].second;
        down*=mult(fac[i].second);
    }
    ll ans=mult(sum)/down;

    printf("%lld %lld\n",sum,ans);
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    make_prime();
    
    while (scanf("%lld",&N)!=EOF) {
        solve();
    }
    
    return 0;
}
