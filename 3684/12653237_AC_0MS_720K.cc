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

const double g=10.0;
int N,H,R,T;
double y[MAX_N];

double calcu(int T){
    if (T<0) {
        return H;
    }
    double t=sqrt(2*H/g);
    int k=(int)(T/t);
    if (k%2==0) {
        double d=T-k*t;
        return H-g*d*d/2;
    }else{
        double d=k*t+t-T;
        return H-g*d*d/2;
    }
}

void solve(){
    for (int i=0; i<N; i++) {
        y[i]=calcu(T-i);
    }
    sort(y, y+N);
    for (int i=0; i<N; i++) {
        printf("%.2f%c",y[i]+2*R*i/100.0,i==N-1?'\n':' ');
    }
}

int main(void){
    
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int f;
    scanf("%d",&f);
    rep(f){
        scanf("%d %d %d %d",&N,&H,&R,&T);
        solve();
    }
    
    return 0;
}
