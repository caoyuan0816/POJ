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
#define MAX_N 100005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int N,m;
int num[MAX_N];

bool Check(int dist){
    int sum_s=0,sum_l=0;
    
    for (int i=0; i<N; i++) {
        int use=num[i]+dist;
        int *l=lower_bound(num+i, num+N, use);
        int *r=l,k=0;
        
        while (*(l+k)==use) {
            k++;
        }
        r=r+k;
        
        sum_s+=(int)(r-l);
        sum_l+=(int)(l-(num+i+1));
    }
    return (sum_s+sum_l) >= m;
}

void solve(){
    sort(num, num+N);
    
    int l=0,r=1000000000,mid;
    while (r-l>1) {
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if (Check(mid)) {
            r=mid;
        }else{
            l=mid;
        }
    }
    printf("%d\n",r);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d",&N)!=EOF) {
        for (int i=0; i<N; i++) {
            scanf("%d",&num[i]);
        }
        long long H;
        H=N*(N-1)/2;
        
        m=(int)H;
        
        if (m%2==0) {
            m=m/2;
        }else{
            m=m/2+1;
        }
        
        solve();
    }
    
    return 0;
}
