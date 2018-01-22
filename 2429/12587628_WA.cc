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
ll gcd_n,lcm_n;
ll res_a,res_b,res_min;
int tot;
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
    x%=m;
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

ll gcd(ll a,ll b)
{
    //if(a==0)return 1;
    if(a<0) return gcd(-a,b);
    while(b){
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}

ll Pollard_rho(ll n, ll c)
{
	ll x, y, d, i = 1, k = 2;
	x = rand() % (n - 1) + 1;
	y = x;
	while (true) {
		i++;
		x = (mult_mod(x, x, n) + c) % n;
		d = gcd(y - x, n);
		if ((1 < d) && (d < n))
			return d;
		if (x == y)
			return n;
		if (i == k)
			y = x, k <<= 1;
	}
}

void findfac(ll n)
{
    if(Miller_Rabin(n))
    {
        fac[tot++]=n;
        return;
    }
    ll p=n;
    while(p>=n){
        p=Pollard_rho(p,(rand()%(n-1))+1);
    }
    findfac(p);
    findfac(n/p);
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

void dfs(int level,ll now,ll n){
    if (now*now>n) {
        return ;
    }
    if (level==tot) {
        ll a,b;
        a=now;
        b=n/now;
        if (a+b<res_min) {
            res_min=a+b;
            res_a=a;
            res_b=b;
        }
        return ;
    }
    dfs(level+1, now*fac[level],n);
    dfs(level+1, now,n);
}

void solve(){
    ll c=lcm_n/gcd_n;
    
    if (c==1) {
        printf("%lld %lld\n",gcd_n,gcd_n);
        return ;
    }

    if (Miller_Rabin(c)) {
        printf("%lld %lld\n",gcd_n,gcd_n*c);
        return ;
    }else{
        findfac(c);
    }

    res_min=L_INF;
    dfs(0,1,c);
    if (res_a>res_b) {
        ll use=res_a;
        res_b=res_a;
        res_a=use;
    }
    printf("%lld %lld\n",gcd_n*res_a,gcd_n*res_b);
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%lld %lld",&gcd_n,&lcm_n)==2) {
        tot=0;
        solve();
    }
    
    return 0;
}
