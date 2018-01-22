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
#define MAX_N 1005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-4;

typedef long long ll;
int n,k;
double A[MAX_N],B[MAX_N];
double C[MAX_N];

bool mycmp(const double &a,const double &b){
    return a>b;
}

bool Check(double x){
    for (int i=0; i<n; i++) {
        C[i]=100*A[i]-x*B[i];
    }
    sort(C,C+n,mycmp);
    double sum=0;
    for (int i=0; i<n-k; i++) {
        sum+=C[i];
    }
    return sum>=0;
}

void solve(){
    double l=0,r=G_INF,mid;
    rep(100) {
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if (Check(mid)) {
            l=mid;
        }else{
            r=mid;
        }
    }
    printf("%.0f\n",l);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d %d",&n,&k)!=EOF && !(n==0 && k==0)) {
        for (int i=0; i<n; i++) {
            scanf("%lf",&A[i]);
        }
        for (int i=0; i<n; i++) {
            scanf("%lf",&B[i]);
        }
        solve();
    }
    
    return 0;
}