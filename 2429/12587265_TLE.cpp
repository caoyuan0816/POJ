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
ll gcd,lcm;
ll res_a,res_b,res;
int k;
int S=20;
ll fac[MAX_N];

ll mult_mod(ll a,ll b,ll m){
    a%=m;
    b%=m;
    ll res=0;
    while (b) {
        if (b&1) {
            res+=a;res%=m;
        }
        a<<=1;
        if (a>=m) {
            a%=m;
        }
        b>>=1;
    }
    return res;
}

ll pow_mod(ll x,ll n,ll m){
    ll res=1;
    while (n) {
        if (n&1) {
            res=mult_mod(res, x, m);
        }
        x=mult_mod(x, x, m);
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
    dfs(level+1, a*fac[level], b);
    dfs(level+1, a, b*fac[level]);
}

void solve(){
    ll c=lcm/gcd;

    if (Miller_Rabin(c)) {
        //cout<<"faf"<<endl;
        printf("%lld %lld\n",gcd*1,gcd*c);
        return ;
    }
    fac[k++]=1;
    for (ll i=2; i*i<=c; i++) {
        if (c%i==0) {
            int use=0;
            while (c%i==0) {
                use++;
                c/=i;
            }
            fac[k++]=my_pow(i, use);
            if (Miller_Rabin(c)) {
                break;
            }
        }
    }
    if (c!=1) {
        fac[k++]=c;
    }

    res=L_INF;
    dfs(0,1,1);
    if (res_a>res_b) {
        swap(res_a, res_b);
    }
    printf("%lld %lld\n",gcd*res_a,gcd*res_b);
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%lld %lld",&gcd,&lcm)==2) {
        k=0;
        solve();
    }
    
    return 0;
}
