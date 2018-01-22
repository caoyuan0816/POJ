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
const int eps=10e-8;

typedef long long ll;
typedef pair<int, int> P;
ll gcd,lcm;
ll res_a,res_b,res;
vector<P> fac;

void dfs(int level,ll a,ll b){
    if (level==fac.size()) {
        if (a!=0 && b!=0 && a+b>res) {
            res=a+b;
            res_a=a;
            res_b=b;
        }
        return ;
    }
    dfs(level+1, a+pow(fac[level].first,fac[level].second), b);
    dfs(level+1, a, b+pow(fac[level].first,fac[level].second));
}

void solve(){
    ll c=lcm/gcd;
    
    for (ll i=2; i*i<c; i++) {
        if (c%i==0) {
            int use=0;
            while (c%i==0) {
                use++;
                c/=i;
            }
            fac.push_back(P(i,use));
        }
    }
    if (c!=1) {
        fac.push_back(P(c,1));
    }
    res=0;
    dfs(0,0,0);
    if (res_a>res_b) {
        swap(res_a, res_b);
    }
    printf("%lld %lld\n",gcd*res_a,gcd*res_b);
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%lld %lld",&gcd,&lcm)!=EOF) {
        fac.clear();
        solve();
    }
    
    return 0;
}
