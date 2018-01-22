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

int N;
double A;

double Check(double x){
    double Hi_2=A,Hi_1=x,Hi;
    rep(N-2){
        Hi=2*Hi_1+2-Hi_2;
        if (Hi<0) {
            return -1;
        }
        Hi_2=Hi_1;
        Hi_1=Hi;
    }
    return Hi;
}

void solve(){
    
    double l=0,r=G_INF,mid,ans;
    rep(100){
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        ans=Check(mid);
        if (ans>0) {
            r=mid;
        }else{
            l=mid;
        }
    }
    printf("%.2f\n",ans);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d %lf",&N,&A)!=EOF) {
        solve();
    }
    
    return 0;
}
