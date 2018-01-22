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
#define MAX_N 50005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int L,N,M;
int X[MAX_N];

bool Check(int d){
    int i=0,crt,sum=0;
    while (i<N) {
        crt=i+1;
        while (crt<N && X[crt]-X[i]<d) {
            crt++;sum++;
        }
        i=crt;
        if (sum>M) {
            return false;
        }
    }
    return true;
}

void solve(){
    int l=0,r=L,mid;
    while (r-l>1) {
        mid=(l+r)/2;
        if (Check(mid)) {
            l=mid;
        }else{
            r=mid;
        }
    }
    printf("%d\n",l);
}

int main(void){
    
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d %d",&L,&N,&M);
    
    if (M==N) {
        printf("%d\n",L);
        return 0;
    }
    
    X[0]=0;
    for (int i=1; i<=N; i++) {
        scanf("%d",&X[i]);
    }
    X[N+1]=L;N+=2;
    sort(X,X+N);
    
    solve();
    
    return 0;
}