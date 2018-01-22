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
const int eps=10e-3;

int N,K;
double L[MAX_N];

bool check(double x){
    int sum=0;
    for (int i=0; i<N; i++) {
        sum+=(floor(L[i]/x));
    }
    return sum>=K;
}

void solve(){
    double l=0,r=INF,mid;
    
    rep(100) {
        mid=(l+r)/2;
        if (check(mid)) {
            l=mid;
        }else{
            r=mid;
        }
    }
    printf("%.2lf\n",floor(mid*100)/100);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d %d",&N,&K)!=EOF) {
        for (int i=0; i<N; i++) {
            scanf("%lf",&L[i]);
        }
        solve();
    }

    return 0;
}