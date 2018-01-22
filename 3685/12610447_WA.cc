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
int N,M,m;

int fun1(){
    
    int l=0,r=N+1,mid;
    while (r-l>1) {
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if ((1+mid)*mid/2<=M) {
            l=mid;
        }else{
            r=mid;
        }
    }
    return l;
}

int fun2(){
    
    m=M-(N+1)*N/2;
    
    int l=0,r=N+1,mid;
    while (r-l>1) {
        mid=(l+r)/2;
        //cout<<"fff"<<l<<" "<<mid<<" "<<r<<endl;
        if ((2*N-mid-1)*(mid)/2 <=m && N-mid>=1) {
            l=mid;
        }else{
            r=mid;
        }
    }
    return l;
}

void solve(){
    
    if (M<=(N*(N+1)/2)) {
        int u=fun1();
        int i,j,k=M-(1+u)*u/2;
        if (k==0) {
            j=N,i=u;
        }else{
            j=N-u,i=1;k--;
            j+=k;i+=k;
        }
        cout<<i*i+j*j+100000*i-100000*j+i*j<<endl;
    }else{
        int u=fun2();
        int i,j,k=m-(2*N-u-1)*(u)/2;
        if (k==0) {
            j=N-u,i=N;
        }else{
            j=1;i=N-u-1;k--;
            i+=k;j+=k;
        }
        cout<<i*i+j*j+100000*i-100000*j+i*j<<endl;
    }
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int T;
    scanf("%d",&T);
    rep(T){
        scanf("%d %d",&N,&M);
        solve();
    }
    
    return 0;
}
