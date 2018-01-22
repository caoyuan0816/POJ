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
#define MAX_N 55

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int N,tot,res;
int num[MAX_N];

void solve(){
    int avg=tot/N;
    res=0;
    for (int i=0; i<N; i++) {
        if (num[i]<avg) {
            res+=(avg-num[i]);
        }
    }
    
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int k=0;
    while (scanf("%d",&N)!=EOF && N!=0) {
        if (k!=0) {
            puts("");
        }
        tot=0;
        for (int i=0; i<N; i++) {
            scanf("%d",&num[i]);
            tot+=num[i];
        }
        solve();
        printf("Set #%d\n",++k);
        printf("The minimum number of moves is %d.\n",res);
    }
    
    return 0;
}