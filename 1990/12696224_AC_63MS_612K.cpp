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
#define MAX_N 20005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;
typedef pair<int, int> P;
int N;
P cow[MAX_N];
ll num[MAX_N+1],sum[MAX_N+1];
ll totsum;
int maxx;

void add(ll *bit,int i,int x){
    while (i<=maxx) {
        bit[i]+=x;
        i+=i&-i;
    }
}

ll get_sum(ll *bit,int i){
    ll s=0;
    while (i>0) {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

void solve(){
    sort(cow, cow+N);
    
    ll res=0;totsum=0;
    for (int i=0; i<N; i++) {
        add(num, cow[i].second, 1);
        add(sum, cow[i].second,cow[i].second);
        
        int x=cow[i].second;
        ll n=get_sum(num,x)-1;
        ll s=get_sum(sum,x)-x;
        
        res+=cow[i].first*(n*x-s+totsum-s-(i-n)*x);
        //cout<<cow[i].first<<"  "<<cow[i].second<<"  "<<n<<"  "<<s<<"  "<<res<<endl;
        totsum+=x;
    }
    printf("%lld\n",res);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&N);maxx=0;
    for (int i=0; i<N; i++) {
        scanf("%d %d",&cow[i].first,&cow[i].second);
        maxx=max(maxx,cow[i].second);
    }
    
    solve();
    
    return 0;
}
