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
struct edge {
    vector<ll> num;
};
ll N;
vector<edge> res;

bool mycmp(const edge &a,const edge &b){
    return a.num.size()>b.num.size();
}

void solve(){
    ll s=1,t=1;
    ll sum=0;
    bool flag=true;
    while (flag) {
        while (sum<N) {
            sum+=t*t;
            if (t*t>N) {
                flag=false;break;
            }
            t++;
        }
        if (sum==N) {
            edge use;
            for (ll i=s; i<=t-1; i++) {
                use.num.push_back(i);
            }
            res.push_back(use);
        }
        sum-=s*s;
        s++;
    }
    sort(res.begin(), res.end(), mycmp);
    
    printf("%d\n",(int)res.size());
    for (int i=0; i<res.size(); i++) {
        printf("%d",(int)res[i].num.size());
        for (int j=0; j<res[i].num.size(); j++) {
            printf(" %lld",res[i].num[j]);
        }
        putchar('\n');
    }
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%lld",&N);
    
    solve();
    
    return 0;
}