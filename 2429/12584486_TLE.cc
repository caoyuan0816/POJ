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
typedef pair<int, int> P;
ll gcd,lcm;
ll res_a,res_b,res;
int k;
P fac[MAX_N];

ll my_pow(ll a, ll b){
    ll res=1;
    while (b>0) {
        if(b&1){
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}

void dfs(int level,ll a,ll b){
    if (level==k) {
        if (a!=0 && b!=0 && a+b<res) {
            res=a+b;
            res_a=a;
            res_b=b;
        }
        return ;
    }
    dfs(level+1, a+my_pow(fac[level].first,fac[level].second), b);
    dfs(level+1, a, b+my_pow(fac[level].first,fac[level].second));
}

void solve(){
    ll c=lcm/gcd;
    
    fac[k++]=P(1,1);
    for (ll i=2; i*i<=c; i++) {
        if (c%i==0) {
            int use=0;
            while (c%i==0) {
                use++;
                c/=i;
            }
            fac[k++]=P(i,use);
        }
    }
    if (c!=1) {
        fac[k++]=P(c,1);
    }
    res=L_INF;
    dfs(0,0,0);
    if (res_a>res_b) {
        swap(res_a, res_b);
    }
    printf("%lld %lld\n",gcd*res_a,gcd*res_b);
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%lld %lld",&gcd,&lcm)!=EOF) {
        k=0;
        solve();
    }
    
    return 0;
}
