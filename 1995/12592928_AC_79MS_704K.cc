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
#define MAX_N 45005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;

int M,N;
int A[MAX_N],B[MAX_N];

int pow_mod (int x, int n ,int mod){
    x%=mod;
    int res=1;
    while (n>0) {
        if (n&1) {
            res=res*x %mod;
        }
        x=x*x %mod;
        n>>=1;
    }
    return res;
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int T;
    scanf("%d",&T);
    rep(T){
        scanf("%d %d",&M,&N);
        int res=0;
        for (int i=0; i<N; i++) {
            scanf("%d %d",&A[i],&B[i]);
            res=(res+pow_mod(A[i], B[i], M))%M;
        }
        printf("%d\n",res);
    }
    
    return 0;
}