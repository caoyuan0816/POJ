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

int n;
int num[MAX_N];
int x[MAX_N],tot;

void solve(){
    tot=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            x[tot++]=abs(num[j]-num[i]);
        }
    }
    int z;
    if (tot%2==0) {
        z=tot/2;
    }else{
        z=tot/2+1;
    }
    
    nth_element(x, x+z, x+tot);
    printf("%d\n",x[z-1]);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%d",&num[i]);
        }
        solve();
    }
    
    return 0;
}