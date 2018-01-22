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

int N,C;
int X[MAX_N];

bool check(int d){
    int last=0,crt;
    for (int i=1; i<C; i++) {
        crt=last+1;
        while (crt<N && X[crt]-X[last]<d) {
            crt++;
        }
        if (crt==N) {
            return false;
        }
        last = crt;
    }
    return true;
}

void solve(){
    sort(X, X+N);
    
    int l=0,r=G_INF,mid;
    
    while (r-l>1) {
        mid=(l+r)/2;
        if (check(mid)) {
            l=mid;
        }else{
            r=mid;
        }
    }
    
    printf("%d\n",l);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d",&N,&C);
    for (int i=0; i<N; i++) {
        scanf("%d",&X[i]);
    }
    solve();
    
    return 0;
}