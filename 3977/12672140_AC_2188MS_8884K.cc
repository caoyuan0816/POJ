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
#include <map>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 262150

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;
int N;
typedef pair<ll, int> P;
ll A[35],B[35],ans_sum;
P set_A[MAX_N];
P set_B[MAX_N];
int a,b,ans_num,tot;

void fun(ll x,int y){
    if (x<ans_sum) {
        ans_sum=x;ans_num=y;
    }else if(x==ans_sum){
        y<ans_num?ans_num=y:y;
    }
}

inline ll myabs(ll n){
    return n<0?(-1*n):n;
}

bool mycmp(const P &a,const P &b){
    return a.first<b.first;
}

void solve(){
    ans_sum=L_INF;ans_num=INF;
    int len=1<<a;
    ll sum;int num;
    for (int i=1; i<len; i++) {
        sum=0,num=0;
        for (int j=0; j<a; j++) {
            if (1&(i>>j)) {
                sum+=A[j];
                num++;
            }
        }
        set_A[i-1].first=sum;
        set_A[i-1].second=num;
    }
    sort(set_A, set_A+len-1);
    
    tot=0;
    set_B[tot]=set_A[0];tot++;
    for (int i=0; i<len-1; i++) {
        if (set_A[i].first>set_B[tot-1].first) {
            set_B[tot++]=set_A[i];
        }else if(set_A[i].first==set_B[tot-1].first){
            set_B[tot-1].second=set_A[i].second;
        }
    }

//num B = 0;
    for (int i=0; i<tot; i++) {
        fun(myabs(set_B[i].first), set_B[i].second);
    }
    len=1<<b;
    for (int i=1; i<len; i++) {
        sum=0;num=0;
        for (int j=0; j<b; j++) {
            if (1&(i>>j)) {
                sum+=B[j];
                num++;
            }
        }
        
//num A = 0;
        fun(myabs(sum), num);
        
        P *k=lower_bound(set_B, set_B+tot, P(-1*sum,0),mycmp);
        
        int v=(int)(k-set_B);
        
        for (int j=v-1>0?v-1:0; j<(v+1<tot?v+1:tot); j++) {
            fun(myabs(set_B[j].first+sum), set_B[j].second+num);
        }
    }
    printf("%lld %d\n",ans_sum,ans_num);
}

int main(void){
    
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d",&N)!=EOF && N!=0) {
        a=N/2+1;
        b=N-a;
        for (int i=0; i<a; i++) {
            scanf("%lld",&A[i]);
        }
        for (int i=0; i<b; i++) {
            scanf("%lld",&B[i]);
        }
        solve();
    }
    
    return 0;
}