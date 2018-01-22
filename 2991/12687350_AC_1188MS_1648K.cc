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
#define PI acos(-1.0)

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;
const int ST_SIZE=(1<<15)-1;

int N,Q;
int L[MAX_N],S[MAX_N],A[MAX_N];

double X[ST_SIZE],Y[ST_SIZE];
double ang[ST_SIZE];
double prv[MAX_N];

//[0,N)
void init(int v,int l,int r){
    ang[v]=X[v]=0.0;
    if (r-l==1) {
        Y[v]=L[l];
    }else{
        init(v*2+1, l, (l+r)/2);
        init(v*2+2, (l+r)/2, r);
        Y[v]=Y[v*2+1]+Y[v*2+2];
    }
}

void change(int s,double a,int v,int l,int r){
    if (s<=l) {
        return ;
    }else if (s<r){
        change(s, a, v*2+1, l, (l+r)/2);
        change(s, a, v*2+2, (l+r)/2, r);
        if (s<=(l+r)/2) {
            ang[v]+=a;
        }
        X[v]=X[v*2+1]+(cos(ang[v])*X[v*2+2]-sin(ang[v])*Y[v*2+2]);
        Y[v]=Y[v*2+1]+(sin(ang[v])*X[v*2+2]+cos(ang[v])*Y[v*2+2]);
    }
}

void solve(){
    init(0,0,N);
    fill(prv, prv+N, PI);
    
    for (int i=0; i<Q; i++) {
        int s=S[i];
        double a=(A[i]/360.0)*2*PI;
        change(s,a-prv[s],0,0,N);
        prv[s]=a;
        printf("%.2f %.2f\n",X[0],Y[0]);
    }
}

int main(void){
    
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int q=0;
    while (scanf("%d %d",&N,&Q)!=EOF) {
        if (q++!=0) {
            puts("");
        }
        for (int i=0; i<N; i++) {
            scanf("%d",&L[i]);
        }
        for (int i=0; i<Q; i++) {
            scanf("%d %d",&S[i],&A[i]);
        }
        solve();
    }
    
    return 0;
}
