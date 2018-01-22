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
    if (y==0) {
        return;
    }
    if (x<ans_sum) {
        ans_sum=x;
        ans_num=y;
    }else if(x==ans_sum){
        ans_num<y?(ans_num=ans_num):(ans_num=y);
    }
}

ll myabs(ll n){
    return n<0?(-1*n):n;
}

bool mycmp(const P &a,const P &b){
    return a.first<b.first;
}

void solve(){
    memset(set_A, 0, sizeof(set_A));
    memset(set_B, 0, sizeof(set_B));
    ans_sum=L_INF;ans_num=INF;
    
    for (int i=0; i<(1<<a); i++) {
        for (int j=0; j<a; j++) {
            if (1&(i>>j)) {
                set_A[i].first+=A[j];
                set_A[i].second++;
            }
        }
    }
    sort(set_A+1, set_A+(1<<a));
    tot=0;
    set_B[tot]=P(-1,0);
    for (int i=1; i<(1<<a); i++) {
        if (set_A[i].first>set_B[tot].first) {
            set_B[++tot]=set_A[i];
        }
    }
//    for (int i=1; i<=tot; i++) {
//        cout<<set_B[i].first<<" "<<set_B[i].second<<endl;
//    }
    
    for (int i=0; i<(1<<b); i++) {
        ll sum=0;int num=0;
        for (int j=0; j<b; j++) {
            if (1&(i>>j)) {
                sum+=B[j];
                num++;
            }
        }
        fun(myabs(sum), num);
        
        P *k=lower_bound(set_B+1, set_B+tot+1, P(-1*sum,0),mycmp);
        
        //cout<<"find "<<-1*sum<<" res "<<k->first<<endl;
        
        fun(myabs(k->first+sum),k->second+num);
        
        if ((k-set_B)>1) {
            k--;
            fun(myabs(k->first+sum),k->second+num);
        }
        if ((k+2-set_B)<tot+1) {
            k+=2;
            fun(myabs(k->first+sum),k->second+num);
        }
        
    }
    printf("%lld %d\n",ans_sum,ans_num);
    //cout<<"........."<<endl;
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
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