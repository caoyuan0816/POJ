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
#define MAX_N 5005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int N,M,K;
int cow[MAX_N];
static int face[MAX_N];

int cal(int k){
    int res=0,sum=0,i;
    for (i=0; i<N; i++) {
        if (i<=N-k) {
            if ((cow[i]+sum)%2==1) {
                face[i]++;res++;
            }
            sum+=face[i];
            (i-k+1)>=0?(sum-=face[i-k+1]):sum;

        }else{
            if ((cow[i]+sum)%2==1) {
                return -1;
            }
            sum+=face[i];
            (i-k+1)>=0?(sum-=face[i-k+1]):sum;
        }
    }
    return res;
}

void solve(){
    K=1,M=N;
    for (int k=1; k<=N; k++) {
        int m=cal(k);
        if (m>=0 && m<M) {
            M=m;
            K=k;
        }
    }
    printf("%d %d\n",K,M);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        char ch;
        getchar();
        ch=getchar();
        ch=='F'?cow[i]=0:cow[i]=1;
    }
    
    solve();
    
    return 0;
}
